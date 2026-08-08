# Review B (skeptical / adversarial): `aa_00570af0` InventoryGrid_MoveItemFootprint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570af0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF + index + ABI; **reject** decompiler stamp body and “fully named product API” claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is first-time place (like PlaceItemFootprint) | **Falsified** — clears **current** origin first; no type-reject / quantity / list bind |
| 2 | Decompiler stamp formula is retail | **Falsified** — `unaff_retaddr` / `(byte)param_2` vs bytes `ox+dx` / `oy+dy` |
| 3 | CanPlace uses null conflictOut | **Falsified** — local buffer pushed (`LEA` of stack temp) |
| 4 | Same-COID overlap move impossible | **Falsified** — non-null conflictOut tolerates first COID (CanPlace seal) |
| 5 | `RET 0x10` four stack args | **Falsified** — epilogue `C2 0C 00` |
| 6 | Cells are 4-byte | **Falsified** — stores at `*8` and `+4` |
| 7 | Index is row-major `y*width+x` | **Falsified** — `height*x+y` family |
| 8 | Has sealed caller graph | **Fail** — Ghidra xrefs empty |
| 9 | Ready for bit-exact complete | **Fail** — runtime/diff open |
| 10 | PDB name known | **Fail** — Inferred only |

---

## 2. Decisive dataflow (bytes 2026-08-04)

```
item = stack0; grid = ECX
if item == 0: return 0

sizeX = u8(blob+0x406); sizeY = u8(blob+0x407)   // blob via item+0xa8 → +0x3c
if !CanPlace(grid, sizeX, sizeY, originX, originY, &localConflict): return 0

// clear at current
for x = GetX() .. GetX()+sizeX-1:          // vtbl+0x250
  for y = GetY() .. GetY()+sizeY-1:        // vtbl+0x254
    idx = height * x + y
    cells[idx] = (-1, -1)

item.vtbl+0x24c(originX, originY)

for dx in 0 .. sizeX-1:
  for dy in 0 .. sizeY-1:
    idx = height * (originX + dx) + (originY + dy)
    cells[idx] = (item+0x160, item+0x164)

if *(grid+0x24): FUN_00512670(*(grid+0x24))
*(grid+0x21) = 1
return 1
// RET 0x0C
```

### Byte attack on stamp index

| Attack | Bytes | Result |
|--------|-------|--------|
| Multiplier width? | `MOV EDX,[EBP+0x0c]` | **height** |
| Multiplicand sizeY+row? | `IMUL [ESP+baseX]` after `baseX=ox+dx` | **ox+dx** |
| Missing originY? | `ADD EDX,[ESP+oy]` after `+dy` | **oy+dy** |
| COID from wrong offset? | `MOV EBX,[ESI+0x160]` / `+0x164` | **sealed** |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear+stamp coverage | **Confirmed** | Ghost occupancy / holes |
| Index vs CanPlace/Place | **Confirmed** | Move succeeds, probes wrong |
| conflictOut local | **High** | Overlap move falsely rejects |
| ABI 3 stack + this | **Confirmed** | Stack smash in ports |
| Product name | **Inferred** | Docs only |
| Caller existence | **Open** | Dead code risk |
| Runtime 2×3 move dump | **Open** | Residual parity |
| Bit-exact complete | **Fail** | Policy |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Decompiler stamp `unaff_*` | Retail? | **No** — bytes falsify |
| Place-equivalent full bind path | Same as 0x00571620? | **No** — no type reject / qty / list |
| Remove-equivalent detach | Same as 0x00571b80? | **No** — no list detach; re-stamps |
| Orphan ⇒ incorrect body | Body incomplete? | **No** — epilogue/RET closed |

---

## 5. Verdict

### **accept-with-gaps**

Accept sealed CF/index/ABI for a **move/relocate footprint** helper. Reject any claim that raw decompiler stamp is portable, that callers are catalogued, or that product naming is final.
