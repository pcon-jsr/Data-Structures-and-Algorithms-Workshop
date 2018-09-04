#include <bits/stdc++.h>
using namespace std;
template<typename T>
bool cmp(T a, T b)
{
	return a>b;
}

template<typename T>
struct triplet
{
	T first, second, third;

	triplet(T a, T b, T c)
	{
		first = a;
		second = b;
		third = c;
	}
	T get_max()
	{

		return max(first,max(second,third));
	}
};
class cmp_length{
	public : bool operator() (string s1, string s2)
	{
		return s1.length() > s2.length();
	}
};

class cmp_mp{
	public : bool operator() (int a, int b)
	{
		return a>b;
	}
};

bool is_volwel(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;
	return false;
}

class cmp_vowels{
	public : bool operator() (string s1, string s2)
	{
		int c1 = 0, c2 = 0;
		for(int i=0; i<s1.length(); i++) if(is_volwel(s1[i])) c1++;
		for(int i=0; i<s2.length(); i++) if(is_volwel(s2[i])) c2++;
		return c1<c2;
	}
};

template<typename T>
class my_vec
{
	vector<T> v;
	map<T,int> m;

public:
	void push(T x)
	{
		v.push_back(x);
		m[x]++;
	}

	int size()
	{
		return v.size();
	}

	T pop()
	{
		T x = v.back();
		v.pop_back();
		m[x]--;
		return x;
	}

	T operator[] (int i)
	{
		return v[i];
	}

	int get_freq(int i)
	{
		return m[v[i]];
	}

};



int main() {
	ios_base::sync_with_stdio(false);
	
	std::vector< pair<int,int> > v(5);
	for(int i=1; i<=5; i++) v[i-1] = make_pair(i,i*2);

	for(vector< pair<int,int> >::iterator it = v.begin(); it!=v.end(); it++) cout<<(*it).first<<" ";

	cout<<endl;

	for(auto it : v) cout<<it.second<<" ";

	cout<<endl;

	std::vector< std::vector<int> > v1(4, std::vector<int>(5,1));
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
			v1[i][j] = i*j;
	}



	for(auto it1 : v1)
	{
		for(auto it2 : it1)
			cout<<it2<<" ";
		cout<<endl;
	}

	cout<<endl;

	v1[2].erase(v1[2].begin() + 2);

	for(auto it1 : v1)
	{
		for(auto it2 : it1)
			cout<<it2<<" ";
		cout<<endl;
	}

	cout<<endl;

	vector< vector< vector< int > > > v2( 3, vector< vector<int> >(4, vector<int>(5,1) ) );

	for(auto it1 : v2)
	{
		for(auto it2 : it1)
		{
			for(auto it3 : it2)
			{
				cout<<it3<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	std::vector< int > v3(5);
	std::vector<float> v4(5);

	for(int i=0; i<5; i++)
	{
		v3[i] = i*2 - 3;
		v4[i] = i/3.0;
	}

	cout<<cmp(2,1)<<endl;

	sort(v3.begin(), v3.end(), cmp<int>);

	sort(v4.begin(), v4.end(), cmp<float>);

	for(int i=0; i<5; i++) cout<<v3[i]<<" ";

	cout<<endl;

	for(int i=0; i<5; i++) cout<<v4[i]<<" ";

	cout<<endl;

	triplet<int> t1(3,1,2);
	cout<<t1.first<<" "<<t1.second<<" "<<t1.third<<" "<<t1.get_max()<<endl;

	triplet<double> t2(0.3,11.52,2.42);
	cout<<t2.first<<" "<<t2.second<<" "<<t2.third<<" "<<t2.get_max()<<endl;

	set<string, cmp_length> st;

	pair< set<string>::iterator , bool > ret = st.insert("a");
	cout<< ret.second<<endl;

	ret = st.insert("abcd");
	cout<< ret.second<<endl;

	ret = st.insert("abce");
	cout<< ret.second<<endl;

	ret = st.insert("bacas");
	cout<< ret.second<<endl;

	ret = st.insert("ab");
	cout<< ret.second<<endl;

	for(auto s : st) cout<<s<<" ";
		cout<<endl;

	priority_queue< int , std::vector<int> , greater<int> > min_heap;

	min_heap.push(4);
	min_heap.push(1);
	min_heap.push(5);
	min_heap.push(7);

	while(!min_heap.empty())
	{
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
	cout<<endl;


	priority_queue< string , std::vector<string> , cmp_vowels > max_volwels;

	max_volwels.push("abcedf");
	max_volwels.push("aaaee");
	max_volwels.push("erfgt");
	max_volwels.push("aei");

	while(!max_volwels.empty())
	{
		cout<<max_volwels.top()<<" ";
		max_volwels.pop();
	}
	cout<<endl;

	my_vec<int> mv;
	mv.push(1);
	mv.push(2);
	mv.push(3);
	mv.push(4);
	mv.push(2);
	mv.push(2);
	mv.push(3);
	mv.push(5);

	for(int i=0; i<mv.size(); i++)
	{
		cout<<mv[i]<<" "<<mv.get_freq(i)<<endl;
	}

	int x = mv.pop();
	cout<<x<<endl;
	x = mv.pop();
	cout<<x<<endl;

	for(int i=0; i<mv.size(); i++)
	{
		cout<<mv[i]<<" "<<mv.get_freq(i)<<endl;
	}


	map<int, int, cmp_mp> mabc;
	mabc[2] = 3;
	mabc[3] = 5;
	mabc[4] = 1;
	cout<<"done";
	return 0;
}