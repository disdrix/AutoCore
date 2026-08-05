# Review B (skeptical / adversarial): `aa_00509010` KillLoot_WalkZoneTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509010` |
| **VA** | `0x00509010` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00509010_KillLoot_WalkZoneTable_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Canonical name is VOG_DEBUG_STOP | String only on lock misuse | **Falsified** |
| 2 | Returns whether an item dropped | Always returns **1** after unlock if walk reached | **Falsified** as drop bool — **walk ok** |
| 3 | Processes all hash entries without filter | Level band + type + chance required | **Falsified** |
| 4 | Chance uses raw percent 0–100 | Multiplies row field by **0.0001** then vs unit random | **Survives** (scaled) |
| 5 | Race filter optional | Keep only if race matches formal or `~RACE_HUMAN` | **Survives** |
| 6 | Same as `FUN_0050aa80` | Different iteration (global hash vs table iterator); sibling loot path | **Falsified** as alias |
| 7 | Zone null always aborts | Null zone skips disable check; may still walk with level 0 midpoint path | **Nuanced** — only `zone!=0 && +0x14c==0` aborts |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hash walk + lock | **High** | Hang / concurrent corrupt |
| Type 0xe/0x12 level path | **High** | Wrong band filter |
| GiveItem + race gate | **High** | Cross-race loot leak |
| Return always 1 after walk | **High** | Misread as drop success |
| VOG name | **Rejected** | Misleading registry |
| Zone flag semantics | **Probable** | Silent no-loot |

---

## 3. Cross-check

Live ≡ raw. Parent calls after `FUN_0050aa80` list materialization; both can produce items.

Constants: `DAT_00aaa664` `17b7d138` ≈ 1e-4; `DAT_00a0f298` = 0.5.

---

## 4. Surviving contract

```
// Post-kill zone table walk — not "did drop"
bool WalkZoneLootTables(Object* victim, RaceId killerRace) {
  // resolve typeKey + level; abort if zone disabled flag
  // locked walk of global loot hash; per-row band/type/chance
  // GiveItemByCbid; keep if race ok else destroy
  return true; // walk finished
}
// Do NOT name from VOG_DEBUG_STOP. Do NOT merge with 0050aa80.
```

---

## 5. What would overturn

1. Additional callers that consume return as drop count.
2. Evidence `~RACE_HUMAN` constant is not race-any/neutral.
3. Disproof of level index mapping for `0x137/0x138/0x139`.

**Verdict:** **accept-with-gaps.**
