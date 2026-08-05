# Raw capture: FUN_006f3ec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f3ec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f3ec0` |
| **Canonical name** | `FUN_006f3ec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006f3ec0(int *param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1 + -1;
  if (3 < *param_1) {
    do {
      piVar1 = (int *)(param_1[2] + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      *param_1 = *param_1 + -1;
      piVar1 = (int *)(param_1[2] + -4 + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      *param_1 = *param_1 + -1;
      piVar1 = (int *)(param_1[2] + -8 + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      *param_1 = *param_1 + -1;
      piVar1 = (int *)(param_1[2] + -0xc + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      iVar2 = iVar2 + -4;
      *param_1 = *param_1 + -1;
    } while (2 < iVar2);
  }
  while( true ) {
    if (iVar2 < 0) {
      return;
    }
    piVar1 = (int *)(param_1[2] + iVar2 * 4);
    if (*piVar1 == 0) break;
    if (param_2 <= *(float *)(*piVar1 + 0xc)) {
      return;
    }
    param_1[3] = *piVar1;
    *piVar1 = 0;
    iVar2 = iVar2 + -1;
    *param_1 = *param_1 + -1;
  }
  return;
}
```
