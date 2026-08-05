# Annotated low-level: FUN_005aa2f0

| Field | Value |
|---|---|
| Stable ID | `aa_005aa2f0` |
| VA | `0x005aa2f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005aa2f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x005aa3f5) */
/* WARNING: Removing unreachable block (ram,0x005aa413) */
/* WARNING: Removing unreachable block (ram,0x005aa420) */
/* WARNING: Removing unreachable block (ram,0x005aa4a2) */
/* WARNING: Removing unreachable block (ram,0x005aa4b5) */
/* WARNING: Removing unreachable block (ram,0x005aa45d) */
/* WARNING: Removing unreachable block (ram,0x005aa4ff) */
/* WARNING: Removing unreachable block (ram,0x005aa501) */
/* WARNING: Removing unreachable block (ram,0x005aa50b) */
/* WARNING: Removing unreachable block (ram,0x005aa522) */
/* WARNING: Removing unreachable block (ram,0x005aa523) */

void FUN_005aa2f0(int *param_1)

{
  char cVar1;
  int iVar2;
  BSTR unaff_ESI;
  int iStack_128;
  int iStack_120;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a649b;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 0x44))();
  if ((iVar2 == 0) && (iStack_120 != 0)) {
    cVar1 = FUN_00799460();
    if (cVar1 == '\0') {
      FUN_0076cec0();
      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1b5);
    }
    else if ((iStack_128 < 8) && (-1 < iStack_128)) {
      (**(code **)(*param_1 + 0x30))();
      FUN_0076cec0();
      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1c8);
    }
    else {
      FUN_0076cec0();
      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1be,3);
    }
  }
  else {
    FUN_0076cec0();
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp",0x1ab);
  }
  SysFreeString(unaff_ESI);
  ExceptionList = pvStack_14;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
