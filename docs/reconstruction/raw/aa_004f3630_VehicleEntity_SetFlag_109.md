# Raw capture: VehicleEntity_SetFlag_109

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3630` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f3630` |
| **Canonical name** | `VehicleEntity_SetFlag_109` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall VehicleEntity_SetFlag_109(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x109) = param_2;
  return;
}
```
