add_subdirectory(controllers/sign_in)
add_subdirectory(db)
add_subdirectory(filters)
add_subdirectory(utilities)

list(APPEND SRC
    ${sign_in_SRC}
    ${db_SRC}
    ${filters_SRC}
    ${utilities_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/AccountManager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(SRC ${SRC} PARENT_SCOPE)