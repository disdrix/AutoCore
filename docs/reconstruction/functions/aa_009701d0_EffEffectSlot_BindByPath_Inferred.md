# Function record: EffEffectSlot_BindByPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009701d0` |
| **Canonical name** | `EffEffectSlot_BindByPath_Inferred` |
| **Ghidra name** | `FUN_009701d0` |
| **Address** | `0x009701d0` |
| **Body range** | `0x009701d0`–`0x00970250` exclusive (**128** B / `0x80`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics effect/material slot bind (intrusive refcount swap) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + refcount sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_009701d0_EffEffectSlot_BindByPath_Inferred.md`, `reviews/B_aa_009701d0_EffEffectSlot_BindByPath_Inferred.md` (2026-08-04 W37-Q) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_009701d0`
- Informal: material bind / FX bind (caller reports)

## Purpose

Load/create an effect object from the process effect manager (`DAT_00d1f61c`) by path/token, AddRef it, release any previous occupant of a `void**` slot, store the new pointer, optionally emit debug path telemetry, and return load status (`-1` on failure).

## Signature

```c
int32_t __thiscall EffEffectSlot_BindByPath_Inferred(
    void** slot,          // ECX
    void* pathOrToken);   // stack
// RET 0x04
// return: 0xFFFFFFFF on load fail; else status written by FUN_0073e1e0 (>=0)
```

## Algorithm

1. `effect = FUN_0073e1e0(DAT_00d1f61c, pathOrToken, &status)` — status aliases stack formal.
2. Null effect → return `-1`.
3. `effect.refcount++` @ `+4`; if first ref, thiscall `vtbl[+4]`.
4. If old `*slot`: `refcount--`; if zero, thiscall `vtbl[+8]`.
5. `*slot = effect`.
6. If `DAT_00d1f050[+0x68]`: debug helpers `FUN_00965600` + `FUN_00744ea0`.
7. Return status formal.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009701d0_FUN_009701d0.md`
- Annotated: `docs/reconstruction/raw/aa_009701d0_FUN_009701d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EffEffectSlot_BindByPath_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_009701d0.cpp`
- Function FUN_*: `docs/reconstruction/functions/aa_009701d0_FUN_009701d0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-009701d0-0043bd40-w37q-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0073e1e0`, `FUN_00965600`, `FUN_00744ea0`, indirect vtbl+4 / vtbl+8 |
| **Callers** | 100+ xrefs — FX preload (`FUN_00948bd0`), material setup (`FUN_0099e6c0`, `FUN_00731130`, `FUN_0099f450`), graphics bootstrap (`FUN_004c0a90`, `FUN_004c1cb0`), Z-fill (`FUN_0098d870`), unserialize paths, … |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body hex | **High** |
| thiscall + `ret 4` + fail `-1` | **High** |
| Refcount @+4 / vtbl+4 / vtbl+8 | **High** |
| Success returns status not effect* | **High** |
| Product English plate | **Inferred** |
| Manager load internals | Unowned |
| Runtime / differential | Open |

## Related

- Refcount release twin pattern: `aa_00437150` `RefCountedSlot_ReleaseAndClear`
- Path intern often preceding: `FUN_00989e00`
- Effect manager ctor / factory map: `FUN_0073e3a0` + `aa_0043bd40`
