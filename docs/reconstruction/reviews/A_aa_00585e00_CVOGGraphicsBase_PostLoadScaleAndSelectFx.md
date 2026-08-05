# Review A (reconstruction fidelity): `aa_00585e00` CVOGGraphicsBase_PostLoadScaleAndSelectFx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00585e00` |
| **VA** | `0x00585e00`–`0x00586056` |
| **Canonical name** | `CVOGGraphicsBase_PostLoadScaleAndSelectFx` |
| **Ghidra name** | `FUN_00585e00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-N) |
| **Counterpart** | `reviews/B_aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` |
| **System** | client / graphics / select-fx / LogicUI |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller decompile of `FUN_00586060` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On a `CVOGGraphicsBase` after successful asset load (caller gates on `obj+0x188` bit0):

1. Require graphics object at `this+8` and `FUN_005130e0(1)`.
2. Read mesh scale from `vtbl+0x48` result `+0xC`; compute **reciprocal** via `2.0/(s*2.0)`.
3. Invoke host scale vtbl `+0xB8(scale)`; lift object Y by scale; transform; push mode-3 position into graphics `vtbl+0x10`.
4. If `skipSideFx==0`: optional near-50-unit pickup SpecialFX; LogicUI type **0x1F** with orientation quat + **3.5** payload.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00585e00_FUN_00585e00.md` (+ W26-N append) |
| Annotated | `docs/reconstruction/raw/aa_00585e00_FUN_00585e00.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGGraphicsBase_PostLoadScaleAndSelectFx.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00585e00.cpp` |
| Function | `docs/reconstruction/functions/aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` |
| Live | `decompile_function` `0x00585e00`; `read_memory` full 599 B + constants |

---

## 3. Signature

```c
// Ghidra: float10 __thiscall FUN_00585e00(int param_1, char param_2)
// Bytes: MOV ESI,ECX … RET 4
float __thiscall CVOGGraphicsBase_PostLoadScaleAndSelectFx(void *this, char skipSideFx);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` at entry | **High** |
| `ret 4` (one stack char) | tail `C2 04 00` | **High** |
| float ST0 return | early `FLD [g_flZero]`; exit `FLD [esp+0x10]` | **High** |
| graphics at `this+8` | gate + vtbl uses | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Dual gate object+probe | **Yes** | **High** |
| Reciprocal scale via 2.0 cancel | **Yes** (`read_memory` 2.0 @ `0x00a10e74`) | **High** |
| Y lift + `FUN_004e88e0` + mode 3 | **Yes** | **High** |
| `skipSideFx` gates FX/LogicUI | **Yes** (`CMP [ebp+arg],0` / decomp) | **High** |
| Near dist **50.0** → `Object_PlayPickupSpecialFX` | **Yes** (W25-J dual callee) | **High** |
| LogicUI type **0x1F** + **3.5** | **Yes** | **High** |
| Caller plate `CVOGGraphicsBase::InitializeGraphics` | **Yes** (string in `FUN_00586060`) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x00585e00` | `55 8B EC 83 E4 F0 81 EC 88 01 00 00 56 8B F1` | frame; ESI=this |
| early fail | `D9 05 18 F5 A0 00` … `C2 04 00` | FLD zero; RET 4 |
| scale base | `F3 0F 10 05 74 0E A1 00` | MOVSS from **2.0** |
| `0x00a0f524` | `00 00 48 42` | **50.0f** |
| `0x009da8a4` | `00 00 60 40` | **3.5f** |
| tail | `D9 44 24 10 5F 5E 8B E5 5D C2 04 00` | FLD ret; epilogue RET 4 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | Site | Args |
|---|---|---|
| `FUN_00586060` (`CVOGGraphicsBase::InitializeGraphics`) | `0x0058645a` | `(0)` when `(byte*)(obj+0x188)&1` |

Callees: listed in function record; nested `FUN_0051aed0` dual-sealed as `Object_PlayPickupSpecialFX`.

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI thiscall + ret 4 + ST0 | **High** |
| CF + float constants | **High** |
| Class family via caller plate | **High** |
| Method English spelling | **Probable** / **Open** product C++ |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product method name (no plate on this VA).
2. Full meaning of graphics vtbl mode 3 / host `+0xB8`.
3. Historical Ghidra label `g_flLevelUpUiBase_Inferred` for the **2.0** cancel constant.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, CF, constants, caller class sealed; method English Probable.
