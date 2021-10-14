#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define AVERANGE_LENGTH_DOM 10
#define AVERANGE_LENGTH 25
#define AVERANGE_LENGTH_NAME_DOM 25
#define BUFFER 101
#define APPR_LIMIT 7

typedef struct {
    char* protocol;
    char* main_domain;
    char** other_domains;
}url_info;

url_info* parser(char*);

int print(url_info);