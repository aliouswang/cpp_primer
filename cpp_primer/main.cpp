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

int main(int argc, const char * argv[]) {
//    printf("Hello unix senior! params:%s\n", argv[0]);
    
    DIR *dp;
    struct dirent *dirp;
    
    if(argc != 2) {
        err_quit("a single argument is required");
    }
    
    return 0;
}
