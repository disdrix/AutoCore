# Function record: RefCountedPtr3Flags_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f510` |
| **Canonical name** | `RefCountedPtr3Flags_Dtor_Inferred` |
| **Ghidra name** | `FUN_0096f510` |
| **Address** | `0x0096f510`–`0x0096f522` exclusive (**18 B** / `0x12`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared util — RefCountedPtr3Flags dtor/release |
| **Status** | Dual A/B sealed W37-H 2026-08-04 — **accept-with-gaps** |

## Purpose

Dtor/release helper for the **8-byte** handle shell introduced by `RefCountedPtr3Flags_DefaultCtor_Inferred` (`0x0096f530`):

| Step | Action |
|------|--------|
| 1 | `payload = *handle` |
| 2 | if null → return |
| 3 | `--payload.refcount` at **+4** |
| 4 | if remaining → return |
| 5 | **tail JMP** `[payload.vtbl + 8]` (Release) |

Does **not** null `*handle`. Does **not** zero flag bytes at handle+4/+5/+6.

## Signature

```c
// ECX = handle*; bare RET; void
void __fastcall RefCountedPtr3Flags_Dtor_Inferred(
    RefCountedPtr3Flags* handle /*ECX*/);
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x0096f530` RefCountedPtr3Flags_DefaultCtor_Inferred | Peer ctor (W35-G) |
| `0x0096ef70` / `0x0096efd0` | Pointer-only RefCountedPtr pair (different layout) |
| `0x00457720` | vector_ctor binds size 8, ctor=`0096f530`, dtor=this |
| `0x00632900` CVOGTacArc_dtor_helper | Named caller |
| `0x0096f0e0` EffTexture_CreateOrAssignSlot | **Different** family — do not merge |

## Artifacts

See `aa_0096f510_FUN_0096f510.md`.
