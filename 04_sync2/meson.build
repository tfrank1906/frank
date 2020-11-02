project('04_sync2', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['warning_level=3', 'werror=true'])

 thread_dep = dependency('threads')

inc_dir = include_directories('include')

src = ['src/loadsim.cpp', 'src/work_queue.cpp']

executable('WorkPacket',
            sources : src,     
            dependencies : thread_dep,
            include_directories: inc_dir
           )



