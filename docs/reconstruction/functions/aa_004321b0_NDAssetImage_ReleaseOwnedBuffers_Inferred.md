# Function record: NDAssetImage_ReleaseOwnedBuffers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004321b0` |
| **Canonical name** | `NDAssetImage_ReleaseOwnedBuffers_Inferred` |
| **Ghidra name** | `FUN_004321b0` |
| **Address** | `0x004321b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NDAssetImage / asset image buffer ownership |
| **Completion status** | **Dual sealed** (W24-A) |
| **Verdict** | **accept-with-gaps** |

See `aa_004321b0_FUN_004321b0.md` for full artifact index and call surface.

## One-line contract

```
if image+0x38: return 0
else release +0x1b4[] (vtbl0(1)), free +0x1b4/+0x1ac/+0x1b0/+4 → return 1
```
