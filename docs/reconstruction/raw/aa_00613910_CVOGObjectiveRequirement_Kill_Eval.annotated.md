# Annotated low-level: CVOGObjectiveRequirement_Kill_Eval

| Field | Value |
|---|---|
| Stable ID | `aa_00613910` |
| VA | `0x00613910` |
| System | missions-progression |
| Date | 2026-07-23; residual refine 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_00613910`; **asm re-verify 2026-07-29**.
- Prefer assembly when decompiler conflicts — **decomp ≡ asm** this unit.
- Integer `@+0x18` converted with **CVTSI2SS** (not float load).
- Compare: `COMISS XMM1(progress), XMM0(required)`; `JC` → incomplete; else complete.
- Side effects: **none** (no stores, no calls).
- Stack: thiscall ECX=req; `[ESP+4]` unused arg; `[ESP+8]`=state; `RET 8`.
- Vtable: entry at `0x009e19ec` (slot +0x8 of `0x009e19e4`); Precheck at +0x4.

## Pseudocode (annotated)

```c
// vtable +0x8 Kill requirement eval
// returns 1 complete / 0 in-progress
undefined4 __thiscall CVOGObjectiveRequirement_Kill_Eval(
    int req,            // ECX — CVOGObjectiveRequirement_Kill*
    undefined4 unused,  // stack arg0 — never read
    int state)          // stack arg1 — active-objective state node*
{
  // requiredKills: int @ req+0x18 → float
  // slot: byte @ req+0x08
  // progress: float @ state + 4 + slot*4
  if ((float)*(int *)(req + 0x18) <=
      *(float *)(state + 4 + (uint)*(byte *)(req + 8) * 4))
  {
    return 1;
  }
  return 0;
}
```

## Assembly spine

```
MOVZX  EAX, [ECX+8]           ; slot
CVTSI2SS XMM0, [ECX+0x18]     ; required
MOV    ECX, [ESP+8]           ; state
MOVSS  XMM1, [ECX+EAX*4+4]    ; progress
COMISS XMM1, XMM0
JC     fail
MOV    AL, 1 / RET 8
fail: XOR AL,AL / RET 8
```

## Cross-function (read-only)

- Precheck `0x00613b50` vcalls this before credit; mutates same slot address.
- RecvObjectiveState `0x00809460` absolute-writes `state[1..4]`.

## Open questions

- Runtime capture; bit-exact image diff.
- Precheck addend residual (not this unit).
