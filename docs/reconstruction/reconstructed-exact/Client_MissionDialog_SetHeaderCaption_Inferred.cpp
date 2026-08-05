// =============================================================================
// Client_MissionDialog_SetHeaderCaption_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Set or clear the mission/NPC dialog header caption widget at
//           dialog+0x6e0. EDI==0 clears; non-zero resolves a caption string,
//           optionally formats via FUN_005465c0, applies chrome via FUN_008aab00,
//           layouts/refreshes, and optionally shows the widget.
//
// Address:  0x008aaf60  (autoassault.exe, image base 0x400000)
// Body:     0x008aaf60–0x008ab098 (312 B / 0x138)
// Stable:   aa_008aaf60
// System:   missions-progression
// Ghidra:   FUN_008aaf60
//
// Convention: ECX = dialog context; EDI = caption key (0 = clear).
//             Plain ret (C3). SEH frame present.
//
// Callers: Client_ShowNpcMissionDialogUI (×3), Client_UpdateMissionJournal (×2),
//          FUN_0093e450 choice-dialog path (×1).
//
// Decompiler lag: vtbl+0x1d8 is called with three stack args (0,1,1), not (0).
// Nested 005465c0 / 008aab00 / 008aa610 owned by other residual agents — order only.
//
// Exactness: CF mirrors live Ghidra decompile 2026-08-04 + read_memory lag fix.
// Dual: reviews/A_aa_008aaf60_* + B_aa_008aaf60_*
// Bit-for-bit / runtime: DEFERRED (terminal_coverage=false).
// =============================================================================

#include <cstdint>
#include <string>

extern int DAT_00d1b6d8;
extern char DAT_00d1b21c;
extern void* ExceptionList;
extern std::uint8_t LAB_009abcb7;

void FUN_007a69d0();
char* FUN_007a6de0(int key, unsigned unk);
void FUN_005465c0(int character, void* pString); // residual WQ7R-D
void FUN_008aab00(void* widget);                 // residual WQ7R-C
void FUN_008aa610();                             // residual WQ7R-B

// ECX = dialogCtx, EDI = captionKey — register contract (not pure thiscall)
void Client_MissionDialog_SetHeaderCaption_Inferred(int dialogCtx /*ecx*/,
                                                    int captionKey /*edi*/)
{
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;
    std::string localStr;
    int* widget;
    int* vtbl;

    local_4 = 0xffffffffu;
    puStack_8 = &LAB_009abcb7;
    local_c = ExceptionList;

    widget = *(int**)(dialogCtx + 0x6e0);
    if (widget == nullptr) {
        ExceptionList = local_c;
        return;
    }

    if (captionKey == 0) {
        ExceptionList = &local_c;
        vtbl = (int*)*widget;
        // bytes: push 1; push 1; push 0; call [vtbl+0x1d8]
        reinterpret_cast<void(__thiscall*)(int*, int, int, int)>(
            vtbl[0x1d8 / 4])(widget, 0, 1, 1);
        reinterpret_cast<void(__thiscall*)(int*)>(vtbl[0x34c / 4])(widget);
    } else {
        ExceptionList = &local_c;
        FUN_007a69d0();
        {
            char* pc = FUN_007a6de0(captionKey, 0xffffffffu);
            localStr.assign(pc ? pc : "");
        }
        local_4 = 0;
        if (DAT_00d1b6d8 != 0) {
            FUN_005465c0(DAT_00d1b6d8, &localStr);
        }
        vtbl = (int*)*widget;
        reinterpret_cast<void(__thiscall*)(int*, int, int, int)>(
            vtbl[0x1d8 / 4])(widget, 0, 1, 1);
        FUN_008aab00(widget);
        reinterpret_cast<void(__thiscall*)(int*)>(vtbl[0x1f0 / 4])(widget);
        reinterpret_cast<void(__thiscall*)(int*)>(vtbl[0x34c / 4])(widget);
        if ((DAT_00d1b21c == '\0') ||
            (*(int*)(dialogCtx + 0x648) == 2) ||
            (*(int*)(dialogCtx + 0x648) == 3)) {
            reinterpret_cast<void(__thiscall*)(int*)>(vtbl[0x1fc / 4])(widget);
        }
        local_4 = 0xffffffffu;
        // ~localStr via RAII
    }

    vtbl = (int*)*widget;
    reinterpret_cast<void(__thiscall*)(int*, int)>(vtbl[0x214 / 4])(widget, 0);
    FUN_008aa610();

    ExceptionList = local_c;
}
