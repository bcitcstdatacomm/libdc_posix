# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

add_definitions( -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 )

if(APPLE)
    add_definitions( -D_DARWIN_C_SOURCE )
endif()

set(CMAKE_C_CLANG_TIDY "clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup")

# Make a shared library
add_library(dc_posix SHARED ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_SYS_LIST})
target_include_directories(dc_posix PRIVATE ../include/dc_posix)
target_include_directories(dc_posix PRIVATE /usr/include)
target_include_directories(dc_posix PRIVATE /usr/local/include)
target_link_directories(dc_posix PRIVATE /usr/local/lib)

set_target_properties(dc_posix PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

# All users of this library will need at least C11
target_compile_features(dc_posix PUBLIC c_std_11)
target_compile_options(dc_posix PRIVATE -g -fPIC)
target_compile_options(dc_posix PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(dc_posix PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(dc_posix PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wpacked -Wpadded -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wlong-long -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings )
# target_compile_options(dc_posix PRIVATE -fanalyzer -fanalyzer-call-summaries -fanalyzer-checker=taint -fno-analyzer-feasibility -fanalyzer-fine-grained -fanalyzer-state-merge -fanalyzer-state-purge -fanalyzer-transitivity -fanalyzer-verbose-edges -fanalyzer-verbose-state-changes -fanalyzer-verbosity=3 -fdump-analyzer -fdump-analyzer-stderr -fdump-analyzer-callgraph -fdump-analyzer-exploded-graph -fdump-analyzer-exploded-nodes -fdump-analyzer-exploded-nodes-2 -fdump-analyzer-exploded-nodes-3 -fdump-analyzer-exploded-paths -fdump-analyzer-feasibility -fdump-analyzer-json -fdump-analyzer-state-purge -fdump-analyzer-supergraph -Wno-analyzer-double-fclose -Wno-analyzer-double-free -Wno-analyzer-exposure-through-output-file -Wno-analyzer-file-leak -Wno-analyzer-free-of-non-heap -Wno-analyzer-malloc-leak -Wno-analyzer-mismatching-deallocation -Wno-analyzer-null-argument -Wno-analyzer-null-dereference -Wno-analyzer-possible-null-argument -Wno-analyzer-possible-null-dereference -Wno-analyzer-shift-count-negative -Wno-analyzer-shift-count-overflow -Wno-analyzer-stale-setjmp-buffer -Wno-analyzer-tainted-array-index -Wanalyzer-too-complex -Wno-analyzer-unsafe-call-within-signal-handler -Wno-analyzer-use-after-free -Wno-analyzer-use-of-pointer-in-stale-stack-frame -Wno-analyzer-use-of-uninitialized-value -Wno-analyzer-write-to-const -Wno-analyzer-write-to-string-literal )
# target_compile_options(dc_posix PRIVATE -analyzer-checker=core -analyzer-checker=cpp -analyzer-checker=unix -analyzer-checker=deadcode -analyzer-checker=optin -analyzer-checker=security -analyzer-checker=unix -analyzer-checker=unix)

install(TARGETS dc_posix LIBRARY DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include/dc_posix)
install(FILES ${HEADER_SYS_LIST} DESTINATION include/dc_posix/sys)

# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST} ${HEADER_SYS_LIST}
)
