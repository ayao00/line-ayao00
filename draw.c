#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0 > x1){
    int hold = x0;
    x0 = x1;
    x1 = hold;
    hold = y0;
    y0 = y1;
    y1 = hold;
  }

  int x = x0;
  int y = y0;

  int a = y1 - y0;
  int b = -1 * (x1 - x0);
  if(b == 0){
    if(y < y1){
      while(y < y1){
        plot(s,c,x,y);
        y++;
      }
    }
    else{
      while(y > y1){
        plot(s,c,x,y);
        y--;
      }
    }
    return;
  }
  double m = -1 * (double)a / (double) b;

  int d;


  if(m <= 1 && m >= 0){
    d = (2 * a) + b;
    while(x <= x1){
      plot(s,c,x,y);
      if(d > 0){
        y++;
        d += 2 * b;
      }
      x++;
      d += 2 * a;
    }
  }
  else if(m > 1){
    d = (2 * b) + a;
    while(y <= y1){
      plot(s,c,x,y);
      if(d < 0){
        x++;
        d += 2 * a;
      }
      y++;
      d += 2 * b;
    }
  }
  else if(m <= 0 && m >= -1){
    d = (2 * a) + b;
    while(x <= x1){
      plot(s,c,x,y);
      if(d < 0){
        y--;
        d -= 2 * b;
      }
      x++;
      d += 2 * a;
    }
  }
  else if(m < -1){
    d = a - (2 * b);
    while(y >= y1){
      plot(s,c,x,y);
      if(d > 0){
        x++;
        d += 2 * a;
      }
      y--;
      d -= 2 * b;
    }
  }
}
