#include "efficiency.h"

void eff_vs_met(TString dataset){
	efficiency eff;

	eff.Initialize(dataset);
	eff.make_metbins();
	eff.counter();
	eff.make_plot();

}