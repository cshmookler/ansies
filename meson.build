# Declare project information
project(
    'ansies',
    'cpp',
    version : files('VERSION'),
    default_options : [ 'cpp_std=c++17' ],
)

# Project root and build directories
root_dir = meson.project_source_root()
build_dir = meson.project_build_root()
include_dir = root_dir / 'ansies'

# Insert the project version into the version header file
conf_data = configuration_data()
conf_data.set('version', meson.project_version())
configure_file(
    configuration : conf_data,
    input : 'ansies' / 'version.hpp.in',
    output : 'version.hpp',
)

# Install headers
headers = files(
    build_dir / 'version.hpp',
    include_dir / 'ansies.hpp'
)
install_headers(headers, subdir : 'ansies')
