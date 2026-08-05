# Annotated low-level: phyBoneSharedData_unserialize

| Field | Value |
|---|---|
| Stable ID | `aa_00997540` |
| VA | `0x00997540` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00997540`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* phyBoneSharedData::unserialize  (BDAT / file tag TADB = 0x42444154)
   Source: C:\vog\1_code\palantir\palantir\physics\phyBoneSharedData.cpp
   
   Reads a bone-name std::string, then an hkQsTransform written as contiguous f32:
     rotation quaternion [x,y,z,w] (4) + translation (3) [+ scale (3) in chunk version 2].
     v1 = 2 component reads (rotation+translation); v2 = 3 reads (adds scale).
     A trailing 4x4 (via FUN_0043edb0) is a near-identity BIND matrix, NOT the transform.
   
   Apply as v' = translation + rotation * (scale * v)  (Havok hkQsTransform order).
   This is the per-model root transform (see phyBone_unserialize / geo-format.md "PBON").
   TADB is nested INSIDE the NOBP chunk (not a GBOD-level sibling). */

undefined4 __thiscall phyBoneSharedData_unserialize(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40 [12];
  char local_34;
  int local_30;
  int local_2c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];
  undefined4 **local_24 [5];
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  iVar2 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1862;
  local_c = ExceptionList;
  param_2 = 0;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope(param_1);
  local_4 = 0;
  if (local_30 != 0x42444154) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoneSharedData.cpp",0x2c,3,
                   "Invalid TAG unserializing phyBoneMaster");
    local_4 = 0xffffffff;
    if (local_34 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return 0xffffffff;
  }
  if (local_2c == 1) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (*(int *)(param_1 + 0x4044) == 0) {
      FUN_00436f10();
    }
    else {
      FUN_0076a200();
    }
    if (local_10 < 0x10) {
      local_24[0] = local_24;
    }
    puVar4 = (undefined4 *)FUN_00989e00(local_40,local_24[0]);
    *(undefined4 *)(iVar2 + 8) = *puVar4;
    stoChunkReader_readF32Array(param_1);
    stoChunkReader_readF32Array(param_1);
    FUN_0043edb0();
    iVar5 = FUN_0076a900();
    if (iVar5 != 0) {
      piVar6 = (int *)FUN_00467690(iVar5);
      *(int **)(iVar2 + 0x80) = piVar6;
      if (piVar6 != (int *)0x0) {
        param_2 = (**(code **)(*piVar6 + 0x10))(param_1);
      }
    }
    fVar1 = g_flOne;
    *(float *)(iVar2 + 0x28) = g_flOne;
    *(float *)(iVar2 + 0x2c) = fVar1;
    *(float *)(iVar2 + 0x30) = fVar1;
  }
  else {
    if (local_2c != 2) {
      uVar3 = FUN_0076cec0(&param_2,"Invalid chunk version (%i) unserializing phyBoneSharedData",
                           local_2c);
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoneSharedData.cpp",0x5b,3,
                     uVar3);
      local_4 = 0xffffffff;
      if (local_34 != '\0') {
        FUN_00769e40();
      }
      ExceptionList = local_c;
      return 0xffffffff;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
    local_4 = CONCAT31(local_4._1_3_,2);
    if (*(int *)(param_1 + 0x4044) == 0) {
      FUN_00436f10();
    }
    else {
      FUN_0076a200();
    }
    if (local_10 < 0x10) {
      local_24[0] = local_24;
    }
    puVar4 = (undefined4 *)FUN_00989e00(local_44,local_24[0]);
    *(undefined4 *)(iVar2 + 8) = *puVar4;
    stoChunkReader_readF32Array(param_1);
    stoChunkReader_readF32Array(param_1);
    stoChunkReader_readF32Array(param_1);
    FUN_0043edb0();
    iVar5 = FUN_0076a900();
    if (iVar5 != 0) {
      piVar6 = (int *)FUN_00467690(iVar5);
      *(int **)(iVar2 + 0x80) = piVar6;
      if (piVar6 != (int *)0x0) {
        param_2 = (**(code **)(*piVar6 + 0x10))(param_1);
      }
    }
  }
  local_4 = local_4 & 0xffffff00;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  local_4 = 0xffffffff;
  if (local_34 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
