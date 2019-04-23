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


void eff_vs_MET(TString dataset){
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

  int metNBins = 10; //10 met bins
  // int metInterval = 50; //10 bins of 50 GeV
  int metHigh = 1000;
  int metLow = 0;
  int metInterval = (metHigh - metLow)/metNBins;
  cout << "met: " << metLow << " GeV to " << metHigh << " GeV" << endl;
  cout << metNBins << " bins with " << metInterval << " GeV each" << endl;

  float met_bins[metNBins+1]; //values of high/low met for cuts
  Float_t met_effs[metNBins]; //failed entries percentage
  Float_t eff_uncerts[metNBins];
  Float_t met_uncerts[metNBins];
  float met_plot[metNBins];
  vector<TGraphErrors*> gr;
  TMultiGraph* mg = new TMultiGraph();







  
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



    // chain->SetBranchAddress("met",&met_f,&b_met);
    // chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
    // chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
    // chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
    // chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
    // chain->SetBranchAddress("ecalBadCalibFilter", &ecalBadCalibFilter, &b_ecalBadCalibFilter);
    // chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
    // chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
    // chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
    // chain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
    // chain->SetBranchAddress("HBHEIsoNoiseFilter", &HBHEIsoNoiseFilter, &b_HBHEIsoNoiseFilter);
    // chain->SetBranchAddress("BadChargedCandidateFilter", &BadChargedCandidateFilter, &b_BadChargedCandidateFilter);

    chain->SetBranchStatus("*",0);
    chain->SetBranchStatus("met",1);
    chain->SetBranchStatus("METFilters", 1);
    chain->SetBranchStatus("CSCTightHaloFilter", 1);
    chain->SetBranchStatus("globalSuperTightHalo2016Filter",1);
    chain->SetBranchStatus("goodVerticesFilter", 1);
    chain->SetBranchStatus("ecalBadCalibFilter", 1);
    chain->SetBranchStatus("HBHENoiseIsoFilter", 1);
    chain->SetBranchStatus("EcalDeadCellTriggerPrimitiveFilter", 1);
    chain->SetBranchStatus("BadPFMuonFilter", 1);
    chain->SetBranchStatus("HBHENoiseFilter", 1);
    chain->SetBranchStatus("HBHEIsoNoiseFilter", 1);
    chain->SetBranchStatus("BadChargedCandidateFilter", 1);

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
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220311/0000/stopFlatNtuples_*");
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220337/0000/stopFlatNtuples_*");
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220403/0000/stopFlatNtuples_*");
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220428/0000/stopFlatNtuples_*");
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220454/0000/stopFlatNtuples_*");
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220520/0000/stopFlatNtuples_*");
    // dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220546/0000/stopFlatNtuples_*");

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



    // chain->SetBranchAddress("met",&met_f,&b_met);
    // chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
    // chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
    // chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
    // chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
    // chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
    // chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
    // chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);

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
  

  Nentries = (float)chain->GetEntries();
  cout << "Nentries " << Nentries << endl;

  TString pass_str = filter_names[0] + "== 1";
  TString fail_str = filter_names[0] + "== 0";

  Npass = (float)chain->GetEntries(pass_str);
  cout << "Npass " << Npass << endl;

  Nfail = (float)chain->GetEntries(fail_str);
  cout << "Nfail " << Nfail << endl;



  if(Npass + Nfail != Nentries){
    cout << "error: total entries do not add up" << endl;
    return;
  }

  cout << "checked for correct number of entries" << endl;

  fail_eff = (Nfail/Nentries)*100;
  fail_sigma = sqrt((fail_eff*(1-fail_eff))/Nentries)*100; //CHECK THIS FORMULA -- MAY BE WRONG
  cout << "fail efficiency: " << fail_eff << " +/- " << fail_sigma << endl;



  for(int i = 0; i < metNBins+1; i++){
    met_bins[i] = (Float_t)i*metInterval;

    cout << "met bins: " << met_bins[i] << endl;
    
  }
  
/*
  Nfilters;
  Nmet;

  NPass[Nfilter][Nmet];
  NTot[Nmet];
  for(...events...)
    GetEntry()
    for(...met...)
      if(eventmet in bin)
        NTot[imet]+= 1.
        for(...filter...) 
          if(filterpass)
            NPadd[ifilter][imet]
*/



/*
not necessary, just for overkill; doesn't add any new info into plot
met_sig = sqrt(avg(met^2) - (avg(met))^2)
avg(met) = sum(met)/Nbin
for uniform distribution: (b-a)/sqrt(12)
*/

  for(int i = 0; i < filter_names.size(); i++){
    for(int j = 0; j < metNBins; j++){
      cout << "met loop#: " << j << endl;
      
      TString met_cut = Form("met > %f && met < %f",met_bins[j],met_bins[j+1]);
      TString fail_cut = filter_names[i] + "== 0 && " + met_cut; 
      TString pass_cut = filter_names[i] + "== 1 && " + met_cut;
      cout << fail_cut << endl;

      
      Nentries_met = (double)chain->GetEntries(met_cut);
      cout << "Nentries_met " << Nentries_met << endl;
      // Npass_met = (double)chain->GetEntries(pass_cut);
      // cout << "Npass_met " << Npass_met << endl;
      Nfail_met = (double)chain->GetEntries(fail_cut);
      cout << "Nfail_met " << Nfail_met << endl;

      // if(Npass_met + Nfail_met != Nentries_met){
      //   cout << "error: met entries do not add up" << endl;
      //   continue;
      // }

      if(Nentries_met == 0 && Nfail_met == 0){
        //don't include points with no events in the met interval
        met_effs[j] = -999;
        eff_uncerts[j] = -999;
        met_uncerts[j] = -999;
        met_plot[j] = -999;
      }
      else{
        met_eff = (Nfail_met/Nentries_met);
        Float_t met_eff_perc = met_eff*100;
        eff_uncert = sqrt((met_eff*(1-met_eff))/Nentries_met)*100;
        cout << "met_eff %: " << met_eff_perc << endl;
        cout << "eff_uncert: " << eff_uncert << endl;
        met_effs[j] = met_eff_perc;
        eff_uncerts[j] = eff_uncert;
        met_uncerts[j] = metInterval/2;
        met_plot[j] = (met_bins[j+1] + met_bins[j])/2;
      }
    }
    gr.push_back(new TGraphErrors(metNBins,met_plot,met_effs,met_uncerts,eff_uncerts));

    //remove points with no entries in met interval
    
    for(int j = metNBins; j > 0; j--){
      if(met_plot[j] == -999){
        cout << "point #: " << j << endl;
        cout << "met_plot: " << met_plot[j] << endl;
        cout << "met_effs: " << met_effs[j] << endl;
        cout << "met_uncerts: " << met_uncerts[j] << endl;
        cout << "eff_uncerts: " << eff_uncerts[j] << endl;
        gr[i]->RemovePoint(j);
      }

    }
    
    gr[i]->Print();

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
    cout << "added TGraphErrors to vector" << endl;

  }

  TCanvas* cv = new TCanvas("cv","cv",1000,600);
  // cv->SetTopMargin(0.09);
  cv->SetGrid();
  mg->Draw("ap");
  mg->SetTitle(sample+" Filter Efficiencies; met (GeV); fail efficiency %");

  // TLegend* leg2 = new TLegend(0.1,0.6,0.43,0.9);
  // for(int i = 0; i < filter_names.size(); i++){
  //   // TString tmpstr = Form(gr[i],filter_names[i])
  //   leg2->AddEntry(gr[i],filter_names[i].Data());
  // }
  // // leg2->SetTextSize(0.033);
  // leg2->SetFillColor(0);
  // leg2->Draw("same");

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

  // cv->Close();



}


