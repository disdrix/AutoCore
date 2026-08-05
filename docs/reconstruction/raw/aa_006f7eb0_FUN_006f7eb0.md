# Raw capture: FUN_006f7eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f7eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f7eb0` |
| **Canonical name** | `FUN_006f7eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006f7eb0(int param_1,undefined1 *param_2,short *param_3)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = *(int *)(param_1 + 0x54) + -1;
  if (-1 < iVar1) {
    psVar2 = (short *)(param_1 + 0x22 + iVar1 * 6);
    do {
      if ((psVar2[-1] == *param_3) && (*psVar2 == param_3[1])) {
        *param_2 = 1;
        return;
      }
      iVar1 = iVar1 + -1;
      psVar2 = psVar2 + -3;
    } while (-1 < iVar1);
  }
  *param_2 = 0;
  return;
}
```
