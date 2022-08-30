#include "QuadDecode_def.h" // Hardware quadrature encoder

QuadDecode<1> *apQDcd1; // Pointers to  correct instance for ISR
QuadDecode<2> *apQDcd2;

void ftm1_isr(void) { // hello
  apQDcd1->ftm_isr();
};

void ftm2_isr(void) {
  apQDcd2->ftm_isr();
};
