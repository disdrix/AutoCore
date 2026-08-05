# Review B (skeptical / adversarial): `aa_00792600` UI_HostPrepChildTree

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792600` |
| **VA** | `0x00792600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00792600_UI_HostPrepChildTree.md` |
| **Evidence** | Live decompile; CreateChildWidgets callers; strings |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Builds full dialog widgets | **Falsified** | Prep only; widgets allocated after return in callers |
| 2 | No-op / empty stub | **Falsified** | Alloc helpers, hash walk, optional Directional |
| 3 | Always rebuilds Directional | **Falsified** | Gated on `+0xbf` and `+0x30` |
| 4 | Safe unlocked hash walk | **Falsified** | Explicit lock flags + HashError strings |
| 5 | Server-side | **Falsified** | Client UI CreateChildWidgets fan-in |
| 6 | Clean invents strings | **Falsified** | In raw |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Prep-before-create role | **High** | Double-children / leak if skipped |
| Hash lock discipline | **High** | UI hash corruption |
| Directional optional | **High CF** | — |
| Offset English | **Tentative** | Layout port |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
UI_HostPrepChildTree(host):
  optional resolution invalidate
  clear host bookkeeping
  rebuild or reattach child-hash head
  locked traverse: detach each hashed child
  unlock
```

Callers must still construct widgets after this returns.

**Verdict:** **accept-with-gaps**
