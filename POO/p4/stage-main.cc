#include "stage.h"
#include <random>
#include <algorithm>  // std::shuffle
#include <chrono>  

int main(){


    //asi se carga catalog
    CyclistCatalog catalog;
  if (!catalog.Load()) {
    std::cerr << "Error al cargar los ciclistas." << std::endl;
    return 1;
  }

  
  Stage stage(3);  // etapa de dureza 3
  stage.Simulate(catalog.Data()); 

  std::cout << "Nombre, ID, Delay (s)" << std::endl;
  
  auto delays = stage.GetDelays();//creacion de delay

  for (const auto& cyclist : catalog.Data()) {//bucle para mostrar catalog
    int id = std::stoi(cyclist.GetCyclistId());
    std::cout << cyclist.GetName() << ", " 
              << id << ", " 
              << delays[id] << std::endl;
  }


    return 0; 
}