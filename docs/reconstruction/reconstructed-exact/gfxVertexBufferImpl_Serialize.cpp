// =============================================================================
// gfxVertexBufferImpl_Serialize
// -----------------------------------------------------------------------------
// Purpose:  Write VERT ("TREV") chunk v3: id + stride + count + nested DECL
//           ("LCED") + count2 + interleaved vertex bytes.
//
// Address:  0x009994c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009994c0
// System:   graphics / gfx (asset I/O)
// DECL v2: u32 elementCount + {type,stream,usage,usageIndex} x N
// Spec: AutoCore-SCAR docs/geo-format.md
// =============================================================================

int gfxVertexBufferImpl_Serialize(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afb82;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x56455254,3);

  local_4 = 0;

  if ((*(int *)(unaff_EDI + 0x10) != 0) &&

     (iVar2 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18),4),

     iVar2 != 0)) {

    if (*(int *)(unaff_EDI + 0x10) == 0) {

      uVar1 = 0;

    }

    else {

      uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x10) + 8);

    }

    FUN_00734640(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18),uVar1);

  }

  FUN_0044c9e0();

  iVar2 = FUN_00746f90();

  if (iVar2 < 0) {

    FUN_00414aa0();

  }

  else {

    FUN_00439870();

    local_4 = CONCAT31(local_4._1_3_,1);

    FUN_00746d40(unaff_EDI + 0x24);

    iVar2 = FUN_00767ab0(0,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18));

    FUN_00414aa0();

    if (iVar2 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0x319,

                     3,"Error serializing vertex buffer");

      FUN_00405ef0();

      local_4 = 0xffffffff;

      stoChunkWriter_EndChunk();

      ExceptionList = local_c;

      return -1;

    }

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return iVar2;

}
