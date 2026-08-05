# Raw capture: FUN_007fb9e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb9e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb9e0` |
| **Canonical name** | `FUN_007fb9e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fb9e0(void)

{
  char cVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(int *)(unaff_ESI + 0x1144) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();
    if ((cVar1 != '\0') && (unaff_EDI != 0)) {
      uVar3 = 1;
      uVar2 = 1;
      (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x1d8))();
      (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x13c))();
                    /* WARNING: Could not recover jumptable at 0x007fba28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x34c))(uVar2,uVar3);
      return;
    }
  }
  return;
}
```
