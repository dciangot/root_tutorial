void fit2D(){

    gStyle->SetOptFit(111);

    TH2F *hpxpy = new TH2F("hpxpy","py vs px",40,4,4,40,4,4);
    Double_t px, py;

    for (Int_t i=0; i<5000; i++){
        gRandom->Rannor(px,py);
        hpxpy->Fill(px,py);
    }
    hpxpy->Draw("col");

    /*

    // https://root.cern.ch/doc/master/classTH2.html#a19eb4ae4f4d399b0f4ad820d838de75e
    TH1D* profX = hpxpy->ProfileX();

    // https://root.cern.ch/doc/master/classTH2.html#a37dfa8181177e3a9d71274c0df9144f8
    TH1D* projX = hpxpy->ProjectionX();

    projX->Fit("gaus");

    projX->Draw();

    */
}
