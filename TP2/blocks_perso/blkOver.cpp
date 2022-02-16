// To be done
#include <blkOver.hpp> 
#include "blkBlock.hpp"

blk::expr blk::over(blk::expr op1, blk::expr op2){
    return std::make_shared<blk::Over>(op1,op2);   
}


int blk::Over::compute_ref_width (blk::expr op1, blk::expr op2){
      return std::max(op1->get_ref_width(), op2->get_ref_width());
}
int blk::Over::compute_ref_height(blk::expr op1, blk::expr op2){
    return op1->get_ref_height();
}

int blk::Over::compute_width     (blk::expr op1, blk::expr op2){
    return compute_ref_width(op1,op2)+ std::max(op1->get_width()-op1->get_ref_width(), op2->get_width()-op2->get_ref_width());
}

int blk::Over::compute_height    (blk::expr op1, blk::expr op2){
    return op1->get_height()+op2->get_height();
}


void blk::Over::print_inbounds_line(std::ostream& os, int line) const{
  if(line < op1->get_height() - op1->get_ref_height()) {
    std::string before = std::string(std::max(this->op2->get_ref_width() - this->op1->get_ref_width(), 0), ' ');
    std::string after  = std::string(std::max((this->op2->get_width() - this->op2->get_ref_width()) - (this->op1->get_width() - this->op1->get_ref_width()), 0), ' ');
    os << before;
    this->op1->print_line(os, line);
    os << after;
  }
  else {
    std::string before = std::string(std::max(this->op1->get_ref_width() - this->op2->get_ref_width(), 0), ' ');
    std::string after  = std::string(std::max((this->op1->get_width() - this->op1->get_ref_width()) - (this->op2->get_width() - this->op2->get_ref_width()), 0), ' ');
    os << before;
    this->op2->print_line(os, line - (this->op1->get_height() - this->op1->get_ref_height()) - this->op2->get_ref_height());
    os << after;
  }
}


blk::Over::Over(blk::expr op1,blk::expr op2):
    Block(
        compute_width(op1,op2),
        compute_height(op1,op2),
        compute_ref_width(op1,op2),
        compute_ref_height(op1,op2)
    ),
    op1(op1),
    op2(op2){}

blk::Over::~Over(){}
