# Annotated low-level: FUN_0079dbc0

| Field | Value |
|---|---|
| Stable ID | `aa_0079dbc0` |
| VA | `0x0079dbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0079dbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0079dbc0(void)

{
  char *in_EAX;
  char *pcVar1;
  int iVar2;
  
  pcVar1 = strrchr(in_EAX,0x2e);
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
  pcVar1 = pcVar1 + 1;
  iVar2 = _strnicmp(pcVar1,"jpg",0x104);
  if (iVar2 == 0) {
    return 1;
  }
  iVar2 = _strnicmp(pcVar1,"png",0x104);
  if (iVar2 == 0) {
    return 3;
  }
  iVar2 = _strnicmp(pcVar1,"dib",0x104);
  if (iVar2 == 0) {
    return 6;
  }
  iVar2 = _strnicmp(pcVar1,"hdr",0x104);
  if (iVar2 == 0) {
    return 7;
  }
  iVar2 = _strnicmp(pcVar1,"pfm",0x104);
  if (iVar2 == 0) {
    return 8;
  }
  iVar2 = _strnicmp(pcVar1,"tga",0x104);
  if (iVar2 == 0) {
    OutputDebugStringA("D3DXSaveSurfaceToFile 9.0c doesn\'t support TGA -- saving as bitmap.");
    return 0;
  }
  iVar2 = _strnicmp(pcVar1,"bmp",0x104);
  if (iVar2 != 0) {
    OutputDebugStringA("Unknown extension -- saving as bitmap.\n");
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
