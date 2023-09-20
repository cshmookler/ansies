project('ansies_package_test',
        'cpp',
        version : '1.0.0',
        default_options : ['cpp_std=c++17'])

ansies = dependency('ansies')

executable(meson.project_name(),
           'src'/'main.cpp',
           dependencies : ansies)