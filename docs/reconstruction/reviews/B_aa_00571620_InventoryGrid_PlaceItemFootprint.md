# Review B (skeptical / adversarial): `aa_00571620` InventoryGrid_PlaceItemFootprint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (strengthen: stamp byte seal) |
| **Counterpart** | `reviews/A_aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and strengthened** (supersedes thin wave2 dual + narrative-only stamp seal) |
| **Verdict** | **accept-with-gaps** on CF + stamp formula; **reject** overclaims that decompiler `unaff_*` body is retail-correct or that this unit is bit-exact complete |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only finds free slot | **Falsified** — places/stamps at coords after CanPlace |
| 2 | Always succeeds | **Falsified** — type reject + CanPlace |
| 3 | Decompiler stamp formula is retail | **Falsified** — bytes show different index; raw `height*(sizeY+row)+…` is corrupted |
| 4 | `unaff_SI` is unknown free register | **Falsified** — outer bound is **sizeX** |
| 5 | `unaff_retaddr` is accidental | **Falsified** — **quantity** 4th stack arg to vtbl+0x260 |
| 6 | Finished English reject type names | **Fail** — CMP set sealed; names open |
| 7 | Type 4 also stamps cells | **Falsified** — early return before loop |
| 8 | Wave2 dual A/B sealed stamp quality | **Falsified** — scaffold-only; residual supersedes |
| 9 | Ready for bit-exact / complete | **Fail** — runtime/diff open |
| 10 | Client cells row-major `y*w+x` | **Falsified** — `height*x+y` (same as FindFree) |
| 11 | Stamp seal was only narrative | **Falsified this pass** — `read_memory` opcodes at `0x005717b0` region |

---

## 2. Decisive dataflow (bytes 2026-07-29)

```
item = stack0; grid = ECX
type = *(item+0xa8)+0x38
if type in {0x12,0x14,0x16,0x36,0x38,0x3a}: return 0
if type == 4:
  Listish_Op(grid+0x2c, item)   // FUN_00566f00
  item.vtbl+0x158(grid+0x24)
  return 1

sizeX = *(u8*)(blob+0x406); sizeY = *(u8*)(blob+0x407)
if grid+4==4: zero dims → 2

if !CanPlace(grid, sizeX, sizeY, originX, originY, NULL): return 0

item.vtbl+0x158(); item.vtbl+0x24c(originX, originY); item.vtbl+0x40(1)
// optional gfx if (item+0x17c)>>6 & 1
item.vtbl+0x260(quantity)

for dx in 0 .. sizeX-1:
  for dy in 0 .. sizeY-1:
    idx = *(grid+0xc) * (originX + dx) + (originY + dy)
    cells[idx].lo = item+0x160
    cells[idx].hi = item+0x164

