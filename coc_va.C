// ROOT MACRO TO COMPARE THE DISTRIBUTION random()/random()
// WITH THE FUNCTION p0/(2*x*(x+1))
// Author: Felipe Ortega
// 30th December 2015


// the function has 2 parameters
// fun: defines which of the 3 options of the macro will run

// fun=1, will display the distribution of random()/random() 
// fitted with the function p0/(2*x*(x+1)).
// note in this case the parameter big is of no interest.

// fun=2, will display the distribution without the fit,
// big=n, will make the distribution to be divided from 0 up 
// to n, by default is 30.

// fun=3, will display the graph of the mean of the distribution
// versus the xmax used to store the distribution
// the plots begins in 0 and ends in big(by default 30).

void coc_va(int fun,int big=30){
if (fun==1){
TCanvas* a=new TCanvas("dist","dist",960,600);
a->SetGrid();
TH1I*va=new TH1I("Info","",30,-0.5,29.5);
for(int i=0; i<10000000; i++){
  va->Fill(random()/random());
}
va->Draw();
gPad->Update();
gStyle->SetOptStat("nem");
TPaveStats* stats=(TPaveStats*)va->FindObject("stats");
TF1 * f1 = new TF1("f1","[0]/(2*x*(x+1))",-0.5,30);
va->Fit(f1,"","",0.5,30);
gStyle->SetOptFit(101);

}else if(fun==2){
TCanvas* b=new TCanvas("dist1","dist1",960,600);
b->SetGrid();
TH1I*va1=new TH1I("Info","",big,-0.5,big-0.5);
for(int i=0; i<10000000; i++){
  va1->Fill(random()/random());
}
va1->Draw();
}else if(fun==3){
TH1I*va=new TH1I("Info","",1,-0.5,0.5);
TGraph*mean=new TGraph();
for(int i=1; i<big;i++){
  for(int j=0; j<10000000; j++){
    va->Fill(random()/random());
  }
  mean->SetPoint(i,i,va->GetMean());
  va->Delete();
  va= new TH1I("Info","",i+1,-0.5,i+0.5);
}
mean->Draw("AL");

}
}
