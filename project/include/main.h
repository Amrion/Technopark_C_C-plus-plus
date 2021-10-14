#pragma once

#include <stdio.h>
#include <stdlib.h>

#define AVERANGE_LENGTH_DOM 10
#define AVERANGE_LENGTH 25
#define AVERANGE_LENGTH_NAME_DOM 25
#define BUFFER 71
#define APPR_LIMIT 7

typedef struct {
    char* protocol;
    char* main_domain;
    char** other_domains;
}url_info;

url_info* parser(char*);

int parser_prtcl(char*, url_info*, int);

int parser_md(char*, url_info*, int);

int parser_str_od(char*, url_info*, int);

int print(url_info);

void free_url(url_info*);