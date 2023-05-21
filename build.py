import os
import json
import fileinput

_processorInfofile = open(r"./ProcessorInfo.json")
_processorInfoData = json.load(_processorInfofile)
for processor in _processorInfoData['Processor']:
     _processorToBuild = processor['Name']
     os.system("cmake  -G \"Unix Makefiles\" -DPROCESSOR=" + _processorToBuild +" -Bbuild-" + _processorToBuild.lower())
     os.system("cd build-"+_processorToBuild.lower()+" & make")
     os.system("cd ..")
