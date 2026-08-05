// =============================================================================
// FUN_00767070 / stoChunkWriter_WriteTextIndent
// -----------------------------------------------------------------------------
// Stable ID: aa_00767070
// Address:   0x00767070–0x0076709d  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W17-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/stoChunkWriter_WriteTextIndent.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - ESI = stoChunkWriter* (register ABI; sole caller WriteFormatted).
 * - count = depth(+0x18)*4; textCol(+0x20)=count; write " " × count via vt+0x18.
 * - status |= each write; return status (+0x04).
 */

#include <cstdint>

// DAT_00a2a000 = " "
extern const char DAT_00a2a000[];

// Decompiler-faithful plate (unaff_ESI = writer)
uint32_t FUN_00767070(void /* ESI = writer */)
{
  // Layout via dword indices matching decompiler unaff_ESI[n]
  // [0]=stream*, [1]=status, [6]=depth, [8]=textCol
  // Implemented as byte offsets in the named clean plate.

  // Pseudocode mirror of raw:
  // iVar2 = unaff_ESI[6] * 4;
  // unaff_ESI[8] = iVar2;
  // if (-1 < iVar2 + -1) {
  //   do {
  //     uVar1 = stream_write_vt18(&DAT_00a2a000, 1);
  //     unaff_ESI[1] |= uVar1;
  //     iVar2--;
  //   } while (iVar2 != 0);
  // }
  // return unaff_ESI[1];

  // See stoChunkWriter_WriteTextIndent.cpp for typed reconstruction.
  return 0; // not linked; documentation unit
}
