# Review A (reconstruction fidelity): `aa_0040d0a0` Math_AcosClamped

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d0a0` |
| **VA** | `0x0040d0a0` |
| **Canonical name** | `Math_AcosClamped` (inferred; product symbol unknown) |
| **Ghidra symbol** | `FUN_0040d0a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040d0a0_Math_AcosClamped.md` |
| **System** | `physics` / shared math helper |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Domain-safe inverse cosine: compute `acos(x)` when `|x| < 1`; when `|x| ≥ 1` return the mathematical endpoints **0** (for `x > 0`) or **π** (for `x ≤ 0`) instead of feeding `_CIacos` an out-of-range argument (NaN/domain error).

Classic `clamp` + `acos` leaf used by orientation / angle recovery paths (turret aim, vehicle/creature orientation, UI angle displays).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d0a0_FUN_0040d0a0.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_0040d0a0_FUN_0040d0a0.annotated.md` | Updated |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_0040d0a0.cpp` | Prior |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Math_AcosClamped.cpp` | Written |
| Function record | `docs/reconstruction/functions/aa_0040d0a0_Math_AcosClamped.md` | Written |
| Live decompile | Ghidra MCP `decompile_function` `0x0040d0a0` | **≡ raw** |
| Live body bytes | Ghidra `read_memory` `0x0040d0a0` length 64 | CF sealed |
| `g_flOne` | `read_memory` `0x00a0f2a0` → `00 00 80 3f` = **1.0** | Sealed |
| `DAT_00a27c3c` | `read_memory` `0x00a27c3c` → `db 0f 49 40` = **π** | Sealed |
| Callee | `_CIacos` @ `0x006a3e26` (from `E8` rel at `0x0040d0d9`) | Sealed |
| Callers | Ghidra `get_function_callers` / xrefs (17 sites / 10 funcs) | Inventory |
| Prior art | `physics/verified/fn_upright_restore.md`, `fn_00598650_applyAction.md` | Same π-endpoint pattern for saturated acos |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl`, one `float` stack arg `@[esp+4]` | **High** | `FLD [esp+4]`; plain `ret` (not `ret n`) |
| Return in **ST0** as `float10` / x87 | **High** | Final `FLD` / `_CIacos` leave ST0 |
| Gate: `|x| ≥ 1` → saturated branch; `|x| < 1` → `_CIacos` | **High** | `FABS` + `FCOMIP` vs `g_flOne`; `JC` when `|x| < 1` |
| Saturated `x > 0` → **0.0** | **High** | `XORPS xmm0,xmm0` then store/load |
| Saturated `x ≤ 0` → **π** (`DAT_00a27c3c`) | **High** | `COMISS` + `JA` skip π load when `x > 0` |
| `g_flOne` @ `0x00a0f2a0` = **1.0f** | **Confirmed** | `read_memory` `0000803f` |
| `DAT_00a27c3c` = **π ≈ 3.14159274f** | **Confirmed** | `read_memory` `db0f4940` |
| Interior path is CRT `_CIacos` | **High** | Direct `CALL 0x006a3e26` |
| No side effects / pure function | **High** | Only stack temp rewrite of arg slot on saturate path |
| Name `Math_AcosClamped` product-official | **Tentative** | Behavior sealed; no string/RTTI |
| NaN / −0 edge English | **Tentative** | IEEE path not runtime-probed |
| Bit-for-bit / runtime harness | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| Load `x` from `[esp+4]`; take `|x|` | Yes (`FLD` / `FABS`) |
| Compare `|x|` to `1.0` (`g_flOne`) | Yes (`FLD` / `FXCH` / `FCOMIP` / `FSTP`) |
| If `|x| < 1` → `FLD x; CALL _CIacos; RET` | Yes (`JC` → `0x0040d0d5`) |
| Else saturate: `xmm0=0`; if `x ≤ 0` load π | Yes (`MOVSS` / `XORPS` / `COMISS` / `JA`) |
| Store result over `[esp+4]`; `FLD`; `RET` | Yes |
| No invent asin / atan2 / clamp-to-[-1,1] then always acos | Yes — early-out avoids `_CIacos` on exterior |

### Instruction seal (`read_memory` 2026-07-29)

```text
0040d0a0  D9 44 24 04          FLD   dword [esp+4]        ; x
0040d0a4  D9 E1                FABS                       ; |x|
0040d0a6  D9 05 A0 F2 A0 00    FLD   dword [g_flOne]      ; 1.0 @ 0x00a0f2a0
0040d0ac  D9 C9                FXCH  st(1)                ; ST0=|x|, ST1=1
0040d0ae  DF F1                FCOMIP st, st(1)           ; |x| ? 1
0040d0b0  DD D8                FSTP  st(0)
0040d0b2  72 21                JC    0040d0d5             ; CF ⇒ |x| < 1 → acos
; --- saturated |x| ≥ 1 ---
0040d0b4  F3 0F 10 4C 24 04    MOVSS xmm1, [esp+4]        ; x
0040d0ba  0F 57 C0             XORPS xmm0, xmm0           ; 0.0
0040d0bd  0F 2F C8             COMISS xmm1, xmm0          ; x ? 0
0040d0c0  77 08                JA    0040d0ca             ; x > 0 → keep 0
0040d0c2  F3 0F 10 05 3C 7C A2 00  MOVSS xmm0, [DAT_00a27c3c] ; π
0040d0ca  F3 0F 11 44 24 04    MOVSS [esp+4], xmm0
0040d0d0  D9 44 24 04          FLD   dword [esp+4]
0040d0d4  C3                   RET
; --- interior ---
0040d0d5  D9 44 24 04          FLD   dword [esp+4]
0040d0d9  E8 48 6D 29 00       CALL  _CIacos              ; → 0x006a3e26
0040d0de  C3                   RET
; pad
0040d0df  CC                   INT3
```

Body size **0x3F** bytes (`0x0040d0a0`–`0x0040d0de` inclusive).

Hex (body through second `RET`):
`d9442404d9e1d905a0f2a000d9c9dff1ddd87221f30f104c24040f57c00f2fc87708f30f10053c7ca200f30f11442404d9442404c3d9442404e8486d2900c3`

### Recovered CF

```c
// __cdecl — stack: [esp+4] = x (float); return angle radians in ST0
float Math_AcosClamped(float x)
{
    if (fabsf(x) >= 1.0f) {
        // endpoints of acos on [-1,1]; also maps |x|>1 → {0, π}
        return (x > 0.0f) ? 0.0f : /* DAT_00a27c3c */ 3.14159274f;
    }
    return acosf(x);   // CRT _CIacos
}
```

Note: saturated branch uses `x > 0` → 0 else π, so **`x == 0` never hits saturate** (`|0| < 1`). At `x == ±1` results match `acos(±1)`.

---

## 5. Constants

| Symbol | VA | Bytes | Value | Role |
|---|---|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0f** | Domain threshold `\|x\| ≥ 1` |
| `DAT_00a27c3c` | `0x00a27c3c` | `db 0f 49 40` | **π** | Saturated negative / anti-aligned endpoint |
| (inline) | — | `XORPS` | **0.0f** | Saturated positive endpoint |

Prior art note: upright / airStab paths also use a **π** constant as acos saturated-negative fallback (`DAT_009d54a4` in those units) — same math policy, different DAT site.

---

## 6. Callers (live xrefs, 17 sites / 10 functions)

| Function | VA | Sites (from) | Role (Probable) |
|---|---|---|---|
| `CVOGPlayerVehicle_UpdateTurretAiming` | `0x004f9570` | `0x004f9e14` | Turret aim angle from basis / aim vector |
| `FUN_004f8430` | `0x004f8430` | `0x004f8818`, `0x004f895a` | Related aim / orientation |
| `FUN_004e9aa0` | `0x004e9aa0` | `0x004e9b91` | Orientation / angle helper |
| `FUN_004c7bd0` | `0x004c7bd0` | `0x004c7def` | Creature / object path |
| `FUN_005f0210` | `0x005f0210` | `0x005f0399` | — |
| `FUN_008352d0` | `0x008352d0` | `0x008354aa` | Client path |
| `FUN_0084b890` | `0x0084b890` | `0x0084bf0d` | — |
| `UI_BuildItemTooltipStats` | `0x00847ad0` | `0x0084943e` | UI angle/stat display |
| `FUN_00864740` | `0x00864740` | 5 sites (`0x008648a7`…`0x00864c3b`) | Multi-angle pack |
| `FUN_0091a5f0` | `0x0091a5f0` | `0x0091a6d8`, `0x0091a7b4` | Camera / look residual helper |
| (+ site `0x008831ca`) | — | — | Additional xref |

Scaffold alias `Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0040d0a0` is **caller-centric only** — not sole consumer.

---

## 7. Gaps / open

1. Product / compiler helper name (no string/RTTI on this leaf).
2. Whether any caller pre-clamps to `[-1,1]` (redundant with this helper) — per-caller residual.
3. NaN / signaling on `_CIacos` vs saturated branch under denormals — runtime open.
4. Full dual of each caller’s angle-construction formula (out of OWN VA scope).

**Verdict:** **accept-with-gaps** — dual **CF + constants (1.0 / π) + ABI + `_CIacos` target + caller inventory** sealed; package **not complete** (product name, runtime, caller-side formulas).
