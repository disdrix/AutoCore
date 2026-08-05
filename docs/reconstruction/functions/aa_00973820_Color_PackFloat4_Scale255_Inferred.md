# Function record: Color_PackFloat4_Scale255_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973820` |
| **Canonical name** | `Color_PackFloat4_Scale255_Inferred` |
| **Ghidra name** | `FUN_00973820` |
| **Address** | `0x00973820`–`0x00973872` (83 B / `0x53`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client color pack utility |
| **Wave** | W28-E OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

```
dest_bytes = PackClamp(src[0]*255, src[1]*255, src[2]*255, src[3]*255)
```

Thin wrapper: multiply float4 by `DAT_00aaa6f8` (**255.0f**), call `FUN_00973590` to clamp+ROUND into the ECX destination buffer.

## ABI

| Item | Value |
|---|---|
| ECX | `uint8_t *dest` (packed 4-byte color) |
| Stack | `const float *src` (float4) |
| Epilogue | **`ret 4`** (`C2 04 00`) |
| Return | void |

## Constant

| Symbol | VA | Bytes | Value |
|---|---|---|---|
| `DAT_00aaa6f8` | `0x00aaa6f8` | `00 00 7F 43` | **255.0f** |

## Call graph

| | |
|---|---|
| Callers | `FUN_004b18f0`, `FUN_005b36f0`, `FUN_005e1fc0`, `FUN_008e4430` (9 code xrefs) |
| Callees | `FUN_00973590` |

## Gaps

1. Product / PDB symbol.
2. Full dual of nested `FUN_00973590` (channel map known from its decompile).
3. Runtime / bit-exact.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00973820_FUN_00973820.md` |
| Annotated | `docs/reconstruction/raw/aa_00973820_FUN_00973820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_PackFloat4_Scale255_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00973820.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_00973820_FUN_00973820.md` |
| A | `docs/reconstruction/reviews/A_aa_00973820_Color_PackFloat4_Scale255_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_00973820_Color_PackFloat4_Scale255_Inferred.md` |
| Report | `docs/agents/task-dual-ab-004b2910-00973820-w28e-report.md` |
