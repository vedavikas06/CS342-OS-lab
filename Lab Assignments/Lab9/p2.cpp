
// C++ program to illustrate Banker's Algorithm 
#include<bits/stdc++.h> 
using namespace std; 
  

int P; 
  
int R; 
  
void calculateNeed(vector<vector<int> > &need, vector<vector<int> > maxm, 
                   vector<vector<int> > allot,int printt) 
{ 
    if(printt)
    cout << "Need Matrix" << endl; 
    for (int i = 0 ; i < P ; i++) {
        for (int j = 0 ; j < R ; j++) {
  
            need[i][j] = maxm[i][j] - allot[i][j];
            if(printt)
            cout << need[i][j] << " " ;
        } 
        if(printt)
        cout << endl;
    }
} 
  
// Function to find the system is in safe state or not 
bool isSafe(vector<int> avail, vector<vector<int> > maxm, vector<vector<int> >  allot) 
{ 
    vector<vector<int> > need(P,vector<int>(R,0));
  
    calculateNeed(need, maxm, allot,1); 
  
   
    vector<bool>finish(P,false);
  
     
    vector<int> safeSeq(P,0);
  
    
    vector<int> work(R,0);
    for (int i = 0; i < R ; i++) {
        work[i] = avail[i]; 
    }
  

    int count = 0; 
    while (count < P) 
    { 

        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            
            if (!finish[p]) 
            { 
              
                int j; 
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        break; 
                    }
                }
  
                if (j == R) 
                { 
                    
                    for (int k = 0 ; k < R ; k++) {
                        work[k] += allot[p][k]; 
                    }
                    // cout << "Available Resource after process " << p << " : ";
                    // for (int k = 0 ; k < R ; k++) {
                    //     cout << work[k] << " ";  
                    // }
                    // cout << endl;

  
                    safeSeq[count++] = p; 
  
                    finish[p] = true; 
  
                    found = true; 
                } 
            } 
        } 
  
       
        if (found == false) 
        { 
            cout << "\nSystem not in safe state" << endl; 
            return false; 
        } 
    } 
  

    cout << "\nSystem is in safe state" << "\n" << "One of the accceptable Safe sequence is: "; 
    for (int i = 0; i < P ; i++) {
        cout << safeSeq[i] << " "; 
    }
    cout << endl;
  
    return true; 
} 



void process_request(int proc,vector<int> req,vector<int> avail, vector<vector<int> > maxm, 
            vector<vector<int> >  allot){

    vector<vector<int> > need(P,vector<int>(R,0));
  
    
    calculateNeed(need, maxm, allot,0);

    // for (int k = 0 ; k < R ; k++) {
    //      cout <<   avail[k] << " "; 
    // }
    // cout << endl;

    int j; 
    for (j = 0; j < R; j++) {
        if (need[proc][j] >= req[j] && avail[j] >= req[j]) {
            continue;
        }else{
            break;
        }
    }

   //cout << j << endl;

    if (j == R) 
    { 
        
        for (int k = 0 ; k < R ; k++) {
            avail[k] -= req[k]; 
        }

        for (int k = 0 ; k < R ; k++) {
            allot[proc][k] += req[k]; 
        }

        for (int k = 0 ; k < R ; k++) {
            need[proc][k] -= req[k]; 
        }



        isSafe(avail,maxm,allot);


        
    }else{
        cout << "Request can't be granted immediately" << endl;
    } 


}

int main() 
{ 

    cout << "input no of processes and resources" << endl;

    cin >> P >> R;

    cout << "No of available for each resource" << endl;
    // int avail[] = {3, 3, 2}; 

    vector<int> avail(R,0);
    for(int i=0;i<R;i++){
        cin >> avail[i];
    }

    vector<vector<int> > maxm(P,vector<int>(R,0));
    cout << "Maximum Allocatable resource for each process" << endl;

    for (int i = 0; i < P; ++i)
    {
        for (int j = 0; j < R; ++j)
        {
            cin >> maxm[i][j];
        }
    }




    vector<vector<int> > allot(P,vector<int>(R,0));


    cout << "Allocated resources for each process" << endl;

    for (int i = 0; i < P; ++i)
    {
        for (int j = 0; j < R; ++j)
        {
            cin >> allot[i][j];
        }
    }


    isSafe(avail, maxm, allot); 

    int proc_req;
    cout << "requesting process" << endl;

    cin >> proc_req;

    cout << "resource requesting" << endl;


    vector<int> req(R,0);
    for(int i=0;i<R;i++){
        cin >> req[i];
        //cout << req[i] << " ";
    }

    process_request(proc_req,req,avail,maxm,allot);

  
    return 0; 
} 
