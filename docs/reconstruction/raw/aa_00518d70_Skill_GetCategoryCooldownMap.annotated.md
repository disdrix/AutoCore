# Annotated low-level: Skill_GetCategoryCooldownMap

| Field | Value |
|---|---|
| Stable ID | `aa_00518d70` |
| VA | `0x00518d70` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00518d70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_GetCategoryCooldownMap(pMapOwner)
   
   Parameters:
     pMapOwner - object holding map pointer at +0x6c (lazy-alloc red-black map)
   
   Returns: map* at +0x6c
   VERIFIED lazy std::map-style construction. */

void * __fastcall Skill_GetCategoryCooldownMap(void *pMapOwner)

{
  void *pvVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3612;
  local_c = ExceptionList;
  if (*(int *)((int)pMapOwner + 0x6c) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      iVar2 = FUN_005ae2b0();
      *(int *)((int)pvVar1 + 4) = iVar2;
      *(undefined1 *)(iVar2 + 0x19) = 1;
      *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);
      *(undefined4 *)*(undefined4 *)((int)pvVar1 + 4) = *(undefined4 *)((int)pvVar1 + 4);
      *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);
      *(undefined4 *)((int)pvVar1 + 8) = 0;
    }
    *(void **)((int)pMapOwner + 0x6c) = pvVar1;
  }
  ExceptionList = local_c;
  return *(void **)((int)pMapOwner + 0x6c);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
