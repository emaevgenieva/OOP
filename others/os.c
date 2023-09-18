
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define COM 'ls'

int main(){
    int i=5, k=2, status;
    if(fork()){
        wait(&status);
        --i;
        --k;
        write(1,"text1\n",6);
        printf("I= %d K=%d",i,k);
    }
    else{
        for(k=1;k<=3;k++){
            write(1,"text2\n",6);
            printf("I= %d K=%d",i,k);
            if((execlp(COM,COM,0))==-1){
                i=i+2;
                write(1,"text2\n",6);
                printf("I= %d K=%d",i,k);
                exit(2);
            }
        }
    }
    write(1,"text4",6);
    if((execlp("date","date",0))==-1)
                printf("I= %d K=%d",i,k);
    else write(1,"text5",6);
            
}

























    // #include <stdio.h>
    // #include <unistd.h>
    // #include <sys/types.h>
    // #include <sys/wait.h>
    // #include <stdbool.h>

    // bool containsPTS(char* line, int lineSize){
    //     for(int i=0; i<lineSize-3+1; ++i){
    //         if(line[i] == 'p' && line[i+1] == 't' && line[i+2] == 's'){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // int strlen(char* str){
    //     int counter =0;
    //     while(str[counter] != '\0'){
    //         ++counter;
    //     }
    //     return counter;
    // }

    // int main(int argc, char** argv){
    //     int fd1 = open("/home/student/x1",O_RDONLY);
    //     if(fd1 == -1){
    //         printf("Problem while opening the file");
    //         exit(1);
    //     }
    //     char currentLine[1024];
    //     int currentSize = 0;
    //     char ch;
    //     while(read(fd1, &ch, 1) != 0){
    //         if(ch == '\n'){
    //             if(containsPTS(currentLine,currentSize)){
    //                 write(1, currentLine, currentSize);
    //                 printf("\n");
    //             }
    //             currentSize = 0;
    //         }
    //         else{
    //             currentLine[currentSize] = ch;
    //             ++currentSize;
    //         }
    //     }

    //     int fd2=open(argv[1],O_WRONLY|O_CREATE|O_TRUNC,0777);
    //     if(fd2 == -1){
    //         printf("Problem while opening the file");
    //         exit(1);
    //     }

    //     int pid = fork();
    //     if(pid == 0){
    //         int status;
    //         wait(&status);
    //         if(status == 0){
    //             printf("%d\n",getppid());
    //             write(fd2,argv[2],strlen(argv[2]));
    //         }
    //     }
    //     else{
    //         execlp(argv[2],argv[2];)
    //     }
    //     close fd1;
    //     close fd2;
    //     return 0;
    // }