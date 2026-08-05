# Review B (skeptical / adversarial): `aa_00521e00` CVOGReaction_MarkRepairStation

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00521e00_CVOGReaction_MarkRepairStation.md` |
| **Verdict** | **accept-with-gaps**; watch Update `this` recovery |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | stationKey is world object COID | **Falsified by plate** — GenericVar1 small key |
| 2 | Always updates map table | **Falsified** — missing related → no Update call |
| 3 | +0x634 bit0 is “failed mission” | **Falsified** — FailMission uses `\|0x10`; this uses `\|1` |
| 4 | Clean nullptr map this is bit-exact | **Attacked** — decompiler likely had map in ECX from caller |
| 5 | Server authority is this client unit | **Falsified** — client apply; server has own handler |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character field writes | High | Wrong respawn station |
| Key vs COID | High | Broken station map |
| Update this-ptr | Tentative | Map insert on wrong object |
| Flag bit taxonomy | Probable | Flag confusion |

---

## 3. Cross-check against raw / clean

Success path spine shared:

```
flag |= 1; lastMap = related.mapId; lastKey = stationKey
UpdateRepairStationPosition(playerTfid, stationKey)
```

Fail: flag |= 1; lastKey = -1; false.

---

## 4. Surviving contract for AutoCore

```
MarkRepairStation(character, stationKey):
  if relatedMap:
    char.flags |= 1
    char.lastStationMap = mapId
    char.lastStationId = stationKey
    UpdateRepairStationPosition(playerTfid, stationKey)
  else:
    char.flags |= 1; char.lastStationId = -1; return false
```

---

## 5. Open questions

1. Respawn reader of +0x740/+0x744.
2. How stationKey maps to world object.
3. ECX map object for Update at call sites.
4. Live type-29 reaction capture.

**Verdict:** Accept mark semantics; seal Update call context with sibling review.
