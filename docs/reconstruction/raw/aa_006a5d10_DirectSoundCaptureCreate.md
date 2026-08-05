# Raw capture: DirectSoundCaptureCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5d10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5d10` |
| **Canonical name** | `DirectSoundCaptureCreate` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void DirectSoundCaptureCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectSoundCaptureCreate();
  return;
}
```
