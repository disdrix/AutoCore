// =============================================================================
// stoChunkWriter_BeginChunk
// -----------------------------------------------------------------------------
// Stable ID: aa_00767460
// Address:   0x00767460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* stoChunkWriter::BeginChunk(u32 tag4cc, u32 version)  [arda2\storage\stoChunk.cpp]
   Binary mode: writes 16-byte chunk header {tag, size(placeholder, patched by EndChunk), version,
   reserved=0} and pushes the header position onto the writer's chunk stack. Text mode: writes
   'CHUNK "%s" %i {'.
   Tags appear byte-reversed on disk (code constant 'VERT' = file bytes "TREV").
   Full .geo format spec: AutoCore-SCAR repo docs/geo-format.md */

uint32_t /* width from decompiler */ __thiscall
stoChunkWriter_BeginChunk(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)

{
  int iVar1;
  uint uVar2;
  uint32_t /* width from decompiler */ *puVar3;
  uint32_t /* width from decompiler */ uVar4;
  uint32_t /* width from decompiler */ local_3c;
  uint32_t /* width from decompiler */ local_38;
  uint32_t /* width from decompiler */ local_34;
  uint32_t /* width from decompiler */ local_30;
  uint32_t /* width from decompiler */ local_2c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [20];
  void *pvStack_14;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ac240;
  pvStack_c = ExceptionList;
  local_38 = 0;
  local_30 = 0;
  local_2c = 0;
  local_3c = param_2;
  local_34 = param_3;
  if (param_1[7] == 0) {
    ExceptionList = &pvStack_c;
    local_2c = (**(code **)(*(int *)*param_1 + 0x30))();
    uVar4 = 0x10;
    puVar3 = &local_3c;
  }
  else {
    ExceptionList = &pvStack_c;
    iVar1 = FUN_00436190(local_28,param_2);
    local_4 = 0;
    if (*(uint *)(iVar1 + 0x18) < 0x10) {
      iVar1 = iVar1 + 4;
    }
    else {
      iVar1 = *(int *)(iVar1 + 4);
    }
    uVar2 = FUN_00767160("CHUNK \"%s\" %i",iVar1,param_3);
    param_1[1] = param_1[1] | uVar2;
    local_4 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
    param_1[8] = 0;
    uVar2 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);
    param_1[1] = param_1[1] | uVar2;
    uVar2 = FUN_00767160(&DAT_00a6c044);
    param_1[1] = param_1[1] | uVar2;
    uVar4 = 2;
    param_1[8] = 0;
    puVar3 = (uint32_t /* width from decompiler */ *)&DAT_00a97b84;
  }
  uVar2 = (**(code **)(*(int *)*param_1 + 0x18))(puVar3,uVar4);
  param_1[1] = param_1[1] | uVar2;
  FUN_00436340();
  ExceptionList = pvStack_14;
  return param_1[1];
}
