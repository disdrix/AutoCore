# Annotated low-level: FUN_0092dbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0092dbb0` |
| VA | `0x0092dbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0092dbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
