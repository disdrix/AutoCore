# Review B (skeptical / adversarial): `aa_0059d880` CVOGObjective_GetCompleteCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d880` |
| **VA** | `0x0059d880` |
| **Review type** | Skeptical / adversarial dual residual |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0059d880_CVOGObjective_GetCompleteCount.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** (runtime open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Non-trivial logic / hash / vtable | Body is 2 instructions: load + ret | **Falsified** — pure getter |
| 2 | Returns progress / current pass count | Field is static on objective; gates **compare** walk counters against return | **Falsified** — **threshold**, not live progress |
| 3 | ECX is character | All 5 sites set ECX from objective / pending def / serializer this | **Falsified** — **objective** |
| 4 | Free function / no this | `mov eax,[ecx+0x164]` | **Falsified** — thiscall/fastcall this |
| 5 | Stack arguments | Bare `ret` | **Falsified** — zero stack formals |
| 6 | Double CALL is decompiler noise | Two real CALLs each in CompleteObjective + EvaluatePending | **Falsified** — dual CALL intentional (zero-test then compare) |
| 7 | Field name unknown / invented | `fprintf` format at `0x009d0638` = `<CompleteCount>%i</CompleteCount>` | **Falsified** — **product CompleteCount** |
| 8 | Offset is not 0x164 | Immediate in opcode `64 01 00 00` | **Falsified** — **+0x164** |
| 9 | More than 3 static callers | xrefs = 5 sites / 3 functions only | **Falsified** — inventory complete |
| 10 | CompleteObjective and EvaluatePending treat 0 identically | CO: `JLE` (≤0); EP: `JZ` (==0) | **Survives as call-site residual** — not a body claim |
| 11 | Getter mutates state | No stores | **Falsified** — read-only; setter is sibling `0x0059d890` |
| 12 | Return is byte/word only | `MOV EAX, dword ptr [...]` | **Falsified** — full **dword** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body load/ret | **High** | Port invents logic that does not exist |
| Offset +0x164 | **High** | Wrong template field → always fail/pass gates |
| Product CompleteCount | **High** | Naming drift vs mission XML / server ObjectiveMax |
| this = objective | **High** | Character-offset confusion |
| Caller inventory complete | **High** | Missed gate site |
| Threshold vs progress semantics | **High** | Double-count bugs in AutoCore Advance |
| Negative-value call-site split (JLE vs JZ) | **Tentative** (callers) | Rare if templates never negative |
| Retail method name | **Tentative** | Cosmetic |
| Runtime value samples | **Open** | Confirm XML values match live defs |

---

## 3. Cross-check against raw / live

Live decompile 2026-07-29 matches raw `aa_0059d880` body exactly:

```c
return *(undefined4 *)(param_1 + 0x164);
```

Live asm / memory strengthen:

* Opcode immediate confirms **0x164**
* No prologue/epilogue beyond `ret`
* Pad `cc` after function

XML dump path strengthens name beyond "min-pass" prose in older CompleteObjective residual notes — English is **CompleteCount**, role is min required passes.

Parent duals (`aa_00533f90`, `aa_00534920`) already sealed this unit as CompleteCount / min-pass; this dual **owns** the getter alone and re-seals with full xref + string + memory.

---

## 4. Surviving contract for AutoCore

```
// Objective definition threshold (template field)
uint32 GetCompleteCount(ObjectiveDef* o) {
  return *(uint32*)((uint8*)o + 0x164);
}

// Port rules:
//  - Do NOT implement as current progress (that is the walk counter in callers).
//  - Do NOT store ObjectiveMax in character DB if re-derivable from this template field
//    (see docs/missionState.md ObjectiveMax note).
//  - CompleteObjective gate: if CompleteCount <= 0 require allReqsOk|force;
//    else require nPassed >= CompleteCount | allReqsOk | force.
//  - EvaluatePending: (CompleteCount != 0 && CompleteCount <= success) || allTrue
//    (zero CompleteCount → allTrue arm only; signed-negative differs from CompleteObjective).
//  - XML dump / tools: tag is <CompleteCount>.
//  - this is objective layout, not character.
```

---

## 5. What would overturn this dual

1. Second body at this VA after image change (would need re-read).
2. Proof any CALL site passes non-objective ECX.
3. Alternate format string path writing different tag for same field.
4. Evidence `+0x164` is not the CompleteCount storage on live objective objects.

Until then, CF + field + callers stand at **High**.

---

## 6. Open questions (keep explicit)

1. Retail method name.
2. Do shipped mission templates ever set CompleteCount < 0?
3. Full load path: which XML parse writes via `FUN_0059d890`.
4. Live sample values vs mission XML.

**Verdict:** Attacks on "non-trivial / character this / progress counter / unknown name / decompiler dual CALL" are **dead**. Unit sealed. Residual is load-path ownership + runtime samples. **accept.**
