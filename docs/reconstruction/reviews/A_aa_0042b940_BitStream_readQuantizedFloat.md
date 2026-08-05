# Review A (reconstruction fidelity): `aa_0042b940` BitStream_readQuantizedFloat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b940` |
| **VA** | `0x0042b940` |
| **Canonical name** | `BitStream_readQuantizedFloat` |
| **System** | network-bitstream |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b940_BitStream_readQuantizedFloat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0042b940_FUN_0042b940.md` |
| Raw | `docs/reconstruction/raw/aa_0042b940_FUN_0042b940.md` |
| Annotated | `docs/reconstruction/raw/aa_0042b940_FUN_0042b940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0042b940.cpp` |

**Primary evidence (this session, own VA only):** Ghidra `decompile_function` / `force_decompile` @ `0x0042b940`; `get_function_pcode` (high); body `0042b940`–`0042b972`.

---

## 2. Purpose (from unit)

Read a quantized integer from the bitstream (via `FUN_0042b9d0`), then **dequantize** to a float by dividing by the signed-range max for `bitCount`:

```
scale = (1 << ((bitCount - 1) & 0x1f)) - 1
return (float)quantizedInt / (float)scale
```

Not a pure trampoline: integer read is delegated; **dequant math lives in this unit**.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Straight-line body: call → i2f → scale → fdiv → ret | **High** | Single basic block in high pcode |
| Scale formula `(1<<((n-1)&0x1f))-1` | **High** | INT_SUB 1, INT_AND 0x1f, INT_LEFT 1, INT_ADD -1 |
| Stack formal `param_1` is 1-byte bit count | **High** | pcode `stack+4` size 1 |
| Return in x87 ST0 (`float10`) | **High** | FLOAT_DIV → RETURN ST0 |
| Callee is `FUN_0042b9d0` @ `0x0042b9d0` | **High** | CALL target only; **own-VA: body not opened** |
| Implicit `this` / full calling convention | **Medium** | Ghidra symbol is free-func; ECX thiscall not sealed here |
| Callee receives bitCount / signed-int semantics | **Open** | CALL shows no explicit formals in high pcode |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; CF matches raw |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| `iVar1 = FUN_0042b9d0()` | **Yes** (clean ≡ raw scaffold) |
| convert `iVar1` to float | **Yes** (INT2FLOAT / float10 cast) |
| `denom = (1 << ((param_1 - 1) & 0x1f)) - 1` | **Yes** (pcode-confirmed) |
| `return iVar1_f / denom_f` | **Yes** (FLOAT_DIV) |
| No branches / error path in this unit | **Yes** (single block) |

---

## 5. Gaps

1. `FUN_0042b9d0` not reviewed in this unit (own-VA scope) — assumed integer bit read; signed vs unsigned not sealed here
2. Free-func form vs BitStream `thiscall` (ECX)
3. Whether bitCount is also passed into the callee (pcode CALL args empty)
4. `float10` decompiler type vs production `float` / FPU width
5. Div-by-zero / bitCount∈{0,1} edge not guarded in this unit

**Verdict:** **accept-with-gaps**
