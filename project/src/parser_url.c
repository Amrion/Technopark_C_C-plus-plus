#include "main.h"

url_info* parser(char* url) {
    if (!url) {
        return NULL;
    }

    url_info* my_url = (url_info*) malloc(sizeof (url_info));
    if (!my_url) {
        return NULL;
    }

    my_url->protocol = (char *) calloc(APPR_LIMIT, sizeof(char));
    if (!my_url->protocol) {
        return NULL;
    }

    int i = 0;

    i = parser_prtcl(url, my_url, i);
    if (i == 1) {
        return NULL;
    }

    my_url->main_domain = (char*) calloc(AVERANGE_LENGTH_NAME_DOM, sizeof(char));
    if (!my_url->main_domain) {
        return NULL;
    }

    i = parser_md(url, my_url, i);
    if (i == 1) {
        return NULL;
    }

    my_url->other_domains = (char**) calloc(AVERANGE_LENGTH_DOM * sizeof(char*), AVERANGE_LENGTH_DOM);
    if (!my_url->other_domains) {
        free (my_url->protocol);
        free (my_url->main_domain);

        return NULL;
    }

    if (parser_str_od(url, my_url, i)) {
        return NULL;
    }

    return my_url;
}


