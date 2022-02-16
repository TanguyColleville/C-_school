#pragma once
#include <blkBlock.hpp>
// To be done


namespace blk{
    expr move_ref(expr op1, int new_x, int new_y);

  class MoveRef : public Block {
  private:
    
    expr op;// pourquoi c'est que ça ? 
    
  public:
    
    MoveRef(expr op, int ref_width, int ref_height);
    virtual ~MoveRef();
    // parce qu'on va devoir repenser notre plot vu qu'il reposait sur l'origine avant 
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
