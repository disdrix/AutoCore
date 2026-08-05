# Function record: CVOGReaction_CompleteObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533f90` |
| **Canonical name** | `CVOGReaction_CompleteObjective` |
| **Address** | `0x00533f90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` (character + objectiveId + reward COID pair + force) |
| **Completion status** | **Human-refined + dual residual (2026-07-29)** — advance/final CF High; flag/`this`/pool/min-pass/arity/hash-map sealed; product English for `+0x544`/`+0x530`/medal open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Finish or advance a single objective: hash lookup, optional GiveMission chain (non-local), requirement eval/force, advance next objective (skill/attrib only) or final mission rewards (XP/credits/medals; local inventory), toast/audio, completed-hash insert, retire active mission pair, `SearchAutoMissions` (local).

**Critical mission-manager unit** — dialog turn-in, `0x2070` force complete, bulk complete, and pending eval all funnel here.

## Signature

```c
uint32_t __thiscall CVOGReaction_CompleteObjective(
    int* thisCharacter,      // CVOGCharacter*
    unsigned objectiveId,    // active-objectives hash key
    unsigned rewardCoidLo,   // inventory reward filter (with Hi)
    unsigned rewardCoidHi,
    char forceComplete);     // non-zero: skip failed requirement evals
```

Returns `1` on success / dirty path, `0` on reject.

## Behavioral summary

1. Lookup `objectiveId` in active-objectives hash `this[0x152]` → byte `+0x548`.
2. If missing: **IsLocal (`entity+0x7e ≠ 0`) → return 0**; else resolve objective def → parent mission → `GiveMission` if not completed.
3. Require mission def at objective `+0x14c`; ensure XML (`FUN_00547920`); log `"Finishing mission %d."`.
4. If pending node in `+0x55c`: walk requirement vtables (`+0x8` eval, `+0x2c` action); min-pass = **`obj+0x164`** (`FUN_0059d880`); fail if gate and not `forceComplete`.
5. **Advance** when `obj+0x14 < count-1`: `AddActiveObjective(next)`, remove retiring from `+0x548`, unlock `next+0x120`, set skill/attrib **absolute** (`+0x6ce` / `+0x6cc`); dirty `this[0x18d]|=0x10`; return (no XP/credits).
6. **Final** (if not already completed `+0x538`): skill/attrib absolute, `Mission_ComputeObjectiveXp` ± bias → `AddExperience(..., PacketOrNonKill)`, credits 64-bit add at `+0x720`, medals/counters, **local-only** inventory×4, toast (`mission_complete_3/5`), insert completed (`FUN_0053c360` @ `+0x538` + manual `+0x53c`), remove active `+0x540`/`+0x544`, destroy bind `+0x530`, `EvaluatePendingObjectives`, local `SearchAutoMissions`.

## Character / def offsets (this unit)

| Location | Role |
|---|---|
| `this[0x152]` / `+0x548` | Active objectives hash |
| `this[0x14e]` / `+0x538` | Completed missions hash |
| `this[0x14f]` / `+0x53c` | Instance / secondary completed hash |
| `this[0x150]` / `+0x540` | Active missions hash (retired on final) |
| `this[0x151]` / `+0x544` | Paired active hash (retired with `+0x540`) |
| `this[0x14c]` / `+0x530` | Reward-state / bind blob hash (destroyed on final) |
| `this[0x157]` / `+0x55c` | Pending objectives hash |
| `this[0x1c8]` / `+0x720` | Currency low dword (64-bit with `+0x724`) |
| `this[0x18d]` / `+0x634` | Dirty flags (`\|1` money, `\|0x10` missions; skill helpers also `\|0x40` on `+0x634`) |
| `char+0x6ce` | Skill-point pool (short; absolute assign) |
| `char+0x6cc` / `this[0x1b3]` | Attribute-point pool (short; absolute assign) |
| `char+0x580` | Short counter via `FUN_00531960` (product English open) |
| `char+0x588` | Map counter via `FUN_00530610` |
| entity chain `+0xa8` then `+0x7e` | **IsLocalPlayer** flag |
| `obj+0x14` | Sequence index byte |
| `obj+0x10` | Objective id key |
| `obj+0x130` | Skill-point grant (short) |
| `obj+0x134` | Attribute-point grant (byte) |
| `obj+0x14c` | Mission def pointer |
| `obj+0x158/15c` | Requirement vtable array |
| `obj+0x164` | Min required pass count (`FUN_0059d880`) |
| `def[0x4c]` as byte / `def+0x130` | Objective count |
| `def[0x4f]` / `def+0x13c` | Objective list base |
| `def[0x3e]` short / `def+0xf8` | Mission type (toast/reward branch) |
| `def[0x40]` / `def+0x100` | Medal id or `-1` |

