#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char **argv)
{
  int fd;
  char a;
  if(strcmp(argv[1],">")==0)
  {
    fd=open(argv[2],O_WRONLY|O_CREAT,0644);
    while(read(0,&a,1)>0)
    {
      if(a=='@')
        break;
      write(fd,&a,1);
    }
  }
  else
  {
    fd=open(argv[1],O_RDONLY);
    while(read(fd,&a,1)>0)
      write(1,&a,1);
  }
  return 0;
}            
