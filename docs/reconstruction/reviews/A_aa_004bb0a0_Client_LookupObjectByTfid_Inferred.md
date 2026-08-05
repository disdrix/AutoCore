# Review A (reconstruction fidelity): `aa_004bb0a0` Client_LookupObjectByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0a0` |
| **VA** | `0x004bb0a0` |
| **Canonical name** | `Client_LookupObjectByTfid_Inferred` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004bb0a0_Client_LookupObjectByTfid_Inferred.md` |
| **System tag** | `client-net` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_LookupObjectByTfid_Inferred.cpp` |
| Raw | `docs/reconstruction/raw/aa_004bb0a0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Resolve world object by TFID: CVOGReaction_ResolveObjectTarget(globalFlag, coidLo, coidHi) then vtbl+0x1dc on result. Returns object* or null. Called from Client_RecvCharacterLevel before ApplyCharacterLevelPacket. Name INFERRED.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Args: globalFlag, coidLo, coidHi | High | Plate + signature |
| CVOGReaction_ResolveObjectTarget first | High | Body |
| Then vtbl +0x1dc on resolved* | High | Body |
| Null if resolve fails | High | Body |
| Used by RecvCharacterLevel | High | Plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| resolve target → if non-null vcall +0x1dc else null | Yes |

---

## 4. Gaps

1. Exact meaning of vtbl+0x1dc (object unwrap?).
2. globalFlag semantics.

**Verdict:** **accept-with-gaps**
