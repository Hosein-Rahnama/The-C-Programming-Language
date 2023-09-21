#ifndef DIRC
#define DIRC

#include <fcntl.h>

#define BUFSIZE 48
#define NAMEMAX 256                 // Longest filename component; system-dependent

typedef struct linux_dirent         // Local directory entry 
{   
    long           d_ino;           // Inode number
    off_t          d_off;           // Offset to next linux_dirent
    unsigned short d_reclen;        // Length of this linux_dirent
    char           d_name[];        // Name
} LinuxDirEnt;

typedef struct                      // Portable directory entry
{
    long ino;                       // Inode number
    char name[NAMEMAX + 1];         // Name
} DirEnt;

typedef struct                      // Minimal Dir; no buffering, etc
{
    int    fd;                      // File descriptor for directory
    DirEnt d;                       // The directory entry
} Dir;

Dir *open_dir(char *);
DirEnt *read_dir(Dir *);
LinuxDirEnt *read_dirent(int);
void close_dir(Dir *);

#endif