#pragma once

#include <stdexcept>
#include <vector> 
#include "rgb.hpp"


namespace colormap {
  class VectorBasedColorMap {
  public:
    using index_type = int; // Type de l'indice de couleur
    using color_type = rgb; // Type de codage de la couleur

  private:
    // A compléter
    using sequence_type = std::vector<color_type>;
    sequence_type colors_;
  public:
    int n; 

    class MissingColor : public std::runtime_error {
      color_type color_;
    public:
      MissingColor(const color_type& color) : std::runtime_error("Missing color"), color_(color) {}
      const color_type& color() { return color_; }
    };

    VectorBasedColorMap(int n); // Constructeur
    void clear(); // Vider le contenu de la table
    void add(const color_type& color); // Ajouter une nouvelle couleur à la table.

    // Renvoie l'indice de la couleur passée en argument.
    // Lance une exception MissingColor si la couleur n'est pas dans la table.
    index_type operator()(const color_type& color) const;

    // Renvoie la couleur associée à un indice
    const color_type& operator()(index_type index) const;
  };
};
