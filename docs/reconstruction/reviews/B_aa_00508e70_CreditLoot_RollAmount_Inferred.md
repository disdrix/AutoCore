# Review B (skeptical / adversarial): `aa_00508e70` CreditLoot_RollAmount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508e70` |
| **VA** | `0x00508e70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00508e70_CreditLoot_RollAmount_Inferred.md` |
| **System** | missions-progression / combat death loot (credits) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function awards kill XP | Parent already awarded XP before call; result is amount → `FUN_004d2750` | **Falsified** as XP — **credits/amount** |
| 2 | Always returns non-zero | Random gate + missing row → 0 | **Falsified** |
| 3 | `param_2` is pure float chance | `FUN_00508dc0` reads `param_2+0xb0/0xb8` map | **Falsified as pure float** — object/table (**Probable** pointer; stack reuse) |
| 4 | Multiplier `+0xc64` always scales base | When `mult >= 1.0`, scaled term is mult alone (then `base + ROUND`) | **Survives with nuance** |
| 5 | `DAT_00aaa638` is 1/65535 | `read_memory` → **1/65536** class (`0x37800080`) | **Falsified** if claimed 65535 |
| 6 | Range pick always runs | `span == 0` skips rem; base stays min | **Survives** |
| 7 | Scaffold name implies exclusive OnDeath callee | Callers list: only OnDeathAwardKillXp | **Survives** (static) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Credit amount roll CF | **High** | Wrong economy |
| Unit random + chance gate | **High** | Always-drop or never-drop |
| Row offsets 0x38/0x3c/0x40 | **High** | Wrong table layout |
| Owner +0xc60/+0xc64 | **High** offsets; **Probable** labels | Bad port of loot luck |
| Second formal type | **Probable** | Mis-wire table lookup |
| Product name | **Probable** | Cosmetic |

---

## 3. Cross-check against raw (minimal)

Live decompile 2026-07-29 ≡ raw `aa_00508e70` body (chance/add/random/rem/mult/ROUND).

Parent: `lVar15 = FUN_00508e70(pvVar5, local_74); if (0 < lVar15) FUN_004d2750(lVar15, … FUN_00521510 …)`.

---

## 4. Surviving contract for AutoCore

```
// Credit amount roll (death path)
int64 RollCreditAmount(Entity* owner, CreditTable* table) {
  row = LookupCreditRow(table);  // FUN_00508dc0
  if (!row) return 0;
  chance = row->chance; // +0x38
  if (chance > 0) chance += min(owner->creditChanceAdd /*+0xc60*/, 1.0f) when add<=1 path as raw;
  if (UnitRandom() > chance) return 0;
  base = RandomInRange(row->min /*+0x3c*/, row->max /*+0x40*/);
  mult = owner->creditMult /*+0xc64*/;
  add = ROUND(mult >= 1.0f ? mult : base * mult);
  return base + add;
}
// Port: do not treat as XP; do not use 1/65535.
```

---

## 5. What would overturn this dual

1. Asm proof second formal is scalar float (would break 00508dc0 object reads — Ghidra wrong).
2. Evidence `FUN_004d2750` is not credit/currency award.
3. Different random scale constant in retail image.

**Verdict:** **accept-with-gaps** — body High; table-key typing residual.
