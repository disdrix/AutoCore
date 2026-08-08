# Review B (skeptical / adversarial): `aa_00617ad0` CVOGHBSkill_OnHit_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` |
| **Verdict** | **accept-with-gaps** on identity/CF/ABI; field English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is OnHeartBeat / tick body | Body is linear ctor; only base CALL + stores + RET | **Falsified** |
| 2 | Generic HB / still `FUN` only | RTTI `.?AVCVOGHBSkill_OnHit@@` + exclusive vtbl install | **Falsified** — class Confirmed |
| 3 | Name is `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` | That plate is one subclass path (`FUN_00623330`); RTTI names product class | **Falsified** — plate retired |
| 4 | `cdecl` / wrong stack cleanup | Dual `RET 0x18` (6×4) | **Falsified** — thiscall + 6 stack |
| 5 | Decompiler dword indices wrong offsets | Asm: `ESI+0x6c0` / `ESI+0x6c4` absolute | **Offsets sealed** (indices 0x1b0/0x1b1 ≡ ×4) |
| 6 | Float compare uses wrong zero | `UCOMISS` vs `0x00a0f518` = all-zero dword | **Sealed** as `g_flZero` |
| 7 | Cast rounds (not truncates) | `CVTTSS2SI` truncates toward 0 | **Sealed** as truncate |
| 8 | Flag=0 zeros `+0x6c0` | Zero path only writes `+0x6c4=0` | **Falsified as zero-store** — gap: may be uninit |
| 9 | Object size not 0x6d0 | Multiple callers `operator_new(0x6d0)`; one subclass uses 0x6e0 after this base | **Survives High** for OnHit shell |
| 10 | Sole factory is this function | Sibling `FUN_00617df0` (R11-013) inlines same field init without calling this VA | **Survives** as multi-factory family; this VA still the named ctor |
| 11 | `+0x6c0` is HB period (`SetPeriodAndCounter`) | Base period is `+0x0C`/`+0x10` from blob `+0x3C`; this field is separate tail | **Falsified as period-merge** |
| 12 | Parent attach uses source not target | Parent dual sealed attach=target; this unit only forwards args | **Survives** parent seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| OnHit RTTI + vtbl + ctor role | **Confirmed** | Wrong skill class factory |
| `+0x6c0` / `+0x6c4` / ret 0x18 | **Confirmed** | Layout / ABI bug |
| Product English for float seed | **Open** | Doc only |
| Flag=0 `+0x6c0` contents | **Open** | Stale int if consumers ignore flag |
| Runtime OnHit behavior | **Open** | Unverified live |

---

## 3. Cross-check raw + live

Live decompile 2026-08-05 ≡ 2026-07-23 raw CF (callee rename only):

```
CVOGHBSkillBase_ctor(p2..p7);   // thiscall ECX=this
*this = &PTR_FUN_009d0f1c;
if (*(float*)(blob+0x4c) != g_flZero) {
  *(u8*)(this+0x6c4) = 1;
  *(int*)(this+0x6c0) = (int)*(float*)(blob+0x4c);  // CVTTSS2SI
  return this;  // ret 0x18
}
*(u8*)(this+0x6c4) = 0;
return this;    // ret 0x18
```

RTTI name string at `0x00af1d68`: `.?AVCVOGHBSkill_OnHit@@`.  
Asm body `0x00617ad0`–`0x00617b33`; pad `CC` at `0x00617b34`.

---

## 4. Surviving contract for AutoCore

```
// OnHit-family factory pattern (callers vary post-vtbl):
void *hb = operator_new(0x6d0);
CVOGHBSkill_OnHit_ctor(hb, source, skillBlob, arg4, target, tfid, arg7);
// hb vtbl = OnHit; +0x6c4 enable; +0x6c0 int seed if enable
// optional: *hb = subclass_vtbl; extra fields
if (hb->pOwner) { CVOGHBList_Enqueue(world+0xe4ec, hb); CVOGHBBase_Start(hb); }
else            { hb->vtbl->scalar_dtor(1); }
```

Do not merge with Virus ctor (`0x0061f940`, size 0x6e0, budget/period at +0x6d0/+0x6d4).  
Do not treat `+0x6c0` as `SetPeriodAndCounter` period.

**Verdict:** **accept-with-gaps**.