Listish_Op(grid+0x2c, item)
item+0x17c |= 0x10
FUN_00512670(item); FUN_005706d0(grid)
return 1
// RET 0x10  (C2 10 00)
```

### Byte attack on index (decisive)

| Attack | Bytes | Result |
|--------|-------|--------|
| Multiplier is width not height? | `MOV EDX,[EDI+0x0c]` then `IMUL` | **height** field |
| Multiplicand is sizeY+row? | `IMUL [ESP+0x14]` after `baseX=ox+dx` store | **ox+dx** |
| Missing originY? | `ADD EDX,[ESP+0x18]` after `ADD EDX,EAX` (dy) | **oy+dy** |
| Row-major? | No width multiply; only height | **column-major height*x+y** |
| 4-byte cells? | stores at `EDX*8` and `+4` | **8-byte COID pair** |

Live **decompile** still emits `unaff_SI` / `unaff_retaddr` — treat as **tooling failure**. Live **bytes** are authoritative for the stamp residual.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stamp rect coverage | **Confirmed** | Occupancy holes / overlaps |
| Index vs CanPlace/FindFree | **Confirmed** | Place succeeds then Find free wrong cells |
| Outer=sizeX / inner=sizeY | **Confirmed** | Swapped footprint stamp |
| Quantity 4th arg | **High** | Wrong stack counts |
| Type-4 bypass | **High** | Phantom occupancy |
| Reject CMP set | **High** | Allow illegal place |
| Reject English names | **Open** | Docs only |
| Runtime 2×3 six-cell dump | **Open** | Residual parity risk |
| Bit-exact complete | **Fail** | Policy |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Decompiler `height*(sizeY+row)+col+bStack_8` | Retail? | **No** — bytes falsify |
| `idx = height*(ox+dx)+(oy+dy)` | Invented? | **No** — `IMUL [EDI+0xc]` + adds |
| COID at item+0x160/+0x164 | Invented? | **No** — `[ESI+0x160]` / `+0x164` |
| Empty model after place | Compatible? | **Yes** — non-`0xFFFFFFFF` halves vs FindFree free test |
| Row-major client buffer | Compatible? | **No** — column-major; ports using `(x,y)` sets OK |
| `FUN_00566f00(this=item)` | Accurate? | **No** — `this=grid+0x2c` (`LEA ECX,[EDI+0x2c]`) |
| inventoryType read here | Hidden? | **No** — caller selects grid |
| `RET 0x0C` (3 args)? | ABI? | **No** — epilogue `C2 10 00` |

### Algebra note (legacy skeptical C2)

Legacy B claimed place index might not match FindFree. **Resolved:** both use `height*x+y`. Decompiler place body was the mismatch source, not retail. CanPlace live decompile: `*(grid+0xc)*x + y`. FindFree free probe: same.

---

## 5. Surviving contract for AutoCore

```
PlaceItemFootprint(grid, item, ox, oy, qty):
  reject type set; type4 attach-only
  dims from InvSize (+ store min 2×2)
  if !CanPlace(full rect): fail
  bind item; set qty
  for each (ox+dx, oy+dy) in footprint:
    occupy cell (server: HashSet<(x,y)> or equivalent multi-cell)
  mark placed

Pairs: FindFreeSlot + SerializeAddItemPacket (wire origin-only)
```

Server already multi-cell stamps; residual was **client formula honesty**, not a new port requirement if logical XY used.

---

## 6. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Runtime: place 2×3 → six matching COID cells at expected indices | **Yes** for complete / bit-exact |
| R2 | Reject type retail names | Mild |
| R3 | vfunc PDB names | Mild |
| R4 | Stamp formula / dual quality | **Closed** (byte seal this dual) |

---

## 7. Concrete checks performed

1. `read_memory` stamp core + outer setup — hand-decoded opcodes (`IMUL`/`ADD`/`MOV [EBX+EDX*8]`).
2. Compared index to live CanPlace + FindFree decompiles — **match**.
3. Epilogue `RET 0x10` bytes — 4 stack args; bound quantity and origins.
4. Verified six reject CMPs (prologue) and type-4 early path.
5. Corrected `FUN_00566f00` / `+0x24c` arg myths.
6. Attacked decompiler stamp expression — **falsified**.
7. Attacked “narrative-only seal” — **replaced with byte evidence**.

---

## 8. Verdict

### **accept-with-gaps**

Stamp residual is **closed at Confirmed** via `read_memory` opcodes (no reliance on `disassemble_bytes` / corrupted decompile). Package is still not complete (runtime/diff). Decompiler body must not be used as stamp authority.

### Stronger-verdict bar (complete)

1. CE/runtime: place known footprint → dump cell array COIDs at sealed indices.
2. Optional differential vs AutoCore multi-cell occupancy for same origin/size.
3. Name reject types if clonebase enum recovered.

---

## 9. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Every footprint cell stamped | **Holds** (bytes) |
| 2 | Decompiler stamp formula | **Falsified** |
| 3 | 8-byte COID cells | **Holds** |
| 4 | Same index as FindFree | **Holds** |
| 5 | Type-4 stamps | **Falsified** |
| 6 | Finished dual quality (wave2) | **Superseded** |
| 7 | Bit-exact complete | **Fail** |
| 8 | `idx = height*(ox+dx)+(oy+dy)` | **Holds Confirmed** |

**Final verdict: `accept-with-gaps`**
