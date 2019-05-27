#ifndef EFFICIENCY_H
#define EFFICIENCY_H

#include <iostream>
//#include "AUX.h" //makeclass for stopntuple
//#include "TLorentzVector.h"
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

class efficiency
{
private:
	vector<TString> filter_names;
	TString draw_string="";
	TString sample ="";
	TChain* chain = new TChain("stopTreeMaker/AUX");

	float Nentries = -999;
	float Npass = -999;
	float Nfail = -999;
	float fail_eff = -999;
	float fail_sigma = -999;

	double Npass_met = -999;
	double Nfail_met = -999;
	double Nentries_met = -999;
	float met_eff = -999;
	float eff_uncert = -999;

	// int metInterval = 50; //10 bins of 50 GeV
	int metHigh = 1000;
	int metLow = 0;
	std::cout << "met: " << metLow << " GeV to " << metHigh << " GeV" << std::endl;

	vector<TGraphErrors*> gr;
	TMultiGraph* mg = new TMultiGraph();


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
	int metNBins = 10; //10 met bins
	int Nmet = metNBins; //number of metbins
	int NFilter = (int)filter_names.size(); //number of filters

	int metInterval = (metHigh - metLow)/metNBins;
	std::cout << metNBins << " bins with " << metInterval << " GeV each" << std::endl;

	float met_bins[metNBins+1]; //values of high/low met for cuts
	Float_t met_effs[metNBins]; //failed entries percentage
	Float_t eff_uncerts[metNBins];
	float met_plot[metNBins];

	Float_t NPass[NFilter][Nmet]; //number of passed events
	Float_t NFail[NFilter][Nmet]; //number of failed events
	Float_t NTot[Nmet]; //number of events in met_bin
	Float_t Neff[NFilter][Nmet];
	Float_t Neff_uncert[NFilter][Nmet];
	Float_t met_uncerts[Nmet];
	
	TCanvas* cv = new TCanvas("cv","cv",1000,600);

	efficiency();
	virtual ~efficiency(){ };
	void Initialize();
	void make_metbins();
	void counter();
  	void make_plot();

};
#endif



