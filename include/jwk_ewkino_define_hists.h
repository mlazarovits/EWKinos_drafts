//
//  Histogram definitions and loading
//  Jack W King III 2019
//

#include "jwk_ewkino_hist_maker.h"

//---------------------------------------------------------------------
// Utility functions
// -------------------------------------------------------------------
TLorentzVector * get4vec(double pt, double eta, double phi, double m){
	double px = pt*cos(phi);
	double py = pt*sin(phi);
	double pz = pt*sinh(eta);
	TLorentzVector *v = new TLorentzVector();
	v->SetXYZM( px,py,pz,m );
	return v;	
}
//---------------------------------------------------------------------
TLorentzVector * add4vecs( vector<double> pt, vector<double> eta, vector<double> phi, vector<double> m){

	TLorentzVector * p = new TLorentzVector();
	for(unsigned int i=0; i<pt.size(); i++){
		TLorentzVector *c = new TLorentzVector();
		c = get4vec(pt.at(i), eta.at(i), phi.at(i), m.at(i) );
		*p += *c;
	}
	return p;

}
//-----------------------------------------------------------------------
////---------------------------------------------------------------------
//
//	<--------------   create new histograms as in example below
//
//
//class otherHistClass : public parentHistClass{
// 
//  public:
//  void init_hist( string treeSubDir );
//  void fill_hist( ReducedBase* base );
// 
//}
//
//void otherHistClass::initi_hist(){
//    
//  setTDRStyle();
//  hist1d = new TH1D("parentHistClass","baseHistClass", 2, -0.5, 1.5 );
//
//}
//
//  note:  parentHistClass has pointers:  
//  		hist1d 
//  		hist2d 
//  		hist1f 
//  		hist2f
//
//void otherHistClass::fill_hist( ReducedBase* base ){
//
//  hist1d->Fill(1.0);
//  //----  or:  hist1d->Fill(base->RISR->at(2), base->weight);
//  //----  or:  hist2d->Fill(base->RISR->at(2), base->PTISR->at(2) , base->weight);
//
//}

//----------------------------------------------------------------------------
//----Example of new class follows-------------------------------------------
//----------------------------------------------------------------------------
class testHistTheFirst : public parentHistClass{

  public: 
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );
 
};

void testHistTheFirst::init_hist( string treeSubDir ){
  
  set_subdir( treeSubDir );   
  hist1d = new TH1D("testHistTheFirst","FirstTestHist", 2, -1.5, 1.5 );
 // std::cout << "In Init from testHistTheFirst !!" << std::endl;

}

void testHistTheFirst::fill_hist( ReducedBase* base ){

  hist1d->Fill(1.0);

}
//-------------------------------------------------------------------------------------------------------
//----------------------------make new hist classes below------------------------------------------------
//-------------------------------------------------------------------------------------------------------
class metHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void metHist::init_hist( string treeSubDir ){
  set_subdir(treeSubDir);
  hist1d = new TH1D("metHist","MET", 90, 100, 1000 );
  hist1d->GetXaxis()->SetTitle("MET [GeV]");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");


 // std::cout << "In Init from metHist !!" << std::endl;

}

void metHist::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->MET, base->weight);

}
//----------------------------------------------------------------------------
class mlHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void mlHist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("mlHist","Single Lepton Mass", 200, 0, 200 );
  hist1d->GetXaxis()->SetTitle("Single Lepton Mass [GeV]");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from mlllHist !!" << std::endl;

}

void mlHist::fill_hist( ReducedBase* base ){

  TLorentzVector * l = add4vecs( *(base->PT_lep), *(base->Eta_lep), *(base->Phi_lep), *(base->M_lep) );
  hist1d->Fill( l->M(), base->weight);

}

//----------------------------------------------------------------------------
class njetsHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void njetsHist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("njetsHist","N jets", 11, -0.5, 10.5 );
  hist1d->GetXaxis()->SetTitle("N jets");
  hist1d->GetYaxis()->SetTitle("");
 // std::cout << "In Init from njetsHist !!" << std::endl;

}

void njetsHist::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->Njet, base->weight);

}
//----------------------------------------------------------------------------
class ptcmHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void ptcmHist_Cat1::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("ptcmHist_Cat1","PTCM Cat 1", 50, 0, 500 );
  hist1d->GetXaxis()->SetTitle("PTCM [GeV] Cat 1");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptcmHist !!" << std::endl;

}

void ptcmHist_Cat1::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTCM->at(0) , base->weight);

}
//----------------------------------------------------------------------------
class ptisrHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void ptisrHist_Cat1::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("ptisrHist_Cat1","P_{t}^{ISR} Cat 1", 100, 0, 1000 );
  hist1d->GetXaxis()->SetTitle("P_{t}^{ISR} [GeV] Cat 1");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptisrHist !!" << std::endl;

}

