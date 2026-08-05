// =============================================================================
// CVOGHBAIBase_SetFloat0x2c
// -----------------------------------------------------------------------------
// Stable ID: aa_0063a700
// Address:   0x0063a700  (autoassault.exe, image base 0x400000)
// System:    hbai
// Generated: 2026-07-29 dual A/B seal (W19-P); supersedes 2026-07-23 scaffold
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf float field setter: *(float*)(this + 0x2c) = value.
 * - Retail bytes: movss xmm0,[esp+4]; movss [ecx+0x2c],xmm0; ret 4.
 * - Decompiler typed arg as undefined4; SSE path seals IEEE float.
 * - Callers: CVOGHBAIWalkingCreatureTurreted_ctor / CVOGHBAIBase_Default_ctor
 *   pass 0.0f (push 0). Also vtbl[+0x20] on Turreted/Default (+ sibling HBAI vtbls).
 * - Product name of +0x2c field: OPEN.
 */

void __thiscall CVOGHBAIBase_SetFloat0x2c(int this_ptr, float value)
{
  *(float *)(this_ptr + 0x2c) = value;
  return;
}
