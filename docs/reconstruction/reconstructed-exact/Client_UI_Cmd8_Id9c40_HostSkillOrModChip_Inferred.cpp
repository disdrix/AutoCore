// =============================================================================
// Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred
// -----------------------------------------------------------------------------
// Purpose:  UI OnCommand specialized body for (cmdClass=8, cmdId=0x9c40).
//           If local player is host-mode (+0x6b8) and not enhanced (+0x6b9==0),
//           cast first hardpoint skill with flag 0x200; else optionally run
//           mod-chip use via DAT_00d1b778 probe. Then refresh optional child
//           float widget at self+0x514. Always returns handled=true.
//
// Address:  0x008c50f4  (autoassault.exe, image base 0x400000)
// Stable:   aa_008c50f4
// System:   skills-abilities / input-drive-control (UI command dispatch)
// Ghidra:   FUN_008c50f4
//
// Convention (BYTES WIN):
//   Logical entry is the gate at 0x008c50d0 (not a Ghidra function):
//     __thiscall ECX=self; stack (cmdClass, cmdId); RET 8.
//   On (cmdClass,cmdId)==(8,0x9c40): PUSH ESI; MOV ESI,ECX; JZ 0x008c50f4.
//   Body at 0x008c50f4 expects ESI=self with ESI already pushed; ends
//   MOV AL,1; POP ESI; RET 8. Decompiler unaff_ESI == self.
//   Other (class,id) pairs forward to FUN_0087b500 (not owned here).
//
// Control flow:
//   1) if DAT_00d1b6d8 == 0 → return 1
//   2) if player+0x6b8 && !player+0x6b9 → Client_CastFirstHardpointSkillFlag200
//      else if DAT_00d1b778 && vtbl+0x3d8() → Client_Input_TryUseModChip(EDX=DAT_00d1b778)
//   3) if self+0x514 → widget vtbl+0x3c8() float; vtbl+0x3b0(float)
//   4) return 1
//
// Callees (owned elsewhere):
//   Client_CastFirstHardpointSkillFlag200_Inferred  0x008c4fc0  aa_008c4fc0
//   Client_Input_TryUseModChip                      0x0091f6b0  aa_0091f6b0
//
// Exactness: Behavior-preserving CF. Not modernization.
// Bit-for-bit / runtime: DEFERRED. Dual gap-close 2026-08-05.
// Dual reviews:
//   reviews/A_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md
//   reviews/B_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md
// Scaffold: reconstructed-exact/FUN_008c50f4.cpp
// =============================================================================

#include <cstdint>

// Globals (client image)
extern "C" int   DAT_00d1b6d8; // local character*
extern "C" void* DAT_00d1b778; // UI probe / mod-chip path object*

// Dualed callees
extern "C" void Client_CastFirstHardpointSkillFlag200_Inferred(void); // 0x008c4fc0
// __fastcall: EDX = client/ui object (ECX unused)
extern "C" void __fastcall Client_Input_TryUseModChip(std::uint32_t unused_ecx, void* client);

// Vtable helpers for opaque UI objects (slots sealed by imm offsets)
using VtblFn_Char = char(__thiscall*)(void* self);
using VtblFn_GetF = float(__thiscall*)(void* self);
using VtblFn_SetF = void(__thiscall*)(void* self, float v);

static inline void** Vtbl(void* obj)
{
    return *reinterpret_cast<void***>(obj);
}

/// UI command body for (class=8, id=0x9c40): host skill cast or mod-chip, then widget refresh.
/// @param self UI object in ESI on live entry (gate already PUSH ESI / MOV ESI,ECX).
/// @return always true (AL=1); cleans two stack formals via RET 8.
bool __thiscall Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred(void* self)
{
    // Live body does not re-read cmdClass/cmdId — gate already matched (8, 0x9c40).
    int player = DAT_00d1b6d8;
    if (player != 0) {
        const char hostFlag     = *reinterpret_cast<char*>(player + 0x6b8);
        const char enhancedFlag = *reinterpret_cast<char*>(player + 0x6b9);

        if (hostFlag != 0 && enhancedFlag == 0) {
            Client_CastFirstHardpointSkillFlag200_Inferred();
        } else {
            void* ui = DAT_00d1b778;
            if (ui != nullptr) {
                auto* vtbl = Vtbl(ui);
                const char probe = reinterpret_cast<VtblFn_Char>(vtbl[0x3d8 / 4])(ui);
                if (probe != 0) {
                    Client_Input_TryUseModChip(0, ui);
                }
            }
        }

        void* widget = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x514);
        if (widget != nullptr) {
            auto* vtbl = Vtbl(widget);
            const float f = reinterpret_cast<VtblFn_GetF>(vtbl[0x3c8 / 4])(widget);
            reinterpret_cast<VtblFn_SetF>(vtbl[0x3b0 / 4])(widget, f);
        }
    }

    return true;
}
