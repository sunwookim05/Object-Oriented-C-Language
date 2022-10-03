#include "main.h"
#include "System.h"
#include "Scanner.h"

import Sys System;

int main(void){
    Scanner sc = new_Scanner(System.in);

    System.out.print("char: ");
    char j = sc.nextChar();
    System.out.print("int8_t: ");
    int8_t a = sc.nextByte();
    System.out.print("int16_t: ");
    int16_t b = sc.nextShort();
    System.out.print("int32_t: ");
    int32_t c = sc.nextInt();
    System.out.print("int64_t: ");
    int64_t d = sc.nextLong();
    System.out.print("uint8_t: ");
    int8_t e = sc.nextUByte();
    System.out.print("uint16_t: ");
    uint16_t f = sc.nextUShort();
    System.out.print("uint32_t: ");
    uint32_t g = sc.nextUInt();
    System.out.print("uint64_t: ");
    uint64_t h = sc.nextULong();
    System.out.print("boolean: ");
    boolean i = sc.nextBoolean();
    System.out.print("float: ");
    float k = sc.nextFloat();
    System.out.print("double: ");
    double l = sc.nextDouble();
    System.out.print("long double: ");
    long double m = sc.nextLDouble();
    System.out.print("String: ");
    String n = sc.next();
    System.out.print("String with space: ");
    String o = sc.nextLine();

    System.out.println(" ");
    System.out.println("char: %c", j);
    System.out.println("int8_t: %d", a);
    System.out.println("int16_t: %d", b);
    System.out.println("int32_t: %d", c);
    System.out.println("int64_t: %lld", d);
    System.out.println("uint8_t: %u", e);
    System.out.println("uint16_t: %u", f);
    System.out.println("uint32_t: %u", g);
    System.out.println("uint64_t: %llu", h);
    System.out.println("boolean: %s", i ? "true" : "false");
    System.out.println("float: %f", k);
    System.out.println("double: %f", l);
    System.out.println("long double: %Lf", m);
    System.out.println("String: %s", n);
    System.out.println("String with space: %s", o);

    free(n);
    free(o);

    return 0;
}