# Review B (skeptical / adversarial): `Color_PackFloat4_Scale255_Inferred` / `FUN_00973820` @ `0x00973820`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-E) |
| **Counterpart** | `reviews/A_aa_00973820_Color_PackFloat4_Scale255_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/scale; reject decompiler-only “stack float* void leaf” reading |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure leaf (no callees) | **Falsified** — calls `FUN_00973590` |
| 2 | Stack-only single arg; no dest | **Falsified** — **ECX dest** (`mov eax,ecx`; call-site `lea/add ecx`) |
| 3 | plain `ret` / cdecl | **Falsified** — **`ret 4`** |
| 4 | Scale by 1.0 / identity | **Falsified** — `DAT_00aaa6f8` = **255.0f** |
| 5 | This **is** the clamp packer | **Falsified** — thin scale wrapper; clamp is nested |
| 6 | Matrix / transform helper (W27-F “matrix setup” shorthand) | **Overstated** — color pack used near matrix helpers; body is color only |
| 7 | Product channel English sealed | **Open** (BGRA-style **probable** via nested) |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 + ECX dest + stack src | **Confirmed** | stack imbalance / wrong dest |
| ×255.0f before pack | **Confirmed** | 0..1 floats written as near-zero colors |
| Nested clamp in `FUN_00973590` | **High** | out-of-range floats wrap wrong |
| “Matrix helper” label | **Rejected** | mis-ports as transform |
| Product C++ name | **Open** | docs only |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
// ECX = dest bytes; stack float* src; ret 4
FUN_00973590(src[0]*255, src[1]*255, src[2]*255, src[3]*255);
// EAX was set from ECX
```

Decompiler 2026-07-29 ≡ raw scale CF but **omits ECX**. Bytes + call sites restore dest ABI. Constant `00 00 7F 43` = 255.0f.

---

## 4. Surviving contract for AutoCore

```
// ECX dest, stack src float4, ret 4, void
void Color_PackFloat4_Scale255(uint8_t* dest, const float* src):
  pack_clamp_u8x4(dest, src[0]*255, src[1]*255, src[2]*255, src[3]*255)
// Used by motion child color, fog, difficulty UI colors, serializers
```

Do **not** drop the ECX destination. Do **not** skip the 255 scale when src is normalized. Do **not** merge with `FUN_00973590` without preserving clamp. Do **not** treat as matrix/basis setup.

---

## 5. Falsification notes

### 5.1 “Decompiler signature is complete”

Surface `void FUN_00973820(float*)` is **wrong as ABI**. Bytes: load stack float*, scale, `mov eax,ecx`, call packer, `ret 4`. Call site in SyncChildPoseHF sets ECX = child+0x34.

### 5.2 “Matrix setup” (parent W27-F shorthand)

Parent notes grouped this with `FUN_00973690` / `FUN_006a3db0` as “matrix setup on child+0x34”. This unit only packs color into +0x34; the 0.75 helper is a **sibling**, not this body.

### 5.3 “Is the clamp function”

Clamp/saturate lives in `FUN_00973590`. This unit only multiplies by 255 and forwards.

---

## 6. Open questions

1. Retail name / product class of the color pack cluster (`00973590` / `00973690` / `00973820`).
2. Full dual of `FUN_00973590` channel indices (decompile suggests f0→[2], f1→[1], f2→[0], f3→[3]).
3. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed scale-255 + ECX dest + ret4. Reject leaf/stack-only/matrix overclaims.
