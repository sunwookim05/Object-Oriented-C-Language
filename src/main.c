#include "main.h"
#include "System.h"

import SYSTEM System;
import INTEGER Integer;

int main(void){
    String str = Integer.toString(Integer.parseInt("0xFF", 16));
    System.out.println(str);

    free(str);
    return 0;
}