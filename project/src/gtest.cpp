#include "gtest/gtest.h"

extern "C" {
#include <cstddef>
#include "../include/main.h"
}


TEST(URL_TEST, TEST_WITH_PRT_SHORT) {
    url_info url;


    url.protocol = "https";
    url.main_domain = "vk";
    url.other_domains = (char**) malloc(2 * sizeof (char*));
    url.other_domains[0] = "com";
    url.other_domains[1] = "im";

    char* my_url = "https://vk.com/im";
    url_info* result_url = parser(my_url);

    EXPECT_STREQ(result_url->main_domain, url.main_domain);
    EXPECT_STREQ(result_url->protocol, url.protocol);
    for (int i = 0; i < 2; ++i) {
        EXPECT_STREQ(result_url->other_domains[i], url.other_domains[i]);
    }

}

TEST(URL_TEST, TEST_WITH_PRT_MEDIUM) {
    url_info url;

    url.protocol = "https";
    url.main_domain = "github";
    url.other_domains = (char**) malloc(3 * sizeof (char*));
    url.other_domains[0] = "com";
    url.other_domains[1] = "Vinograduss";
    url.other_domains[2] = "masterclass";

    char* my_url = "https://github.com/Vinograduss/masterclass";
    url_info* result_url = parser(my_url);


    EXPECT_STREQ(result_url->main_domain, url.main_domain);
    EXPECT_STREQ(result_url->protocol, url.protocol);
    for (int i = 0; i < 3; ++i) {
        EXPECT_STREQ(result_url->other_domains[i], url.other_domains[i]);
    }

}

TEST(URL_TEST, TEST_WITH_PRT_LONG) {
    url_info url;

    url.protocol = "https";
    url.main_domain = "github";
    url.other_domains = (char**) malloc(6 * sizeof (char*));
    url.other_domains[0] = "com";
    url.other_domains[1] = "Vinograduss";
    url.other_domains[2] = "masterclass";
    url.other_domains[3] = "blob";
    url.other_domains[4] = "main";
    url.other_domains[5] = "test.md";

    char* my_url =  "https://github.com/Vinograduss/masterclass/blob/main/test.md";
    url_info* result_url = parser(my_url);


    EXPECT_STREQ(result_url->main_domain, url.main_domain);
    EXPECT_STREQ(result_url->protocol, url.protocol);
    for (int i = 0; i < 6; ++i) {
        EXPECT_STREQ(result_url->other_domains[i], url.other_domains[i]);
    }

}

TEST(URL_TEST, TEST_WITH_PRT_GET) {
    url_info url;

    url.protocol = "https";
    url.main_domain = "vk";
    url.other_domains = (char**) malloc(2 * sizeof (char*));
    url.other_domains[0] = "com";
    url.other_domains[1] = "im";

    char* my_url = "https://vk.com/im?peers=252862492_283866136_c280_215950077_71276649";
    url_info* result_url = parser(my_url);


    EXPECT_STREQ(result_url->main_domain, url.main_domain);
    EXPECT_STREQ(result_url->protocol, url.protocol);
    for (int i = 0; i < 2; ++i) {
        EXPECT_STREQ(result_url->other_domains[i], url.other_domains[i]);
    }

}

TEST(URL_TEST, TEST_WWW) {
    url_info url;

    url.protocol = "-";
    url.main_domain = "mail";
    url.other_domains = (char**) malloc(2 * sizeof(char*));
    url.other_domains[0] = "ru";

    char* my_url = "www.mail.ru";
    url_info* result_url = parser(my_url);

    EXPECT_STREQ(result_url->main_domain, url.main_domain);
    EXPECT_STREQ(result_url->protocol, url.protocol);
    for (int i = 0; i < 1; ++i) {
        EXPECT_STREQ(result_url->other_domains[i], url.other_domains[i]);
    }

}

TEST(URL_TEST, TEST_NO_ADDRESS) {
    char* my_url = "wdasdasd";
    url_info* result_url = parser(my_url);

    EXPECT_EQ(result_url, (url_info*)0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

