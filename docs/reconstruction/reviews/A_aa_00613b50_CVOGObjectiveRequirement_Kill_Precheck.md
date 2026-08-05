# Review A (reconstruction fidelity): `aa_00613b50` CVOGObjectiveRequirement_Kill_Precheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613b50` |
| **VA** | `0x00613b50` |
| **Canonical name** | `CVOGObjectiveRequirement_Kill_Precheck` |
| **Review date** | `2026-07-29` (residual deepen; prior `2026-07-23` thin accept-with-gaps) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` |
| **Verdict** | **accept-with-gaps** (filter+mutate+Eval contrast **sealed**; runtime/diff + product field English open) |

---

## 1. Purpose

Kill requirement **precheck** (vtable **+0x4** on Kill req vtable `0x009e19e4`). Filters kill-context events, **increments** the progress slot float when filters pass, optionally fails the mission. Sibling Eval (`0x00613910`, vtbl **+0x8**) is a pure threshold reader on the **same** slot layout.

---

## 2. Inspected artifacts

| Artifact | Path / note |
|---|---|
| Raw | `raw/aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` (+ 2026-07-29 asm re-verify append) |
| Annotated | `raw/aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Kill_Precheck.cpp` |
| Function record | `functions/aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` |
| Live Ghidra | `decompile_function` + `disassemble_function` + `read_memory` @ `0x00613b50` / vtable `0x009e19e4` |
| Eval sibling | `Kill_Eval @ 0x00613910` (pure-read contrast) |
| FailMission | `CVOGReaction_FailMission @ 0x0052da30` via `req+4 → +0x14c` |

---

## 3. Sealed ABI (thiscall, `RET 0x1c` = 7 stack args)

Authoritative stack after prologue `PUSH EBX/EBP/ESI/EDI` (+0x10):

| Entry offset | After frame | Live reg / use | Role |
|---|---|---|---|
| ECX | ESI | req | `this` requirement object |
| `[ESP+4]` arg1 | `[ESP+0x14]` | killer/context entity | vehicle-path faction @`+0x532`; FailMission thiscall ECX; passed as Eval stack#1 (Eval ignores) |
| `[ESP+8]` arg2 | `[ESP+0x18]` → **EBP** | **state** progress blob | all slot R/W: `state+4+slot*4` |
| `[ESP+0xc]` arg3 | first gate | event type code | **must be 0** else return 0 |
| `[ESP+0x10]` arg4 | `[ESP+0x20]` | float (bits) | direct-CBID path: `CVTTSS2SI` then `== req+0x14` when `req+0x11==0` |
| `[ESP+0x14]` arg5 | `[ESP+0x24]` | **float addend** | default + vehicle credit: `ADDSS` onto slot |
| `[ESP+0x18]` arg6 | — | **no body refs** | reserved / caller padding |
| `[ESP+0x1c]` arg7 | `[ESP+0x2c]` → **EDI** | victim entity | filters / XP vcall `+0x244` / level `+0x27c` |

**Decompiler correction (2026-07-29):** raw `param_3` dual-use (state pointer **and** float addend) and default `+ 0.0` are **false**. Asm uses **distinct** arg2 (EBP = state) and arg5 (`[ESP+0x24]` = addend). No immediate `1.0f` / `0.0f` in the default store path.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Early reject if arg3 ≠ 0 | **High / Confirmed** | first insn `CMP [ESP+0xc],0` / `JNZ` fail |
| Early reject if Eval already complete | **High / Confirmed** | `CALL [vtbl+8](arg1, state)`; `TEST AL` / `JNZ` fail |
| Slot index = byte@req+0x08 | **High / Confirmed** | `MOVZX … [ESI+8]` on every mutate path |
| Slot address = `state+4+slot*4` | **High / Confirmed** | ` [EBP+EAX*4+0x4] `; matches Eval |
| Default / vehicle credit = `slot += arg5` | **High / Confirmed** | `ADDSS XMM0, [ESP+0x24]` @ `0x00613c6b`, `0x00613dca` |
| XP credit path = `slot += (float)victim.vcall(+0x244)` | **High / Confirmed** | when `req+0x13≠0` and victim non-null; `CVTSI2SS` |
| Cap gate: reject if required ≤ progress | **High / Confirmed** | `CVTSI2SS [ESI+0x18]`; `COMISS`; `JBE` fail (direct + type-0xe) |
| Vehicle branch flag = byte@req+0x10 | **High / Confirmed** | `CMP [ESI+0x10],AL` / `JZ` non-vehicle |
| Same-faction reject uses **arg1** not `unaff_EBP` | **High / Confirmed** | load chain from `[ESP+0x14]`; byte@`+0x532` vs victim |
| Vehicle bitmask gates `req+0x24` / `req+0x28` | **High** | `TEST 1<<faction`, `TEST 1<<byte@+0x531` |
| Vehicle success returns 1 **without** FailMission tail | **High / Confirmed** | early `MOV AL,1; RET 0x1c` @ `0x00613c79` |
| FailMission only on non-vehicle credit when `req+0x1c≠0` | **High / Confirmed** | tail @ `0x00613dd8`; then return 0 |
| Eval is pure-read (no store) | **High / Confirmed** | sibling unit; Precheck is sole local mutator here |
| arg6 unused in body | **High** | no `[ESP+0x28]` load in function listing |
| Bitmask / +0x531 / +0x532 English (race/faction) | **Probable** | offsets sealed; product names open |
| arg5 caller always passes 1.0f | **Tentative** | callee only adds whatever float is on stack |

---

## 5. Control flow (asm-sealed spine)

```
if arg3 != 0: return 0
if Kill_Eval(req, arg1, state): return 0          // already complete — no credit

