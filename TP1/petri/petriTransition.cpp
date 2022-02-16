#include <petriTransition.hpp>

// To be done
namespace petri {
    bool Transition::is_activable() const{
    for(auto& elem : inputs){
        // elem c'est un pool et un nombre de token requis 
        if(std::get<0>(elem)->nb_tokens  <  std::get<1>(elem)){
            return false; 
        }
    }
    return true;
    }

    void Transition::activate(){
        for(auto& elem : inputs){
            std::get<0>(elem)->nb_tokens-=std::get<1>(elem);
        }
        for(auto& elem: outputs){
            std::get<0>(elem)->nb_tokens+=std::get<1>(elem);
        }
    }
    Transition::operator bool() const {
        return this->is_activable();
    }


    void Transition::operator() (){
            this->activate();
    }
    
    
    std::ostream& operator<<(std::ostream& os, const Transition& t){
        os<<"{";
        for(auto& elem : t.inputs){
            os<<std::get<0>(elem)<<"/"<<std::get<1>(elem)<<" ";
        }
        os<<"-->"<<t.name<<"-->";
        for(auto& elem: t.outputs){
            os<<"{"<<std::get<0>(elem)<<"/"<<std::get<1>(elem)<<" ";
        }
        os<<"}";

    return os;
    }


}