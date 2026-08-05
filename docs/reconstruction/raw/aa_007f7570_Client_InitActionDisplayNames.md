# Raw capture: Client_InitActionDisplayNames

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f7570` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007f7570` |
| **Canonical name** | `Client_InitActionDisplayNames` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
Error: Decompilation failed
```


---

## Append — force_decompile 2026-07-23 (authoritative recovery)

Raw capture previously failed (`Error: Decompilation failed`). Fresh Ghidra `force_decompile` @ `0x007f7570` recovered full body. Behavior-preserving clean lives in `reconstructed-exact/Client_InitActionDisplayNames.cpp`. Key drive-axis display-name stores:

| Offset | String |
|-------:|--------|
| +0x27d | Accelerate |
| +0x2b1 | Reverse |
| +0x2e5 | Steer Left |
| +0x319 | Steer Right |
| +0x34d | Steer Left Soft |
| +0x381 | Steer Right Soft |
| +0x3b5 | Brake |

Do not treat the original failed block as body ground truth.
