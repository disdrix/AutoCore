# Raw capture: FUN_008e3bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e3bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008e3bd0` |
| **Canonical name** | `FUN_008e3bd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008e3bd0(void)

{
  int iVar1;
  int in_EAX;
  int *extraout_EAX;
  int unaff_ESI;
  int *unaff_EDI;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  if ((in_EAX != 0) && (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 0x1a)) {
    local_8 = *(undefined4 *)(*(int *)(in_EAX + 0xa8) + 0x34);
    Map_LowerBoundFindByIntKey((void *)(unaff_ESI + 0x7f4),local_4,&local_8,unaff_EDI);
    iVar1 = *extraout_EAX;
    *(int *)(unaff_ESI + 0x800) = iVar1;
    if (iVar1 != *(int *)(unaff_ESI + 0x7f8)) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
      if (*(int *)(*(int *)(unaff_ESI + 0x800) + 0x10) < 1) {
        FUN_0040ee20(local_4,*(int *)(unaff_ESI + 0x800));
      }
    }
  }
  return;
}
```
