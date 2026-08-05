# Review B (skeptical / adversarial): `aa_0050ac80` KillLoot_GenerateDrops_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050ac80` |
| **VA** | `0x0050ac80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0050ac80_KillLoot_GenerateDrops_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function is only XP helper | Large weighted loot pipeline; XP already done in parent | **Falsified** as XP |
| 2 | Level gap **increases** drop rate | Decay `p = p - k*p` each gap step | **Falsified** — **decreases** |
| 3 | Same as `00508e70` credits | Shares profile lookup only; this generates **items** | **Falsified** as alias |
| 4 | Zone always upgrades loot | Requires zone hit, `+0x150`, owner level > 4, second random | **Survives as conditional** |
| 5 | `DAT_00b037f4` is always 1.0 | Static image **0.0**; runtime global | **Open** — must load at runtime |
| 6 | OnDeath is sole caller | Also `FUN_0061cdc0` | **Falsified** sole-caller claim |
| 7 | Full tail dual sealed this pass | 900+ lines; dual seals head structure | **Survives as residual** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gap decay formula | **High** | Loot rate wrong vs level delta |
| Attempt / unit random | **High** | Always/never drop |
| Weight tables layout | **High** | Wrong tier distribution |
| Category type codes | **Probable** | Wrong item class |
| Global rate DAT_00b037f4 | **Open** | Zero → no drops if never set |
| Tail spawn CF | **Probable** | Port incomplete loot |

---

## 3. Cross-check

Parent: `if (-1 < (int)local_74) FUN_0050ac80(pvVar5, param_1, &pos, level, local_74, 0, 0);` then `FUN_004d4440(...)`.

`DAT_009cdae0` bytes `cdcccc3d` = 0.1 confirmed.

---

## 4. Surviving contract

```
// Primary kill loot generate (simplified head)
void GenerateKillLoot(Owner* o, Victim* v, int level, float scale, ...) {
  profile = LookupLootProfile(...);
  if (!profile) return;
  int gap = max(0, OwnerLevel(o) - clamp(level,0,80));
  float p = profile->baseP; // +8
  for (i=0;i<gap;i++) p -= profile->decay * p; // +0xc
  p *= g_lootGlobalScale; // DAT_00b037f4
  if (p > 0) p += o->lootChanceAdd; // +0xc58
  // attempts, weighted quality, weighted category, zone bump, spawn…
}
// Do NOT invert gap effect. Do NOT skip global scale.
```

---

## 5. What would overturn

1. Asm that unrolled loop is not gap iterations.
2. Evidence category codes map differently than weight chain order.
3. Proof OnDeath `local_74` gate is not loot-scale enable.

**Verdict:** **accept-with-gaps** — head High; tail open.
