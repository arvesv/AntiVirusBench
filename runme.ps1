$msbuildexe = "c:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\MSBuild\15.0\Bin\MSBuild.exe"


Measure-Command { 
    For ($i=0; $i -le 5; $i++) {
        &$msbuildexe AntiVirusBench.sln  /t:Clean
        &$msbuildexe AntiVirusBench.sln  /t:Build
    }
}
