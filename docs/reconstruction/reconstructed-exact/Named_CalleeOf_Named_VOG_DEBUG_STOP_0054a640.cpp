// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0054a640
// -----------------------------------------------------------------------------
// Stable ID: aa_0054a640
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0054a640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~556 non-empty decompiler lines.
//  - Control keywords: if×39, return×1.
//  - Notable callees: FUN_0054eb20×39, FUN_00578830×27, FUN_00618100×11, FUN_0054a640, FUN_0054f250.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_VOG_DEBUG_STOP_0054a640(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *local_28;

  uint32_t /* width from decompiler */ *local_24;

  uint8_t local_20 [12];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a4608;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  local_28 = operator_new(0x6d0);

  local_c = 0;

  if (local_28 == (uint32_t /* width from decompiler */ *)0x0) {

    local_24 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_24 = (uint32_t /* width from decompiler */ *)FUN_00618100();

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x0;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 1;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d108c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 2;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d1acc;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x2;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 3;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d0e6c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x3;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 4;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d0fdc;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x4;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 5;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1144;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x5;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 6;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d0f1c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x6;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 7;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d156c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x7;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 8;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d12ac;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x8;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 9;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d0f7c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x9;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 10;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d0ec4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0xa;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0xb;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d0e14;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0xb;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0xc;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1034;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0xc;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0xd;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d15c4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0xd;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0xe;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d10e4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0xe;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0xf;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d119c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0xf;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x10;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d11f4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x10;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x11;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d124c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x11;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x12;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d1304;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x12;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6e0);

  local_c = 0x13;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d135c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x13;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x14;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d13b4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x14;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x15;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d140c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x15;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x16;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1464;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x16;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6e0);

  local_c = 0x17;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d14bc;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x17;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x18;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d1514;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x18;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x19;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1624;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x19;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6f0);

  local_c = 0x1a;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1ba4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1a;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x1b;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1684;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1b;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x1c;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d16e4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1c;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x1d;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1744;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1d;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x1e;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d17a4;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1e;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6e0);

  local_c = 0x1f;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d17fc;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x1f;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x20;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d185c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x20;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x21;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d18bc;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x21;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  local_28 = operator_new(0x6d0);

  local_c = 0x22;

  if (local_28 == (uint32_t /* width from decompiler */ *)0x0) {

    local_24 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_24 = (uint32_t /* width from decompiler */ *)FUN_0054f250();

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x22;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6d0);

  local_c = 0x23;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00618100();

    *puVar1 = &PTR_FUN_009d1914;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x23;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6e0);

  local_c = 0x24;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d196c;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x24;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x25;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d19cc;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x25;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  puVar1 = operator_new(0x6c0);

  local_c = 0x26;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28 = puVar1;

    FUN_00578830();

    *puVar1 = &PTR_FUN_009d1a24;

  }

  local_c = 0xffffffff;

  local_28 = (uint32_t /* width from decompiler */ *)0x26;

  local_24 = puVar1;

  FUN_0054eb20(local_20,&local_28);

  ExceptionList = local_14;

  return;

}
