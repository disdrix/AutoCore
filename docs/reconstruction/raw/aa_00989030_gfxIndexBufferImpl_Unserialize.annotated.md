# Annotated low-level: gfxIndexBufferImpl_Unserialize

| Field | Value |
|---|---|
| Stable ID | `aa_00989030` |
| VA | `0x00989030` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00989030`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* gfxIndexBufferImpl::Unserialize  [palantir\graphics\gfxIndexBufferImpl.cpp:0x136/0x164]
   Reads an INDX ("XDNI") chunk; accepts versions 1-2.
    v1: body = u32 count + u16 index data immediately (index size always 2).
    v2: body = u32 id + u16 indexSize(2|4) + u16 count + u32 count2(authoritative) + data.
   Triangle lists (D3DPT_TRIANGLELIST); topology is fixed, not stored per chunk. */

undefined4 gfxIndexBufferImpl_Unserialize(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar4 = param_2;
  iVar5 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b235a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope(param_2);
  local_4 = 0;
  if (local_14 != 0x494e4458) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferImpl.cpp",0x136,3,
                   "Invalid TAG unserializing gfxIndexBufferImpl");
    local_4 = 0xffffffff;
    if (local_18 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return 0xffffffff;
  }
  if (local_10 != 1) {
    if (local_10 == 2) {
      cVar3 = FUN_00734690();
      if (cVar3 != '\0') {
        uVar6 = *(undefined4 *)(iVar5 + 0xc);
        uVar7 = *(undefined4 *)(iVar5 + 8);
        iVar4 = FUN_0044c370(uVar7,uVar6);
        if (iVar4 != 0) {
          local_4 = 0xffffffff;
          if (local_18 != '\0') {
            FUN_00769e40();
          }
          ExceptionList = local_c;
          return 0xfffffffe;
        }
        FUN_0044c340(uVar7,uVar6);
        iVar4 = param_2;
        goto LAB_0098917d;
      }
    }
    else {
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferImpl.cpp",0x164,3
                     ,"Invalid chunk version unserializing gfxIndexBufferImpl");
    }
    local_4 = 0xffffffff;
    if (local_18 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return 0xffffffff;
  }
LAB_0098917d:
  if (*(int *)(iVar4 + 0x4044) == 0) {
    FUN_00437050(&param_1);
  }
  else {
    FUN_00768760(&param_1);
  }
  uVar6 = 0x20;
  if ((*(int *)(*param_3 + 0x14) != 0) && (*(char *)(*(int *)(*param_3 + 0x14) + 0x10) != '\0')) {
    uVar6 = 0x18;
  }
  uVar7 = 0xffffffff;
  FUN_00988f20(param_1,uVar6,0,0);
  piVar1 = *(int **)(iVar5 + 0x10);
  if (piVar1 != (int *)0x0) {
    param_3 = *(int **)(iVar5 + 0x1c);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar2 + 0x2c))
                        (piVar2,piVar1[4] * *(int *)(iVar5 + 0x18),piVar1[4] * (int)param_3,&param_3
                         ,0x800);
      if ((iVar5 < 0) || (piVar1[3] = piVar1[3] + 1, param_3 == (int *)0x0)) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = FUN_0044ed70();
      }
    }
  }
  FUN_0044b8b0();
  local_4 = 0xffffffff;
  if (local_18 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return uVar7;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
