#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "curves.h"
#include "curves.cpp"

int main()
{
    std::vector<Models3D*> models;
    GetRand getRand;
    int iterations = getRand.getRand(5,10);
    for (int i = 0; i <= iterations; i++)
    {
        int chois = getRand.getRand(0,30);
        if (0 <= chois < 10)
        {models.push_back(new Circles{getRand.getRand(1.0 , 30.0)});}
        if (10 <= chois < 20)
        {models.push_back(new Elipses{getRand.getRand(1.0 , 30.0), getRand.getRand(1.0 , 30.0)});}
        if (20 <= chois < 30)
        {models.push_back(new Helixes{getRand.getRand(1.0 , 30.0), getRand.getRand(1.0 , 5.0)});}
    }
    std::vector<Models3D*> circles;
    for (auto item: models)
    {
        std::cout<<item->GetName()<<" point - "<<std::string(item->GetPoint(M_PI / 4))<<std::endl;
        std::cout<<item->GetName()<<" vector - "<<std::string(item->GetVector(M_PI / 4))<<std::endl;
        if (item->GetName() == "circles")
        {
            circles.push_back(item);
        }
    }
    std::sort(circles.begin(),circles.end(),
        [](Models3D* a, Models3D* b)->bool{return a->GetRadius() < b->GetRadius();});
    double sumRadii = 0;
    for (auto item: circles)
    {
        // std::cout<<item->GetRadius()<<std::endl;
        sumRadii += item->GetRadius();
    }
    std::cout<<"Sum of radii is - "<<sumRadii<<std::endl;
    return 0;
}