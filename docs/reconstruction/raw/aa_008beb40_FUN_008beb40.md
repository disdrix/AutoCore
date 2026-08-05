# Raw capture: FUN_008beb40

| Field | Value |
|---|---|
| **Stable ID** | `aa_008beb40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008beb40` |
| **Canonical name** | `FUN_008beb40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_008beb40(ushort param_1)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  
  if (*(int *)(in_EAX + 0x52c) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_EAX + 0x530) - *(int *)(in_EAX + 0x52c) >> 3;
  }
  iVar1 = *(int *)(in_EAX + 0x52c);
  if (uVar2 <= param_1) {
    if ((iVar1 != 0) && (*(int *)(in_EAX + 0x530) - iVar1 >> 3 != 0)) {
      if (iVar1 == 0) {
        return uRamfffffffc;
      }
      return *(undefined4 *)
              (*(int *)(in_EAX + 0x52c) + (*(int *)(in_EAX + 0x530) - iVar1 >> 3) * 8 + -4);
    }
    return 0;
  }
  return *(undefined4 *)(iVar1 + (uint)param_1 * 8 + 4);
}
```
