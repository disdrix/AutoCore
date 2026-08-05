// =============================================================================
// Client_SendGlobalPacket
// -----------------------------------------------------------------------------
// Stable ID: aa_008073b0
// Address:   0x008073b0  (autoassault.exe, image base 0x400000)
// System:    network-global
// Generated: 2026-07-29 dual A/B seal (W18-B)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE:
//   Generic C2S **global** transport. If client+0xc7c (global connection) is
//   non-null AND conn->vtbl[+0x08]() reports ready, call
//   conn->vtbl[+0x18](0xFFFFFFFF, buffer, (int)size, 0) and return 0.
//   Otherwise return E_FAIL (0x80004005).
//
// ABI (sealed by read_memory):
//   ESI          = client*   (NOT ECX thiscall — contrast Client_SendSectorPacket)
//   stack        short size, void* buffer
//   epilogue     ret 8
//   returns      0 on send; 0x80004005 if null conn or ready-check fails
//
// Sibling: Client_SendSectorPacket @ 0x00807460 uses client+0xc78 / ECX thiscall /
//          silent null drop / reliability from live-in EAX.
//
// Callers (examples): Client_SendChatOrMacro (global 0x8000), dismiss modal 0x8006,
//                     force-quit dialog, many UI/global builders (50+ xrefs).
//
// Ghidra alias: FUN_008073b0
// Scaffold:     FUN_008073b0.cpp (prior)
// Dual reviews: A_/B_aa_008073b0_Client_SendGlobalPacket.md
// =============================================================================

#include <cstdint>

// Register ESI holds client* at entry (custom/register ABI; decompiler: unaff_ESI).
uint32_t Client_SendGlobalPacket(short size, uint32_t buffer /* ESI = client* */)
{
  char cVar1;
  int client; // unaff_ESI in Ghidra

  // NOTE: `client` is live-in ESI, not a stack/ECX formal.
  if (*(int *)(client + 0xc7c) != 0) {
    cVar1 = (**(code **)(**(int **)(client + 0xc7c) + 8))(); // vtbl+0x08 ready?
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(client + 0xc7c) + 0x18))(
          0xffffffff, buffer, (int)size, 0);
      return 0;
    }
  }
  return 0x80004005; // E_FAIL
}
