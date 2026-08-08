# Review A (reconstruction fidelity): `aa_005718a0` InventoryGrid_SetOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005718a0` |
| **VA** | `0x005718a0` |
| **Canonical name** | `InventoryGrid_SetOwner_Inferred` |
| **Review date** | `2026-08-04` (WQ8R-A dual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_005718a0_InventoryGrid_SetOwner_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## 1. Purpose

InventoryGrid **vtbl+0x18** method: write owner object* to **`grid+0x24`**, walk the embedded item list under TraversalLock, call each item **vtbl+0x158(owner)** to rebind occupants, then unlock the list critical section.

Does **not** place items, stamp cells, or set `grid+0x4` owner flag (that is `InventoryGrid_SetOwnerFlag_Inferred` @ `0x00570600`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005718a0` (2026-08-04) — **bit-identical** to 2026-07-23 raw body |
| Live meta | `analyze_function_complete`, `get_function_by_address`, `get_xrefs_to`, `get_function_callees`, `read_memory` |
| Raw | `docs/reconstruction/raw/aa_005718a0_FUN_005718a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005718a0_FUN_005718a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_SetOwner_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005718a0.cpp` |
| Function records | `aa_005718a0_FUN_005718a0.md`, `aa_005718a0_InventoryGrid_SetOwner_Inferred.md` |
| Cross | `A_aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount` (vfunc+0x18 bind) |
| Cross | `InventoryGrid_MergeStackQty` owner dirty via `+0x24` |
| Scratch | `docs/reconstruction/tmp/a_005718a0.md` |

**Not performed:** `disassemble_bytes`, Launcher, runtime pack tests, bit-exact diff.

---

## 3. Sealed facts

| # | Fact | Evidence |
|---|------|----------|
| 1 | Body `0x005718a0`–`0x00571911` (`0x72` B) | `get_function_by_address` |
| 2 | `__thiscall`, `RET 4` | epilogue `c2 04 00` via `read_memory` |
| 3 | `*(grid+0x24) = owner` first | decompile store; cargo create dual |
| 4 | List at `grid+0x2c` | prologue `LEA ESI,[EDI+0x2c]` |
| 5 | Unlock `+0x54` / `LeaveCriticalSection(+0x30)` | decompile; list+0x28 / list+4 |
| 6 | Per-item `vtbl+0x158(*(grid+0x24))` | decompile loop |
| 7 | Sole xref DATA `0x009d33a8` = vtbl+0x18 | `get_xrefs_to` + `read_memory` dword |
| 8 | Callees: `004294f0`, `004022a0`, `LeaveCriticalSection` | `get_function_callees` |
| 9 | Live decompile ≡ raw body | byte compare of pseudocode |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Store owner @ +0x24 | **Yes** |
| BeginTraversal on list | **Yes** |
| while Next==0: item vfunc+0x158(owner) | **Yes** |
| Unlock if flag | **Yes** |
| No place / no flag+0x4 | **Yes** |
| Separate clean cursor vs Ghidra stack reuse | **Semantic Yes** (store-before-walk sealed; see B) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High / Sealed** | decompile + RET bytes |
| vtbl+0x18 | **High / Sealed** | DATA xref + dword |
| `+0x24` owner pointer | **High / Sealed** | multi-unit cross-seal |
| Item rebind +0x158 | **High** CF; product name **Open** | |
| Name `SetOwner` English | **Inferred** | no string; role from stores + cargo |
| Runtime Confirmed | **Open** | Terminal false |

---

## 6. Gaps

1. Product / PDB symbol.
2. Exact type of owner object (vehicle MI-adjust vs character vs abstract).
3. Item vfunc `+0x158` product name.
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
