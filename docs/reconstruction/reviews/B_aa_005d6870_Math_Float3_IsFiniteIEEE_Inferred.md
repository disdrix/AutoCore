# Review B (skeptical / adversarial): `aa_005d6870` Math_Float3_IsFiniteIEEE_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-J) |
| **Counterpart** | `reviews/A_aa_005d6870_Math_Float3_IsFiniteIEEE_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a unit-length / near-unit quaternion test | **Falsified** — no length math; only exponent mask |
| 2 | Tests four components (quat) | **Falsified** — loop bound 3; float4 sibling is `0x005d68b0` |
| 3 | `__cdecl` / no ECX this | **Falsified** — loads via `ECX+index*4`; `RET 4` |
| 4 | Returns bool in AL as sole result | **Falsified as primary ABI** — writes out-byte; EAX may residual-hold pointer |
| 5 | Rejects zero / denormals | **Falsified** — only exp==255 class fails |
| 6 | Uses SSE `COMISS` / FP compare | **Falsified** — integer `AND`/`CMP` on bits after `MOVSS` spill |
| 7 | Non-leaf / side effects beyond out byte | **Falsified** — leaf; only `*outOk` store |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bound = 3 | **High** | Port leaves W untested or over-reads |
| Mask semantics | **High** | Accepts Inf into physics apply |
| thiscall + RET 4 | **High** | Stack imbalance / wrong ECX |
| Out polarity (1=ok) | **High** | Inverted gates kill apply paths |

---

## 3. Cross-check against sibling

| Unit | VA | Bound |
|---|---|---|
| This | `0x005d6870` | 3 |
| Sealed dual | `0x005d68b0` Math_Float4_IsFiniteIEEE_Inferred | 4 |

Same mask and out-byte protocol — only bound differs. Clean must **not** merge them.

---

## 4. Surviving contract for AutoCore

```c
// Port of Math_Float3_IsFiniteIEEE_Inferred (client math leaf)
// thiscall: ECX = float[3]*; stack: uint8_t* outOk; RET 4
void Math_Float3_IsFiniteIEEE(float *v, uint8_t *outOk) {
  for (int i = 0; i < 3; ++i) {
    uint32_t bits;
    memcpy(&bits, &v[i], 4);
    if ((bits & 0x7f800000u) == 0x7f800000u) {
      *outOk = 0;
      return;
    }
  }
  *outOk = 1;
}
// Do not use isfinite() without matching Inf/NaN-only reject (denorms must pass).
```

---

## 5. Open questions

1. Product symbol name (none in body).
2. Whether any caller depends on EAX residual pointer vs separate out slot address (both equal when out is the pushed arg).

**Verdict:** **accept**
