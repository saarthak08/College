#include<iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;
int main()
{

    int i,n,page[50],k,s,j,large,large_index,hit=0,found=0,f;
    int nhit=0,nmiss=0,finish=0,pointer=0,m=0;

    cout<<"\nEnter the number of pages to be filled in the page table:";
    cin>>n;

    cout<<"\nEnter the number of frames:"<<endl;
    cin>>f;

    int arr[f],dist[f];

    cout<<"Enter the pages:"<<endl;
    for(i=0;i<n;i++){
        cin>>page[i];
    }

    cout<<"\n\nInitial Page Table: "<<endl;
    for(i=0;i<f;i++){
        arr[i]=-1;
        cout<<arr[i]<<"\t";
    }

    cout<<endl<<endl;


    for(i=0;i<n;i++) 
    {
        for(j=0;j<=i;j++)
        { 
            if(page[i]!=arr[j]){
                hit=0;
            }
            else
            {
                hit=1;
                nhit=nhit+1;
                cout <<"\n\nPage Reference:"<<page[i]<<endl;
                cout<<"Page Hit!"<<endl;
                break;
            }
        }
        if(hit==0) //if not presnt i.e. page miss ,then inserted into the page table
        {
            cout<<"\n\nPage Reference: "<<page[i]<<endl;
            nmiss=nmiss+1;
            cout<<"Page Miss! --  Page Fault!"<<endl;
            arr[pointer]=page[i];
            pointer=pointer+1;
        }
 
        cout<<"Page Table: "<<endl;
        for(k=0;k<f;k++){
            cout<<arr[k]<<"\t";
        }
 
        if(pointer==f)
        {
            finish=i+1;
            cout<<"\n\n\n----- Completed filling the frames -----"<<endl<<endl; 
            break;
        }
    }

    hit=0;
    found=0;

    for(i=finish;i<n;i++)
    {
        for(j=0;j<f;)
        {
            if(page[i]!=arr[j])
            {
                j=j+1;
                hit=0; 
            }
            else
            {
                hit=1;
                break;
            }
        }
        if(hit==1)
        {
            cout<<"\n\nPage Reference: "<<page[i]<<endl;
            cout<<"Page hit!"<<endl;
            nhit=nhit+1;
        }
        else
        {
            cout<<"\n\nPage Reference: "<<page[i]<<endl;
            cout<<"Page miss!"<<endl;
            nmiss=nmiss+1;
            int index=i;
            for(k=0;k<f;k++)
            {
                cout<<"\nIndex:"<<index;
                cout<<"\nUsage of "<<arr[k];
                for(m=index;m>=0;m--)
                { 
                    if(arr[k]==page[m])
                    {
                        dist[k]=index-m;
                        cout<<"\nM is "<<m;
                        cout<<"\n"<<arr[k]<<" is alloted a distance of "<<int(dist[k])<<endl;
                        found=1;
                        break;
                    }
                }
                cout<<endl;
                if(found==0) 
                {
                    dist[k]=INT_MAX;
                    cout<<arr[k]<<" is alloted a distance of "<<int(dist[k])<<endl;
                }
            }
            large=dist[0];
            large_index=0;
            for(s=1;s<f;s++)
            { 
                if(large<dist[s])
                {
                    large=dist[s];
                    large_index=s;
                }
            }
        
            cout<<"\n"<<arr[large_index]<<" stands with largest distance."<<endl;
            arr[large_index]=page[i];
        }
        cout<<"Page Table: "<<endl;
        for(k=0;k<f;k++){
            cout<<arr[k]<<"\t";
        }
    }

    cout<<"\n\nNumber of hits: "<<nhit<<endl;
    cout<<"Number of misses/page faults: "<<nmiss<<endl;
    return 0;
}