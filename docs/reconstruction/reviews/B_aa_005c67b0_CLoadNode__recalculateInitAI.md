# Review B (skeptical / adversarial): `aa_005c67b0` CLoadNode__recalculateInitAI

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c67b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c67b0_CLoadNode__recalculateInitAI.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always enables AI | Falsified — many paths set 0 |
| 2 | Calls vtbl+0xc0 itself | Falsified — only sets flag |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag only vs attach | High | Expect attach here wrongly |
| type==2 gate | High | Skip recalc |

---

## 3. Cross-check against raw

```
_recalculateInitAI: if msg type 2: set +0x64 from TFID/float gates.
```

---

## 4. Surviving contract for AutoCore

```
Pre-initAI flag calculator; initAI consumes +0x64 elsewhere.
```

---

## 5. Open questions

1. Find dispatcher that reads +0x64 before initAI.

**Verdict:** **accept-with-gaps**
