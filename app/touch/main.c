

#include <interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stm32.h>
#include <gpio.h>
#include <syscall.h>
#include <elf.h>
#define FILE            lfs_file_t
#define DIR             lfs_dir_t



syscall_t syscallp;

int main(int argc, char *argv[])
{
	syscall_init(&syscallp);
  int r;
  if(argc < 2){
    return -1;
  }
  if(argv[1]==NULL)return -1;

  char *tmp=syscallp.full_path(argv[1]);
  if(syscallp.exist(tmp)){
    printf("%s file found!\n",tmp );
    syscallp.updatepath();
    return -1;
  }
  
  FILE *fs=syscallp.open(tmp,LFS_O_CREAT);
  syscallp.close(fs);
  syscallp.updatepath();
    
	return 0;
}