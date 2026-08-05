// =============================================================================
// stoChunkReader_readF32Array
// -----------------------------------------------------------------------------
// Stable ID: aa_00436090
// Address:   0x00436090  (autoassault.exe, image base 0x400000)
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

/* stoChunkReader read-N-float32 helper.
   Reads in_EAX (count, passed in EAX) little-endian f32 values into param_1 (fast path when
   *(param_2+0x4044)==0), else reads each element via FUN_00767fd0 (byte-swap path).
   Used by phyBoneSharedData_unserialize to read the hkQsTransform components (quaternion /
   translation / scale vectors). */

uint32_t /* width from decompiler */ __thiscall stoChunkReader_readF32Array(uint32_t /* width from decompiler */ *param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  uint32_t /* width from decompiler */ uVar2;
  
  if (*(int *)(param_2 + 0x4044) == 0) {
    if (0xf < in_EAX) {
      uVar2 = FUN_00435f30(param_1,in_EAX * 4);
      return uVar2;
    }
    if (-1 < in_EAX + -1) {
      do {
        if ((*(int *)(param_2 + 0x18) + 4 <= *(int *)(param_2 + 0x20)) ||
           ((iVar1 = FUN_00435df0(*(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x18)), -1 < iVar1
            && (3 < *(int *)(param_2 + 0x20))))) {
          *param_1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c + *(int *)(param_2 + 0x18));
          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 4;
        }
        param_1 = param_1 + 1;
        in_EAX = in_EAX + -1;
      } while (in_EAX != 0);
      return 0;
    }
  }
  else if (-1 < in_EAX + -1) {
    do {
      FUN_00767fd0(param_1);
      param_1 = param_1 + 1;
      in_EAX = in_EAX + -1;
    } while (in_EAX != 0);
  }
  return 0;
}
