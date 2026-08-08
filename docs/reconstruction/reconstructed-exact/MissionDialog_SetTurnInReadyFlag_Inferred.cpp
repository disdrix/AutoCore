// =============================================================================
// MissionDialog_SetTurnInReadyFlag_Inferred  (aa_008aa490)
// -----------------------------------------------------------------------------
// Address:   0x008aa490–0x008aa4a6 inclusive (23 B / 0x17)
// Wave:      MEGA-078 OWN-ONLY dual 2026-08-05
// System:    missions-progression / NPC mission dialog pre-present
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + caller context. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Pre-present setup on the NPC mission dialog host: store the turn-in
//   readiness flag (char) at dialog+0x580, then if the optional child object
//   at dialog+0x6e8 is non-null, notify it via vtbl[+4] with that flag.
//
//   Sole caller Client_ShowNpcMissionDialogUI seeds the flag from
//   FUN_0052b420 (turn-in readiness probe) immediately before this call, then
//   continues with PrepareResponseOpcode / panel fill / reward chrome.
//
// ABI:
//   EAX = mission dialog host (client+0x1058 controller; caller MOV EAX,EBX).
//   DL  = turn-in ready flag (0/1); full EDX pushed to child vcall.
//   No stack formals. void. Bare RET (C3).
//   NOT MSVC ECX-thiscall for the host.
//
// CALLERS:
//   Client_ShowNpcMissionDialogUI @ 0x00943a57 (sole UNCONDITIONAL_CALL).
//
// RETIRED SCAFFOLD:
//   Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa490 (parent-seed only).
// =============================================================================

#include <cstdint>

// Dialog host layout fragments used here (not a full class def):
//   +0x580  char  turnInReadyFlag
//   +0x6e8  void* optionalChild  // vtbl[+4](flag) when non-null

using VFunc_SetFlag = void(__thiscall*)(void* self, uint32_t flagArg);

// EAX-host + DL-flag custom convention (not MSVC thiscall ECX).
extern "C" void MissionDialog_SetTurnInReadyFlag_Inferred(void /* EAX=dialog, DL=flag */)
{
  void* dialog;
  uint32_t flagEdx;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov dialog, eax
    mov flagEdx, edx
  }
#else
  // Non-MSVC rebuilds must pass host/flag explicitly; retail ABI is EAX+DL.
  dialog = nullptr;
  flagEdx = 0;
#endif

  auto* base = reinterpret_cast<uint8_t*>(dialog);
  void* child = *reinterpret_cast<void**>(base + 0x6e8);

  // Always store low byte of flag at dialog+0x580 (even if child is null).
  *(base + 0x580) = static_cast<uint8_t>(flagEdx & 0xFF);

  if (child != nullptr) {
    void** childVtbl = *reinterpret_cast<void***>(child);
    // PUSH EDX; CALL [vtbl+4]  — thiscall ECX=child, stack=full EDX
    reinterpret_cast<VFunc_SetFlag>(childVtbl[1])(child, flagEdx);
  }
}
