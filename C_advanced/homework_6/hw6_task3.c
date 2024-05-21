//Задание 3. Разница между элементами

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef struct tree {
    int key;
    struct tree *left, *right, *parent;
} tree;

int tree_max(struct tree* tr)
{
    int max_left = tr->key;
    int max_right = tr->key;

    if (tr != NULL)
    {
        if (tr->key > max_left)
            max_left = tr->key;

        if(tr->left)
            max_left = tree_max(tr->left);
        
        if(tr->right)
            max_right = tree_max(tr->right);

        if (max_left > max_right) return max_left;
        return max_right;
    }
}

int tree_min(struct tree* tr)
{
    int min_left = tr->key;
    int min_right = tr->key;

    if (tr != NULL)
    {
        if (tr->key < min_left)
            min_left = tr->key;

        if(tr->left)
            min_left = tree_min(tr->left);
        
        if(tr->right)
            min_right = tree_min(tr->right);

        if (min_left < min_right) return min_left;
        return min_right;
    }
}

int main(void)
{
    tree t[10]={0};
    
    t[0].left = t+1;
    t[0].right = t+2;
    t[0].key = 10;
    
    t[1].left = t+3;
    t[1].right = t+4;
    t[1].key = 5;
    t[1].parent = t+0;
    
    t[2].left = t+5;
    t[2].right = t+6;
    t[2].key = 15;
    t[2].parent = t+0;
    
    t[3].left = t+7;
    t[3].parent = t+1;
    t[3].key = 3;
    
    t[4].left = t+8;
    t[4].parent = t+1;
    t[4].key = 7;
    
    t[5].key = 13;
    t[5].parent = t+2;
    
    t[6].key = 18;
    t[6].parent = t+2;
    
    t[7].key = 1;
    t[7].parent = t+3;
    
    t[8].key = 6;
    t[8].parent = t+4;

    int max = tree_max(t);
    int min = tree_min(t);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    printf("Tree max/min difference = %d\n", max - min);

}