// =============================================================================
// EnsureFactionsLookupLoaded  (named alias of FUN_005197b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005197b0
// Address:   0x005197b0 – 0x00519a22  (autoassault.exe, image base 0x400000)
// Body:      626 bytes (0x272)
// System:    factions / client table bring-up
// Generated: 2026-08-04 (WQ9R-F dual seal)
// Exactness: Behavior-preserving control-flow notes from raw + bytes + loader xpath.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Contract:
//   void EnsureFactionsLookupLoaded(void);  // cdecl, no args
//
//   1. CNDHash_Recreate(&DAT_00b04314, power=4)
//   2. DbEnter(*DAT_00b0469c) → FUN_007ce550 (//tFactions/row) → DbLeave
//   3. For each source row (stride 0xC4):
//        rec = new 0x64 { id@0, mbcsA@+4, mbcsB@+0x24 }
//        CNDHash_Insert(hash, id, rec, allowDup=0)  // FUN_0051e5d0
//   4. Free temp vector; SEH restore
//
// Consumers:
//   FUN_0051a120(id) when DAT_00b04320 == 0 (lazy)
//   FUN_0094a6a0 InitInstance boot table pack
//
// Loader plate (FUN_007ce550): L"//tFactions/row"; row size 0xC4
// =============================================================================

#include <cstdint>
#include <windows.h>

// Hash host at 0x00b04314 — CNDHash_Recreate power 4 (FUN_0051d290)
void __thiscall CNDHash_Recreate_Inferred(void* hash, uint8_t power);
// FUN_0051e5d0
uint32_t __thiscall CNDHash_Insert_Inferred(void* hash, uint32_t key, void* value, char allowDup);
// DB bookends
void __fastcall FUN_007e1d80(void* pDbCtx);
void __fastcall FUN_007b7df0(void* pDbCtx);
// Load tFactions rows into vector (xpath //tFactions/row) — FUN_007ce550
int /*status*/ LoadTFactionsRows_Inferred(void* pDbCtx, void* outStatusScratch, void* outVector);
void FUN_007a4480(int level, const char* fmt, ...);
void FUN_004048e0(uint32_t hr); // noreturn OOM path
void FUN_004048c0(void);        // Win32 last-error throw

extern void* g_pDbReaderCtx_Inferred; // DAT_00b0469c
// 0x00b04314 faction hash
extern uint8_t g_FactionHash_Inferred[];

struct FactionSrcRow_Inferred {
    uint32_t id;           // +0x00
    wchar_t  nameA[0x20];  // +0x04  (0x40 bytes)
    wchar_t  nameB[/*…*/]; // +0x44  through end of 0xC4
};

struct FactionRec_Inferred {
    uint32_t id;       // +0x00
    char     nameA[0x20]; // +0x04
    char     nameB[0x40]; // +0x24  (remainder of 0x64)
};

// Full line-faithful body retained in FUN_005197b0.cpp (scaffold).
// This unit documents the sealed contract for ports.

void EnsureFactionsLookupLoaded(void);
/* implementation: see FUN_005197b0.cpp — same VA entry; prefer this name in call sites */

// Port sketch (not bit-exact):
/*
void EnsureFactionsLookupLoaded(void)
{
    CNDHash_Recreate_Inferred(&g_FactionHash_Inferred, 4);
    void* rows = nullptr; int rowEnd = 0; // vector begin/end
    FUN_007e1d80(g_pDbReaderCtx_Inferred);
    int st = LoadTFactionsRows_Inferred(g_pDbReaderCtx_Inferred, ...);
    FUN_007b7df0(g_pDbReaderCtx_Inferred);
    if (st < 0) FUN_007a4480(0, "VOG_DEBUG_STOP");
    // for each 0xC4 row: alloc 0x64, WCMAP two strings, CNDHash_Insert_Inferred(hash, id, rec, 0)
    // operator_delete(rows)
}
*/

void FUN_005197b0(void)
{
    EnsureFactionsLookupLoaded();
}
