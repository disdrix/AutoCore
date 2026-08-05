# Raw capture: FUN_007ac5d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ac5d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ac5d0` |
| **Canonical name** | `FUN_007ac5d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007ac687) */
/* WARNING: Removing unreachable block (ram,0x007ac695) */
/* WARNING: Removing unreachable block (ram,0x007ac6b1) */
/* WARNING: Removing unreachable block (ram,0x007ac6d9) */
/* WARNING: Removing unreachable block (ram,0x007ac751) */
/* WARNING: Removing unreachable block (ram,0x007ac7cd) */
/* WARNING: Removing unreachable block (ram,0x007ac846) */
/* WARNING: Removing unreachable block (ram,0x007ac859) */
/* WARNING: Removing unreachable block (ram,0x007ac88d) */
/* WARNING: Removing unreachable block (ram,0x007ac89d) */
/* WARNING: Removing unreachable block (ram,0x007ac8ab) */
/* WARNING: Removing unreachable block (ram,0x007ac8a5) */
/* WARNING: Removing unreachable block (ram,0x007ac7e0) */
/* WARNING: Removing unreachable block (ram,0x007ac814) */
/* WARNING: Removing unreachable block (ram,0x007ac824) */
/* WARNING: Removing unreachable block (ram,0x007ac835) */
/* WARNING: Removing unreachable block (ram,0x007ac82c) */
/* WARNING: Removing unreachable block (ram,0x007ac764) */
/* WARNING: Removing unreachable block (ram,0x007ac798) */
/* WARNING: Removing unreachable block (ram,0x007ac7a8) */
/* WARNING: Removing unreachable block (ram,0x007ac7b9) */
/* WARNING: Removing unreachable block (ram,0x007ac7b0) */
/* WARNING: Removing unreachable block (ram,0x007ac6e8) */
/* WARNING: Removing unreachable block (ram,0x007ac71c) */
/* WARNING: Removing unreachable block (ram,0x007ac72c) */
/* WARNING: Removing unreachable block (ram,0x007ac73d) */
/* WARNING: Removing unreachable block (ram,0x007ac734) */
/* WARNING: Removing unreachable block (ram,0x007ac8ba) */
/* WARNING: Removing unreachable block (ram,0x007ac8c4) */
/* WARNING: Removing unreachable block (ram,0x007ac8d9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ac5d0(undefined4 param_1,int *param_2)

{
  BSTR unaff_retaddr;
  undefined4 uVar1;
  undefined4 uStack_3c;
  int *piStack_24;
  int *piStack_1c;
  void *local_14;
  int *piStack_10;
  BSTR pOStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ac3e9;
  pOStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pOStack_c;
  (**(code **)(*param_2 + 0x30))();
  if (piStack_1c == (int *)0x0) {
    uStack_3c = 0x7ac62b;
    SysFreeString(unaff_retaddr);
    ExceptionList = local_14;
    return;
  }
  (**(code **)(*piStack_1c + 0x20))();
  (**(code **)(*piStack_24 + 8))(piStack_24);
  if (puStack_8 == (undefined1 *)0x0) {
    uVar1 = 0;
  }
  else if (puStack_8 == (undefined1 *)0x1) {
    uVar1 = 1;
  }
  else {
    if (puStack_8 != (undefined1 *)0x2) goto LAB_007ac91b;
    uVar1 = 2;
  }
  (**(code **)(*piStack_10 + 0x15c))(uVar1,&uStack_3c);
LAB_007ac91b:
  SysFreeString(pOStack_c);
  ExceptionList = (void *)0x0;
  return;
}
```
