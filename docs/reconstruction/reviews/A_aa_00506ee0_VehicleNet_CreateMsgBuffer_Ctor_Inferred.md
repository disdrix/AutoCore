# Review A (reconstruction fidelity): `aa_00506ee0` VehicleNet_CreateMsgBuffer_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00506ee0` |
| **VA** | `0x00506ee0` |
| **Canonical name** | `VehicleNet_CreateMsgBuffer_Ctor_Inferred` (was `FUN_00506ee0`) |
| **Ghidra symbol** | `FUN_00506ee0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of UnpackGhost) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00506ee0_VehicleNet_CreateMsgBuffer_Ctor_Inferred.md` |
| **System** | input-drive-control / GhostVehicle create templates |
| **Parent** | `VehicleNet_AllocCreateMsgSlots` `0x005f5ad0` ← `VehicleNet_UnpackGhostVehicle` `0x005f7720` |
| **Also caller** | `FUN_005c6c70` (Named_LoadNode_setCreateMsg family) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-place sub-object constructor chain** for a large vehicle create-message buffer (`operator_new(0xD78)` path in AllocCreateMsgSlots).

Body (live):

```
// __fastcall: ECX = buffer*
FUN_00506f50(); ×7   // sequential sub-ctors (decomp collapses args; this-adjust chain)
i = 3
do { FUN_00506f50(); i--; } while (i != 0);  // +3 more = 10 total sub-ctors
return buffer;
```

Does **not** zero memory, stamp opcodes, or set −1 sentinels — those are **parent** AllocCreateMsgSlots after this returns. This unit only runs nested `FUN_00506f50` ctors.

**Callers:** `VehicleNet_AllocCreateMsgSlots` `0x005f5ad0`, `FUN_005c6c70`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00506ee0` |
| Callers | `get_function_callers` → `005c6c70`, `005f5ad0` |
| Parent dual | `A_aa_005f5ad0_VehicleNet_AllocCreateMsgSlots.md` |
| Raw / clean | `raw/aa_00506ee0_*`, `FUN_00506ee0.cpp` |

---

## 3. Signature

```c
void *__fastcall CreateMsgBuffer_Ctor(void *buffer /*ECX*/);
// returns ECX unchanged; 10× FUN_00506f50 sub-ctors
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Ctor shell for 0xD78 vehicle create buffer | **High** (parent context) |
| Exactly 10 sub-ctor calls | **High** (7 + loop 3) |
| No opcode stamp here | **High** |
| Sub-ctor `0x00506f50` English / layout | **Open** residual |
| Character 0x930 / 0x1A8 paths use this | **Falsified** (parent uses different sizes; this is vehicle branch) |

**Verdict:** **accept-with-gaps**
