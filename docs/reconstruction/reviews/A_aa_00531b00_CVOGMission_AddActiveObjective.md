# Review A (reconstruction fidelity): `aa_00531b00` CVOGMission_AddActiveObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **VA** | `0x00531b00` |
| **Canonical name** | `CVOGMission_AddActiveObjective` |
| **Review date** | `2026-07-29` (dual tighten; prior `2026-07-23`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + asm corrections) |
| **Counterpart** | `reviews/B_aa_00531b00_CVOGMission_AddActiveObjective.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and strengthened** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_00531b00.md` |

---

## 1. Purpose

Register an **objective definition** as active on the character (`__thiscall`):

1. **Always** insert the objective **definition** into the active-objectives hash at **`char+0x548`** via `FUN_0053c460` (key = `def+0x10`, value = def, flag `0`).
2. If evaluator vector `[def+0x158, def+0x15c)` non-empty:
   - `operator_new(0x14)` zero-init state node; `node[0] = objectiveDef`
   - Insert state node into **pending** hash **`char+0x55c`** via `FUN_0053c760` (same key/flag shape)
   - On nonzero insert result → `operator_delete(node)` then **fall through** (not noreturn)
   - For each evaluator: vtable **`+0x28`(character, stateNode)**
   - Dirty **`char+0x634 |= 0x10`**
3. Empty evaluators → no node, no pending insert, **no dirty**

