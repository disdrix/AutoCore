# Review B (skeptical / adversarial): `aa_005142a0` Item_GetStoreSellPrice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005142a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_005142a0_Item_GetStoreSellPrice_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on gate + float formula; **reject** overclaims that this sells, multiplies qty, or is the want predicate |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the store-want bool | Sibling `0x00513770` returns AL; this returns int price | **Falsified** |
| 2 | Unwanted items still get min price 1 | Gate returns **0** before math when `def && +0x3B4!=1` | **Falsified** |
| 3 | Null def → price 0 | Null def jumps **into** compute (permissive) | **Falsified** |
| 4 | Scale is 0.1 then optional 0.5 on base | Bytes: `*0.1` then truncate, **then** optional `*0.5` on already-truncated int | **Clarify** — sequential, not `base*0.05` fused |
| 5 | Floor uses `max(1, price)` with signed <1 | Asm: `test; jg; mov 1` ≡ ≤0 → 1 | **Equiv** for int |
| 6 | Free call `FUN_004f1e20(0,1)` | ECX loaded from `item+0xA8` | **Falsified framing** |
| 7 | This multiplies quantity | Qty is caller `vtbl+0x25c` in `FUN_00587970` | **Falsified** |
| 8 | This adds credits | `CVOGCharacter_AddCredits` is caller | **Falsified** |
| 9 | Constants guessed | `read_memory` seals 0.1f / 0.5f bit patterns | **Falsified** guess claim |
| 10 | Ready product name | `_Inferred` | **Open** |

---

## 2. Decisive dataflow (SEALED)

```text
int __thiscall Item_GetStoreSellPrice_Inferred(Item* item)
{
    Clonebase* cb = *(Clonebase**)((uint8_t*)item + 0xA8);
    if (*(void**)((uint8_t*)cb + 0x3C) == nullptr)
        Clonebase_EnsureDefLoaded(cb, 0, 1);

    void* def = *(void**)(*(uint8_t**)((uint8_t*)item + 0xA8) + 0x3C);
    if (def && *(int32_t*)((uint8_t*)def + 0x3B4) != 1)
        return 0;

    int base = FUN_00513580(item) + *(int32_t*)((uint8_t*)item + 0xC4);
    int price = (int)((float)base * 0.1f);          // trunc
    if ((*(uint8_t*)((uint8_t*)item + 0x17E) & 8) != 0)
        price = (int)((float)price * 0.5f);         // trunc again
    if (price <= 0)
        price = 1;
    return price;
}
```

**Cross-seals:**

| Peer | Relation |
|------|----------|
| `Item_IsWantedByStore` | same ensure; bool of `+0x3B4==1`; null def → true |
| `FUN_00587970` | want && price!=0 → qty * price → AddCredits |
| `Clonebase_EnsureDefLoaded` | this dual `aa_004f1e20` |
| Toast on want fail | parent dual (not this unit) |

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate polarity vs want sibling | **High** | Free items / blocked sells |
| 0.1 / 0.5 constants | **High** | Economy off by 10× |
| Sequential trunc vs fused | **High** | Off-by-one credits |
| min price 1 for allowed | **High** | Zero-credit sells |
| Flag `+0x17E&8` English | **Probable** | Wrong condition class |
| `+0xC4` English | **Probable** | Wrong base field |
| Runtime table | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Half applied to base before 0.1 | Compatible with bytes? | **No** — 0.1 first, then half |
| Unwanted → min 1 | Gate? | **No** — early `return 0` |
| `FUN_00513580` free global | ECX=item before call | **thiscall** on item |
| Price is float return | `cvttss2si` → EAX int | **int** |

---

## 5. Surviving contract for AutoCore

```text
// Vendor sell UI / auto-sell helper:
if (!Item_IsWantedByStore(item)) { toast(...); return; }
int unit = Item_GetStoreSellPrice(item);  // 0 if unwanted (belt+suspenders)
if (unit == 0) return;
int total = unit * item.GetStackQty();    // caller-side
AddCredits(player, total);
```

Do **not** treat this unit as want-predicate, qty multiplier, or credit applier.

**Verdict:** **accept-with-gaps**
