#include "mpi_example.h"
#include <iostream>

void mpi_hello_world() {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    std::cout << "Hello world from rank " << rank << " of " << size << std::endl;
}
