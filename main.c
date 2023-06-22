/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:40:06 by fsandel           #+#    #+#             */
/*   Updated: 2023/06/22 12:58:06 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

int header(int fd) {
    FILE* headerfile = fopen("output.txt", "r");
    if (headerfile == NULL) {
        printf("Failed to open the headerfile.\n");
        return 1;
    }

    char buffer[256];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), headerfile)) > 0) {
        write(fd, buffer, bytesRead);
    }

    fclose(headerfile);

    return 0;
}

int getFileDescriptor(FILE* file) {
    int fd = fileno(file);
    return fd;
}

int mainmaker(){
if (!access("main.cpp", F_OK)){
      printf("------------------------------------------------------------------\n");
      printf("|                     MAIN ALREADY EXISTS                        |\n");
      printf("------------------------------------------------------------------\n");
      return(0);
    }
    FILE *file = fopen("main.cpp", "w");
    if (file == NULL) {
        printf("Error creating main.\n");
        return(0);
    }
    fprintf(file, headermaker("main.cpp"));
    fprintf(file, "\n\n");
    fprintf(file, "int main(void) {}\n");
    return(0);
}

int makefile(char *name, char **filenames){
    if (!access("Makefile", F_OK)){
      printf("------------------------------------------------------------------\n");
      printf("|                     MAKEFILE ALREADY EXISTS                    |\n");
      printf("------------------------------------------------------------------\n");
      return(0);
    }
    FILE *file = fopen("Makefile", "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return(0);
    }
    header(getFileDescriptor(file));
    fprintf(file, "#	███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗\n");
    fprintf(file, "#	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝\n");
    fprintf(file, "#	██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗\n");
    fprintf(file, "#	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝\n");
    fprintf(file, "#	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗\n");
    fprintf(file, "#	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝\n");
    fprintf(file, "\n");
    fprintf(file, "NAME = ");
    fprintf(file, "%s", name);
    fprintf(file, "\n");
    fprintf(file, "\n");
    fprintf(file, "CC     = c++\n");
    fprintf(file, "CFLAGS = -Wall -Werror -Wextra -std=c++98\n");
    fprintf(file, "AR     = ar rcs\n");
    fprintf(file, "RM     = rm -rf\n");
    fprintf(file, "\n");
    fprintf(file, "SRC =");
    fprintf(file, " main.cpp");
    for (int i = 0; filenames[i] != NULL; i++)
        fprintf(file, " %s.cpp", filenames[i]);
    fprintf(file, "\n");
    fprintf(file, "\n");
    fprintf(file, "OBJS = $(SRC:.cpp=.o)\n");
    fprintf(file, "\n");
    fprintf(file, "$(NAME): $(OBJS)\n");
    fprintf(file, "\t$(CC) $(CFLAGS) $(OBJS) -o $(NAME)\n");
    fprintf(file, "\n");
    fprintf(file, "all: $(NAME)\n");
    fprintf(file, "\n");
    fprintf(file, "clean:\n");
    fprintf(file, "\t$(RM) $(OBJS)\n");
    fprintf(file, "\n");
    fprintf(file, "fclean: clean\n");
    fprintf(file, "\t@$(RM) $(NAME)\n");
    fprintf(file, "\n");
    fprintf(file, "re: fclean all\n");
    fclose(file);
    return(0);
}

char **split(const char *str, const char *delimiter) {
    char **tokens = NULL;
    char *token = strtok((char *)str, delimiter);
    int count = 0;

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (count + 1));
        tokens[count] = token;
        count++;

        token = strtok(NULL, delimiter);
    }

    tokens = realloc(tokens, sizeof(char *) * (count + 1));
    tokens[count] = NULL;

    return tokens;
}

int single() {
    char input[100];
    char **splitted;
    char *class_name;
    int count = 0;
    while (count != -1) 
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        splitted = split(input, " ");
        
        while (splitted[count] != NULL)
            count++;
        if (strchr(splitted[0], '.'))
            count++;
        if (count != 1) {
            printf("------------------------------------------------------------------\n");
            printf("|Invalid input. Only one argument is allowed.                    |\n");
            printf("|Please provide a valid class name without any spaces.           |\n");
            printf("------------------------------------------------------------------\n");
        }
        else{
            class_name = splitted[0];
            printf("------------------------------------------------------------------\n");
            printf("Class name: %s\n", class_name);
            printf("------------------------------------------------------------------\n");
            count = -1;
        }
    }
    char *cpp_name = strjoin(class_name, ".cpp");
    if (!cpp_name) {
      dprintf(STDERR_FILENO, "First allocation failed\n");
      return (6);
    }
    char *hpp_name = strjoin(class_name, ".hpp");
    if (!hpp_name) {
      dprintf(STDERR_FILENO, "Second allocation failed\n");
      return (7);
    }
    if (!access(cpp_name, F_OK) || !access(hpp_name, F_OK)) {
      dprintf(STDERR_FILENO, "File already exists\n");
      free(cpp_name);
      free(hpp_name);
      return (3);
    }
    int cpp_fd = open(cpp_name, O_WRONLY | O_CREAT, 0644);
    if (cpp_fd < 0) {
      dprintf(STDERR_FILENO, "CPP File open failed\n");
      free(cpp_name);
      free(hpp_name);
      return (4);
    }
    int hpp_fd = open(hpp_name, O_WRONLY | O_CREAT, 0644);
    if (hpp_fd < 0) {
      dprintf(STDERR_FILENO, "HPP File open failed\n");
      free(cpp_name);
      free(hpp_name);
      close(cpp_fd);
      return (5);
    }
    create_hpp(hpp_fd, class_name);
    create_cpp(cpp_fd, class_name);
    close(cpp_fd);
    close(hpp_fd);
    return (0);
    return 0;
}

int full() {
    char input[1000];
    char **splitted;
    char *program_name;
    char **class_name;
    int count = 0;
    int i = 0;
    while (count != -1) 
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        splitted = split(input, " ");
        while (splitted[count] != NULL)
            count++;
        if (count != 1) {
            printf("------------------------------------------------------------------\n");
            printf("|Invalid input. Only one argument is allowed.                    |\n");
            printf("|Please provide a valid program name without any spaces.         |\n");
            printf("------------------------------------------------------------------\n");
        }
        else{
            program_name = strdup(splitted[0]);
            printf("------------------------------------------------------------------\n");
            printf("Program name: %s\n", program_name);
            printf("------------------------------------------------------------------\n");
            count = -1;
        }
    }
    printf("------------------------------------------------------------------\n");
    printf("| Enter all needed class names seperated by spaces               |\n");
    printf("| Press enter when done                                          |\n");
    printf("------------------------------------------------------------------\n");
    count = 0;
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    splitted = split(input, " ");
    printf("------------------------------------------------------------------\n");
    printf("Class names:\n");
    i =0;
    while(splitted[i])
      printf("%s\n", splitted[i++]);
    printf("------------------------------------------------------------------\n");
    i = 0;
    while(splitted[i])
    {
    printf("Making class:%s\n", splitted[i]);
    char *cpp_name = strjoin(splitted[i], ".cpp");
    if (!cpp_name) {
      dprintf(STDERR_FILENO, "First allocation failed\n");
      return (6);
    }
    char *hpp_name = strjoin(splitted[i], ".hpp");
    if (!hpp_name) {
      dprintf(STDERR_FILENO, "Second allocation failed\n");
      return (7);
    }
    if (!access(cpp_name, F_OK) || !access(hpp_name, F_OK)) {
      dprintf(STDERR_FILENO, "File already exists\n");
      free(cpp_name);
      free(hpp_name);
      return (3);
    }
    int cpp_fd = open(cpp_name, O_WRONLY | O_CREAT, 0644);
    if (cpp_fd < 0) {
      dprintf(STDERR_FILENO, "CPP File open failed\n");
      free(cpp_name);
      free(hpp_name);
      return (4);
    }
    int hpp_fd = open(hpp_name, O_WRONLY | O_CREAT, 0644);
    if (hpp_fd < 0) {
      dprintf(STDERR_FILENO, "HPP File open failed\n");
      free(cpp_name);
      free(hpp_name);
      close(cpp_fd);
      return (5);
    }
    create_hpp(hpp_fd, splitted[i]);
    create_cpp(cpp_fd, splitted[i]);
    close(cpp_fd);
    close(hpp_fd);
    i++;
    }
    makefile(program_name, splitted);
    return 0;
}

int main(int argc, char *argv[]) {
  printf("------------------------------------------------------------------\n");
  printf("|                Welcome to Template Builder                     |\n");
  printf("------------------------------------------------------------------\n");
  printf("|Template Builder can either create all necessary templates or   |\n");
  printf("|just single ones.                                               |\n");
  printf("|Full build means Makefile and any amount of classes with .cpp & |\n");
  printf("|.hpp with OCC classes                                           |\n");
  printf("|Single build means one class with matching .cpp & .hpp          |\n");
  printf("|Type \"single\" for single build and \"full\" for full build        |\n");
  printf("------------------------------------------------------------------\n");
  while (1){
    char input[10];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, "full") == 0) {
      printf("------------------------------------------------------------------\n");
      printf("|                         full confirmed                         |\n");
      printf("|                    -enter program name below-                  |\n");
      printf("------------------------------------------------------------------\n");
      full();
      mainmaker();
      exit(0);
    }
    else if (strcmp(input, "single") == 0) {
      printf("------------------------------------------------------------------\n");
      printf("|                        single confirmed                        |\n");
      printf("|                    -enter class name below-                    |\n");
      printf("------------------------------------------------------------------\n");
      single();
      mainmaker();
      exit(0);
    }
    else {
        printf("Invalid input\n");
    }
  }

}
