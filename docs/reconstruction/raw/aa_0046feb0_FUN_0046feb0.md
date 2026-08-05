# Raw capture: FUN_0046feb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046feb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0046feb0` |
| **Canonical name** | `FUN_0046feb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046feb0(double param_1)

{
  int in_EAX;
  int unaff_EDI;
  undefined4 local_c;
  
  if ((in_EAX != 0) && (unaff_EDI != 0)) {
    if (_DAT_00aaa610 < param_1) {
      FUN_00476d60();
      param_1 = _DAT_00aaa610;
    }
    *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 1;
    *(float *)(unaff_EDI + 0x28) = (float)param_1;
    local_c = (undefined4)(longlong)ROUND(_DAT_00aaa5e8 * param_1 + _DAT_00aaa5e0);
    *(undefined4 *)(unaff_EDI + 0xfc) = local_c;
    if (param_1 == _DAT_00aaa608) {
      FUN_00476d60();
    }
  }
  return;
}
```
