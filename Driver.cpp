#include "Driver.h"

extern "C"
NTSTATUS
DriverEntry(
	IN PDRIVER_OBJECT  DriverObject,
	IN PUNICODE_STRING  RegistryPath
)
{
	UNREFERENCED_PARAMETER(RegistryPath);
	auto status = STATUS_SUCCESS;

	DriverObject->DriverUnload = DriverUnload;

	KdPrint(("[!] Driver loaded\n"));

	return status;
}

void
DriverUnload(
	PDRIVER_OBJECT DriverObject
)
{
	UNREFERENCED_PARAMETER(DriverObject);

	KdPrint(("[!] Driver unloaded\n"));
}