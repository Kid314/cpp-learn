/**
 * P1042 [NOIP2003 普及组] 乒乓球
 * 
 */
#include<iostream>
#include<cstring>

char wl[70000];
char ch1;
int win=0,lose=0;

void read()
{
    for(int i=0;std::cin>>ch1;++i)
    {
        wl[i]=ch1;
        if(ch1=='E')
            break;
    }
}

void calc()
{
    for(int i=0;1;++i)
    {
        if(wl[i]=='W')
            win++;
        if(wl[i]=='L')
            lose++;
        if(wl[i]=='E')
        {
            std::cout<<win<<":"<<lose<<"\n\n";
            break;
        }
        if(win-lose>=2||lose-win>=2)
        {
            if(win>=11||lose>=11)
            {
                std::cout<<win<<':'<<lose<<"\n";
                win=0;
                lose=0;
            }
        }
    }
    win=0;
    lose=0;
    
    for(int i=0;1;++i)
    {
        if(wl[i]=='W')
            win++;
        if(wl[i]=='L')
            lose++;
        if(wl[i]=='E')
        {
            std::cout<<win<<":"<<lose;
            break;
        }
        if(win-lose>=2||lose-win>=2)
        {
            if(win>=21||lose>=21)
            {
                std::cout<<win<<':'<<lose<<"\n";
                win=0;
                lose=0;
            }
        }
    }
}
int main()
{
    read();
    calc();
    return 0;
}