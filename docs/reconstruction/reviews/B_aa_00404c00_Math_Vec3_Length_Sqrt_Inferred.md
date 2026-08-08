# Review B (skeptical / adversarial): `aa_00404c00` Math_Vec3_Length_Sqrt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c00` |
| **VA** | `0x00404c00` |
| **Canonical name** | `Math_Vec3_Length_Sqrt_Inferred` |
| **Review date** | `2026-08-05` (MEGA-060 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + `disassemble_function` + callers/xrefs + caller decompiles |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** `Mission_Look_in_your_Mission_Inventory` | **Falsified** — that plate is `FUN_008a8770` @ `0x008a8770`; this VA is 33 B pure math |
| 2 | Mission inventory open / list / journal helper | **Falsified** — no strings, no UI, no inventory stores; 0 callees |
| 3 | 2D length only (x,y) | **Falsified** — loads **three** floats including `[ECX+8]` |
| 4 | Normalize (scale to unit) | **Falsified** — returns length only; no stores back to `v` |
| 5 | Dot product / distance between two vectors | **Falsified** — single pointer; self-products only |
| 6 | Stack arg `float*` / cdecl | **Falsified** — all loads from **ECX**; bare `RET` not `RET 4` |
| 7 | SSE `sqrtss` path | **Falsified** — classic x87 `FLD/FMUL/FADDP/FSQRT` sequence |
| 8 | Has callees (`sqrt` CRT import) | **Falsified** — inline `FSQRT`; callers list empty |
| 9 | Same as sibling `00404c30` | **Falsified** — sibling is float4 dword copy to `this+0x90` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
FLD  [ECX+8]     ; z
FLD  [ECX+4]     ; y
FLD  [ECX]       ; x
; x*x + y*y + z*z
FSQRT
; cleanup → length in ST0
RET              ; C3
```

Body hex (33 B):

```text
d9 41 08  d9 41 04  d9 01  d9 c0  d8 c9  d9 c2  d8 cb  de c1
d9 c3  d8 cc  de c1  d9 fa  dd db  dd d8  dd d8  c3
```

Call-site pattern (mission parent @ `0x008a8cd0` family): ECX set to a float3 (often a delta on stack), `CALL 00404c00`, compare ST0/`float` cast to thresholds — **consumer of length**, not identity of this function.

A ≡ B on live decompile + body hex + xrefs + disassembly.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Length formula | **High** | wrong math port |
| ECX float3 / ST0 / RET | **High** | ABI smash |
| Not mission inventory body | **High** | wrong system ownership |
| Caller set (5 sites) | **High** | missing consumers |
| Product English | Medium | naming only |
| Runtime | Open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// Leaf: Euclidean length of float3 at ECX; result in ST0 / float return.
// No stack args. No mutation of v.
float Vec3Length(ReadOnlySpan<float> v /* len >= 3, ECX */)
{
    float x = v[0], y = v[1], z = v[2];
    return MathF.Sqrt(x * x + y * y + z * z);
}
// Keep distinct from normalize, 2D length, and Mission_Look_in_your_Mission_Inventory (0x008a8770).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/formula and **rejects** mission-inventory identity. Residual product symbol English → **accept-with-gaps**.
