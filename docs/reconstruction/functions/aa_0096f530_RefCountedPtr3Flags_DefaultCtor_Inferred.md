# Function record: RefCountedPtr3Flags_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f530` |
| **Canonical name** | `RefCountedPtr3Flags_DefaultCtor_Inferred` |
| **Ghidra name** | `FUN_0096f530` |
| **Address** | `0x0096f530`–`0x0096f53f` inclusive (**16 B** / `0x10`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared util — refcounted handle + 3 flag bytes default ctor |
| **Status** | Dual A/B sealed W35-G 2026-07-29 — **accept-with-gaps** |

## Purpose

Default-construct an **8-byte** handle shell:

| Offset | Write |
|--------|--------|
| +0..+3 | pointer = 0 |
| +4 | flag byte = 0 |
| +5 | flag byte = 0 |
| +6 | flag byte = 0 |
| +7 | **not written** (pad) |

Peer dtor `FUN_0096f510` (context only) releases `*this` via payload refcount at +4 and vtbl[+8]. Distinct from pointer-only `RefCountedPtr_DefaultCtor_Inferred` (`0x0096ef70`).

## Signature

```c
// ECX = this; no stack args; bare RET; return this* in EAX
RefCountedPtr3Flags* __fastcall RefCountedPtr3Flags_DefaultCtor_Inferred(
    RefCountedPtr3Flags* self /*ECX*/);
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x0096ef70` RefCountedPtr_DefaultCtor_Inferred | Sibling — pointer-only null |
| `0x0096f510` FUN_0096f510 | Peer dtor (refcount release) |
| `0x004c0640` ParticleFluidPhase_Ctor | Caller — two fields @ +0x84 / +0x8c |
| `0x00457720` | Caller — `_eh_vector_constructor_iterator_(…,8,2,ctor,dtor)` |

## Artifacts

See `aa_0096f530_FUN_0096f530.md`.
