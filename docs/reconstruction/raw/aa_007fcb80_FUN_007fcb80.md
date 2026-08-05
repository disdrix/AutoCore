# Raw capture: FUN_007fcb80

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fcb80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fcb80` |
| **Canonical name** | `FUN_007fcb80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_007fcb80(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int unaff_ESI;
  
  if ((DAT_00d1b778 != (int *)0x0) &&
     (cVar3 = (**(code **)(*DAT_00d1b778 + 0x3d8))(), piVar2 = DAT_00d1d898, cVar3 != '\0')) {
    for (; piVar2 != DAT_00d1d89c; piVar2 = piVar2 + 1) {
      if (((*piVar2 != 0) && (iVar1 = *(int *)(*piVar2 + 0x534), iVar1 != 0)) &&
         (iVar1 == unaff_ESI)) {
        return *piVar2;
      }
    }
  }
  return 0;
}
```
