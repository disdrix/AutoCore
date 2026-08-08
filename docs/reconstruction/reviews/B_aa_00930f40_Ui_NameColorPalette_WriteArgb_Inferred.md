# Review B (skeptical / adversarial): `aa_00930f40` Ui_NameColorPalette_WriteArgb_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930f40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/colors; product mode English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the full name-color resolver | Body is only switch+stores; no entity/ctx args | **Falsified** — leaf palette |
| 2 | Same unit as `FUN_0092d580` | Different VA; band is float table copy | **Falsified** |
| 3 | MSVC `__fastcall` (ECX,EDX) formals | Out is **EAX**, not EDX; no stack | **Custom ABI** sealed |
| 4 | Mode 1 is explicit case | Jump table maps mode1→default path | **Survives** — default = beige |
| 5 | Always returns red (parent clean often passes 0) | Live sites use 0,1,2,2\|3 | **Falsified as always-0** |
| 6 | Channel order ARGB in memory | Stores B@0 G@1 R@2 A@3 | **BGRA memory / AARRGGBB dword** |
| 7 | Product name without string | No RTTI/string | **`_Inferred` required** |
| 8 | Decompiler `void` ⇒ no return | Callers load `[eax]` after call | **Return=out survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Five color immediates | **High** | Wrong nameplate defaults |
| ECX mode / EAX out | **High** | Wrong call ABI |
| Not level-band | **High** | Mis-merge with 0092d580 |
| Mode English labels | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
00930f40  add ecx, 1
00930f43  cmp ecx, 4
00930f46  ja  default_beige
00930f48  jmp [ecx*4 + 0x00930fa0]
; cases write B,G,R,A then ret
```

Live 2026-08-04 ≡ 2026-07-23 raw decompile.

---

## 4. Surviving contract

```
*outArgb = *Ui_NameColorPalette_WriteArgb(mode, &tmpBgra);
// mode ∈ {-1,0,1,2,3}; unknown → beige (1)
```

Parents must set ECX=mode and EAX=out before call.

**Verdict:** **accept**.
