# Review B (skeptical / adversarial): `aa_006223c0` CVOGHBSkill_KillCharge_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006223c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-019 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md` |
| **Verdict** | **accept** on identity/CF/ABI; product skill English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is OnHeartBeat / pulse body | Body is linear ctor (base + vtbl + return) | **Falsified** |
| 2 | Class is CommonCastOnDeath | RTTI on installed vtbl is **KillCharge**; caller overwrites to CommonCastOnDeath after return | **Falsified** as CommonCastOnDeath identity |
| 3 | Class is generic CVOGHBSkillBase | Base installs `009d3fdc`; this leaf overrides to `009d16e4` + KillCharge RTTI | **Falsified** |
| 4 | `cdecl` / void / no stack cleanup | `mov esi,ecx`; `ret 0x18` (6 args × 4) | **Falsified** — thiscall + 6 stack |
| 5 | Allocates `0x6d0` inside this VA | No `operator_new` in body; size is caller's concern | **Falsified** |
| 6 | Size is always `0x6d0` | Peer factory `FUN_006226a0` uses `0x6c0` for pure KillCharge; `0x6d0` is subclass path | **Falsified** as single size |
| 7 | Multiple direct CALL sites | Single UNCONDITIONAL_CALL from `FUN_00622f70` @ `0x00623009` | **Survives as sole CALL** (DATA xrefs to vtbl elsewhere) |
| 8 | Extra field stores in this leaf | Bytes: only base call + `mov [esi], vtbl` + return | **Falsified** |
| 9 | Parent is raw `CVOGHBBase_ctor` only | Relative call target sealed to `0x005788d0` SkillBase | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| KillCharge RTTI + vtbl + ctor role | **Confirmed / High** | Wrong skill class factory |
| ABI thiscall / ret 0x18 / 6 stack | **High** | Stack corruption in port |
| Sole CALL + intermediate-base use | **High** | Miss CommonCastOnDeath chain |
| Product "KillCharge" design English | **Open** | Doc only |
| Runtime Enqueue/Start outcomes | **Open** | Live stacking unverified |

---

## 3. Cross-check raw + live

Live decompile 2026-08-05 ≡ 2026-07-23 raw CF (callee renamed in Ghidra symbols):

```
CVOGHBSkillBase_ctor(p2..p7);   // this in ECX
*this = &PTR_FUN_009d16e4;
return this;                    // ret 0x18
```

RTTI name string at `0x00af2b78`: `.?AVCVOGHBSkill_KillCharge@@`.  
COL at `0x00aae2d8` referenced from vtbl tail.  
Body bytes seal `c2 18 00` and `c7 06 e4 16 9d 00`.

---

## 4. Surviving contract for AutoCore

```
// Intermediate KillCharge base (CommonCastOnDeath factory path):
void *hb = operator_new(0x6d0);           // subclass size at caller
CVOGHBSkill_KillCharge_Ctor(hb, caster, skillBlob, world, target, tfid, arg7);
// hb vtbl temporarily KillCharge; caller may set CommonCastOnDeath next

// Pure KillCharge path (peer factory — not this VA):
void *hb = operator_new(0x6c0);
CVOGHBSkillBase_ctor(...);
*hb = &PTR_FUN_009d16e4;                  // same vtbl this ctor installs
```

Do **not** treat this leaf as CommonCastOnDeath, as SkillBase itself, as void/cdecl, or as an allocator.

**Verdict:** **accept**.
