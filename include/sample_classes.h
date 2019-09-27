//////efficiency sample classes//////
#include "eff2.h"
#include "eff_maker.h"
class parentSampleClass : public eff_maker{
public:
	parentSampleClass();
	~parentSampleClass();
	virtual void init_sample();
	TString sample;

};
parentSampleClass::parentSampleClass(){
	std::cout << "parent sample init" << endl;
}







//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
class dyJets : public parentSampleClass{
public:
	void init_eff( string treeSubDir );
	void fill_variables( AUX* aux );
};
void dyJets::init_eff( string treeSubDir ){
	// chain->SetBranchAddress("met",&met,&b_met);
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
	// chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

	filter_names.push_back("globalSuperTightHalo2016Filter");
	filter_names.push_back("goodVerticesFilter");
	filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
	filter_names.push_back("BadPFMuonFilter");
	filter_names.push_back("CSCTightHaloFilter");
	
	filter_names.push_back("METFilters");
	filter_names.push_back("BadChargedCandidateFilter");
	filter_names.push_back("HBHENoiseFilter");
	filter_names.push_back("HBHEIsoNoiseFilter");
	

	// TFileCollection *dyJetsToLL= new TFileCollection("dyJetsToLL","dyJetsToLL");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220245/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220311/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220337/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220403/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220428/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220454/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220520/0000/stopFlatNtuples_*");
	// dyJetsToLL->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/QCD/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/190201_220546/0000/stopFlatNtuples_*");

	// chain->AddFileInfoList((TCollection*)dyJetsToLL->GetList());
	// sample = dyJetsToLL->GetName();
	// std::cout << "sample: " << sample << std::endl;
}
void fill_variables( AUX* aux ){
	filters.push_back(aux->globalSuperTightHalo2016Filter);
	filters.push_back(aux->goodVerticesFilter);
	filters.push_back(aux->EcalDeadCellTriggerPrimitiveFilter);
	filters.push_back(aux->BadPFMuonFilter);
	filters.push_back(aux->CSCTightHaloFilter);
	filters.push_back(aux->METFilters);
	filters.push_back(aux->BadChargedCandidateFilter);
	filters.push_back(aux->HBHENoiseFilter);
	filters.push_back(aux->HBHEIsoNoiseFilter);
}



