# Raw capture: Client_RecvInventoryUsePaint

| Field | Value |
|---|---|
| **Stable ID** | `aa_008095f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008095f0` |
| **Canonical name** | `Client_RecvInventoryUsePaint` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvInventoryUsePaint(int param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  
  piVar1 = Object_ResolveFromTFID((TFID_16 *)(unaff_EDI + 0x10));
  if (((piVar1 != (int *)0x0) && (*(int *)(piVar1[0x2a] + 0x38) == 0xe)) &&
     (iVar2 = (**(code **)(*piVar1 + 0x1d4))(), iVar2 != 0)) {
    if (*(char *)(unaff_EDI + 0x21) == '\0') {
      FUN_004faaf0(*(undefined1 *)(unaff_EDI + 0x20));
    }
    else if (*(char *)(unaff_EDI + 0x21) == '\x01') {
      FUN_004fab40(*(undefined1 *)(unaff_EDI + 0x20));
    }
    if (piVar1 == *(int **)(*(int *)(param_1 + 0xe98) + 0xcd0)) {
      FUN_0051f4e0(0);
    }
    FUN_004fcd80(0);
  }
  return;
}
```
