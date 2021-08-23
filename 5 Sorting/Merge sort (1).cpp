#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    vector<int> mergedVector;
    if(myVector.size() == 0){
        return alicesVector;
    }
    if(alicesVector.size() == 0){
        return myVector;
    }
    // combine the sorted vectors into one large sorted vector
    int i=0, j=0;
    //Go through the vectors until there one of iterators hits the end
    while(i < myVector.size() && j < alicesVector.size()){
        if(myVector[i] <= alicesVector[j]){
            mergedVector.push_back(myVector[i]);
            i++;
        }
        else{
            mergedVector.push_back(alicesVector[j]);
            j++;
        }
    }
    //If myVector is smaller than alicesVector, insert the rest of alicesVector
    if(i == myVector.size() && j < alicesVector.size()){
        for(j; j<alicesVector.size(); j++){
            mergedVector.push_back(alicesVector[j]);
        }
    }
    //If myVector is larger than Alice's vector, insert the rest of myVector
    if(i < myVector.size() && j == alicesVector.size()){
        for(i; i<myVector.size(); i++){
            mergedVector.push_back(myVector[i]);
        }
    }
    
    return mergedVector;
}

int main() {
     vector<int> myVector ;
     myVector.push_back(2);
     myVector.push_back(4);
     myVector.push_back(6);
     myVector.push_back(8);
     cout<<"First Sorted array   :";
     for(int i=0;i<myVector.size();i++)
     cout<<myVector[i]<<" ";
     vector<int> alicesVector;
     alicesVector.push_back(1);
     alicesVector.push_back(7);
     cout<<"\nSecond Sorted array  :";
     for(int i=0;i<alicesVector.size();i++)
     cout<<alicesVector[i]<<" ";
     vector<int> merged = mergeVectors(myVector, alicesVector);
     cout<<"\nMerge array          :";
    for(int i=0; i<merged.size(); i++){
        cout << merged[i] << " ";
    }
    cout << "\n";
    return 0;
}
