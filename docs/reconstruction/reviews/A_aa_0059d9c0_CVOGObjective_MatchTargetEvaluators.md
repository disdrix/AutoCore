# Review A (reconstruction fidelity): `aa_0059d9c0` CVOGObjective_MatchTargetEvaluators

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d9c0` |
| **VA** | `0x0059d9c0` |
| **Canonical name** | `CVOGObjective_MatchTargetEvaluators` (proposed) |
| **Prior names** | `FUN_0059d9c0`; auto-alias noise `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059d9c0` |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw / dual residual) |
| **Counterpart** | `reviews/B_aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| **System** | `interaction-activation` / missions active-objective match |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` on **objective instance**: walk evaluator pointer array half-open range `[this+0x158, this+0x15c)`. For each evaluator `e`, invoke `(*(e->vtbl + 0x40))(argA, argB)`. Return **1** on first non-zero `AL` result; empty range / no hit → **0**.

This is the **+0x40 evaluator path** used by `CVOGCharacter_FindActiveObjectiveIdForInteract` (`aa_00524520` / `0x00524520`) to decide which active objective id to wire for interact / IfInteractable.

Structurally a **slot-swapped clone** of sibling `aa_0059da10` / `CVOGObjective_MatchTargetEvaluators_Slot44` (`0x0059da10`), which uses **`vtable+0x44`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (named) | `docs/reconstruction/raw/aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| Raw (scaffold) | `docs/reconstruction/raw/aa_0059d9c0_FUN_0059d9c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d9c0_FUN_0059d9c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_MatchTargetEvaluators.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| Sibling dual | `aa_0059da10` Slot44 A/B |
| Parent walker | `aa_00524520` FindActiveObjectiveIdForInteract |
| Contrast matcher | `aa_00525bd0` FindObjectiveMatchingTarget (inline eval **`+0x38`**) |
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` `0x0059d9c0`, `0x00524520`, `0x0059da10` (2026-07-29) |
| Live assembly | Ghidra `disassemble_function` `0x0059d9c0`, `0x0059da10`, `0x004cc820` |
| Live memory | Ghidra `read_memory` body @ `0x0059d9c0` (80 B); Collect vtbl `0x009e12c4`; Kill vtbl `0x009e19e4`; Deliver vtbl `0x009e0f24`; UseItem MatchTarget DATA `0x009dfc5c` |
| Call site asm | `get_assembly_context` xref `0x005245aa` |
| Xrefs | **1** UNCONDITIONAL_CALL from `FUN_00524520` @ `0x005245aa` |

---

## 3. Control flow (authoritative asm / live)

```
CVOGObjective_MatchTargetEvaluators(objective this /*ECX*/, argA, argB):
  it  = *(objective + 0x158)   // evaluator** begin
  end = *(objective + 0x15c)   // evaluator** end (half-open)
  if it == end: return 0       // AL = 0
  do:
    eval = *it                 // evaluator object*
    vtbl = *eval
    // thiscall on eval: ECX=eval; push argB; push argA; call [vtbl+0x40]
    c = (*(vtbl + 0x40))(argA, argB)
    if c != 0: return 1        // AL = 1
    it = it + 1                // +4 bytes (pointer stride)
  while it != end
  return 0
```

### 3.1 Full body listing (Ghidra disassemble)

```text
0059d9c0  PUSH EBX / EBP / ESI / EDI
0059d9c4  MOV  EDI, ECX                    ; this = objective
0059d9c6  MOV  ESI, [EDI+0x158]            ; begin
0059d9cc  CMP  ESI, [EDI+0x15c]            ; end
0059d9d2  JZ   fail                        ; empty → 0
0059d9d4  MOV  EBX, [ESP+0x18]             ; argB (after 4 pushes + ret)
0059d9d8  MOV  EBP, [ESP+0x14]             ; argA
0059d9e0  MOV  ECX, [ESI]                  ; eval*
0059d9e2  MOV  EAX, [ECX]                  ; vtbl*
0059d9e4  PUSH EBX                         ; argB
0059d9e5  PUSH EBP                         ; argA
0059d9e6  CALL dword ptr [EAX+0x40]        ; *** slot +0x40 ***
0059d9e9  TEST AL, AL
0059d9eb  JNZ  success
0059d9ed  ADD  ESI, 4
0059d9f0  CMP  ESI, [EDI+0x15c]
0059d9f6  JNZ  0059d9e0
fail:
0059d9f8  …restore…  XOR AL,AL  POP EBX  RET 8
success:
0059da01  …restore…  MOV AL,1   POP EBX  RET 8
```

