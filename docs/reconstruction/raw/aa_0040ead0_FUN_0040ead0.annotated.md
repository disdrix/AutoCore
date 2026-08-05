# Annotated low-level: D3dFormat_GetBitsPerPixel_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0040ead0` |
| VA | `0x0040ead0` |
| Canonical name | `D3dFormat_GetBitsPerPixel_Inferred` (**Inferred**) |
| Ghidra | `FUN_0040ead0` |
| System | Graphics / D3D format utility |
| Date | 2026-08-04 (W38-T) |
| Body | jump-table leaf; extent through index @ `0x0040eb90` (**193 B**) |

## Machine-level notes

- MSVC switch → subtract `0x14`, range-check `0x60`, byte index table, dword jump table of 7 return stubs.
- Returns **bits per pixel**, not bytes. Callers convert with **`shr eax, 3`** then multiply width×height×(mips).
- `__cdecl` (plain `ret`; callers `add esp,4`).
- Leaf: no callees.
- Unknown / unsupported formats return **0** (callers often treat as skip/fail).

## Annotated map

```c
// __cdecl uint32_t D3dFormat_GetBitsPerPixel_Inferred(uint32_t d3d_format)
uint32_t D3dFormat_GetBitsPerPixel_Inferred(uint32_t fmt)
{
  switch (fmt) {
  case 0x14:             return 24;   // D3DFMT_R8G8B8
  case 0x15: case 0x16:
  case 0x23: case 0x70:
  case 0x72:             return 32;
  case 0x17: case 0x19:
  case 0x1a: case 0x33:
  case 0x6f:             return 16;
  case 0x1c: case 0x32:  return 8;
  case 0x24: case 0x71:
  case 0x73:             return 64;
  case 0x74:             return 128;
  default:               return 0;
  }
}
```

## Open residual

- Product English for extended formats `0x6f`–`0x74` (may be D3D9 FOURCC-adjacent or engine-private).
- Full surface-size formula lives in callers (not this leaf).
- Runtime / bit-exact / differential.
