# Review A (reconstruction fidelity): `aa_0050ac80` KillLoot_GenerateDrops_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050ac80` |
| **VA** | `0x0050ac80` |
| **Canonical name** | `KillLoot_GenerateDrops_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_0050ac80`; scaffold Named_CalleeOf_CVOGReaction_Dispatch / OnDeath |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_0050ac80_KillLoot_GenerateDrops_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Primary death loot generator**: given killer/loot owner (`param_1`), victim context (`param_2`), level (`param_4`), loot-scale float (`param_5`), and flags (`param_6`/`param_7`), load the active loot-profile row via `FUN_00508dc0`, apply **level-gap exponential decay** to drop probability, then repeatedly roll:

1. Outer drop chance (unit random vs scaled p)
2. Optional level jitter using profile short `+0x14`
3. Weighted **quality tier** pick (9 weights at profile `+0x44`…)
4. Weighted **item-category / slot class** pick (11 weight shorts + paired float rates)
5. Zone bonus chance (`DAT_009cdae0` = **0.1**) may bump level +2 when zone flag `+0x150` and owner level > 4
6. Materialize / filter / place loot (large tail: GiveItem family, race, `FUN_00521510` scatter, logging buffer)

Callers: `CVOGCombat_OnDeathAwardKillXp` (when `local_74 >= 0`) and `FUN_0061cdc0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0050ac80_FUN_0050ac80.md` (~929 lines) |
| Clean | Named scaffold ~945 lines ≡ raw CF |
| Live decompile | Ghidra `0x0050ac80` (truncated MCP; raw is authoritative twin) |
| Constants | `DAT_00aaa638`=1/65536; `DAT_009cdae0`=**0.1**; `DAT_00b037f4` runtime scale (static 0) |
| Level clamp | `param_4` / computed levels clamped to **0x50 (80)** |

---

## 3. Control flow (sealed head)

```
FUN_0050ac80(owner, victim, ?, level, scaleFloat, flag, file?):
  profile = FUN_00508dc0()   // same credit/loot profile family as 00508e70
  if profile == 0: fall through → fail/0 paths

  ownerLevel = (*owner vtbl+0x27c path)()
  gap = max(0, ownerLevel - level)
  if level > 0x50: level = 0x50

  // p = profile+0x8 float; for i in 0..gap-1: p = p - (profile+0xc)*p
  // unrolled ×4 then remainder — geometric decay
  p *= DAT_00b037f4            // global loot rate scalar
  if p > 0: p += *(owner + 0xc58)  // owner loot-chance add

  if profile->attemptCount (+0x4 short) > 0:
    loop attempts:
      if UnitRandom() <= p:
        // level' = level - rng%(profile+0x14) if short>0; clamp >=0
        // qualityTier = weighted pick from 9 shorts @+0x44..+0x54
        // category = weighted pick from 11 weight shorts @+0x20..+0x34
        //   maps to (rateFloat, typeCode) pairs e.g. 0x34,0x1c,8,6,10,0x32,0xc,0x10,0xe,0x46,0x44
        // zone: lookup victim+0xfc in type hash; if +0x150 and ownerLvl>4:
        //   rate += 0.1; maybe level'+2 / level+2 (cap 80)
        // … large generate/filter/spawn tail …
  multiple early return 0 on empty weight sums / failed gates
```

Full tail (item spawn, inventory vs world, FILE log) remains **Probable** product semantics; raw preserves call order.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Profile via `FUN_00508dc0`; null aborts productive path | **High** | |
| Level gap decay: `p -= decay*p` repeated `gap` times | **High** | unrolled ×4 |
| Clamp level ≤ 80 | **High** | |
| Owner add `+0xc58` when p>0 | **High** | sibling of credit `+0xc60` |
| Attempt loop gated by profile short `+0x4` | **High** | |
| Unit random vs p for attempt | **High** | |
| 9-tier quality weights @ `+0x44` | **High** structure |
| 11-category weighted map → type codes | **High** structure; codes **Probable** inventory slots |
| Zone +0x150 bonus uses **0.1** | **High** constant |
| Death caller when scale `local_74 >= 0` | **High** | parent CF |
| Every spawn/filter edge in 900-line tail | **Probable** | needs row-level dual for ports |
| `param_6`/`param_7` FILE logging role | **Tentative** | rarely non-null from OnDeath (0,0) |

---

## 5. Control flow: clean ≡ raw

Scaffold Named body tracks raw. Live decompile matches head; tail truncated in MCP but raw file complete.

---

## 6. Gaps / open

1. Full category→item table resolution beyond type codes.
2. Runtime `DAT_00b037f4` source/writer.
3. Dual of spawn helpers in tail (`GiveItem`, equip filters, scatter).
4. `FUN_0061cdc0` alternate call contract.

**Verdict:** Head math + structure **High**. Tail product detail **accept-with-gaps**.
