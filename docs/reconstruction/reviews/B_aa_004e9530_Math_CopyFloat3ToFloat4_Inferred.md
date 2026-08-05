# Review B (skeptical / adversarial): `aa_004e9530` Math_CopyFloat3ToFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9530` |
| **VA** | `0x004e9530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e9530_Math_CopyFloat3ToFloat4_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **normalizes** a vector (parent `A_aa_004b7e50` text) | FX-position habit | **Falsified** — only `movss` load/store; no mul/div/sqrt |
| 2 | This is a **quat basis extractor** | Neighbor `004e8xxx` family | **Falsified** — no quat formula; pure copy |
| 3 | Full **float4** copy including `src.w` | Confuse with `0x004e96e0` | **Falsified** — W from stack local, not `src[3]` |
| 4 | `dst.w` is **always 0** | Defensive port assumption | **Falsified as sealed** — no `xorps`/const store; uninit local |
| 5 | `__thiscall` object method | Entity habit | **Falsified** — stack `[ebp+8/0xc]`; no ECX this |
| 6 | Void return only (no pointer) | Decompiler void | **Weakened** — EAX holds `dst*` at RET (callers cast as float*) |
| 7 | Exclusive turret helper | Parent-seed name | **Falsified** — **35** xrefs across FX/drive/AI/UI |
| 8 | Name is string-proven | Symbol inflation | **Not sealed** — **Probable / `_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| float3 xyz copy | **High** | Wrong pack in FX/aim |
| Not normalize | **High** | Port invents length-1 and breaks parity when src non-unit |
| W = uninit stack | **High** (machine) | If port forces W=0, may still match callers that ignore W |
| Sibling `004e96e0` separation | **High** | Wrong full-copy at this VA |
| Product W intent | **Low** | Doc/runtime only |
| Complete caller English | **Low** | Miss consumers |

---

## 3. Cross-check against raw

```text
// raw aa_004e9530 ≡ live decompile
// dst = param_1, src = param_2
dst[0] = src[0]
dst[1] = src[1]
dst[2] = src[2]
dst[3] = local_14   // NEVER written in body — stack trash

// bytes seal (2026-07-29):
//   movss xmm0,[src]; movss xmm1,[src+4]; movss xmm2,[src+8]
//   movss [dst],xmm0
//   movss xmm0,[esp+0xc]   // uninit after sub esp,0x10
//   movss [dst+4],xmm1; movss [dst+8],xmm2; movss [dst+0xc],xmm0
// NOT FUN_004e96e0 (which assigns dst[3]=src[3])
```

Clean scaffold ≡ raw outline (including dirty `local_14`).

---

## 4. Surviving contract for AutoCore

```
Math_CopyFloat3ToFloat4_Inferred(dst, src):
  // stack args; pure leaf; NOT normalize
  dst[0]=src[0]; dst[1]=src[1]; dst[2]=src[2]
  dst[3]=<undefined stack>   // retail; do not invent 0 without product proof
  return dst in EAX          // practical; decompiler shows void

// Pair with:
//   FUN_004e96e0 — full float4 copy
//   004e8a40/8ad0/8b60 — quat basis (different)

// Consumers (sample): FX host 004b7e50, SpecialFX 004b75d0,
//   UpdateTurretAiming, many vehicle/client sites
```

**Port tests that matter:**

* Must **not** implement normalize at this VA.
* Must **not** copy `src[3]` (that is `0x004e96e0`).
* XYZ must match `src` exactly.
* W: either leave undefined or prove callers never read it before overwrite; **do not** claim retail zeros W.
* Correct parent dual mislabel: “normalize via FUN_004e9530” is wrong.

---

## 5. Open questions

1. Official product name.
2. Whether MSVC / optimizer ever zeroed that slot in another build (image shows uninit).
3. Runtime CE: capture `dst.w` after call from a known site.
4. Full caller English catalog.

**Verdict:** **accept-with-gaps** — adversarial attacks on normalize, basis-extract, full float4, thiscall, exclusive-turret naming **fail**; W product intent + English name remain open.
