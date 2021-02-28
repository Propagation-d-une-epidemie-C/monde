#ifndef __monde__
#define __monde__ 1
#include "position.h"

class monde{
  private:
  
    position positions;
    std::vector<std::vector<int> > world;
  
  public: 
  
    // constructeur
    monde(position new_positions);
  
    //méthode du monde
    void condition_initiale(position positions);
    void deplacement();
    std::vector<std::vector<int> > get_monde();
    
 };
    
#endif
