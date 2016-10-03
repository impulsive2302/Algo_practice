
#include <iostream>
using namespace std;
class accounts
{
public:
    bool is_available;
    int start_time;
    int end_time;
    accounts()
    {
        is_available = true;
        start_time = end_time = -1;
    }
};
class account_manager
{
public:
    int num_account;
    accounts* acc;
    int wait_time;
    account_manager(int num_ac,int wait)
    {
        num_account = num_ac;
        acc = new accounts[num_ac];
        wait_time = wait;
    }
};
int main() {
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int account, waiting_time,num_orders;
        cin >> account;
        cin >> waiting_time;
        cin >> num_orders;
        int orders[num_orders];
        for(int i = 0;i<num_orders;i++)
        {
            cin>>orders[i];
        }
        account_manager manager(account,waiting_time);
        for(int i = 0;i < num_orders;i++)
        {
            int free_account = 0;
            bool order_assigned = false;
            for(int j = 0;j < account;j++)
            {
                if(!manager.acc[j].is_available)
                {
                    if(manager.acc[j].end_time <= orders[i])
                    {
                        manager.acc[j].end_time = manager.acc[j].start_time = -1;
                        manager.acc[j].is_available = true;
                    }
                }
                if(!order_assigned && manager.acc[j].is_available)
                {
                    manager.acc[j].start_time = orders[i];
                    manager.acc[j].end_time = orders[i] + waiting_time;
                    manager.acc[j].is_available = false;
                    order_assigned = true;
                }
                if(manager.acc[j].is_available)
                    free_account++;
            }
            cout<<free_account<<endl;
        }
    }
return 0;
}
