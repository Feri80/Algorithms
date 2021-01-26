// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(PT p, PT q, PT r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}
//returns true if line segment 'p1q1' and 'p2q2' intersect.
// oriention code is in convex hull ( change Point to PT first! )
bool segmentIntersect(PT p1, PT q1, PT p2, PT q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  if (o1 != o2 && o3 != o4)
      return true;
   // p1, q1 and p2 are colinear and p2 lies on segment p1q1
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  return false;
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine (PT a, PT b, PT c){
  return a + (b-a)*dot(c-a,b-a)/dot(b-a,b-a);
}
// project point c onto line segment through a and b
PT ProjectPointSegment (PT a, PT b, PT c){
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a,b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}
//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double LinePointDist(PT A, PT B, PT C, bool isSegment){
    double dd = cross(B-A,C-A) / dist(A,B);
    if(isSegment){
        int dot1 = dot(B-A,C-B);
        if(dot1 > 0)return dist(B,C);
        int dot2 = dot(A-B,C-A);
        if(dot2 > 0)return dist(A,C);
    }
    return abs(dd);
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane (double x, double y, double z,
         double a, double b, double c, double d){
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
// determine if two lines are parallel or collinear
bool LinesParallel (PT a, PT b, PT c, PT d){ 
  return fabs(cross(b-a,c-d)) < EPS; 
}
bool LinesCollinear (PT a, PT b, PT c, PT d){ 
  return LinesParallel(a,b,c,d) && fabs(cross(a-c,d-c)) < EPS; 
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists ( check collinear parallel )
PT ComputeLineIntersection (PT a, PT b, PT c, PT d){
  b=b-a; d=c-d; c=c-a;
  if (dot(b,b) < EPS) return a;
  if (dot(d,d) < EPS) return c;
  return a + b*cross(c,d)/cross(b,d);
}
// the relation of the point p and the segment p1->p2.
// 1 if point is on the segment; 0 if not on the line; 
// -1 if on the line but not on the segment
int pAndSeg(PT& p1, PT& p2, PT& p) {
  double s=abs(SignedTriArea(p, p1, p2));
  if(s>EPS) return(0);
  double sg=(p.x-p1.x)*(p.x-p2.x);
  if(sg>EPS) return(-1);
  sg=(p.y-p1.y)*(p.y-p2.y);
  if(sg>EPS) return(-1);
  return(1);
}