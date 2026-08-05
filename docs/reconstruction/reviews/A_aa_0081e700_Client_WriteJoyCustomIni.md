# Review A (reconstruction fidelity): `aa_0081e700` Client_WriteJoyCustomIni

| Field | Value |
|---|---|
| **Stable ID** | `aa_0081e700` |
| **VA** | `0x0081e700` |
| **Canonical name** | `Client_WriteJoyCustomIni` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0081e700_Client_WriteJoyCustomIni.md` |
| **System tag** | `input-drive-control` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_WriteJoyCustomIni.cpp` |
| Raw | `docs/reconstruction/raw/aa_0081e700_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Write joy_custom.ini template including Drive axes (Accelerate/Reverse) and QuickBarNext/Prev/Use/Page bindings. fopen/fputs/fclose; fail path FUN_007a4480 if open fails.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| joy_custom.ini filename | High | String |
| Drive axes + QuickBar* keys in template | High | Plate/strings |
| fopen fail → FUN_007a4480 return | High | Body |
| Many fputs template lines | High | Body |
| Client input config write only | High | No gameplay |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| fopen → write template lines → fclose; or error | Yes |

---

## 4. Gaps

1. Whether overwrites existing custom binds or only templates missing file.
2. Full key list parity with ActionMap.

**Verdict:** **accept**
