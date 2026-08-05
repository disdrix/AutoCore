# Reconstruction review: `aa_00533f90` CVOGReaction_CompleteObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533f90` |
| **VA** | `0x00533f90` |
| **Canonical name** | `CVOGReaction_CompleteObjective` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00533f90_CVOGReaction_CompleteObjective.md` | Authoritative Ghidra decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00533f90_CVOGReaction_CompleteObjective.annotated.md` | Scaffold notes; System now missions-progression |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGReaction_CompleteObjective.cpp` | Human-refined port-shaped rewrite |
| Function record | `docs/reconstruction/functions/aa_00533f90_CVOGReaction_CompleteObjective.md` | Human-refined status; confidence table |
| System map | `docs/reconstruction/systems/missions-progression.md` | Lifecycle / hash layout |
| Prior art | `docs/missionState.md`, `docs/XP.md` | Callers, mission XP, hash offsets |
| Sibling | `raw/aa_00536080_*` bulk complete call shape | |

**Primary claims under review (clean must match low-level):**

1. Active-objective hash walk at `this[0x152]` / `+0x548` by `objectiveId`
2. Missing-obj path: flag `+0x7e` early-out, def lookup, type short, completed reject, `GiveMission`
3. Pending-req walk with `forceComplete` bypass + `FUN_0059d880` min-pass gate
4. Advance when `seq < count-1`: next obj, unlock, skill/attrib, goto dirty-only
5. Final when not completed: XP bias + `AddExperience(PacketOrNonKill)`, 64-bit credits, medals, inventory×4
6. Toast branches type0 / accepted / medal; completed inserts; `SearchAutoMissions` on flag path
7. Returns `0` / `1` only

**Not re-authored:** No edits to raw body pseudocode. Metadata System field and clean/record reviewed as filed.

**Optional live re-decompile:** Not performed this session.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth CF, callees, offsets |
| Annotated body | Annotated | Confirm no material CF delta vs raw |
| Clean body | `CVOGReaction_CompleteObjective.cpp` | Line-by-line fidelity + naming |
| Function record | Function record | Human-refined; dual review expected |
| System / missionState | Hash table `+0x538/53c/540/548/55c` | Offset corroboration via dword indices |
| XP.md mission section | Final-only XP / credits | Semantic cross-check |

No runtime / CE / differential. No instruction-byte body seal.

---

## 3. Confirmed points

### 3.1 Control flow: clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Active hash chain walk | Present | Present (named) | **Yes** |
| Missing → flag / def / GiveMission | Present | Present | **Yes** |
| Null mission def → 0 | Present | Present | **Yes** |
| `"Finishing mission %d."` | Present | Present | **Yes** |
| Pending req loop + force + min gate | Present | Present | **Yes** |
| Advance `seq < count-1` + goto `LAB_005348f3` | Present | Present | **Yes** |
| Final rewards only if completed-hit null | Present | Present | **Yes** |
| XP ± bias + AddExperience non-kill | Present | Present | **Yes** |
| Credits CARRY4 64-bit add | Present | Present (explicit carry) | **Yes** |
| Inventory 4-slot COID filter | Present | Present | **Yes** |
| Toast type0 / accepted / medal | Present | Present | **Yes** |
| Completed `FUN_0053c360` + `+0x53c` insert | Present | Present | **Yes** |
| Double `FUN_00538b20` | Present | Present | **Yes** |
| SearchAutoMissions + dirty `\|0x10` | Present | Present | **Yes** |
| Return `1` / `0` | Present | Present | **Yes** |

### 3.2 Offsets and constants preserved

| Element | Raw | Clean |
|---|---|---|
| Active objectives | `param_1[0x152]` | Same (+ comment `+0x548`) |
| Completed | `param_1[0x14e]` | Same (`+0x538`) |
| Secondary completed | `param_1[0x14f]` | Same (`+0x53c`) |
| Pending | `param_1[0x157]` | Same (`+0x55c`) |
| Money | `param_1+0x1c8` | Same (`+0x720`) |
| Dirty | `param_1[0x18d]` | Same |
| Toast color / audio | `0xffeee3d8`, `mission_complete_3/5` | Same |
| XP bias global | `g_flMissionXpRoundBias` | Same |

### 3.3 Typing / naming delta only

Clean renames `param_*` / `*Var*` to meaningful identifiers (`objectiveId`, `forceComplete`, `pMissionDef`, …) and documents dword-index → byte-offset. Does **not** invent branches, reorder side effects, or modernize mission policy.

`CHAR_FLAG_7E` macro is macro-equivalent of the raw triple-load expression (same address math).

### 3.4 Function record honesty

Record labels **Human-refined clean**, bit-for-bit/runtime **Open**, residual questions listed. Does not claim sealed retail port.

### 3.5 Absences

Clean does not invent: alternate reward formulas, server authority, modernized objective structs, or removal of unresolved `FUN_*`.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `CARRY4` → explicit `(a+b)<a` | Cosmetic | Equivalent to decompiler intrinsic |
| Spree/inventory `FUN_*` still open | Expected | Faithfulness OK |
| `AddActiveObjective` / `GiveMission` arity | Cross-unit | Clean preserves raw call shapes |
| Plate “char+0x152” vs byte `+0x548` | Doc | Clean correctly maps dword index ×4 |
| Stack float casts into `EvaluatePendingObjectives` | Opaque | Preserved as decompiled (slot reuse) |

**No revision required** for clean-vs-raw control-flow fidelity.

---

## 5. Residual uncertainty

1. Entity `+0x7e` polarity on missing-obj early-out vs reward/SearchAuto paths.
2. Which pool `AddSkillPoints` / `AddAttributePoints` actually write.
3. Semantic map for `FUN_0053c360`, `FUN_00538b20`, `FUN_00538bd0`, `FUN_0059d880`.
4. True object types for objective runtime vs definition on GiveMission chain fall-through.
5. No runtime confirmation of advance vs final, force path, or dialog turn-in interaction with `0x2070`.
6. Annotated layer is still largely a spaced copy of raw (System field updated).

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:**

- Clean C++ is a faithful, heavily commented rewrite of raw control flow, offsets, call order, return values, and side-effect structure.
- Naming improves readability without changing behavior.
- Function record status matches refined quality without overclaiming completion.

**Gaps (do not block acceptance of clean≡raw):**

- Heavy unresolved callee surface.
- Cross-unit signature tensions.
- No runtime / bit-for-bit verification.
- `+0x7e` / point-pool naming residual.

**Not needs-revision:** Clean does not diverge from raw in a way that requires CF rewrite.

**Not needs-more-evidence *for clean≡raw*:** Dual static sources agree. Semantic seal of full mission system is out of scope for this review type.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Offsets / return codes match | **Pass** |
| No invented logic | **Pass** |
| Function record does not overclaim | **Pass** |
| Runtime / callee map complete | **Open** |
| Verdict | **accept-with-gaps** |
