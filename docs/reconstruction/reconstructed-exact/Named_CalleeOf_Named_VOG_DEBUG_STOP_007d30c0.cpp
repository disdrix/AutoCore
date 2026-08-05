// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007d30c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007d30c0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007d30c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~498 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, do×2, while×2.
//  - Notable callees: block×181, FUN_004231d0×61, FUN_0041a3e0×4, _com_issue_error×3, CONCAT31×2, CoTaskMemAlloc×2, FUN_00423170×2, wcscpy×2.
//  - Strings: "//vPrefixWeapon/row".
//  - Return sites: 5.

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

/* WARNING: Removing unreachable block (ram,0x007d50e6) */

/* WARNING: Removing unreachable block (ram,0x007d4143) */

/* WARNING: Removing unreachable block (ram,0x007d415b) */

/* WARNING: Removing unreachable block (ram,0x007d4170) */

/* WARNING: Removing unreachable block (ram,0x007d4176) */

/* WARNING: Removing unreachable block (ram,0x007d41ae) */

/* WARNING: Removing unreachable block (ram,0x007d41c3) */

/* WARNING: Removing unreachable block (ram,0x007d41c9) */

/* WARNING: Removing unreachable block (ram,0x007d41f3) */

/* WARNING: Removing unreachable block (ram,0x007d4208) */

/* WARNING: Removing unreachable block (ram,0x007d420e) */

/* WARNING: Removing unreachable block (ram,0x007d4238) */

/* WARNING: Removing unreachable block (ram,0x007d424d) */

/* WARNING: Removing unreachable block (ram,0x007d4253) */

/* WARNING: Removing unreachable block (ram,0x007d427d) */

/* WARNING: Removing unreachable block (ram,0x007d4292) */

/* WARNING: Removing unreachable block (ram,0x007d4298) */

/* WARNING: Removing unreachable block (ram,0x007d42c2) */

/* WARNING: Removing unreachable block (ram,0x007d42d7) */

/* WARNING: Removing unreachable block (ram,0x007d42dd) */

/* WARNING: Removing unreachable block (ram,0x007d4307) */

/* WARNING: Removing unreachable block (ram,0x007d431c) */

/* WARNING: Removing unreachable block (ram,0x007d4322) */

/* WARNING: Removing unreachable block (ram,0x007d434c) */

/* WARNING: Removing unreachable block (ram,0x007d4361) */

/* WARNING: Removing unreachable block (ram,0x007d4367) */

/* WARNING: Removing unreachable block (ram,0x007d4391) */

/* WARNING: Removing unreachable block (ram,0x007d43a6) */

/* WARNING: Removing unreachable block (ram,0x007d43ac) */

/* WARNING: Removing unreachable block (ram,0x007d43d6) */

/* WARNING: Removing unreachable block (ram,0x007d43eb) */

/* WARNING: Removing unreachable block (ram,0x007d43f1) */

/* WARNING: Removing unreachable block (ram,0x007d441b) */

/* WARNING: Removing unreachable block (ram,0x007d4430) */

/* WARNING: Removing unreachable block (ram,0x007d4436) */

/* WARNING: Removing unreachable block (ram,0x007d4460) */

/* WARNING: Removing unreachable block (ram,0x007d4475) */

/* WARNING: Removing unreachable block (ram,0x007d447b) */

/* WARNING: Removing unreachable block (ram,0x007d44a5) */

/* WARNING: Removing unreachable block (ram,0x007d44ba) */

/* WARNING: Removing unreachable block (ram,0x007d44c0) */

/* WARNING: Removing unreachable block (ram,0x007d44e9) */

/* WARNING: Removing unreachable block (ram,0x007d44fe) */

/* WARNING: Removing unreachable block (ram,0x007d4504) */

/* WARNING: Removing unreachable block (ram,0x007d452d) */

/* WARNING: Removing unreachable block (ram,0x007d4542) */

/* WARNING: Removing unreachable block (ram,0x007d4548) */

/* WARNING: Removing unreachable block (ram,0x007d4571) */

/* WARNING: Removing unreachable block (ram,0x007d4586) */

/* WARNING: Removing unreachable block (ram,0x007d458c) */

/* WARNING: Removing unreachable block (ram,0x007d45b5) */

/* WARNING: Removing unreachable block (ram,0x007d45ca) */

/* WARNING: Removing unreachable block (ram,0x007d45d0) */

/* WARNING: Removing unreachable block (ram,0x007d45f9) */

