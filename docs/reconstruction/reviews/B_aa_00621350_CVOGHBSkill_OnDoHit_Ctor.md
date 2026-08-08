# Review B (skeptical / adversarial): `aa_00621350` CVOGHBSkill_OnDoHit_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md` |
| **Verdict** | **accept** on identity/CF/ABI; product skill English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is OnHeartBeat / pulse body | Body is linear ctor: base + vtbl + ret | **Falsified** |
| 2 | Generic HB ctor without class identity | RTTI `.?AVCVOGHBSkill_OnDoHit@@` + exclusive vtbl `009d15c4` | **Falsified** |
| 3 | Adds extra fields beyond SkillBase | Zero stores after vtbl; only `*this = vtbl` | **Falsified** |
| 4 | `cdecl` / wrong stack cleanup | `ret 0x18` (6 stack args) after `pop esi` | **Falsified** — thiscall + 6 stack |
| 5 | Vtbl is SkillBase not subclass | Base installs `009d3fdc`; this overwrites with `009d15c4` | **Falsified** |
| 6 | Sole factory path | Two CODE CALL sites (`00621f50`, `006235e0`) | **Survives as multi-caller** |
| 7 | Callers leave OnDoHit vtbl | Both callers re-install different vtbls after return | **Survives** — this unit is intermediate base |
| 8 | Object size always 0x6d0 | Only `FUN_00621f50` shows `new(0x6d0)` for further subclass | **Size not sealed for pure OnDoHit** |
| 9 | Scaffold name `Named_CalleeOf_…VOG_DEBUG_STOP` is product name | String is in **caller** `FUN_006235e0` debug path, not this unit | **Falsified as product name** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| OnDoHit RTTI + vtbl + ctor role | **High / Confirmed** | Wrong skill class factory |
| ret 0x18 / base-then-vtbl CF | **High** | ABI mismatch in port |
| Product “OnDoHit” design English | **Open** | Doc only |
| Pure size / subclass tail fields | **Open** | Layout bugs in further subclasses |

---

## 3. Cross-check raw + live

Live decompile 2026-08-05 ≡ 2026-07-23 raw CF:

```
CVOGHBSkillBase_ctor / FUN_005788d0(p2..p7);  // thiscall ECX=this
*this = &PTR_FUN_009d15c4;
return this;                                   // ret 0x18
```

RTTI name string at `0x00af1d88`: `.?AVCVOGHBSkill_OnDoHit@@`.  
COL `0x00aae1a0` → type_info `0x00af1d80`.  
Entry bytes: `mov esi,ecx` … `call 0x005788d0` … `mov [esi],0x009d15c4` … `mov eax,esi` / `pop esi` / `ret 0x18`.

---

## 4. Surviving contract for AutoCore

```
// OnDoHit intermediate HB construction:
void *hb = /* allocated by caller (subclass may be 0x6d0+) */;
CVOGHBSkill_OnDoHit_Ctor(hb, pSource, pSkillBlob, arg4, pTarget, pTfid16, arg7);
// hb vtbl = OnDoHit (009d15c4); SkillBase ValidateTarget/attach already ran
// Callers may immediately overwrite vtbl for further subclasses.
```

Do not invent product names beyond RTTI `CVOGHBSkill_OnDoHit`.  
Do not treat this as the final class for callers that reinstall `009d1624` / `009d185c`.

**Verdict:** **accept**.
