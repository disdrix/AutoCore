# Raw capture: FUN_004ed1a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ed1a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ed1a0` |
| **Canonical name** | `FUN_004ed1a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004ed1a0(undefined4 *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  puStack_8 = &LAB_009a28ec;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009ccf24;
  iVar1 = param_1[0xc];
  local_4 = 7;
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_10 = param_1;
  while (iVar1 != 0) {
    FUN_004eb010();
    iVar1 = param_1[0xc];
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if ((void *)param_1[0x21] != (void *)0x0) {
    operator_delete__((void *)param_1[0x21]);
  }
  uVar3 = 0;
  param_1[0x21] = 0;
  if (param_1[0x7c] != 0) {
    do {
      cVar2 = FUN_0050e770(uVar3,&local_10);
      if (cVar2 != '\0') {
        operator_delete__(local_10);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)param_1[0x7c]);
  }
  FUN_00410d60();
  param_1[0x73] = &PTR_FUN_009cccfc;
  FUN_00416c90();
  param_1[0x73] = &PTR_FUN_009ccc2c;
  FUN_00416c90();
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  FUN_005b2ba0();
  local_10 = param_1 + 0x24;
  local_4 = 8;
  FUN_004eaf30();
  local_4 = 0xffffffff;
  if (-1 < (int)param_1[0x2a]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x28],param_1[0x2a] << 4,0x12);
  }
  ExceptionList = local_c;
  return;
}
```