void ptisrHist_Cat1::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTISR->at(0), base->weight);

}
//----------------------------------------------------------------------------
class risrHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void risrHist_Cat1 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("risrHist_Cat1 ","R_{ISR} Cat 1", 40, -1, 3 );
  hist1d->GetXaxis()->SetTitle("R_{ISR} [a.u.] Cat 1");
  hist1d->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void risrHist_Cat1 ::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->RISR->at(0), base->weight);

}
//----------------------------------------------------------------------------
class dphiCMIHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );
  
};

void dphiCMIHist_Cat1::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("dphiCMIHist_Cat1","#delta(#phi_{CMI}) Cat 1", 100, 0, 1000 );
  hist1d->GetXaxis()->SetTitle("#delta(#phi_{CMI}) [GeV] Cat 1");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from dphiCMIHist !!" << std::endl;

}

void dphiCMIHist_Cat1::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTISR->at(0), base->weight);

}
//----------------------------------------------------------------------------
class ptcmHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void ptcmHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("ptcmHist_Cat2","P_{t}^{CM} Cat 2", 50, 0, 500 );
  hist1d->GetXaxis()->SetTitle("P_{t}^{CM} [GeV] Cat 2");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptcmHist !!" << std::endl;

}

void ptcmHist_Cat2::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTCM->at(1) , base->weight);

}
//----------------------------------------------------------------------------
class ptisrHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void ptisrHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("ptisrHist_Cat2","P_{t}^{ISR} Cat 2", 100, 0, 1000 );
  hist1d->GetXaxis()->SetTitle("P_{t}^{ISR} [GeV] Cat 2");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptisrHist !!" << std::endl;

}

void ptisrHist_Cat2::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTISR->at(1), base->weight);

}
//----------------------------------------------------------------------------
class risrHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void risrHist_Cat2 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("risrHist_Cat2 ","R_{ISR} Cat 2", 40, -1, 3 );
  hist1d->GetXaxis()->SetTitle("R_{ISR} [a.u.] Cat 2");
  hist1d->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void risrHist_Cat2 ::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->RISR->at(1), base->weight);

}
//----------------------------------------------------------------------------
class dphiCMIHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );
  
};

void dphiCMIHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("dphiCMIHist_Cat2","#delta(#phi_{CMI}) Cat 2", 100, 0, 1000 );
  hist1d->GetXaxis()->SetTitle("#delta(#phi_{CMI}) [GeV] Cat 2");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from dphiCMIHist !!" << std::endl;

}

void dphiCMIHist_Cat2::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTISR->at(1), base->weight);

}
//----------------------------------------------------------------------------
class ptcmHist_Cat3 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void ptcmHist_Cat3::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("ptcmHist_Cat3","P_{t}^{CM} Cat 3", 50, 0, 500 );
  hist1d->GetXaxis()->SetTitle("P_{t}^{CM} [GeV] Cat 3");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptcmHist !!" << std::endl;

}

void ptcmHist_Cat3::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTCM->at(2) , base->weight);

}
//----------------------------------------------------------------------------
class ptisrHist_Cat3 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void ptisrHist_Cat3::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("ptisrHist_Cat3","P_{t}^{ISR} Cat 3", 100, 0, 1000 );
  hist1d->GetXaxis()->SetTitle("P_{t}^{ISR} [GeV] Cat 3");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptisrHist !!" << std::endl;

}

void ptisrHist_Cat3::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTISR->at(2), base->weight);

}
//----------------------------------------------------------------------------
class risrHist_Cat3 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void risrHist_Cat3 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("risrHist_Cat3 ","R_{ISR} Cat 3", 40, -1, 3 );
  hist1d->GetXaxis()->SetTitle("R_{ISR} [a.u.] Cat 3");
  hist1d->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void risrHist_Cat3 ::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->RISR->at(2), base->weight);

}
//----------------------------------------------------------------------------
class dphiCMIHist_Cat3 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase* base );

};

void dphiCMIHist_Cat3::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new TH1D("dphiCMIHist_Cat3","#delta(#phi_{CMI}) Cat 3", 100, 0, 1000 );
  hist1d->GetXaxis()->SetTitle("#delta(#phi_{CMI}) [GeV] Cat 3");
  hist1d->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from dphiCMIHist !!" << std::endl;

}

void dphiCMIHist_Cat3::fill_hist( ReducedBase* base ){

  hist1d->Fill(base->PTISR->at(2), base->weight);

}
//----------------------------------------------------------------------------
class RISR_v_PTISR_Cat3_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase * base );

};

