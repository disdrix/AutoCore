# Review B (skeptical / adversarial): `aa_005d1d20` Math_QuatExtractForwardZ_OutFirst_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1d20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-J) |
| **Counterpart** | `reviews/A_aa_005d1d20_Math_QuatExtractForwardZ_OutFirst_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same ABI as `Math_QuatExtractForwardZ` @ `0x004e8a40` (quat, out) | **Falsified** — this unit is **(out, quat)**; sibling is **(quat, out)** |
| 2 | Extracts right (+X) or up (+Y) | **Falsified** — closed form is column 2 / +Z only |
| 3 | Quaternion layout is WXYZ | **Falsified** — `*q`=x … `q[3]`=w (XYZW); identity `(0,0,0,1)` → `(0,0,1,0)` |
| 4 | Re-normalizes input or output | **Falsified** — no sqrt/div |
| 5 | `__thiscall` / ECX this | **Falsified** — stack args only; bare `RET` |
| 6 | `g_flLevelUpUiBase_Inferred` is a UI scale here | **Falsified as role** — value is **2.0f** quat factor only |
| 7 | Writes only float3 (no W) | **Falsified** — forces `out[3]=0` |
| 8 | Different algebra from `0x004e8a40` | **Falsified** — same 2(xz+yw), 2(yz−xw), 1−2(x²+y²) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Arg order (out, quat) | **High** | Swapped pointers trash pose math |
| +Z / column-2 identity | **High** | Aim offset dots wrong axis |
| Constants 2.0 / 1.0 | **High** | Scale error on every term |
| No normalize | **High** | Over-engineered port diverges |

---

## 3. Cross-check vs sealed sibling `0x004e8a40`

| | `0x005d1d20` (this) | `0x004e8a40` |
|---|---|---|
| Args | out, quat | quat, out |
| Formula | identical +Z | identical +Z |
| Consts | same DAT 2.0 / 1.0 | same |
| Call graph | HB aim path sole xref | drive / MoveToTarget / applyAction |

Port must keep **two entry points** (or one with explicit arg order) — do not assume merge-safe call sites.

---

## 4. Surviving contract for AutoCore

```c
// Port of Math_QuatExtractForwardZ_OutFirst_Inferred
// cdecl: (out, quat XYZW); W of out forced 0; no normalize
void Math_QuatExtractForwardZ_OutFirst(float out[4], const float q[4]) {
  const float x = q[0], y = q[1], z = q[2], w = q[3];
  const float two = 2.0f; // DAT_00a10e74
  const float one = 1.0f; // DAT_00a0f2a0
  out[0] = (z*x + y*w) * two;
  out[1] = (z*y - x*w) * two;
  out[2] = one - (x*x + y*y) * two;
  out[3] = 0.0f;
}
// Do not swap args to match 0x004e8a40 without fixing call sites.
```

---

## 5. Open questions

1. Product symbol (none in body).
2. Why a second copy of +Z extract exists (historical link / TU split) — not required for port fidelity.
3. Runtime golden optional.

**Verdict:** **accept**
