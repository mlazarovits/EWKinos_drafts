#include "firstlook.h"
using namespace std;

void firstlook::firstlook(TString in_sample){
	sample = in_sample;
	if(sample == "WJetstoLNu17"){
		sample_ext = "/All_Bkg_2017/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
	}
	else if(sample == "TTWJets"){
		sample_ext = "TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8_Fall17.root";
	}
	else{
		cout << "error: dataset not accounted for yet" << endl;
		return;
	}
	chain->Add("/home/t3-ku/crogan/NTUPLES/StopNtuple"+sample_ext);
}

void firstlook::firstlook(TString in_sample, TString file){
	sample = in_sample;
	if(sample == "WJetsToLNu17"){
		TFileCollection* WJetstoLNu17 = new TFileCollection("WJetstoLNu17","WJetstoLNu17");
		WJetstoLNu17->Add("/home/t3-ku/mlazarov/CMSSW_10_1_4_patch1/src/red_NTUPLES/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17/*.root")
		chain->AddFileInfoList((TCollection*)WJetstoLNu17->GetList());
	}
	else if(sample == "TTWJetsToLNu17"){
		TFileCollection* TTWJetsToLNu17 = new TFileCollection("TTWJetsToLNu17","TTWJetsToLNu17");
		WJetstoLNu17->Add("/home/t3-ku/mlazarov/CMSSW_10_1_4_patch1/src/red_NTUPLES/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17/*.root")
		chain->AddFileInfoList((TCollection*)TTWJetsToLNu17->GetList());	
	}
	else{
		cout << "error: dataset not accounted for yet" << endl;
		return;
	}

}
  

   


void firstlook::InitBranches(){
	chain->SetBranchStatus("*",0); 
	chain->SetBranchStatus("MET",1); chain->SetBranchAddress("MET",&MET);
	chain->SetBranchStatus("weight",1); chain->SetBranchAddress("weight",&weight);
	chain->SetBranchStatus("MET_phi",1); chain->SetBranchAddress("MET_phi",&MET_phi);
	chain->SetBranchStatus("genMET",1); chain->SetBranchAddress("genMET",&genMET);
	chain->SetBranchStatus("genMET_phi",1);chain->SetBranchAddress("genMET_phi",&genMET_phi);
	chain->SetBranchStatus("Nele",1); chain->SetBranchAddress("Nele",&Nele);
	chain->SetBranchStatus("Nmu",1); chain->SetBranchAddress("Nmu",&Nmu);
	chain->SetBranchStatus("Nlep",1); chain->SetBranchAddress("Nlep",&Nlep);
	chain->SetBranchStatus("PT_lep",1); chain->SetBranchAddress("PT_lep",&PT_lep);
	chain->SetBranchStatus("Eta_lep",1); chain->SetBranchAddress("Eta_lep",&Eta_lep);
	chain->SetBranchStatus("Phi_lep",1); chain->SetBranchAddress("Phi_lep",&Phi_lep);
	chain->SetBranchStatus("M_lep",1); chain->SetBranchAddress("M_lep",&M_lep);
	chain->SetBranchStatus("Charge_lep",1); chain->SetBranchAddress("Charge_lep",&Charge_lep);
	chain->SetBranchStatus("PDGID_lep",1); chain->SetBranchAddress("PDGID_lep",&PDGID_lep);
	chain->SetBranchStatus("RelIso_lep",1); chain->SetBranchAddress("RelIso_lep",&RelIso_lep);
	chain->SetBranchStatus("MiniIso_lep",1); chain->SetBranchAddress("MiniIso_lep",&MiniIso_lep);
	chain->SetBranchStatus("ID_lep",1); chain->SetBranchAddress("ID_lep",&ID_lep);
	chain->SetBranchStatus("Index_lep",1); chain->SetBranchAddress("Index_lep",&Index_lep);
	chain->SetBranchStatus("genNele",1); chain->SetBranchAddress("genNele",&genNele);
	chain->SetBranchStatus("genNmu",1); chain->SetBranchAddress("genNmu",&genNmu);
	chain->SetBranchStatus("genNlep",1); chain->SetBranchAddress("genNlep",&genNlep);
	chain->SetBranchStatus("genPT_lep",1); chain->SetBranchAddress("genPT_lep",&genPT_lep);
	chain->SetBranchStatus("genEta_lep",1); chain->SetBranchAddress("genEta_lep",&genEta_lep);
	chain->SetBranchStatus("genPhi_lep",1); chain->SetBranchAddress("genPhi_lep",&genPhi_lep);
	chain->SetBranchStatus("genM_lep",1); chain->SetBranchAddress("genM_lep",&genM_lep);
	chain->SetBranchStatus("genCharge_lep",1); chain->SetBranchAddress("genCharge_lep",&genCharge_lep);
	chain->SetBranchStatus("genPDGID_lep",1); chain->SetBranchAddress("genPDGID_lep",&genPDGID_lep);
	chain->SetBranchStatus("genMomPDGID_lep",1); chain->SetBranchAddress("genMomPDGID_lep",&genMomPDGID_lep);
	chain->SetBranchStatus("genIndex_lep",1); chain->SetBranchAddress("genIndex_lep",&genIndex_lep);


}