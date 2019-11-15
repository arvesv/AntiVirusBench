$msbuildexe = "c:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\MSBuild\15.0\Bin\MSBuild.exe"


$x = &$msbuildexe AntiVirusBench.sln  /t:Clean

Measure-Command { &$msbuildexe AntiVirusBench.sln  /t:Build }
