# Function record: Weather_NfxListFillOrActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00556b10` |
| **Canonical name** | `Weather_NfxListFillOrActivate_Inferred` |
| **Ghidra name** | `FUN_00556b10` |
| **Address** | `0x00556b10`–`0x00556ce2` exclusive (**466 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client weather / NDSpecialFX nfx |
| **Partition** | W32-I |
| **Completion status** | **Dual sealed** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Weather-host helper: clear an out-list, then fill with resolved `_nfx.xml` resource ids **or** activate weather FX, selected by mode flag.

## Signature

```c
void Weather_NfxListFillOrActivate_Inferred(
    void* weatherHost /*ECX*/,
    GuardedVectorHeader* outList,
    void* weatherObj,
    char mode);  // RET 0xC
```

## Constants

| Address | Value |
|---|---|
| `0x009ca184` | `"_nfx.xml"` |

## Related

| VA / symbol | Role |
|---|---|
| `FUN_005575c0` | sole caller (weather transition) |
| `FUN_00553d20` | weather FX load (`"Failed to load weather FX"`) |
| `0x0043d670` | `GuardedVector_PushBack_Thiscall` (W31-I) |
| `FxCache_ApplyWithNfxEnsure` | sibling `_nfx.xml` append pattern |
| `host+0x190` / `+0x1a4` | out-list fields used by caller |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00556b10_FUN_00556b10.md` |
| Annotated | `docs/reconstruction/raw/aa_00556b10_FUN_00556b10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weather_NfxListFillOrActivate_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00556b10.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00556b10_FUN_00556b10.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-005441d0-00556b10-w32i-report.md` |