void RISR_v_PTISR_Cat3_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "R_{ISR}";
  double g_Xmin = 0.2;
  double g_Xmax = 1.2;
  int    g_NX = 50;
  string g_Yname = "p_{T}^{ISR} [GeV]";
  double g_Ymin = 50.;
  double g_Ymax = 900.;
  int    g_NY = 50;

  hist2d = new TH2D("RISR_v_PTISR_Cat3_hist","RISR v PTISR Cat3", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  hist2d->GetXaxis()->SetTitle(g_Xname.c_str());
  hist2d->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void RISR_v_PTISR_Cat3_hist::fill_hist( ReducedBase * base ){

  hist2d->Fill(base->RISR->at(2), base->PTISR->at(2) , base->weight);

}

//--------------------------------------------------------------
class RISR_v_PTISR_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase * base );

};

void RISR_v_PTISR_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "R_{ISR}";
  double g_Xmin = 0.2;
  double g_Xmax = 1.2;
  int    g_NX = 50;
  string g_Yname = "p_{T}^{ISR} [GeV]";
  double g_Ymin = 50.;
  double g_Ymax = 900.;
  int    g_NY = 50;

  hist2d = new TH2D("RISR_v_PTISR_Cat2_hist","RISR_v_PTISR_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  hist2d->GetXaxis()->SetTitle(g_Xname.c_str());
  hist2d->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void RISR_v_PTISR_Cat2_hist::fill_hist( ReducedBase * base ){

  hist2d->Fill(base->RISR->at(1), base->PTISR->at(1) , base->weight);

}
//---------------------------------------------------------------------------------
class RISR_v_PTISR_Cat1_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( ReducedBase * base );

};

void RISR_v_PTISR_Cat1_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "R_{ISR}";
  double g_Xmin = 0.2;
  double g_Xmax = 1.2;
  int    g_NX = 50;
  string g_Yname = "p_{T}^{ISR} [GeV]";
  double g_Ymin = 50.;
  double g_Ymax = 900.;
  int    g_NY = 50;

  hist2d = new TH2D("RISR_v_PTISR_Cat1_hist","RISR_v_PTISR_Cat1_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  hist2d->GetXaxis()->SetTitle(g_Xname.c_str());
  hist2d->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void RISR_v_PTISR_Cat1_hist::fill_hist( ReducedBase * base ){

  hist2d->Fill(base->RISR->at(0), base->PTISR->at(0) , base->weight);

}
//------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------
//  make any global cuts for all histograms here.  Should return true to skip event.
//--------------------------------------------------------------------------------------------------------
bool histMaker::global_cuts( ReducedBase * base ){

  bool cut_nlep = true;

  if( base->Nlep == 1 ) cut_nlep = false;
  
  //std::cout << " nlept " << base->Nlep << std::endl;
  //std::cout << " nlep cut " << cut_nlep << " sfos cut " << cut_sfos << std::endl;
  return cut_nlep;
 
}
//---------------------------------------------------------------------------------------------------------
//  loads histograms to be filled, add to new histogram to be run to the hist class vector as shown below.
//--------------------------------------------------------------------------------------------------------
vector< parentHistClass * > histMaker::hist_vector_loader( string treeSubDir ){
 
  vector< parentHistClass *  > vhistclasses;
  //vhistclasses.push_back( new testHistTheFirst );
  //vhistclasses.push_back( new testHistTheSecond );
  //   <--------------------------------------   add new hist classes here
  vhistclasses.push_back( new RISR_v_PTISR_Cat3_hist );
  vhistclasses.push_back( new RISR_v_PTISR_Cat2_hist );
  vhistclasses.push_back( new RISR_v_PTISR_Cat1_hist );
  vhistclasses.push_back( new metHist );
  vhistclasses.push_back( new mlHist );
  vhistclasses.push_back( new njetsHist );
  vhistclasses.push_back( new ptcmHist_Cat1 );
  vhistclasses.push_back( new ptisrHist_Cat1 );
  vhistclasses.push_back( new risrHist_Cat1 );
  vhistclasses.push_back( new dphiCMIHist_Cat1 );
  vhistclasses.push_back( new ptcmHist_Cat2 );
  vhistclasses.push_back( new ptisrHist_Cat2 );
  vhistclasses.push_back( new risrHist_Cat2 );
  vhistclasses.push_back( new dphiCMIHist_Cat2 );
  vhistclasses.push_back( new ptcmHist_Cat3 );
  vhistclasses.push_back( new ptisrHist_Cat3 );
  vhistclasses.push_back( new risrHist_Cat3 );
  vhistclasses.push_back( new dphiCMIHist_Cat3 );

  for( auto histclass : vhistclasses ){ histclass->init_hist( treeSubDir ); }

  return vhistclasses;
 
}
//----------------------------------------------------------------------------

