# Review B (skeptical / adversarial): `aa_00509b10` Item_ApplyModPack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509b10` |
| **VA** | `0x00509b10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00509b10_Item_ApplyModPack_Inferred.md` |
| **System** | inventory-transfer / loot affix path |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the full quality/stat roller | Body only collects slots + resolve pair; no float quality bands | **Falsified** — sibling `00509c70` owns quality roll |
| 2 | Always succeeds | `005e1150 < 0` → return 0 | **Falsified** |
| 3 | Type remap applies to all items | Only when def type `== 6` and subtype 10/11 | **Survives with gate** |
| 4 | Vector free always returns via normal epilogue | Decompiler marks `operator_delete` as non-returning (Ghidra warning) | **Survives as CF** — product still frees then returns 0/1 |
| 5 | Name “ApplyModPack” is Confirmed product | Inferred from callees + call sites only | **Probable / leave-FUN** |
| 6 | Only caller is `00509c70` | Also `0050ac80` | **Falsified** exclusivity |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot collect + skip `-1` | **High** | Drop existing mods |
| Type-6 subtype remap | **High** | Wrong pack table |
| Resolve pair order | **High** | Broken attach |
| Fail on `result < 0` | **High** | Silent bad items |
| Formal semantics | **Tentative** | Mis-wire from loot parent |
| Product name | **Probable** | Cosmetic |

---

## 3. Cross-check against raw (minimal)

Live ≡ raw. `00509c70` call: `FUN_00509b10(item, 1, uVar10, iVar8, 0)` where `uVar10` / `iVar8` come from def vtbl `+0x14` and def dword `[0xf8]` when broken-def re-roll path fires.

---

## 4. Surviving contract for AutoCore

```
// Apply / re-resolve mod pack onto item
bool Item_ApplyModPack(Item* item, /*p2..p5 pack args*/) {
  vector<uint16_t> slots = collect_valid_mod_ids(item); // vtbl +0x5c/+0x60
  int type = item->def->type; // +0x38
  if (type == 6) {
    short sub = item->defBlob->subtype; // +0x3f4
    if (sub == 10) type = 0x44;
    else if (sub == 11) type = 0x46;
  }
  PrepareModPack(type, …, &slots, …);   // FUN_005e0580
  int id = ResolveModPack(type, …, &slots, …); // FUN_005e1150
  if (id < 0) return false;
  item->SetModPackId(id);  // vtbl +0x54
  return true;
}
```

---

## 5. What would overturn this dual

1. Evidence `005e1150` is not a mod/pack resolver (e.g. pure validation with unrelated return).
2. Asm showing type remap uses different subtype offsets.
3. Call sites that ignore return and treat function as void side-effect only (still OK if return is success flag).

**Verdict:** **accept-with-gaps** — body High; pack product labels open.
