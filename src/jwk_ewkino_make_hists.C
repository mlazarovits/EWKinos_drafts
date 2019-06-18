//
//  Jack W King III 2019
//

#include "jwk_ewkino_define_hists.h"

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

const string fall17_TChiWH_Bkg_SubDir = "TChiWH_Bkg_fall2017";

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

const string fall17_TChiWH = "All_Sig/SMS_TChiWH_WToLNu_HToBB_mChargino850_mLSP1_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root";

// const string SigTree_SMS_175_145 = "SMS_175_145";
// const string SigTree_SMS_300_25 = "SMS_300_25";
// const string SigTree_SMS_325_175 = "SMS_325_175";
const string SigTree_SMS_850_1 = "SMS_850_1";

// const string fall17_TChiWZ_SMS_175_145_SubDir =  "TChiWZ_SMS_175_145_fall2017";
// const string fall17_TChiWZ_SMS_300_25_SubDir =  "TChiWZ_SMS_300_25_fall2017";
// const string fall17_TChiWZ_SMS_325_175_SubDir =  "TChiWZ_SMS_325_175_fall2017";
const string fall17_TChiWH_SMS_850_1_SubDir = "TChiWH_SMS_850_fall2017";

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
  make_subdir( outfile, fall17_TChiWH_SMS_850_1_SubDir.c_str() );
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

  if(gSystem->AccessPathName(SingLeptonTFile.c_str())){
    gSystem->Exec("rm"+SingLeptonTFile.c_str());
  }

//--------BackGrounds
  run_hist_maker( BkgTree_KUAnalysis, bkg_vec,    SingLeptonTFile, fall17_TChiWH_Bkg_SubDir );
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
  
//--------Signals
  // run_hist_maker( SigTree_SMS_175_145, fall17_TChiWZ, TriLeptonTFile, fall17_TChiWZ_SMS_175_145_SubDir );
  // run_hist_maker( SigTree_SMS_300_25,  fall17_TChiWZ, TriLeptonTFile, fall17_TChiWZ_SMS_300_25_SubDir );
  // run_hist_maker( SigTree_SMS_325_175, fall17_TChiWZ, TriLeptonTFile, fall17_TChiWZ_SMS_325_175_SubDir );
  // run_hist_maker( SigTree_SMS_850_1, fall17_TChiWH, SingLeptonTFile, fall17_TChiWH_SMS_850_1_SubDir );

}


