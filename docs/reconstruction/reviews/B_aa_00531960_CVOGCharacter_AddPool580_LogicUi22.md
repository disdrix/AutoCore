# Review B (skeptical / adversarial): `aa_00531960` CVOGCharacter_AddPool580_LogicUi22

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531960` |
| **VA** | `0x00531960` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00531960_CVOGCharacter_AddPool580_LogicUi22.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** (name English open only) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Sets pool absolute like skill/attrib helpers | Body is **`+=` delta** | **Falsified absolute** — additive |
| 2 | UI fires for any non-zero including negative | Gate is **`> 0` only** | **Falsified** |
| 3 | Negative delta skipped entirely in callee | Add still runs when delta ≤ 0 | **Falsified skip** — only UI skipped |
| 4 | CompleteObjective can apply negative | Caller `TEST/JLE` skips CALL | **Caller-gated** |
| 5 | Dirty only on positive | `OR \|1` after add always | **Falsified** |
| 6 | Same pool as skill/attrib | Different offsets + UI type 0x22 vs 0x21/0x23 | **Falsified merge** |
| 7 | "Reputation" product name sealed | No string | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+=` short at +0x580 | **High** | Wrong pool math |
| UI type 0x22 | **High** | Wrong client UI event |
| Additive vs absolute | **High** | Double-count if port sets absolute |
| Product English | **Low** | Misnamed field in DB |
| Multi-caller S2C paths | **High** (xrefs exist) | Incomplete inventory if assumed mission-only |

---

## 3. Surviving contract for AutoCore

```
// Port as additive short pool, NOT absolute set.
// LogicUI 0x22 only when delta > 0.
// Always dirty |1 when called.
// CompleteObjective only calls when obj+0x114 > 0.
// Do not invent "reputation" until string/XML seals name.
```

## 4. What would overturn

1. XML/serializer naming `+0x580`.
2. Proof UI type 0x22 maps to a known AutoCore enum already.
