// Scaffold twin — see AssManager_ReleaseOwnedResolvers_Inferred.cpp (aa_007b65d0, W29-D)
// Ghidra name retained for path stability.

#include <cstdint>

void AssManager_ReleaseOwnedResolvers_Inferred(void* self_ebx);

extern "C" void FUN_007b65d0(void)
{
  // Retail: this in EBX; no stack formals.
  // Call AssManager_ReleaseOwnedResolvers_Inferred with EBX as self.
  AssManager_ReleaseOwnedResolvers_Inferred(/*EBX*/ nullptr);
  (void)0;
}
