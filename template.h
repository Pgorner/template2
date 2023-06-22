/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:33 by fsandel           #+#    #+#             */
/*   Updated: 2023/06/22 15:29:17 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/*############################################################################*/
/*						CHANGE THIS FOR THE WORKING HEADER					  */
/*############################################################################*/
#define USERNAME "pgorner"
#define USEREMAIL "pgorner@student.42heilbronn.de"
#define HEADER 1 // SET TO 0 IF HEADER UNWANTED
/*############################################################################*/
#define MAX_TEMPLATE_LENGTH 1000
#define LOGO_LENGTH 52
#define COMMENT_END_LENGTH 7
#define INT_MAX 2147483648

void create_hpp(int fd, char *name);
void create_cpp(int fd, char *name);
char *strjoin(char *f, char *s);
char *headermaker(char *filename);

#endif