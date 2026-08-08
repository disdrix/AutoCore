# Function record: Character_GetEquipTfidTableCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522000` |
| **Canonical name** | `Character_GetEquipTfidTableCount_Inferred` |
| **Ghidra symbol** | `FUN_00522000` |
| **Address** | `0x00522000`–`0x00522016` inclusive (**23 B** / `0x17`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Partition** | MEGA-100 OWN-ONLY (parent dual `0x008e5ce0`) |
| **Completion status** | **Dual sealed** — Path A **accept**, Path B **accept** (2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open — **terminal false** |

## Purpose

Leaf getter: active **equip TFID table entry count** for a Character, used as the exclusive upper bound when scanning `character+0x5a0` (8-byte lo/hi TFID pairs).

```text
count = min(8, (*(uint8_t*)(this + 0x59a) >> 1) + 3)
```

- Base of **3** slots.
- Each unit of `(budget_byte >> 1)` adds one slot.
- Hard cap **8** (matches UI null-character fallback of literal 8).

## Signature (sealed)

```c
// __thiscall / __fastcall: ECX = Character*
// no stack formals; bare RET; EAX = count
std::uint8_t __fastcall Character_GetEquipTfidTableCount_Inferred(void* character /*ECX*/);
```

## ABI

| Item | Value |
|---|---|
| This | **ECX** = Character* |
| Stack | none |
| Return | **EAX** count |
| Epilogue | bare `RET` |
| Callees | none |

## Key offsets

| Off | Role |
|----:|------|
| `+0x59a` | uint8 equip-slot budget (read) |
| `+0x5a0` | equip TFID table base (callers only) |

## Call graph (this unit)

```text
Client_UI_CraftHost_BindObjectByTfid_Inferred  0x008e5ce0  [dualed parent]
FUN_008e5e00 / FUN_008b2f00 / FUN_008b3400 / FUN_008b3670
  └─ FUN_00522000  Character_GetEquipTfidTableCount_Inferred  [OWN MEGA-100]
       (leaf)
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00522000_FUN_00522000.md` |
| Annotated | `docs/reconstruction/raw/aa_00522000_FUN_00522000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetEquipTfidTableCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522000.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00522000_FUN_00522000.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00522000-mega-100-report.md` |

## Retired names

- `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00522000`

## Confidence

| Claim | Level |
|---|---|
| CF / formula / clamp-8 / ABI | **Confirmed** |
| Equip TFID table count role | **High** |
| Product method / `+0x59a` English | **Inferred** / Open |
| Runtime Confirmed | **not claimed** |

## Gaps

1. Product/PDB English for method and `+0x59a`.
2. Low-bit meaning of budget byte.
3. Runtime / bit-exact / differential.
