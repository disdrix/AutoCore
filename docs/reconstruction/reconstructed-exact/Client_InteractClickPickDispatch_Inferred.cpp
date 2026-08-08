// =============================================================================
// Client_InteractClickPickDispatch_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Client virtual mouse-click **entry / dispatch** for the primary
//           interact pick path. Gates mode/UI/character state, cancels pending
//           skill target-select, sets free-select flag DAT_00d1a859, then calls
//           dualed Client_InteractClickPickTarget with soft(0) or commit(1)
//           based on DAT_00d1a860. Soft path may arm CVOGHBBase heartbeat.
//
// Address:  0x009251d0  (autoassault.exe, image base 0x400000)
// Body:     0x009251d0–0x009253d6 inclusive (519 B / 0x207)
// Stable:   aa_009251d0
// System:   interaction-activation
// Generated: 2026-08-05 R11-038 dual A/B (prior scaffold FUN_009251d0 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + asm ABI seal.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
//
// Install:  client vtable DATA @ 0x00a2f41c → this
// Sibling:  Client_InteractWorldClickHub @ 0x00a2f420 (next vtable dword)
// Parent:   Client_InteractClickPickTarget 0x009247b0 (only CALL target for pick)
//
// Convention (asm Confirmed 2026-08-05):
//   ECX / EBX  = client controller* (thiscall; EBX holds this for body)
//   stack arg1 = forwarded residual (object consume + ClickPickTarget formal)
//   stack arg2 = packed screen coords (lo16 sx i16, hi16 sy i16)
//   return AL  = bool; epilogue RET 8
//
// Soft vs commit (parent dual residual English Open):
//   DAT_00d1a860 != 0 → ClickPickTarget(..., softOrCommit=0, filter); return 0
//   DAT_00d1a860 == 0 → ClickPickTarget(..., softOrCommit=1, filter); return its AL
//
// Dual:
//   reviews/A_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md
//   reviews/B_aa_009251d0_Client_InteractClickPickDispatch_Inferred.md
//   docs/agents/task-dual-ab-009251d0-r11-report.md
// =============================================================================

#include <cstdint>

// Named / plate callees (ownership elsewhere)
extern std::uint8_t Client_InteractClickPickTarget(
    std::uint32_t arg1, std::uint32_t packedMouse,
    std::uint32_t softOrCommit, std::uint8_t filterFlag);
// Note: parent dual also documents client residual in EBX at call sites.
extern void Client_PromptSkillTargetSelect(void* clientSingleton, int showFlag);
// Call site: OR EAX,-1 then CALL — skill id cleared; show=0.
extern void FUN_007fb990(void); // ESI=client residual; post-cancel UI helper
extern char FUN_00914be0(void); // free-to-soft-select world/input predicate
extern void CVOGHBBase_Start(void* hb); // 0x005081c0; ECX=this

// Globals (Ghidra DAT_* — absolute aliases of client singleton fields where sealed)
extern int DAT_00d1b644;           // world / session object*
extern int DAT_00d1d900;           // pending skill/mode (== client+0x30c0 absolute)
extern int DAT_00d1d904;           // sibling of pending (read, not branched here)
extern int DAT_00d1b6d8;           // player character*
extern int* DAT_00d1b958;          // UI modal host*
extern int* DAT_00d1b95c;          // UI modal host*
extern int* DAT_00d1b898;
extern int* DAT_00d1b89c;
extern int* DAT_00d1b894;
extern int* DAT_00d1b888;
extern int* DAT_00d1b88c;
extern unsigned char DAT_00d1a859; // free-to-soft-select flag (written)
extern unsigned char DAT_00d1a860; // soft-cast / soft-interact mode flag (read)
extern unsigned char DAT_00d1b205; // filter flag into ClickPickTarget param_4
extern int DAT_00d1a840;           // client singleton base for PromptSkillTargetSelect

