# Function record: CVOGReaction_FailMissionNotify → Vector_PushDword

| Field | Value |
|---|---|
| **Stable ID** | `aa_004149d0` |
| **Canonical name (historical)** | `CVOGReaction_FailMissionNotify` |
| **Sealed product role** | **`Vector_PushDword`** |
| **Address** | `0x004149d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container util (cross-cutting; used by missions-progression among others) |
| **Completion status** | **Dual residual sealed 2026-07-29** — pure push CF High; rename hygiene optional |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual** | `reviews/A_aa_004149d0_*` / `reviews/B_aa_004149d0_*` — **accept** |

## Purpose

Generic growable **dword vector push**:

1. Triad at `this+4` (begin), `this+8` (end), `this+0xc` (cap).
2. If buffer live and size `<` capacity: `*end = *arg0`; `end += 4`.
3. Else grow/insert via `FUN_0040dbf0` → `FUN_004073a0`.

Does **not** fail missions, show UI, send packets, or set dirty bits. Historical name is call-graph residue from FailMission.

## Signature (decompiler + image)

```c
// __thiscall, RET 4
void Vector_PushDword(void *pVec /*ECX*/, uint32_t *pValue /*stack*/);
// Ghidra symbol still: CVOGReaction_FailMissionNotify
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004149d0_CVOGReaction_FailMissionNotify.md`
- Annotated: `docs/reconstruction/raw/aa_004149d0_CVOGReaction_FailMissionNotify.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGReaction_FailMissionNotify.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004149d0_CVOGReaction_FailMissionNotify.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004149d0_CVOGReaction_FailMissionNotify.md`

## Callers / callees

| Direction | Count / names |
|-----------|----------------|
| Callees | `FUN_0040dbf0` only (→ `FUN_004073a0`) |
| Callers (functions) | **40** (`get_function_callers`) |
| Call sites | **51** (`get_xrefs_to` UNCONDITIONAL_CALL) |

Notable callers: `CVOGReaction_FailMission` (`char+0x560` end-quest ids), `Client_UpdateMissionJournal` (stack Active/New temps), freelist pool bootstrap family (`FUN_00414cd0` …), `FUN_00530550` (medal list).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + image | **High** |
| Pure `Vector_PushDword` (no fail UX) | **High** |
| Multi-caller generic (not mission-only) | **High** |
| Parameter product English per site | Site-dependent / Tentative for unsampled tail |
| Types (`uint32_t` element) | **High** (stride 4) |
