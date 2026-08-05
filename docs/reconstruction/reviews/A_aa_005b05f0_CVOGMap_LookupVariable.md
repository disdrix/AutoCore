# Review A (reconstruction fidelity): `aa_005b05f0` CVOGMap_LookupVariable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b05f0` |
| **VA** | `0x005b05f0` |
| **Canonical name** | `CVOGMap_LookupVariable` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b05f0_CVOGMap_LookupVariable.md` |
| **System** | `map-variables` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Hash-bucket lookup of map variable by **id** (`param_2`). Walk chain from `map+0x10` buckets masked by `map+0x8`; match node key `+0x10`; payload at node `+0x8`. If found and flag `node+0x40==0`, write float/value at **`node+0x48`** to `*out` and return success **1**; if computed flag set, `CVOGVariable_EvaluateComputed()`. Miss → **0**. Used by reactions (ShowDialog, faction, etc.).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b05f0_CVOGMap_LookupVariable.md` |
| Annotated | `docs/reconstruction/raw/aa_005b05f0_CVOGMap_LookupVariable.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMap_LookupVariable.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b05f0_CVOGMap_LookupVariable.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Bucket = map+0x10[(map+8)&id]` | **High** | Hash |
| `Chain walk node+0xc; key at +0x10` | **High** | Loop |
| `Payload node via +0x8 after key match` | **High** | Body |
| `Static: *out = node+0x48; return 1` | **High** | flag+0x40==0 |
| `Computed: CVOGVariable_EvaluateComputed` | **High** | flag nonzero |
| `Miss returns 0` | **High** | Both miss paths |
| `No create-on-miss` | **High** | Lookup only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Hash + chain + static/computed + miss | **Yes** |
| No invented write | **Yes** |

---

## 5. Gaps / open

1. Full variable node layout (+0x40/+0x48/+0x58).
2. EvaluateComputed ABI and return packing.
3. Whether map+0x3c debug is only on Set.

**Verdict:** **accept-with-gaps**
