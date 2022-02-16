#include <blkBlock.hpp>
#include <blkText.hpp>

// To be done
namespace blk{
    expr text(std::string text,align alignment){
        return std::make_shared<Text>(text, alignment);
    }
    /*
    Pas aussi simple que ça parqu'on ne veut pas juste un bloc de longueur la chaine de carac
    Text::Text(std::string m_text):Block(m_text.length(),1,0,0),m_text(m_text){}
    */
   int Text::compute_ref_width(const std::string& m_text,align alignment){
        if (alignment==align::center){
            return m_text.length()/2; 
        }
        if(alignment==align::left){
            return 0;
        }
        else{
            return m_text.length(); 
        }
   }

    Text::Text(const std::string& m_text,align alignment):Block(m_text.length(),1,this->compute_ref_width(m_text, alignment),0),m_text(m_text){}
    // Destructeur 
    Text::~Text(){}

    // print in bounds 
    void Text::print_inbounds_line(std::ostream& os, int line) const{
        os<<this->m_text;
    }
  };
