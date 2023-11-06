// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <libgen.h>
#else
#include <unistd.h>
#include <limits.h>
#include <libgen.h>
#endif

#define FILE_NAME_SIZE 128
#define FILE_PATH_SIZE 1024

char * get_file_path(const char * filename) {
    char file_path[FILE_PATH_SIZE];

    #ifdef _WIN32
        // Windows
        GetModuleFileName(NULL, file_path, sizeof(file_path));
        dirname(file_path);

        snprintf(file_path, sizeof(file_path), "%s/%s", file_path, filename);
    #else
        // Unix/Linux
        char dir_path[FILE_PATH_SIZE-FILE_NAME_SIZE];

        if (readlink("/proc/self/exe",
            dir_path, sizeof(dir_path) - 1) == -1) {
            perror("readlink() error");
            exit(1);
        }
        dirname(dir_path);

        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, filename);
    #endif

    char *result = malloc(strlen(file_path) + 1);
    snprintf(result, strlen(file_path) + 1, "%s", file_path);

    return result;
}

int main() {
    char * data_file_path = get_file_path("task_3-5_DATA.txt");

    FILE *fp;
    fp = fopen(data_file_path, "r");

    fseek(fp, 0, SEEK_END);
    printf("Number of characters in file task_3-5_DATA.txt: %ld", ftell(fp));

    fclose(fp);

    if (data_file_path) {
        free(data_file_path);
    }

    return 1;
}
