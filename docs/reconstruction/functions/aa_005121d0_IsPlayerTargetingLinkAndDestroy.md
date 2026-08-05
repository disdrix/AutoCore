# Function record: IsPlayerTargetingLinkAndDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_005121d0` |
| **Canonical name** | `IsPlayerTargetingLinkAndDestroy` (inferred; parent dual + RTTI) |
| **Ghidra name** | `FUN_005121d0` |
| **Address** | `0x005121d0` |
| **Body** | `0x005121d0`–`0x00512206` (leaf; `ret 0xC` @ `0x005121fe`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / combat-target / HB |
| **Completion status** | **Dual A/B sealed** (W16-O, 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_005121d0`
- `Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_005121d0` (legacy scaffold name; inaccurate — sole direct xref is `Object_SetSelectedTarget`, which is itself reached from drive tick among others)

## Purpose

**HB list purge predicate:** RTTI-cast list node from `CVOGHBBase` to `CVOGHBPlayerTargetingLink`; on success invoke `vtbl+0x18(1,0)` (destroy) and return **1** (remove from list); else return **0**.

Used only when the entity **changes selected target** so the prior self-side targeting link is destroyed while base-vtbl target-side HBs are left alone.

## Signature (image-sealed)

```c
// free function, stdcall cleanup ret 0xC (3 stack formals)
// only arg0 is read; arg1/arg2 are list-walk context (caller passes 0,0)
uint32_t __stdcall IsPlayerTargetingLinkAndDestroy(
    void *node,     // HB object* from entity+0xB0 list
    void *ctx1,     // unused
    void *ctx2);    // unused
// returns 1 = remove after destroy; 0 = keep
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005121d0_FUN_005121d0.md`
- Annotated: `docs/reconstruction/raw/aa_005121d0_FUN_005121d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005121d0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/IsPlayerTargetingLinkAndDestroy.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005121d0_IsPlayerTargetingLinkAndDestroy.md`
- Review B: `docs/reconstruction/reviews/B_aa_005121d0_IsPlayerTargetingLinkAndDestroy.md`
- Prior scaffold record: `functions/aa_005121d0_FUN_005121d0.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller (sole) | `0x005172d0` `Object_SetSelectedTarget` | `push pred` @ `0x0051733b`; list this = `entity+0xB0` |
| Callee | `__RTDynamicCast` @ `0x004898A4` | 5-arg cdecl |
| Callee | indirect `vtbl+0x18` | thiscall destroy flags (1, 0) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ image | **Confirmed** |
| RTTI class pair Base → PlayerTargetingLink | **Confirmed** (type-desc strings) |
| `ret 0xC` / 3 stack formals | **Confirmed** (epilogue bytes) |
| Return 1 = remove / destroy path | **High** (caller list remove-if) |
| Product English of vtbl+0x18 | **Tentative** |
| Parameter semantic names beyond node* | **Tentative** (ctx unused) |
