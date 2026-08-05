# Function record: TFID_EqualsObjectId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404aa0` |
| **Canonical name** | `TFID_EqualsObjectId` |
| **Address** | `0x00404aa0`–`0x00404ac6` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | identity / TFID (cross-cutting) |
| **Classification** | leaf |
| **Completion status** | **Sealed** — dual A/B 2026-07-29; body + ABI + field offsets sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept** |

## Purpose

Leaf equality for **ObjectId / TFID head**: compare `int32@+0`, `int32@+4`, `char@+8`. Return **1** if all match, else **0**. No callees, no globals, no null checks. Does **not** compare TFID pad bytes `+9..+15`.

## Signature (sealed)

```c
int __cdecl TFID_EqualsObjectId(void *pA, void *pB);
```

| Param | Stack | Meaning |
|---|---|---|
| `pA` | `[esp+4]` | pointer to first id block |
| `pB` | `[esp+8]` | pointer to second id block |
| return | `EAX` | `1` equal / `0` unequal |

## Compared layout (inferred names)

| Offset | Width | Inferred name |
|---|---|---|
| `+0` | `int32` | `dwCoidLo` |
| `+4` | `int32` | `dwCoidHi` |
| `+8` | `int8` | `bGlobal` |
| `+9..+15` | — | **not compared** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404aa0_TFID_EqualsObjectId.md`
- Annotated: `docs/reconstruction/raw/aa_00404aa0_TFID_EqualsObjectId.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TFID_EqualsObjectId.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00404aa0_TFID_EqualsObjectId.md`
- Review B: `docs/reconstruction/reviews/B_aa_00404aa0_TFID_EqualsObjectId.md`
- Report: `docs/agents/task-dual-ab-00404aa0-tfid-equals-objectid-report.md`

## Callers / callees

**Callees:** none (leaf).

**Named callers (Ghidra `get_function_callers`, 22):**

`Client_RequestCastSkill`, `Client_Skill_ResolveCastTarget`, `Client_StanceOrGadgetActivatePath`, `Skill_ApplyStatusEffectLocal`, `Skill_FilterTargetForResolveList_Inferred`, `NPC_TryCastSkillFromSet`, `VehicleNet_ReconcilePrediction`, `FUN_004b7e50`, `FUN_004c8970`, `FUN_005792d0`, `FUN_0058a810`, `FUN_0058cd60`, `FUN_005b10a0`, `FUN_005cd3b0`, `FUN_005d9290`, `FUN_007ffef0`, `FUN_00829190`, `FUN_008a8770`, `FUN_00930fc0`, `FUN_0093ffb0`, `FUN_00941d50`, `FUN_00946c00`.

**Xref count:** 38 (includes non-function / multi-site).

**Sibling:** `TFID_NotEquals` (`aa_0040b150` / `0x0040b150`) — same three fields, inverted return.

**Related data:** `g_abTfidInvalid_A15870` @ `0x00a15870` = `{0xFFFFFFFF,0xFFFFFFFF,0x00,...}` (common compare target).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| `__cdecl` two-pointer ABI | **High** |
| Offsets +0/+4/+8 only | **High** |
| Field product names | **Probable** |
| Types as full `TFID_16*` | **Probable** (callers pass 16 B blocks; body uses 9 B) |
