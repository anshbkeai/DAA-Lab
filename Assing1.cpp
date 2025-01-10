#include<iostream>
#include<string>

using namespace std;

class User {
    private:
        string  name;
        int  mobile_no;
        float  amt;
        friend  class  Record;
    public :
        User(string n,int  m , float a) {
            name  = n;
            mobile_no  = m;
            amt = a;
        }
        User() {
            name  = "";
            mobile_no  = 0;
            amt  = 0.0;
        }
        void  toString() {
            cout<<"User [ name  = "<<name<<" ,mobile_no = "<<mobile_no<<" ,amonunt = "<<amt<<" ]"<<endl;
        }
};

class  Record {
    private :
        int  n;
        User user_info[100];
        void heapify( int  m,int i ) {
            while(2*i+1<=m) {
                int j  =  (i*2)+1;
                if(j+1<=m && user_info[j+1].amt>user_info[j].amt ) j++;
                if(user_info[i].amt >= user_info[j].amt) {
                break;
                }
                else {
                swap(user_info[i],user_info[j]);
                //i=j;
                //cou
                }
            }   
	    }
public  :
	Record(int n  ) {
		this->n  = n ;
		user_info[n];
	}
	void  accept() {
		for(int  i = 0 ;i < n ;i++) {
			string name;
			int  mobile;
			float  a;
			cout<<"Enter the Name "<<endl;
			cin>>name;
			cout<<"Enter the MOBILE no "<<endl;
			cin>>mobile;
			cout<<"Enter the Amount "<<endl;
			cin>>a;
			User u(name,mobile,a);
			user_info[i] =  u;

		}
	}
	void  display() {
		for(int i = 0 ;i <n;i++) {
			user_info[i].toString();
		}
	}
	void  heap_sort() {
		int  m  = n ;
		for(int i  = (m>>1)-1;i>=0;i--) {
			heapify(m-1,i);
		}
		cout<<"TEST "<<endl;
		display();

		while(m>0) {
			cout<<m<<endl;
			swap(user_info[0],user_info[m-1]);
			m--;
			heapify(m-1,0);
			cout<<"After the  HEAPIFY "<<endl;
			display();
		}
	}
    int partition(int  low ,  int high) {
        int piv  = user_info[high].mobile_no;
        int l   =low-1;
        for(int j  = low;j<high;j++) {
            if(user_info[j].mobile_no <=piv) {
                l++;
                swap(user_info[l],user_info[j]);
            }
        }
        swap(user_info[l+1],user_info[high]);
        return  l+1;
    }
    int partition1(int  low ,  int high) {

        int piv  = user_info[high].mobile_no;
        int l   =low;
        int r=  high-1;
        while(l<=r) {
            while(user_info[l].mobile_no <= piv && l<=r) l++;
            
            while(user_info[r].mobile_no>piv && r>=l) r--;
            if(l<r) swap(user_info[l],user_info[r]);
        }
        swap(user_info[l],user_info[high]);
        return  l;
    
   
    }
    void  quick_sort(int  low,  int high) {
        if(low>=high)return;
        int  piv_idx =  partition(low,high); //college  Defined Partition  Function   
        quick_sort(low,piv_idx-1);
        quick_sort(piv_idx+1,high);

    }
    bool  binary_search_rec(int mobile,int l ,  int h) {
        if(l>h) return false;
        int mid  = ((l+h) >> 1);
        if(user_info[mid].mobile_no > mobile ) return binary_search_rec(mobile,l,mid-1);
        else if(user_info[mid].mobile_no < mobile) return  binary_search_rec(mobile,mid+1,h);
        else return  true;
    }

    bool  binary_search_itr(int mobile_no ){
        int  l = 0 ; 
        int  h = n-1;
        while(l<=h) {
            int mid  = ((l+h) >> 1);
            if(user_info[mid].mobile_no > mobile_no ) h = mid-1;
            else if(user_info[mid].mobile_no < mobile_no) l= mid+1;
            else return  true;
        }
        return  false;
    } 
    bool linear_Search(int  mobile ) {
        for(int i  =0 ;i < n;i++) {
            if(user_info[i].mobile_no == mobile) return  true;
        }
        return  false;
    }
};

int main() {
    int n ;
    cin>>n;
    Record rec(n);
    rec.accept();
    rec.display();
    rec.heap_sort();
    cout<<"Final"<<endl;
    rec.display();
    cout<<"Calling  the  Quick  Sort  for  phone  number "<<endl;
    rec.quick_sort(0,n-1);
    rec.display();
    cout<<"Testing  the  Both  BInary  Serch "<<endl;
    cout<<"ENter mobile  "<<endl;
    int mobile;
    cin>>mobile;
    if(rec.binary_search_itr(mobile)) cout<<"Find out th e  Mobile  Numebr  whoo !"<<endl;
    else  cout<<"OOPS  no  Rec  FOund"<<endl;

    cin>>mobile;
    if(rec.binary_search_rec(mobile,0,n-1)) cout<<"Find out th e  Mobile  Numebr  whoo !"<<mobile<<endl;
    else  cout<<"OOPS  no  Rec  FOund"<<endl;
}
