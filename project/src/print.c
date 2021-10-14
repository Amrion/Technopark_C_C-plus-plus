#include "main.h"

 int print(url_info url) {
    if (printf("Протокол = %s\n", url.protocol) < 0) {
        return 1;
    }
    if (printf("Домен верхнего уровня = %s\n", url.main_domain) < 0) {
        return 1;
    }

    int i = 0;
    while (url.other_domains[i] != NULL) {
        if (printf("Доменная структура остальных и информация об адресе = %s ", url.other_domains[i]) < 0) {
            return 1;
        }
        i++;
    }

    return 0;
}

