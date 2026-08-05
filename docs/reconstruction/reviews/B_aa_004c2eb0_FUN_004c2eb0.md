# Review B (skeptical / adversarial): `aa_004c2eb0` FUN_004c2eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2eb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c2eb0_FUN_004c2eb0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Writes skill / summon state | Pure float→int | **Falsified** |
| 2 | Exact inverse of `FUN_004c2e60` | 004c2e60 uses `*1/14+2`; this uses `(x-2.5)*14` | **Survives as approximate inverse only** |
| 3 | `__cdecl` with caller-clean | Epilogue **`RET 4`** | **Falsified cdecl** — callee pops 4 |
| 4 | Negative intermediate wraps to huge unsigned | Mask forces **0** when `t < 0` | **Falsified wrap risk** |
| 5 | Multiple independent callers | Single xref: FormatFailure | **Confirmed sole** |
| 6 | Input is always player level | FormatFailure stages via vtbl+0x210 + 004c2e60 results | **Overclaim if asserted** |
| 7 | Threshold 0x50 decided here | Threshold is **caller** after this returns | **Falsified** (caller-owned) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `(x-2.5)*14` trunc + clamp≥0 | **Confirmed** | Wrong “until Level” number |
| RET 4 | **Confirmed** | Stack smash on port |
| Sole FormatFailure use | **Confirmed** | Low |
| Exact intermediate `x` | **Medium** | Wrong L in toast |
| Product name | **Open** | Naming only |

---

## 3. Assembly contract

```
004c2eb0  cvtsi2ss xmm0, dword [esp+4]
          subss    xmm0, dword [0xaaa6c4]   ; 2.5
          mulss    xmm0, dword [0x9cb8dc]   ; 14.0
          xor      ecx, ecx
          cvttss2si eax, xmm0
          test     eax, eax
          setl     cl
          sub      ecx, 1                   ; ecx = 0 if neg else -1
          and      eax, ecx                 ; 0 if neg
          ret      4
```

---

## 4. Surviving contract for AutoCore

```
// FormatFailure 0x10 only:
L = FUN_004c2eb0(x);   // max(0, trunc((x - 2.5) * 14))
if (L > 0x50) short_sprintf; else long_sprintf_with_level(L);
// Not a cast gate. Leave FUN_*.
```

---

## 5. Open questions

1. Seal FormatFailure intermediate that becomes `x` (asm at call site).
2. Document band table that justifies 2.0 vs 2.5 bases.
3. Runtime capture of toast Level N for known summon counts.

**Verdict:** **accept-with-gaps** — math/ABI sealed; intermediate arg Medium.
