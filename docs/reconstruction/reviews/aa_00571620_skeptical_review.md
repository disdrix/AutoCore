# Skeptical / adversarial review: `InventoryGrid_PlaceItemFootprint` @ `0x00571620`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Multi-cell place / footprint stamp unit |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

Raw/annotated/clean for `aa_00571620`; FindFreeSlot + AllocateCellArray for cell layout; DropResponse callers of `FUN_00571620`; system map; inventory-cargo-wire-re multi-cell claim.

**Not performed:** asm of stamp loop, CE fill of cells, re-decompile with better types.

---

## 2. Evidence used

Raw alone:

1. Rejects some item types; special-cases type 4.
2. Loads footprint dims from item clonebase-linked struct `+0x406/+0x407`.
3. Calls `FUN_00570840` before mutating grid.
4. Contains a nested loop that writes two dwords per cell into `*(grid+0x28)`.
5. Sets an item flag bit `0x10` on success.

Wire RE claims: “stamps item COID into **every** footprint cell.”

---

## 3. Attack results

### Claim 1 — Function stamps COID into every footprint cell

| Sub-claim | Result |
|-----------|--------|
| Loop writes multiple cells when outer counter ≠ 0 | **Directionally holds** if `unaff_SI` is height/width count. |
| `unaff_SI` is footprint height (or width) | **UNPROVEN.** Unaff = decompiler failed to find source. Could be wrong bound. |
| Index math is correct rect coverage | **ATTACKED.** Expression uses `*(grid+0xc) * (local_c + iVar4) + iVar5 + bStack_8` with `local_c` also the footprint dim — **high risk of decompiler corruption**. |
| Every cell of InvSizeX×InvSizeY gets same COID | **Intended by project narrative; not sealed by clean math.** |

**Severity:** Critical for AutoCore occupancy parity.

### Claim 2 — Empty/occupied model matches allocate (-1 halves)

| Sub-claim | Result |
|-----------|--------|
| Writes both dwords of 8-byte cell | **Holds.** |
| Values are item COID lo/hi from `param_2[0x58]/[0x59]` | **Probable** (consistent with object TFID layout elsewhere). |
| Matches FindFree empty test `(lo & hi)==-1` | **Compatible** — after place, AND of halves unlikely -1 if COID real. Not a formal proof of field identity. |

### Claim 3 — Name `InventoryGrid_PlaceItemFootprint` is accurate

| Sub-claim | Result |
|-----------|--------|
| Does placement-related work on a grid object | **Holds.** |
| Only stamps footprint | **Incomplete.** Also vcalls item setup, possible render scale, flag set, helpers — more than pure stamp. |
| Ghidra name still `FUN_00571620` | Clean retains FUN name — good honesty. |

### Claim 4 — CanPlace is authoritative gate

| Sub-claim | Result |
|-----------|--------|
| `FUN_00570840` fail → return 0 before stamp | **Holds.** |
| Same CanPlace as FindFreeSlot | **Probable** (same address). Argument order differences need seal. |

### Claim 5 — Class reject list semantics

| Sub-claim | Result |
|-----------|--------|
| Six class ids return 0 | **Holds.** |
| Known retail names for 0x12/14/… | **None in unit pack.** |

### Claim 6 — Clean ≡ retail

| Sub-claim | Result |
|-----------|--------|
| Clean ≡ raw decompile | **Yes.** |
| Raw decompile ≡ correct retail stamp | **NOT SEALED** — unaff vars + suspicious index. |

### Claim 7 — DropResponse proves place works

DropResponse **calls** this function; that proves linkage, not loop correctness.

---

## 4. Alternate interpretations

### Minimal safe reading

```
bool place(Grid* g, Item* it, /*x,y,?*/) {
  if (forbidden_type(it)) return false;
  if (special_type4(it)) { attach_only(); return true; }
  dims = inv_size(it); maybe clamp for store grids;
  if (!can_place(...)) return false;
  setup_item(...);
  // INTENDED: for each cell in footprint: cells[idx] = it->coid;
  // ACTUAL DECOMPILE: loop with unaff_SI / bStack_8 / odd index — trust carefully
  mark_item_in_inventory_flag(it);
  return true;
}
```

### Competing index conventions

From FindFreeSlot: `index = *(g+0xc) * x + y` with `+0xc` used as Y-dimension in range math → suggests **column-major** or mislabeled width/height. Place must use the **same** convention; current place formula may not even match FindFree’s form.

---

## 5. Confirmed despite skepticism

1. Multi-step place with can-place gate.
2. Footprint dims sourced at `+0x406/+0x407`.
3. 8-byte cell stores of two dwords from item.
4. Clean did not invent a prettier loop over the decompile.
5. Class-4 bypass path exists.

---

## 6. Critical contradictions / risks

### C1 — Project “every footprint cell” vs unaff loop

Narrative is strong; decompile binding is weak. **Risk of false confidence in port.**

### C2 — Place index formula vs FindFree index formula

FindFree: `height * x + y` (as labeled). Place: `height * (footprintDim + row) + col + bStack_8`. **Not obviously the same addressing scheme.** Either place decompile is wrong, or place uses different origin encoding — must resolve.

### C3 — Status “High” multi-cell place in system map vs Partial scaffold unit

System confidence may outrun unit seal quality.

**Not a clean-vs-raw contradiction.**

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | unaff_SI / bStack_8 / retaddr binding | **Yes** |
| R2 | Index formula correctness | **Yes** |
| R3 | Width vs height field labels on grid | **Yes** |
| R4 | Runtime cell dump after place | **Yes** |
| R5 | Rejected class id names | Mild |

---

## 8. Concrete checks performed

1. Compared stamp loop to allocate cell size (8).
2. Compared empty test in FindFree to written COID pairs.
3. Traced DropResponse call args (X/Y/size vfunc) into this prototype.
4. Flagged unaff_* as non-parameters.
5. Algebraically compared place index vs find index forms — mismatch risk recorded.
6. Confirmed clean does not silently modernize loop.
7. Audited system-map “High” vs unit Partial scaffold tension.

---

## 9. Verdict

### **`needs-more-evidence`**

Directionally correct multi-cell place story, but the **core stamp loop is not sealed** at register/parameter level. Accepting the package as production algorithm would launder decompiler gaps.

**Why not critical-contradiction:** No proof the loop is definitely wrong in retail — only that the decompile is inadequate to certify it.

### Stronger-verdict bar

1. Asm or re-typed decompile of stamp loop (bind SI / origins).
2. CE: place 2×3 item → observe six cells same COID at expected indices.
3. Unify index convention with FindFreeSlot under one layout note.
4. Demote system-map confidence until R1–R2 closed **or** keep High only for “intent” not “formula”.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Every footprint cell stamped | **Intent Probable; formula unsealed** |
| 2 | 8-byte COID cells | **Holds** |
| 3 | Name complete | **Partial (more than stamp)** |
| 4 | CanPlace gate | **Holds** |
| 5 | Class rejects named | **Fail** |
| 6 | Clean ≡ retail algorithm | **Fail seal** |

**Final verdict: `needs-more-evidence`**
