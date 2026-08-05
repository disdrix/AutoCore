# Review B (skeptical / adversarial): `aa_007227e0` Audio_LinearGainToMilliBels

| Field | Value |
|---|---|
| **Stable ID** | `aa_007227e0` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B, W18-M) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007227e0_Audio_LinearGainToMilliBels.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Decompiler main path is bit-exact | Bytes: `FLDLG2`+`FYL2X`, not multiply-by-(1/x) alone | **Falsified** — decompiler linear; seal log |
| 2 | Pcode FLOAT_MULT of log10(2)×(1/x) is hardware truth | Pcode models FYL2X poorly; mnemonic listing wins | **Clarify** — trust FPU ops |
| 3 | Scale is −2000 millibel / dB-ish | `read_memory` double `0xc09f400000000000` = −2000.0; identity `2000*log10` = millibel amp | **Sealed** math; product word **Tentative** |
| 4 | `__cdecl` / no stack clean | `RET 4` thrice | **Falsified** — stdcall |
| 5 | Return in EAX | Callers `FSTP` ST0 | **Falsified** — x87 return |
| 6 | Dual decompiles disagree | force ≡ decompile | **No text conflict**; both wrong on expr |
| 7 | Has callees | analyze complete: leaf | **Sealed** leaf |
| 8 | Name is studio-official | No string/RTTI in body | **Tentative** inferred only |
| 9 | Floor −10000 is power-dB not amp | Same constant serves both if mislabeled; math is 2000×log10 (amp millibel) | **Gap** on product English only |
| 10 | `x>1` should grow positive | Body returns 0 for `x>=1` | **Sealed** clamp |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Log formula | **High** | Wrong volume curves / silent audio bugs |
| Clamps | **High** | Unbounded logs / wrong mute floor |
| Stdcall | **High** | Stack imbalance |
| Millibel label | **Medium** | Doc confusion; numeric port still OK |
| Inferred name | **Medium** | Rename churn |
| `+0x1b0` meaning | **Low–Medium** | Mis-map server/client gain fields |

---

## 3. Cross-check: decompile vs bytes vs pcode

| Step | Decompile | Bytes / mnemonics |
|---|---|---|
| Load x | stack float | `MOVSS [ESP+4]` |
| x<=0 | yes | `COMISS 0,x` / `JC` skip / `FLD -10000` / `RET 4` |
| x>=1 | yes | `COMISS x,1` / `JC` calc / `FLD 0` / `RET 4` |
| Main | `0.30103*(1/x)*(-2000)` **linear** | `FDIV`; **`FLDLG2`**; **`FYL2X`**; `FMUL -2000` **log** |
| Return | float10 | ST0 |

**Consensus:** accept CF with **decompiler main expression rejected**. Gaps remain on English only.

---

## 4. Surviving contract for AutoCore

```csharp
// Linear amplitude gain -> millibels (0.01 dB amp).
// x<=0 => -10000; x>=1 => 0; else 2000*log10(x).
static float Audio_LinearGainToMilliBels(float x)
{
    if (x <= 0f) return -10000f;
    if (x >= 1f) return 0f;
    return 2000f * MathF.Log10(x);
}
// Callers: store float; some integerize via FISTP.
```

**Port traps to reject:**

- Using decompiler `0.30103 * (1/x) * k` (wildly wrong, e.g. x=0.1 → −6020 vs −2000).
- Assuming return in EAX.
- Omitting `RET 4` / stdcall when hooking.
- Treating clamp floor as 0 or −∞.

---

## 5. Residual questions

1. Official symbol / source file for this helper?
2. Exact semantic of object `+0x1b0` (gain, attenuation, fade target)?
3. Any caller intentionally passes `x>1` expecting saturation at 0?
