# Review A (reconstruction fidelity): `aa_005d6870` Math_Float3_IsFiniteIEEE_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6870` |
| **VA** | `0x005d6870`–`0x005d68ab` (60 B) |
| **Canonical name** | `Math_Float3_IsFiniteIEEE_Inferred` |
| **Ghidra name** | `FUN_005d6870` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-J) |
| **Counterpart** | `reviews/B_aa_005d6870_Math_Float3_IsFiniteIEEE_Inferred.md` |
| **System** | math / IEEE finite gate |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_callers` / `get_xrefs_to` |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **IEEE-754 binary32 Inf/NaN rejector on three consecutive floats**. Writes a single out-flag byte: `1` if all three components finite, `0` if any has exponent bits all-ones (`(u32 & 0x7f800000) == 0x7f800000`).

Used widely as a pre-apply / pre-normalize gate (impulse, aim delta, map/save vectors). Sibling `Math_Float4_IsFiniteIEEE_Inferred` @ `0x005d68b0` is the four-component clone.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d6870_FUN_005d6870.md` (+ W27-J live append) |
| Annotated | `docs/reconstruction/raw/aa_005d6870_FUN_005d6870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005d6870.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/Math_Float3_IsFiniteIEEE_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005d6870_FUN_005d6870.md` |
| Live decompile | `decompile_function` @ `0x005d6870` ≡ scaffold CF |
| Bytes | `read_memory` 64 B @ `0x005d6870` — body 60 B then `CC` |

---

## 3. Signature (sealed)

```c
void __thiscall Math_Float3_IsFiniteIEEE_Inferred(float *vec3 /* ECX */, uint8_t *outOk /* stack */);
// RET 4
```

| Claim | Conf |
|---|---|
| ECX = float3 base | **High** — `MOVSS [ECX+EAX*4]` in hex |
| Stack out byte* | **High** — stores via `[esp+8]` after push scratch |
| `RET 4` | **High** — hex `C2 04 00` ×2 |
| void primary | **High** — EAX residual = outOk pointer (caller idiom) |

---

## 4. Control flow (clean ≡ raw ≡ live ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| i = 0 | **Yes** | **High** |
| Test dword i with mask `0x7f800000` | **Yes** | **High** |
| Match → `*outOk=0`; return | **Yes** | **High** |
| i++ ; while i < 3 | **Yes** | **High** |
| Fallthrough `*outOk=1` | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |

---

## 5. Semantics seal

| Claim | Conf |
|---|---|
| Inf/NaN class only (not denorm reject) | **High** |
| Exactly 3 components (not 4) | **High** — bound `CMP EAX,3` / decompile `i < 3`; sibling @+0x40 uses 4 |
| Out values only 0 or 1 | **High** — `C6 00 00` / `C6 00 01` |
| Not unit-length / magnitude | **High** — no mul/add/sqrt |

---

## 6. Gaps

- Product/PDB symbol string — open (**Inferred**).
- Runtime golden samples — deferred.
- Full English product roles of every caller — out of OWN scope; impulse/aim sites noted.

**Verdict:** **accept**