inline efficiency::Initialize(TString dataset){
	if(dataset == "dyJetsToLL"){
		chain->SetBranchAddress("met",&met,&b_met);
		chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
		chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
		chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
		chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
		chain->SetBranchAddress("ecalBadCalibFilter", &ecalBadCalibFilter, &b_ecalBadCalibFilter);
		chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
		chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
		chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
		chain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
		chain->SetBranchAddress("HBHEIsoNoiseFilter", &HBHEIsoNoiseFilter, &b_HBHEIsoNoiseFilter);
		chain->SetBranchAddress("BadChargedCandidateFilter", &BadChargedCandidateFilter, &b_BadChargedCandidateFilter);
		chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);



		filter_names.push_back("globalSuperTightHalo2016Filter");
		filter_names.push_back("goodVerticesFilter");
		filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
		filter_names.push_back("BadChargedCandidateFilter");
		filter_names.push_back("BadPFMuonFilter");
		filter_names.push_back("HBHENoiseFilter");
		filter_names.push_back("HBHEIsoNoiseFilter");
		filter_names.push_back("CSCTightHaloFilter");
		filter_names.push_back("METFilters");

		TFileCollection *dyJetsToLL= new TFileCollection("dyJetsToLL","dyJetsToLL");
		dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220245/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220311/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220337/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220403/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220428/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220454/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220520/0000/stopFlatNtuples_*");
		// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220546/0000/stopFlatNtuples_*");

		chain->AddFileInfoList((TCollection*)dyJetsToLL->GetList());
		sample = dyJetsToLL->GetName();
		std::cout << "sample: " << sample << std::endl;
	}



	else if(dataset == "TChiToWZ"){
		chain->SetBranchAddress("met",&met,&b_met);
		chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
		chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
		chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
		chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
		chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
		chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
		chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
		chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

		chain->SetBranchStatus("*",0);
		chain->SetBranchStatus("*Filter*",1);
		chain->SetBranchStatus("met",1);

		filter_names.push_back("goodVerticesFilter");
		filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
		filter_names.push_back("BadChargedCandidateFilter");
		filter_names.push_back("BadPFMuonFilter");
		filter_names.push_back("HBHENoiseIsoFilter");
		filter_names.push_back("CSCTightHaloFilter");
		filter_names.push_back("METFilters");

		//2016 dataset
		TFileCollection *TChiToWZ = new TFileCollection("TChiToWZ","TChiToWZ");
		TChiToWZ->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWZ_ZToLL_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWZ_ZToLL_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISpring16MiniAODv2/181220_184342/0000/stopFlatNtuples_*");
		TChiToWZ->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv2/181220_184216/0000/stopFlatNtuples_*");
		TChiToWZ->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWZ_ZToLL_mZMin-0p1_mLSP300to350_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWZ_ZToLL_mZMin-0p1_mLSP300to350_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv2/181220_184151/0000/stopFlatNtuples_*");
		std::cout << "finished adding files to file list" << std::endl;

		chain->AddFileInfoList((TCollection*)TChiToWZ->GetList());

		sample = TChiToWZ->GetName();
		std::cout << "sample: " << sample << std::endl;
	}
	else if(dataset == "TChiWH_HToGG"){
		chain->SetBranchAddress("met",&met,&b_met);
		chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
		chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
		chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
		chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
		chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
		chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
		chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
		chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

		chain->SetBranchStatus("*",0);
		chain->SetBranchStatus("*Filter*",1);
		chain->SetBranchStatus("met",1);
			chain->SetBranchStatus("evtWeight",1);

		filter_names.push_back("BadChargedCandidateFilter");
		filter_names.push_back("BadPFMuonFilter");
		filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
		filter_names.push_back("HBHENoiseIsoFilter");
		filter_names.push_back("ecalBadCalibFilter");
		filter_names.push_back("goodVerticesFilter");
		filter_names.push_back("globalSuperTightHalo2016Filter");
		filter_names.push_back("CSCTightHaloFilter");
		filter_names.push_back("METFilters");

		//2016 dataset
		TFileCollection *TChiWH_HToGG = new TFileCollection("TChiWH_HToGG","TChiWH_HToGG");
		TChiWH_HToGG->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWH_HToGG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWH_HToGG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISpring16MiniAODv2/181220_184408/0000/stopFlatNtuples_*");    
		std::cout << "finished adding files to file list" << std::endl;

		chain->AddFileInfoList((TCollection*)TChiWH_HToGG->GetList());
		sample = TChiWH_HToGG->GetName();
		std::cout << "sample: " << sample << std::endl;
	}
	else if(dataset == "WJetsToLNu"){
		chain->SetBranchAddress("met",&met,&b_met);
		chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
		chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
		chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
		chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
		chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
		chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
		chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
		chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

		chain->SetBranchStatus("*",0);
		chain->SetBranchStatus("*Filter*",1);
		chain->SetBranchStatus("met",1);
			chain->SetBranchStatus("evtWeight",1);

		filter_names.push_back("BadChargedCandidateFilter");
		filter_names.push_back("BadPFMuonFilter");
		filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
		filter_names.push_back("HBHENoiseIsoFilter");
		filter_names.push_back("ecalBadCalibFilter");
		filter_names.push_back("goodVerticesFilter");
		filter_names.push_back("globalSuperTightHalo2016Filter");
		filter_names.push_back("CSCTightHaloFilter");
		filter_names.push_back("METFilters");

		//2016 dataset
		TFileCollection *WJetsToLNu = new TFileCollection("WJetsToLNu","WJetsToLNu");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020824/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020702/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020845/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020721/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020740/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020800/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/181116_210752/0000/stopFlatNtuples_*");
		WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_extWJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/181219_234206/0000/stopFlatNtuples_*");

		std::cout << "finished adding files to file list" << std::endl;

		chain->AddFileInfoList((TCollection*)WJetsToLNu->GetList());
		sample = WJetsToLNu->GetName();
		std::cout << "sample: " << sample << std::endl;
	}
	else if(dataset == "TTJets"){
		chain->SetBranchAddress("met",&met,&b_met);
		chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
		chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
		chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
		chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
		chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
		chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
		chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
		chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

		chain->SetBranchStatus("*",0);
		chain->SetBranchStatus("*Filter*",1);
		chain->SetBranchStatus("met",1);
			chain->SetBranchStatus("evtWeight",1);

		filter_names.push_back("BadChargedCandidateFilter");
		filter_names.push_back("BadPFMuonFilter");
		filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
		filter_names.push_back("HBHENoiseIsoFilter");
		filter_names.push_back("ecalBadCalibFilter");
		filter_names.push_back("goodVerticesFilter");
		filter_names.push_back("globalSuperTightHalo2016Filter");
		filter_names.push_back("CSCTightHaloFilter");
		filter_names.push_back("METFilters");

		//2016 dataset
		TFileCollection *TTJets = new TFileCollection("TTJets","TTJets");
		TTJets->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/crogan/TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8/crab_TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8RunIISummer16MiniAODv2/181220_212122/0000/stopFlatNtuples_*");    
		std::cout << "finished adding files to file list" << std::endl;

		chain->AddFileInfoList((TCollection*)TTJets->GetList());
		chain->SetBranchStatus("*",0);
		chain->SetBranchStatus("*Filter*",1);
		chain->SetBranchStatus("met",1);
		chain->SetBranchStatus("evtWeight",1);
		sample = TTJets->GetName();
		std::cout << "sample: " << sample << std::endl;
	}
	else{
		std::cout << "error: not a valid dataset" << std::endl;
		return;
	}
}

