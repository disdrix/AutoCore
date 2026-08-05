# Review B (skeptical / adversarial): `aa_0051a170` CVOGReaction_GiveItemByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a170` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0051a170_CVOGReaction_GiveItemByCbid.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This function grants items into player cargo | **Falsified** |
| 2 | All types use same dual-base return | **Falsified** |
| 3 | Type labels sealed from PDB | **Overstated** |
| 4 | Default case still constructs something | **Falsified** |
| 5 | Clean modernized switch order | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Factory CF by type | High | Wrong item class constructed |
| Dual-base formula | High | Broken item pointers |
| Type enum completeness | Probable | Unknown type drops |
| Ctor arg `1` meaning | Tentative | Flags mis-modeled |

---

## 3. Cross-check against raw

```
if !lookup(cbid): return 0
switch type(def+0x38):
  new(size); ctor(...); return dualBase or raw
default: log VOG_DEBUG_STOP; return 0
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
GiveItemByCbid(cbid) -> item_simple_object*|0
  resolve clonebase; construct runtime item by type id
  does NOT push into inventory — caller responsibility
```

---

## 5. Open questions

1. Full clonebase type enum vs server catalog.
2. Whether reaction GiveItem path wraps this + bag insert.
3. Placement-new vs ignored operator_new return.
4. Runtime create for weapon vs blueprint vs token.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.
