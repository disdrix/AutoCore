# Review A (reconstruction fidelity): `aa_00521310` CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521310` |
| **VA** | `0x00521310`–`0x00521430` (288 bytes) |
| **Canonical name** | `CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred` |
| **Ghidra symbol** | `FUN_00521310` |
| **Review date** | `2026-07-29` (W18-R dual A/B seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` |
| **System** | character create / vehicle attach / sector map |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Character **create-apply finish**: resolve **CurrentVehicleCoid** → `Creature::SetVehicle`, set a vehicle bool, **`CVOGSectorMap_AddCharacter`**, optional AutoAssault LOD boost for packet **`0x2016`**, optional equip-gfx list clear.

This is the player path that always attaches vehicles on create (NPC.md).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00521310_FUN_00521310.md` |
| Annotated | `docs/reconstruction/raw/aa_00521310_FUN_00521310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00521310.cpp` |
| Function record | `docs/reconstruction/functions/aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` |
| Callee duals | `A_aa_004bafe0_Object_ResolveTarget_VCall1d4`, `Creature::SetVehicle` (`004c49d0`), `CVOGSectorMap_AddCharacter` |

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| thiscall subobject `this_adj`; `ret 0x18` | **High** | epilogue bytes; negative offsets |
| Character base `this_adj - 0xda0` | **High** | passed to AddCharacter |
| CurrentVehicle COID at `-0xb90/-0xb8c` | **High** | resolve args + NPC.md |
| `FUN_004bafe0` = resolve+vtbl+0x1d4 | **High** | prior dual A/B |
| `FUN_004c49d0` = `Creature::SetVehicle` | **High** | prior art / NPC.md |
| AddCharacter always (this path) | **High** | unconditional call |
| Packet type `0x2016` gate | **High** | imm compare sealed |
| LOD float 999.0f | **High** | `0x4479c000` |
| Calls AddCharacter (not callee of it) | **High** | xrefs + body |
| `param_3..6` semantics | **Low** | only forwarded when flag |
| `vehicle+0x101` meaning | **Medium** | bool write sealed; name open |
| Product English name | **Inferred** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Optional FUN_005c93f0 | **Yes** |
| Resolve vehicle | **Yes** |
| SetVehicle | **Yes** |
| vehicle+0x101 flag | **Yes** |
| AddCharacter | **Yes** |
| 0x2016 LOD cast path | **Yes** |
| EquipGfx clear | **Yes** |

---

## 5. Gaps / open

1. Recover function containing xref `0x0053bed3`.
2. Name `FUN_0053d970` / `FUN_00760fe0` / `FUN_005c93f0` product English.
3. Runtime / differential — open.

**Verdict:** **accept-with-gaps**
