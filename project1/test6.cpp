#include<iostream>
#include<string>

enum CPU_rank
{
    p1=1,
    p2,
    p3,
    p4,
    p5,
    p6,
    p7
};

class CPU
{
private:
    CPU_rank rank;
    int frequency;
    float voltage;
public:
    CPU(CPU_rank a,int b,float c)
    {
        rank=a;
        frequency=b;
        voltage=c;
        std::cout<<"构建了一个CPU:\n等级:"<<rank<<" 频率:"<<frequency<<" 电压:"<<voltage<<"\n";
    }
    CPU(const CPU& a)
    {
        frequency=a.frequency;
        rank=a.rank;
        voltage=a.voltage;
        std::cout<<"构建了一个CPU:\n等级:"<<rank<<" 频率:"<<frequency<<" 电压:"<<voltage<<"\n";
    }
    ~CPU()
    {
        std::cout<<"CPU销毁"<<"\n";
    }
    void run()
    {
        std::cout<<"CPU开始运行"<<"\n";
    }
    void stop()
    {
        std::cout<<"CPU停止运行"<<"\n";
    }
};

class RAM
{
public:
    int frequency;
    int volume;
    RAM(int a,int b)
    {
        frequency=a;
        volume=b;
        std::cout<<"有了一个频率为"<<frequency<<"MHZ的内存"<<"\n";
        std::cout<<"内存大小为"<<volume<<"GB"<<"\n";
    }
    RAM(const RAM& a)
    {
        frequency=a.frequency;
        volume=a.volume;
        std::cout<<"有了一个频率为"<<frequency<<"MHZ的内存"<<"\n";
        std::cout<<"内存大小为"<<volume<<"GB"<<"\n";
    }
    ~RAM()
    {
        std::cout<<"RAM销毁"<<"\n";
    }
};

class CDROM
{
public:
    int frequency;
    int volume;
    CDROM(int a,int b)
    {
        frequency=a;
        volume=b;
        std::cout<<"有了一个频率为"<<frequency<<"MHZ的CDROM"<<"\n";
        std::cout<<"容量大小为"<<volume<<"GB"<<"\n";
    }
    CDROM(const CDROM& a)
    {
        frequency=a.frequency;
        volume=a.volume;
        std::cout<<"有了一个频率为"<<frequency<<"MHZ的CDROM"<<"\n";
        std::cout<<"容量大小为"<<volume<<"GB"<<"\n";
    }
    ~CDROM()
    {
        std::cout<<"CDROM销毁"<<"\n";
    }
};

class COMPUTER
{
public:
    COMPUTER(const CPU& a,const RAM& b,const CDROM& c):cpu(a),ram(b),cdrom(c)
    {
        std::cout<<"创建了一个计算机\n";
    }
    ~COMPUTER()
    {
        std::cout<<"计算机销毁\n";
    }
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};

int main()
{
    CPU amd(p6,3600,1.5);
    RAM hailishi(4000,1024);
    CDROM xibushuju(500,10240);
    COMPUTER myComputer(amd,hailishi,xibushuju);
    return 0;
}