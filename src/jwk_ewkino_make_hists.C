//
//  Jack W King III 2019
//

#include "../include/jwk_ewkino_define_hists.h"

///-------------- String declarations-------------------------------------------------------------------------

const string fall17_WJetsToLNu_100to200 = "All_Bkg_2017/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_WJetsToLNu_200to400 = "All_Bkg_2017/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_WJetsToLNu_400to600 = "All_Bkg_2017/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_WJetsToLNu_600to800 = "All_Bkg_2017/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_WJetsToLNu_800to1200 = "All_Bkg_2017/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_WJetsToLNu_1200to2500 = "All_Bkg_2017/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_TTWJetsToLNu = "All_Bkg_2017/TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8_Fall17.root";
const string fall17_TTJets_SingleLept_T = "All_Bkg_2017/TTJets_SingleLeptFromT_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_TTJets_SingleLept_Tbar = "All_Bkg_2017/TTJets_SingleLeptFromTbar_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_TTToSemiLept = "All_Bkg_2017/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_Fall17.root";
const string fall17_DYJets = "All_Bkg_2017/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_Fall17.root";

const string BkgTree_KUAnalysis = "KUAnalysis";

const string fall17_WJetsToLNu_SubDir = "WJetsToLNu_fall2017";
const string fall17_WJetsToLNu100to200_SubDir = "WJetsToLNu_100to200_fall2017";
const string fall17_WJetsToLNu200to400_SubDir = "WJetsToLNu_200to400_fall2017";
const string fall17_WJetsToLNu400to600_SubDir = "WJetsToLNu_400to600_fall2017";
const string fall17_WJetsToLNu600to800_SubDir = "WJetsToLNu_600to800_fall2017";
const string fall17_WJetsToLNu800to1200_SubDir = "WJetsToLNu_800to1200_fall2017";
const string fall17_WJetsToLNu1200to2500_SubDir = "WJetsToLNu_1200to2500_fall2017";
const string fall17_TTJetsToLNu_SubDir = "TTJetsToLNu_fall2017";
const string fall17_TTJetsSingLepT_SubDir = "TTJetsSingLepT_fall2017";
const string fall17_TTJetsSingLepTbar_SubDir = "TTJetsSingLepTbar_fall2017";
const string fall17_TTToSemiLept_SubDir = "TTToSemiLept_fall2017";
const string fall17_DYJets_SubDir = "DYJets_fall2017";

const string fall17_TChiWZ_Bkg_SubDir = "TChiWZ_Bkg_fall2017";

inline vector<string> load_gFileVec_TChiWZ_Bkg(){
  vector<string> g_FileVec;
  g_FileVec.push_back(fall17_WJetsToLNu_100to200);
  g_FileVec.push_back(fall17_WJetsToLNu_200to400);
  g_FileVec.push_back(fall17_WJetsToLNu_400to600);
  g_FileVec.push_back(fall17_WJetsToLNu_600to800);
  g_FileVec.push_back(fall17_WJetsToLNu_800to1200);
  g_FileVec.push_back(fall17_WJetsToLNu_1200to2500);
  g_FileVec.push_back(fall17_TTWJetsToLNu);
  g_FileVec.push_back(fall17_TTJets_SingleLept_T);
  g_FileVec.push_back(fall17_TTJets_SingleLept_Tbar); 
  g_FileVec.push_back(fall17_TTToSemiLept);
  g_FileVec.push_back(fall17_DYJets); 
  return g_FileVec;
}

inline std::vector<string> load_gFile_WJetsToLnu(){
  vector<string> g_FileVec;
  g_FileVec.push_back(fall17_WJetsToLNu_100to200);
  g_FileVec.push_back(fall17_WJetsToLNu_200to400);
  g_FileVec.push_back(fall17_WJetsToLNu_400to600);
  g_FileVec.push_back(fall17_WJetsToLNu_600to800);
  g_FileVec.push_back(fall17_WJetsToLNu_800to1200);
  g_FileVec.push_back(fall17_WJetsToLNu_1200to2500);
  return g_FileVec;
}


const string fall17_TChiWZ = "All_Sig/SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCP2_13TeV-madgraphMLM-pythia8_Fall17.root";

const string SigTree_SMS_200_150 = "SMS_200_150";
const string SigTree_SMS_200_1 = "SMS_200_1";
const string SigTree_SMS_200_197 = "SMS_200_197";

const string fall17_TChiWZ_SMS_200_150_SubDir =  "TChiWZ_SMS_200_150_fall2017";
const string fall17_TChiWZ_SMS_200_1_SubDir =  "TChiWZ_SMS_200_1_fall2017";
const string fall17_TChiWZ_SMS_200_197_SubDir =  "TChiWZ_SMS_200_197_fall2017";

