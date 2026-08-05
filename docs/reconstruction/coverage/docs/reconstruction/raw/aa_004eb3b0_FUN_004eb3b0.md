# Raw capture: FUN_004eb3b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eb3b0` |
| **Canonical name** | `FUN_004eb3b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004eb3b0(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *local_90;
  undefined1 local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2770;
  local_c = ExceptionList;
  if ((((*(int *)(param_1 + 0x88) == 0) && (iVar1 = *(int *)(param_1 + 0x3c), iVar1 != 0)) &&
      (iVar1 != -0x316)) && ((*(short *)(iVar1 + 0x316) != 0 && (*(short *)(iVar1 + 0x318) != 0))))
  {
    ExceptionList = &local_c;
    pvVar2 = operator_new(8);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004a1620();
    }
    *(undefined4 *)(param_1 + 0x88) = uVar3;
    local_4 = 0xffffffff;
    puVar4 = (undefined4 *)FUN_00402d50(*(int *)(param_1 + 0x3c) + 0x316);
    local_4 = 1;
    FUN_004a6390(*puVar4);
    if (local_90 != local_8c) {
      free(local_90);
    }
  }
  ExceptionList = local_c;
  return;
}
```
