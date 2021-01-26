// 1 if p is in pv; 0 outside; -1 on the polygon
int PointInPolygon(vector<PT> pv, PT p) {
	int n=pv.size(), j; pv.push_back(pv[0]);
	for(int i=0;i<n;i++)
		if(pAndSeg(pv[i], pv[i+1], p)==1) return(-1);
	for(int i=0;i<n;i++) pv[i] = pv[i]-p;
	p.x=p.y=0.0; double a, y;
	while(1) {
		a=(double)rand()/10000.00;
		j=0;
		for(int i=0;i<n;i++) {
			pv[i] = RotateCCW(pv[i], a);
			if(abs(pv[i].x)<EPS) j=1;
		}
		if(j==0) {
			pv[n]=pv[0];
			j=0;
			for(int i=0;i<n;i++) 
				if(pv[i].x*pv[i+1].x < -EPS) {
					y=pv[i+1].y-pv[i+1].x*(pv[i].y-pv[i+1].y)/(pv[i].x-pv[i+1].x);
					if(y>0) j++;
				}
			return(j%2);
		}
	}
	return 1;
}