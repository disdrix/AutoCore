# Review A (reconstruction fidelity): `aa_0050aa80` KillLoot_RollTableItems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050aa80` |
| **VA** | `0x0050aa80` |
| **Canonical name** | `KillLoot_RollTableItems_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_0050aa80`; scaffold Named_CalleeOf_OnDeath… |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_0050aa80_KillLoot_RollTableItems_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Iterate a loot-table handle** and, for each row that passes a **1/10000 random chance** and **race + quality/level band** filters, **materialize items** (`CVOGReaction_GiveItemByCbid`) into an **output list** (`param_4`). Used by `CVOGCombat_OnDeathAwardKillXp` when global loot manager `DAT_00b037e8` is non-null — produces the item list later scatter-spawned via `FUN_004d2820` / `FUN_00521510`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_0050aa80_*` |
| Live decompile | Ghidra `0x0050aa80` (2026-07-29) |
| Helpers | `FUN_0050eec0` (table lock wrapper), `FUN_004e1830` (iterator), `FUN_00541a80`+`CNDHash_LookupByKey`, `FUN_00509c70` |
| Caller | OnDeathAwardKillXp only (static) |

---

## 3. Control flow (authoritative)

```
FUN_0050aa80(tableKeyOrId, ownerObjish, raceId, outList):
  // defaults for level window [0, 0x50]
  lo = 0; hi = 0x50
  wrap = FUN_0050eec0(tableKeyOrId)
  if wrap[9] == 0:
    (*wrap->dtor)(1); return 0

  key = ownerObjish[0x3f]          // hash key
  zone = CNDHash_LookupByKey(FUN_00541a80(), key)
  if zone:
    lo = *(zone + 0x138)
    hi = *(zone + 0x13c)

  FUN_00508770()                  // prep
  done = FUN_004e1830(iter, &tableKeyOrId)  // first / end?

  do:
    if done != 0:
      // unlock CS if held; destroy wrap; return 1
      ...
      return 1

    // Unit random: (u16 % 10000) <= *(short*)(row+8)
    if pass:
      item = GiveItemByCbid(*(int*)(row+4))
      (*item->vtbl+8)(cbid, 0, 0)
      if item's def+0x3c:
        FUN_00509c70(item, *(short*)(def+0x3f0), 0x80000000, 1, 0)  // quality roll?
      race = Object_GetRootRaceId(item)
      if race == raceId || race == ~RACE_HUMAN:
        q = *(short*)(item+0xea) + (short)item[0x3a]
        // quality/level gate vs [lo,hi], clamp display 0..0x50
        if q in band (with 0/0x50 edge cases):
          // insert item* into outList (STL-like FUN_00418700 + link)
        else:
          (*item->dtor)(1)
      else:
        (*item->dtor)(1)

    done = FUN_004e1830(iter, &tableKeyOrId)
  while true
```

Signature live: `(int param_1, int *param_2, RACE_ID param_3, int param_4)` — parent passes `(typeId, param_3[0x29], raceByte, list)`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Iterator over loot rows until end → return 1 | **High** | |
| Empty wrap → return 0 | **High** | |
| Chance: `u16 % 10000 <= *(short*)(row+8)` | **High** | Not float unit scale |
| CBID at `row+4`; GiveItem + optional `00509c70` | **High** | |
| Race keep/destroy gate | **High** | Same family as 00509010 |
| Zone band defaults 0..80 (0x50); override from zone +0x138/+0x13c | **High** | |
| Output list insert on pass | **High** | FUN_00418700 link |
| Quality sum `item+0xea` + `item[0x3a]` | **High** offsets; **Probable** meaning |
| `FUN_00509c70` role (affix/quality) | **Tentative** | args sealed; product open |
| Table formal identity | **Probable** | parent type id / table key |

---

## 5. Control flow: clean ≡ raw

**Yes** — Named scaffold matches live CF including critical-section leave on success path.

---

## 6. Gaps / open

1. Exact type of `param_1` (table id vs pointer) through `FUN_0050eec0` / `FUN_004e1830`.
2. Semantics of quality fields vs zone min/max.
3. Interaction with subsequent `FUN_00509010` (additive loot sources).

**Verdict:** Iterator CF **High**. Product labels **Probable**. **accept-with-gaps.**
