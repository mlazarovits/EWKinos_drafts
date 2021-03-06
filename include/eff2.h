#ifndef EFFICIENCY_H
#define EFFICIENCY_H

#include <iostream> 
#include "AUX.h" //makeclass for stopntuple
#include "TLorentzVector.h" 
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TCut.h"
#include "TPad.h"
#include "TBranch.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TFileCollection.h"
#include "TLatex.h"
#include "TVector.h"
#include <string>
#include <cmath>

using namespace std;

class eff2
{
private:
	
	

	TChain* chain;

	bool debug;

	float Nentries;
	float Npass;
	float Nfail;
	float fail_eff;
	float fail_sigma;

	double Npass_met;
	double Nfail_met;
	double Nentries_met;
	float met_eff;
	float eff_uncert;

	int metNBins; //10 met bins;
	
	int metHigh;
	int metLow;
	int metInterval;

	// float met_bins[metNBins+1]; //values of high/low met for cuts
	// Float_t met_effs[metNBins]; //failed entries percentage
	// Float_t eff_uncerts[metNBins];
	// float met_plot[metNBins];

	std::vector<float> met_bins;
	std::vector<float> met_effs;
	std::vector<float> eff_uncerts;
	std::vector<float> met_plot;
	
	// Float_t NPass[NFilter][metNBins]; //number of passed events
	// Float_t NFail[NFilter][metNBins]; //number of failed events
	// Float_t Neff[NFilter][metNBins];
	// Float_t Neff_uncert[NFilter][metNBins];

	std::vector<std::vector<float>> NPass;
	std::vector<std::vector<float>> NFail;
	std::vector<std::vector<float>> Neff;
	std::vector<std::vector<float>> Neff_uncert;

	// Float_t NTot[metNBins]; //number of events in met_bin
	// Float_t met_uncerts[metNBins];

	std::vector<float> NTot;
	std::vector<float> met_uncerts;



  	Float_t         met;
    Int_t           METFilters;
    Int_t           CSCTightHaloFilter;
    Int_t           globalSuperTightHalo2016Filter;
    Int_t           goodVerticesFilter;
    Int_t           ecalBadCalibFilter;
    Int_t           HBHENoiseIsoFilter;
    Int_t           EcalDeadCellTriggerPrimitiveFilter;
    UInt_t          BadChargedCandidateFilter;
    UInt_t          BadPFMuonFilter;
    UInt_t          HBHENoiseFilter;
    UInt_t          HBHEIsoNoiseFilter;
    Float_t         evtWeight;

    TBranch        *b_CSCTightHaloFilter;
    TBranch        *b_METFilters;   //!
    TBranch        *b_globalSuperTightHalo2016Filter;   //!
    TBranch        *b_goodVerticesFilter;   //!
    TBranch        *b_ecalBadCalibFilter;   //!
    TBranch        *b_HBHENoiseIsoFilter;   //!
    TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
    TBranch        *b_BadChargedCandidateFilter;   //!
    TBranch        *b_BadPFMuonFilter;   //!
    TBranch        *b_HBHENoiseFilter;   //!
    TBranch        *b_HBHEIsoNoiseFilter; 
    TBranch        *b_met;   //!
    TBranch        *b_evtWeight;


protected:


public:
	
    TCanvas* cv;

	efficiency();
	virtual ~efficiency(){ };
	void Initialize(TString dataset);
	void make_metbins();
	void counter();
  	void make_plot();

};
#endif



inline efficiency::efficiency(){
	chain = new TChain("stopTreeMaker/AUX");
	cv = new TCanvas("cv","cv",1000,600);
	metNBins = 10; //10 met bins;
	
	metHigh = 1000;
	metLow = 0;
	metInterval = (metHigh - metLow)/metNBins;

	debug = false;

	// Nentries = -999;
	// float Npass = -999;
	// float Nfail = -999;
	// float fail_eff = -999;
	// float fail_sigma = -999;

	// double Npass_met = -999;
	// double Nfail_met = -999;
	// double Nentries_met = -999;
	// float met_eff = -999;
	// float eff_uncert = -999;

}

inline void efficiency::make_metbins(){
	std::cout << "met: " << metLow << " GeV to " << metHigh << " GeV" << std::endl;
	std::cout << metNBins << " bins with " << metInterval << " GeV each" << std::endl;
	for(int i = 0; i < metNBins+1; i++){
		// met_bins[i] = (Float_t)i*metInterval;
		met_bins.push_back( (float)i*metInterval );
		// std::cout << "met bins: " << met_bins[i] << std::endl;
	}
}

