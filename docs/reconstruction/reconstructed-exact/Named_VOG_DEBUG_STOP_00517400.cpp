// =============================================================================
// Named_VOG_DEBUG_STOP_00517400  — LEGACY auto string alias (misleading)
// -----------------------------------------------------------------------------
// Prefer: Object_RefreshSkillHash_Inferred (aa_00517400 @ 0x00517400)
// Dual A/B W20-T 2026-07-29: "VOG_DEBUG_STOP" is only the hash-lock error path,
// not the function purpose. Keep this file as a name-stable redirect.
// =============================================================================

void Object_RefreshSkillHash_Inferred(int *pHost, char bReloadSkillDef);

void Named_VOG_DEBUG_STOP_00517400(int *param_1, char param_2)
{
  Object_RefreshSkillHash_Inferred(param_1, param_2);
}
