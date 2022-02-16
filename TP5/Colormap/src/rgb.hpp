#pragma once

namespace colormap {
  // rgb est une classe codant chacune de ses composantes par un octet non signé (de 0 à 255)
  struct rgb {
    // Type scalaire pour les composantes.
    using scalar_type = unsigned char;

    // Composantes RGB
    scalar_type red_, green_, blue_;

    // Constructeur à partir des 3 composantes
    rgb(scalar_type red, scalar_type green, scalar_type blue);

    // Constructeur par recopie
    rgb(const rgb& other) = default;
    
    // Opérateur de comparaison (égalité)
    bool operator==(const rgb& other) const; 
  };
  
};
