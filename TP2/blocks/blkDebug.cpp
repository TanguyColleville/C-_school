#include "blkBlock.hpp"
#include "blkDebug.hpp"

// To be done
namespace blk {
    Debug::Debug(char label, int width, int height, int ref_width, int ref_height):Block(width,height,ref_width,ref_height),label(label){};
    Debug::~Debug(){};


    expr debug(char label, int width, int height, int ref_width, int ref_height){
        return std::make_shared<Debug>(label,width,height,ref_width,ref_height);
    }
    void Debug::print_inbounds_line(std::ostream& os, int line) const {
        if (line!= 0){// si la ligne est différent de la ligne de ref
        os<<std::string(this->get_width(),label);//aaaaa
        }
        else{
        for(int column = 0; column < get_width(); ++column){// sinon on insert le # au bon endroit
          if(column == get_ref_width()){
      os << '#';
            }
          else{
      os << label;
               }
        }
            }
    };

}