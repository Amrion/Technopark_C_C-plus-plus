#include <string.h>

#include "main.h"

int parser_md(char* url, url_info* my_url, int i) {
    if (!url) {
        return 1;
    }
    if (!my_url) {
        return 1;
    }

    int k = 0;
    while (url[i] != '.') {
        my_url->main_domain[k] = url[i];
        ++k;
        ++i;
    }
    if (strcmp(my_url->main_domain, "www") == 0) {
        free(my_url->main_domain);
        ++i;
        k = 0;

        my_url->main_domain = (char*) calloc(AVERANGE_LENGTH_NAME_DOM, sizeof (char));
        if (!my_url->main_domain) {
            return NULL;
        }


        while (url[i] != '.') {
            my_url->main_domain[k] = url[i];
            ++k;
            ++i;
        }
    }
    k = 0;
    ++i;

    return i;
}

