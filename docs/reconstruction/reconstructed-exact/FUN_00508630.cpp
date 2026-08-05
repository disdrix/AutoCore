// =============================================================================
// FUN_00508630 — Ghidra alias for CVOGHBBase_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00508630
// Address:   0x00508630  (autoassault.exe, image base 0x400000)
// See:       CVOGHBBase_ScalarDeletingDtor.cpp (canonical clean)
// Dual A/B:  accept (2026-07-29 W23-Q)
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_009cdab0[];
extern "C" uint32_t __thiscall FUN_005085b0(void *listMgr /* ECX */, void *hb /* stack */);
extern "C" void __cdecl operator_delete(void *p);

// Canonical implementation (inlined twin for FUN_* path consumers)
void *__thiscall FUN_00508630(void *param_1 /* ECX this */, uint8_t param_2 /* flags */)
{
    void *pOwner = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0x18);
    *reinterpret_cast<void **>(param_1) = PTR_FUN_009cdab0;

    if (pOwner != nullptr) {
        void *pListMgr = *reinterpret_cast<void **>(reinterpret_cast<char *>(pOwner) + 0xB0);
        if (pListMgr != nullptr) {
            FUN_005085b0(pListMgr, param_1);
        }
    }

    if ((param_2 & 1u) != 0) {
        operator_delete(param_1);
    }

    return param_1;
}
