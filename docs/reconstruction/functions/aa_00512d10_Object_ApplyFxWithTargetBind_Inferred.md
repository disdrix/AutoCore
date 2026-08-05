# Function record: Object_ApplyFxWithTargetBind_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512d10` |
| **Canonical name** | `Object_ApplyFxWithTargetBind_Inferred` |
| **Ghidra name** | `FUN_00512d10` |
| **Address** | `0x00512d10` |
| **Body range** | `0x00512d10`–`0x00512ead` (~413 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / skills-abilities |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI sealed; product name + nested attach arg residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md`, `reviews/B_aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` (2026-07-29 W21-A) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00512d10`

## Purpose

Vtbl-installed object method that:

1. Resolves or fully applies an FX instance (heavy nfx path vs light ensure).
2. Sets FX header flag bit **2**.
3. Optionally binds a target entity TFID + float4 offset onto the FX (`FUN_004b68c0`).
4. Attaches FX via host vtbl **`+0xf8`** (direct or nested).
5. Posts via `FUN_004b7e50` with zeroed trailing args.

## Signature

```c
uint32_t __thiscall Object_ApplyFxWithTargetBind_Inferred(
    void *thisObj,
    uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5,
    int *pTargetEntity, int offsetComponent, char skipFullNfx, uint32_t *pFxInOut);
// ret 0x20
```

## Algorithm (summary)

See annotated raw. Success returns **1** (or full-apply result); failure returns **0**.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00512d10_FUN_00512d10.md`
- Annotated: `docs/reconstruction/raw/aa_00512d10_FUN_00512d10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ApplyFxWithTargetBind_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00512d10.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00508390-00512d10-w21a-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FxCache_ApplyWithNfxEnsure` `0x00542790`, `FxCache_EnsureMasterAndResolve` `0x005408f0`, `NDSpecialFX_SetTargetTfidAndOffset_Inferred` `0x004b68c0`, `FUN_004b7e50` `0x004b7e50` |
| **Callers** | No direct CALL sites; **DATA** xrefs into 20+ vtbl slots |

## Confidence

| Claim | Level |
|---|---|
| Control flow dual path + flag bit | **High** |
| ABI `ret 0x20` / thiscall | **High** |
| Gate `DAT_00d1f050+0x6c` | **High** (shared with ApplyWithNfx dual) |
| TFID from entity `+0x160` | **High** |
| `2^32` unsigned float adjust | **High** (`read_memory` @ `0x00aaa5dc`) |
| Product English name | **Inferred** |
| Nested vtbl+0xf8 full arg list | Residual (decompiler thin) |
| Runtime / differential | Open |

## Related

- `aa_00542790` — `FxCache_ApplyWithNfxEnsure`
- `aa_005408f0` — `FxCache_EnsureMasterAndResolve`
- `aa_004b68c0` — `NDSpecialFX_SetTargetTfidAndOffset_Inferred`
