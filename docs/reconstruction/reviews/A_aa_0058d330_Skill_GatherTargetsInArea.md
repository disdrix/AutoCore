# Review A (reconstruction fidelity): `aa_0058d330` Skill_GatherTargetsInArea

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d330` |
| **VA** | `0x0058d330` |
| **Canonical name** | `Skill_GatherTargetsInArea` |
| **Review date** | `2026-07-29` (mode-table CF strengthen; prior residual same day; base 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058d330_Skill_GatherTargetsInArea.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Area/chain multi-target collection (**INFERRED** name). Query nearby objects, filter by **`param_8` gather mode**, validate via `FUN_0058a810`, append TFID entries into `param_1` (**stride 0x10**), respect max-targets countdown, optional sort-by-distance. Chain-origin refresh and allow-self flags. Core AoE / interact pick gather.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058d330_Skill_GatherTargetsInArea.md` |
| Annotated | `docs/reconstruction/raw/aa_0058d330_Skill_GatherTargetsInArea.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_GatherTargetsInArea.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058d330_Skill_GatherTargetsInArea.md` |
| Residual scratch | `docs/reconstruction/reviews/a_0058d330.md` |
| Pair filter (xref only) | `FUN_0058a810` `0x0058a810` decompile |
| Callers (Ghidra xrefs) | ResolveTargetList; NPC_TryCastSkillFromSet; DriveControlTick; InteractClickPick; PollBoundActions; `FUN_0061fdf0`; `FUN_009210e0`; `FUN_00921f70`; `FUN_00943340`; `FUN_00943520` |
| Skill ABI | `Skill_ResolveTargetList` `0x00550300` decompile |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Out TFID list stride **0x10** | **High** | plate + stores |
| Hard cap **99** + invalid terminator | **High** | `local_d4 == 99`; `DAT_009d4d28..` |
| maxTargets countdown `param_7` | **High** | body |
| Optional sort-by-distance `param_14` | **High** | `FUN_0058def0` / `FUN_0058c7a0` |
| Validate helper before append | **High** | `FUN_0058a810` |
| Not cast power / ValidateTarget | **High** | scope; no direct Validate call |
| **Mode table CF** (`param_8`) | **High** | sealed residual — see §6 + `a_0058d330.md` |
| Query flag ladder (1 / 0x11 / 10) | **High** | body exact |
| Pass-1 7/10/6 polarity | **High** | re-decompile; annotated corrected |
| Self-allow `{0, 0xb, 1&&flag}` | **High** | body exact |
| Helper mode switch exhaustiveness | **High** | 8 early; 2/1/0xb/0/3/4/9 special; else `return 1` |
| filterA bypass for Veh/Cre/Char | **High** | helper type branch |
| English mode names | **INFERRED** | PDB symbols unknown |
| skill `+0x60c` → mode / `+0x610` → type filter | **High** | ResolveTargetList ABI + asm push |
| 15-arg `ADD ESP,0x3c` | **High** | all callers checked |
| Literal modes 1/2/3/7/8 | **High** | asm + decomp callers |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Setup origin + source handle `vtbl+0x1c8` | Yes |
| Query flag ladder → `FUN_004ea350` | Yes |
| Pass-1 modes 7/10/6/+0xd4/+0xdc (prefer-nonzero primary) | Yes |
| Pass-2 `FUN_0058a810` + self allow + TFID write / sort | Yes |
| Terminator + free | Yes |
| No invented damage | Yes |

---

## 5. Gaps / open

1. Original retail enum **symbol names** for modes (behavioral table sealed; names INFERRED).
2. Spatial query helpers still `FUN_004ea350` / `FUN_004e9aa0` / `FUN_0058a810` (no rename this pass; ownership is this function only).
3. Mode-7 + `filterA=0x14` **intent** (Character-only pick) vs CF (Veh/Cre/Char all bypass filterA) — intent INFERRED.
4. Runtime / bit-exact / image diff (matrix policy).

---

## 6. Mode table residual — sealed (2026-07-29 strengthen)

Full table + caller inventory in `reviews/a_0058d330.md`. Summary:

| Mode | INFERRED role | Key CF |
|---:|---|---|
| 0 | Self / related-owner | `+0x214` equals caster; self OK |
| 1 | Ally / non-hostile | `+0x298==0`; query `0x11`; self if `param_11`; literal `FUN_0061fdf0` |
| 2 | Hostile / enemy | `+0x298!=0`; query `0x11`; many UI literals |
| 3 | Living interact (Veh/Cre/Char) | types `0xe`/`0x12`/`0x14` only |
| 4 | Same related TFID | dual `+0x214` TFID match |
| 6 | `+0xdc`-only broadphase | skip `+0xd4`; helper default accept |
| 7 | Type-filtered special | query `10`; `+0x1dc` prefer-nonzero; callers often `filterA=0x14` |
| 8 | Unfiltered | early accept in helper; PollBound literal |
| 9 | Type-3 or hostile | type==3 else `+0x298` |
| 10 | Dead / corpse-like | allows `+0x198!=0`; pass-1 prefer-nonzero |
| 0xb | Same vehicle/plant crew | `+0x210` / `FUN_005749d0`; self OK |
| unlisted | Default | query `1`; pass-1 default; helper `return 1` |

Types: `CloneBaseObjectType` Vehicle=14, Creature=18, Character=20, ObjectGraphicsPhysics=3.

**Skill ABI (sealed):** `gatherMode=skill+0x60c`, `filterA=skill+0x610`, chain/self from `skill+0x624` bits 14/5; also `NPC_TryCastSkillFromSet`.

**Tighten note:** dual residual **mode table CF sealed High**; English names remain INFERRED; filterA-on-living bypass documented; runtime open.

**Verdict:** **accept-with-gaps** — mode table residual sealed; verification/runtime remain.
