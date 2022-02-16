// To be done
#include <blk.hpp>
#include <blkMoveRef.hpp>

blk::expr blk::move_ref(blk::expr op1, int new_x, int new_y){
    return std::make_shared<MoveRef>(op1,new_x,new_y); 
}

blk::MoveRef::MoveRef(blk::expr op, int ref_width, int ref_height):
    blk::Block(
        op->get_width(),
        op->get_height(),
        ref_width,
        ref_height),
    op(op){}

blk::MoveRef::~MoveRef(){}
// on doit décaler la ligne du au changement de ref 
void blk::MoveRef::print_inbounds_line(std::ostream& os, int line) const{
    op->print_line(os, line + (this->get_ref_height() - op->get_ref_height()));
}