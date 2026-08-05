# Review A (reconstruction fidelity): `aa_004d37f0` CVOGReaction_TransferMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d37f0` |
| **VA** | `0x004d37f0` |
| **Canonical name** | `CVOGReaction_TransferMap` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d37f0_CVOGReaction_TransferMap.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **map/zone transfer request gate**:

1. Require local flag `param_1+0x7e`.
2. Require non-null `param_2` entity; resolve via vtable `+0x210`(0).
3. Require resolved `+0x4f4 == 0` (not already transferring).
4. `FUN_004d2ac0(resolved, param_2, param_3)` success → set `+0x4f4 = 1`, call `FUN_004025e0` (likely begin transfer / stack cookie path).

Small gate; heavy lifting is in callees.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d37f0_CVOGReaction_TransferMap.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_TransferMap.cpp` |
| System map | `docs/reconstruction/systems/missions-progression.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(ctx, entity*, arg3)` | **High** | Raw |
| Requires +0x7e local flag | **High** | Outer guard |
| Vtable +0x210 resolve | **High** | Raw |
| Busy flag +0x4f4 | **High** | Test then set |
| FUN_004d2ac0 transfer prep | **Probable** | Unnamed |
| FUN_004025e0 role | **Tentative** | May be security cookie / epilogue-ish in decomp |
| param_3 map id / dest | **Tentative** | Unnamed |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| All four AND guards | **Yes** |
| Set busy + follow-up call | **Yes** |
| Silent no-op on fail | **Yes** |

---

## 5. Gaps

1. True identity of FUN_004025e0 (decomp artifact vs real call).
2. param_3 destination encoding.
3. Server transfer packet vs pure client.
4. Runtime map change.

**Verdict:** accept-with-gaps.
