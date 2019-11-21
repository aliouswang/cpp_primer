//
//  main.cpp
//  cpp_primer
//
//  Created by aliouswang on 2019/7/11.
//  Copyright © 2019 aliouswang. All rights reserved.
//

#include <iostream>
#include "arrayone.hpp"

#include <pthread.h>

#define NLOOP 5000

static pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond;
static int counter;

void *Adoit(void *);
void *Bdoit(void *);

using namespace std;

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    pthread_cond_init(&cond, NULL);
//
//    pthread_t tA, tB;
//
//    pthread_create(&tB, NULL, Bdoit, NULL);
//
//    pthread_create(&tA, NULL, Adoit, NULL);
//
//    pthread_join(tB, NULL);
//
//    pthread_join(tA, NULL);
//
//
//    std::cout << counter << std::endl;
//
//    return 0;
//}

void *Adoit(void *arg) {
    pthread_mutex_lock(&counter_mutex);
    cout << "A count start" << endl;
    for (int i = 0; i < NLOOP; i++) {
        counter++;
    }
    cout << "A count finish" << endl;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&counter_mutex);
    return NULL;
}

void *Bdoit(void *arg) {
    pthread_mutex_lock(&counter_mutex);
    pthread_cond_wait(&cond, &counter_mutex);
    cout << "B count start" << endl;
    for (int i = 0; i < NLOOP; i++) {
        counter++;
    }
    cout << "B count finish" << endl;
    pthread_mutex_unlock(&counter_mutex);
    return NULL;
}
