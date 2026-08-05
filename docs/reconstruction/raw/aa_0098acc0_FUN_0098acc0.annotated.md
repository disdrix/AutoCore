# Annotated low-level: FUN_0098acc0 (scaffold; see named)

| Field | Value |
|---|---|
| Stable ID | `aa_0098acc0` |
| VA | `0x0098acc0` |
| Canonical name | `NDAssetImage_FlipHorizontal` (supersedes scaffold label) |
| System | client assets / `NDAssetImage` |
| Date | 2026-07-29 W20-L |

## Machine-level notes

- See `aa_0098acc0_NDAssetImage_FlipHorizontal.annotated.md` for full W20-L seal.
- Scaffold body retained for ID continuity; live decompile ≡ 2026-07-23 raw.

## Pseudocode (annotated copy of raw)

```c
// this in EDI — NDAssetImage_FlipHorizontal
undefined4 FUN_0098acc0(void)
{
  // gate this+4; operator_new(0x1b8); vtbl 00a9bcac;
  // bpp-aware reverse-copy this+0x34 → temp+0x34;
  // FUN_00433390; FUN_00432580(this); delete temp; return 1/0
}
```

## Open questions

- (Closed by W20-L) Calling convention: this in EDI; AL return.
- (Closed by W20-L) Role: horizontal flip for TGA bit4; sibling of FlipVertical.
