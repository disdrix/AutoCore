# Review B (skeptical / adversarial): `aa_00632900` CVOGTacArc_dtor_helper

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00632900_CVOGTacArc_dtor_helper.md` |
| **Verdict** | **accept** (CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Frees this always | **Falsified — helper only; vdtor free flag** |
| 2 | No mesh free | **Falsified — delete__ [0xb]** |
| 3 | Skips embed teardown | **Falsified — vcall(1) + FUN pair** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mesh + embed free order | High | Double-free / leak |
| FUN teardown pair | High | SEH mismatch |
| Pointer field map | Tentative | Wrong slot free |

---

## 3. Cross-check against raw

```
*this=vtbl; free [0xb]; vcall dtor [6]; FUN_0096f510; FUN_0096efd0 x2.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
dtor_helper:
  release mesh buffer + embedded object; paired FUN teardown
  pair vdtor (free this if flags&1)
  AutoCore: N/A server-side
```

---

## 5. Open questions

1. Name embed class at [6].
2. Confirm [0xb] is VB/IB only.

**Verdict:** **accept** (CF clear)
