# Review B (skeptical / adversarial): `aa_00571830` InventoryGrid_MergeStackQty

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00571830_InventoryGrid_MergeStackQty.md` |
| **Residual scratch** | `reviews/a_00571830.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI + qty merge; **reject** place/capacity/VOG-name claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function **places** item into cargo / free slot | **Falsified** — no `PlaceItemFootprint` / FindFree / cell stamp |
| 2 | Generic “add item” or full inventory write | **Overstated** — only GetQty + SetQty on **found** COID |
| 3 | Enforces max stack / capacity | **Falsified** — no compare; raw `add` + SetQty |
| 4 | Filters Broken / stack-eligible / CBID match | **Falsified** — FindByCoid only; no `00513e70` / CBID path |
| 5 | `Named_VOG_DEBUG_STOP` is purpose / primary path | **Falsified** — string only on miss; log flag **0** no-ops |
| 6 | Two stack args / `ret 0x08` | **Falsified** — both exits `C2 0C 00` |
| 7 | `this` is character or item, not grid | **Falsified** — `EDI=ECX` drives FindByCoid this + `+0x21/+0x24` grid fields |
| 8 | Second `FUN_00512670` dirties grid itself | **Falsified** — loads `ECX=[EDI+0x24]` then call; dirties **owner pointer** |
| 9 | Decompiler “param_1 is first stack arg” | **Framing residual only** — Ghidra labels thiscall `this` as `param_1`; bytes confirm ECX |
| 10 | Scaffold dual “sealed” quality (2026-07-23) | **Falsified** — scaffold only; this dual supersedes |
| 11 | Ready for bit-exact / runtime seal | **Fail** — open |

---

## 2. Decisive dataflow (SEALED)

```
ECX = InventoryGrid* → EDI
item = FindItemByCoid(EDI, coidLo, coidHi)   // 0x00571010
if item == 0:
    FUN_007a4480(0, "VOG_DEBUG_STOP")        // no log
    return 0                                 // AL=0, ret 0xC
cur  = item.vtbl[+0x25C]()
item.vtbl[+0x260](cur + qtyDelta)
MarkDirty_0x20000(item)                      // FUN_00512670
owner = *(EDI + 0x24)
if owner: MarkDirty_0x20000(owner)
*(u8*)(EDI + 0x21) = 1
return 1                                     // AL=1, ret 0xC
```

Live decompile body ≡ raw 2026-07-23. Bytes confirm vtbl slots, owner branch, dirty byte, and arity.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = qty merge on existing COID stack | **High** | Server ports place instead of merge → desync |
| No capacity clamp here | **High** | Double-gate or silent overflow if callers skip FindByCbid capacity |
| `ret 0x0C` / three stack args | **High** | Wrong ABI → stack corruption |
| Owner dirty is `grid+0x24` object, not grid | **High** | Dirty wrong entity |
| Log path is dead (flag 0) | **High** | Wasted debug work; not a real assert |
| Product name of dirty bit / `@+0x21` | **Open** | UI refresh coupling residual |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Body places footprint | Hidden call? | **No** — only three callees + two vcalls |
| `qtyDelta` is absolute qty | Compatible? | **No** — `add` with GetQty result |
| Miss path crashes | `VOG_DEBUG_STOP`? | **No** — returns 0; log disabled |
| `+0x24` is integer owner id not pointer | Compatible? | **No** — used as `this` for object dirty helper (`+0x17C`) |
| Find uses CBID | Compatible? | **No** — forwards to sealed FindByCoid |
| Positive-only delta | Body clamp? | **No** — signed/unsigned not checked |
| `ret` size wrong | Compatible? | **No** — `C2 0C 00` both exits |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `aa_00571010` FindItemByCoid | **Direct callee** — COID presence only |
| `aa_005710c0` FindItemByCbid | **Not called** — capacity-aware find is **caller** responsibility |
| `aa_00571620` PlaceItemFootprint | **Sibling** place path; do **not** conflate |
| `aa_00513e70` Item_IsStackEligible | Used by callers (RecvAdd / loot place), **not** this body |
| `aa_008151a0` Client_RecvInventoryAddItem | Merge branch when `@+0x12` + in-grid |
| `aa_00530df0` Client_SendInventoryAddItem | C2S merge branch |
| `aa_004f3a30` CreateCargo… | Seals owner store at `grid+0x24` (vfunc `+0x18`) |
| `FUN_00512670` | Dirty mark `\|0x20000` on object + child chain |

---

## 6. Agreement with A

| Claim | A | B |
|-------|---|---|
| Stack-qty merge by COID | Sealed | Sealed |
| No place / no capacity in body | Sealed | Sealed |
| ABI thiscall + 3 stack / `ret 0xC` | Sealed | Sealed |
| `Named_VOG_DEBUG_STOP` purpose name | Reject | Reject |
| PDB / runtime | Open | Open |

No dual conflict on sealed facts.

---

## 7. Verdict

**accept-with-gaps.** Hostile re-read of bytes and callees confirms merge-only behavior. Any description that calls this unit a place helper, capacity gate, or “VOG debug stop” primary is **wrong**. Remaining gaps are naming product labels and runtime verification only.
