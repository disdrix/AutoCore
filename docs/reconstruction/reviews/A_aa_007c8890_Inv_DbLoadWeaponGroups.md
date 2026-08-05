# Review A (reconstruction fidelity): `aa_007c8890` Inv_DbLoadWeaponGroups

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c8890` |
| **VA** | `0x007c8890` |
| **Canonical name** | `Inv_DbLoadWeaponGroups` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007c8890_Inv_DbLoadWeaponGroups.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007c8890_FUN_007c8890.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_DbLoadWeaponGroups.cpp` |
| System | `docs/reconstruction/systems/inventory-transfer.md` |
| Related | `Inv_ValidateEquippedClonebaseSlots` |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loads `//tWeaponGroup/row` | **High** | Literal |
| Cross table `//tWeaponGroup_x/row` | **High** | Literal |
| Fields IDWeaponGroup / CBIDWeapon / strName | **High** | Strings |
| Feeds equip-group lookups | **Medium** | Architectural fit; consumer OPEN |
| ADO pattern matches other DbLoad units | **High** | Shared helpers |

---

## 3. Control flow: clean ≡ raw

Rename + plate; CF preserved.

---

## 4. Gaps

1. Group→slot mapping not sealed.
2. Interaction with Front/Turret/Drop weapon equip validators OPEN.

**Verdict:** Inventory equip-group manager ingest. **accept-with-gaps.**
