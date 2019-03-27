#include <stdio.h>
#include "xpaint.h"

void trigo(int x, int y, int ang, int lado){
     if(lado < 10){
        return;
    }

    float x1 = x;
    float y1 = y;
    
    for(int i = 0; i < 4; i++){
        float fx = x1 + lado * xm_cos(ang); //Descobre a coordenada do x final
        float fy = y1 - lado * xm_sin(ang); //Descobre a coordenada do y final

        xd_thick_line(x1, y1, fx, fy, 2);
        x_step("trigo");

        trigo(fx, fy, ang - 40, lado/3);
        trigo(fx, fy, ang + 40, lado/3);

        x1 = fx;
        y1 = fy;
    }
    
}

int main(){
    x_open(700, 850);

    trigo(700/2, 850 - 20, 90, 150);
    x_save("trigo");
    x_close();

    return 0;
}