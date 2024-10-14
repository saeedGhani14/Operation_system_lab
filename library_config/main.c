#include <stdio.h>
#include <string.h>
#include "mylib.h"
// Define the struct here
struct info {
    uid_t userId;           // User ID
    char *time;             // Time as string
    off_t size;             // File size
};

int main(int argc, char *argv[]){

  //define the variables 
  char *option = argv[1];
  const char *path = argv[2];
  int job_to_do = 0;
  char *endptr;
  int check_result;
  struct info *information;


  if (!strcmp(option, "-t") || !strcmp(option, "-c")){
    char *permission = argv[3];
    int perm = strtol(permission, &endptr, 8);
    if (!strcmp(option, "-t")){
      check_result = checkFile(path, perm);
    }else{
      createFileWithPermission(path, perm);
    }

  }else if (!strcmp(option, "-s")){
    information = showFileInfo(path);
    printf("------------------\n");
    printf("user_id:%d\n", information->userId);
    printf("modified:%s", information->time);
    printf("size:%lld\n", information->size);
    printf("------------------\n");
  }else if (!strcmp(option, "-m")){
    int from = strtol(argv[5], &endptr, 10);
    int to = strtol(argv[6], &endptr, 10);
    createFileList(path, argv[3], argv[4], from, to);
  }
}
