#include <stdbool.h>

#include "main.h"

int parser_str_od(char* url, url_info* my_url, int i) {
    if (!url) {
        return 1;
    }
    if (!my_url) {
        return 1;
    }

    int k = 0;
    int j = 0;
    bool check_domain = false;
    while (url[i] != '\0') {
        my_url->other_domains[j] = (char*) calloc(AVERANGE_LENGTH, sizeof (char));
        if (!my_url->other_domains[j]) {
            return NULL;
        }

        while (url[i] != '\0') {
            if (url[i] == '/') {
                check_domain = true;
                break;
            }
            if (check_domain == false && url[i] == '.') {
                break;
            }
            if (url[i] == '?') {
                break;
            }
            my_url->other_domains[j][k] = url[i];
            ++k;
            ++i;
        }
        k = 0;
        if (url[i] == '?') {
            break;
        }
        if (url[i] != '\0') {
            ++i;
            ++j;
        }
    }

    return 0;
}