#include "main.h"
#include "System.h"
#include "Scanner.h"

import SYSTEM System;
import INTEGER Integer;

int main(void){
    Scanner sc = new_Scanner(System.in);
    System.out.printf("Enter a HEX number:");
    String str = sc.next();
    int num = Integer.parseInt(str, 16);
    System.out.println("Decimal number is: %d", num);

    free(str);
    return 0;
}