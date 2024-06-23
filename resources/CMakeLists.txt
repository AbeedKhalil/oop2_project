add_subdirectory (Sounds)
add_subdirectory (Fonts)
add_subdirectory (Textures)

configure_file ("bullet.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Tank.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("soldier.png" ${CMAKE_BINARY_DIR} COPYONLY)