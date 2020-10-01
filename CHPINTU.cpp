#include<cstdlib>
#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n,m,x=0,w=0;
    vector <int> v;
    
    vector<int>u;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        //scanf("%d",&m);
        vector <int>ans;
        int temp=n;
    if(m>=1&&n>=1&&m<=50&&n<=50)
    {
        while(temp--)
        {
           scanf("%d",&x);
           v.push_back(x);
           

        }
        temp=n;
        x=0;
        
            while(temp--)
            {
                scanf("%d",&x);
                u.push_back(x);

            }
            x=0;
            for(int j=1;j<=m;j++)
            {
                for(int i=0;i<n;i++)
                {
                    if(v[i]==j)
                    {
                        x=u[i]+x;
                    }
                    else
                    {
                        continue;
                    }
                    
                    
                }
                ans.push_back(x);
                
                x=0;
            }
            
            
            sort(ans.begin(),ans.end());
            int z=m;
            for(int i=0;i<m;i++)
            {
                if(ans[i]!=0)
                {
                    printf("%d",ans[i]);
                    break;
                }
                else
                {
                    continue;
                }
                
            }
        }    
    }
    return 0;
}
