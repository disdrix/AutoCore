# Review A (reconstruction fidelity): `aa_004f6a80` Inventory_ValidateEquipmentChange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f6a80` |
| **VA** | `0x004f6a80` |
| **Canonical name** | `Inventory_ValidateEquipmentChange_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile) |
| **Counterpart** | `reviews/B_aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md` |
| **System** | `inventory-transfer` |
| **Work item** | MEGA-056 OWN-ONLY dual |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pre-flight equipment-change validator** for inventory unequip / hardpoint-grab transfers.

Given inventory host `this` and an `item*`:

1. Null item → **8**.
2. Arena lock (`state+0xf6`) → **0xf**.
3. `InventoryGrid_FindFreeForItem(this+0x2b0, …)` fail → **2** (not enough space).
4. Dispatch on item type class `*(item+0xa8)+0x38`:
   - Match item-related TFID (`+0x164/+0x168`) against host hardpoint/container slots → **0**.
   - Type `0x10`: match + town flag → **0** or **1**.
   - Type `6` subtype `0xb`: match + hazard `+0x6b8` → **0** or **0xd**.
   - Type `0xe`: swap-required path → **1** or **0xa**.
5. Default → **8**.

Callers treat **0** as proceed; **nonzero** → `FUN_00931db0` UI string (EDI=code).

**Calling convention:** MSVC `__thiscall` — inventory in `ECX`; one stack arg (item); **`RET 4`**.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | inventory host | prologue `MOV EDI,ECX`; callers `MOV ECX,[player+0x250]` |
| stack0 | item* | prologue `MOV ESI,[ESP+0xC]`; null → 8 |
| EAX | uint32 status | all epilogues |
| cleanup | `RET 4` | every exit including early |

**Side effects:** none on success path beyond FindFreeForItem out-byte writes (discarded by callers that only test AL/EAX). No network.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_004f6a80_FUN_004f6a80.md` |
| Annotated | `docs/reconstruction/raw/aa_004f6a80_FUN_004f6a80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inventory_ValidateEquipmentChange_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004f6a80.cpp` |
| Function records | `docs/reconstruction/functions/aa_004f6a80_*.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x004f6a80` — **≡ raw body** |
| Complete analyze | `analyze_function_complete` (315 insn, 67 BB, 2 xrefs) |
| Disassembly | `disassemble_function` (all `RET 4` exits) |
| Prologue / epilogue bytes | `read_memory` @ `0x004f6a80`, `0x004f6ec8` |
| Call sites | `get_assembly_context` on `0x00862c4c`, `0x00862dd5` |
| Callers / xrefs | `get_function_callers` + `get_function_xrefs` |
| Space callee dual | `aa_005714e0` InventoryGrid_FindFreeForItem |
| UI code map | decompile `0x00931db0` (evidence only) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Null item → 8 | **Yes** |
| Arena `+0xf6` → 0xf | **Yes** |
| FindFreeForItem on `+0x2b0` fail → 2 | **Yes** (asm ECX load sealed) |
| Type 0xc / 0x1c / 0xa / 0x10 / 6 / 0xe dispatch | **Yes** |
| TFID `+0x164/+0x168` compares | **Yes** |
| Type 6 RTTI + hazard 0xd | **Yes** |
| Type 0xe + `FUN_004ce5f0` → 0xa | **Yes** |
| Default → 8 | **Yes** |
| All exits `RET 4` | **Yes** (asm) |

---

## 4. Boundary seal

| Field | Value |
|---|---|
| Start | `0x004f6a80` |
| End (inclusive) | `0x004f6ed1` |
| Size | **1106 B** / `0x452` |
| Pad | `CC×4` @ `0x004f6ed2` |

---

## 5. Name fidelity

| Candidate | Assessment |
|---|---|
| Partition `Inventory_HasSpaceForItem` | **Incomplete** — only ret=2 path via FindFreeForItem |
| `Named_CalleeOf_Client_SendInventoryUnequip_*` | Scaffold only; retired |
| **`Inventory_ValidateEquipmentChange_Inferred`** | **Accepted** — matches multi-code gate + both callers; product symbol open → `_Inferred` |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Function boundary | **High** |
| ABI thiscall / RET 4 / ECX=inventory | **High / Sealed** |
| Return codes 0/1/2/8/0xa/0xd/0xf | **High** (body + UI switch) |
| FindFreeForItem identity @ +0x2b0 | **High** (dualed callee + asm) |
| Type-dispatch offsets | **High** CF/asm |
| Host slot English names | **Tentative** |
| Product retail symbol | **Open** |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps (explicit)

- Product names for type classes and `+0x254…+0x270` slots.
- State flag field names (`+0xf5`, `+0xf6`, hazard `+0x6b8`).
- `FUN_004ce5f0` not dualled here (type 0xe only).
- Runtime Confirmed not claimed.

---

## 8. Verdict

**accept-with-gaps** — CF/ABI/RET4/callers/status-code map/FindFree path sealed; product English + runtime open.
