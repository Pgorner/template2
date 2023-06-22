#include "template.h"

void getCurrentDateTime(char *dateTime) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(dateTime, 20, "%Y/%m/%d %H:%M:%S", timeinfo);
}

char *generateTemplate(const char *filename, const char *email, const char *username) {
    char *template = (char *)malloc(MAX_TEMPLATE_LENGTH * sizeof(char));
    char dateTime[20];

    getCurrentDateTime(dateTime);

    char logoSpacing[LOGO_LENGTH + 1];
    memset(logoSpacing, ' ', LOGO_LENGTH);
    logoSpacing[LOGO_LENGTH] = '\0';

    char commentEndSpacing[COMMENT_END_LENGTH + 1];
    memset(commentEndSpacing, ' ', COMMENT_END_LENGTH);
    commentEndSpacing[COMMENT_END_LENGTH] = '\0';

	// int filenameSpacing = LOGO_LENGTH - (strlen(filename) + 1);
	int filenameSpacing = 51;	
	int emailSpacing = 43;	
	int userSpacing1 = 17;	
	int userSpacing2 = 10;	

    sprintf(template, "/* ************************************************************************** */\n");
    sprintf(template, "%s/*                                                                            */\n", template);
    sprintf(template, "%s/*                                                        :::      ::::::::   */\n", template);
    sprintf(template, "%s/*   %-*s:+:      :+:    :+:   */\n", template, filenameSpacing, filename);
    sprintf(template, "%s/*                                                    +:+ +:+         +:+     */\n", template);
    sprintf(template, "%s/*   By: %-*s#+#  +:+       +#+        */\n", template, emailSpacing, email);
    sprintf(template, "%s/*                                                +#+#+#+#+#+   +#+           */\n", template);
    sprintf(template, "%s/*   Created: %-16s by %-*s #+#    #+#             */\n", template, dateTime, userSpacing1, username);
    sprintf(template, "%s/*   Updated: %-16s by %-*s%s###   ########.fr       */\n", template, dateTime, userSpacing2, username, commentEndSpacing);
    sprintf(template, "%s/*                                                                            */\n", template);
    sprintf(template, "%s/* ************************************************************************** */\n", template);

    return template;
}

char *headermaker(char *filename) {
    char *email = USEREMAIL;
    char *username = USERNAME;

    if (strlen(email) > 30) {
        email[31] = '\0';
    }
    char *template = generateTemplate(filename, email, username);
    return (template);
}
