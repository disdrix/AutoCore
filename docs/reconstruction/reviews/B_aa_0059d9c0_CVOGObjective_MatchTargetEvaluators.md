# Review B (skeptical / adversarial): `aa_0059d9c0` CVOGObjective_MatchTargetEvaluators

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d9c0` |
| **VA** | `0x0059d9c0` |
| **Review type** | Skeptical / adversarial dual residual |
| **Date** | `2026-07-29` (strengthen) |
| **Counterpart** | `reviews/A_aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same slot as SendUseObject MatchTarget (+0x38) | Body is `call [eax+0x40]`; UseItem MatchTarget lives at **+0x38** (`0x0060d7f0`) | **Falsified** — slot **+0x40** |
| 2 | `this` is character (because sole caller is character method) | Call site `MOV ECX,EDI` with `EDI=objInst`; body reads objective `+0x158/+0x15c` | **Falsified** — **this = objective** |
| 3 | Clean invents arity `Match(obj, char, world)` | `RET 8` + ECX thiscall; sole caller pushes two dwords after setting ECX | **Falsified as overclaim** — clean matches real MSVC shape; raw call-site under-types |
| 4 | OR-all / score / last-match | First non-zero `AL` returns 1 immediately; no accumulator | **Falsified** — **first true wins** |
| 5 | Empty evaluator range is error / assert | Empty falls through `XOR AL,AL; RET 8` quietly | **Falsified** — returns **0** |
| 6 | Same function as Slot44 helper `0059da10` | Bodies identical except imm `40` vs `44`; different sole callers | **Falsified** — sibling pair, not aliases |
| 7 | Same function as FindObjectiveMatchingTarget | Different slot (+0x40 vs +0x38), different return (bool vs def* upstream), no pending gate here | **Falsified** — parallel family |
| 8 | All objective types implement useful +0x40 | Collect/Kill/Deliver sample: +0x40 = always-false stub `004cc820`; UseItem +0x40 = **SerializeXml** | **Partially survives as residual** — many types never match via this path |
| 9 | +0x40 is the MatchTarget product name | UseItem real MatchTarget is +0x38; +0x40 elsewhere is SerializeXml / stub | **Survives as role label only** — do not equate to +0x38 English |
| 10 | Return is full EAX meaningful non-0/1 | Success `MOV AL,1` only; fail `XOR AL,AL`; caller tests **AL** | **Falsified as wide int** — **bool 0/1 in AL** (u32 presentation OK) |
| 11 | Multiple static callers | Xrefs = single `005245aa` | **Falsified** — **sole caller** ForInteract |
| 12 | Eval virtuals ignore stack arity | Shared stub `004cc820` is `RET 8`; body pushes two args | **Falsified** — **ret-8 thiscall** on eval too |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range / stride / first-true / empty to 0 | **High** | Hang, miss match, wrong id |
| Slot +0x40 (not 38/44) | **High** | Never match / match wrong class |
| ABI `ret 8` thiscall objective | **High** | Stack smash on port |
| Sole caller + (char, world) binding | **High** | Wrong args into every eval |
| Distinct from +0x38 / +0x44 paths | **High** | Merge breaks IfInteractable vs UseObject vs pick |
| Sample stub matrix (Collect/Kill/Deliver +0x40) | **High** (those types) | Over-expect interact id for cargo/kill/deliver |
| UseItem +0x40 = SerializeXml (not match) | **High** (DATA + body) | Confirms UseItem uses +0x38 path |
| Full non-stub +0x40 implementer map | **Open** | Silent no-match on exotic objectives |
| Product English for +0x40 | **Tentative** | Naming only |
| Runtime multi-eval order | **Open** | Non-deterministic first id |

---

## 3. Cross-check against raw / live

Live decompile 2026-07-29 matches raw `aa_0059d9c0` body:

* `puVar2 = *(this+0x158)` vs end `+0x15c`
* `call *(**puVar2 + 0x40)(param_2, param_3)`
* first true to 1; fall through to 0

Live **asm** strengthens what decompiler understates:

* `RET 0x8` both paths (not bare `RET`)
* Return width is **AL**
* Sibling `0059da10` is byte-identical except `ff 50 44`

Sole-caller asm at `0x005245aa` strengthens ECX/arg binding beyond decompiler two-formal presentation.

Default stub `FUN_004cc820` (`XOR AL,AL; RET 8`) proves empty-match ABI is intentional and shared.

---

## 4. Surviving contract for AutoCore

```
// Objective-side evaluator walk for interact id (ForInteract path)
bool MatchTargetEvaluators_Plus40(Objective* o, Character* ch, Object* world) {
  for (Evaluator* e : o->evaluators /* [+0x158, +0x15c) */) {
    if (e->vtbl[+0x40](ch, world)) return true;  // first hit
  }
  return false;
}

// Port rules:
//  - Do NOT use +0x38 (UseObject MatchTarget / FindObjectiveMatchingTarget).
//  - Do NOT use +0x44 (pick/hover Slot44 helper).
//  - Do NOT assume UseItem MatchTarget is on this slot (it is +0x38).
//  - Do NOT assume Collect/Kill/Deliver can match here (sample +0x40 = always-false).
//  - Empty evaluator list -> false (not error).
//  - this is objective instance, not character.
//  - ABI: thiscall + two stack dwords; callee cleans 8.
```

---

## 5. What would overturn this dual

1. Second production CALL site to `0x0059d9c0` with different this/arg roles.
2. Disassembly showing call imm is not `+0x40` (would invert slot seal).
3. Proof ECX into the call is not objective payload (would invert this).
4. Evidence objective evaluator range is not `+0x158/+0x15c` on live instances.

Until then, helper CF + ABI + sole-caller binding stand at **High**.

---

## 6. Open questions (keep explicit)

1. Which requirement types install a **non-stub, non-SerializeXml** `+0x40` that can return true for interact?
2. Product name of that virtual (retail / PDB).
3. Whether any type shares one body across +0x38 / +0x40 / +0x44.
4. Live multi-active first-wins order for ForInteract packet id.

**Verdict:** Prior "same as MatchTarget +0x38 / this=character / free-arity" attacks are **dead**. CF and ABI sealed. Residual is **implementer matrix + English**, not the loop. **accept-with-gaps.**
