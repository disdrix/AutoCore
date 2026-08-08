// =============================================================================
// RETIRED scaffold — MEGA-020 (2026-08-05)
// -----------------------------------------------------------------------------
// Former auto plate: Named_CalleeOf_Named_Client_InitInstance_00802b70
// Stable ID: aa_00802b70  VA: 0x00802b70
//
// Why retired:
//   Client InitInstance (FUN_0094a6a0) only REGISTERS this address into
//   PTR_FUN_00af31e0 — it does not invoke the body. The live invoker is
//   dualed Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred (0x00578ce0)
//   via (*(code*)PTR_FUN_00af31e0)(hb, 0).
//
// Preferred clean:
//   docs/reconstruction/reconstructed-exact/Client_SkillHB_OnEndUiCleanup_Inferred.cpp
// Scaffold twin:
//   docs/reconstruction/reconstructed-exact/FUN_00802b70.cpp
// =============================================================================

// Intentionally empty — do not compile; see preferred clean above.
