#include "utilities.C"
#include "KUAnalysis.h"
using namepsace std;

class firstlook{
	public:

		void InitBranches();
		void FillHistograms();

		bool debug;
		TString sample;
		TString outDir;
		TString sample_ext;

		TFile* file;
		TChain* chain;

		firstlook(TString in_sample);
		firstlook(TString in_sample, TString file);
		virtual ~firstlook();


	protected:

	private:
		Double_t        weight;
		Double_t        MET;
		Double_t        MET_phi;
		Double_t        genMET;
		Double_t        genMET_phi;
		Int_t           Nele;
		Int_t           Nmu;
		Int_t           Nlep;
		vector<double>  *PT_lep;
		vector<double>  *Eta_lep;
		vector<double>  *Phi_lep;
		vector<double>  *M_lep;
		vector<int>     *Charge_lep;
		vector<int>     *PDGID_lep;
		vector<int>     *RelIso_lep;
		vector<int>     *MiniIso_lep;
		vector<int>     *ID_lep;
		vector<int>     *Index_lep;
		Int_t           genNele;
		Int_t           genNmu;
		Int_t           genNlep;
		vector<double>  *genPT_lep;
		vector<double>  *genEta_lep;
		vector<double>  *genPhi_lep;
		vector<double>  *genM_lep;
		vector<int>     *genCharge_lep;
		vector<int>     *genPDGID_lep;
		vector<int>     *genMomPDGID_lep;
		vector<int>     *genIndex_lep;
};