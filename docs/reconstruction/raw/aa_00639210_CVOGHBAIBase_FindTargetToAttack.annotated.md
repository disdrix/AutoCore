# Annotated low-level: CVOGHBAIBase_FindTargetToAttack

| Field | Value |
|---|---|
| Stable ID | `aa_00639210` |
| VA | `0x00639210` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00639210`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Find a target creature to attack.
   
   Algorithm:
   1. Validate owner (this+0x6) via vtable +0x214 and +0x19c
   2. Set random seed at this+0x2 (rand % this+0x10 / 2 + this+0x10)
   3. If FUN_00512440() == -100 or owner state+0x278 == 2 (dead): return no target
   4. If owner state+0x278 == 3 (respawn): return no target
   5. Otherwise: perform spatial query via FUN_004ea350 using attack radius
   6. Iterate found entities:
      - Skip if FUN_005134e0() fails (not hostile check)
      - Skip if bit 10 of entity+0x180 is set (team check)
      - Check aggro via vtable +0x298
      - Skip if entity vtable +0x198 fails (alive check)
      - Skip if FUN_00512440() == -100
      - Calculate level difference, adjust search radius by level delta
      - Check if within adjusted radius
      - Select closest valid target
   7. Set found target via FUN_005172d0 */

int __fastcall CVOGHBAIBase_FindTargetToAttack(int *this)

{
  int *piVar1;
  float fVar2;
  ushort uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  RACE_ID_INFERRED RVar9;
  float *pfVar10;
  undefined4 uVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack_58;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [20];
  void *pvStack_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a8e73;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGHBAIBase::FindTargetToAttack");
                    /* // Bail if owner (this+0x6) is null */
  local_14 = 0;
  if ((int *)this[6] != (int *)0x0) {
                    /* // Validate owner via vtable +0x214 (alive check) */
    iVar6 = (**(code **)(*(int *)this[6] + 0x214))();
                    /* // Validate via vtable +0x19c (entity reference check) */
    if (iVar6 == 0) {
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    else {
      iVar7 = (**(code **)(*(int *)this[6] + 0x19c))();
      if (iVar7 == 0) {
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      else {
                    /* // Check if dead (-100) or state+0x278 == 2 (dead): no target */
        iVar8 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar8 + 0xc)) {
          *(undefined4 *)(iVar8 + 0xc) = 0;
        }
        uVar3 = *(ushort *)(*(int *)(iVar8 + 8) + *(int *)(iVar8 + 0xc) * 2);
        *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 1;
        this[2] = (int)((longlong)(ulonglong)uVar3 % (longlong)this[10]) / 2 + this[10];
        RVar9 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6));
                    /* // State+0x278 == 3 (respawn): no target */
        if ((RVar9 == 0xffffff9c) || (*(char *)(iVar6 + 0x278) == '\x02')) {
          iVar6 = 0;
        }
        else {
          if (*(char *)(iVar6 + 0x278) == '\x03') goto LAB_006396c4;
          uVar4 = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xa8 + iVar7);
          iVar7 = (**(code **)(*this + 0x24))();
                    /* // Spatial query: find entities within attack radius via FUN_004ea350 */
          if ((iVar7 == 0) ||
             (piVar1 = (int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7), piVar1 == (int *)0x0)
             ) {
            pfVar10 = (float *)FUN_00404c90();
            fStack_40 = *pfVar10;
            fStack_3c = pfVar10[1];
            fStack_38 = pfVar10[2];
            fStack_34 = pfVar10[3];
            fVar2 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xac + iVar6) +
                                       0x3c) + 0x4cc);
            if ((DAT_00d03088 & 1) == 0) {
              DAT_00d03088 = DAT_00d03088 | 1;
              DAT_00d0307c = 0;
              DAT_00d03080 = 0;
              _DAT_00d03084 = 0;
              _atexit((_func_4879 *)&LAB_009c43d0);
              local_14 = local_14 & 0xffffff00;
            }
            uVar11 = FUN_0040aff0(auStack_30);
            iVar7 = FUN_004bb0d0(uVar11);
                    /* // Check if hostile and not same team (bit 10 of entity+0x180) */
            fStack_58 = g_flMultiKillCountBlend;
            iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x28c))()
            ;
            if (((-1 < iVar8) &&
                (iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) +
                                     0x28c))(), iVar6 < 3)) || (iVar7 != 0)) {
              fStack_58 = DAT_00a0f734;
            }
            iVar6 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar6 + 0xc)) {
              *(undefined4 *)(iVar6 + 0xc) = 0;
            }
            uVar3 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
            *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
            if (fStack_58 <= (float)uVar3 * DAT_00aaa638) {
              uVar11 = 0xd;
            }
            else {
              uVar11 = 0x11;
            }
            FUN_004ea350(uVar4,&fStack_40,fVar2,&DAT_00d03078,0,uVar11);
                    /* // Calculate level difference, adjust search radius */
            for (uVar12 = 0;
                (DAT_00d0307c != 0 && (uVar12 < (uint)(DAT_00d03080 - DAT_00d0307c >> 2)));
                uVar12 = uVar12 + 1) {
              iVar6 = *(int *)(DAT_00d0307c + uVar12 * 4);
              cVar5 = FUN_005134e0();
              if (((cVar5 == '\0') &&
                  (iVar7 = *(int *)(*(int *)(iVar6 + 4) + 4),
                  (*(uint *)(iVar7 + 0x180 + iVar6) >> 10 & 1) == 0)) &&
                 ((cVar5 = (**(code **)(*(int *)this[6] + 0x298))(iVar7 + iVar6 + 4), cVar5 != '\0'
                  && ((cVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6)
                                           + 0x198))(), cVar5 == '\0' &&
                      (RVar9 = Object_GetRootRaceId
                                         ((void *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6)),
                      RVar9 != 0xffffff9c)))))) {
                piVar1 = (int *)this[6];
                iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x27c
                                    ))();
                iVar8 = (**(code **)(*piVar1 + 0x27c))();
                iVar7 = iVar7 - iVar8;
                fStack_58 = fVar2 * fVar2;
                if (0 < iVar7) {
                  if (0xb < iVar7) {
                    iVar7 = 0xb;
                  }
                  fStack_58 = (DAT_00aaaa10 - (float)iVar7 * g_flMultiKillCountBlend) *
                              fVar2 * fVar2;
                  if (fStack_58 < DAT_00aaa8a8) {
                    /* // Check if within adjusted attack radius */
                    fStack_58 = DAT_00aaa8a8;
                  }
                }
                if (((int *)this[6] != (int *)0x0) &&
                   (iVar7 = (**(code **)(*(int *)this[6] + 0x1d8))(), iVar7 != 0)) {
                  iVar7 = (**(code **)(*(int *)this[6] + 0x1d8))();
                  fStack_58 = fStack_58 - *(float *)(iVar7 + 0x1ec) * fStack_58;
                }
                iVar7 = *(int *)(*(int *)(iVar6 + 8) + 0x3c);
                fVar15 = *(float *)(iVar7 + 0xb8) - fStack_38;
                fVar14 = *(float *)(iVar7 + 0xb4) - fStack_3c;
                fVar13 = *(float *)(iVar7 + 0xb0) - fStack_40;
                if (fVar15 * fVar15 + fVar14 * fVar14 + fVar13 * fVar13 <= fStack_58) {
                  iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6;
                  goto LAB_006396a1;
                }
              }
            }
            iVar6 = 0;
LAB_006396a1:
            FUN_005172d0(iVar6);
            FUN_00639710(0,0);
            goto LAB_006396c4;
          }
          iVar6 = (**(code **)(*piVar1 + 0x19c))();
          if (iVar6 == 0) {
            iVar6 = 0;
          }
          else {
                    /* // Iterate found entities */
            iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6;
          }
        }
        FUN_005172d0(iVar6);
      }
    }
  }
LAB_006396c4:
  local_14 = 0xffffffff;
  iVar6 = FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return iVar6;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
