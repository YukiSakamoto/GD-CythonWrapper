from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

source = ['./gd_w.pyx', './gd_wrapper.c']

setup(
        cmdclass = dict(build_ext = build_ext),
        ext_modules = [
            Extension(
                'GDWrapper',
                source,
                language='c',
                libraries = ['gd'],
                library_dirs = ['/usr/local/lib'],
            )
        ]
    )
