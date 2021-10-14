#include "main.h"

void free_url(url_info* url) {
    if (!url) {
        return;
    }

    free (url->main_domain);
    free (url->protocol);

    int i = 0;

    while (url->other_domains[i] != NULL) {
        free (url->other_domains[i]);
        ++i;
    }
    free (url->other_domains);

    return;
}
