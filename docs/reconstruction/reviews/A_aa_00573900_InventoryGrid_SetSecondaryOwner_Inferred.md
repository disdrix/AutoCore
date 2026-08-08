# Review A (reconstruction fidelity): `aa_00573900` InventoryGrid_SetSecondaryOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573900` |
| **VA** | `0x00573900`–`0x00573909` inclusive (**10 B** / `0x0A`) |
| **Canonical name** | `InventoryGrid_SetSecondaryOwner_Inferred` |
| **Ghidra name** | `FUN_00573900` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY **MEGA-092**) |
| **Counterpart** | `reviews/B_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md` |
| **System** | inventory-transfer / InventoryGrid vtbl+0x14 / `PTR_FUN_009d3390` |
| **Evidence pass** | Live Ghidra `create_function` + `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_xrefs_to` / `get_function_xrefs` / `get_function_callers` + `read_memory` (body + vtbl). **No** `disassemble_bytes`. **No** Launcher. |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## 1. Purpose

InventoryGrid **vtbl+0x14** leaf setter: write stack argument to **`grid+0x58`** and return. Secondary owner / character link bind used by cargo create after primary SetOwner.

Does **not** write `grid+0x4` (owner flag), does **not** write `grid+0x24` (primary owner), does **not** walk or rebind the item list.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00573900` (2026-08-05) after `create_function` |
| Live meta | `analyze_function_complete`, `disassemble_function`, callers/xrefs, `read_memory` |
| Raw (+ MEGA-092 re-verify) | `docs/reconstruction/raw/aa_00573900_FUN_00573900.md` |
| Annotated | `docs/reconstruction/raw/aa_00573900_FUN_00573900.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_SetSecondaryOwner_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573900.cpp` |
| Function records | `aa_00573900_FUN_00573900.md`, `aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md` |
| Parent dual | `A_aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount` (vfunc+0x14 → +0x58) |
| Peer setters | `InventoryGrid_SetOwner_Inferred` `0x005718a0`; `SetOwnerFlag` `0x00570600` |
| Adjacent | `InventoryGrid_ScalarDeletingDtor` `0x00573910` (vtbl[0]) |

**Not performed:** `disassemble_bytes`, Launcher, runtime pack tests, bit-exact diff.

---

## 3. Sealed facts

| # | Fact | Evidence |
|---|------|----------|
| 1 | Body `0x00573900`–`0x00573909` (**10 B**) | `get_function_by_address` after create; hex length |
| 2 | `__thiscall`, stack arg, **`RET 4`** | disasm `MOV EAX,[ESP+4]` / `MOV [ECX+0x58],EAX` / `RET 0x4` |
| 3 | `*(this+0x58) = arg` only | decompile + 10 B hex `8b442404894158c20400` |
| 4 | Leaf (no callees) | `analyze_function_complete` callees `[]` |
| 5 | No direct CALL callers | callers empty; virtual only |
| 6 | Sole xref DATA `0x009d33a4` | `get_xrefs_to` / `get_function_xrefs` |
| 7 | Vtbl dword = this VA | `read_memory` @ `0x009d33a4` → `0x00573900`; base `0x009d3390` + **0x14** |
| 8 | Pad `CC` then scalar dtor @ `0x00573910` | `read_memory` neighborhood |
| 9 | Clean ≡ raw ≡ live CF | single store; no extra ops |
| 10 | Cargo path uses this slot | dualed parent `0x004f3a30` vfunc+0x14 after +0x18 |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load stack arg | **Yes** |
| Store to `this+0x58` | **Yes** |
| RET 4 | **Yes** |
| No flag / no +0x24 / no list | **Yes** |
| No branches / no callees | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + body bytes | **High / Sealed** | full hex + disasm + decompile |
| vtbl+0x14 slot | **High / Sealed** | DATA xref + dword |
| `+0x58` store offset | **High / Sealed** | `89 41 58` |
| Secondary-owner English | **Inferred** | partition + parent dual; no string |
| Pointee type = character | **Probable** | cargo arg expression; type open |
| Runtime Confirmed | **Open** | Terminal false |

---

## 6. Gaps

1. Product / PDB symbol.
2. Exact type of value at `grid+0x58`.
3. Exhaustive virtual call-site inventory (static graph empty).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/vtbl/store sealed; product English + pointee type residual.
