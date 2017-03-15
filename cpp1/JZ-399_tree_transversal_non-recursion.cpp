#include <iostream>

/*******前序遍历的非递归实现代码如下********/
void pre_traverse(BTree pTree)
{
    PSTACK stack = create_stack();  //创建一个空栈
    BTree node_pop;                 //用来保存出栈节点
    BTree pCur = pTree;             //定义用来指向当前访问的节点的指针

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !is_empty(stack))
    {
        //从根节点开始，输出当前节点，并将其入栈，
        //同时置其左孩子为当前节点，直至其没有左孩子，及当前节点为NULL
        printf("%c ", pCur->data);
        push_stack(stack,pCur);
        pCur = pCur->pLchild;
        //如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，
        //同时置其右孩子为当前节点,循环判断，直至pCur不为空
        while(!pCur && !is_empty(stack))
        {
            pCur = getTop(stack);
            pop_stack(stack,&node_pop);
            pCur = pCur->pRchild;
        }
    }
}

/*******中序遍历的非递归实现代码********/
void in_traverse(BTree pTree)
{
    PSTACK stack = create_stack();  //创建一个空栈
    BTree node_pop;                 //用来保存出栈节点
    BTree pCur = pTree;             //定义指向当前访问的节点的指针

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !is_empty(stack))
    {
        if(pCur->pLchild)
        {
            //如果pCur的左孩子不为空，则将其入栈，并置其左孩子为当前节点
            push_stack(stack,pCur);
            pCur = pCur->pLchild;
        }
        else
        {
            //如果pCur的左孩子为空，则输出pCur节点，并将其右孩子设为当前节点，看其是否为空
            printf("%c ", pCur->data);
            pCur = pCur->pRchild;
            //如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，
            //同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空
            while(!pCur && !is_empty(stack))
            {
                pCur = getTop(stack);
                printf("%c ",pCur->data);
                pop_stack(stack,&node_pop);
                pCur = pCur->pRchild;
            }
        }
    }
}

/*******后序遍历的非递归实现代码********/

void post_traverse(BTree pTree)
{
    PSTACK stack = create_stack();  //创建一个空栈
    BTree node_pop;          //用来保存出栈的节点
    BTree pCur;              //定义指针，指向当前节点
    BTree pPre = NULL;       //定义指针，指向上一各访问的节点

    //先将树的根节点入栈
    push_stack(stack,pTree);
    //直到栈空时，结束循环
    while(!is_empty(stack))
    {
        pCur = getTop(stack);   //当前节点置为栈顶节点
        if((pCur->pLchild==NULL && pCur->pRchild==NULL) ||
           (pPre!=NULL && (pCur->pLchild==pPre || pCur->pRchild==pPre)))
        {
            //如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，
            //则直接输出该节点，将其出栈，将其设为上一个访问的节点
            printf("%c ", pCur->data);
            pop_stack(stack,&node_pop);
            pPre = pCur;
        }
        else
        {
            //如果不满足上面两种情况,则将其右孩子左孩子依次入栈
            if(pCur->pRchild != NULL)
                push_stack(stack,pCur->pRchild);
            if(pCur->pLchild != NULL)
                push_stack(stack,pCur->pLchild);
        }
    }
}

/*******宽度遍历的非递归实现代码如下********/

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Iterative method to find height of Bianry Tree
void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)  return;

    // Create an empty queue for level order tarversal
    queue<pair<Node *,int>> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}