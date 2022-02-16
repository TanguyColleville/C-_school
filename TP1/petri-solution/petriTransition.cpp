#include <petriTransition.hpp>


bool petri::Transition::is_activable() const {
  for(auto& s : inputs)
    if(s.first < s.second)
      return false;
  return true;
}

petri::Transition::operator bool () const {
  return is_activable();
}

void petri::Transition::activate() {
  for(auto& s : inputs)  s.first->nb_tokens -= s.second;
  for(auto& s : outputs) s.first->nb_tokens += s.second;
}

void petri::Transition::operator()() {
  activate();
}

std::ostream& petri::operator<<(std::ostream& os, const petri::Transition& t) {
  os << '{';
  for(auto& s : t.inputs) os << s.first << '/' << s.second << ' ';
  os << "--> " << t.name << " -->";
  for(auto& s : t.outputs) os << ' ' << s.first << '/' << s.second;
  os << '}';
  return os;
}
