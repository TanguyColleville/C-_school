#pragma once

// To be done
namespace blk {
    expr move_ref(expr op, int x, int y);

    class MoveRef : public Block {
        public : 
            MoveRef(expr op, int ref_width, int ref_height);
            virtual ~MoveRef();
    // parce qu'on va devoir repenser notre plot vu qu'il reposait sur l'origine avant 
            virtual void print_inbounds_line(std::ostream& os, int line) const override;
        
        private : 
        expr b; // juste un pointeur 
    }

}
