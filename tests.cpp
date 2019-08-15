#include"seral.hpp"
#include<set>
#include<cstdlib>
using namespace std;
set<int> a;
string&& inttostr(const int& a){
	char buf[16];
	sprintf(buf,"%d",a);
	return string(buf);
}
int main(){
a.insert(1);
a.insert(2);
char* m;
printf("%d\n",settomem(a,&m,inttostr));
printf("%p %p",*((long long*)m),*((long long*)m+1));
}
