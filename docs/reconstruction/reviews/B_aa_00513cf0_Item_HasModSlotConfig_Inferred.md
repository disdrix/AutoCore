# Review B (skeptical / adversarial): `aa_00513cf0` Item_HasModSlotConfig_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513cf0` |
| **VA** | `0x00513cf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513cf0_Item_HasModSlotConfig_Inferred.md` |
| **System** | inventory-transfer / loot broken-roll gate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function sets Broken | Body is pure predicate; SetBroken is callee of parent | **Falsified** as setter |
| 2 | Always true if def non-null | Requires `00599dd0() > 0` | **Falsified** |
| 3 | Counts equipment quantity | Helper counts `!= -1` among five fixed offsets | **Survives** as slot occupancy count |
| 4 | `+0xa8` is always item root | Pattern matches item/host def pointer family | **Probable** |
| 5 | Only used for broken rolls | Also loot generators 004d4440 / 0050ac80 | **Falsified** exclusivity — multi-use gate |
| 6 | Name Confirmed | Inferred | **Probable** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bool return 0/1 | **High** | |
| Def present gate `@host+0x3c` | **High** | False positives |
| Count helper `00599dd0` | **High** | |
| This-arg into helper | **Probable** | Wrong object counted |
| Product label | **Probable** | Cosmetic |

---

## 3. Cross-check against raw (minimal)

Live ≡ raw. Parent `00509c70`:

```
if ((rand%100 < 11) && FUN_00513cf0() && zoneOk)
  vtbl+0x90(0); FUN_00513de0(1);  // SetBroken
```

---

## 4. Surviving contract for AutoCore

```
bool Item_HasModSlotConfig(Item* item) {
  auto* host = item->field_a8;
  if (!host || host->defBlob /*+0x3c*/ == nullptr) return false;
  return CountConfiguredSlots(hostOrDef) > 0; // FUN_00599dd0: five ints != -1
}
// Port: do not set broken here; use only as eligibility predicate.
```

---

## 5. What would overturn this dual

1. Asm showing `00599dd0` this-pointer is unrelated global.
2. Evidence return is a count not a bool (callers only test nonzero — still compatible).
3. Def offset not `+0x3c` under `item+0xa8`.

**Verdict:** **accept-with-gaps** — predicate High; this-arg residual.
