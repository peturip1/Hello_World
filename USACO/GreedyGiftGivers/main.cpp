#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

    map<string,int> m;
    map<string,int>::iterator it;

    void
    put(string name, int value)
    {
        it = m.find(name);
        if ( it != m.end() )
        {
            m[name] = m[name] + value;
        } else
        {
            m[name]=value;
        }


    }

    int main()
    {
      try
      {
       //freopen ("gift1.in","r",stdin);
        freopen ("home/petar/programs/USACO/USACO/bin/Debug/gift1.in","r",stdin);
        //home/petar/programs/USACO/USACO/bin/Debug/gift1.in
        int NP;
        cin>>NP;
        string name;
        vector<string> names;
        for(int i =0;i < NP;++i)
        {
            cin>>name;
            names.push_back(name);
            //cout<<name;

        }
        //sort(names.begin(),names.end());
        //for( int i = 0; i < NP; ++i )
        //{
         //   cout<<names.at(i);
        //}

        int n=NP;
        while ( n!=0 )
        {
            n--;
            cin>>name;
            int initialAmount;
            cin>>initialAmount;
            int friendsNum;
            cin>>friendsNum;
            int moneyForGift;
            int moneyLeft;
            if ( friendsNum!= 0)
            {
                 moneyForGift=initialAmount/friendsNum;
                 moneyLeft=initialAmount%friendsNum;
            } else
            {
                moneyForGift=0;
                moneyLeft=initialAmount;
            }


            for(int i=0; i < friendsNum; ++i)
            {
                string fr;
                cin>>fr;
                put(fr,moneyForGift);
            }
            put(name,moneyLeft);



        }
        for (int i =0;i<NP;++i)
        {
            it=m.begin();
            cout<<it->first<<"->"<<it->second<<endl;
            ++it;
        }

      }
      catch (int e)
      {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
      }

        //cout << "Hello world!" << NP << endl;
        return 0;
    }
