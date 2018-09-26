#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {int x; int y;};

inline int Sor(const Point& a, const Point& b, const Point& c) {return (b.x-a.x)*(b.y+a.y)+(c.x-b.x)*(c.y+b.y)+(a.x-c.x)*(a.y+c.y);}

void Pprint(const Point& a) {printf("(%d;%d) ", a.x, a.y);}

int main()
{
    int n; cin >> n;
    Point points[n]; // here we store points
    
    for(int i=0; i<n; ++i)
        cin >> points[i].x >> points[i].y;

    sort(points, points+n, [](Point a, Point b)->bool{return a.x == b.x ? a.y < b.y : a.x < b.x;});

    vector <int> stack1,stack2; // here we only store the IDs for points[]
    stack1.push_back(n-1);
    stack1.push_back(0);
    stack2.push_back(n-1);
    stack2.push_back(0);

    for(int i=1; i<n; ++i)
    {
        if(Sor(points[n-1], points[0], points[i]) > 0)
        {
            while(stack1.size() > 2 && Sor(points[stack1[stack1.size()-2]], points[stack1[stack1.size()-1]], points[i]) <= 0) stack1.pop_back();
            stack1.push_back(i);
        }
        else if(Sor(points[n-1], points[0], points[i]) < 0)
        {
            while(stack2.size() > 2 && Sor(points[stack2[stack2.size()-2]], points[stack2[stack2.size()-1]], points[i]) >= 0) stack2.pop_back();
            stack2.push_back(i);
        }
    }


    while(stack1.size() > 3 && Sor(points[stack1[stack1.size()-2]], points[stack1[stack1.size()-1]], points[n-1]) <= 0) stack1.pop_back();
    while(stack2.size() > 3 && Sor(points[stack2[stack2.size()-2]], points[stack2[stack2.size()-1]], points[n-1]) >= 0) stack2.pop_back();

    printf("A");Pprint(points[0]); for(int i=2; i<(int)stack1.size(); ++i) Pprint(points[stack1[i]]);
    printf("B");Pprint(points[n-1]); for(int i=(int)stack2.size()-1; i>1; --i) Pprint(points[stack2[i]]);
    printf("\n");

    return 0;
}
