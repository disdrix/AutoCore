# Function record: Math_Vec3Length_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d020` |
| **Canonical name** | `Math_Vec3Length_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_0040d020` |
| **Address** | `0x0040d020` |
| **Body range** | `0x0040d020` – `0x0040d03e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation (partition) / shared pure math |
| **Completion status** | **Partial** — dual A/B sealed 2026-08-05 MEGA-137 (CF + ABI + xrefs); product name open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Pure Euclidean **3-float length** leaf: `sqrt(x*x + y*y + z*z)` via x87 `FSQRT`. No scale, no normalize, no globals.

## Signature (sealed)

```c
// __cdecl; float args @ [esp+4], [esp+8], [esp+0xc]; return length in ST0 (float10 / x87)
float Math_Vec3Length_Inferred(float x, float y, float z);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d020_FUN_0040d020.md`
- Annotated: `docs/reconstruction/raw/aa_0040d020_FUN_0040d020.annotated.md`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_0040d020.cpp`
- Clean (named): `docs/reconstruction/reconstructed-exact/Math_Vec3Length_Inferred.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_InteractClickPickTarget_0040d020.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d020_Math_Vec3Length_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d020_Math_Vec3Length_Inferred.md`

## Callers / callees

- **Callees:** none (`FSQRT` instruction)
- **Callers (2 funcs / 3 sites):**
  - `Client_InteractClickPickTarget` @ `0x009249c0`, `0x00924c76` — pick hit−camera distance; caller multiplies by `_DAT_00aaacbc` (**0.015f**)
  - `FUN_005ba440` @ `0x005bad63` — path/segment node delta length

## Sealed facts

| Fact | Level |
|---|---|
| `sqrt(x²+y²+z²)` formula | **Sealed** |
| Leaf / no callees | **Sealed** |
| `__cdecl` three floats in / ST0 out | **Sealed** |
| Body 31 B through `RET` | **Sealed** |
| 3 UNCONDITIONAL_CALL xrefs | **Sealed** |
| Scale **not** in body | **Sealed** |

## Gaps

| Gap | Status |
|---|---|
| Product / PDB name | Open (inferred `Math_Vec3Length_Inferred`) |
| NaN / −0 edges | Open (static only) |
| `FUN_005ba440` product English | Out of OWN VA |
| Runtime / differential harness | Open / deferred |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + body bytes | **Sealed / High** |
| Parameter semantic (`x,y,z` components of a delta) | **High** (callers) |
| Canonical English name | **Tentative** |
