#include "TDRstyle.h"
#include "AUX.h"
class eff_maker{
public:
	vector< parentSampleClass * > eff_vector_loader( string treeSubDir );
	bool global_cuts( ReducedBase * base );
	void make_plots( string g_Path, vector<string> g_FileVec, string treeName,  TFile * outfile, string treeSubDir );
  	void make_plots( string g_Path, string g_FileName, string treeName, TFile * outfile, string treeSubDir );
  	void counter(AUX* aux);

  	std::vector<std::vector<float>> NPass;
	std::vector<std::vector<float>> NFail;
	std::vector<std::vector<float>> Neff;
	std::vector<std::vector<float>> Neff_uncert;
};

void make_plots( string g_Path, vector<string> g_FileVec, string treeName,  TFile * outfile, string treeSubDir ){
	setTDRStyle();
	const auto veffclasses = eff_vector_loader( treeSubDir );
	int Nsample = g_FileVec.size();

	TChain* chain_tree = new TChain("stopTreeMaker/AUX");
	for( int s = 0;s < Nsample; s++){ chain_tree->Add( (g_Path + g_FileVec[s]).c_str() )};
	AUX* aux = new AUX( chain );
	
	int Nentry = aux->fChain->GetEntries();
	for(int entry = 0; entry < Nentry; entry++){

	}
}
inline void eff_maker::counter(AUX* aux){
	// AUX* aux = new AUX(chain);
	// cout << "counter" << endl;
	int NFilter = (int)filter_names.size();
	// cout << "NFilter " << NFilter << endl;
	NPass.resize(NFilter);
	NFail.resize(NFilter);
	Neff.resize(NFilter);
	Neff_uncert.resize(NFilter);
	int tot_entries;

	if(debug == true){
		tot_entries = 10;
	}
	else{
		tot_entries = (int)chain->GetEntries();
	}
	
	cout << "total entries: " << tot_entries << endl;

	for(int j = 0; j < metNBins; j++){
		met_uncerts.push_back( (float)metInterval/2 );
	    // cout << "point b" << endl;
	    met_plot.push_back( (float)((met_bins[j+1] + met_bins[j])/2) );
	    NTot.push_back( 0.0 );
	}

	for(int k = 0; k < NFilter; k++){
		for(int j = 0; j < metNBins; j++){
			NPass[k].push_back(0.0);
			NFail[k].push_back(0.0);
			Neff[k].push_back(0.0);
			Neff_uncert[k].push_back(0.0);
		}
	}

	for(int imet = 0; imet < tot_entries; imet++){
		int met_evt = chain->GetEntry(imet);


		if(imet % 10000 == 0){
			fprintf(stdout, "\r Counted events: %8d of %8d ",imet, tot_entries);
		}
		fflush(stdout);
		// cout << "entry #: " << imet << endl;
		for(int j = 0; j < metNBins; j++){
	  		if(met > 0 && met < 1000 && met < met_bins[j+1]){
	    
	    		NTot[j] = NTot[j] + (float)1.*evtWeight; //total number of events in this met bin
	    		// cout << "met bin: " << met_bins[j] << " to " << met_bins[j+1] << endl;
	    		for(int k = 0; k < NFilter; k++){
	    			if(filters[k] == 1){
	    				NPass[k][j] = NPass[k][j] + (float)1.*evtWeight;
	    			}
	    			else if(filters[k] == 0){
	    				NFail[k][j] = NFail[k][j] + (float)1.*evtWeight;
	    			}
	    			else{
	    				cout << filter_names[k] << ": " << filters[k] << endl;
	    			}
	    		}
	    		// cout << "BadPFMuonFilter " << BadPFMuonFilter << endl;
	    		// cout << "METFilters " << METFilters << endl;
	    		// cout << "globalSuperTightHalo2016Filter " << globalSuperTightHalo2016Filter << endl;
	    		// cout << "\n" << endl;
	    		continue;
	  		}
	  	}
	  	filters.clear();
	}
	// cout << "\n efficiency calculation loop" << endl;
	for(int k = 0; k < NFilter; k++){
		for(int j = 0; j < metNBins; j++){
		// Neff[k][j] = NFail[k][j]/NTot[j];
		// Neff_uncert[k][j] = sqrt((Neff[k][j]*(1-Neff[k][j]))/NTot[j])*100;
		// Neff[k].push_back( (float)NFail[k][j]/NTot[j] );
		// Neff_uncert[k].push_back( (float)(sqrt((Neff[k][j]*(1-Neff[k][j]))/NTot[j])*100) ); 
			// cout << "point 0" << endl;
			// Neff.push_back(0.0);
			// Neff_uncert.push_back(0.0);
			Neff[k][j] = (float)NFail[k][j]/NTot[j];
			// cout << "point a" << endl;
			Neff_uncert[k][j] = (float)(sqrt((Neff[k][j]*(1-Neff[k][j]))/NTot[j])*100);
			// cout << "point b" << endl;

			// if(abs(Neff[k][j]) > 10){
			// // cout << "point c" << endl;

			// 	std::cout << filter_names[k] << std::endl;
			// 	std::cout << "met_bin: " << met_bins[j] << std::endl;
			// 	std::cout << "total number of events in met bin: " << NTot[j] << std::endl;
			// 	std::cout << "failed events: " << NFail[k][j] << std::endl;
			// 	std::cout << "fail efficiency: " << Neff[k][j] << std::endl;
			// 	std::cout << "error: " << Neff_uncert[k][j] << std::endl;
			// 	std::cout << "\n" << std::endl;
			// }
		}
	}
}