# Raw capture: FUN_008a5dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a5dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a5dd0` |
| **Canonical name** | `FUN_008a5dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x008a5e73) */
/* WARNING: Removing unreachable block (ram,0x008a5e8a) */
/* WARNING: Removing unreachable block (ram,0x008a5e90) */
/* WARNING: Removing unreachable block (ram,0x008a5efc) */
/* WARNING: Removing unreachable block (ram,0x008a5f0f) */
/* WARNING: Removing unreachable block (ram,0x008a5ed5) */
/* WARNING: Removing unreachable block (ram,0x008a5f34) */
/* WARNING: Removing unreachable block (ram,0x008a5f66) */
/* WARNING: Removing unreachable block (ram,0x008a5f7d) */

void FUN_008a5dd0(int *param_1,int param_2)

{
  int iVar1;
  wchar_t *unaff_ESI;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b98d2;
  local_c = ExceptionList;
  local_4 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    ExceptionList = &local_c;
    (**(code **)(*param_1 + 0x1c))();
    iVar1 = _wcsicmp(L"MISSION_WINDOW",unaff_ESI);
    if (iVar1 == 0) {
      (**(code **)(*param_1 + 0x30))(param_1);
    }
    else {
      FUN_007933a0(param_1);
    }
    local_c = (void *)0xffffffff;
    SysFreeString(unaff_ESI);
    ExceptionList = pvStack_14;
    return;
  }
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  SysFreeString((BSTR)0x0);
  ExceptionList = local_c;
  return;
}
```
