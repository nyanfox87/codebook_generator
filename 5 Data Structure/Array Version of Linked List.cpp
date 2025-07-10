/*看不懂cut the node
實際用法需要理解     */
struct node{
    struct node *nxt, *prv;
    long long v;
}pos[100002];

inline node* cut(node *p) // cut the node
{
    p->nxt->prv = p->prv;
    p->prv->nxt = p->nxt;
    p->nxt = p->prv = NULL;
    return p;
}

inline node* insert(node *p, node *q) // insert node q to right side of node p
{
    q->nxt = p->nxt;
    p->nxt->prv = q;
    q->prv = p;
    p->nxt = q;
    return q;
}