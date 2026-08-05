# Function record: FUN_004c7bd0 / CVOGCreature_SlewFacingYaw_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7bd0` |
| **Canonical name** | `CVOGCreature_SlewFacingYaw_Inferred` |
| **Ghidra name** | `FUN_004c7bd0` |
| **Address** | `0x004c7bd0` |
| **Body range** | `0x004c7bd0` – `0x004c7fc1` (1010 B / `0x3F2`, inclusive `RET 4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | creature / facing / aim |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29 (CF + ABI + constants + write site); acos arg component + aim-slot English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Human: `CVOGCreature_SlewFacingYaw_Inferred`
- Former scaffold: `Named_CalleeOf_CVOGCreature_SetupGraphics_004c7bd0` (parent seed; incomplete)

## Purpose

Rate-limited **horizontal facing yaw** update: build unit XZ direction from aim/target vs self pose, measure misalignment, and slew `*(float*)(this+0x11c)` by  
`(1 - align) * ms * 0.001 * 9.6` with **2π** wrap. Used from creature setup and a period-driven HB.

## Signature (sealed)

```c
// __thiscall; ECX = creature/object*; stack int deltaMs; RET 4; void
void CVOGCreature_SlewFacingYaw_Inferred(void *pCreature, int deltaMs);
```

| Formal | Source | Conf |
|---|---|---|
| `this` | ECX | **High** |
| `deltaMs` | stack `[ebp+8]`; float cast; `<0` → `+2^32` | **High** |
| Return | void (`RET 4`) | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c7bd0_FUN_004c7bd0.md`
- Annotated: `docs/reconstruction/raw/aa_004c7bd0_FUN_004c7bd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCreature_SlewFacingYaw_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c7bd0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md`

## Callers / callees

### Callers (3)

| Address | Function | Notes |
|---|---|---|
| `0x004c8e49` | `CVOGCreature_SetupGraphics` | setup path |
| `0x005d6bf7` | `FUN_005d6b80` | HB ctor; zeroes target `+0x11c`; arg `0x1e` |
| `0x005d6c21` | `FUN_005d6c10` | HB tick; arg `nPeriodMs` |

### Callees

`FUN_004e8a40`, `_finite`, `__RTDynamicCast`, `FUN_004e9530`, `FUN_00404c90`, `FUN_0040d0a0` (`Math_AcosClamped`), `FUN_004e8ad0`, `fsin`, `fcos`, `SQRT`.

## Constants (sealed)

| Symbol | VA | Value |
|---|---|---|
| `DAT_009cb8d4` | `0x009cb8d4` | `1.1920929e-7f` |
| `DAT_00aaa7dc` | `0x00aaa7dc` | `≈6.283185f` (`2π`) |
| `DAT_009cbab0` | `0x009cbab0` | `9.6f` |
| `DAT_009cbab8` | `0x009cbab8` | double `0.999` |
| `g_flMsToSeconds_Inferred` | `0x00a0f72c` | `≈0.001f` |
| `DAT_00aaa5dc` | `0x00aaa5dc` | `4294967296.0f` |
| `g_flOne` | `0x00a0f2a0` | `1.0f` |

## Sealed facts

| Fact | Level |
|---|---|
| thiscall + `RET 4` + void | **Sealed** |
| Sole write `*(float*)(this+0x11c)` | **Sealed** |
| Require `this+8` host; finite pose X | **Sealed** |
| Horizontal normalize (Y×0) | **Sealed** |
| Rate `(1-align)*ms*0.001*9.6` | **Sealed** |
| 2π wrap via `DAT_00aaa7dc` | **Sealed** |
| Align gate double `0.999` | **Sealed** |
| Callers: SetupGraphics + HB ctor/tick | **Sealed** |

## Gaps

| Gap | Status |
|---|---|
| Exact float passed to `Math_AcosClamped` (decompiler elides) | Open / Medium |
| Aim-slot English (`+0xe894+0x11c`) | Open |
| Product / PDB name | Open |
| Runtime yaw histogram | Open |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Slew-facing-yaw semantic name | **High** structural / product **Tentative** |
| Acos input component | **Medium** |
