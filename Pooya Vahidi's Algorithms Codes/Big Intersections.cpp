// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CLIntersection (PT a, PT b, PT c, double r){
  vector<PT> ret;
  PT d = b-a;
  double D = cross(a-c,b-c);
  double e = r*r*dot(d,d)-D*D;
  if (e < 0) return ret;
  e = sqrt(e);
  ret.push_back (c+PT(D*d.y+(d.y>=0?1:-1)*d.x*e,-D*d.x+fabs(d.y)*e)/dot(d,d));
  if (e > 0)
    ret.push_back (c+PT(D*d.y-(d.y>=0?1:-1)*d.x*e,-D*d.x-fabs(d.y)*e)/dot(d,d));
  return ret;
}
// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CCIntersection (PT a, PT b, double r, double R){
  vector<PT> ret;
  double d = sqrt(dist2(a,b));
  if (d > r+R || d+min(r,R) < max(r,R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  PT v = (b-a)/d;
  ret.push_back (a+v*x + RotateCCW90(v)*y);
  if (y > 0) 
    ret.push_back (a+v*x - RotateCCW90(v)*y);
  return ret;
}
vector<PT> PPIntersection(vector<PT>& p1, vector<PT>& p2) {
	vector<PT> pts;
	PT pp; pts.clear();
	int m=p1.size(), n=p2.size();
	for(int i=0;i<m;i++)
		if(PointInPolygon(p2, p1[i])!=0) pts.push_back(p1[i]);
	for(int i=0;i<n;i++)
		if(PointInPolygon(p1, p2[i])!=0) pts.push_back(p2[i]);
	if(m>1 && n>1)
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if( !LinesParallel(p1[i], p1[(i+1)%m], p2[j], p2[(j+1)%n]) ) {
					pp = ComputeLineIntersection(p1[i], p1[(i+1)%m], p2[j], p2[(j+1)%n]);
					if(pAndSeg(p1[i], p1[(i+1)%m], pp)!=1) continue;
					if(pAndSeg(p2[j], p2[(j+1)%n], pp)!=1) continue;
					pts.push_back(pp);
				}
	if(pts.size()<=1) 
		pts.clear();
	return pts;
}
// cut the convex polygon pol along line p1->p2;
// pol1 are the resulting polygon on the left side, pol2 on the right.
void cutPoly(vector<PT>& pol, PT& p1, PT& p2, vector<PT>& pol1, vector<PT>& pol2) {
	pol1.clear(); pol2.clear();
	int i, sg, n=pol.size();
	PT q1,q2,r;
	for(i=0;i<n;i++) {
		q1=pol[i]; q2=pol[(i+1)%n];
		sg=orientation(p1, p2, q1);
		if(sg==0 || sg==2) pol1.push_back(q1);
		if(sg==0 || sg==1) pol2.push_back(q1);
		if( !LinesParallel(p1, p2, q1, q2) ) {
			r = ComputeLineIntersection(p1, p2, q1, q2);
			if(pAndSeg(q1, q2, r)==1) {
				pol1.push_back(r);
				pol2.push_back(r);
			}
		}
	}
	if(pol1.size()<=2) pol1.clear();
	if(pol2.size()<=2) pol2.clear();
}