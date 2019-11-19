#include <iostream>
#include <fstream>
#include <cmath>




static double D = 1.0;
static double s = 1.0;

float** createPsi(int N_t, int N_x, string filename);


int main(void)
{
    string datos = "datos";
    int N_x = 30;
    int N_t= 100;
    createPsi(N_t,N_x,datos);

    return 0;
}


float** createPsi(int N_t, int N_x, string filename)
{
    
    float Psi[N_t][N_x];
    float dx = 2 / N_x ;
    float dt = 1 / N_t;
    float t_0 = 0.0;
    float t_max = 1.0;
    double x_0 = -1.0;
    double x_max = 1.0;
    
    ofstream outfile;
    outfile.open(filename);
    
    for (int n=0; n<N_t; n++)
    {
        for(int j=0; j<N_x; j++)
        {
            if (j==0 || j== (N_x - 1))
            {
                Psi[n][j] = 0.0;
            }
            
            if (n==0)
            {
                Psi[n][j] = 0.0;
            }
            
            else 
            {
                Psi[n+1][j] = Psi[n][j] + (((D*dt)/(dx*dx))*(Psi[n][j+1]-(2*Psi[n][j])+Psi[n][j-1]))+(s*dt);
            }
            
            t_0 += dt;
        }
        
        x_0 += dx;
        
        outfile << Psi[n][j]<< " "<< x_0 << " "<< Psi[n][j]<< " ";
        outfile.close();
    }
}