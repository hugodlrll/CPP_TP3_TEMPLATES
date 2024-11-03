# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
)

set(HEADERS
    ../src/PointT.hpp
    ../src/Forme.hpp
    ../src/Rectangle.hpp
    ../src/Carre.hpp
    ../src/ListeFormes.hpp
)

# Créer l'exécutable
add_executable(TemplateFormeProject ${SOURCES} ${HEADERS})