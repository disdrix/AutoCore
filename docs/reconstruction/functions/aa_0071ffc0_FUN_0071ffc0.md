# Function record: FUN_0071ffc0 / CSoundManager_EraseNamedRecordByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ffc0` |
| **Canonical name** | `CSoundManager_EraseNamedRecordByName_Inferred` |
| **Ghidra name** | `FUN_0071ffc0` |
| **Address** | `0x0071ffc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client audio / `CSoundManager` |
| **Completion status** | **Dual A/B sealed** (2026-07-29 OWN-ONLY W16-L) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Structural: `CSoundManager_EraseNamedRecordByName_Inferred`
- Historical: `Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0071ffc0`

## Purpose

Under `manager+0x170` CS, erase the first 200-byte named record matching `name` (`_stricmp`) from either of two dense ranges (`[+0x44,+0x48)` then `[+0x54,+0x58)`), shifting the tail with `FUN_00480970` and shrinking the end pointer by 200.

## Signature (sealed)

```c
// name on stack; ret 4; manager in ESI (not ECX thiscall)
void FUN_0071ffc0(char *name);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0071ffc0_FUN_0071ffc0.md`
- Annotated: `docs/reconstruction/raw/aa_0071ffc0_FUN_0071ffc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0071ffc0.cpp`
- Named alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0071ffc0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0071ffc0_CSoundManager_EraseNamedRecordByName_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0071ffc0_CSoundManager_EraseNamedRecordByName_Inferred.md`

## Callers / callees

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `_stricmp`, `FUN_00480970`.

**Callers:**

| Caller | Site | Role |
|---|---|---|
| `FUN_007203b0` (`CSoundManager_MarkStopByName`) | `0x007203de` | when `doExtra != 0` |
| `FUN_00721a80` (music play) | `0x00721cf3` | after streaming-music create fail |

## Confidence

| Claim | Level |
|---|---|
| Control flow live ≡ raw | **Confirmed** |
| CS at `+0x170`; two ranges; stride 200 | **Confirmed** |
| First-match erase + end-=200 | **Confirmed** |
| ESI = manager | **Confirmed** (bytes `lea ebx,[esi+0x170]`) |
| Record layout beyond name@+0 | **Open** |
| Product English name of tables | **Open** |

## Gaps

1. Full 200-byte record schema.
2. Semantic difference range A vs B.
3. Runtime / differential.
