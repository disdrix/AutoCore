# Annotated low-level: CVOGObjectiveRequirement_Kill_Precheck

| Field | Value |
|---|---|
| Stable ID | `aa_00613b50` |
| VA | `0x00613b50` |
| System | missions-progression |
| Date | 2026-07-29 (asm residual; prior 2026-07-23 scaffold) |

## Machine-level notes

- Prefer **assembly** over decompiler for this unit: decomp merges state/addend and prints `+ 0.0`.
- Slot formula matches Kill_Eval: `state + 4 + slot*4`, `slot = *(u8*)(req+8)`.
- Side effects: float stores on credit paths; optional `CVOGReaction_FailMission` (`0x0052da30`).
- Vehicle path early-returns success **without** FailMission tail.

## ABI (asm)

```
thiscall ECX = req
arg1  ctx entity          → faction compare; FailMission ECX; Eval unused arg
arg2  state blob          → EBP; all progress R/W
arg3  typeCode            → must be 0
arg4  float (CBID path)   → CVTTSS2SI vs req+0x14 when +0x11 clear
arg5  float addend        → ADDSS default/vehicle
arg6  unused in body
arg7  victim entity       → EDI
RET 0x1c
```

## Annotated control flow (asm-backed)

```
// gates
if (typeCode != 0) return 0;
if (Kill_Eval(req, ctx, state)) return 0;   // pure read — no credit if already complete

// vehicle branch (req+0x10)
if (vehicle_flag) {
  // victim +0x1d4 / +0x210(0); reject same faction@+0x532 (ctx vs victim)
  // optional level band +0x27c vs req+0x30/+0x34
  // bitmasks req+0x24 (faction), req+0x28 (byte@+0x531)
  progress[slot] += addend;                 // ADDSS [ESP+0x24]
  return 1;                                 // no FailMission
}

// direct (req+0x12==0) or type-0xe entity path
// CBID / type / level filters; reject if required_i32 <= progress
if (xp_flag req+0x13 && victim)
  progress[slot] += (float)victim.vcall(+0x244);
else
  progress[slot] += addend;

if (fail_flag req+0x1c) { FailMission(...); return 0; }
return 1;
```

## Contrast vs Eval (`0x00613910`)

| | Precheck | Eval |
|---|---|---|
| Slot address | `state+4+slot*4` | same |
| Memory ops | **ADDSS store** | **load only** |
| Filters | CBID/level/faction/type | none |
| Calls | Eval, entity vcalls, FailMission | none |

## Open questions

- Live capture of arg5 / slot delta on kill
- Product English for +0x531 / +0x532
- arg6 caller role
