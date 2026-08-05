# Raw capture: FUN_004e1ca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e1ca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e1ca0` |
| **Canonical name** | `FUN_004e1ca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004e1ca0(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  int local_4;
  
  local_4 = param_1;
  if (('\0' < *(char *)(param_1 + 0x1c)) && (*(char *)(param_1 + 0x1c) < '\x11')) {
    pvVar2 = operator_new__(*(int *)(param_1 + 8) * 4);
    *(void **)(param_1 + 0x10) = pvVar2;
    pvVar2 = malloc(*(int *)(param_1 + 8) * 0xc);
    uVar3 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        *(void **)(*(int *)(param_1 + 0x10) + uVar3 * 4) = pvVar2;
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar3 * 4);
        uVar3 = uVar3 + 1;
        *puVar1 = &PTR_LAB_009cc250;
        puVar1[1] = 0;
        puVar1[2] = 0;
        pvVar2 = (void *)((int)pvVar2 + 0xc);
      } while (uVar3 < *(uint *)(param_1 + 8));
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    return;
  }
  FUN_007a4480(0,"VOG_DEBUG_STOP");
  local_4 = -0x7fffbffd;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_4,(ThrowInfo *)&DAT_00acc430);
}
```
