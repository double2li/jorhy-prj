##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PSStream
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug/plugins
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jorhy/WorkSpace/jorhy-prj/codelite/joiss"
ProjectPath            := "/home/jorhy/WorkSpace/jorhy-prj/codelite/joiss"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=01/23/2013
CodeLitePath           :="/home/jorhy/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
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
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).so
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../src/core" "$(IncludeSwitch)../../src/misc" "$(IncludeSwitch)../../src/utils" "$(IncludeSwitch)../../src/output_stream/ps" 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/ps_PsMux$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug/plugins || $(MakeDirCommand) ./Debug/plugins

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ps_PsMux$(ObjectSuffix): ../../src/stream_output/ps/PsMux.cpp $(IntermediateDirectory)/ps_PsMux$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jorhy/WorkSpace/jorhy-prj/src/stream_output/ps/PsMux.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ps_PsMux$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ps_PsMux$(DependSuffix): ../../src/stream_output/ps/PsMux.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/ps_PsMux$(ObjectSuffix) -MF$(IntermediateDirectory)/ps_PsMux$(DependSuffix) -MM "/home/jorhy/WorkSpace/jorhy-prj/src/stream_output/ps/PsMux.cpp"

$(IntermediateDirectory)/ps_PsMux$(PreprocessSuffix): ../../src/stream_output/ps/PsMux.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ps_PsMux$(PreprocessSuffix) "/home/jorhy/WorkSpace/jorhy-prj/src/stream_output/ps/PsMux.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/ps_PsMux$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ps_PsMux$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ps_PsMux$(PreprocessSuffix)
	$(RM) $(OutputFile)

