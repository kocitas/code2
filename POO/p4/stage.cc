#include "stage.h"
#include <random>
#include <algorithm>  // std::shuffle
#include <chrono>  


stage::stage(int hard){
 
    if(hard<1){hard_=1;}
    else if(hard>5){hard_=5;}
    else{hard_=hard}
}

stage::simulate(const std::vector<Cyclist> &cyclists){

        delay_.clear();
        if (cyclists.empty()) return;

          // Inicialización aleatoria
            std::random_device rd;
            std::mt19937 gen(rd())

    std::uniform_int_distribution<int> winnerDist(0, cyclists.size()-1);

    int winner_index=winner_dist(gen);//indice del ganador 
    int winner_id=cyclists[winner_index].GetId();//asignar id de ganador

    delay_[winner_id] = 0;  // El ganador tiene delay 0


    //se asignan retrasos al resto 
    int max_delay=hard_*400;
    std::uniform_int_distribution<int> delay_dist(1, max_delay);

    for (size_t i = 0; i < cyclists.size(); i++) {
    int id = cyclists[i].GetId();
    if (id == winner_id) continue;  // Ya asignado
    delay_[id] = delay_dist(gen);
    }


    //get delay
    std::map<int, int> Stage::GetDelays() const {
    return delay_;
    }

    //get hard
    int Stage::GetHard() const {
    return hard_;
    }