# Skeptical / adversarial review: `InventoryGrid_AllocateCellArray_Inferred` @ `0x00570720`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Grid cell array allocation / empty fill |
| **Verdict** | **needs-more-evidence** |

*(Mechanical body is strong; verdict reflects incomplete layout semantics and inferred naming — not a CF collapse.)*

---

## 1. What was inspected

Raw/annotated/clean/function record; ctor caller; FindFreeSlot/Place consumers; system map; wire RE; vehicle cargo page notes.

**Not performed:** asm, allocator behavior, live heap dump of grid.

---

## 2. Evidence used

Raw alone:

1. Frees old `+0x28`.
2. `n = dimA * dimB` from `+8` and `+0xc`.
3. Writes `n` to `+0x10`.
4. Computes two derived ints into `+0x1c` and `+0x18`.
5. Allocates `n*8` bytes; fills with `0xFFFFFFFF` dwords.

---

## 3. Attack results

### Claim 1 — Name / role is InventoryGrid cell allocator

| Sub-claim | Result |
|-----------|--------|
| Operates on object with cell pointer `+0x28` | **Holds.** |
| Retail name | **Inferred only** — suffix admits it. |
| Only allocates cells | **Mostly** — also derives page dims; name understates side fields. |

### Claim 2 — Empty cells are `0xFFFFFFFF` halves

| Sub-claim | Result |
|-----------|--------|
| Dword fill -1 across `n*8` bytes | **Holds.** |
| Two -1 dwords per cell | **Holds** (8 bytes / 4 = 2 dwords per cell). |
| Matches FindFree free test | **Holds.** |

### Claim 3 — `nTotal = width * height`

| Sub-claim | Result |
|-----------|--------|
| Product of `+8` and `+0xc` | **Holds.** |
| Which is width vs height | **Not sealed in this function** — labels come from plate/system narrative under attack from FindFree index order. |

### Claim 4 — Page dim formulas are well-defined

| Sub-claim | Result |
|-----------|--------|
| `+0x1c = (n / +0x14) / +8` | **CF holds.** |
| `+0x18 = n / +0xc` | **CF holds.** |
| Division by zero impossible | **Not proven here.** Depends on ctor/`+0x14` always ≥1. |
| Semantic “page height/width” | **Inferred.** |

### Claim 5 — Residual byte loop matters

| Sub-claim | Result |
|-----------|--------|
| Present in decompile | **Holds.** |
| Ever runs | **No** — counter forced to 0. Harmless. |
| Implies size not multiple of 4 | **No** — size always `n*8`. |

### Claim 6 — Safe to call anytime

| Sub-claim | Result |
|-----------|--------|
| Replaces old array | **Holds** if delete+new succeed. |
| Leaves grid consistent if new throws | **Unspecified.** |
| Zeros `+0x28` before new | **Yes** — window where pointer null if new fails/throws. |

### Claim 7 — Clean exact finished

Faithful scaffold of a simple function — closest unit to “done,” still inferred name + unsealed dim semantics.

---

## 4. Alternate interpretations

### Minimal reading

```
void alloc_cells(Grid* g) {
  delete g->cells;
  int n = g->a * g->b;
  g->cells = nullptr;
  g->n = n;
  g->d1 = (n / g->c) / g->a;
  g->d0 = n / g->b;
  g->cells = new dword[n*2]; // 8 bytes each
  memset(g->cells, 0xFF, n*8);
}
```

### Competing dim labels

Still entangled with FindFree’s `index = (+0xc)*x + y` problem. Allocate does not resolve it.

---

## 5. Confirmed despite skepticism

1. Free old, compute n, alloc n*8, fill -1.
2. Writes `+0x10`, `+0x18`, `+0x1c`, `+0x28`.
3. Dead residual loop.
4. Clean ≡ raw.
5. Consumer agreement on empty encoding.

---

## 6. Critical contradictions / risks

### C1 — System “width×height” vs index convention

Allocate does not specify storage order; FindFree’s index may not match port row-major assumptions. Allocate review cannot close that gap alone, but ports that only read this unit may assume wrong linearization.

### C2 — Name confidence

`_Inferred` is honest; dropping it in ports would overclaim.

**No body CF contradiction.**

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Width/height identity | Yes for layout chapter |
| R2 | `+0x14/+0x18/+0x1c` meaning | Medium–yes |
| R3 | Allocator failure | Mild |
| R4 | Original symbol | Mild |
| R5 | Runtime sizes | Mild if ctor sealed |

---

## 8. Concrete checks performed

1. Re-derived fill count: `(n*8)>>2` dword stores of -1.
2. Confirmed residual loop dead.
3. Cross-checked empty pattern with FindFree predicate.
4. Read ctor call site for dim clamp context.
5. Compared clean to raw.
6. Attacked width/height label certainty.
7. Noted division-by-zero precondition gap.

---

## 9. Verdict

### **`needs-more-evidence`**

For **mechanical allocate+fill**, evidence is strong. For **full interpretation package** (dimension names, page fields, linearization shared with find/place), evidence is incomplete. Verdict stays `needs-more-evidence` rather than `no-critical-contradiction` to avoid sealing layout labels that FindFree challenges.

### Stronger-verdict bar

1. Unified InventoryGrid layout note sealed with find/place.
2. Confirm `+0x14` source and nonzero.
3. Optional: original name from RTTI/strings if any.
4. Runtime: cargo grid n and pointer after create.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Role allocate empty cells | **Holds (name inferred)** |
| 2 | Empty -1 / 8-byte | **Holds** |
| 3 | width×height labels | **Unsealed** |
| 4 | Page dims | **CF holds; meaning open** |
| 5 | Residual loop | **Dead** |
| 6 | Finished sealed unit | **Near for CF; not for layout package** |

**Final verdict: `needs-more-evidence`**
