project('03_sync1', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['warning_level=3', 'werror=true'])

 thread_dep = dependency('threads')

inc_dir = include_directories('include')

src = ['src/account.cpp', 'src/main.cpp']

executable('account',
            sources : src,     
            dependencies : thread_dep,
            include_directories: inc_dir
           )



