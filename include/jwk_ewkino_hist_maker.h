//
//  Jack W King III  2019
//

#include <iostream>
#include <string>

#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TH2D.h>
#include <TStyle.h>

#include "jwk_ku_tdr_style.h"
#include "../include/ReducedBase.hh"

using namespace std;

//-----------------  helper function  -----------------------------------------
TDirectory* make_subdir( TFile* outfile, string subdir ){

  outfile->cd();
  TDirectory* fileSubDir;
  if( subdir != "" ){
        fileSubDir = outfile->GetDirectory(subdir.c_str());
        if( fileSubDir == 0 ){
                outfile->mkdir( subdir.c_str() );
                fileSubDir = outfile->GetDirectory(subdir.c_str());
        }
  }
  return fileSubDir;
}
//-----------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
class parentHistClass{

  public:

  parentHistClass();
  ~parentHistClass();

  virtual void init_hist(  string treeSubDir );	
  virtual void fill_hist( ReducedBase * base );
  virtual void write_hist( TFile * outfile );
  void set_subdir( string name ){ subdir = name; }

  protected:

  string subdir;

  TH1F * hist1f;
  TH2F * hist2f;
  TH1D * hist1d;
  TH2D * hist2d;

};
////////////////////////////////////////////////////////////////
parentHistClass::parentHistClass(){

  hist1f = NULL;
  hist2f = NULL;
  hist1d = NULL;
  hist2d = NULL;

  subdir = "";

  gPad->SetMargin(0.1,0.1,0.1,0.1);

}

parentHistClass::~parentHistClass(){

  if( hist1f ) delete hist1f;
  if( hist2f ) delete hist2f;
  if( hist1d ) delete hist1d;
  if( hist2d ) delete hist2d;

}

void parentHistClass::write_hist( TFile* outfile ){

  outfile->cd();
  auto fileSubDir = make_subdir( outfile, subdir );
  fileSubDir->cd();

  if( hist1f ) hist1f->Write();  
  if( hist2f ) hist2f->Write();
  if( hist1d ) hist1d->Write();
  if( hist2d ) hist2d->Write();

}

void parentHistClass::init_hist( string treeSubDir ){

  //set_subdir( treeSubDir );
  // hist1d = new TH1D("parentHistClass","baseHistClass", 2, -0.5, 1.5 );
  std::cout << "In Init from BaseClass !" << std::endl;
}

void parentHistClass::fill_hist( ReducedBase* base ){

  //hist1d->Fill(1.0);
  std::cout << "Filling from BaseClass !" << std::endl;

}
//--------------------------------------------------------------------------------
/////////////////////////////////    maker class that loops over events
class histMaker{

	public:
	vector< parentHistClass * > hist_vector_loader( string treeSubDir );
	bool global_cuts( ReducedBase * base );
	void make_hists( string g_Path, vector<string> g_FileVec, string treeName,  TFile * outfile, string treeSubDir );
  void make_hists( string g_Path, string g_FileName,        string treeName,  TFile * outfile, string treeSubDir );

};

void histMaker::make_hists( string g_Path, string g_FileName, string treeName,  TFile * outfile, string treeSubDir ){

	vector< string > g_FileVec;
	g_FileVec.push_back( g_FileName );
	histMaker::make_hists( g_Path, g_FileVec, treeName, outfile, treeSubDir );
}

void histMaker::make_hists( string g_Path, vector<string> g_FileVec, string treeName,  TFile * outfile, string treeSubDir ){

  setTDRStyle();
  const auto vhistclasses = hist_vector_loader( treeSubDir );
  int Nsample = g_FileVec.size();

  TChain* chain = new TChain( treeName.c_str() );
  for( int s = 0; s < Nsample; s++ ){ chain->Add( ( g_Path + g_FileVec[s] ).c_str() ); } 
  ReducedBase * base = new ReducedBase( chain );

  int Nentry = base->fChain->GetEntries();
  for( int entry = 0; entry < Nentry; entry++ ){
    // if( entry % ( std::max( 1, Nentry/20 ) ) == 0 )  cout << "Event " << entry << " | " << Nentry << endl;
    //if( entry > 1000 ) break;
      if( entry % 1000000 == 0){
        fprintf(stdout, "\r Processed %8d events of %8d", entry, Nentry);
      }
      fflush(stdout);
    base->GetEntry( entry );
    if( global_cuts( base ) ) continue;
    for( auto histclass : vhistclasses ){ histclass->fill_hist( base ); }
  }
  for( auto histclass : vhistclasses ){ histclass->write_hist( outfile ); delete histclass; }
  delete base;
  delete chain;
}

/////////////////////////////////////////////////////////////
