#include "function.h"

#include <string>
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

int min_weight = INT_MAX;
int mwi; //min_weight_index;

void Implement::addEdge(const int label_1, const int label_2 , const int weight)
{
    Neighbor newneighbor1 = Neighbor (label_2, weight);
    VertexArr[label_1].neighbors.push_back(newneighbor1);

    Neighbor newneighbor2 = Neighbor (label_1, weight);
    VertexArr[label_2].neighbors.push_back(newneighbor2 );

    if (weight < min_weight)
    {
        min_weight = weight;
        mwi = label_1;
    }
}

int Implement::shortest_path(const int label_1 , const int label_2)
{
    int dist[VertexArr.size()];
        int length[VertexArr.size()][VertexArr.size()];
        int pi[VertexArr.size()];
        bool s[VertexArr.size()];

        //Initialization for dist, length
         for (int z=0; z<VertexArr.size(); z++)
        {
            dist[z] = INT_MAX;
            pi[z] = -1;
            s[z] = false;
            for (int y=0; y<VertexArr.size(); y++)
                length[z][y] = INT_MAX;
        }

        //Initialization for length
        for (int p=0; p<VertexArr.size(); p++)
        {
            for (int m=0; m<VertexArr[p].neighbors.size(); m++)
            {
                length[VertexArr[p].label][VertexArr[p].neighbors[m].label] = VertexArr[p].neighbors[m].weight;
            }
        }

        //  show length
        /*
        for (int q=0; q<VertexArr.size(); q++)
        {
            for (int n=0; n<VertexArr.size(); n++)
            {
                std::cout << length[q][n] << " " ;
            }
            std::cout << std::endl;
        }
        */

        dist[label_1] = 0;
        int min = INT_MAX;
        int index;

        for (int a=0; a<VertexArr.size()-1; a++)
        {

            min = INT_MAX;
            for (int b=0; b<VertexArr.size(); b++)
            {
                //std::cout << "b: " << s[b] << std::endl;
                //std::cout << "min: " << min << std::endl;
                if (s[b] == false && dist[b] < min)
                {
                    min = dist[b];
                    index = b;
                }
            }

            //std::cout << "index: " << index << std::endl;

            s[index] = true;

            for (int c=0; c<VertexArr.size(); c++)
            {
                if (!s[c] && length[index][c] != INT_MAX &&dist[index] + length[index][c] < dist[c])
                {
                    dist[c] = dist[index] + length[index][c];
                    pi[c] = index;
                    //std::cout << "c: " << c << std::endl;

                    //show pi and dist
                    /*
                    for (int k=0; k<VertexArr.size(); k++)
                    {
                        std::cout << k << " " ;
                        std::cout << pi[k] << " " << dist[k] << " " << s[k] << std::endl;
                    }
                    */
                }
            }
        }

            //use pi to find the shortest path
            int ans = 0;
            int temp = label_2;
            while (pi[temp] != -1)
            {
                ans = ans + (dist[temp] - dist[pi[temp]]);
                //std::cout << ans << std::endl;
                temp = pi[temp];
            }

            return ans;
}

int Implement::mst_weight()
{
int ans = 0;
    bool state[VertexArr.size()];
    int dist[VertexArr.size()];
    int current = 0;
    dist[current] = 0;
    state[current] = true;

    for (int z=1; z<VertexArr.size(); z++)
    {
        state[z] = false;
        dist[z] = INT_MAX;
    }

    for (int a=0; a<VertexArr.size()-1; a++)
    {
        for (int b=0; b<VertexArr[current].neighbors.size(); b++)
        {
            if (dist[VertexArr[current].neighbors[b].label] > VertexArr[current].neighbors[b].weight)
                dist[VertexArr[current].neighbors[b].label] = VertexArr[current].neighbors[b].weight;
        }

        int min = INT_MAX;
        int index;

        for (int c=0; c<VertexArr.size(); c++)
        {
            if (state[c]!=true && dist[c] < min)
            {
                min = dist[c];
                index = c;
            }
        }

        //std::cout << index << std::endl;
        state[index] = true;
        ans = ans + min;
        current = index;
    }

    return ans;

}

bool Implement::two_colorable()
{
   int color[VertexArr.size()];
   int length[VertexArr.size()][VertexArr.size()];

   for (int a=0; a<VertexArr.size(); a++)
   {
       color[a] = -1;
       for (int b=0; b<VertexArr.size(); b++)
       {
           length[a][b] = INT_MAX;
       }
   }

   //Initialization for length
    for (int p=0; p<VertexArr.size(); p++)
    {
        for (int m=0; m<VertexArr[p].neighbors.size(); m++)
        {
            length[VertexArr[p].label][VertexArr[p].neighbors[m].label] = VertexArr[p].neighbors[m].weight;
        }
    }

   std::queue <int> q;
   q.push(0);

   while (!q.empty())
   {
       int u = q.front();
       q.pop();

       for (int c=0; c<VertexArr.size(); c++)
       {
           if (length[u][c] != INT_MAX && color[c] == -1)
           {
               color[c] = 1 - color[u];
               q.push(c);
           }

           else if (length[u][c] != INT_MAX && color[c] == color[u])
           {
               return false;
           }
       }
   }

   return true;

}
