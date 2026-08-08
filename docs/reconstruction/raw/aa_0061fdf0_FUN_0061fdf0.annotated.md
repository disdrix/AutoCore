# Annotated low-level: CVOGHBSkill_Virus_OnHeartBeat (`FUN_0061fdf0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0061fdf0` |
| VA | `0x0061fdf0`–`0x00620186` |
| System | skills-abilities / heartbeat |
| Date | 2026-07-23 scaffold; **2026-08-04 WQ9R-B dual seal** |

---

## Identity

| Item | Value | Confidence |
|---|---|---|
| Class | `CVOGHBSkill_Virus` | **Confirmed** RTTI `.?AVCVOGHBSkill_Virus@@` |
| Slot | vtbl `PTR_FUN_009d14bc` **+0x0c** | **High** |
| Role | **OnHeartBeat** (invoked from `CVOGHBBase_TryFire`) | **High** |
| ABI | `__thiscall`; stack out-status `uint32*`; **`ret 4`** | **High** |

## Control flow (annotated)

```
1. SEH frame; FUN_0061b6f0(&statusOut)          // shared skill-HB pulse / side effects
2. target = FUN_00578270()                        // resolve skill attach TFID → object
3. if target==null OR target.vtbl+0x198() != 0:
     this.vtbl+0x18(1,1)                          // fail/stop arm
     *out = 0; return
4. if skillWorld(+0x688)+0x7e == 0 OR this+0x10 (==period counter dword[4]) == 0:
     *out = statusFromPulse; return               // no multi-spread
5. RNG: sample unit table; if (u16 % 100) <= 25: skip spread; *out = status; return
6. RTTI: owner this+0x18 (pOwner) must cast to CVOGCreature with +0x250!=0
     OR cast to CVOGPhysicsBase; else *out=0 return
7. origin = Object_GetWorldPositionPtr (FUN_00404c90)  // float4
8. seed outTfidList[0] = null TFID (DAT_009e2df0..)
9. radius = this+0x5c (dword[0x17]) if !=0 else 50.0f
10. maxTargets = *(u8*)(this+0x102); if 0 → 4
11. Skill_GatherTargetsInArea(..., mode=1, filterA=-1, ...)  // ally gather
12. if list non-null TFID AND this+0x6d0 (dword[0x1b4]) > 0:
      fill random pad via CVOGReaction_RandomUnitScalar + FUN_0051b720(600,..)
      decrement this+0x6d0 and this+0x6d4 (budget/period remain)
      for each TFID in list until null sentinel:
        obj = Object_ResolveFromTFID(entry)
        if obj:
          hb = new(0x6e0); CVOGHBSkill_Virus_ctor (FUN_0061f940)(...)
          if hb.pOwnerObject==null: scalar dtor(1)
          else: CVOGHBList_Enqueue(world+0xe4ec, hb); CVOGHBBase_Start(hb);
                record TFID into local pad
      terminate pad with null TFID
13. *out = statusFromPulse; return
```

## Key constants (`read_memory`)

| Symbol | Value |
|---|---|
| `DAT_00a0f524` | `0x42480000` = **50.0f** default radius |
| `DAT_009e2df0` | null TFID 16 B `FFFFFFFF FFFFFFFF 00000000 00000000` |
| `DAT_00d02af0` | zeroed 16 B (ctor TFID arg) |
| Child size | **0x6e0** |
| RNG threshold | **0x19** (25) |

## Callees (owned residual neighbors not dualed here)

| Callee | VA | Role |
|---|---|---|
| `FUN_0061b6f0` | `0x0061b6f0` | parent skill pulse |
| `FUN_00578270` | `0x00578270` | resolve attach target |
| `Skill_GatherTargetsInArea` | `0x0058d330` | ally area gather mode 1 |
| `FUN_0061f940` | `0x0061f940` | `CVOGHBSkill_Virus` ctor |
| `CVOGHBList_Enqueue` | `0x005078f0` | pending list |
| `CVOGHBBase_Start` | `0x005081c0` | arm child |
| `Object_ResolveFromTFID` | `0x004bb950` | TFID → object |
| `FUN_00404c90` | `0x00404c90` | world position ptr |
| `FUN_0051b720` | `0x0051b720` | RNG table copy (WQ9R-A owned) |
| `CVOGReaction_RandomUnitScalar` | `0x007a4330` | RNG host |
| `__RTDynamicCast` | — | Creature / PhysicsBase |

## Open

- Product English for skill effect "Virus" beyond RTTI.
- Exact semantic of `+0x7e` flag and `+0x102` maxTargets field English.
- Whether loop resolve uses advancing `pA` (logical) vs decompiler sticky `aTStack_ca0` (noise risk).
- Runtime / bit-exact / child stacking.