## Sealed helper roles (dual residual 2026-07-29)

| FUN / name | Role | This / key evidence |
|---|---|---|
| `FUN_0059d880` | Min required pass count | `*(obj+0x164)`; ECX=objective |
| `FUN_0053c360` | CNDHash insert (mission node) | Final: ECX=`char+0x538` |
| `FUN_00538b20` ×2 | CNDHash remove | ECX=`+0x540` then `+0x544` |
| `FUN_00538bd0` | Objective-hash remove | ECX=`char+0x548` |
| `FUN_00538e00` | Hash destroy-by-key | ECX=`char+0x530` |
| `FUN_00538e50` | Pending destroy-by-key | After req walk |
| `FUN_00530550` | Award medal by id + notify + dirty `\|0x20` | CF High |
| `FUN_00530610` | Map at `char+0x588` insert/`+=` | CF High |
| `FUN_00531960` | Add short to `char+0x580`; LogicUI `0x22`; dirty `\|1` | CF High |
| `FUN_00547920` | Mission def XML ensure-load | ECX=def (GiveMission residual) |
| `FUN_0052d8b0` | Clear mission reward staging @ `+0x50c` | CF High |
| `AddSkillPoints` / `AddAttributePoints` | Absolute assign `+0x6ce` / `+0x6cc` | Bodies sealed |
| `GiveMission` / `AddActiveObjective` | 2-arg thiscall (ECX=character) | Asm sealed |

## Callers (xref)

| Caller | Force | Notes |
|---|---|---|
| `Client_RecvCompleteDynamicObjective` `0x0080ff00` | **1** | S2C `0x2070` |
| `Client_MissionDialogHandleButton` `0x008ae7c0` | local path | Do not also send `0x2070` |
| `CVOGCharacter_CompleteMissionObjectives` `0x00536080` | reason pass-through | Bulk |
| `CVOGCharacter_EvaluatePendingObjectives` `0x00534920` | deferred complete | |
| `FUN_006508d0` | other | product name open |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; multi-caller mission kernel |
| Control flow | High | Raw plate + nested advance/final preserved; live re-decompile match |
| Hash offsets 530/538/53c/540/544/548/55c | High | missionState + residual call-site ECX |
| Flag `+0x7e` IsLocalPlayer polarity | High | **Sealed residual 2026-07-29** |
| Skill/attrib pools + absolute set | High | Callee bodies + call-site math |
| Min-pass `obj+0x164` | High | Trivial getter + ECX |
| Toast / audio strings | High | literal evidence |
| XP/credit award on final only; non-kill XP | High | body + docs/XP.md |
| Hash insert/remove/destroy roles | High | strings + this map |
| Medal FUN product names | Probable roles / open English | CF High |
| Requirement vtable semantics | Probable | offsets only; bodies open |
| Overall | **High (static)** | Dual residual 2026-07-29 |

## Open questions

- Product English for `char+0x544` (paired active) and `char+0x530` (state-blob hash).
- Product names for medal / map-counter / `+0x580` helpers.
- Requirement vtable bodies at `+0x8` / `+0x2c`.
- Runtime complete/advance/0x2070 capture; bit-exact / image diff.

## Dual review status

| Kind | Path | Verdict |
|---|---|---|
| A (fidelity) | `reviews/A_aa_00533f90_CVOGReaction_CompleteObjective.md` | **accept-with-gaps** (2026-07-29 residual) |
| B (skeptical) | `reviews/B_aa_00533f90_CVOGReaction_CompleteObjective.md` | **accept-with-gaps** + reject plate overstatements |
| Scratch | `reviews/a_00533f90.md` | residual seals ledger |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| Annotated | `raw/aa_00533f90_CVOGReaction_CompleteObjective.annotated.md` |
| Clean | `reconstructed-exact/CVOGReaction_CompleteObjective.cpp` |
| Dual residual scratch | `reviews/a_00533f90.md` |
| Dual A/B | `reviews/A_aa_00533f90_*` / `reviews/B_aa_00533f90_*` |
| System map | `systems/missions-progression.md` |
| Prior art | `docs/missionState.md`, `docs/XP.md` (mission XP section) |
| Sibling residual | `reviews/a_005327c0.md` (GiveMission) |
