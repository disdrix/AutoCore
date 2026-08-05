// =============================================================================
// FUN_0053b900  (scaffold alias → CNDHash_scalar_dtor_009cfa7c)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053b900
// Address:   0x0053b900  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-07-29 W25-H dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named clean: CNDHash_scalar_dtor_009cfa7c.cpp
// Dual A/B: accept-with-gaps
// =============================================================================

extern "C" void operator_delete(void *);
extern void __fastcall FUN_0053b920(void *thisHash);

void *__thiscall FUN_0053b900(void *param_1, unsigned char param_2)
{
    FUN_0053b920(param_1);
    if ((param_2 & 1) != 0) {
        operator_delete(param_1);
    }
    return param_1;
}
