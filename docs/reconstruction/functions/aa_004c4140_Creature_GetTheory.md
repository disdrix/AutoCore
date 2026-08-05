# Function record: Creature_GetTheory

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4140` |
| **Canonical name** | `Creature_GetTheory` |
| **Address** | `0x004c4140`–`0x004c41bb` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / character stats |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** — ABI/CF/clamp/product string sealed; field English + vehicle asymmetry open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Review date** | `2026-07-29` |

## Alias

- Ghidra: `FUN_004c4140`
- Scaffold: `Named_CalleeOf_Client_DebugDumpEntityCombatStats_004c4140`

## Purpose

Leaf getter for creature **Theory** stat:

```
clamp(min(int16(creature+0x140), 200) + int16(creature+0x148), 1, 250)
```

Product name from UI `"Theory"` localization key. Also supplies attacker accuracy short-stat bonus (cast to float) in `Skill_AccuracyScore_Inferred`.

## Signature (sealed)

```c
// __fastcall / thiscall: creature in ECX; int return in EAX; plain RET
int __fastcall Creature_GetTheory(void *creature);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c4140_Creature_GetTheory.md` (+ scaffold `aa_004c4140_FUN_004c4140.md`)
- Annotated: `docs/reconstruction/raw/aa_004c4140_Creature_GetTheory.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Creature_GetTheory.cpp` (+ `FUN_004c4140.cpp`)
- Dual A: `docs/reconstruction/reviews/A_aa_004c4140_Creature_GetTheory.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004c4140_Creature_GetTheory.md`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Callees | — | **none** (leaf) |
| Caller | `0x005531d0` | `Skill_AccuracyScore_Inferred` — `(float)Theory` as atk bonus |
| Caller | `0x00845360` | UI requirements — `"Theory"` label |
| Caller | `0x00514390` | req gate vs skill/item short `@+0xf2` |
| Caller | others | `004f74c0`, `00846820`, `008d0b70`, `008f97c0`, `00933d60`, `00955eb0`, `00515520` |
| Sibling | `0x004c4070` | Combat getter (not owned) |
| Sibling | `0x004c41c0` | Perception getter (not owned) |

## Confidence

| Claim | Level |
|---|---|
| ECX creature + leaf RET | **High** |
| Offsets +0x140 / +0x148 shorts | **High** |
| Clamp [1, 250] + base cap 200 | **High** |
| Product name Theory | **High** (UI string) |
| Field-level base vs bonus English | **Probable** |
| Why no vehicle floor (unlike Combat/Perception) | **Open** |
