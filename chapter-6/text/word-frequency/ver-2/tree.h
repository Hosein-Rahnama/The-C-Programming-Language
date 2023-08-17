#ifndef TREE
#define TREE

typedef struct tnode *Treeptr;

typedef struct tnode        // The tree node
{                  
    char *word;             // Points to the text
    int count;              // Number of occurences
    Treeptr left;           // Left child
    Treeptr right;          // Right child
} Treenode;

Treeptr addtree(Treeptr, char *);
void treeprint(Treeptr);
Treeptr talloc(void);

#endif