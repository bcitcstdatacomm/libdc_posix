set(DOXYGEN_EXTRACT_ALL YES)

doxygen_add_docs(docs dc_posix/dc_posix "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md"
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
