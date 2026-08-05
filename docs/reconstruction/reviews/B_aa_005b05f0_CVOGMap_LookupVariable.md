# Review B (skeptical / adversarial): `aa_005b05f0` CVOGMap_LookupVariable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b05f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005b05f0_CVOGMap_LookupVariable.md` |
| **Verdict** | **accept-with-gaps** on CF; computed path residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Creates missing vars | **Falsified — return 0** |
| 2 | Always computed | **Falsified — flag+0x40 gate** |
| 3 | Finished node layout | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hash+chain lookup | High | Wrong var value |
| Static vs computed split | High | Stale formula |
| Out write +0x48 | High | Garbage out |
| EvaluateComputed | Tentative | Wrong formula result |

---

## 3. Cross-check against raw

```
bucket walk; key match; if static *out=+0x48 ret1; if computed Evaluate; else 0.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
LookupVariable(map, id, out):
  O(chain) hash; no insert
  reactions must tolerate miss (0)
  pair SetVariable + GroupReactionCall variable path
  AutoCore map vars for missions/dialogs
```

---

## 5. Open questions

1. Name CVOGVariable_EvaluateComputed.
2. Publish variable node layout.

**Verdict:** **accept-with-gaps** on CF; computed path residual