inline efficiency::make_metbins(){
	for(int i = 0; i < metNBins+1; i++){
		met_bins[i] = (Float_t)i*metInterval;
		std::cout << "met bins: " << met_bins[i] << std::endl;
	}
}

inline efficiency::counter(){
	for(int imet = 0; imet < Nmet; imet++){
		int met_evt = chain->GetEntry(imet);
		for(int j = 0; j < metNBins; j++){
	  		if(met < met_bins[j+1]){
	    		NTot[j]+= 1.*evtWeight;
	    		met_uncerts[j] = metInterval/2;
	    		met_plot[j] = (met_bins[j+1] + met_bins[j])/2;
	    		continue;
	  		}      
	  		for(int k = 0; k < NFilter; k++){ 
	    		if(filter_names[k]==1){ //pass filter
	      			NPass[k][j] += 1.;
	      		}	
	    		if(filter_names[k]==0){ //fail filter
	      			NFail[k][j] += 1.;
	    		}
	    	}
	  	}
	}
	for(int j = 0; j < metNBins; j++){
		for(int k = 0; k < NFilter; k++){
		Neff[k][j] = NFail[k][j]/NTot[j];
		Neff_uncert[k][j] = sqrt((Neff[k][j]*(1-Neff[k][j]))/NTot[j])*100;

			if(abs(Neff[k][j]) > 10){
				std::cout << filter_names[k] << std::endl;
				std::cout << "met_bin: " << met_bins[j] << std::endl;
				std::cout << "total number of events in met bin: " << NTot[j] << std::endl;
				std::cout << "failed events: " << NFail[k][j] << std::endl;
				std::cout << "fail efficiency: " << Neff[k][j] << std::endl;
				std::cout << "error: " << Neff_uncert[k][j] << std::endl;
				std::cout << "" << std::endl;
			}
		}
	}
}

inline efficiency::make_plot(){
	for(int i = 0; i < NFilter; i++){
		gr.push_back(new TGraphErrors(metNBins,met_plot,Neff[i],met_uncerts,Neff_uncert[i]));
		// gr[i]->Print();
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
		mg->Add(gr[i]);
		std::cout << "added TGraphErrors to vector" << std::endl;
	}	
	// cv->SetTopMargin(0.09);
	cv->SetGrid();
	mg->Draw("ap");
	mg->SetTitle(sample+" Filter Efficiencies; met (GeV); fail efficiency %");

	TLegend* leg2 = new TLegend(0.1,0.4,0.43,0.7);
	for(int i = 0; i < filter_names.size(); i++){
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
}	


