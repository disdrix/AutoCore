# Review B (skeptical / adversarial): `aa_005710c0` InventoryGrid_FindItemByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005710c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005710c0_InventoryGrid_FindItemByCbid.md` |
| **Residual scratch** | `reviews/a_005710c0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + CBID key + max-stack mask; **reject** “find-by-COID” and “always ignores Broken” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function finds by **instance COID** | **Falsified** — matches `clonebase+0x34` (CBID). Instance ids are `item+0x160/+0x164`. Sibling `FUN_00571010` is COID walk. |
| 2 | Task/QuickBar “cargo find-by-COID” is correct | **Falsified** — naming debt; address is CBID finder |
| 3 | Always skips Broken items | **Falsified** — Broken filter only when `param_3==0` |
| 4 | Type-4 max is unlimited 999999 | **Overstated** — loaded 999999 then **masked to u16** → 16959 |
| 5 | Default max 200 is always applied | **Falsified** — only when def `+0x4BA` is 0 (and type≠4) |
| 6 | Mutates stacks / places items | **Falsified** — lock + iterate + return pointer only |
| 7 | `this` is character, not grid | **Falsified** — unlock offsets match InventoryGrid pattern; callers use cargo grid `char+0x250→+0x2b0` |
| 8 | Scaffold dual “sealed” quality (2026-07-23) | **Falsified** — scaffold only; this dual supersedes |
| 9 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow (SEALED)

```
ECX = InventoryGrid*
EBP = ECX + 0x2C                 // list
TraversalLock(EBP)
iter = 0
loop:
  status = IterateNext(EBP, &iter, &item)
  if status != 0: unlock; return NULL
  if item == NULL: continue
  cb = item[+0xA8]
  if *(cb+0x34) != cbid: continue
  if skipStackGate: unlock; return item
  if (item[+0x17C] >> 19) & 1: continue     // Broken
  if *(cb+0x38) == 4:
    max = 999999
  else:
    max = *(u16*)(*(cb+0x3C) + 0x4BA)
    if max == 0: max = 200
  qty = item->vtbl[+0x25C]()
  if (int)(qty + (u16)addQty) <= (int)(max & 0xFFFF):
    unlock; return item
  // else continue
```

Live decompile body ≡ raw 2026-07-23. Bytes confirm `lea ebp,[ecx+0x2c]`, CBID cmp, bit19, 999999 constant, `movzx` capacity, `ret 0x0C`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Match is CBID not COID | **High** | Wrong server port API; confuses InventoryManager.FindByCoid |
| First-fit list order | **High** | Non-deterministic merge target if multi-stack |
| skipStackGate early return | **High** | Broken stacks returned when flag set |
| Broken exclusion (gated) | **High** | Merge onto broken / count parity |
| max & 0xFFFF | **High** | Stack-full false accept/reject near 16-bit edge |
| type==4 branch exists | **High** | Miss unlimited-ish path |
| Product label for type 4 | **Tentative** | Naming only |
| List at +0x2C | **High** | Lock coupling wrong |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `item[0x2a]` as clonebase | Invented? | **No** — asm `+0xA8`; family-wide |
| `+0x34` as COID | Compatible? | **No** — COID is TFID @ +0x160; CountByCbid seals +0x34 as CBID |
| bit19 as Broken | Invented? | **No** — `"Broken: "`, overlay, setter `0x00513de0` (CountByCbid dual) |
| vtbl +0x25c as qty | Invented? | **No** — inventory family standard |
| 999999 used raw in compare | Compatible? | **No** — `movzx si` truncates |
| `param_4` is signed | Compatible? | **No** — `movzx` from BX; signature u16 |
| Places free slot | Hidden? | **No** — no call to Place `0x00571620` |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `aa_005711c0` CountItemsByCbid | Same lock/iterate/CBID/Broken; this returns one ptr + capacity gate |
| `FUN_00571010` | COID (TFID lo/hi) presence on grid — **do not conflate** |
| `aa_005714e0` | Calls this with `(cbid, 0, qty)` for merge X/Y reuse |
| `aa_00571620` Place | Downstream of free-slot path, not this unit |
| Server `InventoryManager.FindByCoid` | **Different key** (instance COID); not a port of this function |

---

## 6. Verdict

**accept-with-gaps.** Static CF, CBID key, Broken gate, list embed, and max-stack masking are **sealed**. Runtime/diff/PDB remain open. Any documentation that still says this VA is “find-by-COID” is **wrong** and must not be used as evidence.
