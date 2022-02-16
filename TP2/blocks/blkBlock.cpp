#include "blkBlock.hpp"

// To be done
namespace blk {
    Block::Block(int width, 
	  int height,
	  int ref_width,
	  int ref_height):width(width),height(height),ref_width(ref_width),ref_height(ref_height){};
    
    Block::~Block(){};

    int Block::get_width()      const {return this->width;};
    int Block::get_height()     const {return this->height;};
    int Block::get_ref_width()  const {return this->ref_width;};
    int Block::get_ref_height() const {return this->ref_height;};

    int Block::min_line() const{
        return - this->ref_height;
    }
    int Block::max_line() const{
        return this->height - this->ref_height;
    }
    void Block::print_line(std::ostream& os, int line) const{
        if((line >= min_line()) && (line < max_line())){
        print_inbounds_line(os, line);
    }
    else{
        os<<"  ";
    }
}

    std::ostream& operator<<(std::ostream& os, expr e){
    if(e != nullptr){
    for(int line=e->min_line(); line<e->max_line();line++){
        os<<line<<" : "; 
        e->print_line(os,line);
        os<<std::endl;
    }
    }
      else
    os << "null";
    return os; 
}


}