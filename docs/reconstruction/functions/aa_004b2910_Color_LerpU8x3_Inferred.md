# Function record: Color_LerpU8x3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b2910` |
| **Canonical name** | `Color_LerpU8x3_Inferred` |
| **Ghidra name** | `FUN_004b2910` |
| **Address** | `0x004b2910`–`0x004b29cd` (190 B / `0xBE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client color / object-motion stage params |
| **Wave** | W28-E OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Lerp **exactly three** U8 channels with ROUND:

```
out[2] = from[2] + ROUND((to[2]-from[2]) * t)
out[1] = from[1] + ROUND((to[1]-from[1]) * t)
out[0] = from[0] + ROUND((to[0]-from[0]) * t)
```

No fourth (alpha) channel. Leaf. Sole caller is sealed `ObjectMotion_ApplyStageParams_Inferred`.

## ABI

| Item | Value |
|---|---|
| Convention | **cdecl** |
| Args | `float t`, `uint8_t* out`, `const uint8_t* from`, `const uint8_t* to` |
| Epilogue | plain **`RET`** (`C3`) |
| Return | void |

## Call graph

| | |
|---|---|
| Callers | `FUN_004b2b90` ×3 (`0x004b2df5`, `0x004b2e52`, `0x004b313d`) |
| Callees | none (ROUND intrinsic) |

## Call-site roles (from ApplyStageParams)

| Site | Role |
|---|---|
| dirty, stage `+0x3e2` bit1 | RNG unit × `DAT_00aaa638` → random color between stage endpoints → `slot+0xd` |
| dirty, stage `+0x3e2` bit2 | same pattern → `slot+0x47` |
| continuous, stage `+0x3e1` bit5 | progress `1−rem/total` → lerp baseline `slot+0x2a` → end `slot+0x47` into `slot+0xd` |

## Gaps

1. Product / PDB symbol.
2. Field English for the three-byte color slots on stage/slot.
3. Runtime golden / bit-exact.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004b2910_FUN_004b2910.md` |
| Annotated | `docs/reconstruction/raw/aa_004b2910_FUN_004b2910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_LerpU8x3_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004b2910.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_004b2910_FUN_004b2910.md` |
| A | `docs/reconstruction/reviews/A_aa_004b2910_Color_LerpU8x3_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_004b2910_Color_LerpU8x3_Inferred.md` |
| Report | `docs/agents/task-dual-ab-004b2910-00973820-w28e-report.md` |
