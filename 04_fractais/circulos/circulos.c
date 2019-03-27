#include <stdio.h>
#include "xpaint.h"

void circulos(int x, int y, int raio){
    int angulo = 0;

    if(raio < 10){
        return;
    }

    for(int i = 0; i < 6; i++){
        angulo += 60;
        float fx = x + raio * xm_cos(angulo); //Descobre a coordenada do x final
        float fy = y - raio * xm_sin(angulo); //Descobre a coordenada do y final

        xd_circle(x, y, raio);
        x_step("circulos");

        circulos(fx, fy, raio/3);
    
    }
}

int main(){
    x_open(1000, 1000);

    circulos(500, 500, 300);
    x_save("circulos");
    x_close();
    return 0;
}