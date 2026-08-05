# Raw capture: FUN_007ae2a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ae2a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ae2a0` |
| **Canonical name** | `FUN_007ae2a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_007ae2a0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  FUN_004294f0();
  iVar2 = FUN_00423f40(&local_8);
  iVar1 = local_8;
  while( true ) {
    local_8 = iVar1;
    if (iVar2 != 0) {
      if (DAT_00d1e848 != '\0') {
        DAT_00d1e848 = '\0';
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00d1e824);
      }
      return 0;
    }
    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_1)) break;
    iVar2 = FUN_00423f40(&local_8);
    iVar1 = local_8;
  }
  if (DAT_00d1e848 != '\0') {
    DAT_00d1e848 = '\0';
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00d1e824);
  }
  return *(undefined4 *)(iVar1 + 4);
}
```
