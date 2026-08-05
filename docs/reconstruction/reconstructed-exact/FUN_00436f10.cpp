// =============================================================================
// FUN_00436f10 / stoChunkStreamWindow_ReadCString
// -----------------------------------------------------------------------------
// Stable ID: aa_00436f10
// Address:   0x00436f10–0x00436f7b  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk stream window
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (W38-D)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/stoChunkStreamWindow_ReadCString.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Decompiler form: unaff_ESI = window*, unaff_EDI = std::string*.
 * - Body bytes: ESI=window, EDI=string*, bare RET, 0/−1.
 * - Callees: string::resize IAT, FUN_00435df0 ensure, string::operator+= IAT.
 */

#include <cstdint>
#include <string>

// External (not owned)
extern "C" int32_t FUN_00435df0(int32_t absPos); // thiscall ECX=window in retail

// Decompiler-faithful plate (ESI = window*, EDI = string*)
uint32_t FUN_00436f10(void)
{
  char cVar1;
  int iVar2;
  int unaff_ESI; // window* in ESI on entry
  std::string* unaff_EDI; // out string* in EDI on entry

  unaff_EDI->resize(0);

  if (*(int*)(unaff_ESI + 4) + *(int*)(unaff_ESI + 8) < *(int*)(unaff_ESI + 0x14)) {
    do {
      if (*(int*)(unaff_ESI + 0xc) < *(int*)(unaff_ESI + 4) + 1) {
        iVar2 = FUN_00435df0(*(int*)(unaff_ESI + 8) + *(int*)(unaff_ESI + 4));
        // retail: ECX = unaff_ESI before call
        if (iVar2 < 0) {
          return 0xffffffff;
        }
        if (*(int*)(unaff_ESI + 0xc) < 1) {
          return 0xffffffff;
        }
      }
      cVar1 = *(char*)(*(int*)(unaff_ESI + 4) + 0x18 + unaff_ESI);
      *(int*)(unaff_ESI + 4) = *(int*)(unaff_ESI + 4) + 1;
      if (cVar1 == '\0') {
        return 0;
      }
      (*unaff_EDI) += cVar1;
    } while (*(int*)(unaff_ESI + 4) + *(int*)(unaff_ESI + 8) < *(int*)(unaff_ESI + 0x14));
  }
  return 0xffffffff;
}
