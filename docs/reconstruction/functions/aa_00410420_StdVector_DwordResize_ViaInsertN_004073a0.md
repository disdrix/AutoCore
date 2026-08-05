# Function record: StdVector_DwordResize_ViaInsertN_004073a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_00410420` |
| **Canonical name** | `StdVector_DwordResize_ViaInsertN_004073a0` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00410420` |
| **Address** | `0x00410420` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / container utility (multi-domain dword vectors) |
| **Completion status** | **Dual sealed (A+B)** — W37-T 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_gfxGeometryPiece_00410420` (**reject** as product).
- Structural: `StdVector_DwordResize_ViaInsertN_004073a0` — resize dword vector; grow via `FUN_004073a0`, shrink via `FUN_00410490`.
- Twin: `StdVector_DwordResize` / `FUN_004367f0` (grow via `FUN_004507a0`).

## Purpose

Resize MSVC-style `vector<uint32_t>`-shaped object (`begin@+4`, `end@+8`):

1. **Grow** if `size < newCount`: insert-N filled dwords at end (`FUN_004073a0`).
2. **Shrink** if `newCount < size`: erase range (`FUN_00410490` memmove; no element dtors).
3. **Equal**: no-op.

## Signature (machine-sealed)

```c
void __thiscall FUN_00410420(
    void *this,        // ECX; begin@+4, end@+8
    uint32_t newCount, // stack+4
    uint32_t fillValue // stack+8
);
// ret 8
// body 0x00410420–0x00410488 (105 B)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00410420_FUN_00410420.md`
- Annotated: `docs/reconstruction/raw/aa_00410420_FUN_00410420.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_DwordResize_ViaInsertN_004073a0.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00410420.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md`
- Review B: `docs/reconstruction/reviews/B_aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md`
- Report: `docs/agents/task-dual-ab-00410420-004bfd10-w37t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x004073a0` | Grow insert-N dword |
| Callee | `0x00410490` | `StdVector_EraseRange_Dword_Inferred` (W16-S) |
| Twin | `0x004367f0` | Same resize CF; grow via `004507a0` |
| Callers | 21 funcs / 30 sites | Multi-domain (clear/resize); e.g. `004bbeb0`, `00496410`, `005e7600`, … |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live | **Confirmed** |
| Element width dword (`>>2` / `*4`) | **Confirmed** |
| `__thiscall` + `ret 8` | **Confirmed** |
| Grow `004073a0` / shrink `00410490` | **Confirmed** |
| Role = dword vector resize | **Confirmed** |
| Product / PDB name | **Open** |
