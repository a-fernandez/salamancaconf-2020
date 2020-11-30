#!/bin/sh
gcc -o eco -fno-stack-protector -z execstack -no-pie eco.c
