# BOB: a really simple build tool for single-file C++ sources

## Introduction

Do you write a lot of little C++ programs that consist of only one 
source file? 

1. You don't want to keep typing long compilation commands to specify
   include paths, dependencies, preprocessor switches, etc?
2. Tou don't want to write a Makefile or shell script to overcome point 1?

Then BOB may be of interest. It allows you to store build information
at the start of the source file, which BOB then parses to construct and
execute the compilation. It supports dependencies based on pkg-config, 
or the legacy way of specifying include directories, library directories 
and libraries to link manually.

## Usage

The header of your source file is scanned for lines starting with '///'.
These lines can contain the following directives:
    
    /// packagedir       <dir>                   (<dir>/lib/pkgconfig is searched)'
    /// usepackage       <pkgname>'
    /// legacydir        <dir>                   (adds <dir>/include and <dir>/lib)'
    /// legacyincludedir <dir>'
    /// legacylibrarydir <dir>'
    /// uselibrary       <libname>'
    /// rpath            <dir>                   (extra rpath to use)'
    /// target           executable|sharedlib'
    /// outputfile       <filename>'
    /// cflags           <flags>                 (may contain `<expr>`)'
    /// lflags           <flags>                 (may contain `<expr>`)'
    
## Example

See included example-opengl.cpp

    $ bob -n  example-opengl.cpp 
    DRY RUN, WOULD EXECUTE:
    ['g++', '-O2', '-D_GNU_SOURCE=1', '-D_REENTRANT', '-I/usr/include/SDL', '-o', 'example-opengl', 'example-opengl.cpp', '-lSDL', '-lGL']
    $ bob example-opengl.cpp
    $ ./example-opengl 
    Screen resolution: 2560 x 1600
    Vendor: NVIDIA Corporation
    Renderer: GeForce GTX 560 Ti/PCIe/SSE2
    Version: 4.3.0 NVIDIA 319.49
    GLSL version: 4.30 NVIDIA via Cg compiler
    ...

## Command-line options

    Usage: bob [options] <source-file>

    Options:
      -h, --help            show this help message and exit
      -n, --dry-run         Don't actually do anything, just print command line to
                            execute
      -v, --verbose         Verbose output
      -r, --no-rpath        Don't set rpath in executable (default: do set rpath)
      -O OPTIMIZATION_LEVEL, --optimization-level=OPTIMIZATION_LEVEL
                            Optimization level, i.e. -O<value> (default: 2%)
      -g, --debug           Include debug information (default: no debug
                            information)
      -u ENABLED_SWITCHES, --use=ENABLED_SWITCHES
                            Turns the given switch on, always overrides switch
                            directive in source

## Switches

There's also rudimentary support different build configurations, using binary "switches":
    
    /// switch           <name> 0|1              (0|1 value specifies the default)'
    /// {<conditional>}  directive ...           (note: <conditional> is eval()ed!)'    


bob -u SWITCH

Also #defines USE_SWITCH





