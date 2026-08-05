// =============================================================================
// FUN_0089a260  (alias of UI_RefinePanel_InsertCommodityListRow_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0089a260
// Address:   0x0089a260 – 0x0089b06f  (autoassault.exe, base 0x400000)
// Dual:      W21-S 2026-07-29
// Prefer:    UI_RefinePanel_InsertCommodityListRow_Inferred.cpp
// =============================================================================

void UI_RefinePanel_InsertCommodityListRow_Inferred(void* host, void* entry, int qty, int flag);

// Retail ABI: stdcall 4 args, ret 0x10. arg3 flag unused in body.
// Decompiler often shows 3 params (char* for qty) — corrected by bytes.
void FUN_0089a260(int param_1, int param_2, char* param_3 /*, int flag */)
{
  UI_RefinePanel_InsertCommodityListRow_Inferred(
      (void*)param_1, (void*)param_2, (int)(intptr_t)param_3, /*flag*/ 0);
}

/*
 * Sealed facts:
 * - Body 0x0089a260–0x0089b06f (3600 B), ret 0x10
 * - Filter host+0x52c modes 1/2/3/4/6/7; tier def+0x4c8
 * - Label "[qty] name" with EN/DE quality prefix split
 * - Insert list host+0x568 (no mods, def+0x4d0!=-1) or +0x56c (has mods)
 * - Sole caller FUN_0089bc30 (×2)
 */
