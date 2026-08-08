# Function record: Rng_SampleUnitFloat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4170` |
| **Canonical name** | `Rng_SampleUnitFloat_Inferred` |
| **Address** | `0x007a4170`–`0x007a41d4` exclusive |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed 2026-08-04 WQ9D-F** — trio + A/B; accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

| Name | Role |
|---|---|
| `FUN_007a4170` | Ghidra / scaffold |
| `Named_CalleeOf_CVOGReaction_Dispatch_007a4170` | legacy scaffold (superseded) |
| `Rng_SampleUnitFloat_Inferred` | dual preferred |

## Purpose

Sample one unit float from global RNG ushort table (`RngHost+0x08` base, `+0x0C` cursor). Sequential when signed index < 0 (advance cursor); indexed otherwise (mask wrap, no advance). Scale `DAT_00aaa638` ≈ 1/65535.

## Signature

```c
float __thiscall Rng_SampleUnitFloat_Inferred(RngHost* this, uint32_t index); // ret 4; ST0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007a4170_FUN_007a4170.md`
- Annotated: `docs/reconstruction/raw/aa_007a4170_FUN_007a4170.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Rng_SampleUnitFloat_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_007a4170.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_007a4170_Rng_SampleUnitFloat_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_007a4170_Rng_SampleUnitFloat_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_007a4170.md`

## Callers / callees

**Callers:** `FUN_00508a00` @ `0x00508a31`; second site `0x0057ed44`. Typical: getter `CVOGReaction_RandomUnitScalar` → `mov ecx,eax` → this.

**Callees:** none (leaf).

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI | **Confirmed** |
| Scale constant | **Confirmed** |
| Host layout shared with CopyWindow | **Confirmed** |
| Product name | **Inferred** |
