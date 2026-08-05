# Reconstruction review: `aa_005713a0` InventoryGrid_FindFreeSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **VA** | `0x005713a0` |
| **Canonical name** | `InventoryGrid_FindFreeSlot` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `raw/aa_005713a0_InventoryGrid_FindFreeSlot.md` | Authoritative decompile (`FUN_005713a0`) |
| Annotated | `…annotated.md` | Scaffold copy |
| Exact C++ | `reconstructed-exact/InventoryGrid_FindFreeSlot.cpp` | Clean surface |
| Function record | `functions/aa_005713a0_….md` | Status |
| Related | AllocateCellArray; PlaceItemFootprint; system map | Layout / first-fit narrative |

**Primary claims under review:**

1. Null out-params → return 0
2. If either footprint dim is 0 → write `(0,0)` and return 1 (degenerate success)
3. Page filter: `param_6 == -1` scans full height; else restricts to page band using `grid+0x1c`
4. Nested scan: outer Y (`bVar2`), inner X (`bVar6`); first-fit
5. Cell free test: `(lo & hi) == 0xFFFFFFFF` on 8-byte cell at `grid+0x28`
6. Full footprint validation via `FUN_00570840`; on success write X/Y out-params, return 1
7. Exhausted → return 0

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | CF ground truth |
| Clean C++ | reconstructed-exact | Fidelity |
| Allocate unit | aa_00570720 | `+8/+0xc` dims, cells `+0x28` |
| System map | inventory-transfer | “First-fit free rect” claim |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null out-param guard | **Yes** |
| Zero-dim early success (0,0) | **Yes** |
| Page -1 vs page band Y range | **Yes** |
| Outer Y / inner X loops | **Yes** |
| Free test AND of both cell dwords == -1 | **Yes** |
| CanPlace then write outs | **Yes** |
| Fail return 0 | **Yes** |

### 3.2 Free-cell predicate

```c
(*(uint *)(cells + i*8) & *(uint *)(cells + 4 + i*8)) == 0xffffffff
```

Preserved exactly in clean. Compatible with allocate filling both halves with `0xFFFFFFFF` (AND remains -1 only if both empty).

### 3.3 Naming

Clean still exports `FUN_005713a0` while file uses canonical name — scaffold-consistent.

### 3.4 Function record honesty

Partial scaffold — OK.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `extraout_ECX` reassigns `param_1` after CanPlace | Medium | Decompiler artifact; clean keeps it (fidelity). May be thiscall ECX restore of grid pointer |
| Index `*(g+0xc)*x + y` | Layout | Needs unified width/height labeling with place/allocate |
| `local_c` used as X packed into CanPlace third arg | OK if CanPlace expects x in low byte | Document when refining |
| Zero-dim returns success | Behavioral | Matches raw; may surprise ports that expect fail |

**No clean-vs-raw fidelity revision required.**

---

## 5. What remains uncertain

1. Grid field labels: is `+8` width and `+0xc` height (system narrative) given index `height*x+y`?
2. `param_6` page semantics beyond band math.
3. CanPlace (`FUN_00570840`) full contract / 5th arg 0.
4. Whether first-fit order is Y-major then X (as coded) in all UI paths.
5. Runtime verification.
6. Live re-decompile not done.

---

## 6. Verdict

### **accept-with-gaps**

Clean is a faithful scaffold of a relatively clear first-fit search. Gaps are layout naming, CanPlace contract, and runtime — not fidelity failures.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Free test preserved | **Pass** |
| Page filter preserved | **Pass** |
| First-fit order preserved | **Pass** |
| Layout labels sealed | **Open** |
| Verdict | **accept-with-gaps** |
