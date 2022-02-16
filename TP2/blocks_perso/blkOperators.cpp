// To be done
#include<blk.hpp>
#include<blkOperators.hpp>


namespace blk {
    // on surcharger tous les opérateurs pour dire ok 
    // si j'ai + je beside les blocks, si j'ai div je over etc.. 

  expr operator+ (expr a, expr b){
      //text ça te renvoie un bloc avec + dedans 
      //beside ça colle deux blocs pour en créer un nouveau
      return(beside(a,beside(text("+"),b)));
  }
  expr operator+ (double a, expr b){
      return text(std::to_string(a))+b;
  }
  expr operator+ (expr a, double b){
      return a+ text(std::to_string(b));
  }



  expr operator/ (expr a, expr b){
      return over(a,over(text(std::string(std::max(a->get_width(),b->get_width()),'-')),b));
  }
  expr operator/ (double a, expr b){
      return text(std::to_string(a))/b;
  } 
   expr operator/ (expr a, double b){
       return a/text(std::to_string(b));
   }

    expr operator==(expr a, expr b){
        return beside(a,beside(text("="),b));
  }

  expr operator==(expr a, double b){
        return beside(a,beside(text("="),text(std::to_string(b))));
  }
  expr operator==(double a, expr b){
      return beside(text(std::to_string(a)),beside(text("="),b));
  }


  
}
