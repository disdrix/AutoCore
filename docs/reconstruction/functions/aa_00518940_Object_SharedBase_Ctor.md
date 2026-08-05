# Function record: Object_SharedBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518940` |
| **Canonical name** | `Object_SharedBase_Ctor` |
| **Ghidra name** | `FUN_00518940` |
| **Prior aliases** | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00518940` (incomplete — multi-caller base) |
| **Address** | `0x00518940`–`0x00518c14` (724 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / dual-base shared fields |
| **Completion status** | **Dual-sealed 2026-07-29 W22-B** — ABI/TFID/CS/dirty/instance counter **High**; product class English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **shared dual-base / virtual-base field constructor** for the client object core. Initializes TFIDs to invalid, flag dword (`+0x17c`), float `1.0f`, critical-section helper (`+0xb0`), and bumps a process-wide instance counter. Outer complete-object ctors (Creature, Vehicle, Character, intermediate bases) invoke this with **ECX = core subobject** at type-dependent offsets when `mostDerivedFlag != 0`.

## Signature

```c
// __thiscall/__fastcall; ECX = core this; returns this; no stack args
int32_t __fastcall Object_SharedBase_Ctor(int32_t self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518940_FUN_00518940.md`
- Annotated: `docs/reconstruction/raw/aa_00518940_FUN_00518940.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_SharedBase_Ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00518940.cpp`
- Reviews: `reviews/A_aa_00518940_Object_SharedBase_Ctor.md`, `reviews/B_aa_00518940_Object_SharedBase_Ctor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00518940_FUN_00518940.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `CVOGCreature_ctor` `0x004c9aa0` | mostDerived: `lea ecx,[this+0x500]` |
| Caller | Vehicle ctor `0x00501970` | mostDerived: `lea ecx,[this+0x670]` |
| Caller | `CVOGCharacter_ctor` `0x00536920` | mostDerived path |
| Caller | `FUN_005c82a0` | mostDerived: `lea ecx,[this+0x110]` |
| Caller | `FUN_005d4830` | mostDerived: `lea ecx,[this+0xe0]` |
| Caller | `FUN_0051e7d0` | `lea ecx,[this+0x40]` |
| Caller | 20+ other factory/ctor sites | xrefs |
| Callee | `FUN_00512670` | `Object_PropagateDirtyBit0x20000` |
| Callee | `operator_new(0x2c)` | CS helper |
| Callee | `InitializeCriticalSection` | Win32 |

## Key offsets (core this)

| Offset | Init | Confidence |
|---|---|---|
| +0x40 / +0x160 | invalid TFID (`g_abTfidInvalid_9CDF88`) | **High** |
| +0xb0 | CS helper object* | **High** |
| +0xb8 | `1.0f` (`g_flOne`) | **High** |
| +0xac | 0 (dirty parent link) | **High** |
| +0x17c | `(x & 0xffe22210) \| 0x22210` then `\| 0x20000` | **High** |
| +0x184 | `x & ~0xf` | **High** |

## Confidence

| Claim | Level |
|---|---|
| ABI + return this + no stack formals | **High** |
| Role = shared base field ctor | **High** |
| Type-dependent ECX embed offsets | **High** (image LEA samples) |
| Dirty bit via `00512670` | **High** |
| Product C++ class English name | **Inferred** / open |
| Full field dictionary | **Open** |
