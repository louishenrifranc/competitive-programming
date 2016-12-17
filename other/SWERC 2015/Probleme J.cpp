#include<bits/c++io.h>
#include<math.h>
#include<bits/stdc++.h>


struct point
{
    int x;
    int y;
};
point pivot;
std::vector<point> polygon, CH;


int turn(point p, point q, point r)
{
    int result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    if (result < 0) return -1; // P->Q->R is a right turn
    if (result > 0) return 1; // P->Q->R is a left turn
    return 0; // P->Q->R is a straight line, i.e. P, Q, R are collinear
}
// Note: sometimes, we change the ’> 0’ to ’>= 0’ to accept collinear points
bool ccw(point p, point q, point r)
{
    return (turn(p, q, r) > 0);
}

int area2(point a, point b, point c)
{
    return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
}
int abs(int a)
{
    return (a > 0) ? a : -a;
}
int dist2(point a, point b)   // function to compute distance between 2 points
{
    int dx = abs(a.x - b.x), dy = abs(a.y - b.y);
    return dx * dx + dy * dy;
}


/**
*   Etant donné un point fixe, ici c'est le pivot, et une liste de points
*   Trier les points pour
**/
bool angle_cmp(point a, point b)   // important angle-sorting function
{
    if (area2(pivot, a, b) == 0) // collinear
        return dist2(pivot, a) < dist2(pivot, b); // which one closer
    int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2((double)d1y, (double)d1x) - atan2((double)d2y, (double)d2x)) < 0;
}


std::vector<point> GrahamScan(std::vector<point> Polygon)
{
// first, find P0 = point with lowest Y and if tie: rightmost X
    int i, P0 = 0, N = Polygon.size();
    for (i = 1; i < N; i++)
        if (Polygon[i].y  < Polygon[P0].y ||
                (Polygon[i].y == Polygon[P0].y && Polygon[i].x > Polygon[P0].x))
            P0=i;
    point temp = Polygon[0]; // swap selected vertex with Polygon[0]
    Polygon[0] = Polygon[P0];
    Polygon[P0] = temp;
// second, sort points by angle w.r.t. P0, skipping Polygon [0]
    pivot = Polygon[0]; // use this global variable as reference
    std::sort(++Polygon.begin(), Polygon.end(), angle_cmp);
// third, the ccw tests
    std::stack<point> S;
    point prev, now;
    S.push(Polygon[N - 1]); // put two starting vertices into stack S
    S.push(Polygon[0]);
    i = 1; // and start checking the rest
    while (i < N)   // note: N must be >= 3 for this method to work
    {
        now = S.top();
        S.pop();
        prev = S.top();
        S.push(now); // trick to get the 2nd item from top of S
        if (ccw(prev, now, Polygon[i]))   // if these 3 points make a left turn
        {
            S.push(Polygon[i]); // accept
            i++;
        }
        else // otherwise
            S.pop(); // pop this point until we have a left turn
    }
    std::vector<point> ConvexHull;
    while (!S.empty())   // from stack back to vector
    {
        ConvexHull.push_back(S.top());
        S.pop();
    }
    ConvexHull.pop_back(); // the last one is a duplicate of first one
    return ConvexHull; // return the result
}


int main()
{
    std::vector<point> grand;
    std::vector<point> petit;

    std::vector<point> enveloppeConvexe =GrahamScan(grand);
    bool vrai;
    uint16_t nombredepoints = 0;
    for(point p : petit)
    {
        vrai=true;
        for(int i = 0  ; i < enveloppeConvexe.size() ,vrai; i++)
        {

            if(!ccw(enveloppeConvexe[i % enveloppeConvexe.size()],enveloppeConvexe[ (i+1)% enveloppeConvexe.size() ], p))
                vrai =false;
        }
        if(vrai) nombredepoints++;
    }
}
