#include <iostream> 
#include <map>
#include <string>

using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);

    string car, spy;
    int ncars, nevents, c, p, k, km, perc;
    int time;
    char act;

    map <string, int> spies_cost;
    map<string, string> spies_cars;
    map <string, int(*)> cars;

    while(t--)
    {
        spies_cost.clear();
        spies_cars.clear();
        cars.clear();

        cin >> ncars >> nevents;

        while(ncars--)
        {
            cin >> car >> c >> p >> k;
            cars[car] = (int *) calloc(3, sizeof(int));
            cars[car][0] = c;
            cars[car][1] = p;
            cars[car][2] = k;
        }

        while(nevents--)
        {
            cin >> time >> spy >> act;

            if (act == 'p')
            {
                cin >> car;

                if (spies_cars[spy] != "")
                    spies_cost[spy] = -1;

                if (spies_cost[spy] != -1)
                {
                    spies_cost[spy] += cars[car][1];
                    spies_cars[spy] = car;
                }
            }
            else if (act == 'a')
            {
                cin >> perc;

                if (spies_cars[spy] == "")
                    spies_cost[spy] = -1;
                
                if (spies_cost[spy] != -1)
                    spies_cost[spy] += (perc * cars[spies_cars[spy]][0] + 99) / 100;
            }
            else if (act == 'r')
            {
                cin >> km;

                if (spies_cars[spy] == "")
                    spies_cost[spy] = -1;

                if (spies_cost[spy] != -1)
                {
                    // cout << spy << " RETURNED";
                    spies_cost[spy] += cars[spies_cars[spy]][2] * km;
                    spies_cars[spy] = "";
                }
            }
        }

        for(map<string, int>::iterator iter = spies_cost.begin(); iter != spies_cost.end(); ++iter)
        {
            spy = iter->first;
            cout << spy << " ";
            if (iter->second == -1 || spies_cars[spy] != "")
                cout << "INCONSISTENT";
            else
                cout << iter->second;

            cout << endl;
        }

    }
    return 0;
}