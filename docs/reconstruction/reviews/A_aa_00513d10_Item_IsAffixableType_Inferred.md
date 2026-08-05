# Review A (reconstruction fidelity): `aa_00513d10` Item_IsAffixableType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513d10` |
| **VA** | `0x00513d10` |
| **Canonical name** | `Item_IsAffixableType_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00513d10`; scaffold Named_CalleeOf… |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00513d10_Item_IsAffixableType_Inferred.md` |
| **System** | inventory-transfer / loot quality path |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Predicate: is this item’s def type eligible for quality/affix rolling?**

Reads type code at `*(item+0xa8)+0x38` and returns **1** iff:

| Type (`+0x38`) | Condition |
|---|---|
| **6** | Def blob `*(+0x3c) != 0` and subtype short `@blob+0x3f4` is **10 or 11** (`9 < sub < 0xc`) |
| **10, 0xc, 0xe, 0x10, 0x1c** | Always true |
| **else** | False (return 0) |

Exactly mirrors the **switch cases** handled by `FUN_00509c70` quality/affix roller (type 6 only special-cases some subtypes there for paint/skin; this predicate further restricts type 6 to subtypes 10–11).

Sole static caller: `FUN_0050ac80` (`KillLoot_GenerateDrops_Inferred`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00513d10_*` |
| Live decompile | Ghidra `0x00513d10` (2026-07-29) — **≡ raw** |
| Sibling roller | `FUN_00509c70` type switch |
| Type-6 remap peer | `FUN_00509b10` (subtype 10→0x44, 11→0x46) |
| Caller | `FUN_0050ac80` only |

---

## 3. Control flow

```
FUN_00513d10(item /* ECX */):
  host = *(uint*)(item + 0xa8)
  switch (*(int*)(host + 0x38)):
    case 6:
      blob = *(int*)(host + 0x3c)
      if blob == 0: break → false
      sub = *(short*)(blob + 0x3f4)
      if 10 <= sub <= 11: return 1
      break → false
    case 10:
    case 0xc:
    case 0xe:
    case 0x10:
    case 0x1c:
      return 1
  return 0   // low byte clear
```

Decompiler `CONCAT31` / `uVar2 & 0xffffff00` is bool-in-AL packaging.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Type switch on `host+0x38` | **High** | |
| Type 6 needs subtype ∈ {10,11} | **High** | |
| Five always-true types | **High** | |
| Aligns with `00509c70` case list | **High** | Same set |
| Aligns with `00509b10` type-6 subtype remap window | **High** | 10/11 |
| Sole caller kill-loot generate | **High** | static |
| Product name “affixable” | **Probable** | Role = quality-path filter |
| Host at `+0xa8` layout name | **Probable** | Same family as `00513cf0` |

---

## 5. Control flow: clean ≡ raw

**Yes** — switch + type-6 gated return.

---

## 6. Gaps / open

1. Product names for type codes 6/10/0xc/0xe/0x10/0x1c (weapon/armor/…).
2. Why type 6 subtypes outside 10–11 still appear in `00509c70` case 6 body (paint) but fail this predicate — different call sites.
3. Whether UI or other paths should share this allow-list (currently only kill-loot).

**Verdict:** Predicate CF **High**. Type lexicon residual. **accept-with-gaps.**
