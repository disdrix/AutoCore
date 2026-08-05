# Raw capture: FUN_004bfa80

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfa80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bfa80` |
| **Canonical name** | `FUN_004bfa80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004bfa80(int param_1)

{
  int iVar1;
  undefined4 local_a4 [34];
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a191b;
  local_1c = ExceptionList;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;
  ExceptionList = &local_1c;
  FUN_005c6b40(param_1,iVar1 + 0x84,iVar1 + 0x94,1,0,0);
  local_14 = 0;
  local_a4[0] = DAT_00aaaafc;
  FUN_005c7df0(local_a4,1);
  local_14 = 0xffffffff;
  FUN_005c7be0();
  ExceptionList = local_1c;
  return;
}
```
