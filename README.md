## PrimitiveDriverWDM

### Introduction
- [Debug Windows Drivers - Step by Step Lab (Echo Kernel-Mode)](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debug-universal-drivers---step-by-step-lab--echo-kernel-mode-)
- [The Windows Kernel Programming book samples by Pavel Yosifovich](https://github.com/zodiacon/windowskernelprogrammingbook)
- [Vergilius project - Collection of Microsoft Windows kernel structures, unions and enumerations](https://www.vergiliusproject.com/)

### Save compiled driver on *Debugee* machine

VisualStudio > Solution Explorer > "PrimitiveDriverWDM" > Properties > Configuratin Properties > Build Events > Post-Build Event > Command Line
```cmd
xcopy "$(SolutionDir)$(Platform)\$(Configuration)\$(ProjectName)" "\\<Debugee IP>\Driver\" /s /i /y
```

### Enable loading unsigned drivers

On *Debugee*
```cmd
bcdedit /set nointegritychecks on
bcdedit /set testsigning on
shutdown -r -t 0
```

### Attach the debugger

On *Debugee* onfigure WinDbg connection parameters:
 ```cmd
 cd "C:\Program Files (x86)\Windows Kits\10\Debuggers\x64"
 .\kdnet.exe <Debugger IP> <YourDebugPort>
 ```
 write down displayed connection string ("windbg -k net:port=50030,key=aaaaaaa") and reboot:
 ```cmd
 shutdown -r -t 0
 ```
 On *Debugger* "WinDbg Preview > File > Start debugging > Attach to Kernel" and pass the parameters from connection string.

### Load/Unload driver
```cmd
 sc.exe create PrimitiveDriverWDM type= kernel start= demand error= normal binPath= "C:\<path>\PrimitiveDriverWDM.sys" DisplayName= PrimitiveDriverWDM
 
 sc.exe start PrimitiveDriverWDM
 sc.exe query PrimitiveDriverWDM
 sc.exe stop PrimitiveDriverWDM
```

### Make KdPrint() messages visible in WinDbg Preview
```
kd> ed nt!Kd_Default_Mask 8
```

### Set breakpoint on driver load
```
kd> bu PrimitiveDriverWDM!DriverEntry
```
