# Raw capture: FUN_006c6bf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c6bf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c6bf0` |
| **Canonical name** | `FUN_006c6bf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006c6bf0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(param_1 + 0x1c);
  iVar3 = 0x20;
  puVar2 = param_2;
  do {
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  return;
}
```
