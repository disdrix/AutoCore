# Raw capture: hkAngularVelocityDamper_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064d900` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064d900` |
| **Canonical name** | `hkAngularVelocityDamper_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall hkAngularVelocityDamper_ctor(undefined4 *param_1,undefined4 *param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009e4a68;
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  return;
}
```
