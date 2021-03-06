AliGenerator *
GeneratorCustom()
{
  TString simulation = gSystem->Getenv("CONFIG_SIMULATION");
    
  AliGenCocktail *ctl =  (AliGenCocktail*) GeneratorCocktail("Hijing_Jpsiee001");
  
  if(!simulation.Contains("Embed")){
    AliGenerator *hij = GeneratorHijing();
    ctl->AddGenerator(hij, "Hijing", 1.);
  }
  
  if (uidConfig % 10 < 7) {
    AliGenerator *jpsi  = Generator_Jpsiee("PbPb 2.76", 1.0, 0.3, 0.3, 0.0);
    if(!simulation.Contains("Embed"))
      ctl->AddGenerator(jpsi, "Jpsi2ee", 1., new TFormula("ten", "10."));
    else
      ctl->AddGenerator(jpsi, "Jpsi2ee", 1.,0,10);
    TFile *file = new TFile("typeHF_4.proc", "recreate");
    file->Close();
  }
  else {
    AliGenerator *bjpsi = Generator_Jpsiee("Pythia BBar", 0.0, 0.0, 0.0, 1.0);
    if(!simulation.Contains("Embed"))
      ctl->AddGenerator(bjpsi, "B2Jpsi2ee", 1., new TFormula("ten", "10."));
    else
      ctl->AddGenerator(bjpsi, "B2Jpsi2ee", 1.,0,10);
    TFile *file = new TFile("typeHF_5.proc", "recreate");
    file->Close();
  }
  return ctl;
}
