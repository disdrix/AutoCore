# Raw capture: FUN_0073ebf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073ebf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073ebf0` |
| **Canonical name** | `FUN_0073ebf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0073ebf0(void)

{
  int *piVar1;
  int unaff_ESI;
  
  operator_delete__(*(void **)(unaff_ESI + 0xc));
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  operator_delete__(*(void **)(unaff_ESI + 0x10));
  piVar1 = *(int **)(unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  if (piVar1 != (int *)0x0) {
    if (piVar1[-1] != 0) {
      (**(code **)(*piVar1 + 0x10))(3);
      *(undefined4 *)(unaff_ESI + 8) = 0;
      *(undefined4 *)(unaff_ESI + 0x14) = 0;
      return;
    }
    operator_delete__(piVar1 + -1);
  }
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  return;
}
```
