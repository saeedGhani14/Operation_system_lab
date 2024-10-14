#include "mylib.h"
struct info {
    uid_t userId;           // User ID
    char *time;             // Time as string
    off_t size;             // File size
};

void createFileWithPermission(const char *path, int permission){
  int file = open(path, O_CREAT | O_WRONLY | O_TRUNC, permission);
  chmod(path, permission);
  close(file);
}

int checkFile(const char *path, int permission){
  int read = access(path, R_OK);
  int write = access(path, W_OK);
  int exe = access(path, X_OK);
  int perm = (read * 4) + (write * 2) + exe;
  printf("permission of file: %d\n", perm);
  printf("input of permission: %d\n", permission & perm);
  if ((permission & perm) == permission)
    return 1;
  return -1;
}

struct info* showFileInfo(const char *path){
  struct info *information = (struct info*)malloc(sizeof(info));
  struct stat attr;
  stat(path, &attr);
  information->userId = getuid();
  information->time = ctime(&attr.st_mtime);
  information->size = attr.st_size;

  return information;
}

void createFileList(const char *dirpath, const char *prefix, const char *ext, int from, int to){
  printf("create file list\n");
}
