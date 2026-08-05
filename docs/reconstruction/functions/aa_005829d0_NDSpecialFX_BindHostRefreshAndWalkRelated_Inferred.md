# Function record: NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005829d0` |
| **Canonical name** | `NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred` |
| **Ghidra name** | `FUN_005829d0` |
| **Address** | `0x005829d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX host bind wrapper |
| **Completion status** | **Dual sealed** (W24-A) |
| **Verdict** | **accept-with-gaps** |

See `aa_005829d0_FUN_005829d0.md` for full artifact index and call surface.

## One-line contract

```
BindHostAndRefresh(MI_adjust(host), fx, a2[, a3]);
if *(host-0x88): WalkRelated(ecx=fx, related, 0, 0, -1);
```
