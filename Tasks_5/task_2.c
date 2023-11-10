// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <libgen.h>
#include <windows.h>
#else
#include <libgen.h>
#include <limits.h>
#include <unistd.h>
#endif

#define FILE_NAME_SIZE 128
#define FILE_PATH_SIZE 1024

char *get_file_path(const char *filename) {
  char file_path[FILE_PATH_SIZE];

#ifdef _WIN32
  // Windows
  GetModuleFileName(NULL, file_path, sizeof(file_path));
  dirname(file_path);

  snprintf(file_path, sizeof(file_path), "%s/%s", file_path, filename);
#else
  // Unix/Linux
  char dir_path[FILE_PATH_SIZE - FILE_NAME_SIZE];

  if (readlink("/proc/self/exe", dir_path, sizeof(dir_path) - 1) == -1) {
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
  char *file_path = get_file_path("task_2.txt");

  char x[100];

  FILE *fp;
  fp = fopen(file_path, "w");

  printf("Enter a string of characters to save in the file: ");

  fgets(x, 100, stdin);

  fprintf(fp, "%s", x);

  fclose(fp);

  if (file_path) {
    free(file_path);
  }

  return 1;
}
