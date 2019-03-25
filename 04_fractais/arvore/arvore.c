#include "xpaint.h"
#include <stdlib.h>

void fractal(float x, float y, float ang, float lado){
    int fruta = xm_rand(0, 100);

    if(lado < xm_rand(8, 20)){
        if(fruta <= 20){
            xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
            xd_filled_circle(x + lado * xm_cos(ang), y - lado * xm_sin(ang), 8);
        }
        
        return;
    }
    
    float fx = x + lado * xm_cos(ang); //Descobre a coordenada do x final
    float fy = y - lado * xm_sin(ang); //Descobre a coordenada do y final
    
    
    if(lado > 70.0){
        int galhos = xm_rand(0, 100);
        xs_color((XColor){139, 69, 19});
        xd_thick_line(x, y, fx, fy, 7);

        if(galhos <= 40){
            xs_color((XColor){139, 69, 19});
            fractal(fx, fy, ang, lado - xm_rand(8, 15) );
        }


    }else if(lado > 50.0){
        xs_color((XColor){160, 82, 45});
        xd_thick_line(x, y, fx, fy, 5);
        

    }else if(lado > 30.0){
        int galhos = xm_rand(0, 100);
        xs_color((XColor){205, 133, 63});
        xd_thick_line(x, y, fx, fy, 2);

        if(galhos <= 60){
            xs_color((XColor){205, 133, 63});
            fractal(fx, fy, ang, lado - xm_rand(8, 15) );
        }
        
        
    }
    

    xd_thick_line(x, y, fx, fy, 2); /* desenha a linha */
    x_step("arvore");
    
    fractal(fx, fy, ang - xm_rand(40, 55) , lado - xm_rand(8, 15) );
    
    fractal(fx, fy, ang + xm_rand(40, 55), lado - xm_rand(8, 15) );
}

int main(){
    x_open(800, 600);
    srand(0); /* comente para ter sempre uma arvore diferente */
    fractal(400, 550, 90, 100);
    x_save("arvore");
    x_close();
    return 0;
}
