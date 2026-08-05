# Reconstruction review: `aa_00570720` InventoryGrid_AllocateCellArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **VA** | `0x00570720` |
| **Canonical name** | `InventoryGrid_AllocateCellArray_Inferred` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `raw/aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` | Authoritative decompile + plate algorithm |
| Annotated | `…annotated.md` | Named locals / plate |
| Exact C++ | `reconstructed-exact/InventoryGrid_AllocateCellArray_Inferred.cpp` | Clean surface |
| Function record | `functions/aa_00570720_….md` | Status |
| Caller context | `InventoryGrid_ctor_Inferred` raw/clean | Calls this after dim clamp |
| System / wire RE | inventory-transfer; inventory-cargo-wire-re | empty=-1, 8-byte cells |

**Primary claims under review:**

1. Fastcall `this` = grid in ECX (`pGrid`)
2. Delete prior `cells` at `+0x28` if non-null
3. `nTotal = *(+8) * *(+0xc)` → store `+0x10`; clear `+0x28` temp null
4. Derive page-ish dims into `+0x1c` and `+0x18` via integer divisions
5. `operator_new(nTotal * 8)`; store pointer at `+0x28`
6. Fill with `0xFFFFFFFF` dwords (`nTotal*8/4` iterations)
7. Residual byte loop is dead (`for (nTotalCells=0; nTotalCells!=0; …)`)

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw + plate | Raw capture | Algorithm |
| Clean C++ | reconstructed-exact | Fidelity |
| ctor caller | InventoryGrid_ctor_Inferred | Preconditions (dims ≥ 1) |
| Find/Place units | free/place | Consumers of empty cells |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw ≡ annotated

| Stage | Match |
|---|---|
| Conditional delete old array | **Yes** |
| Total cells product | **Yes** |
| Zero pointer then set counts | **Yes** |
| Page dim divisions | **Yes** |
| new + assign `+0x28` | **Yes** |
| Dword fill -1 | **Yes** |
| Dead residual byte loop | **Yes** (preserved) |

### 3.2 Empty encoding

Each cell 8 bytes of `0xFF` via dword stores → both COID halves empty. Matches FindFree free test and wire-RE narrative.

### 3.3 Naming honesty

Canonical name includes `_Inferred` — plate and record acknowledge non-sealed original symbol. Clean keeps that name.

### 3.4 Function record honesty

Partial scaffold — OK even though body is small/clear.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Dead residual loop | Cosmetic | MSVC memset residual pattern with count always multiple of 4; clean correctly keeps it |
| Division by `*(+0x14)` and `*(+8)` / `*(+0xc)` | Safety | No zero checks in body; ctor may guarantee ≥1 — not proven in this unit alone |
| `+0x18/+0x1c` semantic labels (“page dims”) | Doc | Plate inference; clean does not invent stronger types |
| `operator_new__` / `operator_delete__` names | Scaffold | Unresolved CRT wrappers |

**No fidelity revision required.**

---

## 5. What remains uncertain

1. Original retail symbol name (inferred).
2. Exact meaning of `+0x14` divisor and resulting `+0x18/+0x1c` (pages vs UI strips).
3. Whether `+8`/`+0xc` are width/height in UI order (see FindFree index tension).
4. OOM behavior of `operator_new__` (throw vs null).
5. Runtime size for cargo 6×(13*pages).
6. Live re-decompile not done.

---

## 6. Verdict

### **accept-with-gaps**

Among the seven units, this is the **clearest** body: clean matches raw, algorithm is short, empty fill is explicit. Gaps are naming inference, page-dim semantics, and division preconditions — not clean/raw drift.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| 8-byte cells filled with -1 | **Pass** |
| Free old array preserved | **Pass** |
| Dead residual loop preserved | **Pass** |
| Name / page-dim semantics sealed | **Open** |
| Verdict | **accept-with-gaps** |
