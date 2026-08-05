# Review B (skeptical / adversarial): `aa_004cf100` Mission_FillType0RewardTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf100` |
| **VA** | `0x004cf100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cf100_Mission_FillType0RewardTable.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** on wrapper CF; **needs-more-evidence** on `FUN_0052c700` / `*def` English |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Uses character arg for fill | arg1 loaded and dropped | **Falsified** |
| 2 | Implements reward logic | Single CALL out | **Overstated if claimed rich** |
| 3 | Type-0 decision inside | Branch is CompleteObjective | **Falsified** |
| 4 | thiscall | Stack-only; RET 0xC | **Falsified** |
| 5 | `*param_1` is mission id always | Could be def header id field | **Probable** as key dword |
| 6 | Clean invents args | 3-arg shape matches listing | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper CF | **High** | — |
| Arity RET 0xC | **High** | Stack |
| Ignore character | **High** | Dead pass OK |
| Callee fill correctness | **Low** here | Empty rewards |

---

## 3. Surviving contract for AutoCore

```
// Keep 3-arg call shape for ABI match even though arg1 unused.
// Pair with rolled path FUN_004d08c0 on type short != 0.
// Do not port reward generation without dualing FUN_0052c700.
```
