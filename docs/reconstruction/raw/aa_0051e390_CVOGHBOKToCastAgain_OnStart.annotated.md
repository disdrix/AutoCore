# Annotated low-level: CVOGHBOKToCastAgain_OnStart

| Field | Value |
|---|---|
| Stable ID | `aa_0051e390` |
| VA | `0x0051e390` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0051e390`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGHBOKToCastAgain_OnStart (vtable activate)
   If owner skill attached: Skill_SetIsCastingFlag(skill, 1), CVOGHBBase_ResetStartTick. */

void __fastcall CVOGHBOKToCastAgain_OnStart(void *pHeartbeat)

{
  char unaff_SI;
  
  if (*(int *)((int)pHeartbeat + 0x18) != 0) {
    Skill_SetIsCastingFlag(*(void **)((int)pHeartbeat + 0x24),(void *)0x1,unaff_SI);
  }
  CVOGHBBase_StampLastFireTime(pHeartbeat);
  return;
}
```

## Open questions (2026-07-23 capture)

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

---

## Dual residual seal (2026-07-29) — asm / read_memory

**Do not treat raw decomp `unaff_SI` / 3-arg flag call as authoritative.**

### Body

```
push esi
mov  esi, ecx
cmp  dword [esi+0x18], 0
je   skip
mov  ecx, [esi+0x24]      ; skill
push 1                    ; char flag
call Skill_SetIsCastingFlag (0x005502d0)
skip:
mov  ecx, esi
pop  esi
jmp  CVOGHBBase_StampLastFireTime (0x00508270)
```

### Sealed slots

| Site | Meaning |
|------|---------|
| HB+0x18 | owner entity gate (ctor AttachOwner **owner**) |
| HB+0x24 | skill runtime (flag thiscall target) |
| skill+0x628 | cast flag **byte** |
| skill+0x170 / +0x178 | true path: float0 + tick stamp |
| HB+0x14 | last fire tick (stamp) |
| vtbl 0x009ce1c8 | this OnStart |

### Closed residuals

- SetIsCastingFlag ABI: `__thiscall` + 1× char stack + `RET 4`
- `unaff_SI` phantom third arg: **falsified**
- +0x18 owner vs +0x24 skill: **split sealed**
- Plate “ResetStartTick”: misnomer for StampLastFireTime

See `reviews/a_0051e390.md`.
