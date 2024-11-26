#include<iostream>
#include<cstring>
//C/C++:
// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: init: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: isWin: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: playerMove: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y); 
// -------------------- service --------------------



// -------------------- view --------------------
/*
    负责人: 张三
    功能: menuView: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
    参数: void
    返回值: void
*/
void menuView();

/*
    负责人: 张三
    功能: gameView_ShowMap: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: winView: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: gameView: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init(){
    std::memset(map,0,sizeof(map));
    flag=0;
}

int isWin(int x, int y){
    int x_min=x-5,x_max=x+5;
    int y_min=y-5,y_max=y+5;
    int count=0;
    int army;
    if(flag%2==0)
        army=2;
    else
        army=1;

    if(x_min<0)
        x_min=0;
    if(x_max>18)
        x_max=18;
    if(y_min<0)
        y_min=0;
    if(y_max>18)
        y_max=18;

    for(int i=x_min;i<=x_max;++i)
    {
        count++;
        if(map[i][y]==0||map[i][y]==army)
        {
            count=0;
        }
    }
    if(count==5)
    {
        if(flag%2==0)
            return 1;
        else
            return 2;
    }
    count=0;

    for(int i=y_min;i<=y_max;++i)
    {
        count++;
        if(map[x][i]==0||map[x][i]==army)
        {
            count=0;
        }
    }
    if(count==5)
    {
        if(flag%2==0)
            return 1;
        else
            return 2;
    }
    count=0;

    for(int i=x_min,j=y_min;i<=x_max,j<y_max;++i,++j)
    {
        count++;
        if(map[i][j]==0||map[i][j]==army)
        {
            count=0;
        }
    }
    if(count==5)
    {
        if(flag%2==0)
            return 1;
        else
            return 2;
    }
    count=0;

    for(int i=x_min,j=y_max;i<=x_max,j>=y_min;++i,--j)
    {
        count++;
        if(map[i][y]==0||map[i][y]==army)
        {
            count=0;
        }
    }
    if(count==5)
    {
        if(flag%2==0)
            return 1;
        else
            return 2;
    }
    count=0;

    return 0;
}

int playerMove(int x, int y){
    if(map[x][y]!=0)
    {
        std::cout<<"已经有棋子了！！\n";
        return 0;
    }
    if(flag%2==0)
        map[x][y]=1;
    else
        map[x][y]=2;
    return 1;
}

void menuView(){
    std::cout<<"---------------------------\n";
    std::cout<<"1.开始游戏\n";
    std::cout<<"2.进入设置\n";
    std::cout<<"3.退出游戏\n";
    std::cout<<"---------------------------\n";

    int choice;
    while(1)
    {
        std::cin>>choice;
        switch(choice)
        {
            case 1:
            {
                gameView();
            }
            case 2:
            {
                std::cout<<"敬请期待!\n";
                break;
            }
            case 3:
            default: exit(0);
        }
    }
}

void gameView_ShowMap(){
    for(int i=0;i<19;++i)
    {
        for(int j=0;j<19;++j)
        {
            std::cout<<map[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

void winView(){
    char ch;
    if(flag%2==0)
    {
        std::cout<<"黑棋获胜!\n";
        std::cout<<"一共进行了:"<<flag+1<<"步\n";
    }
    else
    {
        std::cout<<"白棋获胜!\n";
        std::cout<<"一共进行了:"<<flag+1<<"步\n";
    }
    std::cin>>ch;
}

void gameView(){
    int x,y;
    init();
    while(1)
    {
        gameView_ShowMap();
        std::cin>>x>>y;

        if(!playerMove(x,y))
            continue;
        if(isWin(x,y))
        {
            winView();
            break;
        }
        flag++;
    }
}