#include<iostream>
#include<map>
using namespace std;

int main()
{
    map <int, int> briefcase_value = {{1,100},{2,500},{3,1000},{4,5000},{5,10000},{6,25000},{7,50000},{8,100000},{9,500000},{10,1000000}};

    int eliminated;
    int num_briefcases_eliminated;
    int offer;
    int total_value=0;

    //add up the total value of all the briefcases
    for (int y=1;y<=10;y++)
    {
         total_value+=briefcase_value[y];
    }

    cin >> num_briefcases_eliminated;

    //subtract the value of each eliminated briefcase from the total
    for (int x=0;x<num_briefcases_eliminated; x++)
    {
        cin >> eliminated;
        total_value-=briefcase_value[eliminated];
    }

    cin >> offer;

    //if the offer is bigger than the average value, take the deal
    if(offer>total_value/(10-num_briefcases_eliminated))
        cout<<"deal";
    else
        cout <<"no deal";
}
