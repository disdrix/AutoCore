# Raw capture: FUN_0044cbd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044cbd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044cbd0` |
| **Canonical name** | `FUN_0044cbd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0044cbd0(undefined4 param_1)

{
  undefined1 *in_EAX;
  uint uVar1;
  undefined4 *unaff_ESI;
  undefined4 local_4;
  
  if (unaff_ESI[7] == 0) {
    local_4 = CONCAT31((int3)((uint)param_1 >> 8),*in_EAX);
    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&local_4,1);
    unaff_ESI[1] = unaff_ESI[1] | uVar1;
    return unaff_ESI[1];
  }
  local_4 = param_1;
  uVar1 = FUN_00767160(&DAT_00a9d718,*in_EAX);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  unaff_ESI[8] = 0;
  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  return unaff_ESI[1];
}
```
