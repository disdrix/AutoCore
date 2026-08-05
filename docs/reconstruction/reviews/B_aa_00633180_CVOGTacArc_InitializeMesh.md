# Review B (skeptical / adversarial): `aa_00633180` CVOGTacArc_InitializeMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00633180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00633180_CVOGTacArc_InitializeMesh.md` |
| **Verdict** | **accept-with-gaps** on CF outline; **needs-more-evidence** on D3D helper map |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Pure math no assets | **Falsified — fx/dds strings** |
| 2 | Always succeeds | **Overstated — multi fail returns** |
| 3 | Finished D3D helper names | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Asset names | High | Missing files = invisible arc |
| Status return contract | High | Initialize ignores fail |
| Pointer store offsets | Tentative | UpdateMesh null |
| FUN graph | Tentative | Port incomplete |

---

## 3. Cross-check against raw

```
load fx/dds; create mesh/mat; multi FUN helpers; return status.
Clean ≡ raw CF outline; helper names open.
```

---

## 4. Surviving contract for AutoCore

```
InitializeMesh:
  retail assets NDTacArc.fx + veh_tacarc.dds (+ effect dds)
  mesh at +0x18, mat at +0x1c (family) required by UpdateMesh/SetStateColor
  AutoCore server: no port; client visual only
```

---

## 5. Open questions

1. Name FUN_00989e00 family.
2. Seal failure codes.
3. Device reset path.

**Verdict:** **accept-with-gaps** on CF outline; **needs-more-evidence** on D3D helper map
