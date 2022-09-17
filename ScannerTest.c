#include "main.h"

import Sys System;
import Scanner sc;

int main(void){
    int8_t a = sc.nextByte();
    int16_t b = sc.nextShort();
    int32_t c = sc.nextInt();
    int64_t d = sc.nextLong();
    int8_t e = sc.nextUByte();
    uint16_t f = sc.nextUShort();
    uint32_t g = sc.nextUInt();
    uint64_t h = sc.nextULong();
    boolean i = sc.nextBoolean();
    char j = sc.nextChar();
    float k = sc.nextFloat();
    double l = sc.nextDouble();
    String m = sc.next();
    String n = sc.nextLine();

    System.out.println("a = %d", a);
    System.out.println("b = %d", b);
    System.out.println("c = %d", c);
    System.out.println("d = %lld", d);
    System.out.println("e = %d", e);
    System.out.println("f = %d", f);
    System.out.println("g = %d", g);
    System.out.println("h = %lld", h);
    System.out.println(i ? "true" : "false");
    System.out.println("j = %c", j);
    System.out.println("k = %f", k);
    System.out.println("l = %lf", l);
    System.out.println("m = %s", m);
    System.out.println("n = %s", n);

    free(m);
    free(n);

    while(1);

    return 0;
}