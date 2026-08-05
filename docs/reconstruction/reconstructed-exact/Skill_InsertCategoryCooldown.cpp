// READABILITY:
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Skill_GetCategoryCooldownMap, Skill_CategoryCooldownMap_Insert.
//  - Return sites: 1 × RET 0x8.
//  - Residual 2026-07-29: stdcall RET 8; pack now=g_dwClientTickMs; insert-or-find (no equal-key update).

// =============================================================================
// Skill_InsertCategoryCooldown
// -----------------------------------------------------------------------------
// Stable ID: aa_00518df0
// Address:   0x00518df0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow + verified bytes.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - __stdcall; RET 0x8 (two stack args: categoryId, durationMs).
 * - ECX at entry = map owner (cast-side host with map* at +0x6c); phantom, not formal.
 * - categoryId == -1 → no-op (no GetMap / Insert).
 * - Entry pack: { key=categoryId, start=g_dwClientTickMs (0x00b041cc), duration=durationMs }.
 * - Map_Insert is insert-or-find; equal key does not refresh start/duration.
 * - Sole static caller: Skill_ApplyStatusEffectLocal @ 0x0051ac77 (item-skill path).
 * - Cast-again ctor inserts via Map_Insert directly (not this wrapper).
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

/* Skill_InsertCategoryCooldown(categoryId, durationMs)

   Inserts category cooldown map entry: start=g_dwClientTickMs, duration=param.
   Used for item skills; cast-again ctor also inserts (via Map_Insert, not here). */

void __stdcall Skill_InsertCategoryCooldown(int nCategoryId, int nDurationMs)
{
  void *in_ECX;                 // map owner at entry (phantom)
  unsigned char *puVar1;        // &outPair
  int *piVar2;                  // &entry
  unsigned char local_14[8];    // InsertPair {it*, inserted}
  int nKey;
  unsigned int nStartTick;
  int nDuration;

  if (nCategoryId != -1) {
    nStartTick = g_dwClientTickMs;   // DAT_00b041cc / 0x00b041cc
    piVar2 = &nKey;
    nDuration = nDurationMs;
    puVar1 = local_14;
    nKey = nCategoryId;
    Skill_GetCategoryCooldownMap(in_ECX);           // __fastcall ECX=owner → map*
    Skill_CategoryCooldownMap_Insert(puVar1, piVar2); // thiscall this=map (EAX)
  }
  return;
}
