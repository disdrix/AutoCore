# Review A (reconstruction fidelity): `aa_00534920` CVOGCharacter_EvaluatePendingObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534920` |
| **VA** | `0x00534920` |
| **Canonical name** | `CVOGCharacter_EvaluatePendingObjectives` |
| **Review date** | `2026-07-29` (dual residual strengthen — same day re-pass) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + asm residuals) |
| **Counterpart** | `reviews/B_aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| **System** | `missions-progression` |
| **Dual status** | **Residual sealed** (A + B; pending-slot, twin predicate, 7-caller set, CompleteCount) |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `tmp/a_00534920.md` |

---

## 1. Purpose

Client **pending-objective evaluator** on `CVOGCharacter`:

1. Gate on continent/world object via vbase `+0xa8` chain: enter only if `+0x7e != 0` **and** `+0xf6 == 0` (else no-op).
2. Lock pending-objectives hash `char+0x55c` (traversal byte `+0x1d`); hash-error strings on lock protocol violations.
3. Per pending **slot** (`node+8`): `def = *slot`; walk evaluator array `[def+0x158, def+0x15c)`:
   - vtable **`+0x4`** precheck — args `(character, slot, ctx0..ctx3, stack5th)`; **does not skip eval**
   - optional vtable **`+0x20`** action + LogicUI type **4** when precheck and (`mission+0xf8==0` OR `obj+0x14 != 0`)
   - vtable **`+0x8`** eval `(character, slot)` → success count; sticky all-true chain
4. Collect objective id at `def+0x10` when:
   - **`(CompleteCount != 0 && CompleteCount <= successCount) || allTrue`**
   - **and** `def+0x138 == 0`
5. Unlock; for each collected id: `CVOGReaction_CompleteObjective(this, id, -1, -1, force=0)`; then `FUN_005307e0(this)` + free id vector.

`__thiscall` with four context dwords (plus decompiler 5th stack dword forwarded only into precheck).

---

## 2. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| Annotated | `docs/reconstruction/raw/aa_00534920_CVOGCharacter_EvaluatePendingObjectives.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_EvaluatePendingObjectives.cpp` |
| Function record | `docs/reconstruction/functions/aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Ghidra re-decompile | `0x00534920` body |
| Threshold callee | `FUN_0059d880` @ `0x0059d880` → `*(obj+0x164)` = **CompleteCount** |
| Threshold evidence | `FUN_005468c0` dumps `<CompleteCount>%i</CompleteCount>` via same getter |
| Threshold asm | `read_memory` `0x00534ad8`–`0x00534b18`: dual CALL + `cmp [esp+10],eax` / `test bl` / `cmp [esi+0x138],0` |
| Twin CF | `CVOGReaction_CompleteObjective` @ `0x00533f90` min-pass gate (same getter + allTrue / force) |
| Post-pass | `FUN_005307e0` @ `0x005307e0` — drains `char+0x564`; always zeros `+0x564..+0x56c`, `+0xd6c`, `+0xd68` |
| Callers | `get_xrefs_to` / `get_function_callers` — **exactly 7** CODE xrefs |

**Not performed:** `disassemble_bytes`, Launcher, live pending-complete traces.

---

## 3. Sealed residuals (2026-07-29 re-pass)

### 3.1 CompleteCount / dual CALL

| Item | Evidence | Confidence |
|---|---|---|
| Body | `return *(param_1 + 0x164)` (`__fastcall` ECX) | **High** |
| Field name | XML serializer `FUN_005468c0`: `fprintf(..., "<CompleteCount>%i</CompleteCount>", FUN_0059d880())` | **High** |
| Dual CALL real | `0x00534ae0`: `mov ecx,[esi]; call FUN_0059d880; test eax; jz +0xd; mov ecx,[esi]; call; cmp [esp+10],eax; jge; test bl` | **High** |
| Semantics | 1st call: if `count==0` skip count-arm; 2nd: require `successCount >= count`; else fall to allTrue | **High** |
| `count==0` | Completes **only** via allTrue arm (if `+0x138==0`) | **High** |

### 3.2 Pending hash value = **slot** (not bare def*)

| Item | Evidence | Confidence |
|---|---|---|
| Eval path | `mov ecx,[esi]; mov edx,[ecx+0x158]; …; push esi; push ebp; call [eax+8]` — ESI = slot, `*ESI` = def | **High** |
| Threshold | `mov ecx,[esi]; call FUN_0059d880` then later `mov esi,[esi]; cmp [esi+0x138],0; mov esi,[esi+0x10]` | **High** |
| Active contrast | Active hash `+0x548` stores **def*** at `node+8` (CompleteObjective / FUN_00535c60) | **High** |
| Evaluator 2nd arg | Always **slot** (pending LookupByKey result), not bare def | **High** |

### 3.3 Twin predicate ≡ CompleteObjective (force=0)

| Unit | Success continue / collect |
|---|---|
| **EvaluatePending** | `(count != 0 && count <= success) \|\| allTrue`, then `def+0x138==0` |
| **CompleteObjective** | continues unless `((count < 1 \|\| success < count) && !allTrue && !force)` |

Algebraically identical for `force=0` (and no `+0x138` gate on CompleteObjective). Double `FUN_0059d880` also present in CompleteObjective. **High**.

### 3.4 Static caller set (exactly 7)

