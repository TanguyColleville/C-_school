#include <petriPool.hpp>

// To be done
namespace petri {
    // constructeur 
    Pool::Pool(const std::string& name, unsigned int nb_tokens):name(name),nb_tokens(nb_tokens){};
    
    // créer un shared pointeur sur un objet de Pool
    pool_ref make_pool(const std::string& name, unsigned int nb_tokens){
        return std::make_shared<Pool>(name, nb_tokens);
    }

    std::ostream& operator<<(std::ostream& os, pool_ref p){
            os<<"("<<p->name<<","<<p->nb_tokens<<")";
    return os;
    }

    bool operator<(pool_ref p, unsigned int required_number_of_tokens){
        if (p->nb_tokens < required_number_of_tokens){
            return true; 
        }
        return false;
    }


}