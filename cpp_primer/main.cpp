//
//  main.cpp
//  cpp_primer
//
//  Created by aliouswang on 2019/11/21.
//  Copyright © 2019 aliouswang. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "ourhdr.h"
#include "fcntl.h"

#define BUFFSIZE 8192

int main(int argc, const char * argv[]) {
    int n;
    char buf[BUFFSIZE];
    
    int stdin = open("/Users/aliouswang/Desktop/stdin", O_RDWR);
    int stdout = open("/Users/aliouswang/Desktop/stdout", O_RDWR);
    printf("current process id: %d\n", getpid());
    printf("copy start!");
    while((n = read(stdin, buf, BUFFSIZE)) > 0) {
        if(write(stdout, buf, n) != n) {
            err_sys("write error");
        }
    }
    
    if (n < 0) {
        err_sys("read error");
    }
    printf("copy finished!");
    return 0;
}
