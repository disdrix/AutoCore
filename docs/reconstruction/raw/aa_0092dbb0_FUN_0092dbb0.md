# Raw capture: FUN_0092dbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092dbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092dbb0` |
| **Canonical name** | `FUN_0092dbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0092dbb0(void)

{
  char *lpLibFileName;
  HMODULE hModule;
  FARPROC pFVar1;
  int unaff_ESI;
  _OSVERSIONINFOA local_94;
  
  local_94.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_94);
  lpLibFileName = "libInput2k.dll";
  if (local_94.dwMinorVersion != 0) {
    lpLibFileName = "libInputXP.dll";
  }
  hModule = LoadLibraryA(lpLibFileName);
  *(HMODULE *)(unaff_ESI + 0xdc4) = hModule;
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,(LPCSTR)0x6);
    *(FARPROC *)(unaff_ESI + 0xdc8) = pFVar1;
    if (pFVar1 != (FARPROC)0x0) {
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x8);
      *(FARPROC *)(unaff_ESI + 0xdcc) = pFVar1;
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x2);
      *(FARPROC *)(unaff_ESI + 0xdd0) = pFVar1;
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x7);
      *(FARPROC *)(unaff_ESI + 0xdd4) = pFVar1;
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x1);
      *(FARPROC *)(unaff_ESI + 0xdd8) = pFVar1;
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x3);
      *(FARPROC *)(unaff_ESI + 0xddc) = pFVar1;
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x4);
      *(FARPROC *)(unaff_ESI + 0xde0) = pFVar1;
      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x5);
      *(FARPROC *)(unaff_ESI + 0xde4) = pFVar1;
      (**(code **)(unaff_ESI + 0xdc8))(unaff_ESI + 0x9cc,"joy_custom.ini");
      return;
    }
    FreeLibrary(*(HMODULE *)(unaff_ESI + 0xdc4));
    *(undefined4 *)(unaff_ESI + 0xdc4) = 0;
  }
  return;
}
```
