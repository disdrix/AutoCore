# Review A (reconstruction fidelity): `aa_00572730` InventoryGrid_SortAndRepack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572730` |
| **VA** | `0x00572730` |
| **Canonical name** | `InventoryGrid_SortAndRepack_Inferred` |
| **Review date** | `2026-07-29` (W20-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw CF) |
| **Counterpart** | `reviews/B_aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Comparator-driven inventory sort / repack.** For an `InventoryGrid* this`:

1. Reject adjusted-null `this == 0xFFFFFFD4` → **0**.
2. Allocate temp grid (`operator_new(0x68)` + `InventoryGrid_ctor_Inferred` with this `+0x08/+0x0c/+0x14`).
3. Init stack locked list (vtbl + CS + count).
4. Empty this item RB at `+0x60` (`FUN_005731c0` left subtree; reinit sentinel; `+0x64 = 0`).
5. Drain/collect items into working list (`FUN_004294f0` / `FUN_004022a0` / `FUN_00566f00`).
6. While items remain: pick **best** via `compareFn(ctx, cand, best)` (non-zero → prefer cand); place type-4 at (0,0) else `FindFreeSlot(..., page=-1)` then `PlaceItemFootprint`; on FindFree miss set fail.
7. Fail → `FUN_00571e10(0,0)`, destroy temp, **return 0**.
8. Success → realloc cells on **this**, `FUN_00572360`, destroy temp, **return 1**.

**Calling convention:** MSVC `__thiscall` — grid in `ECX`. Stack: compare function pointer, context. **`RET 8`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw + W20-S append | `docs/reconstruction/raw/aa_00572730_FUN_00572730.md` |
| Annotated | `docs/reconstruction/raw/aa_00572730_FUN_00572730.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_SortAndRepack_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00572730.cpp` |
| Function record | `docs/reconstruction/functions/aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x00572730` — **≡ 2026-07-23 raw** |
| Entry bytes | `read_memory` 64 B @ `0x00572730` — SEH, `lea esi,[edi+0x2c]`, `ret 8` |
| Xrefs | `get_function_xrefs` → `FUN_00572ed0`, `FUN_00572ef0` only |
| Sealed callees | FindFree `aa_005713a0`, Place `aa_00571620` (prior duals) |
| Prior note | `reviews/a_005713a0.md` caller table: “Sort/repack into temp grid” |

**Not performed:** `disassemble_bytes`, Launcher, live inventory sort golden, bit-exact package.

---

## 3. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Adjusted-null → 0 | **Yes** (bytes + decomp) |
| Temp `new(0x68)` + ctor dims | **Yes** |
| Stack list + CS init | **Yes** |
| RB free + empty reinit + count 0 | **Yes** |
| Drain loop `004294f0`/`004022a0`/`00566f00` | **Yes** |
| Leave this CS if `+0x54` | **Yes** |
| Selection best under `param_2` | **Yes** |
| Type 4 → (0,0); else FindFree page `-1` | **Yes** |
| Place via `00571620`; fail flag | **Yes** |
| Fail path destroy temp → 0 | **Yes** |
| Success AllocCell + `00572360` + destroy temp → 1 | **Yes** |
| `ret 8` | **Yes** |

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ABI / ret 8 / returns 0|1 | **High** | bytes |
| Temp grid same dims | **High** | ctor args |
| RB clear at +0x60/+0x64 | **High** | body |
| Comparator selection loop | **High** | body |
| FindFree page `-1` + type-4 (0,0) | **High** | body; matches sealed FindFree callers |
| Place / alloc sealed callees | **High** | prior duals |
| Product English name | **Tentative** | `_Inferred` |
| Which object is place/FindFree `this` | **Tentative** | decomp ECX residual; role says temp |
| `FUN_00572360` 2nd arg | **Tentative** | decomp `0` vs callee null guard |
| Fail restore `FUN_00571e10` | **Open** | not owned |
| Runtime golden | **Open** | |

---

## 5. Gaps / open (do not block accept-with-gaps)

1. Product C++ name.
2. Full ECX recovery for list/grid helpers.
3. Exact commit path source list into `FUN_00572360`.
4. Fail-restore semantics of `FUN_00571e10`.
5. Dual of wrappers `00572ed0` / `00572ef0` / comparator bodies (not OWN).
6. Runtime / bit-exact.

### **accept-with-gaps**

CF role, ABI, temp-grid sort/repack architecture, and sealed inventory callees are solid. Residuals are decompiler this/arg and unowned fail-restore — documented, not overclaimed.

---

## 6. AutoCore impact

Ports that implement client-side inventory “sort” must:

- Use a **temp** same-size grid for FindFree/Place during ordering.
- Honor type **4** fixed origin (0,0).
- Pass whole-grid FindFree (`pageIndex = -1`).
- Treat comparator as external policy (wrappers supply type/size order).
- Not assume in-place cell swaps without clearing the item tree first.
