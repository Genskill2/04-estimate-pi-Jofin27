#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }
  //printf("pi=%f\n",pi);

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
  //printf("pi=%f\n",pi);
}

float wallis_pi(int x)
{
	int nr,dr;
	nr=1;
	dr=1;
	double quo,req,pro;
	quo=1.0;
	pro=1.0;
	for(int i=0;i<x;i++)
	{
		nr=(4*pow((i+1),2));
		dr=((4*pow((i+1),2))-1);
		quo=(float)nr/dr;
		pro*=quo;
	//printf("nr=%d\ndr=%d\nquo=%f\npro=%f\n",nr,dr,quo,pro);
	}
	req=2*pro;
	//printf("req=%f\n",req);
return req;
}


