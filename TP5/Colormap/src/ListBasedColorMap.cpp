
// Nécessaire pour importer la fonction assert().
#include <cassert>
#include <list>
 

// On a besoin des déclarations de ListBasedColorMap pour définir ses méthodes
#include "ListBasedColorMap.hpp"

namespace colormap {

	// Constructeur
	ListBasedColorMap::ListBasedColorMap() {}

	void ListBasedColorMap::clear() {
		colors_.clear();
	}

	void ListBasedColorMap::add(const ListBasedColorMap::color_type& color) {
		colors_.push_back(color);
	}

	// Renvoie l'indice de la couleur passée en argument.
    // Lance une exception MissingColor si la couleur n'est pas dans la table.
	ListBasedColorMap::index_type ListBasedColorMap::operator()(const ListBasedColorMap::color_type& color) const {
		for(auto ptr=colors_.begin(); ptr!= colors_.end();++ptr){
			if(*ptr==color){
				return std::distance(colors_.begin(),ptr); 
			}
		}
		throw "Not in map";// if not in map throw exception 
	}

	// Renvoie la couleur associée à un indice
	const ListBasedColorMap::color_type& ListBasedColorMap::operator()(ListBasedColorMap::index_type index) const {
		int i = 0;
		for(auto& elem : colors_){
			if(i++ ==index){
				return elem;
			} 

		}
	}
};
