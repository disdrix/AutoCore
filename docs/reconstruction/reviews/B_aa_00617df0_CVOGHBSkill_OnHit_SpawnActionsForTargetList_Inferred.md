# Review B (skeptical / adversarial): `aa_00617df0` CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617df0` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-08-05` (R11-013 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00617df0_CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/RTTI/ABI; reject overclaims listed below |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This VA is a **subclass ctor** (parent ledger “14 subclass ctors”) | **Falsified as ctor** — body is list factory; true ctor is `FUN_00617ad0`. It *calls* base ctor on **new** objects. |
| 2 | Class name unknown / invent English | **Falsified** — RTTI `.?AVCVOGHBSkill_OnHit@@` Confirmed via COL `0x00aadbc4` |
| 3 | Same class as SpawnEntities (`PTR_FUN_009d0ec4`) | **Falsified** — different vtbl `009d0f1c`; different RTTI |
| 4 | Free function / not virtual | **Falsified** — sole xref DATA @ vtbl+0x2c `0x009d0f48` |
| 5 | Uses virtual `this` (ECX) as HB context | **Falsified** — body never consumes entry ECX; all context from stack |
| 6 | Decompiler `pAction[0x2b].nPeriod*` layout | **Falsified** — machine `+0x6c0`/`+0x6c4` only |
| 7 | ResolveObjectTarget is free/static 3-arg | **Falsified** — assembly loads ECX from `world+0xe4e8` (thiscall) |
| 8 | Return `1` means “spawned one action” | **Falsified** — always `1` on terminator regardless of spawn count |
| 9 | Always Enqueue | **Falsified** — gated on `pOwner(+0x18) != 0`; else dtor(1) |
| 10 | Period always written to `+0x6c0` | **Falsified** — zero float only clears flag `+0x6c4`; no store to `+0x6c0` |
| 11 | Merge with Virus ctor / OnHB | **Falsified** — Virus size `0x6e0`, vtbl `009d14bc`, different fields |
| 12 | Product method name without string | **Overclaim risk** — keep `_Inferred` |
| 13 | Null new is safe | **Falsified as safe** — falls into `[ESI+0x18]` with ESI=0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class RTTI OnHit | **Confirmed** | Wrong skill hierarchy |
| List stride 0x10 + terminator | **Confirmed** | Infinite loop / miss targets |
| new 0x6d0 + base + OnHit vtbl | **Confirmed** | Wrong object layout |
| Enqueue list world+0xe4ec | **Confirmed** | HB never ticks |
| Period skill+0x4c → +0x6c0/+0x6c4 | **Confirmed** | Wrong timer seed |
| Method English | Tentative | Docs only |
| arg7 / tfid product names | Tentative | Wrong wire map |
| Why virtual this unused | Open (static fact High) | Caller ABI confusion |

---

## 3. Cross-check: family contrast

```
CVOGHBSkill_OnHit (vtbl 009d0f1c)          [this unit's class]
  ctor:     FUN_00617ad0  (thiscall; installs vtbl + period)   [R11-012 OWN]
  slot+0x2c: FUN_00617df0  multi-target spawn factory           [OWN R11-013]
  slot+0x00: FUN_00651190  scalar-deleting dtor

Skill_HB_SpawnEntities (vtbl 009d0ec4)     [do not merge]
  ctor:     0x00614dc0
  execute:  0x00615020  (much larger entity spawn pipeline)

CVOGHBSkill_Virus (vtbl 009d14bc)          [do not merge]
  size 0x6e0; budget +0x6d0; OnHB 0x0061fdf0
```

**Attack on partition parent `0x005788d0`:** parent is **callee** (base ctor), not live CODE parent of this virtual. Live structural “caller” is vtbl dispatch only.

---

## 4. Surviving contract for AutoCore

```
CVOGHBSkill_OnHit_SpawnActionsForTargetList(pSource, pSkill, pWorld, pList, pTfid, arg7):
  // ECX this ignored
  i = 0
  loop:
    e = pList + i*0x10
    if e.id0==-1 && e.id1==-1 && e.type==0: return 1
    t = ResolveObjectTarget(*(pWorld+0xe4e8), e.type, e.id0, e.id1)
    if t:
      a = new(0x6d0)
      if a:
        CVOGHBSkillBase_ctor(a, pSource, pSkill, pWorld, t, pTfid, arg7)
        a.vtbl = CVOGHBSkill_OnHit
        if skill.float(+0x4c) == 0: a.u8(+0x6c4)=0
        else: a.u8(+0x6c4)=1; a.i32(+0x6c0)=(int)trunc(float)
      if a.owner(+0x18):
        Enqueue(*(pWorld+0xe4ec), a); Start(a)
      else:
        a.vtbl[0](a, 1)   // delete
    i++
```

Port notes:

- Keep Enqueue **then** Start.
- Do not treat return as spawn count.
- Do not trust decompiler `pAction[0x2b]` field overlay.
- Class name may be registered without `_Inferred`; method name keeps `_Inferred`.

---

## 5. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product method English | No (name `_Inferred`) |
| R2 | List producer / virtual invoker | No |
| R3 | Null-new production contract | Mild |
| R4 | OnHit tick consumers of +0x6c0 | No |
| R5 | Runtime Confirmed | N/A (Terminal false) |

---

## 6. Concrete checks performed

1. Re-decompile `0x00617df0` (live ≡ scaffold CF; base renamed).  
2. Full `disassemble_function` — seal RET 0x18, period offsets, Resolve ECX.  
3. `read_memory` vtbl + COL + type_info string.  
4. Confirm `g_flZero` @ `0x00a0f518` is 0.0f.  
5. Decompile `FUN_00651190` scalar dtor; `CVOGReaction_ResolveObjectTarget`.  
6. Contrast sibling ctor `FUN_00617ad0` and SpawnEntities/Virus duals.  
7. Xrefs: DATA-only vtbl slot.

---

## 7. Verdict

**accept-with-gaps** — RTTI class, CF, ABI, period, Enqueue path sealed; method English + call-site inventory + null-new residual open. Terminal **false**.
