# Function record: EnsureQuestBaseCreditsLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512870` |
| **Canonical name** | `EnsureQuestBaseCreditsLoaded` |
| **Address** | `0x00512870` |
| **Body** | `0x00512870`–`0x005128ad` (62 bytes → `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC cdecl/void — no stack args; void return |
| **Completion status** | **Dual A/B complete** — accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Thin ensure-load wrapper for retail table **`tQuestBaseCredits`**. Always runs DB enter → `LoadQuestBaseCreditsFromWad` → DB leave; on negative status logs `VOG_DEBUG_STOP`. Does **not** early-return on ready flag and does **not** write `g_nQuestBaseCreditsLoaded_Inferred` in-body (caller `Mission_ComputeObjectiveCredits` gates on the flag).

## Signature

```c
void EnsureQuestBaseCreditsLoaded(void);
```

## Behavioral summary (asm-sealed)

1. `ECX = *DAT_00b0469c` → `FUN_007e1d80` (enter).
2. `ECX = *DAT_00b0469c`; push `&g_pQuestBaseCreditsMap_Inferred` (`0x00b04264`) → `LoadQuestBaseCreditsFromWad` (`0x007cc810`).
3. Save status in `ESI`; `ECX = *DAT_00b0469c` → `FUN_007b7df0` (leave).
4. If status `< 0`: `FUN_007a4480(0, "VOG_DEBUG_STOP")`.

## Globals

| VA | Name | Role |
|---|---|---|
| `0x00b0469c` | `DAT_00b0469c` | DB reader context pointer (ECX) |
| `0x00b04264` | `g_pQuestBaseCreditsMap_Inferred` | map root |
| `0x00b04268` | `g_pQuestBaseCreditsEndSentinel_Inferred` | end (consumer) |
| `0x00b0426c` | `g_nQuestBaseCreditsLoaded_Inferred` | ready dword (caller gate; no write in this body) |
| `0x00a15844` | string | `"VOG_DEBUG_STOP"` |

## Callers / callees

**Callers:** `Mission_ComputeObjectiveCredits` (`0x0059df20` @ `0x0059df41`, `0x0059df65`), `FUN_0094a6a0` (`0x0094afbd` init).  
**Callees:** `FUN_007e1d80`, `LoadQuestBaseCreditsFromWad` (`0x007cc810`), `FUN_007b7df0`, `FUN_007a4480`.  
**Sibling:** `EnsureQuestCreditsLookupLoaded` `0x00512830` (same skeleton; map `0x00b04258`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00512870_EnsureQuestBaseCreditsLoaded.md`
- Annotated: `docs/reconstruction/raw/aa_00512870_EnsureQuestBaseCreditsLoaded.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EnsureQuestBaseCreditsLoaded.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00512870_EnsureQuestBaseCreditsLoaded.md`
- Review B: `docs/reconstruction/reviews/B_aa_00512870_EnsureQuestBaseCreditsLoaded.md`

## Confidence

| Claim | Level |
|---|---|
| Linear ensure wrapper control flow | **High** (asm) |
| Map / ctx / string addresses | **High** (`read_memory` + globals) |
| No in-body ready early-out / flag store | **High** |
| Enter/leave product names | Medium (FUN_* residual) |
| Loaded-flag writer | Open (loader residual) |