| VA | Symbol | kind (`p1`) | Notes |
|---:|---|---:|---|
| `0x005355a0` | `CVOGCharacter_AddCredits` | **5** | p2 = `(float)delta` |
| `0x00533f90` | `CVOGReaction_CompleteObjective` | **6** | **Only final** path (`pvVar7==0`); p2/p3 float-cast mission/medal fields |
| `0x005355e0` | `Character_MaybeRefreshCombatState_Inferred` | **7** | elapsed-ms float; gated on continent non-null |
| `0x00535c60` | `FUN_00535c60` | **9** | interact/threat; after active-obj type `0xc` match |
| `0x00535ed0` | `FUN_00535ed0` | **10** | use-object TFID resolve; p2 = `(float)*(obj+0xa8+0x34)` |
| `0x00650de0` | `CVOGHBMissionPatrol_Fn6` | **0xb** | p2..p4 = 0 |
| `0x00650e50` | `CVOGHBMissionPatrol_Fn3` | **0xb** | p2..p4 = 0 |

**Not** static callers: `Client_RecvObjectiveState` / `RecvCompleteDynamicObjective` / `CompleteMissionObjectives` (older MISSION_SYSTEM.md list is wrong for this VA).

### 3.5 `FUN_005307e0` post-pass

| Claim | Confidence |
|---|---|
| Always invoked after pending completes (even if id vector empty) | **High** |
| When `char+0x564` empty: free residual, zero `+0x564/+0x568/+0x56c`, zero `+0xd6c`, zero byte `+0xd68`, return | **High** |
| When non-empty: remove mission/objective hash nodes, optional fail UI / audio | **High** (body) |
| Product English name | **Tentative** |

### 3.6 LogicUI type 4

| Claim | Evidence | Confidence |
|---|---|---|
| Immediate **4** stored before `Client_SendLogicUiPacket` | `mov dword ptr [esp+48h], 4` at action path | **High** |
| Packet `this` / queue object identity | ECX setup via character vbase + continent-adjacent | **Probable** (not fully sealed in this unit) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function boundary @ `0x00534920` | **High** | Named plate; 7 callers |
| Pending hash `char+0x55c` + lock `+0x1d` | **High** | HashError strings + lock/unlock |
| Continent gate `+0x7e != 0` **and** `+0xf6 == 0` | **High** | Body polarity |
| Pending **slot** indirection `def=*slot` | **High** | Asm residual |
| Evaluator array `def+0x158/+0x15c` | **High** | Same shape as CompleteObjective |
| Vtable `+0x4` / `+0x20` / `+0x8` | **High** | Loop body |
| Precheck **only** gates action+LogicUI; **eval always runs** | **High** | B falsified old plate |
| Sticky all-true (`cVar4` / BL) | **High** | Updates only while still true |
| Empty evaluator list → allTrue arm | **High** | `allTrue=1`, loop zero iterations |
| `FUN_0059d880` = CompleteCount @ `+0x164` | **High** | Body + XML + asm |
| Collect uses CompleteCount **or** allTrue | **High** | Nested `\|\|` then `+0x138` |
| Collect only when `def+0x138 == 0` | **High** (CF on **objective def**); **Tentative** (English) | Not mission-def “repeatable” |
| Twin predicate ≡ CompleteObjective force=0 | **High** | Algebra + shared getter |
| Deferred CompleteObjective after unlock | **High** | Post-loop for |
| CompleteObjective force **0**, TFID wildcards `-1` | **High** | Stack args; thiscall character |
| Context kind codes 5/6/7/9/10/0xb | **High** (values from callers); enum **name** open | Not a sealed product enum table |
| Kind **6** only on final CompleteObjective | **High** | `if (pvVar7==0)` gate |
| `FUN_005307e0` post-pass side effects | **High** (layout); name Tentative | Always zeros empty queue fields |
| Continent flag English names | **Tentative** | Offsets sealed |
| Clean ≡ raw CF | **High** | Labels + double threshold call preserved |
| Runtime / bit-exact | **Open** | Not observed |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Outer continent gate polarity | **Yes** |
| Hash lock / traverse (`LAB_005349b0`) / unlock | **Yes** |
| Per-eval precheck → optional action/LogicUI → eval | **Yes** |
| Success count + sticky allTrue | **Yes** |
| Double `FUN_0059d880` then `(count!=0 && count<=succ) \|\| allTrue` | **Yes** |
| `def+0x138==0` collect gate | **Yes** |
| CompleteObjective after unlock, reason/force **0** | **Yes** |
| `FUN_005307e0` + free vector | **Yes** |

---

## 6. Context type codes (caller-derived)

| p1 / kind | Caller | Sealed? | Notes |
|---:|---|---|---|
| **5** | `CVOGCharacter_AddCredits` | value **High** | Money delta as float in p2 |
| **6** | `CVOGReaction_CompleteObjective` | value **High** | Final complete only; float-cast mission fields |
| **7** | `Character_MaybeRefreshCombatState_Inferred` | value **High** | Elapsed ms float |
| **9** | `FUN_00535c60` | value **High** | Interact / threat path |
| **10** | `FUN_00535ed0` | value **High** | Use-object TFID resolve path |
| **0xb** | `CVOGHBMissionPatrol_Fn3` / `Fn6` | value **High** | Patrol progress; zeros payload |

Forwarded into **precheck only**; eval vcall is `(character, slot)` without context. Product enum **name** remains open.

---

## 7. Gaps (remaining)

1. English meaning of objective-def `+0x138` when non-zero (auto-collect inhibit) — **not** mission repeatable.
2. Formal product enum name for context kind (values 5/6/7/9/10/0xb sealed as integers).
3. Full evaluator interface bodies (kill/useitem/money/… precheck filters) — out of unit.
4. Continent `+0x7e` / `+0xf6` retail names.
5. LogicUI queue object base (continent `+0xe8b8`-adjacent) exact product type.
6. Runtime: money/kill/patrol → pending complete end-to-end.

**Verdict:** Evaluator spine + CompleteCount + pending-slot + twin predicate + 7-caller set sealed statically. **accept-with-gaps.**
