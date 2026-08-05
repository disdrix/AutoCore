# Annotated low-level: Client_PlayNamedInterfaceSound

| Field | Value |
|---|---|
| Stable ID | `aa_00726d00` |
| VA | `0x00726d00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00726d00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_PlayNamedInterfaceSound
   
   Play a named interface sound/cue (e.g. mission_complete_3) from the audio table.
   Looks up name, manages concurrent slots, starts playback. */

undefined4 __thiscall
Client_PlayNamedInterfaceSound
          (int param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5,
          undefined4 param_6,undefined4 param_7,int param_8,char param_9)

{
  LPCRITICAL_SECTION lpCriticalSection;
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  float10 fVar10;
  byte local_49;
  int local_44;
  int *local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009b173d;
  local_1c = ExceptionList;
  if (*(char *)(param_1 + 600) != '\0') {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x3f8);
    ExceptionList = &local_1c;
    EnterCriticalSection(lpCriticalSection);
    local_14 = 0;
    if ((((param_8 != 0xc) && (param_8 != 0xd)) && (param_8 != 0x28)) ||
       (cVar2 = FUN_00722b80(param_4,param_5,param_8), cVar2 == '\0')) {
      pbVar3 = (byte *)FUN_007249c0(param_2,DAT_00d1a614);
      if (pbVar3 == (byte *)0x0) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_1c;
        return 0x80004005;
      }
      if ((param_9 != '\0') && (*(char *)(param_1 + 0x25a) == '\0')) {
        pbVar6 = pbVar3 + -1;
        do {
          pbVar4 = pbVar6;
          pbVar6 = pbVar4 + 1;
        } while (pbVar4[1] != 0);
        *(undefined2 *)(pbVar4 + 1) = DAT_00aa9268;
        pbVar4[3] = DAT_00aa926a;
      }
      local_49 = 0;
      local_44 = 0;
      if (0 < *(int *)(param_1 + 0x210)) {
        local_40 = (int *)(param_1 + 0x31c);
        do {
          iVar7 = *local_40;
          if (iVar7 != 0) {
            pbVar6 = (byte *)(iVar7 + 0x48);
            pbVar4 = pbVar6;
            pbVar8 = pbVar3;
            do {
              bVar1 = *pbVar4;
              bVar9 = bVar1 < *pbVar8;
              if (bVar1 != *pbVar8) {
LAB_00726e59:
                iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                goto LAB_00726e5e;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar9 = bVar1 < pbVar8[1];
              if (bVar1 != pbVar8[1]) goto LAB_00726e59;
              pbVar4 = pbVar4 + 2;
              pbVar8 = pbVar8 + 2;
            } while (bVar1 != 0);
            iVar5 = 0;
LAB_00726e5e:
            if (iVar5 == 0) {
              if (*(byte *)(param_1 + 0x2e4) < local_49) {
LAB_00726fd2:
                LeaveCriticalSection(lpCriticalSection);
                ExceptionList = local_1c;
                return 1;
              }
              if ((((*(uint *)(iVar7 + 0x40) & *(uint *)(iVar7 + 0x44)) == 0xffffffff) ||
                  (*(uint *)(iVar7 + 0x40) != param_4)) ||
                 ((*(uint *)(iVar7 + 0x44) != param_5 ||
                  ((pbVar4 = pbVar3, *(char *)(iVar7 + 0x1c5) == '\0' &&
                   (*(char *)(iVar7 + 0x3a) == '\0')))))) {
                if ((*(char *)(iVar7 + 0x1c5) == '\0') && (*(char *)(iVar7 + 0x36) == '\0')) {
                  local_30 = 0;
                  local_2c = 0;
                  local_28 = 0;
                  local_24 = 0;
                  if (*(char *)(*(int *)(param_1 + 0x31c + local_44 * 4) + 0x36) != '\0') {
                    fVar10 = (float10)FUN_007227e0(0);
                    FUN_004801d0((float)fVar10);
                  }
                  FUN_00724570(param_4,param_5,param_6,0,0,0x41200000,0x42a00000);
                  LeaveCriticalSection(lpCriticalSection);
                  ExceptionList = local_1c;
                  return 1;
                }
              }
              else {
                do {
                  bVar1 = *pbVar6;
                  bVar9 = bVar1 < *pbVar4;
                  if (bVar1 != *pbVar4) {
LAB_00726ecc:
                    iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                    goto LAB_00726ed1;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar6[1];
                  bVar9 = bVar1 < pbVar4[1];
                  if (bVar1 != pbVar4[1]) goto LAB_00726ecc;
                  pbVar6 = pbVar6 + 2;
                  pbVar4 = pbVar4 + 2;
                } while (bVar1 != 0);
                iVar7 = 0;
LAB_00726ed1:
                if (iVar7 == 0) {
                  if ((char)param_3 != '\0') {
                    if (param_8 == 10) {
                      *(undefined1 *)(*(int *)(param_1 + 0x31c + local_44 * 4) + 0x38) = 0;
                      FUN_007239b0(param_1);
                      if (*(char *)(*(int *)(param_1 + 0x31c + local_44 * 4) + 0x36) != '\0') {
                        fVar10 = (float10)FUN_007227e0(0);
                        FUN_004801d0((float)fVar10);
                      }
                      *(undefined1 *)(*(int *)(param_1 + 0x31c + local_44 * 4) + 0x3a) = 1;
                      iVar7 = *(int *)(param_1 + 0x31c + local_44 * 4);
                      *(uint *)(iVar7 + 0x40) = param_4;
                      *(uint *)(iVar7 + 0x44) = param_5;
                    }
                    goto LAB_00726fd2;
                  }
                  if (param_8 == 10) {
                    LeaveCriticalSection(lpCriticalSection);
                    ExceptionList = local_1c;
                    return 1;
                  }
                }
              }
              local_49 = local_49 + 1;
            }
          }
          local_40 = local_40 + 1;
          local_44 = local_44 + 1;
        } while (local_44 < *(int *)(param_1 + 0x210));
      }
      if (*(byte *)(param_1 + 0x2e4) < local_49) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_1c;
        return 1;
      }
      iVar7 = FUN_00723f70(param_1 + 0x220,param_8);
      if (iVar7 != -1) {
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        iVar7 = FUN_00726390(param_1,pbVar3,param_4,param_5,param_6,&local_30,iVar7,param_3,1,
                             param_8,param_7,0x3f800000,0x41200000,0x3f800000,0x42a00000);
        if (iVar7 < 0) {
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_1c;
          return 0x80004005;
        }
      }
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  ExceptionList = local_1c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
