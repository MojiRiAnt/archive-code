#include <bits/stdc++.h>
#define MAXN 10012
using namespace std;

//To be revised in the future
//Nevertheless, it works already

int n;

struct pst_t
{
    int size;
    int roots[MAXN];
    struct {int v,l,r;} st[64*MAXN];
    pst_t()
    {
        size = 0;
        roots[0] = 0;
    }

    inline int vcopy(int x)
    {
        ++size;
        st[size] = st[x];
        return size;
    }

    void update(int pos, int val, int cpos = 0, int cl = 1, int cr = n)
    {
        if(cl == cr)
        {
            st[cpos].v = val;
            return;
        }
        int cm = (cl+cr)>>1;
        if(pos <= cm)
        {
            st[cpos].l = vcopy(st[cpos].l);
            update(pos, val, st[cpos].l, cl, cm);
        }
        else
        {
            st[cpos].r = vcopy(st[cpos].r);
            update(pos, val, st[cpos].r, cm+1, cr);
        }
    }

    inline int get(int pos, int cpos, int cl = 1, int cr = n)
    {
        if(cl == cr)
        {
            return st[cpos].v;
        }
        int cm = (cl+cr)>>1;
        if(pos <= cm)
        {
            return get(pos, st[cpos].l, cl, cm);
        }
        else
        {
            return get(pos, st[cpos].r, cm+1, cr);
        }
    }
};


signed main()
{
    pst_t tree1;

    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {int a; scanf("%d", &a); tree1.update(i, a);}

    int k; scanf("%d", &k);
    for(int i=1; i<=k; ++i)
    {
        int m,x,y; scanf("%d%d%d", &m, &x, &y);
        if(y == 0)
        {
            printf("%d\n", tree1.get(x, tree1.roots[m]));
        }
        else
        {
            tree1.roots[i] = tree1.vcopy(tree1.roots[m]);
            tree1.update(x, y, tree1.roots[i]);
        }
    }
}
