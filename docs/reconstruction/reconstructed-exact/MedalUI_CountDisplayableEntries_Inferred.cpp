// =============================================================================
// MedalUI_CountDisplayableEntries_Inferred  (aa_0090c810)
// -----------------------------------------------------------------------------
// Address:   0x0090c810–0x0090c8c9 inclusive (186 B / 0xBA)
// Wave:      MEGA-103 OWN-ONLY dual 2026-08-05
// System:    missions-progression / Medal UI query (count)
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + caller context. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Query total displayable medal/achievement entries for the medal UI:
//     count = size(owned-id vector at char+0x574/+0x578)
//           + #{ hash entries at char+0x540 whose payload[+0x100] has a
//                MedalDef_LookupById hit }
//   Parent FUN_0090cbc0 uses the result for page math (threshold 0x18/0x19)
//   after MedalUI_PrepClearButtonSlots_Inferred and before button bind.
//
// ABI:
//   EBX = character / medal-state object* (callers MOV EBX,[DAT_00d1b6d8]).
//   No stack formals. EAX = int count. Bare RET (C3).
//
// CALLERS:
//   FUN_0090cbc0 @ 0x0090cbfa
//   FUN_0090c920 @ 0x0090c938
//   gap twin @ 0x0090c8ed (body starts 0x0090c8d0; Ghidra unnamed)
//
// RETIRED SCAFFOLD:
//   Named_VOG_DEBUG_STOP_0090c810 (VOG_DEBUG_STOP is hash-lock warn only).
// =============================================================================

#include <cstdint>

// Forward decls — dualed / residual peers
extern "C" void* /* MedalDef* */ __cdecl MedalDef_LookupById(uint32_t id);  // FUN_0051a0e0
extern "C" void __cdecl FUN_007a4480(int channel, const char* msg);

// Character / medal-state layout fragments used here:
//   +0x540  hash table object*
//   +0x574  owned medal-id vector begin (uint32_t*)
//   +0x578  owned medal-id vector end
// Hash object:
//   +0x14   first chain node*
//   +0x1d   traversal lock (byte)
// Chain node:
//   +0x08   payload*
//   +0x14   next node*
// Payload:
//   +0x100  medal def id

// EBX-this custom convention (not MSVC thiscall ECX).
extern "C" int MedalUI_CountDisplayableEntries_Inferred(void /* EBX = char* */)
{
  uint8_t* character;
  int count;
  uint8_t* hashObj;
  uint8_t* cursor;
  uint8_t* payload;
  void* def;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov character, ebx
  }
#else
  // Non-MSVC rebuilds must pass character explicitly; retail ABI is EBX.
  character = nullptr;
#endif

  if (character == nullptr) {
    return 0;
  }

  // Phase A — owned-id vector size (raw; no lookup filter)
  {
    uint32_t* begin = *reinterpret_cast<uint32_t**>(character + 0x574);
    if (begin == nullptr) {
      count = 0;
    } else {
      uint32_t* end = *reinterpret_cast<uint32_t**>(character + 0x578);
      count = static_cast<int>(
          (reinterpret_cast<uintptr_t>(end) - reinterpret_cast<uintptr_t>(begin)) >> 2);
    }
  }

  // Phase B — hash traverse with lock at hash+0x1d
  hashObj = *reinterpret_cast<uint8_t**>(character + 0x540);
  cursor = nullptr;

  if (hashObj[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  hashObj[0x1d] = 1;

  while (true) {
    hashObj = *reinterpret_cast<uint8_t**>(character + 0x540);

    if (hashObj[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    if (cursor == nullptr) {
      cursor = *reinterpret_cast<uint8_t**>(hashObj + 0x14);
    } else {
      cursor = *reinterpret_cast<uint8_t**>(cursor + 0x14);
    }

    if (cursor == nullptr) {
      payload = nullptr;
    } else {
      payload = *reinterpret_cast<uint8_t**>(cursor + 0x08);
    }

    if (payload == nullptr) {
      break;
    }

    {
      uint32_t medalId = *reinterpret_cast<uint32_t*>(payload + 0x100);
      def = MedalDef_LookupById(medalId);
      if (def != nullptr) {
        count = count + 1;
      }
    }
  }

  (*reinterpret_cast<uint8_t**>(character + 0x540))[0x1d] = 0;
  return count;
}
