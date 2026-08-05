# Function record: Rng_CloneSeededTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058ab60` |
| **Canonical name** | `Rng_CloneSeededTable_Inferred` |
| **Prior name** | `FUN_0058ab60` |
| **Address** | `0x0058ab60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (global RNG helper) |
| **Completion status** | **human-refined + dual A/B** (accept-with-gaps) — behavior/ABI/sizes sealed; product PDB open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual date** | `2026-07-29` |

## Alias

- Ghidra: `FUN_0058ab60`
- Prior scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_0058ab60` (obsolete)
- Role labels: “seed/table clone”, “RNG slice”, “dice table clone” (English open)

## Purpose

Seeded clone of a **600-ushort** window (copied as **300 dwords**, heap size **`0x4b0`**) from the global MT-backed RNG table exposed by `CVOGReaction_RandomUnitScalar` (`DAT_00d20c1c`). Forces singleton cursor `+0x0C` to the seed, wraps if `cursor+600 > 0xFFFFF`, copies from `table + cursor*2`, then increments cursor by 1. Primary HB path: `CVOGHBSkillBase_ctor` stores seed at `+0x6a8` and clone at `+0x6a0`.

## Signature

```c
// __cdecl
std::uint32_t* Rng_CloneSeededTable_Inferred(std::uint32_t seedIndex);
// heap: 0x4b0 bytes; often consumed as uint16_t[600]
```

## Sealed facts

| Fact | Level |
|---|---|
| `new[](0x4b0)` + 300-dword copy | **Confirmed** |
| Singleton `+0x08` table / `+0x0C` cursor | **Confirmed** |
| Index scale `*2` (ushort) + wrap `0xFFFFF`/600 | **Confirmed** |
| cdecl 1-arg, EAX return | **Confirmed** |
| 12 CALL xrefs (9 named + 3 orphan) | **Confirmed** |
| HB `+0x6a0` clone / `+0x6a8` seed | **Confirmed** |
| Product C++ name | **Inferred** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0058ab60_FUN_0058ab60.md` (body authoritative; do not overwrite)
- Annotated: `docs/reconstruction/raw/aa_0058ab60_Rng_CloneSeededTable_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Rng_CloneSeededTable_Inferred.cpp` (+ legacy `FUN_0058ab60` alias)
- Dual A: `docs/reconstruction/reviews/A_aa_0058ab60_Rng_CloneSeededTable_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0058ab60_Rng_CloneSeededTable_Inferred.md`
- Scratch: `tmp/a_0058ab60.md`
- Prior scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0058ab60.cpp` (superseded by named clean)

## Callers / callees

**Callees:** `operator_new[]` / `operator_new__`, `CVOGReaction_RandomUnitScalar` ×2.

**Named callers:** `CVOGHBSkillBase_ctor`, `Skill_ApplyEffectsOnTarget_Inferred`, `FUN_0054c720`, `FUN_00615020`, `FUN_006189d0`, `FUN_0061c090`, `FUN_0061cdc0`, `FUN_0061dfc0`, `FUN_0061e2a0`.

**Orphan CALL xrefs:** `0x0054ef92`, `0x0061e909`, `0x0061ea62`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** |
| ABI / sizes / wrap / singleton layout | **Confirmed** |
| Parameter semantic name (`seedIndex`) | **High** |
| Product / PDB symbol | **Inferred** |
| Runtime / bit-exact table contents | Open |
