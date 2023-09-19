project('ansies',
        'cpp',
        version : run_command('git', 'describe', '--tags', check : true).stdout().strip(),
        default_options : ['cpp_std=c++17'])

project_name = meson.project_name()
version = meson.project_version()

include_dir = meson.source_root()/'include'/project_name
src_dir = meson.source_root()/'src'
build_dir = meson.build_root()

conf_data = configuration_data()
conf_data.set('version', version)
configure_file(configuration : conf_data,
               input : include_dir/'version.hpp.in',
               output : 'version.hpp')

headers = files(include_dir/'ansies.hpp',
                build_dir/'version.hpp')

sources = files(src_dir/'ansies.cpp',
                src_dir/'version.cpp')

library(meson.project_name(), sources, version : version, install : true)
install_headers(headers, subdir : project_name)