// =============================================================================
// FUN_0052db50  — scaffold alias → SkillTree_RemoveBySkillId_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0052db50
// Address:   0x0052db50  (autoassault.exe, image base 0x400000)
// Dual A/B:  2026-07-29 W20-T
// Prefer:    reconstructed-exact/SkillTree_RemoveBySkillId_Inferred.cpp
// =============================================================================

// Scaffold keeps Ghidra name for path-stable includes. Full CF (including vector
// erase omitted by decompiler) lives in the named plate.
// Signature sealed: __thiscall (this, nSkillId); ret 4.

void __thiscall SkillTree_RemoveBySkillId_Inferred(void *pThis, int nSkillId);

void __thiscall FUN_0052db50(int param_1, int param_2)
{
  SkillTree_RemoveBySkillId_Inferred(reinterpret_cast<void *>(param_1), param_2);
}
