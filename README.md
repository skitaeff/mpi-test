# mpi-test

Simple MPI blocking communications test

Steps:
- load "module load hpcx/2.5.0-redhat7.6"
- compile with "mpicc -std=c99 mpi-test.c -o mpi-test"
- run 'sbatch slurm-mpi-test' a few times
- observe with 'show_job'. 

The wall time is set to one minute that the experiment can be quckly re-run.