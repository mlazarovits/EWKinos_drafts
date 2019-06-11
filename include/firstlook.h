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
};