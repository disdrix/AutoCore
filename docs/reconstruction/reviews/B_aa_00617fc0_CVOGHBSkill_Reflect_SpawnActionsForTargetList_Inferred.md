# Review B (skeptical / adversarial): `aa_00617fc0` CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617fc0` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-08-05` (R12-039 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md` |
| **Dual start** | 2646 |
| **Verdict** | **accept-with-gaps** on CF/RTTI/ABI; reject overclaims listed below |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This VA is a **subclass ctor** | **Falsified as ctor** — body is list factory; true OnHit intermediate ctor is `FUN_00617ad0` (called). Reflect construction is new+ctor+vtbl overwrite. |
| 2 | Class is still `CVOGHBSkill_OnHit` (same as parent dual) | **Falsified** — RTTI `.?AVCVOGHBSkill_Reflect@@` via COL `0x00aadc14`; installs vtbl `009d0f7c` not `009d0f1c`. |
| 3 | Same method as OnHit spawn `FUN_00617df0` | **Falsified** — different vtbl slot owner; this unit has vehicle 0xe remap + calls OnHit_ctor instead of inlining base+OnHit vtbl. |
| 4 | Free function / not virtual | **Falsified** — sole xref DATA @ vtbl+0x2c `0x009d0fa8` |
| 5 | Uses virtual `this` (ECX) as HB context | **Falsified** — body never consumes entry ECX; all context from stack |
| 6 | ResolveObjectTarget is free/static 3-arg | **Falsified** — assembly loads ECX from `world+0xe4e8` (thiscall) |
| 7 | Return `1` means “spawned one action” | **Falsified** — always `1` on terminator regardless of spawn count |
| 8 | Always Enqueue | **Falsified** — gated on `pOwner(+0x18) != 0`; else dtor(1) |
| 9 | Period seeded in this body | **Falsified** — period writes live inside callee `CVOGHBSkill_OnHit_ctor` only |
| 10 | Vehicle branch always runs | **Falsified** — only when clone type dword == `0xe` |
| 11 | Merge with Virus / SpawnEntities | **Falsified** — Virus size `0x6e0`/vtbl `009d14bc`; SpawnEntities vtbl `009d0ec4` |
| 12 | Product method name without string | **Overclaim risk** — keep `_Inferred` |
| 13 | Null new / null cast is safe | **Falsified as safe** — falls into `[ESI+0x18]` or `+[0xb0]` with null base |
| 14 | Partition parent `0x00617ad0` is CODE caller of this VA | **Falsified direction** — parent is **callee** (OnHit ctor); this unit is a factory that *calls* parent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class RTTI Reflect | **Confirmed** | Wrong skill hierarchy |
| List stride 0x10 + terminator | **Confirmed** | Infinite loop / miss targets |
| new 0x6d0 + OnHit_ctor + Reflect vtbl | **Confirmed** | Wrong object layout |
| Enqueue list world+0xe4ec | **Confirmed** | HB never ticks |
| Vehicle type 0xe + host +0xb0 | **Confirmed** (static) | Wrong attach target on vehicles |
| Method English | Tentative | Docs only |
| arg7 / tfid product names | Tentative | Wrong wire map |
| Host English at +0xb0 | Tentative product word | Port docs wording |
| Why virtual this unused | Open (static fact High) | Caller ABI confusion |

---

## 3. Cross-check: family contrast

```
CVOGHBSkill_Reflect (vtbl 009d0f7c)         [this unit's class]
  COL 0x00aadc14 → type_info 0x00af28f4  ".?AVCVOGHBSkill_Reflect@@"
  slot+0x2c: FUN_00617fc0  multi-target spawn factory   [OWN R12-039]
  slot+0x00: FUN_00651190  scalar-deleting dtor
  construct path: new(0x6d0) → CVOGHBSkill_OnHit_ctor → overwrite Reflect vtbl

CVOGHBSkill_OnHit (vtbl 009d0f1c)           [parent dual R11-012]
  ctor:      FUN_00617ad0  (thiscall; installs OnHit vtbl + period)
  slot+0x2c: FUN_00617df0  multi-target spawn (no vehicle remap)

Skill_HB_SpawnEntities (vtbl 009d0ec4)     [do not merge]
  ctor:     0x00614dc0
  execute:  0x00615020

CVOGHBSkill_Virus (vtbl 009d14bc)          [do not merge]
  size 0x6e0; budget +0x6d0; OnHB 0x0061fdf0
```

**Attack on partition parent `0x00617ad0`:** parent is **callee** (OnHit intermediate ctor), not a CODE parent of this virtual. Live structural “caller” is vtbl dispatch only.

---

## 4. Surviving contract for AutoCore

```
CVOGHBSkill_Reflect_SpawnActionsForTargetList(pSource, pSkill, pWorld, pList, pTfid, arg7):
  // ECX this ignored
  i = 0
  loop:
    e = pList + i*0x10
    if e.id0==-1 && e.id1==-1 && e.type==0: return 1
    t = ResolveObjectTarget(*(pWorld+0xe4e8), e.type, e.id0, e.id1)
    if t:
      if *(*(t+0xa8)+0x38) == 0xe:
        v = RTDynamicCast(t, CVOGClonedObjectBase → CVOGVehicle)
        t = *(*(*(v+4)+4) + v + 0xb0)
      a = new(0x6d0)
      if a:
        CVOGHBSkill_OnHit_ctor(a, pSource, pSkill, pWorld, t, pTfid, arg7)
        a.vtbl = CVOGHBSkill_Reflect
      if a.owner(+0x18):
        Enqueue(*(pWorld+0xe4ec), a); Start(a)
      else:
        a.vtbl[0](a, 1)   // delete
    i++
```

Port notes:

- Keep Enqueue **then** Start.
- Do not treat return as spawn count.
- Vehicle targets attach to host at COM `+0xb0`, not the vehicle object itself.
- Period seed lives in OnHit_ctor (`+0x6c0`/`+0x6c4` from skill float `+0x4c`).
- Class name may be registered without `_Inferred`; method name keeps `_Inferred`.

---

## 5. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product method English | No (name `_Inferred`) |
| R2 | List producer / virtual invoker | No |
| R3 | Null-new / null-cast production contract | Mild |
| R4 | Host product word for vehicle+0xb0 | No |
| R5 | Runtime Confirmed | N/A (Terminal false) |

---

## 6. Concrete checks performed

1. Re-decompile `0x00617fc0` (live ≡ scaffold CF).  
2. Full `disassemble_function` — seal RET 0x18, Resolve ECX, vehicle branch, Reflect vtbl imm.  
3. `read_memory` vtbl + COL + type_info string (`.?AVCVOGHBSkill_Reflect@@`).  
4. Confirm RTDynamicCast descriptors: `CVOGClonedObjectBase` @ `0x00af8e10`, `CVOGVehicle` @ `0x00aff68c`.  
5. Contrast parent `FUN_00617ad0`, sibling OnHit spawn `FUN_00617df0`, SpawnEntities/Virus duals.  
6. `get_function_xrefs` / callers: DATA-only, no CODE.  
