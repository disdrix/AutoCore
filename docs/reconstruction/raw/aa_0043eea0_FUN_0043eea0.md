# Raw capture: FUN_0043eea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043eea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043eea0` |
| **Canonical name** | `FUN_0043eea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0043eea0(void)

{
  int iVar1;
  undefined4 in_EAX;
  int *piVar2;
  int *unaff_EDI;
  int local_4;
  
  piVar2 = &local_4;
  if (*unaff_EDI == 0) {
    local_4 = -1;
  }
  else {
    piVar2 = (int *)FUN_00752370(&local_4,in_EAX);
  }
  iVar1 = *piVar2;
  if (-1 < iVar1) {
    FUN_0096fdf0();
    FUN_00752800(iVar1);
    return 0;
  }
  return 1;
}
```
