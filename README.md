# pybind-mpi_build_example

[![Gitter][gitter-badge]][gitter-link]

|      CI              | status |
|----------------------|--------|
| conda.recipe         | [![Conda Actions Status][actions-conda-badge]][actions-conda-link] |
| pip builds           | [![Pip Actions Status][actions-pip-badge]][actions-pip-link] |


An example MPI project built with [pybind11][] and [scikit-build-core][]. Python
3.7+. In this repository, we demonstrate how to expose a Python interface to an MPI-parallel program using pybind11 and scikit-build. This strategy is helpful on such [cases](https://enccs.se/news/2021/03/mpi-hybrid-c-python-code/):

- You have a C++ MPI-parallel library and you would like to provide a Python interface to it.
- You have an MPI-parallel Python program and you want to rewrite some core functionality in C++ for performance reasons.


[gitter-badge]:            https://badges.gitter.im/pybind/Lobby.svg
[gitter-link]:             https://gitter.im/pybind/Lobby
[actions-badge]:           https://github.com/pybind/scikit_build_example/workflows/Tests/badge.svg
[actions-conda-link]:      https://github.com/pybind/scikit_build_example/actions?query=workflow%3AConda
[actions-conda-badge]:     https://github.com/pybind/scikit_build_example/workflows/Conda/badge.svg
[actions-pip-link]:        https://github.com/pybind/scikit_build_example/actions?query=workflow%3APip
[actions-pip-badge]:       https://github.com/pybind/scikit_build_example/workflows/Pip/badge.svg
[actions-wheels-link]:     https://github.com/pybind/scikit_build_example/actions?query=workflow%3AWheels
[actions-wheels-badge]:    https://github.com/pybind/scikit_build_example/workflows/Wheels/badge.svg


## Installation

### MPI SetUp

Provide an example on the Ubuntu.

```shell
sudo apt-get update && sudo apt-get upgrade
sudo apt-get install openmpi-bin openmpi-common libopenmpi-dev libgtk2.0-dev
# sudo apt-get install -f 
```

### Pybind SetUp
- `conda create -n pybd python=3.8`
- `conda activate pybd`
- `pip install pybind11 mpi4py`
- `git clone https://github.com/jieli-matrix/pybind-mpi.git`
- `cd pybind-mpi && pip install -v .`

## Test call

```
mpirun -n 8 --allow-run-as-root python tests/test_basic.py

Hello world from rank 4 of 8
Hello world from rank 0 of 8
Hello world from rank 1 of 8
Hello world from rank 5 of 8
Hello world from rank 6 of 8
Hello world from rank 7 of 8
Hello world from rank 2 of 8
Hello world from rank 3 of 8
```

## Files

This example has several files that are a good idea, but aren't strictly
necessary. The necessary files are:

* `pyproject.toml`: The Python project file
* `CMakeLists.txt`: The CMake configuration file
* `src/main.cpp`: The source file for the C++ build
* `src/scikit_build_example/__init__.py`: The Python portion of the module. The root of the module needs to be `<package_name>`, `src/<package_name>`, or `python/<package_name>` to be auto-discovered.

These files are also expected and highly recommended:

* `.gitignore`: Git's ignore list, also used by `scikit-build-core` to select files for the SDist
* `README.md`: The source for the PyPI description
* `LICENSE`: The license file

There are also several completely optional directories:

* `.github`: configuration for [Dependabot][] and [GitHub Actions][]
* `conda.recipe`: Example recipe. Normally you should submit projects to conda-forge instead of building them yourself, but this is useful for testing the example.
* `docs/`: Documentation
* `tests/`: Tests go here

And some optional files:

* `.pre-commit-config.yaml`: Configuration for the fantastic static-check runner [pre-commit][].
* `noxfile.py`: Configuration for the [nox][] task runner, which helps make setup easier for contributors.

This is a simplified version of the recommendations in the [Scientific-Python
Development Guide][], which is a _highly_ recommended read for anyone
interested in Python package development (Scientific or not). The guide also
has a cookiecutter that includes scikit-build-core and pybind11 as a backend
choice.

### CI Examples

There are examples for CI in `.github/workflows`. A simple way to produces
binary "wheels" for all platforms is illustrated in the "wheels.yml" file,
using [cibuildwheel][].

## License

pybind11 is provided under a BSD-style license that can be found in the LICENSE
file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.

[cibuildwheel]: https://cibuildwheel.readthedocs.io
[scientific-python development guide]: https://learn.scientific-python.org/development
[dependabot]: https://docs.github.com/en/code-security/dependabot
[github actions]: https://docs.github.com/en/actions
[pre-commit]: https://pre-commit.com
[nox]: https://nox.thea.codes
[pybind11]: https://pybind11.readthedocs.io
[scikit-build-core]: https://scikit-build-core.readthedocs.io
[scikit-build (classic)]: https://scikit-build.readthedocs.io
