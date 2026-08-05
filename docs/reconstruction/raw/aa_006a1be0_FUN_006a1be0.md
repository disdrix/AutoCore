# Raw capture: FUN_006a1be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a1be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a1be0` |
| **Canonical name** | `FUN_006a1be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 FUN_006a1be0(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_006a35e0();
  return ((float10)param_2 - (float10)param_1) * fVar1 + (float10)param_1;
}
```
