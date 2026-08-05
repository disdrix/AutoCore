// =============================================================================
// EnsureQuestBaseCreditsLoaded
// -----------------------------------------------------------------------------
// Purpose:  Ensure-load wrapper for tQuestBaseCredits (client table used by
//           Mission_ComputeObjectiveCredits base term). Always invokes the
//           WAD/DB load path; does not early-out on the ready flag (caller-gated).
//
// Address:  0x00512870  (autoassault.exe, image base 0x400000)
// Body:     0x00512870 – 0x005128ad (62 bytes)
// Stable:   aa_00512870
// System:   missions-progression
//
// Convention: no stack args; void return.
//
// Asm-sealed algorithm (2026-07-29 dual A/B):
//   ECX = *g_pDbReaderCtx_Inferred              // DAT_00b0469c
//   DbReader_Enter_Inferred(ECX)                // FUN_007e1d80
//   ECX = *g_pDbReaderCtx_Inferred
//   status = LoadQuestBaseCreditsFromWad(ECX, &g_pQuestBaseCreditsMap_Inferred)
//           // stack imm 0x00b04264; callee 0x007cc810
//   ECX = *g_pDbReaderCtx_Inferred
//   DbReader_Leave_Inferred(ECX)                // FUN_007b7df0
//   if (status < 0) FUN_007a4480(0, "VOG_DEBUG_STOP");  // str @ 0x00a15844
//
// Plate comment "if already loaded: return" / "sets loaded flag" is NOT in body.
// Sibling: EnsureQuestCreditsLookupLoaded (0x00512830) — same shape, map 0x00b04258.
//
// Exactness: Behavior-preserving rewrite of raw decompile + asm ECX plumbing.
// =============================================================================

#include <cstdint>

// aa_007cc810 — ECX = DB ctx; stack = address of map root block at 0x00b04264
int  __fastcall LoadQuestBaseCreditsFromWad(void* pDbCtx, void* pMapRoot);
// FUN_007e1d80 / FUN_007b7df0 — ECX = DB ctx (refcount at ctx+0x20)
void __fastcall FUN_007e1d80(void* pDbCtx);
void __fastcall FUN_007b7df0(void* pDbCtx);
void FUN_007a4480(int level, const char* fmt, ...);

// DAT_00b0469c
extern void* g_pDbReaderCtx_Inferred;
// 0x00b04264 — map root; +4 end sentinel; +8 loaded flag (flag not written here)
extern void* g_pQuestBaseCreditsMap_Inferred;

void EnsureQuestBaseCreditsLoaded(void)
{
    int nLoadResult;
    void* pCtx;

    pCtx = g_pDbReaderCtx_Inferred;
    FUN_007e1d80(pCtx);

    pCtx = g_pDbReaderCtx_Inferred;
    nLoadResult = LoadQuestBaseCreditsFromWad(pCtx, &g_pQuestBaseCreditsMap_Inferred);

    pCtx = g_pDbReaderCtx_Inferred;
    FUN_007b7df0(pCtx);

    if (nLoadResult < 0) {
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
}
