import os
import fnmatch
from building import *

src = []
inc = []
cwd = GetCurrentDir()  # get current dir path

SRC_DIR = os.path.join(cwd, "src")


def glob_relpath(pattern, root='.', relative_to='.'):
    """Find files matching pattern and return relative paths."""
    result = []
    for root_dir, _, files in os.walk(root):
        for name in files:
            if fnmatch.fnmatch(name, pattern):
                full_path = os.path.join(root_dir, name)
                # Use relative path for C source code, so .o will be generated in build subfolder
                rel_path = os.path.relpath(full_path, relative_to)
                result.append(rel_path)
    return result


inc += [cwd]
src += glob_relpath("*.c", os.path.join(SRC_DIR, "apps"), cwd)

group = DefineGroup('watchx', src, depend=[''], CPPPATH=inc)
Return('group')
