# Function record: StdVector_Resize_Elem8_ViaInsertN_00438d80

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438040` |
| **Canonical name** | `StdVector_Resize_Elem8_ViaInsertN_00438d80` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00438040` |
| **Address** | `0x00438040` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / container utility (8-byte element vectors) |
| **Completion status** | **Dual sealed (A+B)** — W38-G 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_gfxBody_00438040` (**reject** as product).
- Ghidra: `FUN_00438040`.
- Structural: `StdVector_Resize_Elem8_ViaInsertN_00438d80`.

## Purpose

Resize MSVC-style vector of 8-byte elements. Grow via insert-N `FUN_00438d80`; shrink via erase-range `FUN_00438d00` (non-POD element destroy). By-value 8-byte fill with optional control-block release on exit.

## Signature (machine-sealed)

```c
void __fastcall StdVector_Resize_Elem8_ViaInsertN_00438d80(
    uint32_t newCount, // ECX
    void *vec,         // EDX
    /* 8-byte fill on stack */
);
// ret 8; body 171 B @ 0x00438040-0x004380EA
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00438040_FUN_00438040.md`
- Annotated: `docs/reconstruction/raw/aa_00438040_FUN_00438040.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem8_ViaInsertN_00438d80.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00438040.cpp`
- Function (FUN_*): `docs/reconstruction/functions/aa_00438040_FUN_00438040.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00438040_StdVector_Resize_Elem8_ViaInsertN_00438d80.md`, `B_aa_00438040_...`
- Report: `docs/agents/task-dual-ab-00438040-004382c0-w38g-report.md`

## Callers / callees

| Direction | VA | Role |
|---|---|---|
| Callee | `0x00438d80` | Grow insert-N |
| Callee | `0x00438d00` | Shrink erase-range |
| Caller | `0x00437ce0`, `0x00765740` | Wrapper / host`+0x128` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / stride 8 | **Confirmed** |
| Product element type | **Open** |
