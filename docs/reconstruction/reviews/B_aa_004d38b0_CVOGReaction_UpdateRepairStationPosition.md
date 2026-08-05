# Review B (skeptical / adversarial): `aa_004d38b0` CVOGReaction_UpdateRepairStationPosition

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d38b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d38b0_CVOGReaction_UpdateRepairStationPosition.md` |
| **Verdict** | **accept-with-gaps** on map update CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Updates world object position of station | **Falsified** — updates player→key map, not station XYZ |
| 2 | Name implies geometry write | **Overstated** — “Position” is map entry, not floats |
| 3 | Always returns 1 | **Falsified** — 0 if key unchanged |
| 4 | Character fields written here | **Falsified** — MarkRepairStation writes +0x740/+0x744 |
| 5 | Tree helpers fully sealed | **Falsified** — FUN_* opaque |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert/update/no-op trichotomy | High | Stale station map |
| Geometry interpretation | Low if trusted | Wrong physics/port |
| Helper internals | Tentative | Corrupt map |

---

## 3. Cross-check against raw

```
it = find(map+0xe740, playerTfid)
if end: insert(tfid, key); return 1
if it.key != key: it.key = key; return 1
return 0
```

Clean matches (including awkward decompiler pointer reuse of `param_2`).

---

## 4. Surviving contract for AutoCore

```
UpdateRepairStationPosition(map, playerTfid, stationKey) -> changed:0|1
  upsert player→stationKey in map+0xe740
Does not move entities or write character last-station fields.
```

---

## 5. Open questions

1. Readers of +0xe740 map.
2. Cross-map migration of entries.
3. TFID stability across relog.
4. Live unchanged return (return 0) cases.

**Verdict:** Accept as upsert helper; ignore geometry connotation of name.
