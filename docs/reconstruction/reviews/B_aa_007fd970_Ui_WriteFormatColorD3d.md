# Review B (skeptical / adversarial): `aa_007fd970` Ui_WriteFormatColorD3d

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fd970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W22-F) |
| **Counterpart** | `reviews/A_aa_007fd970_Ui_WriteFormatColorD3d.md` |
| **Scratch** | `tmp/a_007fd970.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Plain `__fastcall` with only CL formal | **Partial** — decomp shows CL; EAX out is phantom but required; callers confirm both |
| 2 | RGBA byte order (R first) | **Falsified** — cases 100/101/102 are pure R/G/B only if LE D3DCOLOR `[B,G,R,A]` |
| 3 | Has callees / non-leaf | **Falsified** — leaf |
| 4 | Index 5..99 have special colors | **Falsified** — index table maps all to default (8) |
| 5 | Returns void / color by value in EAX | **Overstated decomp void** — EAX is out ptr; some callers deref, some pass ptr into draw |
| 6 | Format indices product-named | **Unproven** — constants sealed; names Tentative |
| 7 | Only map UI uses it | **Falsified** — scores, event dispatch, tracked lists |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Switch / JT / idx table | **High** | Wrong colors |
| Case constants | **High** | Wrong palette |
| ABI CL + EAX out | **High** | Corrupt stack color / wrong buffer |
| D3DCOLOR channel order | **High** | Red/blue swap |
| Index product English | **Tentative** | Docs only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
MOVSX ECX, CL
CMP ECX, 0x66
JA default
MOVZX ECX, byte [ECX+0x7fda3c]
JMP [ECX*4+0x7fda18]
; each case: MOV byte [EAX+i], imm; RET
```

Caller seal:

- `UiHost_RefreshTrackedNodeWidgets`: CL from `*(u8*)(node+0x1c)-0x0f` then call (bytes refine decomp).
- Arena scores: write `*FUN_007fd970()` into color array for `FUN_00891b60`.

Live decompile ≡ raw. Clean plate carries full case table.

---

## 4. Surviving contract for AutoCore

```
// Client UI color LUT only — not server-authoritative
out = Ui_WriteFormatColorD3d(formatIndex, outBuf4);
// outBuf4 is D3DCOLOR little-endian AARRGGBB
// indices 0..4 = UI palette; 100/101/102 = pure R/G/B; else white
// never invent server-side color from this table without matching client
```

---

## 5. Verdict

All adversarial attacks on CF/ABI/channel order fail or refine without contradiction. Product English residual only → **accept**.
