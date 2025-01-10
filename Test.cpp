#include<iostream>
#include<string>
#include<vector>


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
	    
	    void merge(int low,  int  mid , int high) {
	    	vector<User>  list =  {};
	    	int l  = low;
	    	int   r = mid+1;
	    	while(l<=mid &&  r<=high) {
	    		if(user_info[l].mobile_no <= user_info[r].mobile_no) {
	    			list.push_back(user_info[l++]);
	    		}
	    		else {
	    			list.push_back(user_info[r++]);
	    		}
	    	}
	    	while(l<=mid) list.push_back(user_info[l++]);
	    	while(r<=high) list.push_back(user_info[r++]);
	    	for(int i  = low ; i <=high;i++)  user_info[i]=  list[i-low];
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
    
    void   merge_sort(int  low  , int  high) {
    	if(low>=high)  return;
    	int  mid= (low+high)>>1;
    	merge_sort(low,mid);
    	merge_sort(mid+1,high);
    	merge(low,mid,high);
    	
    }
};

int main() {
    int n;
    cout << "Enter number of records: ";
    cin >> n;

    Record rec(n);
    int choice;
    
    do {
        cout << "\n1. Accept Data\n2. Display Data\n3. Quick Sort (Acs MobileNo)\n 4.Heap Sort(Asc BillAmount)\n5. Search Mobile No\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: rec.accept(); break;
            case 2: rec.display(); break;
            case 3: rec.quick_sort(0, n - 1); rec.display(); break;
            case 4: rec.heap_sort(); cout<<"The Final  Dispay  "<<endl; rec.display(); break;
            case 5: {
                int mobile;
                cout << "Enter Mobile No: ";
                cin >> mobile;
                if (rec.binary_search_itr(mobile))
                    cout << "Record Found using Iterative Search!\n";
                else
                    cout << "Record Not Found!\n";

                cout << "Enter Mobile No: ";
                cin >> mobile;
                if (rec.binary_search_rec(mobile, 0, n - 1))
                    cout << "Record Found using Recursive Search!\n";
                else
                    cout << "Record Not Found!\n";
                break;
            }
            case 6:
            		rec.merge_sort(0,n-1);
            
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
