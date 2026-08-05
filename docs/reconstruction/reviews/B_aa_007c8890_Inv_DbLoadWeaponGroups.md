# Review B (skeptical): `aa_007c8890` Inv_DbLoadWeaponGroups

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c8890` |
| **VA** | `0x007c8890` |
| **Canonical name** | `Inv_DbLoadWeaponGroups` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Skeptical / adversarial |
| **Counterpart** | `reviews/A_aa_007c8890_Inv_DbLoadWeaponGroups.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. What could be wrong

| Risk | Severity | Assessment |
|---|---|---|
| “Inv_” prefix for combat weapon taxonomy | Low | Weapon groups gate equip legality — inventory domain OK |
| Cross-table `_x` purpose guessed | Med | Name does not invent join semantics beyond load |
| Confuse with runtime equip packet | Low | DbLoad naming prevents that |

---

## 2. Evidence that holds

- Weapon group + CBIDWeapon strings are inventory/equip taxonomy.
- Parallel structure to skill/mission DbLoad units.

---

## 3. Required follow-ups

1. Find runtime consumers of weapon-group map.
2. Document group id vs clonebase type codes (0xc weapons etc.).

**Verdict:** Rename justified. **accept-with-gaps.**
