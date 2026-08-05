# Review B (skeptical / adversarial): `aa_004d4440` CVOGSectorMap_GenerateLevelGatedLoot

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d4440_CVOGSectorMap_GenerateLevelGatedLoot.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always spawns ≥1 item | Chance miss returns 1 with empty list path | **Falsified** as always-spawn |
| 2 | No level gate | `level - param_2 < 11` hard gate | **Falsified** no-gate |
| 3 | Places into inventory bag | Live path uses `PlaceWorldObject` r=5 | **Falsified** as bag |
| 4 | Dump mode is dead code | `param_6` + `fwrite` + destroy | **Falsified** dead |
| 5 | Radius is 1.0 like assist drop | Imm **0x40a00000 = 5.0f** | **Survives** as 5.0 |
| 6 | Secondary roll threshold 0.5 | `DAT_00aaa8ec = 0.08f` | **Falsified** as 0.5 |

---

## 2. Live ≡ raw

Phases match decompile:

```
if levelDelta >= 11: fail-ish return
touch context; load chance; if chance <= rand: return 1
build cbid vector
for each: factory; init; optional affix; pose; optional 8% bonus;
         place r=5 OR dump name to FILE
```

Clean scaffold is large but control-equivalent.

---

## 3. Surviving contract

```
// kill/dispatch loot: level-gated, chance-gated, multi-CBID world drops
GenerateLevelGatedLoot(map, lvlRef, victim, pos, lootKey, dumpMode, file)
  → low-byte 1 on soft success (incl. chance miss), 0 on hard fail
```

**Not** credits amount path (`004d2750`); **not** single assist object (`004d31a0`).

**Verdict:** **accept-with-gaps**.
