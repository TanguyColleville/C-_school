# 1 "main.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 383 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "main.cpp" 2


# 1 "./definitions.cpp" 1















struct Complex {
  double re, im;
};

# 3 "main.cpp" 2
# 1 "./functions.cpp" 1


double to_rad(double angle) {
  return angle * 3.14 / 180.0;
}

# 4 "main.cpp" 2

int main() {

  double angle1 = 2*3.14;
  double angle2 = to_rad(90);
  return 0;
}

