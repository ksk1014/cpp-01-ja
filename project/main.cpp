#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>  // abs() for integer


struct vehicle{
    int x;
    int y;
    int velocity;
    double orientation;
};

struct landmark{
    int x;
    int y;
    char simbol;
    std::string information;
};

void map_display(vehicle ego,const int* map, int rows, int cols, std::vector<landmark> landmarks){

    // コンソールにマップと自社位置を表示する関数
    for(int i=0 ; i < rows; i++){
 
        for(int j=0; j < cols; j++){
            int element = *(map + i * cols + j);

            char simbol = ' ';

            for(auto landmark : landmarks){
                if(i == landmark.y && j == landmark.x){
                    simbol = landmark.simbol;
                    std::cout << simbol;
                    }
            }

            if(simbol != ' '){
                continue;
            }else if(i == ego.y && j == ego.x){
                if(sin(ego.orientation) < 1e-10 && cos(ego.orientation) == 1){
                    std::cout << "→";
                }else if(sin(ego.orientation) == 1 && cos(ego.orientation) < 1e-10){
                    std::cout << "↑";
                }else if(sin(ego.orientation) < 1e-10 && cos(ego.orientation) == -1){
                    std::cout << "←";
                }else if(sin(ego.orientation) == -1 && cos(ego.orientation) < 1e-10){
                    std::cout << "↓";}
            }else if(element == 1){
                std::cout << "#";
            }else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        }

}

int main(){

    vehicle ego = {0,2,0,0};

    landmark home = {3,1,'H',"You've arrived at home"};
    landmark office = {1,7,'0',"You've arrived at office"};
    landmark park = {9,9,'P',"You've arrived at park"};

    std::vector<landmark> landmarks = {home, office, park};

    const int map[10][12] = {
        {1,1,0,1,1,0,1,1,0,1,1,1},
        {1,1,0,1,1,0,1,1,0,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,0,1,1,0,1,1,1},
        {1,1,0,1,1,0,1,1,0,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,0,1,1,0,1,1,1},
        {1,1,0,1,1,0,1,1,0,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,0,1,1,0,1,1,1},
    };

    int rows = sizeof(map)/sizeof(*map);
    int cols = sizeof(*map)/sizeof(**map);

    while (true) {

    vehicle temp_ego = ego;

    // コンソールにマップと自社位置を表示
    map_display(ego, &map[0][0], rows, cols, landmarks);

    // ランドマークのインフォメーションを表示
    for(auto landmark : landmarks){
        if(abs(ego.x - landmark.x) <= 1 && abs(ego.y - landmark.y) <= 1){
            std::cout << "[Info.] " << landmark.information << std::endl;
        }
    }

     // Handle user command and update car's position
     std::string command;
     std::cout << "Enter a command : l(turn left), r(turn right), s(straight), a(accelerate), d(decelerate), st(stop), q(quit): ";
     std::getline(std::cin, command);
     std::cout << "Your command << " << command << std::endl;

        if (command == "l") {
            ego.orientation += M_PI/2;
        } else if (command == "r") {
            ego.orientation -= M_PI/2;
        } else if (command == "s") {
            ego.x += ego.velocity * cos(ego.orientation);
            ego.y -= ego.velocity * static_cast<int>(sin(ego.orientation));
        } else if (command == "a") {
            ego.velocity += 1;
        } else if (command == "d") {
            ego.velocity -= 1;
        } else if (command == "st") {
            ego.velocity = 0;
        } else if (command == "q") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }

    if ( map[ego.y][ego.x] == 1){
        std::cout << "Cannot go ahead" << std::endl;
        ego = temp_ego;
    }
    
    //自車のステータスを表示
    std::cout << "<Vehicle Status>  position:" << "(" << ego.x << "," << ego.y << ")" << " " << "velocity:" << ego.velocity << " " << "orientation:" << ego.orientation << std::endl;

    }

    return 0;

};