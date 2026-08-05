# Review A (reconstruction fidelity): `aa_00509c70` Item_RollQualityAndAffixes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509c70` |
| **VA** | `0x00509c70` |
| **Canonical name** | `Item_RollQualityAndAffixes_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00509c70`; scaffold Named_CalleeOf…; prior dual notes “affix/quality” |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00509c70_Item_RollQualityAndAffixes_Inferred.md` |
| **System** | inventory-transfer / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Post-spawn item quality + type-specific affix roller.** Given a non-null item, draws a unit random `U16/65536`, optionally selects a **quality scale / tier direction** (−1 / 0 / +1) when item “level sum” is outside a low band, then **switches on def type** (`item[0x2a]+0x38`) to write rolled stats into type-specific subobjects (vtbl getters `+0x1f4/+0x1e0/+0x1d4/+0x1f0/+0x1f8`). If `param_4 != 0`, runs the **optional finish block**: durability/broken chance, quality vtbl `+0x90`, up to three skill-tint slots from def `+0x3bc/+0x3c0/+0x3c4`, finalizer `+0x22c`, and a **~11% broken roll** gated by `FUN_00513cf0` + zone/hash check → `FUN_00513de0(1)` (`Item_SetBroken`).

Callers: loot materialize paths `FUN_004cf120`, `FUN_004d4440`, `FUN_0050aa80`, `FUN_0050ac80`, `FUN_0050b6c0` — typically after `GiveItemByCbid` with args like `(item, qualityHint, 0x80000000, doFinish, seed)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00509c70_*` |
| Live decompile | Ghidra `0x00509c70` (2026-07-29) — large body **≡ raw** |
| Constants (`read_memory`) | see §4 |
| Helpers | `FUN_00508a00` (scaled random float), `FUN_00509b10` (mod pack), `FUN_00513cf0`, `Item_SetBroken` `0x00513de0` |
| Callers | five loot generators (static) |

---

## 3. Control flow (compressed)

```
FUN_00509c70(item*, param_2, param_3, param_4_finish, param_5):
  if item == null: return

  // unit random roll
  u = UnitRandomU16() * DAT_00aaa638           // 1/65536
  levelSum = (short)item[+0xea] + (short)item[0x3a]
  qualityScale = 1.0
  tierDir = 0
  if levelSum > 0x50 || (short)levelSum > 2:
    if u < float(_DAT_009cdce0):               // low band (~0.0035 float / 0.333 double residual)
      qualityScale = broken? 0.94 : 0.80       // DAT_009cdcd8 / DAT_00a0f698
      tierDir = -1
    if u > DAT_009cdcd4 (~0.666):
      qualityScale = broken? 1.34 : 1.20       // DAT_009cdcd0 / DAT_00aaab3c
      tierDir = +1
    if broken && double(_DAT_009cdce0) < u < float(_DAT_009cdcc8):
      qualityScale = DAT_009cdcc4 (~1.11)      // mid band override

  switch defType at item[0x2a]+0x38:
    case 6:   // weapon-like subtype 8 → random paint/skin id @ item[0x32]
    case 10:  // armor-ish: scale floats @ sub+0xbc..+0xc8 via FUN_00508a00
    case 0xc: // another gear: floats @ +0xfc..+0x108 + short @ +0x10c
    case 0xe: // wide float block +0x21c..+0x240 (+ flag +0x2ac); optional FUN_004faaf0/40
    case 0x10:// 6-iter blend via FUN_005a6f20 / FUN_005a6e90
    case 0x1c:// floats +0xc4/+0xc8 + short +0xcc
    default:  // no type-specific body

  if param_4 != 0:   // finish / post-roll
    if def[+0x409] == 0:
      item->vtbl[+0x154]()
    else:
      // chance gate using param_2; fail → vtbl+0x154; else FUN_00509b10 + vtbl+0x64
    // roll quality index from def[+0x4b4]; item->vtbl[+0x90](q)
    // up to 3 skill CBID slots → ResolveSkillTargets → vtbl +0x270/+0x274/+0x278
    item->vtbl[+0x22c]()
    // zone hash gate + (rand%100 < 11) && FUN_00513cf0() → SetBroken(1)
