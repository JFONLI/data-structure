#include "function.h"
#include <algorithm>

void Implement::Add(const string &str)
{
    int temp;
    int ha = 0;
    int length = str.length();

    for (int a=0; a<length-1; a++)
    {
        temp = str[a];
        for (int b=1; b<length-a; b++)
        {
            //cout << temp << endl;
            temp = (temp*13331)%41;
        }
        ha = ha+temp;
    }

    temp = str[length-1];
    //cout << temp << endl;
    ha = ha+temp;
    ha = ha%41;
    //cout << ha << endl;
    list<string>::iterator it;
    it = find(table[ha].begin(), table[ha].end(), str);

    if(it == table[ha].end())
    {
        table[ha].push_back(str);
    }


}

void Implement::Delete(const string &str)
{
    int temp;
    int ha = 0;
    int length = str.length();
    for (int a=0; a<length-1; a++)
    {
        temp = str[a];
        for (int b=1; b<length-a; b++)
        {
            //cout << temp << endl;
            temp = (temp*13331)%41;
        }
        ha = ha+temp;
    }
    temp = str[length-1];
    ha = ha+temp;
    ha = ha%41;

    table[ha].remove(str);
    return;
}

bool Implement::Exist(const string &str)
{
    int temp;
    int ha = 0;
    int length = str.length();
    for (int a=0; a<length-1; a++)
    {
        temp = str[a];
        for (int b=1; b<length-a; b++)
        {
            //cout << temp << endl;
            temp = (temp*13331)%41;
        }
        ha = ha+temp;
    }
    temp = str[length-1];
    ha = ha+temp;
    ha = ha%41;

    list<string>::iterator it;
    it = find(table[ha].begin(), table[ha].end(), str);

    if(it == table[ha].end())
    {
        return false;
    }
    else
    {
        return true;
    }

}
