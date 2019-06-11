using namespace std;


void CosmeticMap(TH2F * map, TString zaxis);
void Cosmetic1D(TH1F * h);
void DrawCMS(bool is1D=false);


void Cosmetic1D(TH1F * h){
	h->SetLineWidth(2);
	h->SetStats(0);
	h->GetXaxis()->SetTitleSize(0.05);
	h->GetYaxis()->SetTitleSize(0.05);
	h->GetYaxis()->SetTitleOffset(0.9);
	h->GetXaxis()->SetTitleOffset(1.1);
	h->GetXaxis()->SetLabelSize(0.045);
	h->GetYaxis()->SetLabelSize(0.045);
}

void CosmeticMap(TH2F * map, TString branch){
	map->SetStats(0);
	map->SetTitle("");
	map->SetTitle(Form(";Events ;%s [GeV]",branch.Data()));
//	map->GetXaxis()->SetTitleOffset(0.95);
	map->GetXaxis()->SetTitleSize(0.05);
	map->GetYaxis()->SetTitleOffset(0.65);
	map->GetZaxis()->SetTitleOffset(0.8);
	map->GetYaxis()->SetTitleSize(0.05);
	map->GetZaxis()->SetTitleSize(0.055);
	
	map->GetZaxis()->SetLabelSize(0.045);


}

void DrawCMS(bool is1D){
	TLatex * tla = new TLatex();
    tla->SetTextSize(0.05);
	if(!is1D)tla->DrawLatexNDC(0.07,0.92,"#font[62]{CMS} #scale[0.8]{#font[52]{Preliminary}}");
	else tla->DrawLatexNDC(0.11,0.92,"#font[62]{CMS} #scale[0.8]{#font[52]{Preliminary}}");
}


