# Raw capture: FUN_007f9df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007f9df0` |
| **Canonical name** | `FUN_007f9df0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007f9df0(undefined4 param_1)

{
  int in_EAX;
  int *unaff_EDI;
  undefined4 local_4;
  
  local_4 = param_1;
  if (in_EAX == 0) {
    if (*(char *)((int)unaff_EDI + 0x489) == '\0') {
      (**(code **)(*unaff_EDI + 0x15c))(0,unaff_EDI + 0x139);
      (**(code **)(*unaff_EDI + 0x34c))();
    }
  }
  else if ((in_EAX == 5) && (*(char *)((int)unaff_EDI + 0x489) == '\0')) {
    local_4 = 0xffff0000;
    (**(code **)(*unaff_EDI + 0x15c))(0,&local_4);
    (**(code **)(*unaff_EDI + 0x34c))();
  }
  unaff_EDI[0x13a] = 0;
  unaff_EDI[0x13b] = in_EAX;
  if (unaff_EDI[0x13c] != (&DAT_00afa098)[in_EAX]) {
    FUN_007f9cc0();
  }
  return;
}
```
