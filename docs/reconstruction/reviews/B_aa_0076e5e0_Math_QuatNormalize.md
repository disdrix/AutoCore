# Review B (skeptical / adversarial): `aa_0076e5e0` Math_QuatNormalize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076e5e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-B) |
| **Counterpart** | `reviews/A_aa_0076e5e0_Math_QuatNormalize.md` |
| **Scratch** | `tmp/a_0076e5e0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is vec3 normalize | **Falsified** — four components in lenSq and scale/copy |
| 2 | Always forces unit length | **Falsified** — near-zero band returns without scale; near-unit skip |
| 3 | Near-zero uses only `+eps` | **Falsified** — both `+1e-6` and `−1e-6` globals (`read_memory`) |
| 4 | Nearly-equal uses only abs tol | **Falsified** — both rel and abs pushed as `0x358637BD` into `FUN_0040d450` |
| 5 | Scale multiplies `in` | **Falsified** — FPU `FMUL [eax]` with EAX=`out` |
| 6 | stdcall / thiscall | **Falsified** — plain `RET`, 2 stack ptrs, ESI only saved |
| 7 | Name is retail string | **Overstated** — role evidence High; product English open |
| 8 | Leaf (no callees) | **Falsified** — calls `FUN_0040d450` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Near-zero + near-unit CF | **High** | Wrong skip → NaNs or drift |
| ±1e-6 constant bits | **High** | Threshold mismatch vs client |
| cdecl + return out | **High** | ABI break |
| Scale target = out | **High** | Broken if out≠in assumed copy-first |
| Product English | **Medium** | Naming only |
| Runtime FPU bit-exact | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
lenSq = in·in                    // SSE mul/add on [esi]
if -1e-6 < lenSq < +1e-6: ret out
if !NearlyEqual(lenSq,1,1e-6,1e-6):
  out *= 1/sqrt(lenSq)           // FPU path
else if out != in: copy
return out
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. W25-T already cited this VA as quat normalize skip caller of FloatNearlyEqual — sealed here.

---

## 4. Surviving contract for AutoCore

```
// Port normalize must:
//  1) early-out when |lenSq| < 1e-6 (strict open interval via jbe pair)
//  2) skip scale when abs+rel nearness of lenSq to 1.0 with both tols 1e-6
//  3) otherwise scale the destination quat by 1/sqrt(lenSq)
// Prefer aliasing out==in (matches call sites e.g. ObjectMotion integrate).
```

---

## 5. Verdict

Adversarial pass **confirms** A: quat normalize CF, constants, ABI, and FloatNearlyEqual linkage sealed. Residuals English + runtime FPU → **accept**.
