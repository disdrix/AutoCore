// =============================================================================
// FUN_00556b10  (twin of Weather_NfxListFillOrActivate_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00556b10
// Address:   0x00556b10–0x00556ce2  (autoassault.exe, image base 0x400000)
// Dual:      W32-I 2026-07-29
// Prefer:    Weather_NfxListFillOrActivate_Inferred.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean:
//   docs/reconstruction/reconstructed-exact/Weather_NfxListFillOrActivate_Inferred.cpp

// Retail: ECX=weather host; stack (outList*, weatherObj*, mode); RET 0xC.
// Clear list; mode0 fill nfx resource ids; mode1 activate weather FX.

void __thiscall FUN_00556b10(void* weatherHost /*ECX*/,
                             void* outList,
                             void* weatherObj,
                             char mode)
{
  // FUN_0043d650(outList, 0);
  // if (!weatherObj) return;
  // mode==0: resolve names + optional "_nfx.xml" (DAT_009ca184) + push ids
  // mode!=0: FUN_00555600 / FUN_00553d20 + FUN_004b88e0
  (void)weatherHost;
  (void)outList;
  (void)weatherObj;
  (void)mode;
}
