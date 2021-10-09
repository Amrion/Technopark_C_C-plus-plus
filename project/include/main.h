#pragma once

#define AVERANGE_LENGTH 10
#define APPR_LIMIT 7

typedef struct url_info {
    const char* protocol;
    const char* main_domain;
    const char** other_domains;
}url_info;

url_info* parser(char*);