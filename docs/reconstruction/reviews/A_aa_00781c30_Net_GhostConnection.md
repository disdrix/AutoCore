# Review A (reconstruction fidelity): `aa_00781c30` Net_GhostConnection

| Field | Value |
|---|---|
| **Stable ID** | `aa_00781c30` |
| **VA** | `0x00781c30` |
| **Canonical name** | `Net_GhostConnection` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00781c30_Net_GhostConnection.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ghost **connection / scope management** unit (plate `Net_GhostConnection`). `__thiscall(this, param_2, param_3)` orchestrates connection-side ghost lifecycle with `BitStream_writeBits`/`writeFlag`, plus callees `FUN_00780b70`, `FUN_00783aa0`, `FUN_00783b60`, `FUN_00975870`, `FUN_00429c30`, `FUN_00431c00`. Large (~355-line) connection hub — not a single object unpack.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00781c30_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00781c30_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_GhostConnection.cpp` |
| Function record | `docs/reconstruction/functions/aa_00781c30_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Connection-level ghost orchestration | High | Name + size + callees |
| Uses BitStream write helpers | High | Body |
| Not per-object UnpackGhostUpdate | High | Distinct role |
| Full state machine sealed | Medium | FUN_* residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| connection setup/write branches → helper callees | Yes |

---

## 5. Gaps / open

1. Name FUN_00783* connection subroutines.
2. Relate to TNL GhostConnection port in AutoCore.

**Verdict:** **accept-with-gaps**
