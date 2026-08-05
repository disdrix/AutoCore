# Annotated low-level: identity

| Field | Value |
|---|---|
| Stable ID | `aa_00929ec0` |
| VA | `0x00929ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00929ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_EvalAutoPatrolWaypoint — mission patrol waypoint evaluation + optional AutoPatrol C2S
   send.
   
   Opcode: 0x20B3 (GameOpcode.AutoPatrol / EMSG_Sector_AutoPatrol)
   Direction: client → server only (NOT handled by Client_PacketDispatch).
   
   Args (stack):
     param_1 = patrol manager (global DAT_00d1ad10)
     param_2 = out TFID of waypoint identity (16 bytes)
     param_3 = out position XYZ of waypoint
     EAX = waypoint index into manager vector at +0x11c/+0x120
   
   Behavior:
     1. Index into patrol waypoint list; each entry has TFID [0..3] + cached pos [4..6].
     2. Resolve world object via CVOGReaction_ResolveObjectTarget (FUN_004bb950).
     3. Refresh cached position from object +0x80/+0x84/+0x88.
     4. If AutoPatrol enabled (manager+0x102) and player distance < threshold (manager+0x104 float),
        send CMSG AutoPatrol (size 0x18):
          +0x00 u32 opcode 0x20B3
          +0x04 u32 pad (often residual; ignore on server)
          +0x08 TFID of target object (16 bytes from object+0x160)
     5. Uses Client_SendSectorPacket (FUN_00807460).
   
   Related: ObjectiveRequirementPatrol / CVOGHBMissionPatrol, "Follow waypoints.",
   "Patrol mission without any patrol points." */

void __cdecl
Client_EvalAutoPatrolWaypoint(void *patrolManager,void *outWaypointTfid,float *outPosition)

{
  TFID_16 *pTfid;
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float local_30;
  float local_2c;
  float local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  
  if (*(int *)(*(int *)patrolManager + 0xe98) == 0) {
LAB_0092a0be:
    *(uint *)outWaypointTfid = DAT_00a158a0;
    *(uint *)((int)outWaypointTfid + 4) = DAT_00a158a4;
    *(undefined4 *)((int)outWaypointTfid + 8) = DAT_00a158a8;
    *(undefined4 *)((int)outWaypointTfid + 0xc) = DAT_00a158ac;
    return;
  }
  if (-1 < in_EAX) {
    if (*(int *)((int)patrolManager + 0x11c) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)((int)patrolManager + 0x120) - *(int *)((int)patrolManager + 0x11c) >> 2;
    }
    if (in_EAX <= iVar5) {
      pTfid = *(TFID_16 **)(*(int *)((int)patrolManager + 0x11c) + in_EAX * 4);
      if (*(char *)((int)patrolManager + 8) != '\0') {
        iVar5 = *(int *)(*(int *)patrolManager + 0xe98);
        local_30 = (float)pTfid[1].dwCoidLo;
        local_2c = (float)pTfid[1].dwCoidHi;
        local_28 = *(float *)&pTfid[1].bGlobal;
        pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) +
                                      0x1a0))();
        if (SQRT((local_30 - *pfVar7) * (local_30 - *pfVar7) +
                 (local_2c - pfVar7[1]) * (local_2c - pfVar7[1]) +
                 (local_28 - pfVar7[2]) * (local_28 - pfVar7[2])) < DAT_00aaa7ac) {
          *(undefined1 *)((int)patrolManager + 4) = 1;
        }
        *outPosition = (float)pTfid[1].dwCoidLo;
        outPosition[1] = (float)pTfid[1].dwCoidHi;
        outPosition[2] = *(float *)&pTfid[1].bGlobal;
LAB_0092a1a8:
        *(uint *)outWaypointTfid = pTfid->dwCoidLo;
        *(uint *)((int)outWaypointTfid + 4) = pTfid->dwCoidHi;
        *(undefined4 *)((int)outWaypointTfid + 8) = *(undefined4 *)&pTfid->bGlobal;
        *(undefined4 *)((int)outWaypointTfid + 0xc) = *(undefined4 *)&pTfid->bPad3;
        return;
      }
      piVar6 = Object_ResolveFromTFID(pTfid);
      if (piVar6 != (int *)0x0) {
        iVar5 = *(int *)(*(int *)(*(int *)patrolManager + 0xe98) + 0x250);
        if (iVar5 != 0) {
          iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;
        }
        if (piVar6[0x2b] != iVar5) {
          cVar4 = (**(code **)(*piVar6 + 0x198))();
          if (cVar4 == '\0') {
            (**(code **)(*piVar6 + 0x144))();
            local_30 = (float)piVar6[0x20];
            local_2c = (float)piVar6[0x21];
            local_28 = (float)piVar6[0x22];
            pTfid[1].dwCoidLo = (uint)local_30;
            pTfid[1].dwCoidHi = (uint)local_2c;
            *(float *)&pTfid[1].bGlobal = local_28;
            *outPosition = (float)pTfid[1].dwCoidLo;
            outPosition[1] = (float)pTfid[1].dwCoidHi;
            outPosition[2] = *(float *)&pTfid[1].bGlobal;
            if (*(char *)((int)patrolManager + 0x102) != '\0') {
              pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)
                                                  patrolManager + 0xe98) + 4) + 4) + 4 +
                                                  *(int *)(*(int *)patrolManager + 0xe98)) + 0x1a0))
                                          ();
              local_2c = local_2c - pfVar7[1];
              if (SQRT((local_30 - *pfVar7) * (local_30 - *pfVar7) +
                       local_2c * local_2c + (local_28 - pfVar7[2]) * (local_28 - pfVar7[2])) <
                  *(float *)((int)patrolManager + 0x104)) {
                local_28 = (float)piVar6[0x58];
                iStack_24 = piVar6[0x59];
                iStack_20 = piVar6[0x5a];
                iStack_1c = piVar6[0x5b];
                    /* C2S AutoPatrol 0x20B3: size 0x18 = u32 opcode + u32 pad + TFID(16) from
                       target object+0x160 */
                local_30 = 1.17303e-41;
                Client_SendSectorPacket(*(void **)patrolManager,0x18,&local_30);
              }
            }
            goto LAB_0092a1a8;
          }
        }
      }
      pTfid->dwCoidLo = DAT_00a158a0;
      pTfid->dwCoidHi = DAT_00a158a4;
      uVar1 = DAT_00a158a8._1_1_;
      uVar2 = DAT_00a158a8._2_1_;
      uVar3 = DAT_00a158a8._3_1_;
      pTfid->bGlobal = (undefined1)DAT_00a158a8;
      pTfid->bPad0 = uVar1;
      pTfid->bPad1 = uVar2;
      pTfid->bPad2 = uVar3;
      uVar1 = DAT_00a158ac._1_1_;
      uVar2 = DAT_00a158ac._2_1_;
      uVar3 = DAT_00a158ac._3_1_;
      pTfid->bPad3 = (undefined1)DAT_00a158ac;
      pTfid->bPad4 = uVar1;
      pTfid->bPad5 = uVar2;
      pTfid->bPad6 = uVar3;
      *(undefined1 *)((int)patrolManager + 4) = 1;
      goto LAB_0092a0be;
    }
  }
  *(uint *)outWaypointTfid = DAT_00a158a0;
  *(uint *)((int)outWaypointTfid + 4) = DAT_00a158a4;
  *(undefined4 *)((int)outWaypointTfid + 8) = DAT_00a158a8;
  *(undefined4 *)((int)outWaypointTfid + 0xc) = DAT_00a158ac;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
