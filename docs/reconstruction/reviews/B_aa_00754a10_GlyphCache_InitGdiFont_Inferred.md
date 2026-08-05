# Review B (skeptical / adversarial): `aa_00754a10` GlyphCache_InitGdiFont_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754a10` |
| **VA** | `0x00754a10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00754a10_GlyphCache_InitGdiFont_Inferred.md` |
| **Evidence** | Live decompile + body/epilogue `read_memory` + factory call-site bytes + W35-H ctor layout + W37-AE get-or-create dual |
| **Agent** | W38-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `__thiscall` means ECX is C++ this | Stores use **ESI**; ECX is style; caller `MOV ESI,EDI` + `MOV ECX,EBP` | **Falsified thiscall-this** — ESI this |
| 2 | Returns BOOL true/false only | Fail is `0xFFFFFFFF`; success `0`; caller uses `JGE` | **Sealed signed 0/-1** |
| 3 | Always uses ClearType quality 5 | Height `< 0xE` forces quality **3** | **Falsified always-5** |
| 4 | Bold weight is 700 via constant only | Formula `(-(bit0!=0)&300)+400` → 400/700 | **Sealed** |
| 5 | Host is not GlyphCache | Size `0xB8`, ctor W35-H, factory W37-AE, GDI slots match | **Falsified not-GlyphCache** |
| 6 | Arial is only supported face | Factory tries requested face first; Arial is fallback | **Falsified Arial-only** (caller) |
| 7 | Scaffold `Named_gfxFontImpl_*` is method plate | Path residue only | **Rejected as product method** |
| 8 | Product English method name sealed | Path + structural name only | **Accepted gap** |
| 9 | Creates texture here | Only GDI DIB + HFONT/HDC; texture string is ctor-adjacent fail path elsewhere | **Falsified texture-here** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| GDI open + metrics + DIB role | **Confirmed** | Wrong font port |
| ESI this + ECX style + RET 8 | **Confirmed** | Caller ABI break |
| Style bits + shadow/outline pad | **Confirmed** | Wrong cell sizes |
| Product path gfxFontImpl | **Confirmed** | Doc-only if wrong |
| Method English plate | **Open** | Doc-only |
| `DAT_00d1a548` / device caps English | **Open** | Cap mis-port |
| Runtime | **Open** | — |

---

## 3. Cross-check vs factory caller

`FUN_0073bc50` miss path (sites `0x0073bd22`, `0x0073bd33`):

```text
MOV ESI, EDI          ; GlyphCache* from new+placement ctor
MOV ECX, EBP          ; style
PUSH height / face    ; order per site
CALL FUN_00754a10
TEST EAX, EAX
JGE success           ; >=0
… push "Arial"; CALL again
```

Matches ESI this, ECX style, RET 8, 0/-1 return. Arial string @ `0x00aa267c`.

---

## 4. Byte anchors

```text
0x00754a10: 6A FF … 81 EC C8 01 00 00  … 8B D9
            style bit tests → operator+= "|Bold"/… 
            CreateFontIndirectA / CreateCompatibleDC / GetTextMetricsW
            CreateDIBSection biBitCount=0x20 biHeight=-cellH
            81 C4 D4 01 00 00 C2 08 00
```

Weight: `AND 300` after `-1` mask + `ADD 400` → 400/700.

---

## 5. What would reverse the seal?

- Proof ESI is not this (contradicted by `+0xA4/+0xA8/+0xA0` stores and factory `MOV ESI,EDI`).
- Proof `RET 0xC` three-stack-arg thiscall (contradicted by `C2 08 00` and two factory stack pushes).
- Proof success returns non-zero true (contradicted by `XOR EAX,EAX` success path and `JGE`).

None observed. Remaining gaps are unowned globals and product method English — do not overturn CF/ABI seal.
