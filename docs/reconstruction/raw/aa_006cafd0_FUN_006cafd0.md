# Raw capture: FUN_006cafd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cafd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cafd0` |
| **Canonical name** | `FUN_006cafd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006cafd0(int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int local_4;
  
  puVar1 = (undefined4 *)(param_1 + 0x118c);
  puVar2 = (undefined1 *)(param_1 + 0x418e);
  local_4 = 0x20;
  do {
    iVar3 = 0x20;
    do {
      puVar1[-0x400] = *(undefined4 *)(param_1 + 8);
      *puVar1 = FUN_0056f570;
      puVar1[0x400] = FUN_0056f570;
      puVar1[0x800] = FUN_0056f570;
      *puVar2 = 100;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}
```
