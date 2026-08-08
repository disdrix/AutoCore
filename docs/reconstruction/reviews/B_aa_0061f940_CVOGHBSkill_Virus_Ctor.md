# Review B (skeptical / adversarial): `aa_0061f940` CVOGHBSkill_Virus_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061f940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| **Verdict** | **accept** on identity/CF/ABI; product skill English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is OnHeartBeat / pulse body | Body is linear ctor; OnHeartBeat is `0x0061fdf0` | **Falsified** |
| 2 | Generic HB ctor without Virus identity | RTTI + exclusive vtbl `009d14bc` + sole caller Virus OnHeartBeat | **Falsified** |
| 3 | `param_8`/`param_9` are floats | Stored as dwords; SetPeriodAndCounter takes int period | **Falsified as float** |
| 4 | Budget at wrong offset | Bytes `+0x6d0`/`+0x6d4`; OnHeartBeat decrements same | **Offset sealed** |
| 5 | `cdecl` / no stack cleanup | `ret 0x20` (8 args) | **Falsified** — thiscall + 8 stack |
| 6 | Base last float is period | Base gets `0` + `1.0f`; period is param_9 after | **Falsified** |
| 7 | Multiple direct CALL factories | Single CALL from `FUN_0061fdf0` | **Survives as sole CALL** (DATA vtbl uses elsewhere) |
| 8 | Size not 0x6e0 | Caller `operator_new(0x6e0)` only | **Survives as High** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Virus RTTI + vtbl + ctor role | **High / Confirmed** | Wrong skill class factory |
| +0x6d0 / +0x6d4 / ret 0x20 | **High** | Spread budget / period bug |
| Product “Virus” design English | **Open** | Doc only |
| Runtime stacking of children | **Open** | Unverified live |

---

## 3. Cross-check raw + live

Live decompile 2026-08-04 ≡ 2026-07-23 raw:

```
FUN_00618180(p2..p7, 0, 0x3f800000);
this[0x1b4] = p8;          // +0x6d0
*this = &PTR_FUN_009d14bc;
this[0x1b5] = p9;          // +0x6d4
CVOGHBBase_SetPeriodAndCounter(this, p9, true);
return this;               // ret 0x20
```

RTTI name string at `0x00af2b10`: `.?AVCVOGHBSkill_Virus@@`.  
Vtbl[+0x0c] dword = `0x0061fdf0` (OnHeartBeat dual sealed).

---

## 4. Surviving contract for AutoCore

```
// Virus multi-spread spawn (from OnHeartBeat):
void *hb = operator_new(0x6e0);
CVOGHBSkill_Virus_Ctor(hb, primary, skillBlob, world, newTarget, tfidArg,
                       arg7, remainBudget, remainPeriod);
// hb vtbl = Virus; +0x6d0 budget; +0x6d4 period seeded
CVOGHBList_Enqueue(world+0xe4ec, hb);
CVOGHBBase_Start(hb);
```

Do not reuse non-Virus HB ctors for this factory path.

**Verdict:** **accept**.
