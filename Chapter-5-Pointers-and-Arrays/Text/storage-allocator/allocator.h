/* This ensure that the header file is included only one. It does the same
   thing that we did with #ifndef, #define and #endif in the reverse-polish-calculator 
   program. However, it has the advantage of not being worried about the
   uniqueness of the of keyword included after #define. */
#pragma once

char *alloc(int);
void afree (char *);
int free_space(void);