/* WARNING: Removing unreachable block (ram,0x007d460e) */

/* WARNING: Removing unreachable block (ram,0x007d4614) */

/* WARNING: Removing unreachable block (ram,0x007d463d) */

/* WARNING: Removing unreachable block (ram,0x007d4652) */

/* WARNING: Removing unreachable block (ram,0x007d4658) */

/* WARNING: Removing unreachable block (ram,0x007d4681) */

/* WARNING: Removing unreachable block (ram,0x007d4696) */

/* WARNING: Removing unreachable block (ram,0x007d469c) */

/* WARNING: Removing unreachable block (ram,0x007d46c5) */

/* WARNING: Removing unreachable block (ram,0x007d46da) */

/* WARNING: Removing unreachable block (ram,0x007d46e0) */

/* WARNING: Removing unreachable block (ram,0x007d4709) */

/* WARNING: Removing unreachable block (ram,0x007d471e) */

/* WARNING: Removing unreachable block (ram,0x007d4724) */

/* WARNING: Removing unreachable block (ram,0x007d474d) */

/* WARNING: Removing unreachable block (ram,0x007d4762) */

/* WARNING: Removing unreachable block (ram,0x007d4768) */

/* WARNING: Removing unreachable block (ram,0x007d4791) */

/* WARNING: Removing unreachable block (ram,0x007d47a6) */

/* WARNING: Removing unreachable block (ram,0x007d47ac) */

/* WARNING: Removing unreachable block (ram,0x007d47d5) */

/* WARNING: Removing unreachable block (ram,0x007d47ea) */

/* WARNING: Removing unreachable block (ram,0x007d47f0) */

/* WARNING: Removing unreachable block (ram,0x007d481a) */

/* WARNING: Removing unreachable block (ram,0x007d482f) */

/* WARNING: Removing unreachable block (ram,0x007d4835) */

/* WARNING: Removing unreachable block (ram,0x007d485f) */

/* WARNING: Removing unreachable block (ram,0x007d4874) */

/* WARNING: Removing unreachable block (ram,0x007d487a) */

/* WARNING: Removing unreachable block (ram,0x007d48a4) */

/* WARNING: Removing unreachable block (ram,0x007d48b9) */

/* WARNING: Removing unreachable block (ram,0x007d48bf) */

/* WARNING: Removing unreachable block (ram,0x007d48e9) */

/* WARNING: Removing unreachable block (ram,0x007d48fe) */

/* WARNING: Removing unreachable block (ram,0x007d4904) */

/* WARNING: Removing unreachable block (ram,0x007d492e) */

/* WARNING: Removing unreachable block (ram,0x007d4943) */

/* WARNING: Removing unreachable block (ram,0x007d4949) */

/* WARNING: Removing unreachable block (ram,0x007d4972) */

/* WARNING: Removing unreachable block (ram,0x007d4987) */

/* WARNING: Removing unreachable block (ram,0x007d498d) */

/* WARNING: Removing unreachable block (ram,0x007d49b6) */

/* WARNING: Removing unreachable block (ram,0x007d49cb) */

/* WARNING: Removing unreachable block (ram,0x007d49d1) */

/* WARNING: Removing unreachable block (ram,0x007d49fa) */

/* WARNING: Removing unreachable block (ram,0x007d4a0f) */

/* WARNING: Removing unreachable block (ram,0x007d4a15) */

/* WARNING: Removing unreachable block (ram,0x007d4a3f) */

/* WARNING: Removing unreachable block (ram,0x007d4a54) */

/* WARNING: Removing unreachable block (ram,0x007d4a5a) */

/* WARNING: Removing unreachable block (ram,0x007d4a84) */

/* WARNING: Removing unreachable block (ram,0x007d4a99) */

/* WARNING: Removing unreachable block (ram,0x007d4a9f) */

/* WARNING: Removing unreachable block (ram,0x007d4ac8) */

/* WARNING: Removing unreachable block (ram,0x007d4add) */

/* WARNING: Removing unreachable block (ram,0x007d4ae3) */

/* WARNING: Removing unreachable block (ram,0x007d4b0d) */

/* WARNING: Removing unreachable block (ram,0x007d4b22) */

/* WARNING: Removing unreachable block (ram,0x007d4b28) */

/* WARNING: Removing unreachable block (ram,0x007d4b4f) */

/* WARNING: Removing unreachable block (ram,0x007d4b64) */

/* WARNING: Removing unreachable block (ram,0x007d4b6a) */

