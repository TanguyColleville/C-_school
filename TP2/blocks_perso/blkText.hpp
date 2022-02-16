#pragma once
#include <blkBlock.hpp>

// To be done
namespace blk{
    enum class align: char {left, center, right};// ça c'est une class qui prend une des trois val

    expr text(std::string text,align alignment=align::center);// valeur par défaut center

    class Text : public Block {
    private : 
        std::string m_text;
        // la ref width va devoir être calculée en fonction de l'alignement 
        static int compute_ref_width(const std::string& label, align alignment);

  public:

    // Constructeur
    Text(const std::string& m_text,align alignment);

    // Destructeur 
    virtual ~Text();

    // print in bounds 
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
