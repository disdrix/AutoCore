# Function record: Color_ClampRoundPackBGRA_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973590` |
| **Canonical name** | `Color_ClampRoundPackBGRA_Inferred` |
| **Ghidra name** | `FUN_00973590` |
| **Address** | `0x00973590`–`0x00973680` (240 B / `0xF0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client color pack utility |
| **Wave** | W29-I OWN-ONLY dual |
| **Verdict** | **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

```
dest_BGRA = {
  clamp_u8(ROUND(f0)),  // → dest[2]  (R if args are RGBA)
  clamp_u8(ROUND(f1)),  // → dest[1]  (G)
  clamp_u8(ROUND(f2)),  // → dest[0]  (B)
  clamp_u8(ROUND(f3))   // → dest[3]  (A)
}
```

Leaf clamp+ROUND packer used by scale-255 wrapper (`00973820`), packed ARGB lerp (`00973690`), difficulty colors, serializers, etc.

## ABI

| Item | Value |
|---|---|
| EAX | `uint8_t *dest` (packed 4-byte color) |
| Stack | `float f0, f1, f2, f3` |
| Epilogue | `add esp, 0xC`; **`ret 0x10`** (`C2 10 00`) |
| Return | void |
| Class | **leaf** |

## Call graph

| | |
|---|---|
| Callers | `FUN_00973820`, `FUN_00973690`, `FUN_00973770`, `FUN_00973880`, `FUN_008e4430`, `FUN_00923c50`, `FUN_0073d200` (×5), + more (**20** code xrefs) |
| Callees | none |

## Gaps

1. Product / PDB symbol.
2. Runtime / bit-exact (ROUND edge cases).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00973590_FUN_00973590.md` |
| Annotated | `docs/reconstruction/raw/aa_00973590_FUN_00973590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_ClampRoundPackBGRA_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00973590.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_00973590_FUN_00973590.md` |
| A | `docs/reconstruction/reviews/A_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00973590-005b36f0-w29i-report.md` |
