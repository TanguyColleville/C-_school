#include "blkBlock.hpp"
#include "blkDebug.hpp"

// fais un pointeur d'un objet debug, seulement sur la partie block car c'est un type expr
blk::expr blk::debug(char label, int width, int height, int ref_width, int ref_height){
    return std::make_shared<Debug>(label,width,height,ref_width,ref_height);
}
//constructeur : Attention l'ordre compte car on hérite de block 
blk::Debug::Debug(char label, int width, int height, int ref_width, int ref_height):blk::Block::Block(width,height,ref_width,ref_height),label(label){}

// destructeur 
blk::Debug::~Debug(){}


void blk::Debug::print_inbounds_line(std::ostream& os, int line) const{
    if (line!= 0){// si la ligne est différent de la ligne de ref
    os<<std::string(this->get_width(),label);//aaaaa
    }
    else{
    for(int column = 0; column < get_width(); ++column){// sinon on insert le # au bon endroit
      if(column == get_ref_width()){
	os << '#';}
      else{
	os << label;}
  }
  }
}