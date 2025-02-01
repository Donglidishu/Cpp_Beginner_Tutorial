#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
  public:
    string m_Name;
    int m_Salary;
};

void addWorker(vector<Worker> &v)
{
    string workerSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += workerSeed[i];           // 变为员工ABCD...
        worker.m_Salary = rand() % 10000 + 10000; // 生成0~9999的随机数 再+10000
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int depId = rand() % 3;
        m.insert(make_pair(depId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{

    cout << "策划部门: " << endl;
    int count = m.count(CEHUA); // 统计策划人数
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    for (int index = 0; pos != m.end() && index < count; pos++, index++) // 创建一个index变量，当迭代器不等于end以及index小于统计出来的个数为条件，并递增pos和index
    {
        cout << "姓名: " << (*pos).second.m_Name << " 工资: " << (*pos).second.m_Salary << endl;
    }

    cout << "--------------------" << endl;

    cout << "美术部门: " << endl;
    count = m.count(MEISHU); // 统计美术人数
    pos = m.find(MEISHU);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << (*pos).second.m_Name << " 工资: " << (*pos).second.m_Salary << endl;
    }

    cout << "--------------------" << endl;

    cout << "研发部门: " << endl;
    count = m.count(YANFA); // 统计研发人数
    pos = m.find(YANFA);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << (*pos).second.m_Name << " 工资: " << (*pos).second.m_Salary << endl;
    }
}

int main()
{
    srand((unsigned int)time(nullptr));
    // 创建员工
    vector<Worker> workerContainer;
    addWorker(workerContainer);

    // 分组
    multimap<int, Worker> groupContainer;
    setGroup(workerContainer, groupContainer);

    showWorkerByGroup(groupContainer);

    // test
    //  for (vector<Worker>::iterator it = workerContainer.begin(); it != workerContainer.end(); it++)
    //  {
    //      cout << "姓名: " << (*it).m_Name << " 工资: " << (*it).m_Salary << endl;
    //  }

    return 0;
}