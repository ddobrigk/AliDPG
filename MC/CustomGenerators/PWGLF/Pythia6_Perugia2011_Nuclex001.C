AliGenerator *
GeneratorCustom()
{
    AliGenCocktail *ctl   = (AliGenCocktail*) GeneratorCocktail("Perugia2011_Nuclex001");
    AliGenerator   *pyt   = GeneratorPythia6(kPythia6Tune_Perugia2011);
    ctl->AddGenerator(pyt,  "Pythia6", 1.);
    AliGenerator   *nu1a  = Generator_Nuclex(0xF, kFALSE, 10);
    AliGenerator   *nu1b  = Generator_Nuclex(0xF, kTRUE, 10);
    AliGenerator   *nu2a  = Generator_Nuclex(0x10, kFALSE, 40);
    AliGenerator   *nu2b  = Generator_Nuclex(0x10, kTRUE, 40);
    AliGenerator   *nu3a  = Generator_Nuclex(0xFE0, kFALSE, 20);
    AliGenerator   *nu3b  = Generator_Nuclex(0xFE0, kTRUE, 20);
    ctl->AddGenerator(nu1a,  "Nuclex1a", 1.);
    ctl->AddGenerator(nu1b,  "Nuclex1b", 1.);
    ctl->AddGenerator(nu2a,  "Nuclex2a", 1.);
    ctl->AddGenerator(nu2b,  "Nuclex2b", 1.);
    ctl->AddGenerator(nu3a,  "Nuclex3a", 1.);
    ctl->AddGenerator(nu3b,  "Nuclex3b", 1.);
    return ctl;
}
