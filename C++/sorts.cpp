// Here are some popular sorting algorithms written in C++
// All these functions accept a comparator

#include <iostream>

using namespace std;

typedef long long t_array_el; // Array elements type
typedef int t_array_su; // Array subscript type (you probably don't need to touch this one)

//======================[QuickSort]======================

//this is a randomized version of quicksort
//note that it uses rand() function

void QuickSort(t_array_el* a, t_array_su l, t_array_su r, bool cmp(t_array_el , t_array_el) = [] (t_array_el a, t_array_el b) -> bool {return a<b;})
{
    t_array_el piv = a[l + rand()%(r-l+1)];
    t_array_su b=l, e=r;
    while(b<=e)
    {
        while(cmp(a[b], piv)) b++;
        while(cmp(piv, a[e])) e--;
        if(b<=e)
        {
            swap(a[b], a[e]);
            b++; e--;
        }
    }
    if(e>l) QuickSort(a, l, e, cmp);
    if(r>b) QuickSort(a, b, r, cmp);
}

//======================[MergeSort]======================

void MergeS(t_array_el* a, t_array_su na, t_array_el* b, t_array_su nb, t_array_el* c, bool cmp(t_array_el, t_array_el))
{
    t_array_su ia=0, ib=0;
    for(t_array_su i=0; i<na+nb; ++i)
    {
        if(ia < na && (ib == nb || cmp(a[ia], b[ib]))) {c[i]=a[ia]; ia++;}
        else {c[i]=b[ib]; ib++;}
    }
}

void MergeSort(t_array_el* c, t_array_su n, bool cmp(t_array_el, t_array_el) = [] (t_array_el a, t_array_el b) -> bool {return a<b;})
{
    if(n>1)
    {
        t_array_el a[n/2], b[n-n/2];
        for(t_array_su i=0; i<n/2; ++i) a[i]=c[i];
        for(t_array_su i=0; i<n-n/2; ++i) b[i]=c[n/2+i];
        MergeSort(a, n/2, cmp);
        MergeSort(b, n-n/2, cmp);
        MergeS(a, n/2, b, n-n/2, c, cmp);
    }
}

//======================[HeapSort]======================

void sorttree(t_array_el a[], t_array_su n, t_array_su v, bool cmp(t_array_el, t_array_el))
{
    t_array_su p=v, l=2*v+1, r=2*v+2;
    if(r<n && cmp(a[p], a[r])) p=r;
    if(l<n && cmp(a[p], a[l])) p=l;
    if(p != v)
    {
        swap(a[p], a[v]);
        sorttree(a, n, p, cmp);
    }
}

void HeapSort(t_array_el a[], t_array_su n, bool cmp(t_array_el, t_array_el) = [] (t_array_el a, t_array_el b) -> bool {return a<b;})
{
    for(t_array_su h=n/2-1; h>=0; --h) sorttree(a, n, h, cmp);
    for(t_array_su h=n-1; h>=0; --h)
    {
        swap(a[0], a[h]);
        sorttree(a, h, 0, cmp);
    }
}

//======================[Example]======================

int main()
{
	// An example of QuickSort usage

	t_array_su N; std::cin >> N; // Read an array size

	t_array_el a[N]; for(t_array_su i=0; i<N; ++i) std::cin >> a[i]; // Read an array

	QuickSort(a, 0, N-1); // Launch QuickSort with default comparator

	for(t_array_su i=0; i<N; ++i) std::cout << a[i] << " "; std::cout << std::endl; // Print an array

    return 0;
}
