# Raw capture: CVOGObjectiveRequirement_Kill_Precheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613b50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00613b50` |
| **Canonical name** | `CVOGObjectiveRequirement_Kill_Precheck` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall

CVOGObjectiveRequirement_Kill_Precheck

          (int *param_1,undefined4 param_2,float param_3,int param_4,undefined4 param_5,int *param_6

          )



{

  float *pfVar1;

  byte bVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  int unaff_EBP;

  

  if (param_4 != 0) {

    return 0;

  }

  cVar3 = (**(code **)(*param_1 + 8))(param_2,param_3);

  if (cVar3 != '\0') {

    return 0;

  }

  if ((char)param_1[4] != '\0') {

    iVar4 = (**(code **)(*param_6 + 0x1d4))();

    if (iVar4 == 0) {

      return 0;

    }

    iVar4 = (**(code **)(*param_6 + 0x210))(0);

    if (iVar4 == 0) {

      return 0;

    }

    bVar2 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) +

                     0x532);

    if (*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + 4) + 4) + 0xac + unaff_EBP) + 0x3c

                          ) + 0x532) == bVar2) {

      return 0;

    }

    if ((char)param_1[0xb] != '\0') {

      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))();

      if (iVar5 < param_1[0xc]) {

        return 0;

      }

      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))();

      if (param_1[0xd] < iVar5) {

        return 0;

      }

    }

    if ((param_1[9] & 1 << (bVar2 & 0x1f)) == 0) {

      return 0;

    }

    if ((param_1[10] &

        1 << (*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c)

                       + 0x531) & 0x1f)) != 0) {

      *(float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4) =

           *(float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4) + param_3;

      return 1;

    }

    return 0;

  }

  if (*(char *)((int)param_1 + 0x12) == '\0') {

    if (*(char *)((int)param_1 + 0x11) == '\0') {

      if ((param_1[5] != -1) && ((int)param_3 != param_1[5])) {

        return 0;

      }

    }

    else {

      if (param_6 == (int *)0x0) {

        return 0;

      }

      iVar4 = (**(code **)(*param_6 + 0x28c))();

      if (param_1[5] != iVar4) {

        return 0;

      }

    }

    pfVar1 = (float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4);

    if ((float)param_1[6] < *pfVar1 || (float)param_1[6] == *pfVar1) {

      return 0;

    }

    if (param_1[9] != -1) {

      if (param_6 == (int *)0x0) {

        return 0;

      }

      if (*(int *)(param_6[0x2a] + 0x38) != param_1[9]) {

        return 0;

      }

    }

    if ((char)param_1[0xb] != '\0') {

      iVar4 = (**(code **)(*param_6 + 0x27c))();

      if (iVar4 < param_1[0xc]) {

        return 0;

      }

      iVar4 = (**(code **)(*param_6 + 0x27c))();

      if (param_1[0xd] < iVar4) {

        return 0;

      }

    }

    if ((*(char *)((int)param_1 + 0x13) != '\0') && (param_6 != (int *)0x0)) {

      uVar6 = (uint)*(byte *)(param_1 + 2);

LAB_00613d35:

      pfVar1 = (float *)((int)param_3 + 4 + uVar6 * 4);

      iVar4 = (**(code **)(*param_6 + 0x244))();

      *pfVar1 = (float)iVar4 + *pfVar1;

      goto LAB_00613dd8;

    }

    uVar6 = (uint)*(byte *)(param_1 + 2);

  }

  else {

    if (*(int *)(param_6[0x2a] + 0x38) != 0xe) {

      return 0;

    }

    (**(code **)(*param_6 + 0x1d4))();

    piVar7 = (int *)FUN_005001f0();

    if (param_1[5] != *piVar7) {

      return 0;

    }

    pfVar1 = (float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4);

    if ((float)param_1[6] < *pfVar1 || (float)param_1[6] == *pfVar1) {

      return 0;

    }

    if ((char)param_1[0xb] != '\0') {

      iVar4 = (**(code **)(*param_6 + 0x27c))();

      if (iVar4 < param_1[0xc]) {

        return 0;

      }

      iVar4 = (**(code **)(*param_6 + 0x27c))();

      if (param_1[0xd] < iVar4) {

        return 0;

      }

    }

    uVar6 = (uint)*(byte *)(param_1 + 2);

    if (*(char *)((int)param_1 + 0x13) != '\0') goto LAB_00613d35;

  }

  *(float *)((int)param_3 + 4 + uVar6 * 4) = *(float *)((int)param_3 + 4 + uVar6 * 4) + 0.0;

LAB_00613dd8:

  if ((char)param_1[7] != '\0') {

    CVOGReaction_FailMission(**(undefined4 **)(param_1[1] + 0x14c));

    return 0;

  }

  return 1;

}
```

﻿---

## Re-verify append (2026-07-29) — asm seal; do not rewrite body above

**Tools:** decompile_function (unchanged vs raw), disassemble_function full listing, read_memory vtable 0x009e19e4.

### Decompiler myths corrected by asm

| Decomp claim | Asm truth |
|---|---|
| Default credit + 0.0 | ADDSS XMM0, dword ptr [ESP+0x24] @ 0x00613c6b and 0x00613dca (arg5 float addend) |
| param_3 dual-use as state + float | arg2 loaded to EBP = state; arg5 at frame [ESP+0x24] = addend |
| unaff_EBP faction compare | Faction load from arg1 [ESP+0x14] after frame; byte @ entity chain +0x532 |

### Authoritative mutate sites

```
; vehicle path credit
00613c61  MOVZX  EAX, byte ptr [ESI+0x8]          ; slot
00613c65  MOVSS  XMM0, dword ptr [EBP+EAX*4+0x4]  ; progress
00613c6b  ADDSS  XMM0, dword ptr [ESP+0x24]       ; += arg5
00613c71  LEA    EAX, [EBP+EAX*4+0x4]
00613c75  MOVSS  dword ptr [EAX], XMM0
00613c79  … MOV AL,1 ; RET 0x1c                  ; no FailMission

; XP path
00613d39  LEA    EBX, [EBP+EAX*4+0x4]
00613d3d  CALL   [EDI.vtbl+0x244]
00613d43  CVTSI2SS XMM0, EAX
00613d47  ADDSS  XMM0, dword ptr [EBX]
00613d4b  MOVSS  dword ptr [EBX], XMM0

; default path (shared tail)
00613dc4  MOVSS  XMM0, dword ptr [EBP+EAX*4+0x4]
00613dca  ADDSS  XMM0, dword ptr [ESP+0x24]
00613dd0  LEA    EAX, [EBP+EAX*4+0x4]
00613dd4  MOVSS  dword ptr [EAX], XMM0
00613dd8  CMP    byte ptr [ESI+0x1c], 0           ; FailMission flag
```

### Eval pure-read contrast

Precheck prologue: CALL dword ptr [ESI.vtbl+0x8] with (arg1, state=EBP); AL!=0 -> reject (already complete).

Eval body (0x00613910): load slot float + COMISS vs (float)req+0x18; no stores.

### ABI

- RET 0x1c -> 7 stack dwords
- Vtable base 0x009e19e4: +0x4 = this (0x00613b50), +0x8 = Eval (0x00613910) — read_memory confirmed
