#pragma once

#include <iostream>
#include <memory>


namespace blk {

  class Block;
  using expr = std::shared_ptr<const Block>;
  // on dit qu'un pointeur shared sur un block c'est expr

  std::ostream& operator<<(std::ostream& os, expr e);
  
  class Block {
  private:
    // les attributs 
    int width;// dim en largueur du tableau
    int height; // dim en hauteur du tableau 
    int ref_width;// le x de l'origine dans le tableau de dim (width,height)
    int ref_height;// le y  de l'origine dans le tableau de dim(width,height)

    // Returns the lowest line number which is in the block.
    int min_line() const;

    // Returns 1 + the highest line number which is in the block.
    int max_line() const;

  public:
    // Prints any line. If the line is outside the block, it prints a
    // range of spaces. Otherwise, it calls print_inbounds_line to
    // print the block content at that line. We declare this method
    // public for now, but this will have to be reconsider later, in
    // the "better design" part of the labwork.
    void print_line(std::ostream& os, int line) const;
  private:

    // This will call the private min_line and max_line methods, this
    // is why it has to be a friend of the class.
    friend std::ostream& operator<<(std::ostream& os, expr block);
    
  public:
// constructeur 
    Block(int width, 
	  int height,
	  int ref_width,
	  int ref_height);
    virtual ~Block();

    // This prints line number line, if line is in [min_line(),
    // max_line()[.  Do not implement this method in the blkBlock.cpp
    // file, it is a pure virtual. The inherited class will have to
    // implement the method, defining their own way to print a line.
    virtual void print_inbounds_line(std::ostream& os, int line) const = 0;// égale 0 c'est pour
    //dire que c'est une fonction abstraite on va juste la re-définir dans chaque classe fille.
// les ascesseurs 
    int get_width()      const;
    int get_height()     const;
    int get_ref_width()  const;
    int get_ref_height() const;
  };
}
