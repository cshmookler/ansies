"""Remove build files"""

import os
from shutil import rmtree


def remove(file: str) -> None:
    """Remove a file and ignore errors"""
    try:
        os.remove(file)
    except FileNotFoundError:
        pass


def clean() -> None:
    """Remove build files"""
    this_dir: str = os.path.dirname(__file__)
    rmtree(os.path.join(this_dir, "build"), ignore_errors=True)
    rmtree(os.path.join(this_dir, "test_package", "build"), ignore_errors=True)
    rmtree(os.path.join(this_dir, "__pycache__"), ignore_errors=True)
    remove(os.path.join(this_dir, "ansies", "version.hpp"))


if __name__ == "__main__":
    clean()