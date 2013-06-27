#include <iostream>
#include <TChain.h>
#include <TClonesArray.h>
#include <TString.h>
#include <map>
#include <TSystem.h>
#include <TROOT.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TRandom3.h>
#include "TF1.h"
#include <stdio.h>
#include <math.h>
// class init
class SmearingTool {
 public:
  //SmearingTool();
  //SmearingTool(int seed);
  SmearingTool();
  float PTsmear(float PTmuonGen, float ETAmuonGen, float CHARGEmuonGen, float PTmuonReco, int Ismear, float ParSig = 0, TString ParVar = "null");

 private:
  static const float mean[104];
  static const float sig1[104];
  static const float sig2[104];
  static const float Asig2[104];
  static const float ERRmean[104];
  static const float ERRsig1[104];
  static const float ERRsig2[104];
  static const float ERRAsig2[104];
  static const float ResRMS[104];
  static const float ErrResRMS[104];

  static const float meanMuPlus[104];
  static const float sig1MuPlus[104];
  static const float sig2MuPlus[104];
  static const float Asig2MuPlus[104];
  static const float ERRmeanMuPlus[104];
  static const float ERRsig1MuPlus[104];
  static const float ERRsig2MuPlus[104];
  static const float ERRAsig2MuPlus[104];
  static const float ResRMSMuPlus[104];
  static const float ErrResRMSMuPlus[104];

  static const float PTbin[14];
  static const float ETAbin[9];

};
// end: class init

