# Review A (reconstruction fidelity): `aa_00509010` KillLoot_WalkZoneTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509010` |
| **VA** | `0x00509010` |
| **Canonical name** | `KillLoot_WalkZoneTable_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00509010`; false string alias `Named_VOG_DEBUG_STOP_00509010` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00509010_KillLoot_WalkZoneTable_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Zone / global loot-table walk** after kill: for a **victim object** (`param_1`) and **killer race id** (`param_2`), resolve victim level band and type, then traverse the global hash at `*(DAT_00b041d4 + 0xf14)` under traversal lock `hash+0x1d`. For each table entry whose level band and type match, roll drop chance and optionally `CVOGReaction_GiveItemByCbid` + race-gate the spawned object.

Called from `CVOGCombat_OnDeathAwardKillXp` after the `FUN_0050aa80` list path when loot manager singleton is live.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00509010_*` |
| Live decompile | Ghidra `0x00509010` (2026-07-29) |
| Constants | `DAT_00aaa638`=1/65536; `DAT_00aaa664`≈**0.0001**; `DAT_00a0f298`=**0.5** |
| Strings | HashError/VOG_DEBUG_STOP assert only — **not** function identity |
| Caller | OnDeathAwardKillXp only (static) |

---

## 3. Control flow (authoritative)

```
FUN_00509010(victimObj, raceId):
  def = victimObj[0x2a]            // type-def / clone-def pointer index
  if def == 0: return 0
  sub = *(def + 0x3c)
  if sub == 0: FUN_004f1e20(0,1); re-read; if still 0: return 0
  typeKey = (*sub->vtbl+0xc)()     // type discriminator

  // zone/type-def lookup by victim owner key
  key = *(victimObj[0x29] + 0xfc)
  zone = CNDHash_LookupByKey(FUN_00541a80(), key)
  if zone != 0 && *(zone + 0x14c) == 0: return 0   // zone disabled / no loot flag

  // level sample for band filter
  if *(def + 0x38) == 0xe:         // character-like
    node = (*victimObj->vtbl+0x1d4)()
    level = (*(...node...vtbl+0x27c))()
  else if *(def + 0x38) == 0x12:   // creature-like
    node = (*victimObj->vtbl+0x1d8)()
    level = (*(...node...vtbl+0x27c))()
  else:
    // non 0xe/0x12: midpoint of zone level band * 0.5, ROUND
    if zone: level = ROUND((*(zone+0x13c)+*(zone+0x138)) * 0.5)
    else: level = 0

  hash = *(DAT_00b041d4 + 0xf14)
  lock hash+0x1d = 1  (assert if already locked)
  for each node in hash chain (first +0x14, next node+0x14, payload node+8):
    entryDef = payload; ensure +0x3c via FUN_004f1e20 if null
    row = *(entryDef + 0x3c)
    if row && row[0x137] <= level <= row[0x138]:
      if (*row->vtbl+0xc)() == typeKey && != -1:
        // chance: UnitRandom() <= (float)row[0x139] * 0.0001
        if pass:
          item = GiveItemByCbid(row[1])  // cbid at +4
          if item:
            (*item->vtbl+8)(cbid, victimObj[0x29], 0)
            race = Object_GetRootRaceId(item)
            if race == raceId || race == ~RACE_HUMAN:
              FUN_00402d10(&itemRef)     // keep / stash
            else:
              (*item->vtbl+0)(1)         // destroy
  unlock hash+0x1d
  return 1
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Not named by VOG_DEBUG_STOP | **High** | Assert-only strings |
| Returns 0 on missing def/sub/zone-flag; 1 after walk | **High** | |
| Global hash `DAT_00b041d4+0xf14` + lock `+0x1d` | **High** | Shared CNDHash pattern |
| Type codes `0xe` / `0x12` branch level sources | **High** | Parallel OnDeath paths |
| Level band `row[0x137..0x138]` (dword indices → +0x4dc/+0x4e0 if int*) | **High** | decomp index |
| Drop chance `row[0x139] * 1e-4` vs unit random | **High** | constants sealed |
| GiveItem + race keep/destroy | **High** | |
| Race id formal | **High** | caller passes race byte from owner def `+0x532` |
| Zone flag `+0x14c == 0` means “no loot walk” | **Probable** | binary gate only |
| Full product table schema | **Open** | |

---

## 5. Control flow: clean ≡ raw

Clean Named_VOG_DEBUG_STOP body ≡ raw/live. **Name is wrong** (assert alias); CF is faithful.

---

## 6. Gaps / open

1. Exact meaning of zone `+0x14c`.
2. What `FUN_00402d10` does with kept item ref (inventory vs world).
3. Whether return **1** means “walk completed” only (not “item dropped”).

**Verdict:** Walk CF **High**. Scaffold VOG name **rejected**. **accept-with-gaps.**
