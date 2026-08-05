# Review A (reconstruction fidelity): `aa_00572360` InventoryGrid_RePlaceItems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572360` |
| **VA** | `0x00572360` |
| **Body** | `0x00572360`–`0x00572595` |
| **Canonical name** | `InventoryGrid_RePlaceItems_Inferred` |
| **Ghidra symbol** | `FUN_00572360` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B — W21-B) |
| **Counterpart** | `reviews/B_aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| **System** | inventory-transfer |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Re-place / commit inventory items** on `InventoryGrid* this`:

1. `relatedPtr == null` → **0** (byte-sealed).
2. Enumerate items (`FUN_004294f0` / `FUN_004022a0` on `this+0x2c`).
3. Per item: origins via vfuncs `+0x250/+0x254`; type ≠ 4 → CanPlace; on miss FindFree page **`-1`**; PlaceItemFootprint (`+0x25c` pack arg).
4. Fail → `FUN_00571e10`, leave CS if `+0x54`, **return 0**.
5. Success → leave CS; optional `FUN_00571e10` if flag; free/reinit RB `+0x60` / count `+0x64=0`; if `!flag` → `FUN_004bc580` + `AllocateCellArray`; **return 1**.

**Calling convention:** MSVC `__thiscall`. Stack: related pointer, flag. **`RET 8`**.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_00572360_FUN_00572360.md` | W21-B append + entry/exit bytes |
| Annotated | `raw/aa_00572360_FUN_00572360.annotated.md` | Sealed |
| Clean named | `reconstructed-exact/InventoryGrid_RePlaceItems_Inferred.cpp` | New sealed |
| Clean scaffold | `reconstructed-exact/FUN_00572360.cpp` | Replaced (no bare undefined4) |
| Function records | `functions/aa_00572360_*` | Updated |
| Live decompile | Ghidra `0x00572360` | ≡ 2026-07-23 raw |
| Entry bytes | `read_memory` 256 B | null gate + ret 8 |
| Exit bytes | `read_memory` @ success/fail | AL 0/1 + ret 8 |
| Xrefs | complete | SortAndRepack, cargo×3, wrapper |
| Sealed callees | Place / FindFree / CanPlace / AllocCell | prior duals |

**Not performed:** `disassemble_bytes`, Launcher, live inventory golden, bit-exact package.

---

## 3. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Null related → 0 / ret 8 | **Yes** (bytes) |
| Walk begin `004294f0` / `004022a0` | **Yes** |
| Origin vfuncs + type-4 skip CanPlace/FindFree | **Yes** |
| CanPlace → else FindFree page `-1` | **Yes** |
| Place `00571620`; fail → 571e10 + leave CS → 0 | **Yes** |
| Success leave CS; flag→571e10; RB reinit | **Yes** |
| `!flag` → 004bc580 + AllocCell → 1 | **Yes** |
| `ret 8` both exits | **Yes** |

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ABI / ret 8 / returns 0\|1 | **High** | entry + exit bytes |
| Null related gate | **High** | |
| Inventory place family roles | **High** | sealed callees |
| Type-4 special path | **High** | shared with SortAndRepack |
| FindFree page `-1` | **High** | body + prior dual |
| Product English name | **Tentative** | `_Inferred` |
| relatedPtr exact object type | **Tentative** | null-checked + 571e10 |
| Success RB empty intent | **Open** | CF sealed; product “why” residual |
| 571e10 full ABI | **Tentative** | decomp residual |
| Runtime golden | **Open** | |

---

## 5. Callers / callees

| Direction | Target | Role |
|---|---|---|
| In | `FUN_00572730` | SortAndRepack success |
| In | `FUN_005252f0` ×3 | cargo resize migration |
| In | `FUN_00521e90` | wrapper flag=1 |
| Out | CanPlace / FindFree / Place / AllocCell / RB free / 571e10 / list walk | inventory family |

---

## 6. Gaps / open (do not block accept-with-gaps)

1. Product C++ name.
2. Exact `relatedPtr` type and `FUN_00571e10` arity/ECX.
3. Product reason for emptying destination RB after successful Place loop.
4. Full ECX recovery for every thiscall helper (roles still sealed).
5. Runtime / bit-exact.

### **accept-with-gaps**
