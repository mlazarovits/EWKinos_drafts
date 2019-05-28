#include "/home/t3-ku/mlazarov/CMSSW_10_1_4_patch1/src/EWKinos_drafts/include/efficiency.h"

void eff_vs_met2(TString dataset){
	efficiency eff;

	eff.Initialize(dataset);
	eff.make_metbins();
	eff.counter();
	eff.make_plot();

}