# Review B (skeptical / adversarial): `aa_007d8fe0` Drive_LoadOneVehicleTemplate_dcFetch_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007d8fe0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007d8fe0_Drive_LoadOneVehicleTemplate_dcFetch_Open.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Live NPC MoveTo axes | Falsified — template load |
| 2 | Single field only | Falsified — multi fetch |
| 3 | Finished schema | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Template open path exists | High | Missing vehicle defs |
| Not drive tick | High | Wrong subsystem port |
| Column schema | Tentative | Wrong stats |

---

## 3. Cross-check against raw

```
dcFetch Open; read columns; fill vehicle template; log DBReader mismatches.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
LoadOneVehicleTemplate_dcFetch_Open(reader…):
  data load for vehicle templates; pair clonebase/vehicle DB
  AutoCore: catalog load, not movement
```

---

## 5. Open questions

1. Document column→field map.
2. Link Inv_DbLoadWeaponGroups relation.

**Verdict:** **accept-with-gaps**
