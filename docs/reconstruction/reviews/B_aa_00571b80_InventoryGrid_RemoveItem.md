# Review B (skeptical / adversarial): `aa_00571b80` InventoryGrid_RemoveItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00571b80_InventoryGrid_RemoveItem.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (supersedes scaffold-only 2026-07-23 package) |
| **Verdict** | **accept-with-gaps** on CF + unstamp formula; **reject** overclaims that decompiler `this` for list ops is complete, that peel unstamps cells, or that package is bit-exact complete |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only checks occupancy / ContainsItem | **Falsified** — clears cells, detaches list, peels stacks |
| 2 | Always removes footprint cells | **Falsified** — peel path with remain&gt;0 && force=0 leaves cells; type 4 skips clear |
| 3 | Partial stack remove unstamps then re-stamps | **Falsified** — peel only SetQty; no clear |
| 4 | `FUN_00415c00` / `FUN_005085b0` this = item or grid root | **Falsified** — bytes `LEA ECX,[EDI+0x2C]` |
| 5 | Signature is free/stdcall 4-arg mess from scaffold | **Falsified** — thiscall + **3** stack; `RET 0x0C` |
| 6 | Clear index is row-major `y*width+x` | **Falsified** — `height*(ox+dx)+(oy+dy)` |
| 7 | Empty cell is zero | **Falsified** — both dwords `0xFFFFFFFF` (matches alloc empty) |
| 8 | Type 4 still multi-cell clears | **Falsified** — early jump past loop |
| 9 | Same list API as Place attach (`FUN_00566f00`) | **Fail as identity** — different VA; both target `+0x2c` |
| 10 | Ready for bit-exact / complete | **Fail** — runtime/diff open |
| 11 | Scaffold `FUN_00571b80.cpp` is finished dual quality | **Falsified** — auto CF scaffold only |

---

## 2. Decisive dataflow (bytes + decompile 2026-07-29)

```
item = stack0; removeQty = stack1; force = stack2; grid = ECX
if item==0 or !ListContains(grid+0x2c, item): return 0

saved = 1
if StackMode(item):                    // FUN_00513e70
  saved = GetQty(item)
  cur = GetQty(item)
  if cur > 1 and !(flags>>15 & 1):
    SetQty(cur - removeQty)
    if GetQty() > 0 and force == 0:
      dirty(owner?, grid+0x21); return 0   // cells UNCHANGED
  elif flags bit15 and force == 0:
      dirty; return 0

// full remove
if type(item) != 4:
  ox, oy = GetOriginX/Y()
  sizeX/Y = blob+0x406/407
  for dx, dy in footprint:
    idx = height*(ox+dx) + (oy+dy)
    if in range: cells[idx] = (-1, -1)

ListDetach(grid+0x2c, item)            // FUN_005085b0
SetQty(saved); Unbind(0)
dirty owner if grid+0x24; grid+0x21 = 1
return item
// RET 0x0C
```

### Byte attack on index (decisive)

| Attack | Bytes | Result |
|--------|-------|--------|
| Multiplier is width? | `MOV ECX,[EDI+0x0c]` then `IMUL` | **height** |
| Missing originY? | `ADD ECX,EAX` after dy | **oy included** |
| Row-major? | No width multiply | **height*x+y** |
| 4-byte cells? | stores at `ECX*8` and `+4` | **8-byte pair** |
| Stamp COID instead of empty? | immediates `FFFFFFFF` | **clear**, not stamp |
| Detach this = item? | `LEA ECX,[EDI+0x2C]; PUSH ESI` | **list subobject** |

