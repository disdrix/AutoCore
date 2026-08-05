# Review A (reconstruction fidelity): `aa_0094caa0` Client_ShowInventoryFullAcceptMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094caa0` |
| **VA** | `0x0094caa0` |
| **Canonical name** | `Client_ShowInventoryFullAcceptMessage` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0094caa0_Client_ShowInventoryFullAcceptMessage.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ShowInventoryFullAcceptMessage.cpp` |
| Raw | `docs/reconstruction/raw/aa_0094caa0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** When inventory cannot accept offered/loot item: if gate fails show toast 'Your inventory is too full to accept.'; else may send sector packet opcode **0x208f** size 0x18 with TFID fields from char dual-base. Gates: local char, UI@game+0x1050 visible, vehicle@char+0x250, optional unaff_BL + FUN_00521e90 fit check.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Toast inventory too full to accept | High | String |
| Else path C2S 0x208f size 0x18 | High | Body auStack_18[0]=0x208f |
| Requires char + visible UI + vehicle | High | Body gates |
| Fit check FUN_00521e90 when unaff_BL | High | Body |
| TFID from char dual-base +0x164/+0x168 | High | Body |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| gates → if unfit toast else send 0x208f | Yes |

---

## 4. Gaps

1. True meaning of 0x208f (accept offer vs other).
2. UI object at game+0x1050 identity.

**Verdict:** **accept-with-gaps**
