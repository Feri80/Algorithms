//O(n log n) 0-base
struct PT { int x; int y; };
vector<PT> p; //PTs of the Polygon to be processed
vector<PT> S; //Contains the convex hull
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big?????
int orientation(PT p1, PT p2, PT p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);
    if (abs(val) < EPS) return 0;  // colinear
    return (val > 0)? 1: 2; // clock(1) or counterclockwise(2)
}
//Returns the square of distance
int distSq(PT p1, PT p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
bool cmp (PT p1, PT p2) {
	int o = orientation(p1, p[0], p2);
	if (o==0) return (distSq(p[0], p1) <= distSq(p[0], p2));
	return (o==1);
}
void convexHull (int n=p.size()) {
	// Find the bottommost-leftmost PT
   int ymn = p[0].y, mn = 0;
   for (int i = 1; i < n; i++) {
     int y = p[i].y;
     if ((y < ymn) || (ymn == y && p[i].x < p[mn].x))
        ymn = p[i].y, mn = i;
   }
   swap(p[0], p[mn]);
   sort(p.begin()+1, p.end(), cmp);
   int m=1; //Removing collinears and same PTs
   for (int i=1; i<n; i++) {
       while (i < n-1 && orientation(p[0], p[i], p[i+1]) == 0)
          i++;
       p[m] = p[i]; m++;
   }
   if (m<3) return; // Go for the convex hull
   S.push_back(p[0]); S.push_back(p[1]); S.push_back(p[2]);
   for (int i = 3; i < m; i++) {
      // Keep removing top while the turn is not ccw
      while (orientation(S[S.size()-2], S[S.size()-1], p[i]) != 2)
         S.pop_back();
      S.push_back(p[i]);
   }
}
// return 0 if not convex, 1 if strictly convex,
// 2 if convex but there are points unnecesary
// this function does not work if the polygon is self intersecting
// in that case, compute the convex hull of v, and see if both have the same area
int isConvex( vector<PT>& v ) {
   int c0=0, c1=0, c2=0, n=v.size();
   for ( int i=0; i<n; i++ ) {
		int j=(i+1)%n; k=(i+2)%n;
		int s=orientation(v[i], v[j], v[k]);
		if (s==0) c0++;
		if (s==2) c1++;
		if (s==1) c2++;
   }
   if(c1 && c2) return 0;
   if(c0) return 2;
   return 1;
}