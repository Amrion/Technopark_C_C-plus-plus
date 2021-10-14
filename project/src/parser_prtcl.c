#include "main.h"

int parser_prtcl(char* url, url_info* my_url, int i) {
    if (!url) {
        return 1;
    }
    if (!my_url) {
        return 1;
    }

    while (1) {
        if (url[i] == '/' || url[i] == '.') {
            break;
        }
        if (url[i] == '\0') {
            return 1;
        }
        ++i;
    }

    i = 0;

    for (; i < APPR_LIMIT; ++i) {
        if (url[i] == ':') {
            i = 0;
            break;
        }
    }

    if (i == APPR_LIMIT) {
        my_url->protocol[0] = '-';
        i = 0;
    } else {
        while (url[i] != ':') {
            my_url->protocol[i] = url[i];
            ++i;
        }
        i += 3;
    }

    return i;
}

