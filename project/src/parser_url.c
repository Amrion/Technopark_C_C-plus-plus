#include "../include/main.h"

url_info* parser(char* url) {
    if (!url) {
        return NULL;
    }

    int i = 0;

    while (1) {
        if (url[i] == '/' || url[i] == '.') {
            break;
        }
        if (url[i] == '\0') {
            return NULL;
        }
        i++;
    }

    i = 0;

    for (; i < APPR_LIMIT; ++i) {
        if (url[i] == ':') {
            i = 0;
            break;
        }
    }

    url_info* my_url = (url_info*) malloc(sizeof (url_info));

    my_url->protocol = (char *) malloc(APPR_LIMIT);

    if (i == APPR_LIMIT) {
        my_url->protocol[0] = '-';
        i = 0;
    } else {
        while (url[i] != ':') {
            my_url->protocol[i] = url[i];
            i++;
        }
        i += 3;
    }

    my_url->main_domain = (char*) calloc(AVERANGE_LENGTH_NAME_DOM, sizeof(char));

    int k = 0;
    while (url[i] != '.') {
        my_url->main_domain[k] = url[i];
        k++;
        i++;
    }
    if (strcmp(my_url->main_domain, "www") == 0) {
        free(my_url->main_domain);
        i++;
        k = 0;

        my_url->main_domain = (char*) calloc(AVERANGE_LENGTH_NAME_DOM, sizeof (char));

        while (url[i] != '.') {
            my_url->main_domain[k] = url[i];
            k++;
            i++;
        }
    }
    k = 0;
    i++;

    my_url->other_domains = (char**) calloc(AVERANGE_LENGTH_DOM * sizeof(char*), AVERANGE_LENGTH_DOM);
    if (!my_url->other_domains) {
        return NULL;
    }

    int j = 0;
    bool check_domain = false;
    while (url[i] != '\0') {
        my_url->other_domains[j] = (char*) calloc(AVERANGE_LENGTH, sizeof (char));
        while (url[i] != '\0') {
            if (url[i] == '/') {
                check_domain = true;
                break;
            }
            if (check_domain == false & url[i] == '.') {
                break;
            }
            if (url[i] == '?') {
                break;
            }
            my_url->other_domains[j][k] = url[i];
            k++;
            i++;
        }
        k = 0;
        if (url[i] == '?') {
            break;
        }
        if (url[i] != '\0') {
            i++;
            j++;
        }
    }

    return my_url;
}


