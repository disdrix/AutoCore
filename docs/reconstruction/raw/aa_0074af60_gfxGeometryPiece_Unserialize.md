# Raw capture: gfxGeometryPiece_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074af60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074af60` |
| **Canonical name** | `gfxGeometryPiece_Unserialize` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* gfxGeometryPiece::Unserialize  [palantir\graphics\gfxGeometryPiece.cpp:0xd6/0x164]
   Reads a GPCE ("ECPG") chunk; accepts versions 8, 9, 10. v10 path: reads flags,
   effEffect_Unserialize (this+0x1c), index buffer (this+4), vertex buffer (this+0xc), then
   bbox/name strings/user data.
   Piece tail layout on disk: bodyName\0 + 8 bytes + numStr\0 + pieceName\0 (with _LOD1/_LOD2
   suffixes) + ADSU chunk {u32 pairCount + key\0value\0 pairs, key "LODLevel"}. */

int __thiscall gfxGeometryPiece_Unserialize(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *******pppppppuVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;
  undefined4 unaff_EBX;
  undefined **local_98;
  int local_94;
  char local_88;
  int local_84;
  int local_80;
  undefined **local_7c;
  int local_78;
  undefined4 ******appppppuStack_74 [5];
  uint uStack_60;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_5c [4];
  undefined4 ******appppppuStack_58 [5];
  uint uStack_44;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [8];
  undefined1 local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b3065;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope(param_2);
  local_4 = 0;
  if (local_84 != 0x47504345) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp",0xd6,3,
                   "Invalid TAG unserializing gfxGeometryPiece");
    local_4 = 0xffffffff;
    if (local_88 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return -1;
  }
  cVar2 = FUN_00767120();
  if (cVar2 != '\0') {
    local_4 = 0xffffffff;
    if (local_88 != '\0') {
      FUN_00769e40();
    }
    ExceptionList = local_c;
    return 0;
  }
  if (local_80 != 8) {
    if (local_80 != 9) {
      if (local_80 == 10) {
        FUN_00439a50();
        piVar1 = (int *)(param_1 + -4);
        FUN_00437990(local_98);
        iVar8 = param_1 + 0x1c;
        iVar3 = effEffect_Unserialize(iVar8,param_2);
        if ((iVar3 < 0) || (iVar3 = FUN_009a00d0(param_1 + 4,param_2,iVar8), iVar3 < 0))
        goto LAB_0074b044;
        FUN_009a0000(param_1 + 0xc,param_2,iVar8,param_1 + 4);
        FUN_0043f5c0();
        (**(code **)(*piVar1 + 0x78))(iVar8);
        FUN_0074ce60();
        if (*(char *)(param_1 + 0x50) == '\0') {
          FUN_00414b20(0);
        }
        else {
          *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
        }
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_5c);
        puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
        FUN_00439a20(param_2);
        pppppppuVar5 = (undefined4 *******)appppppuStack_58[0];
        if (uStack_44 < 0x10) {
          pppppppuVar5 = appppppuStack_58;
        }
        puVar4 = (undefined4 *)FUN_00989e00(auStack_30,pppppppuVar5);
        *(undefined4 *)(param_1 + 0x54) = *puVar4;
        FUN_00436900();
        *(undefined4 *)(param_1 + 0x70) = unaff_EBX;
        FUN_00439a00();
        FUN_00439a20(param_2);
        pppppppuVar5 = (undefined4 *******)appppppuStack_58[0];
        if (uStack_44 < 0x10) {
          pppppppuVar5 = appppppuStack_58;
        }
        puVar4 = (undefined4 *)FUN_00989e00(auStack_34,pppppppuVar5);
        *(undefined4 *)(param_1 + 0x8c) = *puVar4;
        FUN_00439a20(param_2);
        if (uStack_44 < 0x10) {
          appppppuStack_58[0] = appppppuStack_58;
        }
        puVar4 = (undefined4 *)FUN_00989e00(auStack_3c,appppppuStack_58[0]);
        *(undefined4 *)(param_1 + 0x90) = *puVar4;
        FUN_007496c0(piVar1);
        FUN_00439a00();
        FUN_00436900();
        FUN_00439a00();
        (**(code **)(*piVar1 + 100))();
        this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               appppppuStack_58;
        goto LAB_0074b467;
      }
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp",0x164,3,
                     "Invalid chunk version unserializing gfxGeometryPiece");
      goto LAB_0074b044;
    }
    FUN_00439a50();
    FUN_00437990(local_98);
  }
  iVar8 = param_1 + 0x1c;
  iVar3 = effEffect_Unserialize(iVar8,param_2);
  if (-1 < iVar3) {
    iVar3 = param_1 + 4;
    iVar6 = FUN_009a00d0(iVar3,param_2,iVar8);
    if (-1 < iVar6) {
      FUN_00439a00();
      if (local_98 == (undefined **)0x2) {
        local_94 = 0;
        local_98 = &PTR_FUN_00a9db18;
        local_78 = 0;
        local_7c = &PTR_FUN_00a9db18;
        local_4._0_1_ = 3;
        FUN_009a0000(&local_98,param_2,iVar8,iVar3);
        FUN_009a0000(&local_7c,param_2,iVar8,iVar3);
        FUN_004451c0(local_24,local_78 + 0x24);
        local_4._0_1_ = 4;
        FUN_00746c10();
        FUN_00747390();
        uVar7 = FUN_0044bb60();
        if (local_94 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = *(undefined4 *)(local_94 + 0x18);
        }
        FUN_00414c20(uVar9,local_24,uVar7,0);
        FUN_0044bbc0(&local_98,0,0);
        FUN_0044bbc0(&local_7c,0,0);
        FUN_00414b60();
        local_4._0_1_ = 2;
        FUN_00437450();
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_00437450();
      }
      else {
        FUN_009a0000(param_1 + 0xc,param_2,iVar8,iVar3);
      }
      (**(code **)(*(int *)(param_1 + -4) + 0x78))(param_1 + 0x1c);
      FUN_0074ce60();
      if (*(char *)(param_1 + 0x50) == '\0') {
        FUN_00414b20(0);
      }
      else {
        *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &local_78);
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,5);
      FUN_00439a20(param_2);
      pppppppuVar5 = (undefined4 *******)appppppuStack_74[0];
      if (uStack_60 < 0x10) {
        pppppppuVar5 = appppppuStack_74;
      }
      puVar4 = (undefined4 *)FUN_00989e00(auStack_2c,pppppppuVar5);
      *(undefined4 *)(param_1 + 0x54) = *puVar4;
      FUN_00436900();
      *(undefined4 *)(param_1 + 0x70) = unaff_EBX;
      FUN_00439a00();
      FUN_00439a20(param_2);
      pppppppuVar5 = (undefined4 *******)appppppuStack_74[0];
      if (uStack_60 < 0x10) {
        pppppppuVar5 = appppppuStack_74;
      }
      puVar4 = (undefined4 *)FUN_00989e00(auStack_40,pppppppuVar5);
      *(undefined4 *)(param_1 + 0x8c) = *puVar4;
      FUN_00439a20(param_2);
      if (uStack_60 < 0x10) {
        appppppuStack_74[0] = appppppuStack_74;
      }
      puVar4 = (undefined4 *)FUN_00989e00(auStack_38,appppppuStack_74[0]);
      *(undefined4 *)(param_1 + 0x90) = *puVar4;
      FUN_007496c0((int *)(param_1 + -4));
      FUN_00439a00();
      FUN_00436900();
      FUN_00439a00();
      (**(code **)(*(int *)(param_1 + -4) + 100))();
      this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             appppppuStack_74;
LAB_0074b467:
      local_4 = local_4 & 0xffffff00;
      iVar8 = (-1 < *(int *)(param_2 + 0x402c)) - 1;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this);
      local_4 = 0xffffffff;
      if (local_88 == '\0') {
        ExceptionList = local_c;
        return iVar8;
      }
      FUN_00769e40();
      ExceptionList = local_c;
      return iVar8;
    }
  }
LAB_0074b044:
  local_4 = 0xffffffff;
  if (local_88 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return -1;
}
```
