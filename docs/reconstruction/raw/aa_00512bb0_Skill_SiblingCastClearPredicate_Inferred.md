# Raw: Skill_SiblingCastClearPredicate_Inferred

| Field | Value |
|-------|-------|
| Stable ID | `aa_00512bb0` |
| VA | `0x00512bb0` |
| Name | `Skill_SiblingCastClearPredicate_INFERRED` (was `LAB_00512bb0`) |
| System | `skills-abilities` |
| Source | Live Ghidra decompile + `read_memory` 2026-07-29; body dualed as unit (parent `aa_00514e20`) |

## Live decompile

```c
undefined4 Skill_SiblingCastClearPredicate_INFERRED(int param_1,int *param_2)
{
  int *piVar1;
  bool bVar2;

  if (*(int *)(param_1 + 0x1c) == 1) {
    piVar1 = (int *)__RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,
                                    &CVOGHBSkillBase::RTTI_Type_Descriptor,0);
    if (piVar1[0x188] != *param_2) {
      return 0;
    }
    if (piVar1[0x196] != param_2[2]) {
      return 0;
    }
    if (piVar1[0x197] != param_2[3]) {
      return 0;
    }
    bVar2 = (char)piVar1[0x198] == (char)param_2[4];
  }
  else {
    if ((char)param_2[6] == '\0') {
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) != 8) {
      return 0;
    }
    piVar1 = (int *)__RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,
                                    &CVOGHBOKToCastAgain::RTTI_Type_Descriptor,0);
    bVar2 = *(int *)(piVar1[9] + 0x5fc) == *param_2;
  }
  if (!bVar2) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x18))(1,0);
  return 1;
}
```

## Asm notes (`read_memory`)

- Entry: `mov eax,[esp+4]`; `mov ecx,[eax+0x1c]`; `sub esp,0x10`
- Type-1 RTTI pushes: `0x00af8cec` (SkillBase), `0x00af8d98` (Base)
- Type-1 skillId load: `[eax+0x620]`; TFID lea `[eax+0x658]`; compare dwords then `cmp dl,[ecx+0x10]`
- Type-8: flag `[ctx+0x18]`; RTTI `0x00b0015c` (OKToCastAgain); `[eax+0x24]` → `[+0x5fc]`
- Match: `push 0; push 1; mov ecx,eax; call [vtbl+0x18]`
- Epilogue both paths: `ret 0x0C` (stdcall 3 args; third unused)

## Offset decode (decomp array indices)

| Decomp | Byte off | Field |
|--------|----------|-------|
| `piVar1[0x188]` | `0x620` | skillId on SkillBase HB |
| `piVar1[0x196]` | `0x658` | TFID dword0 |
| `piVar1[0x197]` | `0x65c` | TFID dword1 |
| `(char)piVar1[0x198]` | `0x660` lo | TFID dword2 byte |
| `piVar1[9]` | `0x24` | skill* on OKToCastAgain |
| `param_2[6]` as char | `0x18` | alsoOkToCastAgain flag |

## DATA xrefs

- `0x00514e5b` in `FUN_00514e20` / Skill_SiblingCastClear
- `0x00517520` in `FUN_00517400`

See dual A/B for sealed CF.
