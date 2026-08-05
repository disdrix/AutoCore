# Raw capture: FUN_0060bed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060bed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060bed0` |
| **Canonical name** | `FUN_0060bed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_0060bed0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x14);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    puVar1 = (undefined4 *)(iVar3 + 8);
    puVar2 = (undefined4 *)(iVar3 + 0x10);
    iVar3 = *(int *)(iVar3 + 0x14);
    iVar4 = FUN_0060bf10(*puVar2,*puVar1,0);
  } while (-1 < iVar4);
  return iVar4;
}
```
