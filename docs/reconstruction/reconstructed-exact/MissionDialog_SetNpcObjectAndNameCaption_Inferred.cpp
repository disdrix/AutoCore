// =============================================================================
// MissionDialog_SetNpcObjectAndNameCaption_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa4b0
// Address:   0x008aa4b0 – 0x008aa50e inclusive (95 B / 0x5F)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression
// Ghidra:    FUN_008aa4b0
// Generated: 2026-08-05 MEGA-058 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + sealed disasm.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE:
//   Stamp NPC object pointer into mission dialog+0x644 and bind or clear the
//   NPC-name caption widget at dialog+0x6d8 (vtbl+0x1d8 SetText family +
//   vtbl+0x34c refresh). Called from Client_ShowNpcMissionDialogUI (×2)
//   and from FUN_009373e0 immediately before thr0/steer0/handbrake park.
//
// ABI (register contract — not stack thiscall):
//   ESI = mission dialog host*
//   EAX = NPC object* (0 = clear name + stamp null)
//   plain RET (C3); no stack formals
//
// Sibling chrome:
//   Client_MissionDialog_SetHeaderCaption_Inferred (0x008aaf60) uses +0x6e0
//   for the *header* caption with the same +0x1d8/+0x34c paint pair.
//
// Retired scaffold: Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0
//   (incomplete — also called from FUN_009373e0).
// =============================================================================

#include <cstdint>

// Shared empty C-string constant (single 0x00 at 0x00a1419b).
extern char DAT_00a1419b;

// Register formals documented in plate; body uses ESI/EAX as sealed.
void MissionDialog_SetNpcObjectAndNameCaption_Inferred(void)
{
    // In: ESI = dialog*, EAX = npcObject*
    int dialog = 0; // placeholder for unaff_ESI (register)
    int npc = 0;    // placeholder for in_EAX (register)
    // NOTE: In retail, dialog lives in ESI and npc in EAX at entry.
    // The reconstruction below mirrors the sealed control flow with those
    // register sources named explicitly for portability comments.

    // --- sealed body (register sources: ESI=dialog, EAX=npc) ---
    // Reconstruct as if:
    //   int* dialog = (int*)ESI;
    //   int  npc    = (int)EAX;
    //
    // Live path (do not invent extra stores/loads):

    /*
    int *nameWidget = *(int **)((char *)dialog + 0x6d8);
    *(int *)((char *)dialog + 0x644) = npc;
    if (nameWidget == nullptr) {
        return;
    }
    if (npc == 0) {
        // clear path: SetText("", 1, 1)
        auto setText3 = reinterpret_cast<void (__thiscall *)(int *, char *, int, int)>(
            *(void **)(*nameWidget + 0x1d8));
        setText3(nameWidget, &DAT_00a1419b, 1, 1);
    } else {
        // bind path: secondary vtbl GetDisplayName-like, then SetText(name)
        int *savedVtbl = reinterpret_cast<int *>(*nameWidget);
        int *mid = *reinterpret_cast<int **>(npc + 4);
        int *sec = *reinterpret_cast<int **>(reinterpret_cast<char *>(mid) + 4);
        int *nameThis = reinterpret_cast<int *>(
            reinterpret_cast<char *>(sec) + npc + 4); // LEA [edx+eax+4]
        auto getName = reinterpret_cast<std::uint32_t (__thiscall *)(int *, int, int)>(
            *(void **)(*nameThis + 0x160));
        std::uint32_t nameStr = getName(nameThis, 1, 1);
        auto setText1 = reinterpret_cast<void (__thiscall *)(int *, std::uint32_t)>(
            *(void **)(reinterpret_cast<char *>(savedVtbl) + 0x1d8));
        // ECX reloaded from dialog+0x6d8 before call
        nameWidget = *reinterpret_cast<int **>((char *)dialog + 0x6d8);
        setText1(nameWidget, nameStr);
    }
    // tail JMP refresh (not CALL) — does not return here in retail if +0x34c
    // is a real method that returns; retail uses JMP [edx+0x34c]
    nameWidget = *reinterpret_cast<int **>((char *)dialog + 0x6d8);
    auto refresh = reinterpret_cast<void (__thiscall *)(int *)>(
        *(void **)(*nameWidget + 0x34c));
    refresh(nameWidget);
    */

    // Compiler-visible scaffold matching Ghidra decompile CF (register formals):
    int *piVar1;
    int iVar2;
    int in_EAX;
    std::uint32_t uVar3;
    int unaff_ESI;

    piVar1 = *(int **)(unaff_ESI + 0x6d8);
    *(int *)(unaff_ESI + 0x644) = in_EAX;
    if (piVar1 != (int *)0x0) {
        if (in_EAX == 0) {
            (**(void (__thiscall ***)(int *, char *, int, int))(*piVar1 + 0x1d8))(
                piVar1, &DAT_00a1419b, 1, 1);
        } else {
            iVar2 = *piVar1;
            uVar3 = (**(std::uint32_t (__thiscall ***)(int *, int, int))(
                *(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))(
                (int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX), 1, 1);
            (**(void (__thiscall ***)(int *, std::uint32_t))(iVar2 + 0x1d8))(
                *(int **)(unaff_ESI + 0x6d8), uVar3);
        }
        // WARNING: retail is JMP [vtbl+0x34c] (tail), not CALL+RET
        (**(void (__thiscall ***)(int *))(**(int **)(unaff_ESI + 0x6d8) + 0x34c))(
            *(int **)(unaff_ESI + 0x6d8));
        return;
    }
    return;
}