inline void efficiency::counter(){
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
		filters.push_back(globalSuperTightHalo2016Filter);
		filters.push_back(goodVerticesFilter);
		filters.push_back(EcalDeadCellTriggerPrimitiveFilter);
		filters.push_back(BadPFMuonFilter);
		filters.push_back(CSCTightHaloFilter);

		if(sample == "dyJetsToLL"){
			filters.push_back(METFilters);
			filters.push_back(BadChargedCandidateFilter);
			filters.push_back(HBHENoiseFilter);
			filters.push_back(HBHEIsoNoiseFilter);
		}

		if(sample == "TChiToWZ"){
			filters.push_back(HBHENoiseIsoFilter);
		}
		if(sample == "TChiWH_HToGG"){
			filters.push_back(HBHENoiseIsoFilter);		
			filters.push_back(METFilters);
		}

		if(sample == "WJetsToLNu"){
			filters.push_back(HBHENoiseIsoFilter);
			filters.push_back(METFilters);
		}

		if(sample == "TTJets"){
			filters.push_back(HBHENoiseIsoFilter);
			filters.push_back(METFilters);
		}




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

inline void efficiency::make_plot(){
	vector<TGraphErrors*> gr;
	TMultiGraph* mg = new TMultiGraph(sample,sample);	
	// cout << "make_plot" << endl;
	int gr_nfilter = (int)filter_names.size();
	Float_t gr_eff[gr_nfilter][metNBins];
	Float_t gr_effuncert[gr_nfilter][metNBins];
	Float_t gr_met[metNBins];
	Float_t gr_metuncert[metNBins];

	for(int j = 0; j < gr_nfilter; j++){
		// cout << filter_names[j] << endl;
		// cout << "total number of events: " << NTot[j] << endl;
		for(int i = 0; i < metNBins; i++){
			gr_eff[j][i] = Neff[j][i];
			gr_effuncert[j][i] = Neff_uncert[j][i];
			
			// cout << "# passed: " << NPass[j][i] << "; # failed: " << NFail[j][i] << " in met bin " << met_bins[i] << " to " << met_bins[i+1] << endl;

		}
	}

	for(int i = 0; i < metNBins; i++){
		gr_met[i] = met_plot[i];
		gr_metuncert[i] = met_uncerts[i];
	}
	for(int i = 0; i < (int)filter_names.size(); i++){
		gr.push_back(new TGraphErrors(metNBins,gr_met,gr_eff[i],gr_metuncert,gr_effuncert[i]));

		// cout << "pushback tgraph" << endl;
		// cout << filter_names[i] << endl;


		// gr[i]->Print();
		// cout << "\n" << endl;
		
		if(i/3 == 0){
			gr[i]->SetMarkerStyle(24);
		} 
		else if(i/3 == 1){
			gr[i]->SetMarkerStyle(25);
		}
		else{
			gr[i]->SetMarkerStyle(26);
		}
		if(i%3 == 0){ 
			gr[i]->SetMarkerColor(kRed-7);
			gr[i]->SetLineColor(kRed-7);
		}
		if(i%3 == 1){ 
			gr[i]->SetMarkerColor(kGreen-7);
			gr[i]->SetLineColor(kGreen-7);
		}
		if(i%3 == 2){
			gr[i]->SetMarkerColor(kBlue-7);
			gr[i]->SetLineColor(kBlue-7);
		}
		gr[i]->SetMarkerSize(2);
		gr[i]->SetLineWidth(2);
		gr[i]->SetFillStyle(0);
		gr[i]->SetFillColor(0);
		// cout << "formatting" << endl;
		mg->Add(gr[i]);
		// cout << "added TGraphErrors to multigraph" << endl;
	}	
	// cv->SetTopMargin(0.09);
	cv->SetGrid();
	mg->Draw("AP");
	mg->SetTitle(sample+" Filter Efficiencies; met (GeV); fail efficiency %");
	mg->GetYaxis()->SetLimits(0.0,0.15);

	TLegend* leg2 = new TLegend(0.1,0.6,0.43,0.9);
	for(int i = 0; i < (int)filter_names.size(); i++){
	// TString tmpstr = Form(gr[i],filter_names[i])
		leg2->AddEntry(gr[i],filter_names[i].Data());
	}
	// leg2->SetTextSize(0.033);
	leg2->SetFillColor(0);
	leg2->SetFillStyle(0); //transparent
	leg2->Draw("same");

	cv->Update();

	//CMS Mark
	TLatex l;
	// l.SetTextFont(132);
	l.SetNDC();
	l.SetTextSize(0.035);
	l.SetTextFont(42);
	l.SetTextSize(0.04);
	l.SetTextFont(61);
	l.DrawLatex(0.11,0.905,"CMS");
	l.SetTextFont(52);
	l.DrawLatex(0.165,0.905,"Preliminary");
	cv->Update();

	cv->SaveAs("plots/"+sample+"_filters_eff.pdf");

	TFile* file = new TFile("/home/t3-ku/mlazarov/CMSSW_10_1_4_patch1/src/EWKinos_drafts/output/eff_plot.root","RECREATE");
	cv->Write();
	mg->Write();
}	

inline void efficiency::Initialize(TString dataset){
	// cout << "Initialize" << endl;
	
	
}

