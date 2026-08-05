# Review A (reconstruction fidelity): `aa_005afbc0` CVOGMap_SetVariable

| Field | Value |
|---|---|
| **Stable ID** | `aa_005afbc0` |
| **VA** | `0x005afbc0` |
| **Canonical name** | `CVOGMap_SetVariable` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005afbc0_CVOGMap_SetVariable.md` |
| **System** | `map-variables` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set map variable **id** to float **value**: same hash/chain as Lookup; on hit write **`node+0x48=value`**; optional debug `SV(%d: %f)` when `map+0x3c`; notify `FUN_004cd3b0(id,value)`; iterate listener TFID range **`[node+0x58, node+0x5c)`** resolving each via `CVOGReaction_ResolveObjectTarget` and virtual call **vtbl+0x13c(param_4)**. Miss → no-op (no create).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005afbc0_CVOGMap_SetVariable.md` |
| Annotated | `docs/reconstruction/raw/aa_005afbc0_CVOGMap_SetVariable.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMap_SetVariable.cpp` |
| Function record | `docs/reconstruction/functions/aa_005afbc0_CVOGMap_SetVariable.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Same hash/chain as Lookup` | **High** | Body |
| `Write node+0x48 = param_3 float` | **High** | Store |
| `Debug log if map+0x3c` | **High** | SV format |
| `FUN_004cd3b0 notify` | **High** | Call |
| `Listener vector +0x58..+0x5c TFID pairs` | **High** | Loop step 8 |
| `ResolveObjectTarget + vtbl+0x13c(param_4)` | **High** | Per listener |
| `Miss is silent no-op` | **High** | No insert |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Lookup + write + notify + listeners | **Yes** |
| No invented insert | **Yes** |

---

## 5. Gaps / open

1. FUN_004cd3b0 identity (global var bus?).
2. What vtbl+0x13c is (variable-changed handler).
3. param_4 semantic (source reaction context).

**Verdict:** **accept-with-gaps**
