# Review B (skeptical / adversarial): `aa_00513d10` Item_IsAffixableType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513d10` |
| **VA** | `0x00513d10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513d10_Item_IsAffixableType_Inferred.md` |
| **System** | inventory-transfer / loot quality path |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function rolls affixes | Pure type allow-list; no random | **Falsified** as roller |
| 2 | Type 6 always allowed | Requires subtype 10 or 11 and non-null blob | **Falsified** |
| 3 | Allow-list is {6,10,12,14,16,28} without nuance | Type 6 is conditional | **Survives with nuance** |
| 4 | Used by all loot paths | Only `0050ac80` static caller | **Survives** — narrow |
| 5 | `0xc` means 12 decimal product type “armor” | Numeric sealed; name open | **Tentative** product |
| 6 | Return is full EAX count | Bool packaging (`& 0xffffff00` / CONCAT) | **Survives as bool** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Switch membership | **High** | Affix wrong item classes |
| Type-6 subtype window 10–11 | **High** | Include/exclude weapons wrongly |
| Host `+0xa8`, type `+0x38`, subtype `+0x3f4` | **High** | |
| Product type names | **Tentative** | Docs only |
| Shared with non-loot systems | **Open** | Missing callers if dynamic |

---

## 3. Cross-check against raw (minimal)

Live ≡ raw. Cross-check vs `00509c70` switch cases and `00509b10` subtype remap: consistent type-6 special case.

---

## 4. Surviving contract for AutoCore

```
bool Item_IsAffixableType(Item* item) {
  auto* host = item->field_a8;
  switch (host->type /*+0x38*/) {
    case 6: {
      auto* blob = host->blob /*+0x3c*/;
      if (!blob) return false;
      int sub = blob->subtype /*+0x3f4*/;
      return sub == 10 || sub == 11;
    }
    case 10: case 0x0c: case 0x0e: case 0x10: case 0x1c:
      return true;
    default:
      return false;
  }
}
// Port: keep type-6 subtype gate; do not treat as the roller itself.
```

---

## 5. What would overturn this dual

1. Asm subtype compare not exclusive 10–11.
2. Additional type cases in retail not visible in decompile.
3. Evidence host type lives at different offset than `+0x38`.

**Verdict:** **accept-with-gaps** — allow-list High; product type names open.
