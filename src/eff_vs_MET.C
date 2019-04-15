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
#include <cmath>
using namespace std;


void filters_vs_MET(TString dataset){
  vector<TString> filter_names;
  TString draw_string="";
  TString sample ="";
  TChain* chain = new TChain("stopTreeMaker/AUX");
  float Nentries;
  float Npass;
  float Nfail;










  cout << "finished initializing" << endl;


  
  //filter_names.push_back("noBadMuonsFilter");
  //filter_names.push_back("badMuonsFilter");
  //filter_names.push_back("duplicateMuonsFilter");

  

  //2017 dataset
  if(dataset == "dyJetsToLL"){
    TBranch *b_CSCTightHaloFilter;
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

    Float_t         met_f;
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



    chain->SetBranchAddress("met",&met_f,&b_met);
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

    chain->SetBranchStatus("*",0);
    chain->SetBranchStatus("*Filter*",1);
    chain->SetBranchStatus("met",1);



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
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220311/0000/stopFlatNtuples_*");
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220337/0000/stopFlatNtuples_*");
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220403/0000/stopFlatNtuples_*");
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220428/0000/stopFlatNtuples_*");
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220454/0000/stopFlatNtuples_*");
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220520/0000/stopFlatNtuples_*");
    dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220546/0000/stopFlatNtuples_*");

    chain->AddFileInfoList((TCollection*)dyJetsToLL->GetList());
    sample = dyJetsToLL->GetName();
    cout << "sample: " << sample << endl;
  }



  else if(dataset == "TChiToWZ"){

    TBranch *b_CSCTightHaloFilter;
    TBranch        *b_METFilters;   //!
    TBranch        *b_globalSuperTightHalo2016Filter;   //!
    TBranch        *b_goodVerticesFilter;   //!
    TBranch        *b_HBHENoiseIsoFilter;   //!
    TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
    TBranch        *b_BadPFMuonFilter;   //!
    TBranch        *b_met;   //!

    Float_t         met_f;
    Int_t           METFilters;
    Int_t           CSCTightHaloFilter;
    Int_t           globalSuperTightHalo2016Filter;
    Int_t           goodVerticesFilter;
    Int_t           HBHENoiseIsoFilter;
    Int_t           EcalDeadCellTriggerPrimitiveFilter;
    UInt_t          BadPFMuonFilter;



    chain->SetBranchAddress("met",&met_f,&b_met);
    chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
    chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
    chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
    chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
    chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
    chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
    chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);

    chain->SetBranchStatus("*",0);
    chain->SetBranchStatus("*Filter*",1);
    chain->SetBranchStatus("met",1);




    filter_names.push_back("globalSuperTightHalo2016Filter");
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
    cout << "finished adding files to file list" << endl;

    chain->AddFileInfoList((TCollection*)TChiToWZ->GetList());
    sample = TChiToWZ->GetName();
    cout << "sample: " << sample << endl;
  }
  else{
    cout << "error: not a valid dataset" << endl;
    return;
  }
  

  
  cout << "finished adding files to tchain" << endl;
  Nentries = (float)chain->GetEntries();
  TString pass_str = filter_names[0] + "== 0";
  TString fail_str = filter_names[0] + "== 1";
  Npass = (float)chain->GetEntries(pass_str);
  Nfail = (float)chain->GetEntries(fail_str);
  float Npass_met;
  float Nfail_met;
  if(Npass + Nfail != Nentries){
    cout << "error: total entries do not add up" << endl;
    return;
  }


  float fail_eff = (Nfail/Nentries)*100;
  float fail_sigma = sqrt(Nentries*fail_eff*(1-fail_eff))*100;
  cout << "fail efficiency: " << fail_eff << "+/- " << fail_sigma << endl;

  vector<float> met_bins; //empty bins to be filled with met values
  int metNBins = 10; //10 met bins
  int metInterval = 50; //10 bins of 50 GeV
  vector<float> met_effs; //failed entries percentage
  vector<float> eff_uncerts;
  vector<float> met_uncerts;
  vector<TGraphErrors*> gr;
  TMultiGraph* mg = new TMultiGraph();

  for(int i = 0; i < metNBins; i++){
    met_bins.push_back(i*metInterval);
  }




  for(int i = 0; i < filter_names.size(); i++){
    for(int j = 0; j < metNBins-1; j++){
      TString met_cut = Form("met > %f && met < %f",met_bins[j],met_bins[j+1]);
      TString fail_cut = filter_names[i] + "== 0 && " + met_cut; 
      TString pass_cut = filter_names[i] + "== 1 && " + met_cut;
      
      float Nentries_met = (float)chain->GetEntries(met_cut);
      Npass_met = (float)chain->GetEntries(pass_cut);
      Nfail_met = (float)chain->GetEntries(fail_cut);
      if(Npass_met + Nfail_met != Nentries_met){
        cout << "error: met entries do not add up" << endl;
        return;
      }

      float met_eff = (Nfail_met/Nentries_met)*100;
      float eff_uncert = sqrt(met_eff*(1-met_eff)/Nentries_met)*100;

      met_effs.push_back(met_eff);
      eff_uncerts.push_back(eff_uncert);
      met_uncerts.push_back(0);
    //check met_effs, met_uncerts and met_bins-1 all have same length
    }
    cout << "met bins" << met_bins.size() << endl;
    cout << "met_effs" << met_effs.size() << endl;
    cout << "eff_uncerts" << eff_uncerts.size() << endl;
    gr.push_back(new TGraphErrors(metNBins,met_bins,met_effs,met_uncerts,eff_uncerts));

    mg->Add(gr[i]);

  }

  TCanvas* cv = new TCanvas("cv","cv",800,600);
  cv->SetTopMargin(0.09);
  cv->SetGrid();
  mg->Draw("ap");

  TLegend* leg1,*leg2;

  leg2 = new TLegend(0.2,0.69,0.475,0.88);
  for(int i = 0; i < filter_names.size(); i++){
    leg2->AddEntry(gr[i],filter_names[i].c_str());
  }
  leg2->SetTextSize(0.033);
  leg2->Draw("same");

  cv->Update();



  //CMS Mark
  TLatex mark;
  mark.SetNDC(true);

  double fontScale = 6.5/8;

  mark.SetTextAlign(11);
  mark.SetTextSize(0.042 * fontScale * 1.25);
  mark.SetTextFont(61);
  mark.DrawLatex(gPad->GetLeftMargin()/*+0.05*/, 1 - (gPad->GetTopMargin() - 0.017), "CMS");
  mark.SetTextSize(0.042 * fontScale);
  mark.SetTextFont(52);
  mark.DrawLatex(gPad->GetLeftMargin()+0.095/*+0.14*/, 1 - (gPad->GetTopMargin() - 0.017), "Preliminary");
  //mark.SetTextFont(42);
  //mark.SetTextAlign(31);
  //mark.DrawLatex(1 - gPad->GetRightMargin(), 1 - (gPad->GetTopMargin() - 0.017), "35.9 fb^{-1} (13 TeV)");

  cv->Update();

  cv->SaveAs("filters_eff.pdf");

  cv->Close();



}


