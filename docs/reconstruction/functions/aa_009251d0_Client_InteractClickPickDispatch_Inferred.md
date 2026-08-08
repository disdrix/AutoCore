# Function record: `Client_InteractClickPickDispatch_Inferred`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009251d0` |
| **Canonical name** | `Client_InteractClickPickDispatch_Inferred` |
| **Ghidra name** | `FUN_009251d0` |
| **Address** | `0x009251d0` |
| **Body** | `009251d0`–`009253d6` inclusive (**519 B** / `0x207`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Partition** | R11-038 (parent dual `0x009247b0` Client_InteractClickPickTarget) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (R11-038)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred; Terminal false) |

## Alias

- Prior scaffold: `FUN_009251d0`
- Parent (not this unit): `Client_InteractClickPickTarget` `aa_009247b0`
- Sibling vtable neighbor: `Client_InteractWorldClickHub` `aa_00925820`

## Purpose

Virtual mouse-click **entry / dispatch** on the client controller: mode/UI/character gates, pending-skill cancel, free-select flag `DAT_00d1a859`, then soft/commit call into dualed `Client_InteractClickPickTarget`. Soft path may arm `CVOGHBBase` heartbeat.

## Signature

```c
uint8_t __thiscall Client_InteractClickPickDispatch_Inferred(
    Client *this, uint32_t arg1, uint32_t packedMouse);
// packedMouse: lo = sx (i16), hi = sy (i16); epilogue RET 8
// soft: DAT_00d1a860 != 0 → ClickPickTarget(..., 0, filter); return 0
// commit: DAT_00d1a860 == 0 → return ClickPickTarget(..., 1, filter)
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009251d0_FUN_009251d0.md` (+ R11-038 append) |
| Annotated | `docs/reconstruction/raw/aa_009251d0_FUN_009251d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractClickPickDispatch_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_009251d0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md` |
| Report | `docs/agents/task-dual-ab-009251d0-r11-report.md` |

## Callers / callees

**Callers:** virtual only — DATA `@ 0x00a2f41c` (client vtable).

**Key callees:**

| Callee | VA / note |
|--------|-----------|
| `Client_InteractClickPickTarget` | `0x009247b0` (parent dual) |
| `Client_PromptSkillTargetSelect` | `0x0093bac0` (dualed; cancel −1) |
| `CVOGHBBase_Start` | `0x005081c0` (soft path) |
| `FUN_007fb990` | `0x007fb990` (post-cancel UI; ESI=client) |
| `FUN_00914be0` | `0x00914be0` (free predicate) |
| client vtbl `+0x3bc`, `+0x42c` | mouse UI on `+0x4b8` |
| select vtbl `+0x378` | consume click |
| char component `+0x194` / UI `+0x3d8` | dead / modal gates |

## Confidence

| Claim | Level |
|---|---|
| Stage map + ABI + soft/commit | **High / Confirmed** |
| Product English name | **Probable** structural `_Inferred` |
| Vtbl slot / mode 6 English | **Open** |
| Runtime | **Open** |
