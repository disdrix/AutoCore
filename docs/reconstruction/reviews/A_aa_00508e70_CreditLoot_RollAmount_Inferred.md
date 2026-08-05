# Review A (reconstruction fidelity): `aa_00508e70` CreditLoot_RollAmount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508e70` |
| **VA** | `0x00508e70` |
| **Canonical name** | `CreditLoot_RollAmount_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00508e70`; scaffold `Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00508e70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00508e70_CreditLoot_RollAmount_Inferred.md` |
| **System** | missions-progression / combat death loot (credits) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Death-path **credit/money amount roll**. Given a **killer/loot owner** (`param_1`) and a **credit-table root** (second formal; decompiler float-types a pointer stack slot), look up the active credit row via `FUN_00508dc0`, apply owner modifiers at `+0xc60` / `+0xc64`, gate on a unit random roll, then return a non-negative integer amount (as `longlong`) or **0** on miss/no-table.

Sole death-path caller: `CVOGCombat_OnDeathAwardKillXp` (`0x004da630`) when level gap `< 11` and credit table source is valid — result feeds `FUN_004d2750` with scatter origin from `FUN_00521510`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508e70_FUN_00508e70.md` |
| Annotated | `docs/reconstruction/raw/aa_00508e70_FUN_00508e70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00508e70.cpp` / Named_* twin |
| Function record | `docs/reconstruction/functions/aa_00508e70_FUN_00508e70.md` |
| Live decompile | Ghidra `0x00508e70`, helper `0x00508dc0` (2026-07-29) |
| Constants | `DAT_00aaa638` = **1/65536** (`read_memory` `80008037`) |
| Caller | `aa_004da630` annotated call at post-XP credit branch |

---

## 3. Control flow (authoritative raw / live)

```
FUN_00508e70(owner, tableOrKey):
  row = FUN_00508dc0(tableOrKey)   // map lower-bound on table+0xb0; payload @node+0x10
  if row == 0: return 0

  chance = *(float*)(row + 0x38)
  bonus = 0.0
  if chance > 0.0:
    if *(float*)(owner + 0xc60) <= 1.0:  // g_flOne
      bonus = *(float*)(owner + 0xc60)
    chance = bonus + chance

  // unit random U16/65536 via CVOGReaction_RandomUnitScalar ring (wrap at 0x100000)
  if (float)u16 * DAT_00aaa638 > chance: return 0

  span = *(int*)(row+0x40) - *(int*)(row+0x3c)
  base = (longlong)*(int*)(row+0x3c)
  if span is non-zero (signed 64-bit range check):
    r = random U16 % span   // __allrem
    base = base + r

  mult = *(float*)(owner + 0xc64)
  if mult >= 1.0:
    scaled = mult
  else:
    scaled = (float)base * mult
  return base + (int)ROUND(scaled)
```

`FUN_00508dc0` (live): if `table+0xb8 == 0` → 0; else `Map_LowerBoundFindByIntKey(table+0xb0, …)` and return payload `*node+0x10` when key hits.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature two formals → integer amount (`longlong`) | **High** | Live; caller uses `0 < lVar15` |
| Null/miss row → 0 | **High** | Early exit |
| Chance at `row+0x38`; range `[+0x3c,+0x40)` | **High** | Body |
| Owner luck/add at `+0xc60` (cap 1.0 when ≤1) | **High** | Only applied when chance > 0 |
| Owner multiplier at `+0xc64` (≥1 uses raw mult as additive ROUND source; else base×mult) | **High** | Unusual: when mult≥1, scaled path uses mult alone then `base+ROUND(mult)` |
| Unit random scale `1/65536` | **High** | `DAT_00aaa638` bytes |
| Random ring wrap index `> 0xfffff` → 0 | **High** | Shared pattern |
| Product role = **credits** not item CBID | **High** | Caller awards via `FUN_004d2750(amount, …)` not GiveItem |
| Second formal is table pointer (not float) | **Probable** | Stack slot reused as float in parent; 00508dc0 treats as object with `+0xb0` map |
| Semantic names of `+0xc60`/`+0xc64` (loot luck / credit mult) | **Probable** | Offsets sealed; product labels open |
| Exact map key identity into 00508dc0 | **Open** | Parent loads `local_74` from def `+0x514` / `+0x178` |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Row lookup | **Yes** |
| Chance + owner add | **Yes** |
| Random gate | **Yes** |
| Range pick + mult + ROUND return | **Yes** |
| Fail → 0 | **Yes** |

Scaffold Named_* body matches raw; no CF drift.

---

## 6. Callers

| Site | Role |
|---|---|
| `CVOGCombat_OnDeathAwardKillXp` `0x004da630` | Only UNCONDITIONAL_CALL; after XP; level gap `< 11` |

---

## 7. Gaps / open

1. Confirm second formal provenance (def float vs pointer) at call site asm.
2. Name/role of owner `+0xc60` / `+0xc64` in character layout registry.
3. Runtime capture of credit amounts vs table min/max.

**Verdict:** CF and constants **High**. Product name **Probable**. Residual is table-key typing and owner-mod labels. **accept-with-gaps.**
