// =============================================================================
// stoChunkWriter_EndChunk
// -----------------------------------------------------------------------------
// Stable ID: aa_007673a0
// Address:   0x007673a0  (autoassault.exe, image base 0x400000)
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

/* stoChunkWriter::EndChunk()  [arda2\storage\stoChunk.cpp]
   Binary mode: pops the chunk stack, computes size = tell() - headerPos - 0x10 (so the size field
   EXCLUDES the 16-byte header), seeks back, rewrites the 16-byte header with the real size, seeks
   to end. Text mode: writes closing '}'. */

uint32_t /* width from decompiler */ __fastcall stoChunkWriter_EndChunk(uint32_t /* width from decompiler */ *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[7] == 0) {
    uVar3 = (param_1[6] + param_1[5]) - 1;
    if ((uint)param_1[4] <= uVar3) {
      uVar3 = uVar3 - param_1[4];
    }
    iVar2 = *(int *)(param_1[3] + uVar3 * 4);
    iVar1 = (**(code **)(*(int *)*param_1 + 0x30))();
    *(int *)(iVar2 + 4) = (iVar1 - *(int *)(iVar2 + 0x10)) + -0x10;
    uVar3 = (**(code **)(*(int *)*param_1 + 4))(*(int *)(iVar2 + 0x10),0);
    param_1[1] = param_1[1] | uVar3;
    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(iVar2,0x10);
    param_1[1] = param_1[1] | uVar3;
    uVar3 = (**(code **)(*(int *)*param_1 + 4))(iVar1,0);
    param_1[1] = param_1[1] | uVar3;
  }
  if ((param_1[6] != 0) && (iVar2 = param_1[6] + -1, param_1[6] = iVar2, iVar2 == 0)) {
    param_1[5] = 0;
  }
  if (param_1[7] == 1) {
    uVar3 = FUN_00767160(&DAT_00a6bfd0);
    param_1[1] = param_1[1] | uVar3;
    param_1[8] = 0;
    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);
    param_1[1] = param_1[1] | uVar3;
  }
  return param_1[1];
}
