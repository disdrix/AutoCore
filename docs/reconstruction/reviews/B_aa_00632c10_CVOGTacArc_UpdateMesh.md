# Review B (skeptical / adversarial): `aa_00632c10` CVOGTacArc_UpdateMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632c10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00632c10_CVOGTacArc_UpdateMesh.md` |
| **Verdict** | **accept-with-gaps** on CF; vertex formula residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | No early fail | **Falsified — mesh/mat null → -1** |
| 2 | Ignores owner | **Falsified — reads owner fields** |
| 3 | Finished vertex formula | **Overstated** |
| 4 | Server authoritative cone | **Falsified — client mesh** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null mesh/mat gate | High | Crash/update skip |
| Owner angle/range sources | High | Wrong cone shape |
| Accessory +0x19c range add | Tentative | Missing range boost |
| Vertex math | Tentative | Visual glitch only |

---

## 3. Cross-check against raw

```
if !mesh||!mat return -1;
sample owner or cache angles/range; optional accessory; rebuild verts.
Clean ≡ raw CF outline; full float formula residual.
```

---

## 4. Surviving contract for AutoCore

```
UpdateMesh:
  client mesh refresh from owner weapon cone fields
  require InitializeMesh success first
  AutoCore combat does not depend on this mesh
  accessory vtbl+0x19c can grow displayed range
```

---

## 5. Open questions

1. Name owner cone fields.
2. Name FUN_0056a680.
3. Document segment formula vs param_1[10]=0x32.

**Verdict:** **accept-with-gaps** on CF; vertex formula residual
