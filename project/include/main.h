#pragma once

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000

#define unlikely(x)     __builtin_expect((x),0)

int find_max(const char*, int);
int find_max_one_proc(const char*, int);
int timer(int (*func)(const char*, int), const char* arr, int);



