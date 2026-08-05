// =============================================================================
// FUN_004bcc40  (scaffold twin → ThreadSafeObjectList_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcc40
// Address:   0x004bcc40  (autoassault.exe, image base 0x400000)
// Body:      0x004bcc40–0x004bcc5d (30 B)
// System:    client::util / lock-protected object list
// Generated: 2026-07-29 W26-I dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: ThreadSafeObjectList_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004bcbf0(void *list /* ECX */);
extern "C" void __cdecl operator_delete(void *p);

// __thiscall RET 4; EAX = this
void *__thiscall FUN_004bcc40(void *param_1 /* ECX */, uint8_t param_2)
{
    FUN_004bcbf0(param_1);
    if ((param_2 & 1u) != 0) {
        operator_delete(param_1);
    }
    return param_1;
}
