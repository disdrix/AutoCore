# Raw capture: CVOGReaction_CastSkillOnTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d09a0` |
| **Canonical name** | `CVOGReaction_CastSkillOnTarget` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGReaction_CastSkillOnTarget(...)
   
   Packs SkillStatusEffect 0x2031 buffer.
     size = nTargets*0x18 + 0x58
     +0x08 skillId(+0x5FC)  +0x0C level  +0x10 remaining charge
     +0x14 status 0 or 'c'  +0x28 source TFID  +0x38 item flag
     targets 0x18 + terminator g_abTfidInvalid
   
   VERIFIED size formula and field sources from packer body. */

undefined4 __thiscall
CVOGReaction_CastSkillOnTarget
          (int param_1,int param_2,void *param_3,int *param_4,char param_5,TFID_16 *param_6,
          undefined4 *param_7,char param_8,undefined4 param_9,char param_10,int param_11)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  void *nInferred;
  undefined4 *pPacket;
  TFID_16 *pTfid;
  uint local_8;
  int local_4;
  
  local_8 = 0;
  if (((*(char *)(param_1 + 0x7e) != '\0') && (param_2 != 0)) && (param_3 != (void *)0x0)) {
    local_4 = param_1;
    if ((param_4 != (int *)0x0) &&
       (((iVar3 = *(int *)(param_4[0x2a] + 0x38), iVar3 == 0xe || (iVar3 == 0x12)) ||
        ((iVar3 == 0x14 || (iVar3 == 3)))))) {
      iVar3 = (**(code **)(*param_4 + 0x19c))();
      if (iVar3 == 0) {
        param_4 = (int *)0x0;
      }
      else {
        param_4 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);
      }
    }
    puVar4 = operator_new(0x9a0);
    pPacket = (undefined4 *)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[8] = 0;
      puVar4[7] = 0;
      puVar4[6] = 0;
      pPacket = puVar4;
    }
    *pPacket = 0x2031;
    *(bool *)(pPacket + 0xe) = param_5 == '\0';
    pPacket[2] = *(undefined4 *)(param_2 + 0x5fc);
    pPacket[10] = *(undefined4 *)((int)param_3 + 0x160);
    pPacket[0xb] = *(undefined4 *)((int)param_3 + 0x164);
    pPacket[0xc] = *(undefined4 *)((int)param_3 + 0x168);
    pPacket[0xd] = *(undefined4 *)((int)param_3 + 0x16c);
    *(short *)(pPacket + 3) = *(short *)(param_2 + 0x5f6) + *(short *)(param_2 + 0x174);
    *(byte *)(pPacket + 5) = -(param_10 != '\0') & 99;
    param_11 = *(short *)(param_2 + 0x14) - param_11;
    pPacket[4] = param_11;
    if (param_11 < 0) {
      pPacket[4] = 0;
    }
    pPacket[6] = *param_7;
    pPacket[7] = param_7[1];
    pPacket[8] = param_7[2];
    if (param_8 != '\0') {
      pPacket[0xf] = param_9;
    }
    bVar2 = false;
    if (param_6 == (TFID_16 *)0x0) {
      bVar2 = true;
      param_6 = operator_new__(0x640);
      piVar5 = param_4 + 0x58;
      if (param_4 == (int *)0x0) {
        piVar5 = (int *)&DAT_009cbf68;
      }
      Skill_ResolveTargetList
                (param_6,local_4,param_3,*piVar5,piVar5[1],piVar5[2],piVar5[3],param_7,&local_8);
      if (local_8 != 0) {
        if ((local_8 & 2) == 0) {
          if ((local_8 & 4) == 0) {
            local_8 = ((int)(char)local_8 & 8U | 4) >> 2;
          }
          else {
            local_8 = 0xe;
          }
        }
        else {
          local_8 = 0xd;
        }
      }
    }
    _param_10 = 0;
    puVar4 = pPacket + 0x14;
    pTfid = param_6;
    while (((pTfid->dwCoidLo & pTfid->dwCoidHi) != 0xffffffff || (pTfid->bGlobal != 0))) {
      piVar5 = Object_ResolveFromTFID(pTfid);
      if (piVar5 == (int *)0x0) {
        _param_10 = _param_10 + 1;
        puVar4[-4] = DAT_009cbf68;
        puVar4[-3] = DAT_009cbf6c;
        puVar4[-2] = DAT_009cbf70;
        puVar4[-1] = DAT_009cbf74;
        *(undefined2 *)puVar4 = 0;
        *(undefined2 *)((int)puVar4 + 2) = 0;
        pTfid = pTfid + 1;
        puVar4 = puVar4 + 6;
      }
      else {
        puVar4[-4] = pTfid->dwCoidLo;
        puVar4[-3] = pTfid->dwCoidHi;
        puVar4[-2] = *(undefined4 *)&pTfid->bGlobal;
        puVar4[-1] = *(undefined4 *)&pTfid->bPad3;
        iVar3 = (**(code **)(*piVar5 + 0x214))();
        if (iVar3 != 0) {
          *(undefined2 *)puVar4 = *(undefined2 *)(iVar3 + 300);
          *(undefined2 *)((int)puVar4 + 2) = *(undefined2 *)(iVar3 + 0x12e);
        }
        _param_10 = _param_10 + 1;
        pTfid = pTfid + 1;
        puVar4 = puVar4 + 6;
      }
    }
    if (bVar2) {
      operator_delete__(param_6);
    }
    puVar1 = pPacket + _param_10 * 6 + 0x10;
    *puVar1 = DAT_009cbf68;
    puVar1[1] = DAT_009cbf6c;
    puVar1[2] = DAT_009cbf70;
    puVar1[3] = DAT_009cbf74;
    nInferred = (void *)(_param_10 * 3);
    *(short *)(pPacket + 1) = (short)nInferred * 8 + 0x58;
    if ((((((pPacket[0x10] & pPacket[0x11]) != 0xffffffff) || (*(char *)(pPacket + 0x12) != '\0'))
         || (*(int *)(param_2 + 0x614) == 1)) ||
        (((*(byte *)(param_2 + 0x624) & 1) != 0 &&
         (nInferred = param_3, *(int *)(*(int *)((int)param_3 + 0xa8) + 0x38) == 0x12)))) &&
       (param_8 == '\0')) {
      local_8 = Skill_ApplyStatusEffectLocal(param_3,(int)nInferred,pPacket,'\0');
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(pPacket);
  }
  return 0;
}
```
