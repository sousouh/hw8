#include <iostream>
#include <cmath>

using namespace std;

struct star{
  double q[2], p[2];
};

void init(star* b, double& H){
 const double e=0.6;
 
 H = -1./2.;
 b -> q[0] = 1. - e;
 b -> q[1] = 0.;
 b -> p[0] = 0.;
 b -> p[1] = sqrt((1. + e)/(1. - e));
 
 }
 
 int main(){
 double H;
 const double dt=5 * 1e-4; 
 const double T = 20*M_PI;
 star b;
 init(&b,H);
 
 cout << "0" << "\t" << H << "\t" << b.q[0] << "\t" << b.q[1] << "\t" << b.p[0] << "\t" << b.p[1] << endl;
 
 
 for (double t=dt; t<=T; t+=dt){
   
 for(int i=0; i<2; i++){
   b.p[i] -= dt* b.q[i]*pow((b.q[0] * b.q[0] + b.q[1] * b.q[1]),-3./2.);
   b.q[i] += dt* b.p[i];
 }
 
 H = (1/2)*(b.p[0] * b.p[0] + b.p[1] * b.p[1]) - 1/sqrt((b.q[0] * b.q[0] + b.q[1] * b.q[1]));
 cout << t << "\t" << H << "\t" << b.q[0] << "\t" << b.q[1] << "\t" << b.p[0] << "\t" << b.p[1] << endl;
 }
   return 0;
 }