# Review B (skeptical / adversarial): `aa_00564290` CVOGSpawnPoint_CreateTemplateVehicle

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00564290_CVOGSpawnPoint_CreateTemplateVehicle.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on ctor/helpers |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses CreateCreature path | **Falsified — distinct vehicle alloc 0x800** |
| 2 | Ignores terrain height | **Falsified — CastTerrainHeight** |
| 3 | Always activates | **Falsified — param_4 gate** |
| 4 | Finished exact | **Overstated — many FUN_*** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Terrain Y + scatter fail | High | Underground / no spawn |
| Waypoint path COID | High | Driver return broken |
| Alloc size 0x800 | Tentative | Wrong object class |

---

## 3. Cross-check against raw

```
sample terrain height; optional scatter or fail;
new 0x800 vehicle; init or STOP;
copy pose/orient; waypoint from spawn; hooks;
if param_4: activate.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
CreateTemplateVehicle(spawn, ...):
  height-correct spawn pose; optional scatter
  allocate template vehicle; bind spawn pose/orient
  init waypoint/path for AI return; optional activate
Pair height policy with CreateCreature / NPC_SPAWN_HEIGHT notes.
Do not skip CastTerrainHeight.
```

---

## 5. Open questions

1. Vehicle ctor symbol for FUN_00501970.
2. Path COID 0xffffff01 sentinel meaning.
3. Live DR vehicle spawn.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on ctor/helpers
