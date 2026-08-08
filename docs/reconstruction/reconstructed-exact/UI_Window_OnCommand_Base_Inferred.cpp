// =============================================================================
// UI_Window_OnCommand_Base_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Base UI window OnCommand worker: special-case cmdId 70000 for
//           command classes {8, 0xb, 0xe} via dismiss helper FUN_0090d400
//           (ESI=self, EDI=child@+0x2b0); otherwise, if this.vtbl+0xd8() and
//           child@+0x2b0 non-null, forward OnCommand to child.vtbl+0x338.
//
// Address:  0x0082c780  (autoassault.exe, image base 0x400000)
// Stable:   aa_0082c780
// Body:     0x0082c780–0x0082c7eb inclusive last (108 B / 0x6C); pad CC×4
// System:   UI command dispatch (inventory-transfer partition host)
// Ghidra:   FUN_0082c780
//
// Convention: __thiscall ECX=this; stack (cmdClass, cmdId); RET 8.
// Entry: DATA vtable @ 0x00a732a4 (+ CALL sites from Class8 / siblings).
//
// Dual reviews (R11-027 2026-08-05):
//   reviews/A_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md
//   reviews/B_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md
// Scaffold twin: reconstructed-exact/FUN_0082c780.cpp
// Exactness: Behavior-preserving CF from live decompile + disasm. Not modernization.
// Terminal: false (no runtime Confirmed).
// =============================================================================

#include <cstdint>

// Register-convention dismiss helper (not dualled here): ESI=self, EDI=child@+0x2b0.
extern "C" void FUN_0090d400(void);

/// Base UI OnCommand: 70000 dismiss for classes {8,0xb,0xe}, else forward to child.
uint32_t __thiscall UI_Window_OnCommand_Base_Inferred(
    int* self, int cmdClass, int cmdId)
{
    // Path A: sentinel cmdId 70000 (0x11170) for classes 8 / 0xb / 0xe
    if (cmdId == 70000 && (cmdClass == 8 || cmdClass == 0xb || cmdClass == 0xe)) {
        // asm: MOV EDI, [ESI+0x2b0]; CALL FUN_0090d400  (ESI=this already)
        // Decompiler elides EDI setup; sealed by disassemble_function.
        (void)(*(int*)((char*)self + 0x2b0)); // documents EDI source
        FUN_0090d400();
        return 1;
    }

    // Path B: predicate + child forward
    auto vtbl = *reinterpret_cast<int**>(self);
    char pred = reinterpret_cast<char(__thiscall*)(int*)>(vtbl[0xd8 / 4])(self);
    int* child = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x2b0);
    if (pred != '\0' && child != nullptr) {
        auto childVtbl = *reinterpret_cast<int**>(child);
        auto onCommand = reinterpret_cast<uint32_t(__thiscall*)(int*, int, int)>(
            childVtbl[0x338 / 4]);
        return onCommand(child, cmdClass, cmdId);
    }

    return 0;
}

// Ghidra export alias
extern "C" uint32_t __thiscall FUN_0082c780(int* self, int cmdClass, int cmdId)
{
    return UI_Window_OnCommand_Base_Inferred(self, cmdClass, cmdId);
}
