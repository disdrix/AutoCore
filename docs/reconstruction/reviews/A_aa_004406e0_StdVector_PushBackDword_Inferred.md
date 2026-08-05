# Review A (reconstruction fidelity): `aa_004406e0` StdVector_PushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004406e0` |
| **VA** | `0x004406e0` |
| **Canonical name** | `StdVector_PushBackDword_Inferred` (structural; MSVC vector-like) |
| **Ghidra name** | `FUN_004406e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004406e0_StdVector_PushBackDword_Inferred.md` |
| **System** | container / std::vector&lt;void*/dword&gt; push |
| **Live tools** | `batch_decompile` 0x004406e0; callers gfx/UI (`Named_gfxDeviceIB` chain, many) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Push one dword** onto a classic 3-pointer MSVC-ish vector header in **EAX**, value from **ESI**:

| Off | Field |
|---|---|
| `+0x04` | begin* |
| `+0x08` | end* |
| `+0x0c` | capacityEnd* |

CF:

1. `begin = *(this+4)`. If `begin != 0` **and** `(end-begin)/4 < (capEnd-begin)/4` (room for ≥1 more dword):
   - `*end = *esi`; `end += 4`; return.
2. Else grow-path: `FUN_00466da0(end, esi)` — realloc/insert helper (capacity exhausted or null begin).

Fast path is pure pointer arithmetic; no heap in this unit on hit. Stride fixed at **4** (`>> 2`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_004406e0_*`, `reconstructed-exact/FUN_004406e0.cpp` |
| Function record | `functions/aa_004406e0_FUN_004406e0.md` |
| Grow callee | `FUN_00466da0` |
| Callers sample | `ClientSpecialEvent_Respawn_Update`, TeleportIn ctor, many UI |
| Live | EAX=vector, ESI=value*; capacity check via >>2 |

**Three-rep:** present.

---

## 3. Recovered CF

```c
// customcc: EAX = vector*, ESI = const dword*
void PushBackDword(VecDword *v, const uint32_t *val)
{
  void *begin = v->begin; // +4
  if (begin && (v->end - begin)/4 < (v->capEnd - begin)/4) {
    *v->end++ = *val;
    return;
  }
  GrowInsertAtEnd(v->end, val); // FUN_00466da0
}
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| Vector layout begin/end/cap at +4/+8/+c | **High** |
| Element size 4 | **Confirmed** |
| Fast path write + end bump | **Confirmed** |
| Slow path `00466da0` | **Confirmed** |
| EAX / ESI customcc | **High** |
| Product name / exact vector typedef | **Tentative** |
| Whether +0 is vtbl or unused | **Open** (not touched) |

---

## 5. Gaps

1. Dual of grow helper `FUN_00466da0`.
2. Confirm +0 field with parent types (gfx index buffer paths).
3. Runtime open.

**Verdict:** **accept-with-gaps**
