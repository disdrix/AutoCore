# Raw capture: FUN_006ef5b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ef5b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ef5b0` |
| **Canonical name** | `FUN_006ef5b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006ef5b0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_006cde50(param_2);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar3 = (undefined4 *)(param_1 + 0x18);
    do {
      if (*(uint *)(param_2 + 8) == (*(uint *)(param_2 + 0xc) & 0x7fffffff)) {
        FUN_005b3370((int *)(param_2 + 4),0x10);
      }
      puVar1 = (undefined4 *)(*(int *)(param_2 + 8) * 0x10 + *(int *)(param_2 + 4));
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      *puVar1 = puVar3[-2];
      puVar1[1] = puVar3[-1];
      puVar1[2] = *puVar3;
      puVar1[3] = puVar3[1];
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar2 < *(int *)(param_1 + 0xc));
  }
  return;
}
```
