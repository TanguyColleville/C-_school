#include "blkBlock.hpp"
// les refs c'est l'origine du tableau 

// Constructeur : 
blk::Block::Block(int width, int height, int ref_width,int ref_height):width(width),height(height),ref_width(ref_width),ref_height(ref_height){}

// Destructeur : 
blk::Block::~Block(){}// on n'a pas pointeur pour le moment 


// les acesseurs : 
int blk::Block::get_width()      const {return width;}
int blk::Block::get_height()     const {return height;}
int blk::Block::get_ref_width()  const {return  ref_width;}
int blk::Block::get_ref_height() const {return ref_height;}


// Returns the lowest line number which is in the block.
int blk::Block::min_line() const {
    return - this->ref_height; 
}
// Returns 1 + the highest line number which is in the block.
int blk::Block::max_line() const{
    return this->height - this->ref_height;
}


// Prints any line. If the line is outside the block, it prints a
// range of spaces. Otherwise, it calls print_inbounds_line to
// print the block content at that line. We declare this method
// public for now, but this will have to be reconsider later, in
// the "better design" part of the labwork.

// verifie si on est dans bien le quadrillage et si oui on appele la méthode virtuelle de print in bouds line
void blk::Block::print_line(std::ostream& os, int line) const{
    if((line >= min_line()) && (line < max_line())){
        print_inbounds_line(os, line);
    }
    else{
        os<<"  ";
    }
}

std::ostream& blk::operator<<(std::ostream& os, blk::expr e){// e comme block tant qu'on a le type blk::expr
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



