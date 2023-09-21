#ifndef USRIO
#define USRIO

#undef NULL

#define NULL     0
#define EOF      (-1)
#define BUFSIZ   1024
#define OPEN_MAX 20     // Maximum number of files open at once

typedef struct _iobuf 
{
    int cnt;            // Characters left in buffer
    char *ptr;          // Next character position in buffer
    char *base;         // Location of buffer
    int flag;           // Mode of file access
    int fd;             // File descriptor
} FILE;
extern FILE _iob[];

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags
{
    _READ  = 01,        // File open for reading
    _WRITE = 02,        // File open for writing
    _UNBUF = 04,        // File is unbuffered
    _EOF   = 010,       // EOF has occurred on this file
    _ERR   = 020        // Error has occurred on this file
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);
FILE *fopen(char *, char *);

#define feof(p)   (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p)    (--(p)->cnt >= 0 ? (unsigned char)(*(p)->ptr++) : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar()  getc(stdin)
#define putchar(x) putc((x), stdout)

#endif