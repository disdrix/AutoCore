# Review B (skeptical / adversarial): `aa_004e88e0` Vec3_Copy

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e88e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-B) |
| **Counterpart** | `reviews/A_aa_004e88e0_Vec3_Copy.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a basis / matrix transform | **Falsified** — only three movss loads/stores |
| 2 | Copies full float4 (includes W) | **Falsified** — no access to +0xC |
| 3 | `__thiscall` / ECX this | **Falsified** — stack args only; bare `ret` |
| 4 | Args reversed (src, dst) | **Falsified** — `[esp+4]` is store base, `[esp+8]` is load base |
| 5 | Normalizes or clamps | **Falsified** — no arithmetic |
| 6 | Decompiler integer temps mean non-float path | **Falsified as ABI semantics** — bytes are `movss` (float bits still copy correctly) |
| 7 | Non-leaf / has side effects | **Falsified** — 37-byte leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-float width | **High** | Corrupting W of float4 or leaving Y/Z stale |
| dst/src order | **High** | Overwriting source |
| cdecl / stack | **High** | Wrong port ABI |
| No math | **High** | Over-engineered port with normalize |

---

## 3. Cross-check against raw + bytes

```
dst[0..2] = src[0..2]
return
```

Clean must **not** invent quaternion, matrix, length, or W-component handling. Sibling `FUN_004e8830` is the float4 full copy — different unit.

---

## 4. Surviving contract for AutoCore

```c
// Port of Vec3_Copy (client math leaf)
void Vec3_Copy(float* dst, const float* src) {
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
}
// Do not copy src[3]/W. Self-copy of non-overlapping or identical buffers OK.
```

---

## 5. Open questions

1. Product symbol name (none in body).
2. Whether any caller intentionally aliases partial-overlap buffers (would be UB for partial overlap; unlikely for 12-byte block).

**Verdict:** **accept**
