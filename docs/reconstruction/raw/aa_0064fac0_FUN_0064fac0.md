# Raw capture: FUN_0064fac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064fac0` |
| **Canonical name** | `FUN_0064fac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall hkDefaultSteering_ctor(undefined4 *param_1,undefined4 param_2)

{
  FUN_0065e5f0(param_2);
  *param_1 = &PTR_FUN_009e4ee4;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0x80000000;
  FUN_0064f920(param_2);
  return param_1;
}
```
