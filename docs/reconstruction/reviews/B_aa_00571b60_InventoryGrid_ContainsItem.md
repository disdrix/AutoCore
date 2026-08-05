# Review B (skeptical / adversarial): `aa_00571b60` InventoryGrid_ContainsItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571b60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00571b60_InventoryGrid_ContainsItem.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI; **reject** cell-occupancy / finished-name overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function scans grid cells for COID occupancy | **Falsified** — 25 B; no cell base, no `IMUL`, no footprint loop |
| 2 | Body implements full “already at (X,Y)” | **Falsified** — only list contains; X/Y are caller vfuncs `+0x250/+0x254` |
| 3 | Decompiler signature is complete | **Falsified** — omits thiscall ECX and rewrites stack for tail |
| 4 | `FUN_00415c00()` takes no arguments | **Falsified** — `ADD ECX,0x2C` + stack item; thiscall list contains |
| 5 | Always returns full EAX truth | **Overstated** — null path only clears **AL** |
| 6 | `+0x2c` is the cell array | **Falsified** — cells are `+0x28` (Place/FindFree); `+0x2c` is list embed (Place `FUN_00566f00`) |
| 7 | Partition label “occupancy” = cell free test | **Misleading** — usage metaphor; body is membership |
| 8 | Scaffold complete / bit-exact ready | **Fail** — prior scaffold incomplete; runtime open |
| 9 | Null item path falls through to list | **Falsified** — early `RET 4` with AL=0 |
| 10 | Near call (not tail) to `00415c00` | **Falsified** — `E9` jmp tail |

---

## 2. Decisive dataflow (bytes 2026-07-29)

```
item = [ESP+4]
if item == 0:
  AL = 0
  RET 4
[ESP+4] = item          // preserve as callee stack arg
ECX = ECX + 0x2C        // list subobject
JMP FUN_00415c00        // thiscall (list, item) → AL
```

### Byte attack table

| Attack | Bytes | Result |
|--------|-------|--------|
| Two stack args? | Epilogue `C2 04 00` | **One** dword |
| Fastcall item in EDX? | Only `[ESP+4]` load | **Stack** item |
| ECX unused / static? | `83 C1 2C` | **thiscall grid** |
| Call not tail? | `E9 …` no push ret | **Tail jmp** |
| Rel target wrong? | `next=00571b79 + signed(FFEA4087)` | **0x00415c00** |
| Cell stamp present? | No `8B … 28` / `IMUL` | **Absent** |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null / RET ABI | **Confirmed** | Wrong stack cleanup → crash |
| List base +0x2c | **Confirmed** | Wrong this → false contains / AV |
| Tail to 00415c00 | **Confirmed** | Misname callee |
| Contains semantics of callee | **High** | If 00415c00 is not membership, role flips |
| Not CanPlace | **Confirmed** | Wrong server gate design |
| Product English name | **Open** | Docs only |
| Runtime membership dump | **Open** | Residual parity |
| Bit-exact complete | **Fail** | Policy |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `grid+0x2c` is cells | Compatible with Place stamp? | **No** — cells `+0x28`, 8 B COID |
| `grid+0x2c` list attach | Place ends with `LEA ECX,[EDI+0x2c]; CALL 00566f00` | **Yes** — same embed |
| Body compares X/Y | Any CMP to coords? | **No** |
| Wrapper adds quantity arg | Extra stack? | **No** — RET 4 only |
| Decompiler `FUN_00415c00()` | Accurate? | **No** — missing this/item |

---

## 5. Surviving contract for AutoCore

```
bool InventoryGrid_ContainsItem(InventoryGrid* grid, Item* item):
  if item is null: return false
  return grid.itemList.Contains(item)   // pointer equality over list at +0x2c

// Drop place gate (caller, not this unit):
if !ContainsItem(item) OR item.pos != (locX,locY):
  PlaceItemFootprint(...)
```

Server ports that only track multi-cell occupancy do **not** need this list predicate unless mirroring client “already bound to this grid” short-circuit.

---

## 6. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Live CE: insert item via place → Contains true; remove → false | Soft (High already) |
| R2 | Full `FUN_00415c00` node layout dual | No for this thin unit |
| R3 | Retail symbol name | Mild |
| R4 | Bit-exact complete | Yes for “complete” only |

---

## 7. Concrete checks performed

1. `read_memory` full 25 B body — hand-decoded opcodes.
2. Relative `JMP` target math → `0x00415c00`.
3. Compared to Place/CountItems duals for `+0x2c` list vs `+0x28` cells.
4. Re-decompile body — confirmed tooling omits this/args (bytes override).
5. DropResponse live decompile gate — Contains + pos vfuncs, not body coords.
6. Attacked “cell occupancy” partition gloss — usage only.

---

## 8. Verdict

### **accept-with-gaps**

Wrapper CF/ABI/**+0x2c** tail are **Confirmed**. Reject any claim that this unit stamps cells, runs CanPlace, or alone encodes “(X,Y) already correct.” Gaps: runtime dump, PDB name, deep list dual.

### Stronger-verdict bar (complete)

1. CE: after Place, Contains returns 1; after remove (`00571b80` path), returns 0.
2. Optional: differential AutoCore list membership if ported.

---

## 9. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Cell occupancy body | **Falsified** |
| 2 | Null → 0, RET 4 | **Holds** |
| 3 | thiscall +0x2c list | **Holds** |
| 4 | Tail List_Contains | **Holds** |
| 5 | Alone equals “at (X,Y)” | **Falsified** |
| 6 | Bit-exact complete | **Fail** |

**Final verdict: `accept-with-gaps`**
