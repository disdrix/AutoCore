# Review A (reconstruction fidelity): `aa_00506f50` VehicleNet_CreateMsgSlice_InitMotionFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00506f50` |
| **VA** | `0x00506f50` |
| **Canonical name** | `VehicleNet_CreateMsgSlice_InitMotionFields_Inferred` (was `FUN_00506f50`) |
| **Ghidra symbol** | `FUN_00506f50` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — create msg helper residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00506f50_VehicleNet_CreateMsgSlice_InitMotionFields_Inferred.md` |
| **System** | input-drive-control / GhostVehicle create templates |
| **Callers** | **Sole:** `VehicleNet_CreateMsgBuffer_Ctor_Inferred` `0x00506ee0` (×10 sub-ctor chain) |
| **Parent** | `VehicleNet_AllocCreateMsgSlots` `0x005f5ad0` ← UnpackGhost vehicle path |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Initialize one motion/pose slice** inside the large vehicle create-message buffer. Parent `FUN_00506ee0` invokes this **10 times** with this-adjust (decomp collapses distinct ECX bases).

Live body (trivial):

```
*(this + 0x64) = 0;
*(this + 0x68) = 0;
*(this + 0x6c) = 0;   // float3-ish block A zeroed
*(this + 0x70) = 0;
*(this + 0x74) = 0;
*(this + 0x78) = 0;   // float3-ish block B zeroed
*(float*)(this + 0x7c) = g_flMsToSeconds_Inferred;  // 0.001 @ 0x00a0f72c
return;
```

Does **not** stamp opcodes, −1 sentinels, or full 0xD78 zero — parent AllocCreateMsgSlots owns those. This unit only seeds two zeroed triples + a default time-scale float on each of 10 slices.

Product English for the two float3s (pos/vel vs lin/ang residual) **Open**; layout offsets **High**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00506f50` |
| Callers | `get_function_callers` → only `00506ee0` |
| Parent dual | `A_aa_00506ee0_VehicleNet_CreateMsgBuffer_Ctor_Inferred.md` |
| Constant plate | `physics/constants/c_wheels_fixed.md` — `g_flMsToSeconds_Inferred` = **0.001** @ `0x00a0f72c` |
| Raw / clean | `raw/aa_00506f50_*`, `FUN_00506f50.cpp` |

---

## 3. Signature

```c
// ECX = one create-msg sub-object / this-adjusted slice
void __fastcall CreateMsgSlice_InitMotionFields(CreateMsgSlice *this);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Zeros +0x64..+0x6c and +0x70..+0x78 | **High** |
| Sets +0x7c = **0.001** (ms→s global) | **High** |
| Exactly the sub-ctor used ×10 by `0x00506ee0` | **High** |
| No opcode / full-buffer init here | **High** |
| Slice stride / absolute English field names | **Open** residual |
| Shared with character create buffers | **Falsified** (parent dual: vehicle branch) |

**Verdict:** **accept-with-gaps**
