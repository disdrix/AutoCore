# Review B (skeptical / adversarial): `aa_00633590` CVOGTacArc_vdtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00633590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00633590_CVOGTacArc_vdtor.md` |
| **Verdict** | **accept** (trivial CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always free | **Falsified — gated by bit0** |
| 2 | Inline full teardown here | **Falsified — helper owns teardown** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar deleting pattern | High | Heap leak/double-free |
| Helper first | High | Use-after-free if inverted |

---

## 3. Cross-check against raw

```
dtor_helper(); if (flags&1) delete this; return this.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
vdtor:
  MSVC scalar deleting dtor; always helper then free if bit0
  pair ctor + dtor_helper
```

---

## 5. Open questions

1. Xrefs for allocation path.

**Verdict:** **accept** (trivial CF clear)
