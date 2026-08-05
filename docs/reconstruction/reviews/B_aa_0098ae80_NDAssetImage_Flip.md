# Review B (skeptical / adversarial): `aa_0098ae80` NDAssetImage_Flip

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098ae80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-K) |
| **Counterpart** | `reviews/A_aa_0098ae80_NDAssetImage_Flip.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x0098ae80` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `NDAssetImage_FlipVertical` (`0x004332e0`) | This unit allocates temp, row-copies DIB `+0x34`, then calls FlipVertical, then transfer | **Falsified identity** — broader flip |
| 2 | cdecl / plain RET | epilogue `C2 04 00` | **Falsified** — **ret 4** |
| 3 | In-place only, no allocation | `new(0x1b8)` + dtor | **Falsified** |
| 4 | Always succeeds | null DIB / OOM / null temp DIB → 0 | **Falsified** |
| 5 | General image utility with many callers | single xref from BMP top-down path | **Narrowed** — specialized caller |
| 6 | Row buffer is `+0x1b0` | loop uses `+0x30/+0x34`; FlipVertical handles `+0x1b0` | **Falsified single-buffer** |
| 7 | Three-rep diverges | live ≡ raw ≡ bytes | **Falsified** |
| 8 | PDB name proven | no direct symbol string on this VA | **Open English** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 + image* stack arg | **High** | stack corruption |
| Temp 0x1b8 + vtbl | **High** | wrong type / leak |
| pitch/pBits/height row reverse | **High** | upside-down wrong axis |
| Transfer then dtor order | **High** | double-free / leak |
| Top-down BMP caller role | **High** | wrong trigger |
| Product `CxImage::Flip` English | **Probable** | doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if image+4==0 return 0
  temp = new(0x1b8); vtbl; ctor; copy(...,1)
  if temp+4==0 return 0
  row reverse pBits pitch height
  FlipVertical; Transfer; dtor(1); return 1

bytes:
  68 B8 01 00 00     push 0x1b8
  C7 03 AC BC A9 00  vtbl PTR_FUN_00a9bcac
  F3 A5 / F3 A4      REP MOVSD/B
  B0 01 … C2 04 00   success ret 4
  32 C0 … C2 04 00   fail ret 4
```

**No conflict** on owned CF. Not a synonym of FlipVertical-only.

---

## 4. Surviving contract for AutoCore

```csharp
// NDAssetImage_Flip @ 0x0098ae80
// retail: stack image*, ret 4, AL 0/1

bool Flip(NDAssetImage img)
{
  // Must flip DIB bits (+0x34/pitch) AND info buffer (+0x1b0).
  // Do not implement as FlipVertical-only.
  // Preserve fail on null DIB / OOM.
}
```

---

## 5. Residual risks

1. If `NDAssetImage_FlipVertical` returns 0, this unit still transfers and returns 1 — possible partial flip (sibling residual).
2. Copy helper may share/shallow-copy edge fields — Create path evidence says temp gets own DIB via Create inside copy; not re-proven here beyond decompile.
3. No runtime hit confirmation in this dual.
