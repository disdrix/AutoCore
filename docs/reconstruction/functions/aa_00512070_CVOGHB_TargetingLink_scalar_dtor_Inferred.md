# Function record: CVOGHB_TargetingLink_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512070` |
| **Canonical name** | `CVOGHB_TargetingLink_scalar_dtor_Inferred` |
| **Ghidra name** | `FUN_00512070` |
| **Address** | `0x00512070`–`0x0051208d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / targeting-link |
| **Completion status** | **Dual A/B sealed 2026-07-29 W19-G** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Vtbl** | `PTR_FUN_009cdfb0` slot **0** (DATA xref `0x009cdfb0`) |
| **Class family** | Base targeting-link (`CVOGHB_TargetingLink_*_Inferred` ctor dual) |

## Alias

- Ghidra / scaffold: `FUN_00512070`

## Purpose

MSVC **scalar-deleting destructor** for base targeting-link heartbeat objects: run complete dtor `FUN_00512060`, then `operator_delete(this)` when `flags & 1`. Virtual slot 0 only.

## Signature

```c
void* __thiscall CVOGHB_TargetingLink_scalar_dtor_Inferred(
    void* thisHb /* ECX */,
    uint8_t flags /* bit0 => delete */);
// ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00512070_FUN_00512070.md`
- Annotated: `docs/reconstruction/raw/aa_00512070_FUN_00512070.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHB_TargetingLink_scalar_dtor_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_00512070.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md`
- Function alias: `docs/reconstruction/functions/aa_00512070_FUN_00512070.md`

## Callers / callees

| Direction | VA / name |
|---|---|
| DATA vtbl | `0x009cdfb0` slot 0 |
| Callee | `FUN_00512060` (complete dtor) |
| Callee | `operator_delete` |
| CODE callers | none (virtual) |
| Twin (derived) | `0x0051b870` `CVOGHBPlayerTargetingLink_scalar_dtor` |
| Ctor family | `0x00604d40` `CVOGHB_TargetingLink_ctor_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| Scalar-deleting dtor CF | **Confirmed** |
| Vtbl slot 0 of `009cdfb0` | **Confirmed** |
| Class product RTTI string | **Inferred** (family via ctor dual) |
| MSVC mangled name | Open |

## Gaps

1. Product RTTI / mangled name.
2. Array-deleting dtor presence unknown.
3. Runtime / bit-exact image diff.
