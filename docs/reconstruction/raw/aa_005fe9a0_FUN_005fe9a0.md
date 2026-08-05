# Raw capture: FUN_005fe9a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe9a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe9a0` |
| **Canonical name** | `FUN_005fe9a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005fe9a0(int param_1,float param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  
  if ((param_2 <= DAT_009c8354) || (DAT_009d2f7c <= param_2)) {
    psVar1 = (short *)(param_1 + 0xb6);
    iVar3 = 6;
    do {
      sVar2 = (short)(int)((float)(int)*psVar1 * param_2);
      *psVar1 = sVar2;
      if (sVar2 < 0) {
        *psVar1 = 0;
      }
      psVar1 = psVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}
```
