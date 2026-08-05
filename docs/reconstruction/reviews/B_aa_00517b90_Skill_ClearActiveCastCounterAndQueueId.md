# Review B (skeptical / adversarial): `aa_00517b90` Skill_ClearActiveCastCounterAndQueueId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517b90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual refresh; prior 2026-07-23 scaffold) |
| **Counterpart** | `reviews/A_aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md` |
| **Verdict** | **accept-with-gaps**; bookkeeping CF **sealed** |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | Validates cast allow / power / range | **Falsified** — only slot counter + deferred queue |
| 2 | Force-clears active-cast counter to 0 always | **Falsified** — **decrements** +0x10; zero only of **+0xC** when count hits 0 |
| 3 | Always returns 0 / void | **Falsified** — `AL` 0/1 from BL; `RET 4` |
| 4 | Return gates StartCastAgain on client cast paths | **Falsified for known xrefs** — 4/4 callers ignore AL (no TEST); check skill `+0x61c` after side-effect call |
| 5 | QueueDeferred `this` is outer skill/character | **Falsified** — third `FUN_005169c0` return (slot) moved to ECX |
| 6 | Pure stdcall, no ECX this | **Falsified** — `MOV ESI,ECX` at entry; thiscall-shaped |
| 7 | Field offsets unknown | **Falsified for +0x10/+0xC** — asm sealed; product **names** still open |
| 8 | Name implies wipe-all cast state | **Overstated** — does not clear active-cast **map** binding (`Skill_ClearCastBinding…` is sibling); only busy-slot counter/queue + deferred id push |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dec + conditional +0xC clear | **High** | Stuck busy / wrong LocalCastValidate code 6 |
| Always queue skill id | **High** | Miss deferred cast-again id |
| Return was-live | **High** | Doc only today (callers ignore) |
| slot+0x10 = busy refcount | **High** (behavior) | Wrong sim busy gate |
| +0xC product word | **INFERRED** | Mislabel only if CF held |
| Outer ECX type | Tentative | Wrong object in port |

---

## 3. Cross-check against raw / asm

```
ESI = this
BL = 0
slot = FUN_005169c0(this)
if (slot->+0x10 >= 1) {
  slot = FUN_005169c0(this)
  if (slot->+0x10 != 0) {
    slot->+0x10 -= 1
    if (slot->+0x10 == 0) slot->+0xC = 0
  }
  BL = 1
}
PUSH &nSkillId
slot = FUN_005169c0(this)
Skill_QueueDeferredCastId(slot, &nSkillId)
return BL
```

Prior B text “if counter: clear counter+queue id” was **wrong** (must not re-introduce). Clean ≡ raw CF outline; asm seals dec/RET/this.

Re-decompile 2026-07-29: same body; third-call arg display still decompiler-noisy — trust asm.

---

## 4. Surviving contract for AutoCore

```
// thiscall: ECX = owner with lazy slot at +0x64
char Skill_ClearActiveCastCounterAndQueueId(Owner* this, int nSkillId)
{
  // side effects: dec busy refcount; maybe clear slot+0xC; always enqueue skill id
  // return: 1 iff counter was live (>=1) at entry — currently unused by known client callers
}
```

Pair with:

* `FUN_005169c0` — slot factory (leave-FUN)
* `Skill_QueueDeferredCastId` — ring write
* `Skill_LocalCastValidate` — busy if `slot+0x10 != 0` → response **6**
* `Skill_ClearCastBindingAndMaybeRestartCd` — **map** binding clear (sibling; not this body)
* Client cast-again: after Clear, gate on skill **`+0x61c`** + no active binding, not on Clear’s AL

---

## 5. Open questions (post-residual)

1. Product names for slot fields and outer type of ECX.
2. Increment sites for +0x10 (who takes the busy ref).
3. Whether any **unlisted** caller consumes AL (xrefs = 4 only as of seal).
4. Runtime proof of queue ring vs LocalCastValidate busy interaction.

**Tighten note (2026-07-29 residual):** Adversarial re-check — name remains slightly misleading (“Clear” vs dec); **CF/ABI/offsets sealed High**; return **unused** by known callers; do **not** claim force-zero counter or StartCastAgain return-gate.

**Verdict:** **accept-with-gaps**; residual **sealed** (CF); product names / incrementer / runtime open
