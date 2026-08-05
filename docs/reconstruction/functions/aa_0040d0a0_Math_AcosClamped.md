# Function record: Math_AcosClamped

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d0a0` |
| **Canonical name** | `Math_AcosClamped` (inferred) |
| **Ghidra symbol** | `FUN_0040d0a0` |
| **Address** | `0x0040d0a0` |
| **Body range** | `0x0040d0a0` – `0x0040d0de` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` / shared math |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29 (CF + constants + ABI); product name open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Domain-safe `acos`: if `|x| ≥ 1` return **0** (`x > 0`) or **π** (`x ≤ 0`); else CRT `_CIacos(x)`. Returns **radians** in ST0.

## Signature (sealed)

```c
// __cdecl; float arg @ [esp+4]; return in ST0 (float10 / x87)
float Math_AcosClamped(float x);
```

## Constants

| Symbol | VA | Value |
|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `1.0f` |
| `DAT_00a27c3c` | `0x00a27c3c` | `π` (`db 0f 49 40`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d0a0_FUN_0040d0a0.md`
- Annotated: `docs/reconstruction/raw/aa_0040d0a0_FUN_0040d0a0.annotated.md`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_0040d0a0.cpp`
- Clean (named): `docs/reconstruction/reconstructed-exact/Math_AcosClamped.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d0a0_Math_AcosClamped.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d0a0_Math_AcosClamped.md`

## Callers / callees

- **Callees:** `_CIacos` @ `0x006a3e26`
- **Callers (10 funcs / 17 sites):** `CVOGPlayerVehicle_UpdateTurretAiming`, `FUN_004f8430`, `FUN_004e9aa0`, `FUN_004c7bd0`, `FUN_005f0210`, `FUN_008352d0`, `FUN_0084b890`, `UI_BuildItemTooltipStats`, `FUN_00864740`, `FUN_0091a5f0` (+ site `0x008831ca`)

## Sealed facts

| Fact | Level |
|---|---|
| `|x| < 1` → `_CIacos` | **Sealed** |
| `|x| ≥ 1` && `x > 0` → `0` | **Sealed** |
| `|x| ≥ 1` && `x ≤ 0` → `π` | **Sealed** |
| Radians (not degrees) | **Sealed** |
| `__cdecl` float in / ST0 out | **Sealed** |
| Threshold / π constant bytes | **Sealed** (`read_memory`) |

## Gaps

| Gap | Status |
|---|---|
| Product / PDB name | Open (inferred `Math_AcosClamped`) |
| NaN / −0 edges | Open (static only) |
| Caller angle formulas | Out of OWN VA |
| Runtime / differential harness | Open / deferred |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + body bytes | **Sealed / High** |
| Parameter semantic (`x` = cos-domain scalar, often unit-dot) | **High** (callers) / **Probable** product |
| Canonical English name | **Tentative** |
