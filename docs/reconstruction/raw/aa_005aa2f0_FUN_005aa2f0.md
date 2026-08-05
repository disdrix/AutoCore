# Raw capture: FUN_005aa2f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aa2f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005aa2f0` |
| **Canonical name** | `FUN_005aa2f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
