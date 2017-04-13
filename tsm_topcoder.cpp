#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void sort_visit(vector<int>& v,int lb,int ub){
	int pi = ub;
	int l=lb;
	int u=ub;
	if(lb>=ub)
		return;
	ub=ub-1;
	while(lb<=ub){
		while(lb<pi && v[lb] >= v[pi])
			lb++;
		while(lb<=ub && v[ub]<v[pi])
			ub--;
		if(lb < ub) {
			swap(v[lb], v[ub]);
			lb++;
			ub--;
		}
	}
	swap(v[lb], v[pi]);
	sort_visit(v, l, lb-1);
	sort_visit(v, lb+1, u);
}

void sort_profit(vector<int>& p, vector<int>& c, int lb,int ub){
	int pi = ub;
	int l=lb;
	int u=ub;
	if(lb>=ub)
		return;
	ub=ub-1;
	while(lb<=ub){
		while(lb<pi && p[lb] >= p[pi])
			lb++;
		while(lb<=ub && p[ub]<p[pi])
			ub--;
		if(lb < ub) {
			swap(p[lb], p[ub]);
			swap(c[lb], c[ub]);
			lb++;
			ub--;
		}
	}
	swap(p[lb], p[pi]);
	swap(c[lb], c[pi]);
	sort_profit(p, c, l, lb-1);
	sort_profit(p, c, lb+1, u);
}

int search_visit(vector<int>& v, int lb, int ub, int k){
	int ret =0;
	int l=lb;
	int u=ub;
	int mid;
	if(lb>ub)
		return 0;
	mid = u - (u-l)/2;
	if (k>=abs(v[mid])){
		if(!(v[mid]<0 && k == abs(v[mid])))
			ret = search_visit(v,lb,mid-1,k);
	}
	if(!ret && k==v[mid]){
		v[mid]=-v[mid];
		ret=1;
		return ret;
	}
	if(k <= abs(v[mid]) && !ret)
		ret = search_visit(v,mid+1,ub,k);
	return ret;
}

int main(){
	int tot_profit =0;
	int pa[]={22,91,53,7,80,100,36,65,92,93,19,92,95,3,60,50,39,36,2,30,63,84,2};
	int ca[]={5,3,4,3,6,5,6,6,5,2,7,6,3,2,6,1,7,4,6,3,7,2,5};
	int va[]={5,7,1,3,6,2,5,7,3,6,3,2,7,3,1,3,1,7,2,3,1,1,3,1,6,1};
	vector<int> p(pa,pa+sizeof(pa)/sizeof(pa[0]));
	vector<int> c(ca,ca+sizeof(ca)/sizeof(ca[0]));
	vector<int> v(va,va+sizeof(va)/sizeof(va[0]));
	cout<<"111"<<endl;
	sort_profit(p,c,0,p.size()-1);
	for(int i=0; i<p.size();i++)
		cout<<p[i]<<"   ";
	cout<<endl;
	for(int i=0; i<c.size();i++)
		cout<<c[i]<<"   ";
	cout<<endl;
	sort_visit(v,0,v.size()-1);
	for(int i=0; i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	for(int i=0;i<c.size();i++){
		if(search_visit(v,0,v.size()-1,c[i])){
			cout<<p[i]<<endl;
			tot_profit+=p[i];
		}
	}
	cout<<tot_profit<<endl;
	return 0;
}
