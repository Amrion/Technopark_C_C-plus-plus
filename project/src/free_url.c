#include "main.h"

void free_url(url_info* url) {
    if (!url) {
        return;
    }

    free (url->protocol);
    free (url->main_domain);

    int i = 0;

    while (url->other_domains[i] != NULL) {
        free (url->other_domains[i]);
        ++i;
    }
    free (url->other_domains);

    return;
}
