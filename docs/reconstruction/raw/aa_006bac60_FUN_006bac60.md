# Raw capture: FUN_006bac60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bac60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bac60` |
| **Canonical name** | `FUN_006bac60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006bac60(float *param_1,float *param_2)

{
  float *in_EAX;
  
  *in_EAX = *param_2 - *param_1;
  in_EAX[1] = param_2[1] - param_1[1];
  in_EAX[2] = param_2[2] - param_1[2];
  in_EAX[3] = param_2[3] - param_1[3];
  return;
}
```