/* WARNING: Removing unreachable block (ram,0x007d4b91) */

/* WARNING: Removing unreachable block (ram,0x007d4ba6) */

/* WARNING: Removing unreachable block (ram,0x007d4bac) */

/* WARNING: Removing unreachable block (ram,0x007d4bd0) */

/* WARNING: Removing unreachable block (ram,0x007d4be5) */

/* WARNING: Removing unreachable block (ram,0x007d4beb) */

/* WARNING: Removing unreachable block (ram,0x007d4c10) */

/* WARNING: Removing unreachable block (ram,0x007d4c25) */

/* WARNING: Removing unreachable block (ram,0x007d4c2b) */

/* WARNING: Removing unreachable block (ram,0x007d4c50) */

/* WARNING: Removing unreachable block (ram,0x007d4c65) */

/* WARNING: Removing unreachable block (ram,0x007d4c6b) */

/* WARNING: Removing unreachable block (ram,0x007d4c93) */

/* WARNING: Removing unreachable block (ram,0x007d4ca8) */

/* WARNING: Removing unreachable block (ram,0x007d4cae) */

/* WARNING: Removing unreachable block (ram,0x007d4cd3) */

/* WARNING: Removing unreachable block (ram,0x007d4ce8) */

/* WARNING: Removing unreachable block (ram,0x007d4cee) */

/* WARNING: Removing unreachable block (ram,0x007d4d16) */

/* WARNING: Removing unreachable block (ram,0x007d4d2b) */

/* WARNING: Removing unreachable block (ram,0x007d4d31) */

/* WARNING: Removing unreachable block (ram,0x007d4d59) */

/* WARNING: Removing unreachable block (ram,0x007d4d6e) */

/* WARNING: Removing unreachable block (ram,0x007d4d74) */

/* WARNING: Removing unreachable block (ram,0x007d4d9c) */

/* WARNING: Removing unreachable block (ram,0x007d4db1) */

/* WARNING: Removing unreachable block (ram,0x007d4db7) */

/* WARNING: Removing unreachable block (ram,0x007d4ddf) */

/* WARNING: Removing unreachable block (ram,0x007d4df4) */

/* WARNING: Removing unreachable block (ram,0x007d4dfa) */

/* WARNING: Removing unreachable block (ram,0x007d4e22) */

/* WARNING: Removing unreachable block (ram,0x007d4e37) */

/* WARNING: Removing unreachable block (ram,0x007d4e3d) */

/* WARNING: Removing unreachable block (ram,0x007d4e65) */

/* WARNING: Removing unreachable block (ram,0x007d4e7a) */

/* WARNING: Removing unreachable block (ram,0x007d4e80) */

/* WARNING: Removing unreachable block (ram,0x007d4ea8) */

/* WARNING: Removing unreachable block (ram,0x007d4ebd) */

/* WARNING: Removing unreachable block (ram,0x007d4ec3) */

/* WARNING: Removing unreachable block (ram,0x007d4eec) */

/* WARNING: Removing unreachable block (ram,0x007d4f01) */

/* WARNING: Removing unreachable block (ram,0x007d4f07) */

/* WARNING: Removing unreachable block (ram,0x007d4f31) */

/* WARNING: Removing unreachable block (ram,0x007d4f46) */

/* WARNING: Removing unreachable block (ram,0x007d4f4c) */

/* WARNING: Removing unreachable block (ram,0x007d4f75) */

/* WARNING: Removing unreachable block (ram,0x007d4f8a) */

/* WARNING: Removing unreachable block (ram,0x007d4f90) */

/* WARNING: Removing unreachable block (ram,0x007d4fb9) */

/* WARNING: Removing unreachable block (ram,0x007d4fce) */

/* WARNING: Removing unreachable block (ram,0x007d4fd4) */

/* WARNING: Removing unreachable block (ram,0x007d4ffd) */

/* WARNING: Removing unreachable block (ram,0x007d5012) */

/* WARNING: Removing unreachable block (ram,0x007d5018) */

/* WARNING: Removing unreachable block (ram,0x007d5041) */

/* WARNING: Removing unreachable block (ram,0x007d5056) */

/* WARNING: Removing unreachable block (ram,0x007d505c) */

/* WARNING: Removing unreachable block (ram,0x007d508c) */

/* WARNING: Removing unreachable block (ram,0x007d50a1) */

/* WARNING: Removing unreachable block (ram,0x007d50a7) */

/* WARNING: Removing unreachable block (ram,0x007d50d1) */

