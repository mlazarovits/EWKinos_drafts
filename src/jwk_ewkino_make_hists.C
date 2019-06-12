//
//  Jack W King III 2019
//

#include "jwk_ewkino_define_hists.h"

///-------------- String declarations-------------------------------------------------------------------------

const string fall17_WZ = "All_Bkg_2017/WZ_TuneCP5_13TeV-pythia8_Fall17.root";
const string fall17_DYJetsToLL_M50 = "All_Bkg_2017/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_Fall17.root";
const string fall17_DYJetsToLL_M5to50 = "All_Bkg_2017/DYJetsToLL_M-5to50_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root"; 
const string fall17_TTJets = "All_Bkg_2017/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_TuneCP5.root";
const string fall17_WJetsToLNu = "All_Bkg_2017/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";
const string fall17_WW = "All_Bkg_2017/WW_TuneCP5_13TeV-pythia8_Fall17.root";
const string fall17_ZZ = "All_Bkg_2017/ZZ_TuneCP5_13TeV-pythia8_Fall17.root";

const string BkgTree_KUAnalysis = "KUAnalysis";

const string fall17_WZ_SubDir = "WZ_fall2017";
const string fall17_DYJetsToLL_M50_SubDir = "DYJetsToLL_M50_fall2017";
const string fall17_DYJetsToLL_M5to50_SubDir = "DYJetsToLL_M5to50_fall2017";
const string fall17_TTJets_SubDir = "TTJets_fall2017";
const string fall17_WJetsToLNu_SubDir = "WJetsToLNu_fall2017";
const string fall17_WW_SubDir = "WW_fall2017";
const string fall17_ZZ_SubDir = "ZZ_fall2017";

const string fall17_TChiWZ_Bkg_SubDir = "TChiWZ_Bkg_fall2017";
vector<string> load_gFileVec_TChiWZ_Bkg(){
  vector<string> g_FileVec;
  g_FileVec.push_back(fall17_WZ);
  g_FileVec.push_back(fall17_DYJetsToLL_M50);
  g_FileVec.push_back(fall17_DYJetsToLL_M5to50);
  g_FileVec.push_back(fall17_TTJets);
  g_FileVec.push_back(fall17_WJetsToLNu);
  g_FileVec.push_back(fall17_WW);
  g_FileVec.push_back(fall17_ZZ);
  return g_FileVec;
}

const string fall17_TChiWZ = "All_Sig/SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCP2_13TeV-madgraphMLM-pythia8_Fall17.root";

const string SigTree_SMS_175_145 = "SMS_175_145";
const string SigTree_SMS_300_25 = "SMS_300_25";
const string SigTree_SMS_325_175 = "SMS_325_175";

const string fall17_TChiWZ_SMS_175_145_SubDir =  "TChiWZ_SMS_175_145_fall2017";
const string fall17_TChiWZ_SMS_300_25_SubDir =  "TChiWZ_SMS_300_25_fall2017";
const string fall17_TChiWZ_SMS_325_175_SubDir =  "TChiWZ_SMS_325_175_fall2017";

const string TriLeptonTFile = "KUEwkino_2017_lll_hists.root";
const string g_Path = "/home/t3-ku/crogan/NTUPLES/StopNtuple/";

//----------------------------------------------------------
//  Create TFile and TFile SubDirectories
//---------------------------------------------------------
TFile * makeTFile( string outfile_name ){

  auto outfile = new TFile( outfile_name.c_str(), "update" );
  outfile->cd();
  make_subdir( outfile, fall17_WZ_SubDir.c_str() );
  make_subdir( outfile, fall17_DYJetsToLL_M50_SubDir.c_str() );
  make_subdir( outfile, fall17_DYJetsToLL_M5to50_SubDir.c_str() );
  make_subdir( outfile, fall17_TTJets_SubDir.c_str() );
  make_subdir( outfile, fall17_WW_SubDir.c_str() );
  make_subdir( outfile, fall17_ZZ_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_Bkg_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_175_145_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_300_25_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_325_175_SubDir.c_str() );
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

//--------BackGrounds
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg(), TriLeptonTFile, fall17_TChiWZ_Bkg_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_WZ, 		  TriLeptonTFile, fall17_WZ_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_DYJetsToLL_M50,      TriLeptonTFile, fall17_DYJetsToLL_M50_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_DYJetsToLL_M5to50,   TriLeptonTFile, fall17_DYJetsToLL_M5to50_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_TTJets, 		  TriLeptonTFile, fall17_TTJets_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_WJetsToLNu,          TriLeptonTFile, fall17_WJetsToLNu_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_WW, 		  TriLeptonTFile, fall17_WW_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, fall17_ZZ, 		  TriLeptonTFile, fall17_ZZ_SubDir );

//--------Signals
  run_hist_maker( SigTree_SMS_175_145, fall17_TChiWZ, TriLeptonTFile, fall17_TChiWZ_SMS_175_145_SubDir );
  run_hist_maker( SigTree_SMS_300_25,  fall17_TChiWZ, TriLeptonTFile, fall17_TChiWZ_SMS_300_25_SubDir );
  run_hist_maker( SigTree_SMS_325_175, fall17_TChiWZ, TriLeptonTFile, fall17_TChiWZ_SMS_325_175_SubDir );

}


