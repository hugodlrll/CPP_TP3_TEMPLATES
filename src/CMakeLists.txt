# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
)

set(HEADERS
    ../src/PointT.hpp
)

# Créer l'exécutable
add_executable(TemplateFormeProject ${SOURCES} ${HEADERS})