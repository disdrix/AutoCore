// =============================================================================
// FUN_00436900  (alias of stoChunkReader_ReadU32_ModeDispatch)
// -----------------------------------------------------------------------------
// Stable ID: aa_00436900
// Address:   0x00436900–0x0043691a  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W22-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Entry ABI: EAX = stoChunkReader*, ECX = uint32_t* out; plain RET.
 * - Gate reader+0x4044: 0 → FUN_00437050 (binary ReadU32); else FUN_007689e0 (text).
 * - Text arm: mov edi,eax before call (text reader uses EDI).
 * - Return EAX status 0 / 0xffffffff (decompiler void is residual).
 * - Named: stoChunkReader_ReadU32_ModeDispatch (role-sealed INFERRED).
 */

#include <cstdint>

// External callees
extern "C" int32_t FUN_00437050(uint32_t* out /*stack*/ /* + reader in EAX */);
extern "C" int32_t FUN_007689e0(uint32_t* out /*stack*/ /* + reader in EDI */);

// Scaffold signature keeps Ghidra shape; status return corrected from void.
int32_t __fastcall FUN_00436900(uint32_t* out /*ECX*/)
{
  int reader; // in_EAX — retail object pointer
  // NOTE: reader is the entry EAX value (not a formal in Ghidra signature).

  if (*(int*)(reader + 0x4044) == 0) {
    return FUN_00437050(out);
  }
  return FUN_007689e0(out);
}
