# Review B (skeptical / adversarial): `aa_005355a0` CVOGCharacter_AddCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_005355a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005355a0_CVOGCharacter_AddCredits.md` |
| **Verdict** | **accept** on additive money CF; **needs-more-evidence** on type-5 enum / currency units |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets absolute money | **Falsified** — additive only |
| 2 | Always toasts / UI floater | **Falsified** — no UI in body; only pending eval |
| 3 | Type 5 proven as Money enum | **Inferred** — single call site pattern, not sealed enum table |
| 4 | Float cast preserves full int64 | **Risk** — large deltas lose precision in eval path only |
| 5 | Clamps at 0 | **Falsified** — no clamp; wrap possible |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Additive +0x720 | High | Absolute overwrite corrupts money |
| Pending re-eval hook | High | Money objectives never advance |
| Type code 5 | Probable | Wrong eval context |
| Base-1000 decomposition | External doc | Display/server mismatch if wrong unit |

---

## 3. Cross-check against raw

```
money64(this+0x720) += delta
EvaluatePendingObjectives(this, 5, (float)delta, 0, 0)
return money64
```

Clean matches. Packet duals already distinguish additive GiveCredits vs absolute money set opcodes.

---

## 4. Surviving contract for AutoCore

```
AddCredits(character, int64 delta) -> int64 newAbsolute
  character.money += delta
  re-evaluate pending objectives with money context (5)
  no toast, no clamp, no server round-trip in this function
```

---

## 5. Open questions

1. Seal pending-eval type enum (money=5).
2. Negative credit / trade spend path sharing.
3. Whether float truncation matters for money objectives.
4. Live capture after GiveCredits 0x20xx and mission final credit.

**Verdict:** Accept additive CF; keep currency unit and enum as external/open.
