# Raw capture: Skill_GetCategoryCooldownMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518d70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00518d70` |
| **Canonical name** | `Skill_GetCategoryCooldownMap` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
