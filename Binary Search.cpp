int bs(int c)
{
	l=0,r=n;
	while(r-l>1)
	{
		mid=(l+r)/2;
		if(a[mid]>c)
		{
			r=mid;
		}
		if(a[mid]<=c)
		{
			l=mid;
		}
		if(a[l]==c)
		{
			return l;
		}
	}
	return -1;
}