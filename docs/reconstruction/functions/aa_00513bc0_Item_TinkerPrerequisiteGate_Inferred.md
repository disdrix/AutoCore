# Function record: Item_TinkerPrerequisiteGate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513bc0` |
| **Canonical name** | `Item_TinkerPrerequisiteGate_Inferred` |
| **Ghidra name** | `FUN_00513bc0` |
| **Address** | `0x00513bc0` |
| **Body** | `0x00513bc0`–`0x00513c06` inclusive (**71 B** / `0x47`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / tinker kit validation |
| **Work item** | MEGA-104 OWN-ONLY dual |
| **Dual verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Purpose

Boolean **prerequisite type-compatibility gate** for tinker-kit validation. Sole caller `FUN_00513c10` (residual `Item_ValidateTinkerKitUse`) rejects with status `3` when this returns false.

## Contract

```
bool Item_TinkerPrerequisiteGate(kit /*ECX*/, candidate /*stack*/):
  if !candidate: return false
  kitHost = *(kit + 0xa8)
  candType = *(candidate + 0xb4)
  if candType == *(kitHost + 0x38): return true
  if candType == 0x44: return *(short*)(*(kitHost+0x3c)+0x3f4) == 10
  if candType == 0x46: return *(short*)(*(kitHost+0x3c)+0x3f4) == 11
  return false
```

ABI: **`__thiscall`**, **`RET 4`**, bool in **AL**. Leaf (no callees).

## Evidence anchors

- Live decompile ≡ 2026-07-23 raw CF
- `disassemble_function` + `read_memory` seal RET 4 / AL bool / type immediates
- 1 xref: `FUN_00513c10` @ `0x00513c36`
- Type-6 remap peer (context): `FUN_00509b10` (10→0x44, 11→0x46)

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513bc0_FUN_00513bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513bc0_FUN_00513bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_TinkerPrerequisiteGate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513bc0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00513bc0_FUN_00513bc0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00513bc0-mega-104-report.md` |

## Gaps

1. Product English for type ids `0x44` / `0x46` and layout fields.
2. Parent `FUN_00513c10` dual residual.
3. Runtime / differential golden.
