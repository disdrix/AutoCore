# Raw capture: CVOGCharacter_FindActiveObjectiveIdForInteract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00524520` |
| **VA** | `0x00524520` |
| **Canonical name** | `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| **Prior** | `FUN_00524520` |
| **System** | interaction-activation |
| **Capture** | Ghidra decompile + `read_memory` byte seal 2026-07-29 |

## Raw pseudocode (decompiler)

```c
undefined4 __thiscall FUN_00524520(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x548);
  iVar3 = 0;
  uVar2 = 0;
  if (*(char *)(iVar4 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar4 + 0x1d) = 1;
  do {
    iVar4 = *(int *)(param_1 + 0x548);
    // lock checks HashError:TraverseToNext ...
    if (iVar3 == 0) {
      iVar3 = *(int *)(iVar4 + 0x14);
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x14);
    }
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar3 + 8);
    }
    if (iVar4 == 0) goto LAB_005245b6;
    cVar1 = FUN_0059d9c0(param_1,param_2);  // thiscall ECX=iVar4 (obj); see bytes
  } while (cVar1 == '\0');
  uVar2 = *(undefined4 *)(iVar4 + 0x10);
LAB_005245b6:
  *(undefined1 *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;
  return uVar2;
}
```

## Byte seal (authoritative arity)

```
00524520: cmp [esp+4],0 / push ebx / mov ebx,ecx / ... / ret 4
005245a2: mov eax,[esp+0x14] / push eax / push ebx / mov ecx,edi / call 0059d9c0
005245b3: mov ebp,[edi+0x10]  ; id
005245c1: mov byte ptr [ecx+0x1d],0 / pop ebx / ret 4

0059d9c0: ... call [eax+0x40] with (character, world) / ret 8
00930d85: mov ecx,[esi+0xe98] / push edi / call 00524520
00930dd8: mov [esp+0x1c],eax   ; packet+0x18 IDObjective
```
