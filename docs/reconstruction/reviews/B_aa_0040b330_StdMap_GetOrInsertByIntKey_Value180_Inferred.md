# Review B (skeptical / adversarial): `aa_0040b330` StdMap_GetOrInsertByIntKey_Value180_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b330` |
| **VA** | `0x0040b330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040b330_StdMap_GetOrInsertByIntKey_Value180_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure lower_bound / find-only | Miss path **inserts** zeroed value | **Falsified find-only** |
| 2 | Returns the node header | Returns **`node+0x10`** value | **Falsified node*** |
| 3 | Map is `this` of the game object | Wrapper forces **`ECX = DAT_00b047a0`** | **Falsified object-this** |
| 4 | Same nil flag family as `+0x29` / `+0x1d` maps | This family uses **`+0x191`** | **Falsified family mix** |
| 5 | Value size is 0xC / small POD | Zero-fill **0x60 dwords = 0x180** | **Falsified small** |
| 6 | OnDeath XP formula lives here | Body is map glue only | **Falsified XP** |
| 7 | `FUN_005001f0` decomp voids return | Callers use **EAX** value* | **Survives as decomp hazard** |
| 8 | Early condition is only `key <` without equality | Under correct LB, `key_node <= k` ⇒ equal | **Survives as intentional** |
| 9 | Product name string-sealed | No string | **Not sealed** — `_Inferred` |
| 10 | Pair-key map like `005a3b00` | Single **int** key | **Falsified pair** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Get-or-insert polarity | **Confirmed** | missing def rows / dup inserts |
| Return value @ +0x10 | **Confirmed** | bad HP/loot scalar loads |
| Global map `00b047a0` | **Confirmed** | per-object map bug |
| Large-node nil `+0x191` | **Confirmed** | walk corruption |
| 0x180 zero on insert | **Confirmed** | uninitialized def fields |
| Field atlas beyond samples | **Low–Med** | wrong offset docs |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
// Global map at DAT_00b047a0 (not the object):
value* = Map_GetOrInsert_IntKey_Value180(map, &key):
  it = lower_bound(map, key)   // nil @ node+0x191, key @ +0xC
  if it != end && it.key == key: return it+0x10
  insert zeroed 0x180-byte value; return new+0x10

// Common wrapper:
key = object[+0x14c]
return Map_GetOrInsert(DAT_00b047a0, &key)
```

Port rule: **never** use object ECX as map; **never** treat return as node base (value is +0x10). Do not mix with pair-key ghost map (`005a3b00`) or small XP maps (`+0x1d` / `+0x15` nil families).

---

## 4. Open questions

1. Complete value blob field list.
2. Key domain name for `+0x14c`.
3. Whether any caller depends on insert side-effects beyond zero init.

**Verdict:** **accept-with-gaps** — adversarial pass keeps global get-or-insert + 0x180 value; schema residual only.
