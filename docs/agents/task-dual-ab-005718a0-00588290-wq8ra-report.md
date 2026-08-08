# Dual A/B report — WQ8R-A OWN `aa_005718a0` + `aa_00588290`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-A  
**Scope:** VAs `0x005718a0`, `0x00588290` only. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq008_residual_partition_map.md`  
**Work item:** WQ-008 inventory residual (priority 94)  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005718a0` InventoryGrid_SetOwner_Inferred | **accept-with-gaps** — CF + ABI + vtbl+0x18 + owner/+list lock sealed; product English open |
| `aa_00588290` CVOGStore_TryAddItemQty_Inferred | **accept-with-gaps** — merge-or-place CF + host+0x35c + RET 8 sealed; no merge capacity clamp (odd); type name Probable via caller RTTI |

---

## VA `0x005718a0` — sealed facts

1. **Body:** `0x005718a0`–`0x00571911` (`0x72` B; `RET 4`).
2. **ABI:** **ECX**=`InventoryGrid*`; stack `ownerObject*`; void-ish return (EAX undefined).
3. **Semantics:** Store owner at **`grid+0x24`**; TraversalLock walk list at **`grid+0x2c`**; each item **vtbl+0x158(owner)**; unlock **`+0x54` / LeaveCS(`+0x30`)**.
4. **Vtable:** sole xref DATA `0x009d33a8` = `PTR_FUN_009d3390` slot **`+0x18`**.
5. **Callers (code):** none direct — virtual only (cargo create path documented).
6. **Callees:** `FUN_004294f0`, `FUN_004022a0`, `LeaveCriticalSection`.
7. **Name:** `InventoryGrid_SetOwner_Inferred` (Ghidra `FUN_005718a0`; **_Inferred**).
8. **Not** `SetOwnerFlag` (`0x00570600` writes `+0x4` only).
9. **Live decompile ≡** 2026-07-23 raw body.
10. **Odd:** decompiler reuses owner stack slot as list cursor after store; clean uses separate cursor with store-before-walk sealed.

### Gaps

- Product/PDB symbol and owner object English type.  
- Item vfunc `+0x158` product name.  
- Nested list helpers dual ownership residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005718a0_InventoryGrid_SetOwner_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005718a0_InventoryGrid_SetOwner_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005718a0_FUN_005718a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005718a0_FUN_005718a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_SetOwner_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005718a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005718a0_FUN_005718a0.md` |
| Function named | `docs/reconstruction/functions/aa_005718a0_InventoryGrid_SetOwner_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005718a0.md` |

---

## VA `0x00588290` — sealed facts

1. **Body:** `0x00588290`–`0x00588440` (`0x1B1` B; `RET 8` all exits).
2. **ABI:** **ECX**=host with **`+0x35c → InventoryGrid*`** (caller path: **`CVOGStore*`**); stack `item*`, `qty`; returns **`qty` or 0**.
3. **Semantics:** Prefer in-list **CBID + IsStackEligible** merge (add qty, **no** max-stack clamp); else SetQty absolute, **`item+0x17c |= 0x10`**, dirty, FindFree (2×2 if both InvSize 0 else FindFreeForItem stack+whole-grid), PlaceItemFootprint.
4. **Sole code caller:** `FUN_00588450` @ `0x00588489` (RTTI cast to `CVOGStore`, then GetQty → this).
5. **Callees:** list lock pair, `00513e70`, `00512670`, `005713a0`, `005714e0`, `00571620`, LeaveCriticalSection.
6. **Name:** `CVOGStore_TryAddItemQty_Inferred` (Ghidra `FUN_00588290`; **_Inferred**).
7. **Odd (preserve):** unbounded merge add; decompiler `unaff_EBX`/`unaff_retaddr` = FindFree **outX/outY**.
8. **Live decompile ≡** 2026-07-23 raw body.
9. **Cross-seals:** FindFree residual caller table; Place / IsStackEligible duals.

### Gaps

- Product method symbol; field English for `+0x35c` and flag `0x10`.  
- Whether non-store hosts share layout (only store caller observed).  
- Caller chain `00588450` / `00513200` not owned here.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00588290_FUN_00588290.md` |
| Annotated | `docs/reconstruction/raw/aa_00588290_FUN_00588290.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGStore_TryAddItemQty_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00588290.cpp` |
| Function | `docs/reconstruction/functions/aa_00588290_FUN_00588290.md` |
| Function named | `docs/reconstruction/functions/aa_00588290_CVOGStore_TryAddItemQty_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00588290.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005718a0` | Cargo/grid owner bind must set `OwnerObject (+0x24)` **and** rebind list items (`vtbl+0x158`); separate from OwnerFlag `+0x4`. |
| `00588290` | Store deposit: stack-merge **without** client max-stack clamp on this path; free path sets qty then places; InvSize (0,0) uses 2×2 free search; return value is **qty**, not bool. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Clean uses meaningful names (not Ghidra iVar paste); odd behaviors preserved and noted.  
- This report: `docs/agents/task-dual-ab-005718a0-00588290-wq8ra-report.md`
