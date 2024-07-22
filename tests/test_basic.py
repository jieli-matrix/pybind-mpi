from __future__ import annotations

import scikit_build_example as m
import mpi4py.MPI as MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if __name__ == "__main__":
    m.mpi_hello_world()