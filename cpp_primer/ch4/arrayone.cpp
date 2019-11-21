//
//  arrayone.cpp
//  cpp_primer
//
//  Created by aliouswang on 2019/7/11.
//  Copyright © 2019 aliouswang. All rights reserved.
//

#include "arrayone.hpp"

void runArrayOneSample() {
    using namespace std;
    
    inflatable* one = new inflatable;
    one->name = "jake";
    
    cout << one->name << endl;

}
