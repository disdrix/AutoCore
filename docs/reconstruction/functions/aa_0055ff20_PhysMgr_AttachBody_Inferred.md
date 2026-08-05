# Function record: PhysMgr_AttachBody_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ff20` |
| **Canonical name** | `PhysMgr_AttachBody_Inferred` |
| **Ghidra name** | `FUN_0055ff20` |
| **Address** | `0x0055ff20`–`0x00560017` (**248 B** / `0xF8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / manager body attach |
| **Completion status** | **Dual sealed** (W29-R 2026-07-29) — A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0055ff20`
- Prior scaffold alias: `Named_CalleeOf_Named_VOG_DEBUG_STOP_0055ff20` (superseded)

## Purpose

Manager-side attach of a physics body: owner stamp, worklist link collect, CanonAndSort + SortedDiffWalk (new vs empty), serial assign, short refcount++, body vector push (grow with `FUN_005b3370`), host-action notify, worklist release. Twin: detach `FUN_00560020`.

## Signature (machine)

```c
// thiscall; ECX = manager; stack = body*; ret 4; returns body*
int * PhysMgr_AttachBody_Inferred(int manager, int *body);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055ff20_FUN_0055ff20.md` (+ W29-R append)
- Annotated: `docs/reconstruction/raw/aa_0055ff20_FUN_0055ff20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PhysMgr_AttachBody_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0055ff20.cpp`
- Function: `docs/reconstruction/functions/aa_0055ff20_FUN_0055ff20.md`
- Review A: `docs/reconstruction/reviews/A_aa_0055ff20_PhysMgr_AttachBody_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0055ff20_PhysMgr_AttachBody_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (7 / 8 xrefs) | `FUN_004ca9f0`, `FUN_004e9720`, `FUN_004ea350`, `FUN_005625c0`, `FUN_005dd080`×2, `FUN_00932060`, `hkVehicleFramework_preUpdate` |
| Callees | LocalWorklist init `0062d960`, body vtbl+0x18, mgr `[+0xc4]+4`, CanonAndSort, SortedDiffWalk, `005b3370`, `0062a4d0`, LocalWorklist_Release |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI thiscall / `ret 4` / returns body | **High** |
| Attach role vs detach twin | **High** |
| Body list grow mask | **High** |
| Product manager/body English | **Tentative** |
| Runtime / bit-exact | **Open** |
