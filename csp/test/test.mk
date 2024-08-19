##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=test
ConfigurationName      :=Debug
WorkspacePath          :=/home/csp/Documents/c++
ProjectPath            :=/home/csp/Documents/c++/test
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=04/11/21
CodeLitePath           :=/home/csp/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="test.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/1.cpp$(ObjectSuffix) $(IntermediateDirectory)/2.cpp$(ObjectSuffix) $(IntermediateDirectory)/3.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/1.cpp$(ObjectSuffix): 1.cpp $(IntermediateDirectory)/1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/csp/Documents/c++/test/1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/1.cpp$(DependSuffix): 1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/1.cpp$(DependSuffix) -MM 1.cpp

$(IntermediateDirectory)/1.cpp$(PreprocessSuffix): 1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/1.cpp$(PreprocessSuffix) 1.cpp

$(IntermediateDirectory)/2.cpp$(ObjectSuffix): 2.cpp $(IntermediateDirectory)/2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/csp/Documents/c++/test/2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/2.cpp$(DependSuffix): 2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/2.cpp$(DependSuffix) -MM 2.cpp

$(IntermediateDirectory)/2.cpp$(PreprocessSuffix): 2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/2.cpp$(PreprocessSuffix) 2.cpp

$(IntermediateDirectory)/3.cpp$(ObjectSuffix): 3.cpp $(IntermediateDirectory)/3.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/csp/Documents/c++/test/3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/3.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/3.cpp$(DependSuffix): 3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/3.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/3.cpp$(DependSuffix) -MM 3.cpp

$(IntermediateDirectory)/3.cpp$(PreprocessSuffix): 3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/3.cpp$(PreprocessSuffix) 3.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