std::uint8_t __thiscall Client_InteractClickPickDispatch_Inferred(
    int* client,
    std::uint32_t arg1,
    std::uint32_t packedMouse)
{
  char freeOk;
  char modalBusy;
  std::uint8_t pickRet;

  // Stage 0 — mode-6 quiet swallow (client+0xcc4 / +0x493 / world+0xf5)
  if (((client[0x331] == 6) && (*reinterpret_cast<char*>(reinterpret_cast<int>(client) + 0x493) == '\0')) &&
      (*reinterpret_cast<char*>(DAT_00d1b644 + 0xf5) == '\0')) {
    return 0;
  }

  // Stage 1 — mouse UI on select slot client+0x4b8
  (**(code**)(*client + 0x3bc))(client[0x12e]);
  (**(code**)(*client + 0x42c))(
      client[0x12e],
      static_cast<int>(static_cast<std::int16_t>(packedMouse)),
      static_cast<int>(static_cast<std::int16_t>(packedMouse >> 16)));

  // Stage 2 — selected object consume (vtbl+0x378)
  if ((reinterpret_cast<int*>(client[0x12e]) != nullptr) &&
      (freeOk = (**(code**)(*reinterpret_cast<int*>(client[0x12e]) + 0x378))(arg1, packedMouse),
       freeOk != '\0')) {
    return 1;
  }

  // Stage 3 — cancel pending skill target-select
  if (DAT_00d1d900 != -1) {
    // EAX = -1 (asm OR EAX,0xFFFFFFFF) before CALL; show flag 0
    Client_PromptSkillTargetSelect(&DAT_00d1a840, 0);
    FUN_007fb990();
    return 1;
  }

  // Stage 4 — require character
  if (DAT_00d1b6d8 == 0) {
    return 0;
  }

  // Stage 5 — character blocked/dead component
  freeOk = (**(code**)(*reinterpret_cast<int*>(
      *reinterpret_cast<int*>(*reinterpret_cast<int*>(DAT_00d1b6d8 + 4) + 4) + 4 +
      DAT_00d1b6d8) +
                         0x194))();
  if (freeOk != '\0') {
    return 0;
  }

  // Stage 6 — primary UI modal pair
  freeOk = (**(code**)(*DAT_00d1b958 + 0x3d8))();
  if (freeOk != '\0') {
    return 0;
  }
  freeOk = (**(code**)(*DAT_00d1b95c + 0x3d8))();
  if (freeOk != '\0') {
    return 0;
  }

  // Stage 7 — DAT_00d1a859 free-to-soft-select
  freeOk = FUN_00914be0();
  if ((((((freeOk == '\0') || (*reinterpret_cast<int*>(DAT_00d1b6d8 + 0xcd0) != 0)) ||
         ((DAT_00d1b898 != nullptr &&
           (modalBusy = (**(code**)(*DAT_00d1b898 + 0x3d8))(), modalBusy != '\0')))) ||
        ((DAT_00d1b89c != nullptr &&
          (modalBusy = (**(code**)(*DAT_00d1b89c + 0x3d8))(), modalBusy != '\0')))) ||
       ((DAT_00d1b894 != nullptr &&
         (modalBusy = (**(code**)(*DAT_00d1b894 + 0x3d8))(), modalBusy != '\0')))) ||
      (((DAT_00d1b888 != nullptr &&
         (modalBusy = (**(code**)(*DAT_00d1b888 + 0x3d8))(), modalBusy != '\0')) ||
        ((DAT_00d1b88c != nullptr &&
          (modalBusy = (**(code**)(*DAT_00d1b88c + 0x3d8))(), modalBusy != '\0')))))) {
    DAT_00d1a859 = 0;
  } else {
    DAT_00d1a859 = 1;
  }

  // Stage 8 — soft vs commit pick hub
  if (DAT_00d1a860 != '\0') {
    Client_InteractClickPickTarget(arg1, packedMouse, 0, DAT_00d1b205);
    if ((client[0x31c] != 0) && (freeOk != '\0')) {
      *reinterpret_cast<std::uint8_t*>(reinterpret_cast<int>(client) + 0xa35) = 1;
      CVOGHBBase_Start(reinterpret_cast<void*>(client[0x31c]));
    }
    return 0;
  }
  pickRet = Client_InteractClickPickTarget(arg1, packedMouse, 1, DAT_00d1b205);
  return pickRet;
}
