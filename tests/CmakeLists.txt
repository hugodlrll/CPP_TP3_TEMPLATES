# Ajouter Google Test
add_subdirectory(../googletest googletest-build)

# Activer les tests
enable_testing()

# Créer l'exécutable de tests
add_executable(tests tests_main.cpp)

# Lier Google Test et le projet principal
target_link_libraries(tests gtest gtest_main)
