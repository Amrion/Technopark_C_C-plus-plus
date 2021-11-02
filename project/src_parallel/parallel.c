#include "main.h"
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

int find_max_one_proc(const char* arr, int size) {
    if (unlikely(!arr)) {
        return -1;
    }

    int kol = 0, maxkol = 0;

    for (int i = 0; i < (size - 1); ++i) {
        if (arr[i] != arr[i + 1]) {
            ++kol;
        } else {
            ++kol;
            if (kol > maxkol) {
                maxkol = kol;
            }
            kol = 0;
        }
    }

    return maxkol;
}

int find_max(const char* arr, int size) {
    if (unlikely(!arr)) {
        return -1;
    }

    long num_proc = sysconf(_SC_NPROCESSORS_ONLN);
    if (unlikely(num_proc == -1)) {
        return -1;
    }
    int fd[num_proc][2];

    for (int i = 0; i < num_proc; ++i) {
        if (pipe(fd[i]) == -1) {
            return -1;
        }
    }

    for (int i = 0; i < num_proc; ++i) {
        int pid = fork();
        if (unlikely(pid == -1)) {
            return -1;
        }

        if (pid == 0) {
            if ( i == 11) {
                size = (int)(ceil(SIZE/12) + (SIZE - ceil(SIZE/12) * 12));
            } else {
                size = (int)ceil(SIZE/12);
            }
            int res = find_max_one_proc((arr + (int)(ceil(SIZE/12) * i)), size);
            if (unlikely(res == -1)) {
                return -1;
            }
            for (int j = 0; j < num_proc; ++j) {
                close(fd[j][0]);
                if (j != i) {
                    close(fd[j][1]);
                }
            }

            if (write(fd[i][1], &res, sizeof(res)) == -1) {
                return -1;
            }

            close(fd[i][1]);

            exit(0);
        }
    }

    int status = 0;
    for (int i = 0; i < num_proc; ++i) {
        if (wait(&status) < 0) {
            return -1;
        }
    }

    int res = 0;
    for (int i = 0; i < num_proc; ++i) {
        int inter_res = 0;

        if (read(fd[i][0], &inter_res, sizeof(inter_res)) == -1) {
            return -1;
        }
        if (inter_res > res) {
            res = inter_res;
        }
    }

    for (int j = 0; j < num_proc; ++j) {
        close(fd[j][1]);
        close(fd[j][0]);
    }

    return res;
}
