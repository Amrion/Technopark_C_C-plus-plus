#include "../include/main.h"

int main(int argc, char* argv[]) {
    url_info url;
    char string_url[BUFFER];

    url_info* test;

    if (argc > 1) {
        test = parser(argv[1]);
    } else {
        if (scanf("%300s", string_url) != 1) {
            return 1;
        }

        test = parser(string_url);
    }

    if (!test) {
        return 1;
    } else {
        url = *test;
    }

    if (print(url) != 0) {
        return 1;
    }

    int i = 0;

    free(url.main_domain);
    free(url.protocol);
    while (url.other_domains[i] != NULL) {
        free(url.other_domains[i]);
        i++;
    }
    free(url.other_domains);

    return 0;
}
