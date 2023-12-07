#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }


  int rank = world_rank;
  int i;

  if (world_rank != 0) {
    // If we are rank non-0, send the rank to process 0

    MPI_Send(
      /* data         = */ &rank, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_INT, 
      /* destination  = */ 0, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD);
  } else if (world_rank == 0) {

    printf("Process 0 reports that world_size = %d\n", world_size);

    for(i=1; i<world_size; i++){
    MPI_Recv(
      /* data         = */ &rank, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_INT, 
      /* source       = */ i, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD, 
      /* status       = */ MPI_STATUS_IGNORE);
    printf("Process 0 received message from rank %d\n", rank);
   }
  }
  MPI_Finalize();
}