#include "monde.h"
#include <cstdlib>
#include <iostream>


/*legende :
0 == absence de personne
1 == personne saine
2 == personne contaminée
3 == personne inactive */

//constructeur

monde::monde(position new_positions) :  positions(new_positions)
  {
    world.push_back(std::vector<int> (50, 0));
    for(unsigned int j = 0 ; j < positions.get_taille(); j++)
      world[j].push_back(0);
  }


//méthode
void monde::condition_initiale(position positions){
  //placement de la personne contaminée
  world[positions.get_x(0)][positions.get_y(0)] = 2;
  //placement des personnes saines
  for(unsigned int i=1; i < positions.get_N(); i++){
    world[positions.get_x(i)][positions.get_y(i)] = 1;
   }
}


void monde::deplacement(){
  int unsigned i, j;
  double proba; 
  for(i=0; i < positions.get_taille(); i++){
    for(j=0; j < positions.get_taille(); j++){
      if (world[i][j]!=0){ 
        proba=rand(); // proba de deplacement pour chaque personne
        
        // conditions aux bords
        if (i == 0 && j != 0 && j != positions.get_taille()-1){
          if(proba<=1/5){
            if(world[i][j-1]==0){
              world[i][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/5<proba && proba<=2/5){
            if(world[i+1][j-1]==0){
              world[i+1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/5<proba && proba<=3/5){
            if(world[i+1][j]==0){
              world[i+1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(3/5<proba && proba<=4/5){
            if(world[i+1][j+1]==0){
              world[i+1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(4/5<proba && proba<=1){
            if(world[i][j+1]==0){
              world[i][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        if (i == positions.get_taille()-1 && j != 0 && j != positions.get_taille()-1){
          if(proba<=1/5){
            if(world[i][j-1]==0){
              world[i][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/5<proba && proba<=2/5){
            if(world[i-1][j-1]==0){
              world[i-1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/5<proba && proba<=3/5){
            if(world[i-1][j]==0){
              world[i-1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(3/5<proba && proba<=4/5){
            if(world[i-1][j+1]==0){
              world[i-1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(4/5<proba && proba<=1){
            if(world[i][j+1]==0){
              world[i][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        if (j == 0 && i != 0 && i != positions.get_taille()-1){
          if(proba<=1/5){
            if(world[i-1][j]==0){
              world[i-1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/5<proba && proba<=2/5){
            if(world[i-1][j+1]==0){
              world[i-1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/5<proba && proba<=3/5){
            if(world[i+1][j]==0){
              world[i+1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(3/5<proba && proba<=4/5){
            if(world[i+1][j+1]==0){
              world[i+1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(4/5<proba && proba<=1){
            if(world[i][j+1]==0){
              world[i][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        if (j == positions.get_taille()-1 && i != 0 && i != positions.get_taille()-1){
          if(proba<=1/5){
            if(world[i-1][j]==0){
              world[i-1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/5<proba && proba<=2/5){
            if(world[i-1][j-1]==0){
              world[i-1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/5<proba && proba<=3/5){
            if(world[i+1][j]==0){
              world[i+1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(3/5<proba && proba<=4/5){
            if(world[i+1][j-1]==0){
              world[i+1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(4/5<proba && proba<=1){
            if(world[i][j-1]==0){
              world[i][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        
        // coins
        if (i == 0 && j == 0){
          if(proba<=1/3){
            if(world[i][j+1]==0){
              world[i][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/3<proba && proba<=2/3){
            if(world[i+1][j+1]==0){
              world[i+1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/3<proba && proba<=1){
            if(world[i+1][j]==0){
              world[i+1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        if (i == positions.get_taille()-1 && j == positions.get_taille()-1){
          if(proba<=1/3){
            if(world[i][j-1]==0){
              world[i][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/3<proba && proba<=2/3){
            if(world[i-1][j-1]==0){
              world[i-1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/3<proba && proba<=1){
            if(world[i-1][j]==0){
              world[i-1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        if (i == 0 && j == positions.get_taille()-1){
          if(proba<=1/3){
            if(world[i][j-1]==0){
              world[i][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/3<proba && proba<=2/3){
            if(world[i+1][j-1]==0){
              world[i+1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/3<proba && proba<=1){
            if(world[i+1][j]==0){
              world[i+1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        if (i == positions.get_taille()-1 && j == 0){
          if(proba<=1/3){
            if(world[i][j+1]==0){
              world[i][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(1/3<proba && proba<=2/3){
            if(world[i-1][j+1]==0){
              world[i-1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          if(2/3<proba && proba<=1){
            if(world[i-1][j]==0){
              world[i-1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
        
       
        
        // cas général
        else{
          if(proba<=1/8){ // la proba de deplacement donne la case dans laquelle se déplacer
            if(world[i+1][j]==0){ // ne peut pas se déplacer si une personne se trouve déjà dans la case
              world[i+1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(1/8<proba && proba<=2/8){
            if(world[i+1][j+1]==0){
              world[i+1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(2/8<proba && proba<=3/8){
            if(world[i][j+1]==0){
              world[i][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(3/8<proba && proba<=4/8){
            if(world[i-1][j+1]==0){
              world[i-1][j+1] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(4/8<proba && proba<=5/8){
            if(world[i-1][j]==0){
              world[i-1][j] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(5/8<proba && proba<=6/8){
            if(world[i-1][j-1]==0){
              world[i-1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(6/8<proba && proba<=7/8){
            if(world[i][j-1]==0){
              world[i][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
          else if(7/8<proba && proba<=1){
            if(world[i+1][j-1]==0){
              world[i+1][j-1] = world[i][j];
              world[i][j] = 0;
            }
          }
        }
      }
    }
  }
}

std::vector<std::vector<int> > monde::get_monde(){
  return world;
}
