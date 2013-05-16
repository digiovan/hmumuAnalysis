import os
import sys
import glob

env = Environment(ENV = {'PATH':os.environ['PATH']} )

includes = []
libpath = []
libs = []
env.MergeFlags('-fPIC -O2 -lm')
#env.MergeFlags('-g')

# For BLINDING
####env.MergeFlags("-D BLIND")
env.MergeFlags("-D PTMISSINMVA")


# For using gprof
#env.Append(CCFLAGS=["-pg"])
#env.Append(LINKFLAGS=["-pg"])

includes.append("src/")

#boost
#includes.append("/usr/include/boost141")
#libpath.append("/usr/lib/boost141")
libs.append("boost_program_options")
libs.append("boost_regex")
libs.append("boost_filesystem")

#root
env.ParseConfig('root-config --cflags')
env.ParseConfig('root-config --libs')
libs.append("EG")
libs.append("TMVA")
libs.append("Minuit2")
libs.append("Minuit")
libs.append("MathMore")
libs.append("XMLIO")
libs.append("MLP")
libs.append("TreePlayer")

#Anna's Calibration Code & Corrections
doSmearing = True
doMuScleFit = True
doRochester = False
assert(not (doMuScleFit and doRochester))
smearFiles = ["annaCalibCode/FuncSmearingZmumu2012PtCorr0.C"] #For Vanilla 2012
smearFiles += ["annaCalibCode/FuncSmearingZmumu2011ChargePtCorr0.C"] #For Vanilla 2011
if doSmearing:
  env.MergeFlags("-D SMEARING")
if doMuScleFit:
  env.MergeFlags("-D MUSCLEFIT")
  smearFiles = ["annaCalibCode/FuncSmearingZmumu2012PtCorr2.C"] #For Muscle 2012
  smearFiles += ["annaCalibCode/FuncSmearingZmumu2011ChargePtCorr2.C"] #For Muscle 2011
if doRochester:
  env.MergeFlags("-D ROCHESTER")
  smearFiles = ["annaCalibCode/FuncSmearingZmumu2012PtCorr1.C"] #For Rochester 2012
includes.append("annaCalibCode/")

#Muon Corrections
corrFiles = ["rochester/rochcor2012.C",
            "rochester/rochcor.C"
        ]
includes.append("rochester/")
includes.append("musclefit/")

#MEKD
mekdSources = ["src/MEKD_Wrapper.cc"]+glob.glob("mekd/src/*.cpp")+glob.glob("mekd/src/*/*.cpp")+glob.glob("mekd/src/*/*.cc")+glob.glob("mekd/src/*/*.c")
includes += ["mekd/interface","mekd/src"]#,"mekd/Extra_code/","mekd/MadGraphSrc/","mekd/PDFTables/","mekd/higgs_properties/"]
env.MergeFlags("-D MEKD_STANDALONE")

env.Append(CPPPATH=includes)
env.Append(LIBPATH=libpath)
env.Append(LIBS=libs)

#Checking for things to exist (~autoConf)
if not env.GetOption("clean"):
  conf = Configure(env)
  if not conf.CheckCXX():
    print("Error: C++ Compiler Broken")
    Exit(1)
  if not conf.CheckSHCXX():
    print("Error: C++ Compiler Broken")
    Exit(1)
  if not conf.CheckLibWithHeader("Hist","TH1F.h","c++","TH1F h;"):
    print("Error: ROOT libs must be installed!")
    Exit(1)
  if not conf.CheckLibWithHeader("EG","TGenerator.h","c++","TGenerator g;"):
    print("Error: ROOT lib libEG.a must be installed!")
    Exit(1)
  if not conf.CheckLibWithHeader("TMVA",["TMVA/Tools.h"],"c++",'TMVA::Tools::Instance();'):
    print("Error: ROOT lib libTMVA.a must be installed!")
    Exit(1)
  if not conf.CheckCXXHeader("boost/lexical_cast.hpp"):
    print("Error: boost/lexical_cast.hpp header not installed!")
    Exit(1)
  if not conf.CheckCXXHeader("boost/algorithm/string.hpp"):
    print("Error: boost/algorithm/string.hpp header not installed!")
    Exit(1)
  if not conf.CheckCXXHeader("boost/program_options.hpp"):
    print("Error: boost/program_options.hpp header not installed!")
    Exit(1)
  if not conf.CheckLibWithHeader("boost_program_options","boost/program_options.hpp","c++",'boost::program_options::options_description optionDesc("options");'):
    print("Error: boost/program_options.hpp header and lib must be installed!")
    Exit(1)
  if not conf.CheckLibWithHeader("boost_regex","boost/regex.hpp","c++",'boost::regex re("aregex");'):
    print("Error: boost/regex.hpp header and lib must be installed!")
    Exit(1)
  if not conf.CheckLibWithHeader("boost_filesystem","boost/filesystem/operations.hpp","c++",'boost::filesystem::path p("p");'):
    print("Error: boost/filesystem.hpp header and lib must be installed!")
    Exit(1)
  env = conf.Finish()
 
env.Library(target="src/mva",source=["src/mva.cc"])
env.Library(target="src/helpers",source=["src/helpers.cc"])
mekd = env.Library(target="mekd/MEKD",source=mekdSources)
env.Program(target="analyzer", source=["analyzer.cc","src/libmva.a","src/libhelpers.a",mekd]+corrFiles+smearFiles)
#env.Program(target="systematics", source=["systematics.cc","src/libmva.a","src/libhelpers.a",mekd]+corrFiles+smearFiles)
env.Program(target="systematicsJets", source=["systematicsJets.cc","src/libmva.a","src/libhelpers.a",mekd]+corrFiles+smearFiles)
env.Program(target="mvaTrain", source=["mvaTrain.cc"])

env.Program(target="testVertex", source=["testVertex.cc","src/libmva.a","src/libhelpers.a",mekd])
env.Program(target="eventPrinter", source=["eventPrinter.cc","src/libmva.a","src/libhelpers.a",mekd])
env.Program(target="endpoint", source=["endpoint.cc","src/libhelpers.a"])
env.Program(target="skim", source=["skim.cc","src/libhelpers.a"])

#print env.Dump()
