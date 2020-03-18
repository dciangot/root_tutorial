void 2D(){

    TH2F *hpxpy = new TH2F("hpxpy","py vs px",40,4,4,40,4,4);
    Double_t px, py;

    for (Int_t i=0; i<50000; i++){
        gRandom->Rannor(px,py);
        hpxpy->Fill(px,py);
        hpx->Fill(px);
        hpy->Fill(py);
    }
    hpxpy->Draw("col");
}