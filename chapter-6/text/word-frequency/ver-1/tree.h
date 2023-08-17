#ifndef TREE
#define TREE

struct tnode                    // The tree node
{                  
    char *word;                 // Points to the text
    int count;                  // Number of occurences
    struct tnode *left;         // Left child
    struct tnode *right;        // Right child
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);

#endif