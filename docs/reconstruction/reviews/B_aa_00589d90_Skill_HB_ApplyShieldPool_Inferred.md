# Review B (skeptical / adversarial): `aa_00589d90` Skill_HB_ApplyShieldPool_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589d90` |
| **VA** | `0x00589d90` |
| **Canonical name** | `Skill_HB_ApplyShieldPool_Inferred` |
| **Review date** | `2026-08-05` (MEGA-007 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent/sibling decompiles |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** `Vehicle_SetCurrentShield` | **Falsified** — that plate is `0x00419140` (thiscall, absolute set, void); this VA is cdecl 3-arg resolve+delta+return |
| 2 | This is HP apply (`00589c70`) | **Falsified** — HP uses `vtbl+0x23c/0x244` and `FUN_004d7e30`; this uses `+0x144/+0x148` store and `vtbl+0x1d4` |
| 3 | This is heat apply (`00589bc0`) | **Falsified** — heat uses `__RTDynamicCast` + `Vehicle_AddHeat`; no RTTI here |
| 4 | thiscall ECX=pool / ECX=skill | **Falsified** — prologue `PUSH ESI; MOV ESI,[ESP+0xC]` (param_2); bare `RET` not `RET n`; callers `ADD ESP,0xC` |
| 5 | Amount is always absolute integer | **Falsified** — `COMISS` gate vs `-1.0f` and `1.0f` switches to `max * amount` fraction |
| 6 | Amount is always fraction of max | **Falsified** — outside `[-1,1]` path is plain `CVTTSS2SI` of amount |
| 7 | Writes max shield / armor / heat | **Falsified** — store only to **`+0x144`**; reads max at **`+0x148`** for clamp/fraction |
| 8 | No return / void | **Falsified** — returns `new-old` in EAX when changed |
| 9 | Direct callees / CRT | **Falsified** — analyze callees empty; only virtual indirect calls |
| 10 | Product name sealed without `_Inferred` | **Open** — no string/RTTI on VA; `_Inferred` required |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
; cdecl entry — param_2 in ESI
PUSH ESI
MOV  ESI, [ESP+0xC]          ; preferredHost
TEST ESI, ESI
...
CALL [EAX+0x19c]             ; resolve
LEA  ECX, [EDX+EAX+4]        ; MI component
...
MOV  ECX, [ESI+0xAC]         ; secondary host fallback
...
CALL [EAX+0x1d4]             ; combat pool
MOVSS XMM0, [ESP+0x10]       ; amount
COMISS XMM0, [-1.0f@aaa668]
CVTTSS2SI EAX, XMM0          ; absolute trunc (default)
JC   skip_frac
COMISS [1.0f@a0f2a0], XMM0
JC   skip_frac
CVTSI2SS XMM1, [EDX+0x148]   ; max
MULSS XMM1, XMM0
CVTTSS2SI EAX, XMM1          ; fraction → delta
skip_frac:
MOV  ESI, [EDX+0x144]        ; cur
MOV  ECX, [EDX+0x148]        ; max
ADD  EAX, ESI                ; cur+delta
; clamp to [0, max] → EAX
MOV  [EDX+0x144], EAX
JZ   ret0
SUB  EAX, ESI                ; return applied delta
POP  ESI
RET                          ; C3 — caller ADD ESP,0xC
```

Body end: `C3` @ `0x00589e5c`; pad `CC`.

Call-site pattern (parent `0061b88f` family):

```text
; amount = period(+0x6c4) * shieldField(+0x144 on HB)
; PUSH float; PUSH object; CALL FUN_00578270; PUSH EAX; CALL 00589d90; ADD ESP,0xC
```

A ≡ B on live decompile + body disassembly + constants + xrefs.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 3-arg + RET + ADD ESP,0xC | **High** | ABI smash |
| Shield current/max +0x144/+0x148 | **High** | wrong pool field |
| Fraction band [-1,1] | **High** | wrong delta scale |
| Resolve chain 0x19c / +0xAC / 0x1d4 | **High** | wrong host |
| Not heat / not HP / not SetCurrentShield | **High** | wrong system merge |
| Skill-HB consumer role | **High** | parents sealed |
| Product English | Medium | naming only |
| Orphan site 0061be96 owner | Medium | missing consumer plate |
| Runtime | Open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// cdecl; caller cleans 12 bytes. Returns actual applied delta (may be negative).
int SkillHbApplyShieldPool(
    object? fallbackHost,
    object? preferredHost,
    float amount)
{
    var component = ResolveCombatComponent(preferredHost)
                 ?? ResolveCombatComponent(SecondaryAt0xAC(preferredHost))
                 ?? ResolveCombatComponent(fallbackHost);
    if (component is null) return 0;

    var pool = component.GetVehicleCombatPool(); // vtbl+0x1d4
    if (pool is null) return 0;

    int delta = (amount >= -1f && amount <= 1f)
        ? (int)(pool.MaxShield * amount)   // +0x148
        : (int)amount;

    int cur = pool.CurrentShield;          // +0x144
    int max = pool.MaxShield;
    int next = Math.Clamp(cur + delta, 0, max);
    pool.CurrentShield = next;
    return next == cur ? 0 : next - cur;
}
// Keep distinct from Vehicle_SetCurrentShield (absolute thiscall),
// Skill_HB_ApplyHpDelta (0x00589c70), Skill_HB_ApplyHeatDelta (0x00589bc0).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/field plate/fraction gate and **rejects** heat/HP/SetCurrentShield merges and thiscall claims. Residual product symbol English + orphan site plate → **accept-with-gaps**.
