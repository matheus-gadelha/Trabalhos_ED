#include <stdio.h>
#include "xpaint.h"

void floquinho(int x, int y, int ang, int lado){

    if(lado < 10){
        return;
    }

    for(int i = 0; i < 5; i++){
        float fx = x + lado * xm_cos(ang); //Descobre a coordenada do x final
        float fy = y - lado * xm_sin(ang); //Descobre a coordenada do y final

        xd_thick_line(x, y, fx, fy, 2);
        x_step("floco");

        floquinho(fx, fy, ang+= 72, lado/3);
    }

    
}


int main(){
    x_open(1000, 1000);

    floquinho(1000/2, 1000/2, 54, 300);
    x_save("floco");
    x_close();

    return 0;    
}