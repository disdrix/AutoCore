# Raw capture: FUN_0096feb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096feb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096feb0` |
| **Canonical name** | `FUN_0096feb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0096feb0(int param_1)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int unaff_EDI;
  
  cVar2 = FUN_0096fdf0();
  iVar1 = *in_EAX;
  if (param_1 < 0) {
    if ((cVar2 != '\0') && (iVar1 != 0)) {
      iVar3 = *(int *)(iVar1 + 0x18);
      if (*(int *)(iVar1 + 0x18) == 0) {
        iVar3 = iVar1;
      }
      if (iVar3 != iVar1) {
        FUN_00448fc0(iVar3);
      }
    }
    return 0xffffffff;
  }
  if (0xf < *(uint *)(unaff_EDI + 0x18)) {
    FUN_00752800(param_1);
    return 0;
  }
  FUN_00752800(param_1);
  return 0;
}
```
