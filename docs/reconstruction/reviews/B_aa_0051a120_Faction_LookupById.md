# Review B (adversarial): `aa_0051a120` Faction_LookupById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a120` |
| **VA** | `0x0051a120` |
| **Canonical name** | `Faction_LookupById` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial / gap hunter (OWN-ONLY WQ9R-G) |
| **Counterpart** | `reviews/A_aa_0051a120_Faction_LookupById.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| # | Attack | Outcome |
|---|---|---|
| 1 | Skill-bank / skill-id lookup (WQ-009 residual label) | **Rejected as body role.** No skill bank vector; callers print **FACTION** / use for vehicle/infantry/creature objective labels. |
| 2 | Same as `FUN_00519d20` (nearby) | **Rejected.** Different globals (`00b043*` vs `00b042b*`); this returns **value ptr**, sibling returns **`*value`**. |
| 3 | Thin `CNDHash_LookupByKey` thunk | **Rejected.** Inline bucket walk; sibling `0051a0e0` is the CNDHash wrapper. |
| 4 | thiscall / ECX id | **Rejected.** `mov esi,[esp+8]` after push; bare `C3`. |
| 5 | Returns node not value | **Rejected.** Hit path `mov eax,[eax+8]` then ret — value slot. |
| 6 | Drive_Vehicles-only helper (scaffold alias) | **Rejected as plate.** Two mission/UI formatters; not exclusive to vehicles (also Infantry/Creatures/Characters suffixes). |
| 7 | Init always required | **Nuanced.** Only when `DAT_00b04320==0`; ready tables skip `005197b0`. |
| 8 | Negative check is unsigned mistake | **Rejected.** Intentional signed gate: high-bit ids never hit table. |
| 9 | Runtime Confirmed | **Rejected claim.** BSS zeros offline; live table only after init. |

---

## Residual gaps

1. Product name / RTTI for faction record (0x64 alloc in loader).
2. Full field map beyond id@0, name@+4, secondary string@+0x24 (from `005197b0` — not owned).
3. Whether mask is always `count-1` power-of-two (standard) — not re-proven here.
4. Runtime / bit-exact / differential.

---

## Agreement with A

| Topic | A | B |
|---|---|---|
| Name `Faction_LookupById` | accept | accept (string-sealed) |
| cdecl leaf hash | accept | accept |
| Not skill-bank | accept | accept |
| Reject Drive_Vehicles plate | accept | accept |
| Verdict | accept-with-gaps | **accept-with-gaps** |

---

## Verdict

**accept-with-gaps** — no adversarial unseat of CF/ABI/faction role; record product English open.