Body hex (through both epilogues) — **sealed** `read_memory` 2026-07-29:

```text
53 55 56 57 8b f9 8b b7 58 01 00 00 3b b7 5c 01 00 00 74 24
8b 5c 24 18 8b 6c 24 14 8d 64 24 00 8b 0e 8b 01 53 55
ff 50 40
84 c0 75 14 83 c6 04 3b b7 5c 01 00 00 75 e8
5f 5e 5d 32 c0 5b c2 08 00
5f 5e 5d b0 01 5b c2 08 00
```

---

## 4. ABI seal (High)

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = **objective** | `MOV EDI,ECX`; reads `+0x158/+0x15c` objective layout | **High** |
| **Two** stack formals | Both epilogues `RET 0x8` (`c2 08 00`) | **High** |
| Return in **AL** as 0/1 | `XOR AL,AL` / `MOV AL,1`; caller `TEST AL,AL` | **High** |
| Eval virtual ABI also `ret 8` thiscall | pushes argB then argA; ECX=eval; default stub `004cc820` is `XOR AL,AL; RET 8` | **High** |
| No third stack formal | No load of `[ESP+0x1c]`+ | **High** |

Canonical signature:

```c
// AL / zero-extended dword presentation both OK
std::uint32_t __thiscall CVOGObjective_MatchTargetEvaluators(
    void* objective, void* argA, void* argB);
```

---

## 5. Sole caller seal — FindActiveObjectiveIdForInteract

| Claim | Evidence | Conf |
|---|---|---|
| Only production call | `get_function_xrefs` / callers → **1** site `0x005245aa` in `FUN_00524520` | **High** |
| ECX = objective instance | Call site: `MOV ECX,EDI` where `EDI = [node+8]` objInst | **High** |
| argA = **character**, argB = **worldObject** | `PUSH EAX` (world from stack formal), `PUSH EBX` (character this of walker), then `CALL 0059d9c0` | **High** |
| Match sense | After call: `TEST AL,AL` / `JZ continue`; on hit `MOV EBP,[EDI+0x10]` (objective id) | **High** |

Call-site fragment (`get_assembly_context` 2026-07-29):

```text
00524597  MOV  EDI, [ESI+8]          ; objInst
0052459e  TEST EDI, EDI
005245a0  JZ   unlock
005245a2  MOV  EAX, [ESP+0x14]       ; worldObject
005245a6  PUSH EAX                   ; argB
005245a7  PUSH EBX                   ; argA = character (walker this)
005245a8  MOV  ECX, EDI              ; this = objective
005245aa  CALL 0x0059d9c0
005245af  TEST AL, AL
005245b1  JZ   continue_walk
005245b3  MOV  EBP, [EDI+0x10]       ; objective id
```

**Ghidra call-site decompile under-types** as `FUN_0059d9c0(param_1, param_2)` (hides this in ECX). Clean `FUN_0059d9c0(obj, char, world)` is the real MSVC shape — **not** an invented third formal beyond thiscall.

---

## 6. Dual residual vs Slot44 `0x0059da10` (sealed)

Bodies sit **back-to-back**. Instruction stream is **identical except one immediate**:

| Offset in body | Bytes (`d9c0`) | Bytes (`da10`) | Meaning |
|---|---|---|---|
| `+0x00..+0x26` | identical | identical | push/setup, load begin/end, load args, deref eval |
| **`+0x27`** | **`ff 50 40`** | **`ff 50 44`** | **`call dword ptr [eax + slot]`** |
| `+0x2A..end` | identical | identical | test al; advance it; loop; ret 8 paths |

| Dimension | This `0x0059d9c0` | Sibling `0x0059da10` | Residual |
|---|---|---|---|
| this layout | `+0x158` / `+0x15c` | same | **none** |
| Eval pointer stride | `+4` | same | **none** |
| Match policy | first true → 1 | same | **none** |
| Empty range | 0 | same | **none** |
| Stack arity | `ret 8` | same | **none** |
| **Vtbl slot** | **`+0x40`** | **`+0x44`** | **only CF difference** |
| Sole caller | ForInteract `0x00524520` | ForPick `0x005245d0` | caller family |

### Slot family (do not merge)

