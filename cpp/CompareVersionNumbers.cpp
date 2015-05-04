#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = version1.find('.');
        int pos2 = version2.find('.');

        if(pos1 == -1 && pos2 == -1) {
        	int tmp1 = atoi(version1.c_str());
        	int tmp2 = atoi(version2.c_str());

        	cout<<"tmp1: "<<tmp1<<"\t";
        	cout<<"tmp2: "<<tmp2<<endl;
        	if(tmp1 < tmp2) {
        		return -1;
        	} else if(tmp1 > tmp2) {
        		return 1;
        	} else {
        		return 0;
        	}
        }

        if(pos1 == -1) {
        	version1.append(".0");
        	pos1 = version1.find('.');
        }
        if(pos2 == -1) {
        	version2.append(".0");
        	pos2 = version2.find('.');
        }

        string front1 = version1.substr(0, pos1);
        string front2 = version2.substr(0, pos2);

        cout<<"front1: "<<front1<<"\t";
        cout<<"front2: "<<front2<<endl;

        int i1 = atoi(front1.c_str());
        int i2 = atoi(front2.c_str());
        if (i1 < i2) {
        	return -1;
        } else if(i1 > i2) {
        	return 1;
        } else {
        	string back1 = version1.substr(pos1 + 1);
        	string back2 = version2.substr(pos2 + 1);

        	return this->compareVersion(back1, back2);
        }
    }
};


int main() {
	string s1, s2;
	cin>>s1>>s2;
	Solution *sol = new Solution;
	int rs = sol->compareVersion(s1, s2);
	cout<<rs<<endl;
	return 1;
}