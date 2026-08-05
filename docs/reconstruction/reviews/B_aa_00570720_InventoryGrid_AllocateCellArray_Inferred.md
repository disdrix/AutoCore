# Review B (skeptical / adversarial): `aa_00570720` InventoryGrid_AllocateCellArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present and strengthened** (A + B modern pair; supersedes thin 2026-07-23 scaffold + legacy skeptical `needs-more-evidence` package) |
| **Verdict** | **accept-with-gaps** on CF + empty encoding + page-height algebra; **reject** overclaims that this unit places items, zero-fills, uses 4-byte cells, or seals a retail symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Leaves old buffer in place | **Falsified** — deletes `+0x28` first if non-null |
| 2 | Zero-fills cells | **Falsified** — dword fill `0xFFFFFFFF` |
| 3 | 4-byte cells | **Falsified** — `nTotal * 8` alloc; two u32 COID halves |
| 4 | Places / stamps items | **Falsified** — empty buffer only; place is `0x00571620` |
| 5 | Residual byte loop matters | **Falsified** — counter forced to 0; size always multiple of 4 |
| 6 | Unit alone proves divisors ≠0 | **Overstated** — no body guards; ctor clamps ≥1; rebuild assumes prior dims |
| 7 | `+0x18` is a second independent page axis | **Weak** — algebraically equals **width** when `nTotal=w*h` and h≠0 |
| 8 | Name is sealed retail | **Fail** — `_Inferred` only |
| 9 | Wave2 dual A/B “sealed” quality | **Falsified** — scaffold-only; this dual supersedes |
| 10 | Ready for bit-exact / complete | **Fail** — runtime/diff open |
| 11 | Client cell packing is row-major | **N/A to this unit** — allocate does not index; Find/Place use `height*x+y` (column-major storage) |

---

## 2. Decisive dataflow (raw + live decompile 2026-07-29)

```
if (*(void**)(grid+0x28) != NULL)
  operator_delete(*(void**)(grid+0x28))

nTotal = *(i32*)(grid+0x08) * *(i32*)(grid+0x0c)
*(void**)(grid+0x28) = NULL
*(i32*)(grid+0x10)   = nTotal
*(i32*)(grid+0x1c)   = (nTotal / *(i32*)(grid+0x14)) / *(i32*)(grid+0x08)
*(i32*)(grid+0x18)   = nTotal / *(i32*)(grid+0x0c)

pCell = operator_new(nTotal * 8)
*(void**)(grid+0x28) = pCell

for (n = (nTotal * 8) >> 2; n != 0; --n)
  *pCell++ = 0xFFFFFFFF

for (nTotal = 0; nTotal != 0; --nTotal)   // dead
  *(u8*)pCell++ = 0xFF
```

Live body matches 2026-07-23 raw capture (no decompiler drift).

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free → recompute → new → fill -1 | **High** | Leak / stale occupancy |
| Empty sentinel both halves -1 | **High** | False free / false full in Find |
| 8-byte cells | **High** | Wrong buffer size / index*8 |
| `+0x1c` = (n/pages)/w page height | **High** CF | Wrong page window in Find/Can |
| Cargo pageH = 13 | **High** | Cargo UI / multi-page bounds |
| `+0x18` semantic beyond `n/h` | **Probable** | Misnamed “page width” if product differs |
| Div-by-zero impossible | **Probable** (ctor) | Crash on corrupt grid |
| OOM after free (null window) | **Open** | UAF if callers assume non-null mid-path |
| Runtime golden sizes | **Open** | Residual parity risk |
| Retail name | **Open** | Cosmetic only |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x08` as width | Invented? | **No** — product + page divisor; Find X bounds |
| `+0x0c` as height | Invented? | **No** — product + `+0x18` divisor; Find stride |
| `+0x10` total cells | Invented? | **No** — product store + fill count source |
| `+0x14` pages | Invented name? | **CF holds** as divisor; English “pages” from ctor arg plate |
| `+0x1c` page height | Invented? | **No** — algebra + Find `pageH * pageIndex` + CanPlace `%` |
| `+0x28` cell base | Invented? | **No** — free/new/fill target |
| Zero-fill empty | Compatible? | **No** — `-1` only |
| Leaves occupancy | Compatible? | **No** — always full empty; rebuild callers re-stamp |

### Algebra note

```
nTotal = w * h
pageH  = (nTotal / pages) / w   =  (h / pages)   when exact
echoW  = nTotal / h             =  w             when exact
```

Cargo ctor path: `w=6`, `h=pages*13` → `pageH=13`, `echoW=6`. Truncating integer division is retail if dims are not exact multiples.

### Legacy skeptical C1 (width×height vs index)

Allocate does **not** linearize. Storage order is sealed by Find/Place (`idx = height*x + y`). Attack that “allocate proves row-major” **fails**. Ports using `(x,y)` sets (AutoCore) are unaffected.

---

## 5. Surviving contract for AutoCore

```
On grid create / full rebuild:
  free cells if any
  totalCells = width * height
  pageHeight = (totalCells / pages) / width   // cargo → 13
  cells = new u32[totalCells * 2]             // 8 bytes/cell
  fill every dword 0xFFFFFFFF

