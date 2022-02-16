#pragma once

#include <blkBlock.hpp>

namespace blk {
    // on surcharger tous les opérateurs pour dire ok 
    // si j'ai + je beside les blocks, si j'ai div je over etc.. 

  expr operator+ (expr a, expr b);
  expr operator==(expr a, expr b);
  expr operator/ (expr a, expr b);
  
  expr operator+ (double a, expr b);
  expr operator==(double a, expr b);
  expr operator/ (double a, expr b);
  
  expr operator+ (expr a, double b);
  expr operator==(expr a, double b);
  expr operator/ (expr a, double b);
  
}


