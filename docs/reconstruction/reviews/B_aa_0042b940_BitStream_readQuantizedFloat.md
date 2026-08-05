# Review B (skeptical / adversarial): `BitStream_readQuantizedFloat` @ `0x0042b940`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b940_BitStream_readQuantizedFloat.md` |
| **Verdict** | **accept-with-gaps** on CF/dequant math; **needs-more-evidence** on unrecovered FUN_/convention |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Pure trampoline like writeQuantizedFloat | **Falsified** — dequant scale + fdiv are **in-body** (pcode INT_*/FLOAT_DIV) |
| 2 | Scale is `(1<<bitCount)-1` (unsigned full mask) | **Falsified** — uses `(1<<((n-1)&0x1f))-1` (signed-range max) |
| 3 | Callee args fully recovered | **Overstated** — high pcode CALL has target only; bitCount may still be ECX/stack for callee |
| 4 | Production signature is `float10 (char)` free func | **Overstated** — widths/convention tentative; symbol table said `void` formals |
| — | Param names / types are production-ready | **Overstated** — `param_1` / `float10` / `FUN_*` remain |
| — | Runtime verified | **Falsified** — open / deferred |
| — | Inverse of writeQuantizedFloat sealed from this unit alone | **Needs-more-evidence** — write side trampolines to `FUN_0042b980`; not opened here |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| In-body dequant division | High | Wrong → protocol float mismatch risk |
| Scale `(1<<((n-1)&0x1f))-1` | High | Wrong → range/sign decode errors |
| Straight-line CF / no local OOB check | High | Missed sticky error only if assumed here |
| Callee = integer source | Medium | Wrong callee role → entire decode wrong |
| Implicit this / bitCount to callee | Medium | Wrong → wire codec layout mistakes |
| Clean is CF-preserving scaffold | High | Low for map use; high if treating as bit-exact |
| Semantic field names beyond Ghidra | Medium | Auth/network float fields mis-scaled |

---

## 3. Surviving contract for AutoCore

```
BitStream_readQuantizedFloat(bitCount: u8) -> float:
  q = FUN_0042b9d0(...)   // integer read; callee not sealed in this unit
  scale = (1 << ((bitCount - 1) & 31)) - 1
  return (float)q / (float)scale

Do not implement the integer bit-read from this unit alone.
Do not assume unsigned scale (1<<n)-1 — binary uses (n-1) form.
```

---

## 4. Open questions

1. What is `FUN_0042b9d0` (signed int read? shared bitCount?)
2. Free-func vs thiscall; does bitCount reach the callee?
3. Edge bitCount 0/1 → scale 0 → FPU div0 behavior
4. Exact inverse pairing with `BitStream_writeQuantizedFloat` / `FUN_0042b980`

**Verdict:** **accept-with-gaps** on CF/dequant math; **needs-more-evidence** on unrecovered FUN_/convention — safe as behavioral map for AutoCore network float dequant; do not treat `FUN_0042b9d0` or incomplete decomp signatures as sealed wire codecs without sibling units.