Never treat this unit as place/find.
Re-stamp after rebuild via PlaceItemFootprint.
Ctor-side: clamp width/height/pages ≥ 1 before allocate.
```

Server ports that only track `HashSet<(x,y)>` need not allocate a client-style buffer, but **empty semantics** and **page height** must match when emulating find/can/place.

---

## 6. Caller evidence

| Caller | Path shape |
|--------|------------|
| `InventoryGrid_ctor_Inferred` (`0x00572650`) | Clamp ≥1 → allocate (first empty grid) |
| `FUN_00570f50` | Clear helper → allocate (thin re-empty) |
| `FUN_00570f70` | Tear down items → leave CS → clear → allocate |
| `FUN_00572360` | Tree clear + allocate when rebuild flag requires empty buffer |
| `FUN_00572730` | Scratch-grid fail path allocate; live-grid success path allocate before re-place |

All observed call sites treat allocate as **reset occupancy to empty**, not as preserve-content resize.

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Runtime: cargo 6×(13*pages) nTotal + pageH after create | **Yes** for bit-exact / complete |
| R2 | OOM / throw of `operator_new__` | Mild |
| R3 | Retail symbol | Mild |
| R4 | Non-cargo grids with exotic page factors | Mild if layout shared |
| R5 | `FUN_004bc580` exact clear semantics | No for this unit CF |

---

## 8. Concrete checks performed

1. Live re-decompile of `0x00570720` — matches raw.
2. Re-derived fill count `(n*8)>>2` dword stores of -1.
3. Confirmed residual loop dead (counter=0).
4. Cross-checked empty pattern with FindFreeSlot free predicate `(lo&hi)==-1`.
5. Algebra: cargo pages → pageH 13.
6. Ctor clamp cross-check (pages/width/height ≥1).
7. Sampled five caller VAs via Ghidra xrefs/callers.
8. Compared clean to raw (no fidelity rewrite needed).
9. Attacked wave2 dual quality (scaffold-only) — **replaced**.
10. Upgraded legacy package-level `needs-more-evidence` for **mechanical CF** while keeping layout-name honesty.

---

## 9. Verdict

### **accept-with-gaps**

Mechanical allocate+fill is strong and re-sealed. Page-height algebra is sealed against Find/Can consumers. Remaining gaps are runtime goldens, OOM, and retail naming — not body contradictions. Legacy “needs-more-evidence” on the **full interpretation package** is narrowed: width/height/pageH labels now hold via the place/find/can/alloc family dual work (2026-07-29); name remains inferred.

### Stronger-verdict bar (complete)

1. Runtime: cargo create → observe `+0x10`, `+0x1c=13`, `+0x28` non-null, first cells `-1`.
2. Optional: original name from RTTI/strings if any.
3. Document OOM policy for ports (null vs throw).

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Role allocate empty cells | **Holds (name inferred)** |
| 2 | Empty -1 / 8-byte | **Holds** |
| 3 | width×height product | **Holds** |
| 4 | Page height formula | **Holds** (CF + cargo 13) |
| 5 | Residual loop | **Dead** |
| 6 | Places items / preserves occupancy | **Falsified** |
| 7 | Finished modern API / bit-exact | **Fail** |
| 8 | Wave2 dual quality | **Superseded** |

**Final verdict: `accept-with-gaps`**
