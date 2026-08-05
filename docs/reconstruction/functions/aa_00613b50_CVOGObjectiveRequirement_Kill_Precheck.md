# Function record: CVOGObjectiveRequirement_Kill_Precheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613b50` |
| **Canonical name** | `CVOGObjectiveRequirement_Kill_Precheck` |
| **Address** | `0x00613b50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Vtable** | Kill req `0x009e19e4` slot **+0x4** (Eval @ +0x8 = `0x00613910`) |
| **Calling convention** | `thiscall`; **7** stack args; **`RET 0x1c`** |
| **Completion status** | **Dual A/B strengthened 2026-07-29** — ABI + mutate + Eval pure-read sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Kill precheck: filter kill context, **increment** progress slot float (`state+4+slot*4`), optional FailMission. Early-outs when sibling **Kill_Eval** already reports complete.

## Signature (asm-sealed)

```
u8 __thiscall Kill_Precheck(
  req* this,           // ECX
  Entity* ctx,         // arg1 — killer/context; faction compare
  float* state,        // arg2 — progress blob (EBP)
  int typeCode,        // arg3 — must be 0
  float cbidOrVal,     // arg4 — CVTTSS2SI for direct CBID when flag+0x11 clear
  float addend,        // arg5 — default/vehicle credit delta
  void* unused,        // arg6 — no body refs
  Entity* victim       // arg7 — EDI
);
```

## Slot formula (shared with Eval)

```
slot     = *(u8*)(req + 0x08)
progress = *(float*)(state + 4 + slot * 4)
required = (float)*(i32*)(req + 0x18)
```

| Writer | Mode |
|---|---|
| This Precheck | `progress += addend` or `+=(float)victim.vcall(+0x244)` |
| Kill_Eval | **read only** — complete iff `progress >= required` |
| Client_RecvObjectiveState `0x00809460` | absolute overwrite (S2C `0x2071`) |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` |
| Annotated | `raw/aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Kill_Precheck.cpp` |
| Dual A | `reviews/A_aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` |
| Dual B | `reviews/B_aa_00613b50_CVOGObjectiveRequirement_Kill_Precheck.md` |
| Eval sibling | `functions/aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + three mutate sites | **High / Confirmed** (asm) |
| State (arg2) vs addend (arg5) split | **High / Confirmed** |
| Eval pure-read contrast | **High / Confirmed** |
| Parameter product English names | Probable / Tentative |
| Runtime / bit-exact | Open |

## Open questions

- Live kill capture of addend + slot delta
- Product names for `+0x531` / `+0x532` / bitmasks
- arg6 caller role
- Server field map for req object