if req.byte@+0x10:                                // vehicle-style path
  victim.vcall(+0x1d4) / (+0x210)(0) gates
  reject if arg1.faction@+0x532 == victim.faction@+0x532
  optional level band via nested +0x27c vs req+0x30/+0x34
  require bit req+0x24 for victim faction; bit req+0x28 for byte@+0x531
  slot += arg5; return 1                          // no FailMission

// non-vehicle
if req.byte@+0x12 == 0:                           // direct path
  if req.byte@+0x11 == 0:
    if req+0x14 != -1 and (int)CVTTSS2SI(arg4) != req+0x14: return 0
  else:
    if victim==0 or victim.vcall(+0x28c) != req+0x14: return 0
  if required <= slot: return 0
  if req+0x24 != -1: require victim.type@([+0xa8]+0x38) == req+0x24
  optional level band on victim +0x27c
  if req+0x13 and victim: slot += (float)vcall(+0x244); goto fail_tail
  else: slot += arg5
else:                                             // type-0xe entity path
  require victim.type == 0xe
  match CBID via FUN_005001f0 after +0x1d4
  if required <= slot: return 0
  optional level; XP flag → +0x244 else += arg5

fail_tail:
  if req.byte@+0x1c: FailMission(mission from req+4→+0x14c); return 0
  return 1
```

---

## 6. Seal: slot float increment vs Eval pure-read

| Unit | VA | Slot access | Side effect |
|---|---|---|---|
| **Kill_Eval** | `0x00613910` | `MOVSS` load `state+4+slot*4`; `COMISS` vs `(float)req+0x18` | **None** — no stores, no calls |
| **Kill_Precheck** | `0x00613b50` | same address formula | **`ADDSS` store** (arg5 or XP int→float) |
| **RecvObjectiveState** (cross) | `0x00809460` | slots 0–3 at `state+4..+0x10` | absolute dword overwrite from S2C `0x2071` |

**Interaction contract:**

1. Precheck prologue vcalls Eval; if already complete → **no** increment.
2. Non-vehicle paths also refuse credit when `required <= progress` (same threshold ints).
3. After Precheck bumps, later Eval pure-reads the new float.
4. Server `0x2071` absolute resync overwrites the same floats; Eval does not care who wrote.

**AutoCore port implication:** implement Precheck as filter + optional `progress[slot] += delta`; implement Eval as pure `progress[slot] >= required`. Do not put credit math inside Eval.

---

## 7. Gaps closed this residual pass

1. ~~Decomp `+ 0.0` default credit~~ → **`ADDSS [ESP+0x24]`** (arg5 float).
2. ~~`param_3` dual-use state/addend~~ → **arg2 = state (EBP), arg5 = addend**.
3. ~~`unaff_EBP` faction compare~~ → **arg1** entity chain; same-faction reject sealed.
4. ~~RET size / arity~~ → **`RET 0x1c`**, seven stack args.
5. ~~Eval pure-read vs Precheck mutate~~ → sealed (table above).
6. ~~Vehicle path FailMission~~ → **skips** FailMission; early return 1.

---

## 8. Remaining gaps

1. Runtime live kill → observe arg5 value and slot delta.
2. Product English for `+0x531`/`+0x532` and bitmask fields.
3. arg6 purpose (unused here; caller ABI).
4. Image bit-exact / binary diff policy.
5. Map req layout to server `ObjectiveRequirementKill` field names.

**Verdict:** **accept-with-gaps** — ABI, mutate paths, and Eval contrast sealed High; product names + runtime open.
