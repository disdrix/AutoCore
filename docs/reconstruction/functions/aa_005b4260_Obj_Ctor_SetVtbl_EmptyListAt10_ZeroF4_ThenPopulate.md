# Function record: Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b4260` |
| **Canonical name** | `Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate` (Inferred) |
| **Ghidra name** | `FUN_005b4260` |
| **Address** | `0x005b4260` |
| **Body range** | `0x005b4260`–`0x005b42e6` exclusive (**134** B / `0x86`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host object / MSVC ctor + populate |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI sealed; **zero live callers**; product class open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md`, `reviews/B_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` (2026-07-29 W30-O) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005b4260`
- Role: convenience ctor = default shell + `FUN_005b3fa0` under SEH

## Purpose

Construct the same **0x30**-byte host shell as the default ctor, then immediately invoke populate `FUN_005b3fa0` with five stack parameters. MSVC SEH around construction. **No code xrefs** in image — live code paths call default ctor then populate separately.

## Signature

```c
void * __thiscall Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate(
    void *self,
    uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6);
// ECX = this; ret 0x14; returns this in EAX
```

## Algorithm

1. SEH prolog (handler `0x009a6860`, state `-1`).
2. Same shell as default ctor: vtbl, empty list at `+0x10`, zero F4 at `+0x20`.
3. SEH state `0`; call `FUN_005b3fa0(this, p2..p6)`.
4. SEH unlink; return `this`; `ret 0x14`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b4260_FUN_005b4260.md`
- Annotated: `docs/reconstruction/raw/aa_005b4260_FUN_005b4260.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005b4260.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005b3f60-005b4260-w30o-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005b43b0` (sentinel); `FUN_005b3fa0` (populate — not owned this wave) |
| **Callers** | **none** (zero code xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Bytes: shell + populate + `ret 0x14` | **High** |
| Five stack args | **High** |
| Zero live callers | **High** |
| Product class / populate semantics | **Open** |
| Runtime / differential | Open |

## Related

- Default ctor twin: `aa_005b3f60`
- Body dtor: `aa_005b3b20` (W28-N)
- Populate: `FUN_005b3fa0`
