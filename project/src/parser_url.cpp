#include "../include/main.h"

url_info* parser(char* url) {
    if (!url) {
        return NULL;
    }

    url_info my_url;
    my_url.protocol = ' ';
    int i = 0;

    for (; i < APPR_LIMIT; ++i) {
        if (my_url.protocol == ':') {
            i = 0;
            break;
        }
    }

    if (i == 7) {
        my_url.protocol = "Нет данных о протоколе";
        i = 0;
    }

    while (url[i] != ':') {
        my_url.protocol += url[i];
        i++;
    }



}

