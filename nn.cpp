#include <cmath>
#include <iostream>

using namespace std;

double getRandom() { return ((double)rand() / RAND_MAX); }

void print(int round, double i1, double w1, double i2, double w2, double act,
           double out, double delta, double err) {
  printf("round: %d\t", round);
  printf("i1: %lf\t", i1);
  printf("w1: %lf\t", w1);
  printf("i2: %lf\t", i2);
  printf("w2: %lf\t", w2);
  printf("act: %lf\t", act);
  printf("out: %lf\t", out);
  printf("delta: %lf\t", delta);
  printf("err: %lf\t", err);
  printf("\n");
}

double getActual(double a, double b) { return 3 * a + 4 * b; }

int main() {
  srand(time(nullptr));
  double a = .01;
  double w1 = getRandom();
  double w2 = getRandom();
  for (int i = 0; i < 20000; ++i) {
    double i1 = getRandom();
    double i2 = getRandom();
    double act = getActual(i1, i2);
    double out = i1 * w1 + i2 * w2; // forward pass
    double delta = out - act;
    double err = pow(delta, 2) / 2;
    w1 = w1 - a * i1 * delta;
    w2 = w2 - a * i2 * delta;
    if (i % 500 == 0) {
      print(i, i1, w1, i2, w2, act, out, delta, err);
    }
  }
}