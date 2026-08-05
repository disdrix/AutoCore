# Review A (reconstruction fidelity): `aa_0059da10` CVOGObjective_MatchTargetEvaluators_Slot44

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059da10` |
| **VA** | `0x0059da10` |
| **Canonical name** | `CVOGObjective_MatchTargetEvaluators_Slot44` |
| **Prior names** | `FUN_0059da10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw / dual residual) |
| **Counterpart** | `reviews/B_aa_0059da10_CVOGObjective_MatchTargetEvaluators_Slot44.md` |
| **System** | `interaction-activation` / missions active-objective match |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` on **objective instance**: walk evaluator pointer array half-open range `[this+0x158, this+0x15c)`. For each evaluator `e`, invoke `(*(e->vtbl + 0x44))(argA, argB)`. Return **1** on first non-zero char result; empty range / no hit → **0**.

Structurally a **slot-swapped clone** of sibling `aa_0059d9c0` / `CVOGObjective_MatchTargetEvaluators` (`0x0059d9c0`), which uses **`vtable+0x40`**.

Sole production caller: `CVOGCharacter_FindActiveObjectiveIdForPick` (`aa_005245d0` / `0x005245d0`) — pick/hover active-obj id walker. Sibling helper’s sole caller is `FindActiveObjectiveIdForInteract` (`0x00524520`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059da10_FUN_0059da10.md` (+ re-verify appends) |
| Annotated | `docs/reconstruction/raw/aa_0059da10_FUN_0059da10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_MatchTargetEvaluators_Slot44.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059da10_CVOGObjective_MatchTargetEvaluators_Slot44.md` |
| Sibling dual residual | `aa_0059d9c0` raw/clean @ `0x0059d9c0` |
| Parent walker | `aa_005245d0` ForPick (caller of this) |
| Sibling walker | `aa_00524520` ForInteract (caller of +0x40 helper) |
| Live decompile | Ghidra `batch_decompile` `0x0059da10`, `0x0059d9c0` (2026-07-29) |
| Live memory | Ghidra `read_memory` both bodies, 80 bytes (2026-07-29) |
| Callers / xrefs | `get_function_callers` / `get_xrefs_to` — **1** each |

---

## 3. Control flow (authoritative raw / live)

```
CVOGObjective_MatchTargetEvaluators_Slot44(objective this, argA, argB):
  it  = *(objective + 0x158)   // evaluator** begin
  end = *(objective + 0x15c)   // evaluator** end (half-open)
  if it == end: return 0
  do:
    eval = *it                 // evaluator object*
    vtbl = *eval
    c = (*(vtbl + 0x44))(argA, argB)   // THIS slot — not +0x40 / +0x38
    if c != 0: return 1
    it = it + 1                // +4 bytes (pointer stride)
  while it != end
  return 0
```

Calling convention from body (memory):

- Prologue saves `EBX/EBP/ESI/EDI`; `EDI = ECX` (this).
- Loads `ESI = [EDI+0x158]`, compares to `[EDI+0x15c]`.
- Stack formals: `[ESP+…]` loaded as `EBX`/`EBP` then pushed as args before `call [EAX+imm8]`.
- Epilogue: `ret 8` (`c2 08 00`) — **two stack dwords** + thiscall ECX → **3-arg thiscall**.
- Success path: `mov al,1`; fail path: `xor al,al`.

---

## 4. Dual residual vs `0x0059d9c0` (sealed static)

Bodies sit **back-to-back**:

| | `aa_0059d9c0` | `aa_0059da10` (this) |
|---|---|---|
| Entry | `0x0059d9c0` | `0x0059da10` |
| Body end (Ghidra) | `0x0059da09` | `0x0059da59` |
| Size | 0x4A bytes (+ align pad) | 0x4A bytes (+ align pad) |

### 4.1 Byte identity

`read_memory` 80 bytes at each entry (2026-07-29). Instruction stream is **identical except one immediate**:

| Offset in body | Bytes (`d9c0`) | Bytes (`da10`) | Meaning |
|---|---|---|---|
| `+0x00..+0x26` | identical | identical | push/setup, load begin/end, load args, deref eval |
| **`+0x27`** | **`ff 50 40`** | **`ff 50 44`** | **`call dword ptr [eax + slot]`** |
| `+0x2A..end` | identical | identical | test al; advance it; loop; ret 8 paths |

Hex (this unit, through epilogues):

