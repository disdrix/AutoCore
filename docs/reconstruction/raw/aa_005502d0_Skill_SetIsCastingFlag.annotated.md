# Annotated low-level: Skill_SetIsCastingFlag

| Field | Value |
|---|---|
| Stable ID | `aa_005502d0` |
| VA | `0x005502d0` |
| System | skills-abilities |
| Date | 2026-07-29 (dual residual seal; prior 2026-07-23) |

## Machine-level notes

- Source: raw capture + 2026-07-29 `read_memory` body/callers (no `disassemble_bytes`).
- Prefer machine body when decompiler invents extra formals.
- `g_dwClientTickMs` = `DAT_00b041cc`.

## Machine body (sealed)

```
mov  al, [esp+4]              ; bIsCasting
test al, al
mov  [ecx+0x628], al          ; skill+0x628 is-casting byte
je   ret4
xorps xmm0, xmm0
movss [ecx+0x170], xmm0       ; float 0
mov  eax, [g_dwClientTickMs]
mov  [ecx+0x178], eax
ret  4
```

## Corrected signature (not decomp plate)

```c
void __thiscall Skill_SetIsCastingFlag(void *thisSkill, char bIsCasting);
// always: *(char*)(thisSkill+0x628) = bIsCasting;
// if (bIsCasting): *(float*)(thisSkill+0x170)=0.f; *(uint*)(thisSkill+0x178)=g_dwClientTickMs;
```

## Callers

| Site | Flag |
|---|---|
| `CVOGHBOKToCastAgain_OnStart` | 1 |
| `CVOGHBOKToCastAgain_OnEnd` | 0 |
| `FUN_0052c780` hash walk | 0 |

## Consumers of `+0x628`

- `Skill_LocalCastValidate` — busy → eSkillResponses **7**
- `QuickBar_UpdateSkillSlotCooldownGauge` / `UpdateSlotCooldownOverlay` — charge path via `+0x178`

## Open questions

- Product / PDB English for `+0x628` / `+0x170` / `+0x178`
- Full product name of `FUN_0052c780`
- Runtime / bit-exact
