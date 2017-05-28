//
//  main.cpp
//  CSE101_HW6
//
//  Created by Siqi Qin on 5/27/17.
//  Copyright © 2017 Siqi Qin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>
#include <ctime>
#define M 1024

class MMM{
public :
int MIS(std::vector<std::vector<int>> A, std::unordered_set<int> &visited){
    if(visited.size() == M)
        return 0;
    int i = 0;
    while(visited.find(i) != visited.end())
        i++;
    visited.insert(i);
    std::vector<std::vector<int>> Ac = A;
    std::vector<std::vector<int>> Ab = A;
    int deg = 0;
    for(int j = i;j < M; j++)
    {
        if(Ab[i][j]){
            for(int k = 0; k < M;k++)
            {
                Ab[j][k] = 0;
                Ab[k][j] = 0;
            }
            deg++;
            visited.insert(j);
        }
        Ab[i][j] = 0;
        Ac[i][j] = 0;
    }
    int s1 = 1 + MIS(Ab,visited);
    if(deg == 0 | deg == 1)
        return s1;
    visited.erase(i);
    int s2 = MIS(Ac,visited);
    return std::max(s1,s2);
}
};

int main(int argc, const char * argv[]) {
    int m = 0;
    for(int l = 0;l < 100;l++){
        srand(unsigned(time(0)));
        std::vector<std::vector<int>> AdjMatrix(M,std::vector<int>(M,0));
        for(int i = 1;i < M;i++)
            for(int j = i + 1;j < M;j++)
                if(rand()%2)
                    AdjMatrix[i][j] = 1;
    
        std::unordered_set<int> visited;
        MMM MM;
        m += MM.MIS(AdjMatrix,visited);
        std::cout<<l<<std::endl;
    }
    std::cout<<m / 100.0<<std::endl;
    
}


