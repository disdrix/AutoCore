# Review A (reconstruction fidelity): `aa_007227e0` Audio_LinearGainToMilliBels

| Field | Value |
|---|---|
| **Stable ID** | `aa_007227e0` |
| **VA** | `0x007227e0`–`0x00722821` |
| **Canonical name** | `Audio_LinearGainToMilliBels` (Ghidra `FUN_007227e0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A, W18-M) |
| **Counterpart** | `reviews/B_aa_007227e0_Audio_LinearGainToMilliBels.md` |
| **System** | audio / interface sound |
| **Verdict** | **accept-with-gaps** — CF + log math sealed; studio symbol + field English open |

---

## 1. Purpose

Leaf **linear gain → millibel** converter. Input float gain `x`; output x87 ST0:

| Input | Output |
|---|---|
| `x <= 0` | `−10000.f` (`DAT_00aaa5d8`) |
| `x >= 1` | `0.f` (`g_flZero`) |
| `0 < x < 1` | `2000 * log10(x)` via `FLDLG2`/`FYL2X`/`FMUL −2000.0` |

Callers store into sound/voice `float` fields (commonly `+0x1b0`) after `FSTP`, or convert via `FISTP` for integer paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007227e0_FUN_007227e0.md` |
| Annotated | `docs/reconstruction/raw/aa_007227e0_FUN_007227e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007227e0.cpp` / `Audio_LinearGainToMilliBels.cpp` |
| Function record | `docs/reconstruction/functions/aa_007227e0_FUN_007227e0.md` |
| Live Ghidra | `decompile_function` + `force_decompile` `0x007227e0` (**identical text**) |
| | `read_memory` 128 B @ `0x007227e0`; constants @ `0x00aaa5d0`/`0x00aaa5d8`/`0x00a0f2a0`/`0x00a0f518` |
| | `get_function_pcode` basic |
| | `analyze_function_complete` (22 xrefs, leaf; mnemonics include `FLDLG2`/`FYL2X`) |
| | `get_assembly_context` sample call sites |
| Tools avoided | `disassemble_bytes` (policy) |

**Dual A/B decompile agreement (text):** identical, but **both wrong on main expression** — sealed from FPU mnemonics + constant bytes instead.

---

## 3. Signature

```c
// __stdcall; float on stack; RET 4; return ST0
long double __stdcall Audio_LinearGainToMilliBels(float linearGain);
```

| Item | Evidence |
|---|---|
| Convention | `RET 4` in body hex; stack arg `MOVSS XMM0,[ESP+4]` |
| Return | ST0; callers `FSTP` / `FISTP` |
| Body range | `0x007227e0`–`0x00722821` (~66 B); `CC` pad follows |
| Callees | none |

---

## 4. Control flow (sealed)

```
x = arg0
if (x <= 0) return -10000.f
if (x >= 1) return 0.f
// FPU: 1/x ; FLDLG2 ; FXCH ; FYL2X ; FMUL -2000.0
return 2000 * log10(x)
```

---

## 5. Machine bytes (`read_memory` @ `0x007227e0`)

```
0F 57 C9                XORPS XMM1,XMM1
F3 0F 10 44 24 04       MOVSS XMM0,[ESP+4]
0F 2F C8                COMISS XMM1,XMM0
72 09                   JC +9
D9 05 D8 A5 AA 00       FLD dword [DAT_00aaa5d8]
C2 04 00                RET 4
0F 2F 05 A0 F2 A0 00    COMISS XMM0,[g_flOne]
72 09                   JC +9
D9 05 18 F5 A0 00       FLD dword [g_flZero]
C2 04 00                RET 4
D9 05 A0 F2 A0 00       FLD dword [g_flOne]
D8 74 24 04             FDIV dword [ESP+4]
D9 EC                   FLDLG2
D9 C9                   FXCH
D9 F1                   FYL2X
DC 0D D0 A5 AA 00       FMUL qword [_DAT_00aaa5d0]
C2 04 00                RET 4
```

Constants: `_DAT_00aaa5d0 = −2000.0` (double), `DAT_00aaa5d8 = −10000.f`.

---

## 6. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| Clamp CF | **High** | bytes + dual decompile |
| Log vs linear main path | **High** | `FLDLG2`/`FYL2X` mnemonics; decompiler rejected |
| Scale −2000 / floor −10000 | **High** | `read_memory` |
| Millibel identity | **High** math / **Tentative** product label |
| Studio symbol | **Tentative** | inferred only |
| `+0x1b0` field English | **Tentative** | caller pattern only |

---

## 7. Gaps (non-blocking for CF seal)

1. Official studio name.
2. Product name of destination field `+0x1b0`.
3. Runtime capture of ST0 for known inputs (0.1 → −2000, 0.5 → ≈−602.06).
4. Whether any path relies on decompiler-linear bug (must not).

---

## 8. AutoCore impact

- Do **not** port decompiler formula `0.30103*(1/x)*k`.
- Port clamps + `2000*log10(x)` (or equivalent FPU sequence).
- Interface-sound / voice gain paths should treat unit as **millibels** (0.01 dB amplitude).
