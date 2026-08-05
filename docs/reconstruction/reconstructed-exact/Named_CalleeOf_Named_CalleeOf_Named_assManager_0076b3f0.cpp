// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assManager_0076b3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b3f0
// Callee of Named_CalleeOf_Named_assManager
// Address:   0x0076b3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×2.
//  - Notable callees: FUN_004301f0, FUN_0076adc0, FUN_0076b3f0, FindClose, FindFirstFileA, FindNextFileA.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assManager
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

void Named_CalleeOf_Named_CalleeOf_Named_assManager_0076b3f0(char *param_1)



{

  char cVar1;

  LPCSTR ****pppppCVar2;

  HANDLE hFindFile;

  uint32_t /* width from decompiler */ uVar3;

  BOOL BVar4;

  int iVar5;

  CHAR *pCVar6;

  char *pcVar7;

  bool bVar8;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_184 [4];

  LPCSTR ***local_180 [5];

  uint local_16c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_168 [28];

  _WIN32_FIND_DATAA local_14c;

  void *local_c;

  uint8_t *puStack_8;

  HANDLE local_4;

  

  local_4 = (HANDLE)0xffffffff;

  puStack_8 = &LAB_009acd96;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_184,param_1);

  local_4 = (HANDLE)0x0;

  pppppCVar2 = (LPCSTR ****)local_180[0];

  if (local_16c < 0x10) {

    pppppCVar2 = local_180;

  }

  cVar1 = FUN_0076adc0(pppppCVar2);

  if (cVar1 != '\0') {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

              (local_184,"/*");

  }

  if (local_16c < 0x10) {

    local_180[0] = (LPCSTR ***)local_180;

  }

  hFindFile = FindFirstFileA((LPCSTR)local_180[0],&local_14c);

  if (hFindFile == (HANDLE)0xffffffff) {

    local_4 = hFindFile;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_184);

    ExceptionList = local_c;

    return;

  }

  do {

    iVar5 = 2;

    bVar8 = true;

    pCVar6 = local_14c.cFileName;

    pcVar7 = ".";

    do {

      if (iVar5 == 0) break;

      iVar5 = iVar5 + -1;

      bVar8 = *pCVar6 == *pcVar7;

      pCVar6 = pCVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (!bVar8) {

      iVar5 = 3;

      bVar8 = true;

      pCVar6 = local_14c.cFileName;

      pcVar7 = "..";

      do {

        if (iVar5 == 0) break;

        iVar5 = iVar5 + -1;

        bVar8 = *pCVar6 == *pcVar7;

        pCVar6 = pCVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (!bVar8) {

        uVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          (local_168,local_14c.cFileName);

        local_4._0_1_ = 1;

        FUN_004301f0(uVar3);

        local_4 = (HANDLE)((uint)local_4._1_3_ << 8);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_168);

      }

    }

    BVar4 = FindNextFileA(hFindFile,&local_14c);

    if (BVar4 == 0) {

      FindClose(hFindFile);

      local_4 = (HANDLE)0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_184);

      ExceptionList = local_c;

      return;

    }

  } while( true );

}