Live decompile matches raw CF but **elides** list `this` — treat bytes as authoritative for those two calls.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unstamp rect coverage | **Confirmed** | Ghost occupancy after remove |
| Index vs Place/FindFree | **Confirmed** | Place+remove asymmetry holes |
| Peel leaves stamps | **High** | Double-free / phantom free slots if port unstamps on peel |
| List base +0x2c | **Confirmed** | Remove wrong list |
| ABI RET 0x0C | **Confirmed** | Stack corruption |
| forceFull semantics | **High** | Force-destroy callers (`1000000,1`) |
| Bit15 meaning | **Open** | Docs only |
| Runtime peel/remove dump | **Open** | Residual parity risk |
| Bit-exact complete | **Fail** | Policy |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `idx = height*(ox+dx)+(oy+dy)` | Invented? | **No** — `IMUL [EDI+0xc]` + adds |
| Empty = `-1,-1` | Invented? | **No** — `C7 … FFFFFFFF` twice |
| Compatible with Place stamp | Yes? | **Yes** — inverse of COID pair write |
| Compatible with FindFree empty test `(lo&hi)==-1` | Yes? | **Yes** |
| `FUN_005085b0(this=item)` | Accurate? | **No** — `this=grid+0x2c` |
| Membership optional? | Skipable? | **No** — early return if not in list |
| Peel unstamps | Required? | **No** — branch before clear |
| `RET 0x10` (4 args)? | ABI? | **No** — `C2 0C 00` |

### Caller patterns (attack on arg roles)

| Caller pattern | Args | Implication |
|----------------|------|-------------|
| Equip / many UI | `(item, 1, 0)` | remove 1; allow peel |
| Drop occupant | `(item, qty, 0)` | qty-aware peel |
| `CVOGReaction_RemoveInventoryItem` | `(item, 1000000, 1)` | force full even if bit15 / remain |
| `FUN_00571d80` | FindByCoid then `(item, 1, flag)` | thin wrapper |

---

## 5. Surviving contract for AutoCore

```
RemoveItem(grid, item, removeQty, forceFull):
  require item in grid list
  if stackable and can peel and not force:
    qty -= removeQty; if qty > 0: dirty; return null  // keep footprint
  if type != 4:
    for each cell in InvSize footprint at item origin:
      clear occupancy (server: remove multi-cell coords)
  detach list node; unbind item
  dirty; return item

Pairs: PlaceItemFootprint (stamp) ↔ this (unstamp)
       MergeStackQty (qty only, no cells)
```

Server ports using logical `(x,y)` sets remain valid if clear covers full footprint; **must not** clear on partial stack peel.

---

## 6. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Runtime: place 2×3 → remove → six empty cells at sealed indices | **Yes** for complete |
| R2 | Runtime: peel qty on multi-cell stack → cells still occupied | **Yes** for peel contract complete |
| R3 | Bit15 / force product names | Mild |
| R4 | Unstamp formula / dual quality | **Closed** (byte seal this dual) |
| R5 | Deep `FUN_005085b0` node layout | Out of unit |

---

## 7. Concrete checks performed

1. `read_memory` prologue — `EDI=ECX`, item ESI, `LEA ECX,[EDI+0x2C]`, call `00415c00`.
2. `read_memory` clear core — `IMUL` height × (ox+dx), +dy +oy, store `-1` pairs at `cells[idx*8]`.
3. `read_memory` post-loop — `LEA ECX,[EDI+0x2C]`, call `005085b0`; SetQty; `+0x158(0)`.
4. Epilogue `RET 0x0C` + `grid+0x21=1`.
5. Live decompile ≡ raw body; force-decompile not required (no unaff corruption on clear path).
6. Compared index to Place dual — **match**.
7. Attacked “peel unstamps” and “scaffold finished” — **falsified**.

---

## 8. Verdict

### **accept-with-gaps**

Unstamp residual is **closed at Confirmed** via `read_memory` (no `disassemble_bytes`). Package is not complete (runtime/diff). Decompiler must not be trusted for list-op `this` without the `LEA ECX,[EDI+0x2C]` bytes.

### Stronger-verdict bar (complete)

1. CE: place known footprint → RemoveItem full → cell array empty at sealed indices; list Contains false.
2. CE: stack peel remain&gt;0 → cells still hold COID; GetQty reduced.
3. Optional differential vs AutoCore multi-cell clear on remove.

---

## 9. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Full footprint cleared on full remove | **Holds** (bytes) |
| 2 | Peel leaves occupancy | **Holds** (CF) |
| 3 | Index matches Place | **Holds Confirmed** |
| 4 | 8-byte empty cells | **Holds** |
| 5 | Type-4 clears cells | **Falsified** |
| 6 | List this = grid root | **Falsified** |
| 7 | Bit-exact complete | **Fail** |
| 8 | Dual quality (scaffold era) | **Superseded** |

**Final verdict: `accept-with-gaps`**
