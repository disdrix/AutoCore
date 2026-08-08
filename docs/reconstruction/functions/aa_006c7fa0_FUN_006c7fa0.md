# Function record: FUN_006c7fa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fa0` |
| **Canonical name** | `PhysicsShape_Sphere_CtorFromRadius_Inferred` (Ghidra `FUN_006c7fa0`) |
| **Address** | `0x006c7fa0`–`0x006c7fbc` (**29 B** / `0x1D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / physics sphere shape |
| **Agent** | MEGA-071 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | **false** |

## Alias

- Ghidra: `FUN_006c7fa0`
- Named: `PhysicsShape_Sphere_CtorFromRadius_Inferred`
- **Retired:** `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0`

## Purpose

Leaf thiscall constructor for a 0x10-byte sphere shape: refcount@+0x06=1, clear@+0x08, radius@+0x0c, vtbl `PTR_FUN_00a0d610`, RET 4.

## Signature

```c
void *__thiscall FUN_006c7fa0(void *self, float radius); // RET 4; EAX=self
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.md`
- Annotated: `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PhysicsShape_Sphere_CtorFromRadius_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006c7fa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md`
- Report: `docs/agents/task-dual-ab-006c7fa0-mega-071-report.md`

## Callers / callees

| Role | Value |
|---|---|
| Callers (17) | `FUN_004e9720`, `FUN_004e9aa0`, `FUN_004ea350`, `FUN_004ed470`, `FUN_004ee080`, `FUN_005dd080`, `FUN_005f1ec0`, `FUN_005f3e10`, `FUN_006ca1d0`, `FUN_006ec530`, `FUN_006ec690`, `FUN_006ec7f0`, `FUN_006ec970`, `FUN_006ecad0`, `FUN_006ecc50`, `FUN_006ecdb0`, `FUN_006ed0d0` |
| Xrefs | 18 UNCONDITIONAL_CALL |
| Callees | none |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **Confirmed** |
| thiscall RET 4; radius@+0x0c | **Confirmed** |
| Sphere vtbl family | **Confirmed** |
| Product class English | **Inferred** / open |
