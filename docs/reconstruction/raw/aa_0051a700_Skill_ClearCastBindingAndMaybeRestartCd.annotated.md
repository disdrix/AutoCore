# Annotated low-level: Skill_ClearCastBindingAndMaybeRestartCd

| Field | Value |
|---|---|
| Stable ID | `aa_0051a700` |
| VA | `0x0051a700` |
| System | skills-abilities |
| Date | 2026-07-23 (residual annotate 2026-07-29) |

## Machine-level notes

- Source: raw capture for `aa_0051a700` + PE body seal 2026-07-29.
- Prefer assembly / PE bytes when decompiler conflicts (this unit: **yes** conflicts).
- Dual A/B: `reviews/A\|B_aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md`
- Scratch: `reviews/a_0051a700.md`

### PE-sealed facts

| Fact | Evidence |
|---|---|
| `RET 0x14` (5 stack dwords) | epilogue `C2 14 00` |
| Find skillId then partial TFID erase | `cmp [it+0x18/1c/20]` vs `esp+0x10/14/18` |
| Restart: `vtbl+0x234(skillId)`, gate `+0x61c != 0`, charge `0` | `push skillId; call [edx+0x234]` / `6A 00 50 E8→00519200` |
| arg4 unread | no load of stack4 in body |

### Decompiler noise

1. Formals `(pSkill, nSkillId, nTfidLo, nTfidHi, bGlobal)` → real: `(skillId, tfid0, tfid1, tfid2, pad)`.
2. Multi-arg `FUN_00518c20` → unary leave-FUN; pushes for find/erase.
3. Zero-arg `vtbl+0x234()` → takes **skillId**.
4. Four-arg `StartCastAgainHeartbeat` → **two** stack args (`skill`, `0`) per `aa_00519200`.

## Pseudocode (annotated copy of raw + corrections)

```c
/* Skill_ClearCastBindingAndMaybeRestartCd(owner, skillId, tfid0, tfid1, tfid2, pad)
   
   Clears active-cast binding matching skillId+partial TFID; if skill+0x61c set,
   Skill_StartCastAgainHeartbeat(owner, skill, 0).
   
   ABI: __thiscall RET 0x14 (PE). */

void __thiscall
Skill_ClearCastBindingAndMaybeRestartCd
          (void *this, int nSkillId, int nTfid0, int nTfid1, int nTfid2, char padUnused)

{
  int iVar1;
  void *pSkill;
  void **ppvVar2;
  void **ppvVar3;
  void *local_4;
  
  /* RAW surface (noise args on FUN_00518c20 retained for audit): */
  ppvVar3 = (void **)&nSkillId;
  ppvVar2 = &local_4;
  local_4 = this;
  FUN_00518c20(ppvVar2,ppvVar3);          /* NOISE arity — unary get map */
  FUN_0051c150(ppvVar2,ppvVar3);          /* exact find skillId */
  iVar1 = FUN_00518c20();
  if ((((local_4 != *(void **)(iVar1 + 4)) && (*(int *)((int)local_4 + 0x18) == nTfid0)) &&
      (*(int *)((int)local_4 + 0x1c) == nTfid1)) &&
     (*(char *)((int)local_4 + 0x20) == (char)nTfid2)) {
    FUN_00518c20(&nSkillId,local_4);      /* NOISE — get map for erase */
    FUN_0051cb40();                       /* map erase */
  }
  /* RECOVERED: pSkill = this->vtbl+0x234(nSkillId);  decomp zero-arg is wrong */
  pSkill = (void *)(**(code **)(*(int *)this + 0x234))(nSkillId);
  if ((pSkill != (void *)0x0) && (*(char *)((int)pSkill + 0x61c) != '\0')) {
    /* RECOVERED: StartCastAgain(this, pSkill, 0) — not 4-arg */
    Skill_StartCastAgainHeartbeat(this, pSkill, 0);
  }
  return;
}
```

## Open questions

- Map owner product type (`FUN_00518c20` leave-FUN residual).
- Product English for `vtbl+0x234` and `skill+0x61c`.
- `FUN_0051cb40` product name / full erase iterator package.
- Live Ghidra re-decompile when MCP available.
