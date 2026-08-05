# Raw capture: FUN_008cd1a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cd1a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cd1a0` |
| **Canonical name** | `FUN_008cd1a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008cd1a0(void)

{
  undefined4 in_EAX;
  int *unaff_ESI;
  
  DAT_00d1a980 = in_EAX;
  FUN_008cd070();
                    /* WARNING: Could not recover jumptable at 0x008cd1b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_ESI + 0x444))();
  return;
}
```
