#ifndef SORT
#define SORT

#define MAXLINES 5000           // Maximum number of lines to be sorted
#define MAXLEN 1000             // Maximum length of any input line

char *alloc(int n);
void afree (char *p);
int getline(char line[], int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

#endif