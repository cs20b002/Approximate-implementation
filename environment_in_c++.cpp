#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        s[i]="";
        string in="";
        while(in!=";")
        {
            cin>>in;
            s[i]+=in;
            s[i]+=" ";
        }
    }
    vector<string> vec_name; // stores the var name in vector

    vector<vector<int>> envi; //example environment for int
    for(int i=0;i<n;i++)
    {
        int m=1;
        for(int j=0;j<s[i].size();j++)if(s[i][j]==',')m++;
        
        string var_name="";
        vector<int> numbers;
        int pos=0;

        cout<<s[i]<<endl;

        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='='){pos++; continue;}
            if(pos==0)
            {
                if(s[i][j]!=' ')var_name+=s[i][j];
            }
            if(pos==1)
            {
                //cout<<"TEST";
                pos++;
                j+=3;
                continue;
            }
            if(pos==2)
            {
                j++;
                string num="";
                while(s[i][j]!=',' && s[i][j]!='"')
                {
                    num+=s[i][j];
                    j++;
                }
                numbers.push_back(stoi(num));
            }
        }

        vec_name.push_back(var_name);
        if(envi.empty()) // adds new variable to the existing environment
        {
            for(int i=0;i<numbers.size();i++)envi.push_back({numbers[i]});
        }
        else
        {
            vector<vector<int>> temp=envi;
            envi.clear();
            for(int i=0;i<numbers.size();i++)
            {
                for(int j=0;j<temp.size();j++)
                {
                    vector<int> v=temp[j];
                    v.push_back(numbers[i]);
                    envi.push_back(v);
                }
            }
        }
    }

    cout<<"(";
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)cout<<vec_name[i]<<", ";
        else cout<<vec_name[i];
    }
    cout<<")"<<endl;

    for(int i=0;i<envi.size();i++)
    {
        cout<<"(";
        for(int j=0;j<envi[i].size();j++)
            if(j!=envi[i].size()-1)cout<<envi[i][j]<<", ";
            else cout<<envi[i][j];
        cout<<")"<<endl;
    } 
}
