# Review B (skeptical / adversarial): `aa_005d9af0` Drive_CollisionListener_PlayCollisionEffect

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9af0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-G) |
| **Counterpart** | `reviews/A_aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md` |
| **Scratch** | `tmp/a_005d9af0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler sig is complete (`void thiscall(int)` only) | **Falsified** — `RET 0x14`, five stack formals, `[ebp+8]` float3 use |
| 2 | No product name | **Falsified** — literal `"CollisionListener::PlayCollisionEffect"` |
| 3 | Always creates FxMaster | **Falsified** — only if `allowCreate!=0` and `this+4==0` and no prebound `clonebase+0x88` |
| 4 | Null object still runs FX | **Falsified** — first check returns before profiler |
| 5 | Single caller | **Falsified** — Contact + `FUN_005d9ea0` (flag 1 vs 0) |
| 6 | stack0 unused | **Falsified** — `movss` ×3 from `[ebp+8]` after FX resolve |
| 7 | Float math fully sealed | **Overstated** — 2.0f/1.0f sealed; full algebra residual |
| 8 | Name confusable with PlayCollisionSound | **Noted** — different string/VA (`005d90a0` sound vs this effect) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name / string | **High** | Misfiled system |
| thiscall + RET 0x14 | **High** | Stack smash |
| Null go / allowCreate gates | **High** | Spurious FX / missed FX |
| Lazy FxMaster @ +4 | **High** | Leak / null deref path |
| clonebase +0xA8 / +0x88 | **High** | Wrong FX bind |
| SetParam ×3 + play | **High** | Silent no-VFX |
| stack1/stack2 English | **Medium** | Adapter residual |
| Float algebra bit-exact | **Medium** | Visual mismatch |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = ECX; (vec3, a1, a2, go, allowCreate) = stack×5
if !go: return
scope("CollisionListener::PlayCollisionEffect")
cb = *(go+0xA8)
if !*(cb+0x88):
  if !allowCreate: leave
  ensure FxMaster at this+4; LoadEventVariant or leave
else:
  LoadEventVariant or fall into create path
sample go vtbl+0x1C8 ×2
SetParamFloat3 keys 1..3
go vtbl+0xF8; FUN_004b7e50(0,0,0)
leave; RET 0x14
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Clean plate fills ABI + string.

Call sites confirm flag polarity: Contact passes **1**, `005d9ea0` passes **0**.

---

## 4. Surviving contract for AutoCore

```
// Client collision VFX (not damage)
Drive_CollisionListener_PlayCollisionEffect(
    listener, vec3, a1, a2, gameObject, allowCreate)
// no-op if gameObject==null
// allowCreate=0 → only prebound clonebase+0x88 path (no lazy master)
// FxMaster cached at listener+4
// Plays NDSpecialFX with three float3 params after frame samples
```

Not required for pure server sim; required for client collision VFX parity.
