#ifndef HASH
#define HASH

#define HASHSIZE 101

struct nlist                    // Table entry
{
    struct nlist *next;         // Next entry in chain
    char *name;                 // Defined name
    char *defn;                 // Replacement text
};

unsigned int hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void print_table(void);
void init_table(void);

#endif