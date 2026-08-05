# Review B (skeptical / adversarial): `aa_006334e0` CVOGTacArc_Initialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_006334e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_006334e0_CVOGTacArc_Initialize.md` |
| **Verdict** | **accept-with-gaps** on CF; owner field residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Works without owner | **Falsified — null → -1** |
| 2 | Skips UpdateMesh | **Falsified — UpdateMesh(0) on success** |
| 3 | Finished owner field map | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Owner +0x20 bind | High | Null deref later |
| InitializeMesh fail gate | High | Broken arc silent |
| Bounds from +0xe8 | Tentative | Wrong cone size |

---

## 3. Cross-check against raw

```
if !owner return -1; +0x20=owner; SetStateColor; InitializeMesh;
if ok && mesh: bounds from owner+0xe8; UpdateMesh(0); return status.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Initialize:
  bind owner; state color; build mesh; seed bounds; first UpdateMesh(0)
  fail fast on null owner or mesh init
  pair ctor defaults + UpdateMesh per-frame
```

---

## 5. Open questions

1. Name owner+0xe8.
2. Name FUN_0074b8f0.
3. Caller graph (weapon equip UI).

**Verdict:** **accept-with-gaps** on CF; owner field residual
