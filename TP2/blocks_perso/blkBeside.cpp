#include "blkBlock.hpp"
#include "blkBeside.hpp"


//static c'est comme si c'était une fonction classique 
blk::expr blk::beside(expr op1, expr op2){
    return std::make_shared<Beside>(op1,op2);
}


int blk::Beside::compute_width     (blk::expr op1, blk::expr op2){
    return op1->get_width()+op2->get_width();
}

int blk::Beside::compute_height    (blk::expr op1, blk::expr op2){
    return compute_ref_height(op1,op2)+std::max(op1->get_height()-op1->get_ref_height(),op2->get_height()-op2->get_ref_height());
}

int blk::Beside::compute_ref_width (blk::expr op1, blk::expr op2){
    return op1->get_ref_width();
}

int blk::Beside::compute_ref_height(blk::expr op1, blk::expr op2){
    return std::max(op1->get_ref_height(),op2->get_ref_height());
}


void blk::Beside::print_inbounds_line(std::ostream& os, int line) const{
    this->op1->print_line(os,line);// si y'a rien il fait rien partie hachurée du schéma
    this->op2->print_line(os,line);// et il print la ligne du block deux
}


// constructeur 
blk::Beside::Beside(blk::expr op1, blk::expr op2):
    blk::Block(
        compute_width(op1,op2),
        compute_height(op1,op2),
        compute_ref_width(op1,op2),
        compute_ref_height(op1,op2)),
    op1(op1),
    op2(op2) {}

// destructeur 
blk::Beside::~Beside() {}