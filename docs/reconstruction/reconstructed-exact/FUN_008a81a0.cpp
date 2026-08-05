// =============================================================================
// FUN_008a81a0  — alias for Client_InteractPrompt_SetTarget_Inferred
// Stable ID: aa_008a81a0  |  VA: 0x008a81a0
// See Client_InteractPrompt_SetTarget_Inferred.cpp for sealed body + dual notes.
// =============================================================================

#include <cstdint>

extern "C" void Client_InteractPrompt_SetTarget_Inferred(int* promptHost);

extern "C" void FUN_008a81a0(int* promptHost)
{
  Client_InteractPrompt_SetTarget_Inferred(promptHost);
}