//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
class TChiWZ : public parentSampleClass{
public:
	void init_eff( string tree SubDir );
};
void TChiWZ::init_eff( string tree SubDir ){
		chain->SetBranchAddress("met",&met,&b_met);
		chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
		chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
		chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
		chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
		chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
		chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
		chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
		chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

		chain->SetBranchStatus("*",0);
		chain->SetBranchStatus("*Filter*",1);
		chain->SetBranchStatus("met",1);
		
		filter_names.push_back("globalSuperTightHalo2016Filter");
		filter_names.push_back("goodVerticesFilter");
		filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
		filter_names.push_back("BadPFMuonFilter");
		filter_names.push_back("CSCTightHaloFilter");
		filter_names.push_back("HBHENoiseIsoFilter");
	

		//2016 dataset
		TFileCollection *TChiToWZ = new TFileCollection("TChiToWZ","TChiToWZ");
		TChiToWZ->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWZ_ZToLL_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWZ_ZToLL_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISpring16MiniAODv2/181220_184342/0000/stopFlatNtuples_*");
		TChiToWZ->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv2/181220_184216/0000/stopFlatNtuples_*");
		TChiToWZ->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWZ_ZToLL_mZMin-0p1_mLSP300to350_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWZ_ZToLL_mZMin-0p1_mLSP300to350_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv2/181220_184151/0000/stopFlatNtuples_*");
		std::cout << "finished adding files to file list" << std::endl;

		chain->AddFileInfoList((TCollection*)TChiToWZ->GetList());

		sample = TChiToWZ->GetName();
		std::cout << "sample: " << sample << std::endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
class TChiWH_HToGG : public parentSampleClass{
public:
	void init_eff( string treeSubDir );
}

void TChiWH_HToGG::init_eff( string treeSubDir ){
	chain->SetBranchAddress("met",&met,&b_met);
	chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
	chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
	chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
	chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
	chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
	chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
	chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
	chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

	chain->SetBranchStatus("*",0);
	chain->SetBranchStatus("*Filter*",1);
	chain->SetBranchStatus("met",1);
	chain->SetBranchStatus("evtWeight",1);

	filter_names.push_back("globalSuperTightHalo2016Filter");
	filter_names.push_back("goodVerticesFilter");
	filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
	filter_names.push_back("BadPFMuonFilter");
	filter_names.push_back("CSCTightHaloFilter");
	filter_names.push_back("HBHENoiseIsoFilter");		
	filter_names.push_back("METFilters");

	//2016 dataset
	TFileCollection *TChiWH_HToGG = new TFileCollection("TChiWH_HToGG","TChiWH_HToGG");
	TChiWH_HToGG->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/jaking/Ewkinos/Signal/SMS-TChiWH_HToGG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_SMS-TChiWH_HToGG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISpring16MiniAODv2/181220_184408/0000/stopFlatNtuples_*");    
	std::cout << "finished adding files to file list" << std::endl;

	chain->AddFileInfoList((TCollection*)TChiWH_HToGG->GetList());
	sample = TChiWH_HToGG->GetName();
	std::cout << "sample: " << sample << std::endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
class WJetsToLNu : public parentSampleClass{
public:
	void init_eff( string treeSubDir );
};
void WJetsToLNu::init_eff( string treeSubDir ){
	chain->SetBranchAddress("met",&met,&b_met);
	chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
	chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
	chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
	chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
	chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
	chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
	chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
	chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

	chain->SetBranchStatus("*",0);
	chain->SetBranchStatus("*Filter*",1);
	chain->SetBranchStatus("met",1);
	chain->SetBranchStatus("evtWeight",1);


	filter_names.push_back("globalSuperTightHalo2016Filter");
	filter_names.push_back("goodVerticesFilter");
	filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
	filter_names.push_back("BadPFMuonFilter");
	filter_names.push_back("CSCTightHaloFilter");
	filter_names.push_back("HBHENoiseIsoFilter");
	filter_names.push_back("METFilters");

	//2016 dataset
	TFileCollection *WJetsToLNu = new TFileCollection("WJetsToLNu","WJetsToLNu");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020824/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020702/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020845/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020721/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020740/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8RunIISummer16MiniAODv3/190222_020800/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/181116_210752/0000/stopFlatNtuples_*");
	WJetsToLNu->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/zflowers/Ewkinos/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/crab_extWJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8RunIIFall17MiniAODv2/181219_234206/0000/stopFlatNtuples_*");

	std::cout << "finished adding files to file list" << std::endl;

	chain->AddFileInfoList((TCollection*)WJetsToLNu->GetList());
	sample = WJetsToLNu->GetName();
	std::cout << "sample: " << sample << std::endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
class TTJets : public parentSampleClass{
public:
	void init_eff( string treeSubDir );
};
void TTJets::init_eff( string treeSubDir ){
	chain->SetBranchAddress("met",&met,&b_met);
	chain->SetBranchAddress("METFilters", &METFilters, &b_METFilters);
	chain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
	chain->SetBranchAddress("globalSuperTightHalo2016Filter", &globalSuperTightHalo2016Filter, &b_globalSuperTightHalo2016Filter);
	chain->SetBranchAddress("goodVerticesFilter", &goodVerticesFilter, &b_goodVerticesFilter);
	chain->SetBranchAddress("HBHENoiseIsoFilter", &HBHENoiseIsoFilter, &b_HBHENoiseIsoFilter);
	chain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
	chain->SetBranchAddress("BadPFMuonFilter", &BadPFMuonFilter, &b_BadPFMuonFilter);
	chain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);

	chain->SetBranchStatus("*",0);
	chain->SetBranchStatus("*Filter*",1);
	chain->SetBranchStatus("met",1);
	chain->SetBranchStatus("evtWeight",1);
	
	
	filter_names.push_back("globalSuperTightHalo2016Filter");
	filter_names.push_back("goodVerticesFilter");
	filter_names.push_back("EcalDeadCellTriggerPrimitiveFilter");
	filter_names.push_back("BadPFMuonFilter");
	filter_names.push_back("CSCTightHaloFilter");
	filter_names.push_back("HBHENoiseIsoFilter");
	filter_names.push_back("METFilters");

	//2016 dataset
	TFileCollection *TTJets = new TFileCollection("TTJets","TTJets");
	TTJets->Add("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/crogan/TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8/crab_TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8RunIISummer16MiniAODv2/181220_212122/0000/stopFlatNtuples_*");    
	std::cout << "finished adding files to file list" << std::endl;

	chain->AddFileInfoList((TCollection*)TTJets->GetList());
	chain->SetBranchStatus("*",0);
	chain->SetBranchStatus("*Filter*",1);
	chain->SetBranchStatus("met",1);
	chain->SetBranchStatus("evtWeight",1);
	sample = TTJets->GetName();
	std::cout << "sample: " << sample << std::endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------


vector< parentSampleClass * > eff_maker::eff_vector_loader( string treeSubDir ){
 
  vector< parentSampleClass *  > veffclasses;
  //vhistclasses.push_back( new testHistTheFirst );
  //vhistclasses.push_back( new testHistTheSecond );
  //   <--------------------------------------   add new hist classes here
  vhistclasses.push_back( new dyJets );
  vhistclasses.push_back( new WJetsToLNu );
  vhistclasses.push_back( new TTJets );
  vhistclasses.push_back( new TChiWZ );
  vhistclasses.push_back( new TChiWH_HToGG );

  for( auto effclass : veffclasses ){ effclass->init_eff( treeSubDir ); }

  return veffclasses;
}


