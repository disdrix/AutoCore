// =============================================================================
// UI_Case_CloseBtn_9c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00870e15
// Address:   0x00870e15  (autoassault.exe, image base 0x400000)
// System:    UI dialog message switch (close control 0x9c40)
// Ghidra:    caseD_9c40 / switchD_00870aaa::caseD_9c40
// Generated: 2026-07-29 dual A/B (three-rep decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI fixes.
//            Not modernization. Not bit-for-bit vs retail EXE.
// Bit-for-bit / runtime / differential: OPEN
// =============================================================================

// PURPOSE:
// Jump-table case for UI control id 0x9c40 (40000, close button) inside the
// parent message handler at 0x00870a90 (switch on controlId - 0x9c40, range 0..11).
//
// On message code 8 (click/activate):
//   - If this+0x50c == -1 (no selection): call generic leave host FUN_007fca10
//     with EAX=this and EBX=&static_client@0x00d1a840, then return 1.
//   - If this+0x50c != -1: do not leave; still return 1 (click swallowed).
// On any other message: thiscall FUN_0087b500(this, msg, controlId) and return
// its result.
//
// Parent ABI (sealed for register recovery only; parent not this unit):
//   thiscall; stack [esp+4]=msg, [esp+8]=controlId; EDI saved as this;
//   cases epilogue pop edi; ret 8.

// Callees (not owned here):
//   FUN_007fca10 @ 0x007fca10 — generic dialog leave / visible → vtbl+0x440
//   FUN_0087b500 @ 0x0087b500 — non-activate message forward helper

#include <cstdint>

// FUN_007fca10 — leave host: EAX=dialog, EBX=client object base
extern "C" void FUN_007fca10(void);

// FUN_0087b500 — thiscall (this, msg, controlId)
extern "C" uint32_t __thiscall FUN_0087b500(void* self, int msg, uint32_t controlId);

// -----------------------------------------------------------------------------
// Body 0x00870e15–0x00870e43
// Live registers on entry (set by parent 0x00870a90 before computed jump):
//   EDI = this
//   EAX = msg
//   EDX = controlId   // always 0x9c40 when this case is entered via table[0]
// -----------------------------------------------------------------------------
uint32_t UI_Case_CloseBtn_9c40_live(/* EDI */ void* self,
                                    /* EAX */ int msg,
                                    /* EDX */ uint32_t controlId)
{
    if (msg == 8) {
        if (*(int*)((char*)self + 0x50c) == -1) {
            // push ebx; mov eax, edi; mov ebx, 0x00d1a840; call FUN_007fca10; pop ebx
            // (register ABI for leave host — not a C prototype)
            FUN_007fca10();
        }
        return 1;
    }

    return FUN_0087b500(self, msg, controlId);
}

// Decompiler-shaped mirror (phantoms preserved for raw ↔ clean audit):
// undefined4 __fastcall switchD_00870aaa::caseD_9c40(param_1, param_2)
// {
//   if (in_EAX == 8) {
//     if (*(int*)(unaff_EDI + 0x50c) == -1) FUN_007fca10();
//     return 1;
//   }
//   return FUN_0087b500(in_EAX, param_2);  // decompiler omits ECX=this
// }
