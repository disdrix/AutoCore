# Review B (skeptical / adversarial): `aa_004e96e0` Math_CopyFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e96e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-O) |
| **Counterpart** | `reviews/A_aa_004e96e0_Math_CopyFloat4_Inferred.md` |
| **Verdict** | **accept** (trivial leaf; bytes close plate drift) |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a normalizer / unit vector helper | **Falsified** — no length/sqrt/scale |
| 2 | Same contract as `0x004e9530` (float3 pack) | **Falsified** — this unit loads/stores **src.w** |
| 3 | `thiscall` / ECX this | **Falsified** — stack args only; no ECX use |
| 4 | Void return (decompiler) | **Partially true as display** — EAX holds dst*; callers cast to `float*` |
| 5 | Exclusive turret helper | **Falsified** — 12+ named callers across FX/vehicle/AI |
| 6 | `and esp,-16` implies SIMD aligned store requirement | **Overstated** — stores are `movss` unaligned-safe; align is prolog artifact |
| 7 | Copies as integer dwords only (no float semantics) | **Weak** — opcodes are `movss` (float move); bit-identical to dword copy for pure transfer |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Full 4-component transfer | **High** | W dropped → quat/orient bugs |
| Distinction from dirty-W sibling | **High** | Mis-port uses wrong helper |
| cdecl + EAX=dst* | **High** | Callers lose chain-assign |
| Name “Math_CopyFloat4” | **Inferred** | Rename only |
| No side effects | **High** | Spurious global deps in port |

---

## 3. Cross-check against raw + bytes

```
dst.x = src.x; dst.y = src.y; dst.z = src.z; dst.w = src.w;
return dst;
```

Decompiler order (temps for w,y,z then stores) matches SSE load/store order. Clean must **not** invent normalization or zeroing of W.

---

## 4. Surviving contract for AutoCore

```c
// Port of Math_CopyFloat4_Inferred (client math leaf)
float* Math_CopyFloat4(float* dst, const float* src) {
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
  return dst;
}
// Prefer this over Math_CopyFloat3ToFloat4 when source is full float4/quat/orient.
```

---

## 5. Open questions

1. Whether any path intentionally uses `004e9530` when W must be zero — separate unit.
2. Product symbol for the helper (none in body).

**Verdict:** **accept**
