#include "main.h"

int main(int argc, char* argv[]) {
    url_info url = {url.protocol = "", url.main_domain = "", url.other_domains = NULL};

    char* string_url = NULL;
    url_info* test = NULL;

    if (argc > 1) {
        string_url = argv[1];
    } else {
        string_url = (char*) calloc(sizeof (char), BUFFER);
        if (!string_url) {
            return 1;
        }

        if (scanf("%71s", string_url) != 1) {
            free (test);
            free (string_url);
            return 1;
        }
    }

    test = parser(string_url);

    if (!test) {
        free (string_url);

        return 1;
    } else {
        url = *test;
    }

    if (print(url) != 0) {
        return 1;
    }

    free (string_url);
    free_url(&url);
    free (test);

    return 0;
}
