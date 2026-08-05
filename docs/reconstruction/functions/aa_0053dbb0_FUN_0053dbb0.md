# Function record: FUN_0053dbb0 / CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053dbb0` |
| **Canonical name** | `CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred` |
| **Ghidra symbol** | `FUN_0053dbb0` |
| **Address** | `0x0053dbb0`–`0x0053dcf6` (**327 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object lifecycle / AI mode apply |
| **Completion status** | **Dual sealed** (W26-E 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Virtual **mode-flag apply** on a CVOGObject: branch self vfuncs on the char flag, stamp host mode `0x10` and fan-out children when flag≠0, always **WorldObj_RebindActivate**, dual locked AI notifies, optionally **SwitchHBAIByCode(1|6)** when the world object lacks both flag@+0x40 and ptr@+8.

## Signature

```c
// thiscall; ret 4; virtual (8 rdata vtable installs)
void __thiscall CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred(
    int *self /*ECX*/, char modeFlag /*stack+4*/);
```

## Callers / callees

| Dir | Targets |
|---|---|
| Callers | **vtable only** (8 rdata xrefs; 0 direct function callers) |
| Callees | self vtbl +0xc/+0x10; child list +0x4c/+0x50; child vtbl+8; `FUN_00560e90`; `FUN_005070b0`/`FUN_005070d0`; AI vtbl +0x50/+0x54; tail `FUN_005d4440` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053dbb0_FUN_0053dbb0.md`
- Annotated: `docs/reconstruction/raw/aa_0053dbb0_FUN_0053dbb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0053dbb0.cpp`
- Function named: `docs/reconstruction/functions/aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md`
- Reviews: `A_aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md`, `B_aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI thiscall + char + ret 4 | **High** |
| Tail SwitchHBAI 1/6 | **High** |
| Virtual install | **High** |
| Product English for mode flag | **Probable** |