```

Broken flag test uses `item[0x5f]` dword `+0x17c` bit 19 (`>> 0x13 & 1`) — same **ItemFlag_Broken** mask as `Item_SetBroken`.

---

## 4. Constants (`read_memory`)

| Symbol | Bytes | Float / notes |
|---|---|---|
| `DAT_00aaa638` | `80 00 80 37` | **1/65536** (~1.5259e-5) |
| `DAT_009cdcd0` | `1f 85 ab 3f` | **1.34** (broken high scale) |
| `DAT_009cdcd4` | `fa 7e 2a 3f` | **0.666** high-roll threshold |
| `DAT_009cdcd8` | `d7 a3 70 3f` | **0.94** (broken low scale) |
| `DAT_00a0f698` | `cd cc 4c 3f` | **0.80** (non-broken low scale) |
| `DAT_00aaab3c` | `9a 99 99 3f` | **1.20** (non-broken high scale) |
| `DAT_009cdcc4` | `7b 14 8e 3f` | **1.11** mid override |
| `_DAT_009cdce0` | `1d 5a 64 3b df 4f d5 3f` | float low dword ~0.00348; **double 0.333** |
| `DAT_009cdae0` | `cd cc cc 3d` | **0.10** |
| `_DAT_009cdae8` | `cd cc 4c 3e` | **0.20** |
| `DAT_00a0f298` | `00 00 00 3f` | **0.50** (used in `00508a00` / floor clamps) |
| `DAT_00aaa668` | `00 00 80 bf` | **−1.0** (sign flip path in `00508a00`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null item early-out | **High** | |
| Unit random + quality scale selection | **High** | Constants sealed |
| Scale differs when Broken bit 19 set | **High** | `item[0x5f] >> 19` |
| Switch cases 6/10/0xc/0xe/0x10/0x1c | **High** | Matches `00513d10` allow-list |
| `FUN_00508a00` = scale×random float helper | **High** | Live decompile |
| `param_4` gates finish/broken/skill tints | **High** | Entire tail under `if param_4` |
| Finish calls `00509b10` / `00513cf0` / `SetBroken` | **High** | |
| Subobject field product names (armor stats etc.) | **Tentative** | Offsets sealed |
| `param_2` = quality/level input to finish formula | **Probable** | Used as float scale in durability chance |
| `param_3` / `param_5` seed / stream index | **Probable** | Advanced through `FUN_00508a00` slots |
| Exact mid-band double/float aliasing at `009cdce0` | **Probable** | Dual use in decompiler |

---

## 6. Control flow: clean ≡ raw

**Yes** — large scaffold matches live switch + finish tail. No intentional CF modernization.

---

## 7. Callers

| Site | Role |
|---|---|
| `FUN_004cf120` | Generate/give item path |
| `CVOGSectorMap_GenerateLevelGatedLoot` `0x004d4440` | Optional after give |
| `KillLoot_RollTableItems_Inferred` `0x0050aa80` | After GiveItem when def present |
| `KillLoot_GenerateDrops_Inferred` `0x0050ac80` | Primary death loot |
| `FUN_0050b6c0` | Sibling loot path |

---

## 8. Gaps / open

1. Seal product names for each type-case subobject layout.
2. Confirm `param_3`/`param_5` as deterministic seed vs “ignore / use unit random” (`00508a00` branch on `param_4==0` of helper).
3. Runtime capture of quality tier frequencies vs thresholds 0.333 / 0.666.
4. `DAT_00b042b8` domain (skin/paint table size) for case 6/0xe.

**Verdict:** CF + constants **High**. Field product labels **Tentative**. **accept-with-gaps.**