```text
53 55 56 57 8b f9 8b b7 58 01 00 00 3b b7 5c 01 00 00 74 24
8b 5c 24 18 8b 6c 24 14 8d 64 24 00 8b 0e 8b 01 53 55
ff 50 44    ; sibling: ff 50 40
84 c0 75 14 83 c6 04 3b b7 5c 01 00 00 75 e8
5f 5e 5d 32 c0 5b c2 08 00
5f 5e 5d b0 01 5b c2 08 00
```

**Residual of the dual pair = only the vtable slot immediate (`0x40` vs `0x44`).** No second difference in range offsets, return shape, loop stride, or stack arity.

### 4.2 Behavioral residual table

| Dimension | Sibling `0x0059d9c0` | This `0x0059da10` | Residual |
|---|---|---|---|
| this layout | `+0x158` / `+0x15c` | same | **none** |
| Eval pointer stride | `+4` | same | **none** |
| Match policy | first true → 1 | same | **none** |
| Empty range | 0 | same | **none** |
| Stack arity | `ret 8` (2 args) | same | **none** |
| **Vtbl slot** | **`+0x40`** | **`+0x44`** | **only CF difference** |
| Sole caller | `FUN_00524520` ForInteract | `FUN_005245d0` ForPick | caller family |
| Product role (inferred) | interact id match | pick/hover id match | via callers only |

### 4.3 Slot family (do not merge)

| Slot | Helper / path | Returns upstream |
|---|---|---|
| **`+0x38`** | inline in `Client_FindObjectiveMatchingTarget` `0x00525bd0` | **def\*** (+ pending gate) |
| **`+0x40`** | `aa_0059d9c0` ← ForInteract `0x00524520` | **objective id** |
| **`+0x44`** | **this** ← ForPick `0x005245d0` | **objective id** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall (Objective*, A, B) → u32` (0/1) | **High** | `ret 8`; ECX=this; al return |
| Range `[+0x158, +0x15c)` pointer array | **High** | decompile + `8b b7 58 01 00 00` / `5c 01 00 00` |
| Slot **vtable+0x44** | **High** | decompile + `ff 50 44` memory |
| Clone of `0059d9c0` except slot | **High** | full byte dual residual = 1 imm |
| First hit → 1; empty → 0 | **High** | both paths in body |
| this = objective (not character) | **High** | layout + sole caller ECX=objInst |
| Sole xref = ForPick `0x005245d0` | **High** | callers + xrefs |
| argA/argB ≈ (character, worldObject) | **Probable** | sole caller pushes those; implementers open |
| Name `…MatchTargetEvaluators_Slot44` | **Probable** | role parallel to sibling; retail +0x44 word open |
| Product semantic ≠ +0x40 per type | **Tentative / Open** | callers differ; eval bodies not dualed |
| Runtime / binary-diff suite | **Open** | static sealed only |

---

## 6. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Load begin/end at `+0x158`/`+0x15c` | **Yes** |
| Loop until end | **Yes** (clean `while`; raw `if`+`do-while` ≡) |
| Call vtbl **`+0x44`** with (argA, argB) | **Yes** |
| First non-zero → return 1 | **Yes** |
| Exhaust / empty → 0 | **Yes** |
| No extra gates | **Yes** |

Clean does not invent fields or merge with `+0x40` helper.

---

## 7. Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (sole) | `CVOGCharacter_FindActiveObjectiveIdForPick` @ `0x005245d0` (`0052465a` UNCONDITIONAL_CALL) | ECX=objInst; stack (char, world) |
| Callees | **indirect only** — eval vtbl **`+0x44`** | no direct `FUN_*` |

Parent’s own callers (not this unit): `Client_InteractClickPickTarget` `0x009247b0`, `FUN_00925820`, `FUN_00490070`.

---

## 8. Gaps / open (residual of *this* unit)

1. **Per-requirement `vtable+0x44` implementers** — which objective/requirement types have non-trivial predicates (may no-op / always false).
2. **Product name** of the +0x44 method (vs +0x40 “interact match” vs +0x38 MatchTarget).
3. **Whether +0x44 ≡ +0x40** for any concrete type (possible alias / possible distinct filter).
4. Runtime first-wins under multi-evaluator objectives on pick/hover.
5. Sibling `aa_0059d9c0` still `FUN_*` in Ghidra (cosmetic; out of OWN ONLY).

**Verdict:** Control flow, slot, and dual residual vs `0x0059d9c0` are **High / sealed**. Name **Probable**. Remaining residual is **eval implementers + product slot word**, not this helper’s CF. **accept-with-gaps.**
