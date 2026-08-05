# Raw capture: FUN_008fbaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008fbaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008fbaf0` |
| **Canonical name** | `FUN_008fbaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008fbaf0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1dc))();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(unaff_ESI + 0x660);
    uVar2 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1dc))(uVar3);
    FUN_00933d60(&DAT_00d1a840,uVar2,uVar3);
  }
  FUN_007fca10();
  return;
}
```
