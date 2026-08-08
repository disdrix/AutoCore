# Function record: FUN_004cbee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbee0` |
| **Canonical name** | `FUN_004cbee0` (see named record) |
| **Named** | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` |
| **Address** | `0x004cbee0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cbee0`–`0x004cbfb2` exclusive (**210 B**) |
| **System** | MSVC std::map insert-or-find (isnil@+0x29 pair key) |
| **Agent** | WQ9F-D OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Alias

- Preferred: `StdMap_InsertOrFind_PairKey_Isnil29_Inferred`
- Reject product: `Named_CalleeOf_…_VOG_DEBUG_ST_004cbee0`

## Purpose

Pair-key unique insert-or-find shell (hi signed primary, lo unsigned secondary) over dualed isnil29 insert+RB.

## Signature

```c
void __thiscall FUN_004cbee0(
    MapShell_Isnil29 *map,        // ECX
    InsertPair_Isnil29 *out,      // +4
    const Val_PairKey *value);    // +8  lo@+0 hi@+4
// RET 8
```

## Callers / callees

| Role | Target |
|---|---|
| Caller (1) | `FUN_004cc220` @ `0x004cc3ae` |
| Insert | `FUN_004cbb60` |
| Predecessor | `FUN_004cb4f0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.md`
- Annotated: `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cbee0.cpp`
- A/B: `docs/reconstruction/reviews/A|B_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md`
- Named record: `docs/reconstruction/functions/aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + pair order | High |
| Product pair English | Open (`_Inferred`) |