Callers (asm-sealed): `CVOGReaction_GiveMission` `0x005328b2`, `CVOGReaction_CompleteObjective` `0x005348a2`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00531b00_CVOGMission_AddActiveObjective.md` |
| Annotated | `docs/reconstruction/raw/aa_00531b00_CVOGMission_AddActiveObjective.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMission_AddActiveObjective.cpp` |
| Function record | `docs/reconstruction/functions/aa_00531b00_CVOGMission_AddActiveObjective.md` |
| Fresh decompile | Ghidra MCP `decompile_function` @ `0x00531b00` (2026-07-29) — CF ≡ 2026-07-23 |
| Call-site / body asm | Ghidra `get_assembly_context` @ insert sites + callers |
| Helpers | `FUN_0053c460` @ `0x0053c460`, `FUN_0053c760` @ `0x0053c760` (decompile) |
| Layout | `docs/missionState.md` §2.1 (`+0x548` / `+0x55c`) |
| Prior dual (legacy) | `aa_00531b00_reconstruction_review.md` / `aa_00531b00_skeptical_review.md` |
| Callers | GiveMission `aa_005327c0`, CompleteObjective `aa_00533f90` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Scratch | `reviews/a_00531b00.md` |

**Not performed:** `disassemble_bytes` bulk, Launcher, live grant capture.

---

## 3. Evidence table (body-backed + asm)

| Claim | Width / shape | Evidence | Confidence |
|---|---|---|---|
| `__thiscall(char*, ObjectiveDef*) → void` | sig | Prologue: `param_1`=ECX, `param_2`=Stack[0x4]; both callers | **High** |
| Always def-hash insert first | order | First call; return ignored | **High** |
| Def insert hash = **`this+0x548`** | CNDHash* | asm `MOV ECX,[EBP+0x548]` before `FUN_0053c460` | **High** |
| State insert hash = **`this+0x55c`** | CNDHash* | asm `MOV ECX,[EBP+0x55c]` before `FUN_0053c760` | **High** |
| Key = `def+0x10` (objective id) | u32 | Push EAX from `[ESI+0x10]` | **High** |
| Helpers are twin hash inserts | thiscall | Callee decompile: null/dup/lock checks; distinct node vtables | **High** role |
| Evaluator empty early exit (no dirty) | branch | begin==0 or `(end-begin)>>2==0` | **High** |
| State node **0x14** / back-pointer def | layout | `operator_new(0x14)` + five dword zero + `*node=def` | **High** |
| Setup vcall **+0x28** per evaluator | loop | `(char, stateNode)` args | **High** CF; **Probable** English |
| Dirty **0x10** only when evaluators present | flag | End of non-empty branch only | **High** |
| Delete on insert fail then **fall through** | CF | asm continues at `0x00531b8f`; Ghidra noreturn false | **High** |
| GiveMission one-arg decompile | ABI myth | **Falsified** — `PUSH obj; MOV ECX,char; CALL` | **High** |
| Direct store to `+0x548` in this body | plate | **No** — ECX load only; insert via helper | **High** |
| Clean ≡ raw CF (plus restored hash `this`) | fidelity | See §4 | **High** |

---

## 4. Control flow: clean ≡ raw (+ asm this restore)

| Stage | Raw / decomp | Clean | Match |
|---|---|---|---|
| Def insert first | Present (this dropped) | Present with `this+0x548` restored | **Yes** (asm correction) |
| Vector empty check | Present | Present | **Yes** |
| `operator_new(0x14)` zero-init 5 ints | Present | Present | **Yes** |
| `*node = objectiveDef` | Present | Present | **Yes** |
| State insert + delete on nonzero | Present | Present with `this+0x55c` restored | **Yes** (asm correction) |
| Fall-through after delete into loop | Present (despite WARNING) | Present | **Yes** |
| Virtual loop vtable `+0x28` | Present | Present | **Yes** |
| Dirty `+0x634 \|= 0x10` | Present | Present | **Yes** |
| Early return if vector empty (no dirty) | Present | Present | **Yes** |
| Invented branches / clamps | — | None | **Yes** |

Restoring hash `this` on the two helper calls mirrors machine code; decompiler omission is documented (same class of correction as CheckMissionPrerequisites thiscall restores).

---

## 5. Param / local renames (evidence only)

| Raw | Clean | Evidence |
|---|---|---|
| `param_1` | `thisCharacter` | ECX; dirty `+0x634`; hash bases `+0x548`/`+0x55c`; callers pass character |
| `param_2` | `objectiveDef` | Stack; `+0x10` id; `+0x158/+0x15c` evaluators; passed as hash value |
| `piVar1` | `stateNode` | `operator_new(0x14)`; first field = def |

---

## 6. Gaps / open questions

1. Original symbols for `FUN_0053c460` / `FUN_0053c760` (role sealed as hash insert; names open).
2. Evaluator vtable `+0x28` method English (setup/bind Probable only).
3. Consumers of dirty bit `0x10` at `+0x634` (shared with FailMission).
4. Full 0x14 state-node field map vs `RecvObjectiveState` slot floats.
5. Runtime: grant → observe `+0x548` / `+0x55c` nodes and dirty bit.
6. Cross-unit: GiveMission clean still shows one-arg `AddActiveObjective` form (doc debt outside this dual).

---

## 7. Relation to prior reviews

| Review | Date | Verdict | Notes |
|--------|------|---------|-------|
| Legacy reconstruction | 2026-07-23 | accept-with-gaps | CF yes; helpers open |
| Legacy skeptical | 2026-07-23 | needs-more-evidence | +0x548 / arity attacked |
| Dual A thin | 2026-07-23 | accept-with-gaps | Modern A/B first cut |
| Dual B thin | 2026-07-23 | accept-with-gaps / needs-more-evidence helpers | Correct +0x548 in-body store attack |
| **This dual A** | **2026-07-29** | **accept-with-gaps** | Asm seals hash targets + arity + delete fall-through |

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches frozen raw CF. Asm seals `+0x548` def-hash and `+0x55c` pending-hash inserts, two-arg thiscall at both callers, and fall-through after `operator_delete`. Clean preserves branch order and restores helper `this` per machine code. Prior “no +0x548 in body” remains true for **direct stores** but the plate hash claim is now **ECX-backed High**.

**Gaps:** Helper English names, vtable `+0x28` identity, dirty consumers, runtime/diff.

**Porting rule:** Always insert def at active-objectives hash; only allocate pending state + dirty when evaluators non-empty; do not treat insert-fail delete as aborting the rest of the activate path.
