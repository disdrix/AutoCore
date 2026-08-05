# Review B (skeptical / adversarial): `aa_00513580` Item_SumEquippedComponentValues

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513580_Item_SumEquippedComponentValues.md` |
| **System** | `inventory-transfer` (vendor / item value) |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on sum CF + `+0x94`; **reject** “full inventory walk” / “returns price already scaled” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function returns final store sell price | **Falsified** — no `*0.1` / half / min1; callers scale |
| 2 | Walks whole character inventory | **Falsified** — only host item slots via `vtbl+0x60` |
| 3 | Sum field is `item+0xC4` | **Falsified** — adds **`component+0x94`**; callers add `+0xC4` separately |
| 4 | Works with no catalog | **Falsified** — `FUN_004ce940` null → **return 0** |
| 5 | All item types sum components | **Falsified** — only types **10, 0xc, 0xe, 0x1c, 0x44, 0x46**; default skip |
| 6 | Switch key is per-slot type | **Falsified** — switch is **host** `clonebase+0x38` each iteration (constant for item) |
| 7 | Single lookup per hit | **Nuance** — decompile/bytes re-fetch slot + lookup when non-null (preserve) |
| 8 | `__fastcall` with arg in EDX | **Falsified** — `mov esi,ecx`; no second register arg |
| 9 | Scaffold multi-hop client-refresh name is purpose | **Overstated** — pricing callers are the clear economic use |
| 10 | Ready for economy table seal | **Fail** — no runtime golden |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Item*
// ret int sum

catalog = FUN_004ce940()          // singleton; may construct
if catalog == 0: return 0

sum = 0
n = item->vtbl[+0x60]()           // slot count
if n == 0: return 0

i = 0
do:
  type = *(item[0x2a] + 0x38)     // clonebase type
  slotId = item->vtbl[+0x5c](i)
  switch type:
    10   → comp = FUN_00508b60(catalog, slotId)
    0xc  → FUN_00508ac0
    0xe  → FUN_00508bb0
    0x1c → FUN_00508b10
    0x44 → FUN_00508c50
    0x46 → FUN_00508c00
    else → no add
  if comp: sum += *(i32*)(comp + 0x94)   // may re-call slot+lookup first
  i++
  n = item->vtbl[+0x60]()
while i < n

return sum
```

### Byte anchors

| Region | Bytes / fact | Meaning |
|--------|--------------|---------|
| Prologue | `8b f1 33 db e8 … 8b e8 85 ed` | ESI=this; EBX=0; call catalog; EBP=result; null check |
| Sum | `03 98 94 00 00 00` | `add ebx, [eax+0x94]` |
| Epilogue | `8b c3 5b c3` | `eax = sum; ret` |
| JT base | `0x00513714` | 7 dword targets (6 cases + default) |
| Case map | `0x00513730` | type-10 → index byte |

---

## 3. Relation attack: sum vs price formula

| Unit | Role |
|------|------|
| **This** `0x00513580` | raw component value **sum** |
| `0x005142a0` | `(sum + item+0xC4) * 0.1` [, *0.5 if flag], min 1 |
| `0x00514250` | related base+sum pricing path |

**Cannot** claim this function alone is “sell price.”

---

## 4. Lookup sample attack

`FUN_00508b60(catalog, slotId)`: if `slotId != -1` and list non-empty, linear scan `catalog+0x4c` for `*entry+0x6c == slotId`, return entry. Confirms slot ids are **keys**, not raw pointers — supports “equipped component table lookup” reading.

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sum offset `+0x94` | **High / Sealed** | Wrong value field in economy port |
| Six type cases | **High / Sealed** | Missing/extra component classes |
| Catalog gate required | **High** | Sums when tables unloaded |
| Pricing use (caller) | **High** | Misplace in non-economy systems |
| Field English “value” | **Probable** | Cost vs sell vs power |
| Type enum names | **Low** | Wrong class mapping |
| PDB symbol | **Open** | — |

---

## 6. Verdict

### **accept-with-gaps**

CF and **`component+0x94` sum** are **sealed**. Reject “already scaled price,” “full inventory walk,” and “always sums all types.” Leave type/field product English and runtime goldens open.
