# Review B (skeptical / adversarial): `aa_00632a20` CVOGTacArc_SetStateColor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632a20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00632a20_CVOGTacArc_SetStateColor.md` |
| **Verdict** | **accept-with-gaps** on CF; enum names residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Interpolates colors | **Falsified — hard tables only** |
| 2 | No material update | **Falsified — MatZFailColor when +0x1c** |
| 3 | Finished state enum names | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Four-state color tables | High | Wrong arc tint |
| +0x24 state storage | High | Stale UI state |
| MatZFailColor path | Tentative | Z-fail silhouette wrong |

---

## 3. Cross-check against raw

```
+0x24=state; write RGB for 0/1/2/else; if mat: set MatZFailColor.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetStateColor:
  discrete state→RGBA; optional shader MatZFailColor
  AutoCore server ignores; client combat UI only
  pair Initialize (calls with param_3) + UpdateMesh
```

---

## 5. Open questions

1. Name state enum from callers.
2. Document channel layout +0x30..+0x37.

**Verdict:** **accept-with-gaps** on CF; enum names residual
