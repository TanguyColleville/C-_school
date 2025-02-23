#pragma once

namespace colormap {
  // rgb est une classe codant chacune de ses composantes par un octet non sign� (de 0 � 255)
  struct rgb {
    // Type scalaire pour les composantes.
    using scalar_type = unsigned char;

    // Composantes RGB
    scalar_type red_, green_, blue_;

    // Constructeur � partir des 3 composantes
    rgb(scalar_type red, scalar_type green, scalar_type blue);

    // Constructeur par recopie
    rgb(const rgb& other) = default;
    
    // Op�rateur de comparaison (�galit�)
    bool operator==(const rgb& other) const; 
  };
  
};
