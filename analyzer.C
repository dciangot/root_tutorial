void analyzer(){

    string filename = "input_data.csv";  

    TTree *lab_tree = new TTree("lab_tree", "Fit calcolo velocita");

    ct->ReadFile(filename.c_str(), "spazio/F:t_partenza/F:t_arrivo/F:e_t/F", ',');

    cout << endl;
    cout << " Il numero di rigehe letto dal file " << filename << "  e: " << ct->GetEntries() << endl;
    cout << endl;

    float t_partenza, t_arrivo, e_t;
    float spazio;

    ct->SetBranchAddress("Spazio",     &spazio);
    ct->SetBranchAddress("t_partenza",    &t_partenza);
    ct->SetBranchAddress("t_arrivo",       &t_arrivo);
    ct->SetBranchAddress("e_t",       &e_t);

    // Numero di righe
    int entries = ct->GetEntries();

    // definiamo i vettori che vogliamo mostrare
    float spazi[entries];
    float tempi[entries];
    float e_tempi[entries];
    float e_spazi[entries];

    for( int i=0; i<entries; i++){

        ct->GetEntry(i);

        cout << i << " " << spazio << endl;
        
        spazi[i] = spazio;

        cout << i << " " << t_arrivo - t_partenza << endl;

        tempi[i] = t_arrivo - t_partenza;

        e_tempi[i] = e_t;

        e_spazi[0] = 0;

    }


    TCanvas *c1 = new TCanvas("c1","Il mio grafico",200,10,700,500);

    TGraphErrors *gr = new TGraphErrors(entries,tempi,spazi,e_tempi,e_spazi);
    gr->SetTitle("TGraphErrors Example");
    gr->SetMarkerColor(4);
    gr->SetMarkerStyle(21);
    gr->Draw("ALP");
    gr->Fit("pol1");

    c1->Update();


}
