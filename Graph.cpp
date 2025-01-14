/*
things   yet  to  iimplement  About  that 
I have  implementeed  that  using  the int  values  so  i have  to  modiy  that  Code according  to  that  

BFS  LEFT AND   OTHER  THINGS  ALSO
*/

#include<iostream>
#include<string>
#include<vector>
using  namespace std;
/*
    Class  Graph {
    //they  waant  to  do it  using  the   Adjecy  LIst   
    tyep  of  the  ds  using to  save   th e Graph  the  Matix  ot  the   LIst   Format   
            // we have to  Identify  with the  Tpye vof the   user  and  th e  USer  idv   to  get  the   index  or  we ahve  have the map
            void  init() ; 
            
            void  add_edge() 
    }

*/

class  GNode {
    private :
            int  i;
            
            friend class Graph;
    public  :
        GNode  *next;
       
        GNode(int i) {
            this->i = i ;
            this->next= nullptr;
        }
    
};
class  Graph {
    private :
        int n;
        GNode  *vertex[100];
    public:
            Graph(int  n) {
                //GNode *vertex[n];
                this->n  = n;
                for(int i  = 0 ;i < n  ;i++) {
                    vertex[i] = nullptr;
                    int j;
                    cout<<"Enter  the  Vartex  vlue"<<endl;
                    cin>>j;
                    vertex[i] =  new GNode(j);
                }
            }

            //
            void add_edge_dir(int  v1, int  v2 ) {
                // Considering  the  Grpah s  the  Directed  Grpah 
                for(int i  = 0 ;i <n  ;i++) {
                    
                    if(vertex[i]->i ==  v1) {
                        GNode  *node  =  vertex[i];
                        while(node->next != nullptr) { 
                        //cout<<node->i<<" ";
                        node  =  node->next;
                    
                    }
                        node->next =  new  GNode(v2);
                        break;
                    }
                    
                }
                //itdepenps  upoun  th e  Code   DIracted  ro  Undirecd  
            }

            void  add_edge(int  v1, int  v2) {
                for(int i  = 0 ;i <n  ;i++) {
                    
                    if(vertex[i]->i ==  v1) {
                        GNode  *node  =  vertex[i];
                        while(node->next != nullptr) { 
                        //cout<<node->i<<" ";
                        node  =  node->next;
                    
                    }
                        node->next =  new  GNode(v2);
                        break;
                    }
                    
                }
                for(int i  = 0 ;i <n  ;i++) {
                    
                    if(vertex[i]->i ==  v2) {
                        GNode  *node  =  vertex[i];
                        while(node->next != nullptr) { 
                        //cout<<node->i<<" ";
                        node  =  node->next;
                    
                    }
                        node->next =  new  GNode(v1);
                        break;
                    }
                    
                }
            }

            void  display() {
                for(int i  = 0 ;i < n ;i++){
                   
                    cout<<vertex[i]->i<<"--->";
                    GNode *node  =  vertex[i]->next;
                    while(node != nullptr){ 
                        cout<<node->i<<" ";
                        node  =  node->next;
                    
                    }
                    cout<<endl;
                }
            }
            
            void  dfs_helper(int  v1, vector<bool> &visit) {
                cout<<v1<<"-->";
                
                visit[v1] =  true;
                for(int i  = 0 ;i < n  ;i++) {
                    if(vertex[i]->i == v1) {
                        GNode* node =  vertex[i]->next;
                        while(node != nullptr) {
                            if(!visit[node->i]) dfs_helper(node->i,visit);
                            node=node->next;
                        }
                    }
                }
            }
            void  dfs() {
                vector<bool>  visited(n,false);
                cout<<"Hey  User  Enter  the  Starting of  the Graph where  you  want  to  start "<<endl;
                int   v1;
                cin>>v1;
                dfs_helper(v1,visited);

            }

};

int main() {
    int  v = 5;
    //  we hacve   to  Werie  the  Code   about  the  Graph  and   we  have to  keep  that  simple  
    //Adject  Matix  to  store  
    /*y  
    1.Adjencency  Matix  SPACE  (O(N^2))  they  say  to  Create  a  user and   have  the  Link  Between  ten 
    2.Adjencency  LIst 
    we  can   have  then  
*/
    Graph graph (v);
    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(1,4);
    graph.add_edge(2,3);
    graph.add_edge(3,4);
    
    graph.display();

    graph.dfs();
}
/*
#include <iostream>
using namespace std;

class GNode {
private:
    int i;
    GNode* next;
    friend class Graph;

public:
    GNode(int  n) {
        i  = n ;
        next = nullptr;
    }
};

class Graph {
private:
    int n;                 // Number of vertices
    GNode* vertex[100];    // Array of adjacency list heads (pointers to GNode)

public:
    Graph(int v) {
        n  =v;
       // GNode *vertex[n];
        for (int i = 0; i < n; i++) {
            vertex[i] = nullptr; // Initialize all vertices as null
            cout << "Enter the vertex value ";
            int val;
            cin >> val;
            vertex[i] = new GNode(val); // Dynamically allocate a new GNode
        }
    }

    void add_edge(int v1, int v2) {
        // Find the vertex for v1
        for (int i = 0; i < n; i++) {
            if (vertex[i]->i == v1) { // Match the vertex value
                GNode* node = vertex[i];
                // Traverse to the end of the list
                while (node->next != nullptr) {
                    node = node->next;
                }
                node->next = new GNode(v2); // Add new node at the end
                break;
            }
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            GNode* node = vertex[i];
            cout << node->i << " ---> ";
            node = node->next; // Move to the adjacency list
            while (node != nullptr) {
                cout << node->i << " ";
                node = node->next;
            }
            cout << endl;
        }
    }

    ~Graph() {
        // Destructor to clean up dynamically allocated memory
        for (int i = 0; i < n; i++) {
            GNode* node = vertex[i];
            while (node != nullptr) {
                GNode* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }
};

int main() {
    int v = 4;
    Graph graph(v);
    //graph.display();

    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(2, 4);

    cout << "Graph adjacency list:" << endl;
    graph.display();

    return 0;
}
*/