| Slot | Helper / path | Upstream return |
|---|---|---|
| **`+0x38`** | inline in `Client_FindObjectiveMatchingTarget` `0x00525bd0` | **def\*** (+ pending `+0x55c`) |
| **`+0x40`** | **this** ← ForInteract `0x00524520` | **objective id** `@+0x10` |
| **`+0x44`** | Slot44 ← ForPick `0x005245d0` | **objective id** `@+0x10` |

---

## 7. Implementer samples (residual strengthen — not full matrix)

Default always-false stub shared by many slots:

```text
004cc820  XOR AL, AL
004cc822  RET 8          ; matches match-predicate ABI
```

| Requirement class | Vtable base | Slot `+0x38` | Slot `+0x40` | Slot `+0x44` | Notes |
|---|---|---|---|---|---|
| **Collect** | `PTR_FUN_009e12c4` (ctor `0x00611690`) | `004cc820` stub | **`004cc820` stub** | `004cc820` stub | Interact id-path never matches Collect |
| **Kill** | `0x009e19e4` | `004cc820` stub | **`004cc820` stub** | `0x00613eb0` (non-stub) | Interact no; pick may |
| **Deliver** | `0x009e0f24` | `0x00610f20` (non-stub) | **`004cc820` stub** | `004cc820` stub | UseObject +0x38 path; not +0x40 |
| **UseItem** | MatchTarget DATA @ `0x009dfc5c` ⇒ base `0x009dfc24` | `0x0060d7f0` → `FUN_0060d460` | **`0x0060d800` SerializeXml** | (next dword) | **+0x40 is NOT a match predicate** |

**Sealed product implication:** ForInteract’s +0x40 helper does **not** reuse UseItem’s MatchTarget (+0x38). UseItem world-object matching for UseObject is the **`+0x38`** / `FindObjectiveMatchingTarget` path. Types that only stub `+0x40` will never contribute an interact objective id via this unit.

Non-stub **interact-specific** `+0x40` implementers (which requirement classes actually return true here) remain **open** beyond the sample matrix.

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall (Objective*, A, B) → 0/1 in AL` | **High** | `ret 8`; dual epilogues |
| Range `[+0x158, +0x15c)` pointer array | **High** | decompile + `8b b7 58/5c 01 00 00` |
| Slot **vtable+0x40** | **High** | `ff 50 40` memory |
| Clone of `0059da10` except slot | **High** | full byte dual residual = 1 imm |
| First hit → 1; empty → 0 | **High** | both paths |
| this = objective (not character) | **High** | layout + sole-caller ECX=objInst |
| Sole xref = ForInteract `0x00524520` | **High** | callers + xrefs |
| argA/argB = (character, worldObject) on production path | **High** | sole caller push order sealed |
| Name `CVOGObjective_MatchTargetEvaluators` | **Probable** | role; retail method word open |
| Per-type product meaning of +0x40 | **Tentative / Open** | sample stubs + UseItem SerializeXml sealed; full matrix open |
| Runtime / bit-exact suite | **Open** | static only |

---

## 9. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Load begin/end at `+0x158`/`+0x15c` | **Yes** |
| Loop until end | **Yes** (clean `while`; raw `if`+`do-while` ≡) |
| Call vtbl **`+0x40`** with (argA, argB) | **Yes** |
| First non-zero → return 1 | **Yes** |
| Exhaust / empty → 0 | **Yes** |
| No extra gates | **Yes** |
| Clean 3-arg thiscall arity | **Yes (intent)** — documents ECX+2 stack; raw Ghidra call-site under-typed |

Scaffold `FUN_0059d9c0.cpp` (if present) is a direct dump; prefer named clean.

---

## 10. Gaps / open (residual of *this* unit)

1. **Full matrix of non-stub `vtable+0x40` implementers** — which requirement types can ever return true on ForInteract.
2. **Product English** for the +0x40 method (vs +0x38 MatchTarget / +0x44 pick).
3. Whether any type aliases +0x40 to the same body as +0x38 or +0x44.
4. Multi-evaluator first-wins order under live multi-active objectives (runtime).
5. Ghidra still shows `FUN_0059d9c0` (cosmetic rename; out of behavior residual).

**Verdict:** Control flow, ABI (`ret 8`), slot `+0x40`, sole-caller arg binding, and dual residual vs Slot44 are **High / sealed**. Sample implementer matrix strengthens “not every objective type participates.” Remaining residual is **non-stub +0x40 bodies + product slot word**, not this helper’s CF. **accept-with-gaps.**
