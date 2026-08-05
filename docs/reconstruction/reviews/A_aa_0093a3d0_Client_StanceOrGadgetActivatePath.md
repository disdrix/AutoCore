# Review A (reconstruction fidelity): `aa_0093a3d0` Client_StanceOrGadgetActivatePath

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a3d0` |
| **VA** | `0x0093a3d0` |
| **Canonical name** | `Client_StanceOrGadgetActivatePath` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093a3d0_Client_StanceOrGadgetActivatePath.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_StanceOrGadgetActivatePath.cpp` |
| Raw | `docs/reconstruction/raw/aa_0093a3d0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** INFERRED stance/gadget slot activate path related to cast-again (opcode 0x20bb nearby). Resolves skill from char+0xd58[slot] (slot 0..2 else -1), vtbl+0x234 lookup, requires skill+0x5f6!=0. Uses Skill_LookupActiveCastBinding / ClearActiveCastCounterAndQueueId / FormatFailureMessage / StartCastAgainHeartbeat when world+0x7e==0. Not fully walked.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Slot index EBX 0..2 → char+0xd58 | High | Body |
| Skill resolve vtbl+0x234 | High | Body |
| Requires trained rank skill+0x5f6!=0 | High | Body |
| Active cast binding helpers | High | Callees |
| 0x20bb cast-again family nearby | Probable | Plate |
| INFERRED / not fully walked | Tentative | Plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if local char and valid slot: resolve skill → cast-again/stance path or fail message | Yes |

---

## 4. Gaps

1. Exact distinction stance vs gadget vs normal cast.
2. Full CF after skill resolve.
3. world+0x7e gate semantics.

**Verdict:** **accept-with-gaps**
