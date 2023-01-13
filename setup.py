import sys

from pybind11 import get_cmake_dir
from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

setup(
    ext_modules = [
        Pybind11Extension(
            "native_spl",
            ["cpp/native_spl.cpp"],
            define_macros = [('VERSION_INFO', "0.1.0")],
        ),
    ],
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
