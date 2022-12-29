# PrimitiveDriverWDM

## Enable loading unsigned drivers

On *Debugee*
```cmd
bcdedit /set nointegritychecks on
bcdedit /set testsigning on
shutdown -r -t 0
```

## Attach the debugger

On *Debugee* onfigure WinDbg connection parameters:
 ```cmd
 cd "C:\Program Files (x86)\Windows Kits\10\Debuggers\x64"
 .\kdnet.exe <HostComputerIPAddress> <YourDebugPort>
 ```
 write down displayed connection string ("windbg -k net:port=50030,key=aaaaaaa") and reboot:
 ```cmd
 shutdown -r -t 0
 ```
 On *Debugger* "WinDbgPreview > File > Start debugging > Attach to Kernel" and pass the parameters from connection string.
