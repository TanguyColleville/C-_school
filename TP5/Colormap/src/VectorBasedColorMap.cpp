
// Nécessaire pour importer la fonction assert().
#include <cassert>
#include <vector>

// On a besoin des déclarations de VectorBasedColorMap pour définir ses méthodes
#include "VectorBasedColorMap.hpp"



namespace colormap {

	// Constructeur
	VectorBasedColorMap::VectorBasedColorMap(int n):n(n){
    }

	void VectorBasedColorMap::clear() {
		colors_.clear();
	}

	void VectorBasedColorMap::add(const VectorBasedColorMap::color_type& color) {
		colors_.push_back(color);
	}

	// Renvoie l'indice de la couleur passée en argument.
    // Lance une exception MissingColor si la couleur n'est pas dans la table.
	VectorBasedColorMap::index_type VectorBasedColorMap::operator()(const VectorBasedColorMap::color_type& color) const {
		for(auto ptr=colors_.begin(); ptr!= colors_.end();++ptr){
			if(*ptr==color){
				return std::distance(colors_.begin(),ptr); 
			}
		}
		throw color;// if not in map throw exception 
	}

	// Renvoie la couleur associée à un indice
	const VectorBasedColorMap::color_type& VectorBasedColorMap::operator()(VectorBasedColorMap::index_type index) const {
		// int i = 0;
		// for(auto& elem : colors_){
		// 	if(i++ ==index){
		// 		return elem;
		// 	} 

		// }
		return colors_[index];
	}
};