/* WARNING: Removing unreachable block (ram,0x007d50ec) */

/* WARNING: Removing unreachable block (ram,0x007d510b) */

/* WARNING: Removing unreachable block (ram,0x007d5120) */

/* WARNING: Removing unreachable block (ram,0x007d5126) */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007d30c0(char *param_1,int *param_2,int *param_3)



{

  int *piVar1;

  int iVar2;

  LPVOID pvVar3;

  int iVar4;

  IUnknown *This;

  ULONG UVar5;

  int *unaff_EBX;

  int *unaff_retaddr;

  int *piVar6;

  uint32_t /* width from decompiler */ local_1e0;

  uint32_t /* width from decompiler */ local_1dc;

  uint32_t /* width from decompiler */ *local_1d8;

  uint32_t /* width from decompiler */ local_1d4;

  int local_1d0;

  uint32_t /* width from decompiler */ local_1cc;

  uint32_t /* width from decompiler */ *local_1c8;

  uint32_t /* width from decompiler */ local_1c4;

  uint32_t /* width from decompiler */ local_1c0;

  uint32_t /* width from decompiler */ local_1bc;

  int *local_1b8;

  IUnknown *local_1b4;

  uint16_t local_1b0;

  short local_1ac;

  uint16_t local_1a8;

  uint16_t local_1a4;

  uint16_t local_1a0;

  uint16_t local_19c;

  uint16_t local_198;

  uint16_t local_194;

  uint16_t local_190;

  uint16_t local_18c;

  uint16_t local_188;

  uint16_t local_184;

  uint16_t local_180;

  short local_17c;

  short local_178;

  uint16_t local_174;

  uint16_t local_170;

  uint16_t local_16c;

  int local_168;

  uint32_t /* width from decompiler */ local_164;

  uint16_t local_160;

  uint16_t local_15c;

  uint16_t local_158;

  int local_154;

  uint8_t *local_150;

  uint16_t local_14c;

  short local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ local_140;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ local_fc;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  BSTR local_d8;

  BSTR local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  wchar_t local_b8 [34];

  wchar_t local_74 [50];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae9da;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvStack_10;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_1c8 = &local_1e0;

    local_1e0 = 0;

    local_1dc = 0;

    local_1d8 = (uint32_t /* width from decompiler */ *)0x0;

    local_1d4 = 0;

    local_1d0 = 0;

    local_1cc = 0;

    local_1c0 = 0;

    local_1c4 = 0;

    local_1bc = 0;

    local_1b8 = (int *)0x0;

    local_4 = 0;

    iVar2 = FUN_0041a810(local_1c8,param_1 + 0x28,0);

    local_1d8 = &local_144;

    if (((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

        ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

         (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

       ((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

        ((((iVar2 = FUN_004231d0(), iVar2 < 0 ||

           ((((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

               (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

              (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

               ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

                ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

             ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

              ((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

                (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

               ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

            (((((iVar2 = FUN_004231d0(), iVar2 < 0 ||

                ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

               (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

              (((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

                 (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

                (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

                 ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

                  ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0))))))))

               || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

             (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

              (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

          (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (((iVar2 = FUN_004231d0(), iVar2 < 0 ||

             ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

            (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

         ((((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

             (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

            ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

           (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (local_1d0 == 0)))))))))) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar2 = FUN_0041a9b0();

      if (iVar2 == 0) {

        if (local_148 < 1) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0;

        }

        *param_2 = (int)local_148;

        pvVar3 = CoTaskMemAlloc(local_148 * 0x178);

        *param_3 = (int)pvVar3;

        if (pvVar3 == (LPVOID)0x0) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0x8007000e;

        }

        iVar2 = 0;

        do {

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x120 + iVar2) = local_138;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x124 + iVar2) = local_cc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x128 + iVar2) = local_c4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 300 + iVar2) = local_140;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x130 + iVar2) = local_bc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x134 + iVar2) = local_130;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x138 + iVar2) = local_f0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x13c + iVar2) = local_128;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x140 + iVar2) = local_d0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x144 + iVar2) = local_120;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x148 + iVar2) = local_e8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x14c + iVar2) = local_118;

          *(uint16_t *)(*param_3 + 0x150 + iVar2) = local_180;

          *(uint16_t *)(*param_3 + 0x152 + iVar2) = local_174;

          *(uint16_t *)(*param_3 + 0x154 + iVar2) = local_16c;

          *(uint16_t *)(*param_3 + 0x156 + iVar2) = local_14c;

          *(uint16_t *)(*param_3 + 0x158 + iVar2) = local_1a8;

          *(uint16_t *)(*param_3 + 0x15a + iVar2) = local_15c;

          *(uint16_t *)(*param_3 + 0x15c + iVar2) = local_1a0;

          *(uint16_t *)(*param_3 + 0x15e + iVar2) = local_170;

          *(uint16_t *)(*param_3 + 0x160 + iVar2) = local_198;

          *(uint16_t *)(*param_3 + 0x162 + iVar2) = local_158;

          *(uint16_t *)(*param_3 + 0x164 + iVar2) = local_190;

          *(uint16_t *)(*param_3 + 0x166 + iVar2) = (uint16_t)local_168;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x11c + iVar2) = local_c0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x108 + iVar2) = local_110;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x114 + iVar2) = local_e0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10c + iVar2) = local_108;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x110 + iVar2) = local_c8;

          *(uint16_t *)(*param_3 + 0x118 + iVar2) = local_188;

          *(uint16_t *)(*param_3 + 0x11a + iVar2) = (uint16_t)local_154;

          *(uint16_t *)(*param_3 + 0x168 + iVar2) = local_1b0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x16c + iVar2) = local_100;

          *(BSTR *)(*param_3 + 0x170 + iVar2) = local_d8;

          *(uint16_t *)(*param_3 + 0x174 + iVar2) = local_160;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x84 + iVar2) = local_f8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10 + iVar2) = local_13c;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 8 + iVar2) = local_134;

          *(uint32_t /* width from decompiler */ *)(iVar2 + *param_3) = local_144;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x14 + iVar2) = local_12c;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x18 + iVar2) = local_124;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x88 + iVar2) = local_11c;

          *(uint *)(*param_3 + 0xc + iVar2) = (uint)(local_178 == -1);

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x8c + iVar2) = local_114;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x90 + iVar2) = local_10c;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x94 + iVar2) = local_104;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x98 + iVar2) = local_fc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x9c + iVar2) = local_f4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xa0 + iVar2) = local_ec;

          *(uint *)(*param_3 + 0xa4 + iVar2) = (uint)(local_1ac == -1);

          *(uint16_t *)(*param_3 + 0xa8 + iVar2) = local_1a4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xac + iVar2) = local_e4;

          *(uint16_t *)(*param_3 + 0xb0 + iVar2) = local_19c;

          *(uint16_t *)(*param_3 + 0xb2 + iVar2) = local_194;

          *(uint16_t *)(*param_3 + 0xb4 + iVar2) = local_18c;

          *(uint16_t *)(*param_3 + 0xb6 + iVar2) = local_184;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xbc + iVar2) = local_dc;

          wcscpy((wchar_t *)(*param_3 + 0x1c + iVar2),local_74);

          wcscpy((wchar_t *)(*param_3 + 0xc4 + iVar2),local_b8);

          iVar2 = iVar2 + 0x178;

          *(uint *)(*param_3 + -0xb8 + iVar2) = (uint)(local_17c == -1);

          iVar4 = FUN_0041c000();

        } while (iVar4 == 0);

      }

      if (local_1d0 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    local_d4 = SysAllocString(L"//vPrefixWeapon/row");

    if (local_d4 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_150 = &stack0xfffffe04;

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    This = local_1b4;

    if (local_1b4 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

      This = local_1b4;

    }

    local_164 = 0;

    UVar5 = (*This->lpVtbl[2].Release)(This);

    if ((int)UVar5 < 0) {

      _com_issue_errorex(UVar5,This,(_GUID *)&DAT_00a86118);

    }

    iVar2 = local_168;

    *unaff_retaddr = local_168;

    pvVar3 = CoTaskMemAlloc(local_168 * 0x178);

    *param_3 = (int)pvVar3;

    local_154 = 0;

    piVar6 = unaff_EBX;

    if (0 < iVar2) {

      do {

        iVar2 = local_154;

        if (local_1b8 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar1 = local_1b8;

        if (piVar6 != (int *)0x0) {

          (**(code **)(*piVar6 + 8))();

        }

        piVar6 = (int *)0x0;

        (**(code **)(*piVar1 + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_154 = iVar2 + 1;

      } while (local_154 < local_168);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

    if (local_1b8 != (int *)0x0) {

      (**(code **)(*local_1b8 + 8))();

    }

    SysFreeString(local_d8);

  }

  ExceptionList = pvStack_10;

  return 0;

}
