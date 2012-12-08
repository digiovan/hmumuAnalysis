#include <algorithm>
#include <limits.h>
#include <ctime>
#include "boost/program_options.hpp"
#include "boost/regex.hpp"
#include <boost/lexical_cast.hpp>
//Defines method of std::string that appends any type :-)
#define appendAny(a) append(boost::lexical_cast<std::string>(a))

#include <TSystem.h>
#include <TROOT.h>
#include <TClonesArray.h>
#include <TParticle.h>
#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TH2F.h>
#include <TH1F.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TF1.h>
#include <TRandom3.h>
#include "DataFormats.h"

using namespace std;
using namespace boost;

typedef void* voidp;

int main(int argc, char *argv[])
{
  /////////////////////////////////////////////
  //////////// Configuration Options //////////
  /////////////////////////////////////////////

  gErrorIgnoreLevel = kError;
  time_t timeStart = time(NULL);

  const char* optionIntro = "UF Skimmer\n\nUsage: ./skim [--help] [-c \"Cut string\"] [-m MaxEvents] <outputFileName.root> <inputFileName.root> [<inputFileName2.root>...]\n\nAllowed Options";
  program_options::options_description optionDesc(optionIntro);
  optionDesc.add_options()
      ("help,h", "Produce Help Message")
      ("filenames",program_options::value<vector<string> >(), "Input & Output File Names, put output name first followed by all input file names")
      ("cut,c",program_options::value<string>(), "ROOT Cut String")
      ("maxEvents,m",program_options::value<Long64_t>(), "Max Number of Events")
  ;
  
  program_options::positional_options_description optionPos;
  optionPos.add("filenames",-1);
  
  program_options::variables_map optionMap;
  program_options::store(program_options::command_line_parser(argc, argv).options(optionDesc).positional(optionPos).run(), optionMap);
  program_options::notify(optionMap);    
  
  if (optionMap.count("help")) 
  {
      cout << optionDesc << "\n";
      return 1;
  }

  std::string cut = "";
  if (optionMap.count("cut")) 
  {
    cut = optionMap["cut"].as<string>();
  }

  Long64_t maxEvents = 1000000000;
  if (optionMap.count("maxEvents")) 
  {
    maxEvents = optionMap["maxEvents"].as<Long64_t>();
  }

  std::vector<std::string> filenames;
  vector<string>::const_iterator filename;
  std::string outputFileName;
  if (optionMap.count("filenames")>0)
  {
     filenames = optionMap["filenames"].as<vector<string> >();
     if(filenames.size()<2)
     {
       cout << "Error: Need both input file and output file names, exiting." << endl;
       return 1;
     }
     outputFileName = filenames[0];
     filenames.erase(filenames.begin());
  }
  else
  {
     cout << "Error: Input file name  and ouput file name arguments required, exiting." << endl;
     return 1;
  }

  TChain * tree = new TChain("tree");

  cout << "Input File Names: \n"; 
  for(filename = filenames.begin();filename != filenames.end();filename++)
  {
    cout<<"  "<< *filename << endl;
    tree->AddFile(filename->c_str());
  }

  //std::vector<voidp> branchAddressPointers;
  TIter branchList(tree->GetListOfBranches());
  TBranch* tmpBranch;
  while (tmpBranch = (TBranch*) branchList())
  {
    //voidp tmp = 0; //I Allocate, but Root Owns
    tree->SetBranchAddress(tmpBranch->GetName(),0);//Root handles objects
    //tree->SetBranchAddress(tmpBranch->GetName(),&tmp);//I Own Objects
    //branchAddressPointers.append(tmp)
  }

  cout << "Output File Name: " << outputFileName << endl;
  TFile * outFile = new TFile(outputFileName.c_str(),"RECREATE");

  TTree *newtree = tree->CopyTree(cut.c_str(),"",maxEvents);
  newtree->SetAutoSave(true);
  outFile->Write();

  float efficiency = ((float) newtree->GetEntries())/(float) std::min(tree->GetEntries(),maxEvents);
  std::cout <<"Events Pass: "<<efficiency*100.0<<"%"<<std::endl;

  return 0;
}
