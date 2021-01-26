double INF = 1e100;
double EPS = 1e-8;
struct PT { 
  double x, y; 
  PT (){}
  PT (double x, double y) : x(x), y(y){}
  PT (const PT &p) : x(p.x), y(p.y){}
  PT operator- (const PT &p){ return PT(x-p.x,y-p.y); }
  PT operator+ (const PT &p){ return PT(x+p.x,y+p.y); }
  PT operator* (double c){ return PT(x*c,y*c); }
  PT operator/ (double c){ return PT(x/c,y/c); }
};
double dot (PT p, PT q){ return p.x*q.x+p.y*q.y; }
double dist2 (PT p, PT q){ return dot(p-q,p-q); }
double dist (PT p, PT q) { return sqrt( dist2(p, q) ); }
double cross (PT p, PT q){ return p.x*q.y-p.y*q.x; }
// rotate a point CCW or CW around the origin
PT RotateCCW90 (PT p){ return PT(-p.y,p.x); }
PT RotateCW90 (PT p){ return PT(p.y,-p.x); }
PT RotateCCW (PT p, double t){ 
  return PT(p.x*cos(t)-p.y*sin(t),
      p.x*sin(t)+p.y*cos(t)); 
}
// rotate p1 around p0 clockwise, by angle a
PT RotateC(PT p0, PT p1, double a) {
	p1 = p1-p0;
	return p0 + PT(cos(a)*p1.x-sin(a)*p1.y,
	sin(a)*p1.x+cos(a)*p1.y);
}
// p1->p2 line, reflect p3 to get r.
PT reflect(PT& p1, PT& p2, PT p3) {
	if(dist(p1, p3)<EPS) {return p3;}
	double a=dot(p2-p1,p3-p1)/(dist(p1,p2)*dist(p1,p3));
	a=acos(a); 
	return RotateC(p1, p3, -2.0*a);
}
double SignedTriArea (PT a, PT b, PT c) {
  return( (a.x*b.y - a.y*b.x + a.y*c.x
  - a.x*c.y + b.x*c.y - c.x*b.y) / 2.0 );
}
double SignedArea (vector<PT> v){
  double area = 0;
  for (int i = 0; i < v.size(); i++){
    int j = (i+1) % v.size();
    area += v[i].x*v[j].y - v[j].x*v[i].y;
  }
  return area / 2.0;
}
