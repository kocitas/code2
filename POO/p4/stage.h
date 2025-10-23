
#ifndef STAGE_H
#define STAGE_H

#include <map>
#include <vector>

class stage{
    
    private: 

    std::map<int, int> delay_;
    int hard_; 

    public:

    Simulate();
    stage(int hard);
    std::map GetDelays();
    int GetHard();

};


#endif // STAGE_H
