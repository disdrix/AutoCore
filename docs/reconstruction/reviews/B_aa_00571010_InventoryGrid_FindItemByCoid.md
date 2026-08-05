# Review B (skeptical / adversarial): `aa_00571010` InventoryGrid_FindItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571010` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00571010_InventoryGrid_FindItemByCoid.md` |
| **Residual scratch** | `reviews/a_00571010.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + COID key + list embed; **reject** conflation with FindItemByCbid |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function finds by **clonebase CBID** | **Falsified** — matches `item+0x160/+0x164` only; never loads `item+0xA8` / `clonebase+0x34` |
| 2 | Same semantics as `0x005710c0` FindItemByCbid | **Falsified** — different key, arity, no capacity/Broken |
| 3 | Skips Broken items | **Falsified** — no flags load at `+0x17C` |
| 4 | Stack capacity / merge room gate | **Falsified** — no qty vfunc, no max-stack path |
| 5 | Mutates inventory / places / changes qty | **Falsified** — lock + iterate + return pointer only |
| 6 | `this` is character, not grid | **Falsified** — unlock offsets match InventoryGrid list pattern; callers use cargo grid |
| 7 | Three stack args / `ret 0xC` | **Falsified** — bytes show `ret 0x08` (2 dwords) |
| 8 | Scaffold dual “sealed” quality (2026-07-23) | **Falsified** — scaffold only; this dual supersedes |
| 9 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow (SEALED)

```
ECX = InventoryGrid*
ESI = ECX + 0x2C                 // list
TraversalLock(ESI)
iter = 0
loop:
  status = IterateNext(ESI, &iter, &item)
  if status != 0: unlock; return NULL
  if item == NULL: continue
  if *(item+0x160) != coidLo: continue
  if *(item+0x164) != coidHi: continue
  unlock; return item
```

Live decompile body ≡ raw 2026-07-23. Bytes confirm `lea esi,[ecx+0x2c]`, dual cmp on `+0x160/+0x164`, unlock via list+0x28 / list+4, `ret 0x08`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Match is instance COID not CBID | **High** | Wrong port of FindByCbid; merge/stack bugs |
| First-fit list order | **High** | Non-deterministic if duplicate COIDs ever exist |
| No Broken filter | **High** | Broken stacks still returned (callers must handle) |
| No capacity gate | **High** | Confusing with merge-room FindByCbid |
| List at +0x2C | **High** | Lock coupling wrong |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x160/+0x164` as CBID | Compatible? | **No** — CBID is `*(item+0xA8)+0x34`; sibling seals that |
| `+0x160` as only 32-bit id | Compatible? | **No** — both dwords compared |
| Hidden capacity after match | Hidden? | **No** — jump straight to unlock/return |
| `param_1` is list not grid | Compatible? | **No** — `lea esi,[ecx+0x2c]` then unlock relative to ESI; decompiler unlock uses `param_1+0x54` (grid) |
| Places free slot | Hidden? | **No** — no call to Place `0x00571620` |
| `ret` stack size wrong | Compatible? | **No** — `C2 08 00` at both exits |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `aa_005710c0` FindItemByCbid | **Sibling** — same lock/iterate; **CBID** + optional capacity; **do not conflate** |
| `aa_005711c0` CountItemsByCbid | Same list embed; CBID count + Broken |
| `FUN_00571830` | Calls this with COID → qty merge on found stack |
| `FUN_00571d80` | FindByCoid then `FUN_00571b80` |
| `Client_RecvInventoryEquip` / Drop / Add | Resolve cargo item by instance id before pull/place/swap |
| Server `InventoryManager.FindByCoid` | **Same key class** (instance COID); still not a bit-identical port claim |

---

## 6. Verdict

**accept-with-gaps.** Static CF, COID key, list embed, and absence of capacity/Broken are **sealed**. Runtime/diff/PDB remain open. Any text that equates this VA with `FindItemByCbid` (`0x005710c0`) is **wrong**.