const string SingLeptonTFile = "/home/t3-ku/mlazarov/CMSSW_10_1_4_patch1/src/EWKinos_drafts/output/KUEwkino_2017_singlelep_hists.root";
const string g_Path = "/home/t3-ku/crogan/NTUPLES/StopNtuple/";

//----------------------------------------------------------
//  Create TFile and TFile SubDirectories
//---------------------------------------------------------
inline TFile * makeTFile( string outfile_name ){

  auto outfile = new TFile( outfile_name.c_str(), "update" );
  outfile->cd();
  make_subdir( outfile, fall17_WJetsToLNu_SubDir.c_str() );
  make_subdir( outfile, fall17_TTJetsToLNu_SubDir.c_str() );
  make_subdir( outfile, fall17_TTJetsSingLepT_SubDir.c_str() );
  make_subdir( outfile, fall17_TTJetsSingLepTbar_SubDir.c_str() );
  make_subdir( outfile, fall17_TTToSemiLept_SubDir.c_str() );
  make_subdir( outfile, fall17_DYJets_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_200_150_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_200_1_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_200_197_SubDir.c_str() );

  return outfile;
}
//-------------------------------------------------------------------------------------------------------
//  Functions called to substantiate and run the hist maker class
//-------------------------------------------------------------------------------------------------------
void run_hist_maker( string treename, vector<string> g_FileVec, string outfile_name, string treeSubDir )
{ 
  std::cout << "Running over " << treename << " in: "  << std::endl;
  for( auto gfile : g_FileVec ){ std::cout << gfile << std::endl; }
  std::cout << "Writing to " << outfile_name << "/" << treeSubDir << std::endl;
  histMaker hist_maker; 
  auto tfile = makeTFile(outfile_name);
  hist_maker.make_hists( g_Path, g_FileVec, treename, tfile, treeSubDir );
  tfile->Close();
  std::cout << "Finished" << std::endl;
}
void run_hist_maker( string treename, string g_FileName, string outfile_name, string treeSubDir )
{
  std::cout << "Running over " << treename << " in: "  << std::endl;
  std::cout << g_FileName << std::endl;
  std::cout << "Writing to " << outfile_name << "/" << treeSubDir << std::endl;
  histMaker hist_maker;
  auto tfile = makeTFile(outfile_name);
  hist_maker.make_hists( g_Path, g_FileName, treename, tfile, treeSubDir );
  tfile->Close();
  std::cout << "Finished" << std::endl;
}
//-------------------------------------------------------------------------------------------------------
//Root Macro to run histogram jobs
//--------------------------------------------------------------------------------------------------------

void jwk_ewkino_make_hists(){
  vector<string> bkg_vec = load_gFileVec_TChiWZ_Bkg();
  vector<string> wjets_total = load_gFile_WJetsToLnu();
  histMaker hist_maker;
  hist_maker.skip = 10000;


//--------BackGrounds
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec,    SingLeptonTFile, fall17_TChiWZ_Bkg_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[0], SingLeptonTFile, fall17_WJetsToLNu100to200_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[1], SingLeptonTFile, fall17_WJetsToLNu200to400_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[2], SingLeptonTFile, fall17_WJetsToLNu400to600_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[3], SingLeptonTFile, fall17_WJetsToLNu600to800_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[4], SingLeptonTFile, fall17_WJetsToLNu800to1200_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[5], SingLeptonTFile, fall17_WJetsToLNu1200to2500_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, wjets_total,SingLeptonTFile, fall17_WJetsToLNu_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[6], SingLeptonTFile, fall17_TTJetsToLNu_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[7], SingLeptonTFile, fall17_TTJetsSingLepT_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[8], SingLeptonTFile, fall17_TTJetsSingLepTbar_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[9], SingLeptonTFile, fall17_TTToSemiLept_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec[10],SingLeptonTFile, fall17_DYJets_SubDir );


//--------Signals
  run_hist_maker( SigTree_SMS_200_150, fall17_TChiWZ, SingLeptonTFile, fall17_TChiWZ_SMS_200_150_SubDir );
  run_hist_maker( SigTree_SMS_200_1,   fall17_TChiWZ, SingLeptonTFile, fall17_TChiWZ_SMS_200_1_SubDir );
  run_hist_maker( SigTree_SMS_200_197, fall17_TChiWZ, SingLeptonTFile, fall17_TChiWZ_SMS_200_197_SubDir );

}


