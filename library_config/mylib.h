#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

struct{
  int userId;
  char *time;
  int size;
}info;

void createFileWithPermission(const char *path, int permission);
int checkFile(const char *path, int permission);
struct info *showFileInfo(const char *path);
void createFileList(const char *dirpath, const char *prefix, const char *ext, int from, int to);
