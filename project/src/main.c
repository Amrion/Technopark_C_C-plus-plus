#include "main.h"

int main(int argc, char* argv[]) {
    url_info url = {url.protocol = "", url.main_domain = "", url.other_domains = NULL};

    char* string_url = (char*) calloc(sizeof (char), BUFFER);
    if (!string_url) {
        return 1;
    }

    url_info* test = NULL;

    if (argc > 1) {
        test = parser(argv[1]);
    } else {
        if (scanf("%71s", string_url) != 1) {
            free (test);
            free (string_url);
            return 1;
        }

        test = parser(string_url);
    }

    int i = 0;

    if (!test) {
        free (string_url);
        free (url.main_domain);
        free (url.protocol);
        while (url.other_domains[i] != NULL) {
            free (url.other_domains[i]);
            i++;
        }
        free (url.other_domains);

        return 1;
    } else {
        url = *test;
    }

    if (print(url) != 0) {
        return 1;
    }

    free (string_url);
    free (url.main_domain);
    free (url.protocol);
    while (url.other_domains[i] != NULL) {
        free (url.other_domains[i]);
        i++;
    }
    free (url.other_domains);
    free (test);

    return 0;
}
