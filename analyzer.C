void analyzer(){

    string filename = "input_data.csv";  

    TTree *lab_tree = new TTree("lab_tree", "Fit calcolo velocita");

    lab_tree->ReadFile(filename.c_str(), "spazio:t_partenza:t_arrivo:e_s", ',');

    cout << endl;
    cout << " Il numero di rigehe letto dal file " << filename << "  e: " << lab_tree->GetEntries() << endl;
    cout << endl;

    /*
    float t_partenza = 0, t_arrivo = 0;
    float spazio = 0, e_s = 0;

    lab_tree->SetBranchAddress("spazio",     &spazio);
    lab_tree->SetBranchAddress("t_partenza",    &t_partenza);
    lab_tree->SetBranchAddress("t_arrivo",       &t_arrivo);
    lab_tree->SetBranchAddress("e_s",       &e_s);

    // Numero di righe
    int entries = lab_tree->GetEntries();

    // definiamo i vettori che vogliamo mostrare
    float spazi[entries];
    float tempi[entries];
    float e_tempi[entries];
    float e_spazi[entries];

    for( int i=0; i<entries; i++){

        lab_tree->GetEntry(i);

        cout << i << " " << spazio << endl;
        
        spazi[i] = spazio;

        cout << i << " " << t_arrivo << " "<<  t_partenza << endl;
        cout << i << " " << t_arrivo - t_partenza << endl;

        tempi[i] = t_arrivo - t_partenza;

        e_spazi[i] = e_s;

        e_tempi[0] = 0;

    }


    TCanvas *c1 = new TCanvas("c1","Il mio grafico",200,10,700,500);

    TGraphErrors *gr = new TGraphErrors(entries,tempi,spazi,e_tempi,e_spazi);
    //https://root.cern.ch/doc/master/classTPaveStats.html
    gStyle->SetOptFit(111);

    gr->SetTitle("TGraphErrors Example");
    gr->SetMarkerColor(4);
    gr->SetMarkerStyle(21);
    gr->Draw("AP");
    gr->Fit("pol1");

    c1->Update();

    */
}
