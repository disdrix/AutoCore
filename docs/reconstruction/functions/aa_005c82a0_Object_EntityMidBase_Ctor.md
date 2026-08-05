# Function record: Object_EntityMidBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c82a0` |
| **Canonical name** | `Object_EntityMidBase_Ctor` |
| **Ghidra name** | `FUN_005c82a0` |
| **Prior aliases** | `Named_CalleeOf_CVOGReaction_GiveItemByCbid_005c82a0` (incomplete — multi-caller mid-base) |
| **Address** | `0x005c82a0`–`0x005c83a1` (257 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / entity mid-base ctor |
| **Completion status** | **Dual-sealed 2026-07-29 W23-K** — ABI/CF/vtbl/fields/callers **High**; product class English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **most-derived / base constructor** for the entity mid-base shared by **CVOGCreature** and **Vehicle**. When `mostDerivedFlag != 0`, installs dual-base vb cookies and constructs `Object_SharedBase` at `this+0x110`. Always chains parent `FUN_005d4830(0)`, installs mid-base vtbls, applies vb adjustor **`-0x10c`**, and defaults `+0xD0..+0xF8` (including **500** at `+0xE4`).

## Signature

```c
// __thiscall; ECX=this; stack mostDerivedFlag; RET 4; EAX=this
uint32_t* __thiscall Object_EntityMidBase_Ctor(uint32_t* self, int mostDerivedFlag);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005c82a0_FUN_005c82a0.md` (+ W23-K append)
- Annotated: `docs/reconstruction/raw/aa_005c82a0_FUN_005c82a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_EntityMidBase_Ctor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005c82a0.cpp`
- Reviews: `reviews/A_aa_005c82a0_Object_EntityMidBase_Ctor.md`, `reviews/B_aa_005c82a0_Object_EntityMidBase_Ctor.md`
- Scaffold record: `docs/reconstruction/functions/aa_005c82a0_FUN_005c82a0.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `CVOGCreature_ctor` `0x004c9aa0` | parent, flag 0 |
| Caller | Vehicle ctor `0x00501970` | parent, flag 0; `PTR_Vehicle_TryActivatePhysics` |
| Caller | `FUN_00588dc0` | sibling large-object ctor |
| Caller | `CVOGReaction_GiveItemByCbid` `0x0051a170` | factory |
| Caller | `FUN_0051ea10`, `FUN_0051ef40` | factory/ctor |
| Callee | `Object_SharedBase_Ctor` `0x00518940` | mostDerived: `this+0x110` |
| Callee | `FUN_005d4830` | parent mid base, flag 0 |

## Key offsets (this)

| Offset | Init | Confidence |
|---|---|---|
| +0x00 / +0x40 | mid-base vtbls | **High** |
| +0x04 / +0x44 | vb cookies (mostDerived) | **High** |
| +0x110 | `Object_SharedBase` embed (mostDerived) | **High** |
| vb adjustor | `-0x10c` | **High** |
| +0xE4 | 500 | **High** (image imm) |
| +0xE8 / +0xEC | 1 / -1 | **High** |
| +0xF2..+0xF4 | bytes 1 | **High** |

## Confidence

| Claim | Level |
|---|---|
| ABI + RET 4 + return this | **High** |
| Role = entity mid-base ctor (creature+vehicle parent) | **High** |
| SharedBase at +0x110 | **High** |
| Field default table | **High** |
| Product C++ class English | **Inferred** / open |
| `+0xE4=500` semantic | **Open** |
