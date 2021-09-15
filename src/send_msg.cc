#include<iostream>
#include<mpi.h>
using namespace std;

int main(int argc, char *argv[])
{
  MPI_Init(NULL,NULL);
  int rank;
  MPI_Status status;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  if(rank==0){
    int x = 10;
    cout <<"\n master: "<<x<<endl;
    MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
  }else{
    int y;
    MPI_Recv(&y,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
    cout <<"\n slave: "<<++y<<endl; 
  }
  MPI_Finalize();
  return 0;
}
