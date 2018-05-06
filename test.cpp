#include "step_iterator.h"
#include <vector>
#include <iostream>

int main(){
		using namespace std;
		vector<int> a={1,2,3,4,5,6};
		copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
		cout<<endl;
		step_iterator1<typename vector<int>::iterator> s1(a.begin()), s2(a.end());
//		copy(s1, s2, ostream_iterator<int>(cout," "));
		for(auto i=s1;i!=s2;i++)
				cout<<*i<<" ";
		cout<<endl;
		step_iterator2<typename vector<int>::iterator> s3(a.begin()), s4(a.end());
		copy(s3, s4, ostream_iterator<int>(cout," "));
		cout<<endl;

		return 0;
}
