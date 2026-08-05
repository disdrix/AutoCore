# Review A (reconstruction fidelity): `aa_00533f90` CVOGReaction_CompleteObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533f90` |
| **VA** | `0x00533f90` |
| **Canonical name** | `CVOGReaction_CompleteObjective` |
| **Review date** | `2026-07-29` (dual residual; prior `2026-07-23`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00533f90_CVOGReaction_CompleteObjective.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — residual strengthen 2026-07-29** |
| **Verdict** | **accept-with-gaps** |
| **Residual scratch** | `reviews/a_00533f90.md` |

---

## 1. Purpose

Client-side **finish or advance a single objective** on a character (`missions-progression` kernel):

1. Resolve `objectiveId` in active-objectives hash **`char+0x548`** (`this[0x152]`).
2. If missing: when entity flag **`+0x7e == 0`** (non-local), def lookup → parent mission → `GiveMission` if not completed; when **`+0x7e ≠ 0`** (local) → **return 0**.
3. Require mission def at `obj+0x14c`; `FUN_00547920` ensure-XML; log `"Finishing mission %d."`.
4. If pending node in `+0x55c`: walk requirement vtables (`+0x8` eval, `+0x2c` action); min-pass = **`obj+0x164`** via `FUN_0059d880`; `forceComplete` bypasses fail.
5. **Advance** when `obj+0x14 < count-1`: `AddActiveObjective(next)`, remove retiring obj from `+0x548`, unlock `next+0x120`, set skill/attrib **absolute**, dirty `\|0x10`; **no XP/credits**.
6. **Final** when last and mission not in completed `+0x538`: skill/attrib, XP (non-kill + bias), 64-bit credits at `+0x720`, medals/counters, local-only inventory×4 + reward fill; toast/audio; insert completed `+0x538`/`+0x53c`; retire active `+0x540`/`+0x544`; destroy bind `+0x530`; `EvaluatePendingObjectives`; local `SearchAutoMissions`.

**Critical mission-manager unit** — dialog turn-in, S2C `0x2070` force, bulk complete, and pending eval all funnel here. Residual: `reviews/a_00533f90.md`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| Annotated | `docs/reconstruction/raw/aa_00533f90_CVOGReaction_CompleteObjective.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_CompleteObjective.cpp` |
| Function record | `docs/reconstruction/functions/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| Prior dual (legacy) | `aa_00533f90_reconstruction_review.md` / `aa_00533f90_skeptical_review.md` |
| Residual scratch | `reviews/a_00533f90.md` |
| Sibling residual | `reviews/a_005327c0.md` (GiveMission `+0x540`/`+0x544` pair) |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Prior art | `docs/missionState.md`, `docs/XP.md` |
| Live re-decompile | Ghidra `decompile_function(0x00533f90)` + helpers 2026-07-29 |

**Not performed:** `disassemble_bytes`; Launcher; live complete capture.

---

## 3. Signature / ABI

```c
uint32_t __thiscall CVOGReaction_CompleteObjective(
    int* thisCharacter,      // CVOGCharacter*
    unsigned objectiveId,    // active-objectives hash key (+0x548)
    unsigned rewardCoidLo,   // inventory reward filter (with Hi)
    unsigned rewardCoidHi,
    char forceComplete);     // non-zero: skip failed requirement evals (0x2070 uses 1)
```

Returns `1` on success / dirty path, `0` on reject.

| Callee | Convention | Args (asm-sealed residual) | Confidence |
|--------|------------|----------------------------|------------|
| `CVOGReaction_GiveMission` `0x005327c0` | `__thiscall` | `ECX=character`, stack missionId | **High** |
| `CVOGMission_AddActiveObjective` `0x00531b00` | `__thiscall` | `ECX=character`, stack `objectiveDef*` | **High** |
| `CVOGCharacter_AddSkillPoints` `0x005312c0` | `__thiscall` | `ECX=char`, stack short **absolute** pool | **High** |
| `CVOGCharacter_AddAttributePoints` `0x00531250` | `__thiscall` | `ECX=char`, stack short **absolute** pool | **High** |
| `FUN_0059d880` | `__fastcall` | `ECX=objective` → `*(u32*)(obj+0x164)` | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Active hash walk `this[0x152]` / `+0x548` by objectiveId | **High** | Raw chain walk preserved |
| Flag `+0x7e` = **IsLocalPlayer** (entity chain via `+0xa8`) | **High** | **Sealed residual 2026-07-29** — multi-site polarity + sibling units |
| Missing-obj: local (`+0x7e≠0`) → return 0; non-local → GiveMission chain | **High** | Asm + raw |
| Pending-req eval + forceComplete bypass | **High** | vtbl +0x8 / +0x2c |
| Min-pass = `obj+0x164` via `FUN_0059d880` | **High** | **Sealed** — trivial body + ECX=objective |
| ADVANCE when `seq < count-1` (no XP/credits) | **High** | goto dirty-only |
| Skill pool `char+0x6ce` / attrib `char+0x6cc` — **not swapped** | **High** | **Sealed** — callee bodies assign absolute; caller `current+grant` |
| Obj grants: `obj+0x130` short skill, `obj+0x134` byte attrib | **High** | Call-site math |
| FINAL XP via `Mission_ComputeObjectiveXp` ± `g_flMissionXpRoundBias` + `AddExperience(PacketOrNonKill)` | **High** | Non-kill; bias @ `0x00AAA6D0` ≈ 0.5001f (`8e 06 00 3f`) |
| FINAL 64-bit credits add at `+0x720` (`this[0x1c8]`) | **High** | Explicit carry |
| XP/credits/medals **not** gated by `+0x7e` | **High** | **Sealed** — only inventory + SearchAuto are local-gated |
| Inventory×4 + reward fill only when `+0x7e≠0` | **High** | Raw guard |
| `FUN_0053c360` insert completed → ECX **`char+0x538`** | **High** | **Sealed** call-site this |
| Double `FUN_00538b20` = remove **`+0x540` then `+0x544`** (not same-hash twice) | **High** | **Sealed** — matches GiveMission insert pair |
| `FUN_00538bd0` remove objective → ECX **`char+0x548`** | **High** | Advance + final |
| `FUN_00538e00` destroy bind → ECX **`char+0x530`** | **High** | GiveMission inserts via `FUN_0053c660` |
| Manual `+0x53c` instance-completed insert (not second `FUN_0053c360`) | **High** | Raw node walk |
| Medal `FUN_00530550` / map `FUN_00530610` / short+`0x580` `FUN_00531960` roles | **High** CF | Product English open |
| Toast / audio strings | **High** | literal evidence |
| Primary-entity toast gate `+0xe8a0` (≠ `+0x7e`) | **High** | Separate expression |
| Dirty `this[0x18d]\|=0x10` (missions); `\|1` on credits | **High** | Raw |
| Return `0`/`1` only | **High** | No invented codes |
| Req vtable bodies (+0x8 / +0x2c) | **Probable** | offsets sealed; bodies open |
| Product English for `+0x544` / `+0x530` / medal helpers | **Tentative** | shared GiveMission open |
| Runtime / bit-exact / image diff | **Open** | matrix policy |

---

## 5. Control flow: clean ≡ raw (spot-check)

| Stage | Raw present? | Clean match? |
|---|---|---|
| Active hash walk `+0x548` | Yes | **Yes** |
| Missing → `+0x7e` gate → GiveMission chain | Yes | **Yes** |
| Mission def null → 0; log finishing | Yes | **Yes** |
| Pending req walk + min-pass + force | Yes | **Yes** |
| Advance skill/attrib absolute only; dirty-only exit | Yes | **Yes** |
| Final rewards gated on completed-hash miss | Yes | **Yes** |
| XP bias nearest-int + PacketOrNonKill | Yes | **Yes** |
| Credits 64-bit carry + dirty `\|1` | Yes | **Yes** |
| Local inventory×4 COID filter | Yes | **Yes** |
| Toast primary-entity + audio mission_complete_3/5 | Yes | **Yes** |
| Completed insert `+0x538` + manual `+0x53c` | Yes | **Yes** |
| Remove active `+0x540`/`+0x544`; obj `+0x548`; destroy `+0x530` | Yes | **Yes** |
| Local SearchAutoMissions; dirty `\|0x10` | Yes | **Yes** |
| Invented clamps / reordered awards | — | **None** |

**Result:** Clean CF ≡ raw. Residual sealed flag / hash-this / pool / min-pass / arity — no CF rewrite required.

---

## 6. Param / local renames (evidence only)

| Raw | Clean / role | Evidence |
|---|---|---|
| `param_1` | `thisCharacter` | `__thiscall`; hash bases |
| `param_2` | `objectiveId` | Active-objectives key |
| `param_3` / `param_4` | `rewardCoidLo` / `Hi` | Inventory filter vs slot COID |
| `param_5` | `forceComplete` | Req-eval bypass; 0x2070 = 1 |
| `local_2d4` | `pObjectiveSaved` | Objective payload across branches |
| `local_2e8` | `nReqPassed` | Actioned-req count vs min-pass |
| `local_2dc` | pending node / loop idx | Dual use across stages |
| `puVar2` | `pMissionDef` | `obj+0x14c` |
| `pvVar7` | completed hit (pre-final) / next-obj hit | Reused |

---

## 7. Gaps / open questions

1. Product English for `char+0x544` (paired active) and `char+0x530` (state-blob hash) — shared with GiveMission residual.
2. Product names for medal award / map-counter / `char+0x580` short helpers.
3. Requirement vtable bodies at `+0x8` / `+0x2c` (sibling units).
4. `FUN_004d08c0` full arg map vs decompiler mild residual.
5. Runtime complete / advance / force-0x2070 capture; bit-exact / image diff.
6. ~~Flag `+0x7e` polarity~~ **Sealed High** as IsLocalPlayer.
7. ~~Skill/attrib pool swap~~ **Falsified** — names match pools; absolute set.
8. ~~Double `FUN_00538b20` same-hash~~ **Falsified** — `+0x540` then `+0x544`.
9. ~~GiveMission / AddActiveObjective arity~~ **Sealed** 2-arg thiscall from residual.

**Verdict:** Mission-progression kernel CF faithful; residual sealed local-flag, hash this-map, pools, min-pass, arities, medal FUN roles. **accept-with-gaps.**
