# Function record: SoftCastHitList_ControllerFillWrapper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e1e0` |
| **Canonical name** | `SoftCastHitList_ControllerFillWrapper_Inferred` |
| **Ghidra name** | `FUN_0055e1e0` |
| **Address** | `0x0055e1e0`–`0x0055e21f` inclusive (**64 B** / `0x40`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | R11-003 (score parent `0x006ca890`) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (R11-003)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Ghidra / scaffold: `FUN_0055e1e0`
- No `Named_CalleeOf_*` scaffold for this VA

## Purpose

Thin **thiscall** wrapper under dualed **Client_InteractWorldClickHub**:

1. 16-byte-align stack; allocate `0x50` local frame.
2. Install SoftCastHitEntry vtbl **`0x009D27A8`** on stack entry; pre-zero entry **`+0x44`**.
3. Load **manager** from `controller+0xC4` and **related** from `controller+0xD0`.
4. Call dualed **`SoftCastHitList_CoreFillAndRegister_Inferred`** with payload **hard 0** and hub hit-list backref.
5. **`RET 0x8`**.

## Signature

```c
void __thiscall SoftCastHitList_ControllerFillWrapper_Inferred(
    void *controller,           // ECX
    uint32_t *soft_desc,        // [EBP+8]
    uint32_t hit_list_backref   // [EBP+0xC]
);
// RET 0x8 (C2 08 00)
```

## Callers / callees

| Direction | Target | Note |
|---|---|---|
| Caller (1) | `Client_InteractWorldClickHub` / `FUN_00925820` @ `0x00925c32` | after ctor `0040c410`; before sort `0048a060` |
| Callee (1) | `SoftCastHitList_CoreFillAndRegister_Inferred` / `FUN_006ca890` @ `0x0055e215` | local entry as ECX; RET 0x14 |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055e1e0_FUN_0055e1e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055e1e0_FUN_0055e1e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_ControllerFillWrapper_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055e1e0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0055e1e0_FUN_0055e1e0.md` |
| Report | `docs/agents/task-dual-ab-0055e1e0-r11-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 0x8 / local entry / sole caller | **Confirmed** |
| Soft-cast hit-list role under hub | **High** |
| Product English / vtbl map | **Inferred** |
| Runtime | **Open** |
