# Function record: Object_EntityBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4830` |
| **Canonical name** | `Object_EntityBase_Ctor` |
| **Ghidra name** | `FUN_005d4830` |
| **Address** | `0x005d4830`–`0x005d48e4` (181 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / entity base ctor |
| **Completion status** | **dual-sealed** W24-E 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Parent base ctor under `Object_EntityMidBase_Ctor`: dual-base mostDerived path, composite sub-ctors at +0 / +0x40, flag bits 0x40|0x20.

## Signature

```c
void* __thiscall Object_EntityBase_Ctor(void* self, int mostDerivedFlag);
// RET 4
```

## Artifacts

See `aa_005d4830_FUN_005d4830.md` for full table + A/B paths.
