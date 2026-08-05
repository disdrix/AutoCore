# Review B (skeptical / adversarial): `CVOGSectorMap_LoadMapFile` @ `0x004dc510`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dc510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004dc510_CVOGSectorMap_LoadMapFile.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only loads terrain height TGA | Falsified — sector map + triggers |
| 2 | Player trigger at +0xE7E8 | Falsified — player +0xE7E0; creator +0xE7E8 |
| 3 | OnKill at +0xE7E0 | Falsified — OnKill +0xE7D8 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trigger COID offsets E7D8/E0/E8/F0 | High | Wrong on-load reactions |
| Named property load path | High | Map init fail |
| Object body format | Tentative | Missing entities |

---

## 3. Cross-check against raw

```
Load fam/fat; FUN_00514320 writes trigger COIDs at documented offsets;
then objects. Matches DoPlayer/DoCreator consumers.
```

---

## 4. Surviving contract for AutoCore

```
LoadMapFile(sector, path, flags...):
  stream header
  sector+0xE7D8 OnKill, +0xE7E0 PerPlayerLoad, +0xE7E8 CreatorLoad, +0xE7F0 LastTeam
  load objects
  pairs AddCharacter on-load trigger fire
```

---

## 5. Open questions

1. Seal object record layout.
2. Version/magic for .fam vs .fat.

**Verdict:** **accept-with-gaps**
