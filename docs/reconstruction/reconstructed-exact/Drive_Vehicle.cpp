// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×15, return×2, for×1.
//  - Notable callees: _wcsicmp×6, FUN_00799300×5, FUN_007996d0×4, FUN_00798bb0×2, FUN_00403450, FUN_0049fcd0, FUN_005b8370, FUN_00799460.
//  - Strings: "filename"; "mass"; "collisionFilter"; "initialVelocity".
//  - Return sites: 2.

// =============================================================================
// Drive_Vehicle
// -----------------------------------------------------------------------------
// Stable ID: aa_0049fcd0
// Address:   0x0049fcd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Vehicle"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Drive_Vehicle(int param_1,int *param_2,char param_3)



{

  char cVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  char cStack_299;

  uint32_t /* width from decompiler */ local_298;

  char *pcStack_294;

  char acStack_290 [128];

  wchar_t awStack_210 [2];

  uint32_t /* width from decompiler */ auStack_20c [130];

  

  iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_298);

  if ((-1 < iVar3) && (unaff_EBX != (int *)0x0)) {

    awStack_210[0] = L'\0';

    awStack_210[1] = L'\0';

    puVar5 = auStack_20c;

    for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    if (param_3 == '\0') {

      *(byte *)(param_1 + 0x90d) = *(byte *)(param_1 + 0x90d) | 1;

    }

    else {

      *(byte *)(param_1 + 0x90c) = *(byte *)(param_1 + 0x90c) | 0x80;

    }

    *(uint8_t *)(param_1 + 0x911) = 0;

    FUN_00798bb0(unaff_EBX,L"filename",awStack_210);

    pcStack_294 = acStack_290;

    uVar4 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(awStack_210,uVar4);

    strncpy((char *)(param_1 + 0x2be),pcStack_294,0x7e);

    if (pcStack_294 != acStack_290) {

      free(pcStack_294);

    }

    FUN_00799300(unaff_EBX,L"mass",param_1 + 0x284);

    FUN_00799460(unaff_EBX,L"collisionFilter",param_1 + 0x900,10);

    cVar1 = FUN_007995a0(unaff_EBX,&local_298,L"initialVelocity",param_1 + 0x28c,param_1 + 0x298,

                         &cStack_299,0);

    FUN_005b8370(local_298,0xc,param_1 + 0x28c,param_1);

    *(byte *)(param_1 + 0x90c) =

         *(byte *)(param_1 + 0x90c) ^ (cStack_299 * '\b' ^ *(byte *)(param_1 + 0x90c)) & 8;

    if (cVar1 != '\0') {

      *(byte *)(param_1 + 0x90c) = *(byte *)(param_1 + 0x90c) | 0x20;

    }

    cVar1 = FUN_007994c0(unaff_EBX,L"initialRotation",param_1 + 0x2a4,param_1 + 0x2b0,&cStack_299,0)

    ;

    *(byte *)(param_1 + 0x90c) =

         *(byte *)(param_1 + 0x90c) ^ (cStack_299 * '\x04' ^ *(byte *)(param_1 + 0x90c)) & 4;

    if (cVar1 != '\0') {

      *(byte *)(param_1 + 0x90c) = *(byte *)(param_1 + 0x90c) | 0x40;

    }

    FUN_007996d0(unaff_EBX,L"relativeCoords",&stack0xfffffd5f);

    *(byte *)(param_1 + 0x90c) =

         *(byte *)(param_1 + 0x90c) ^ (cVar1 << 4 ^ *(byte *)(param_1 + 0x90c)) & 0x10;

    cVar2 = FUN_007996d0(unaff_EBX,L"useParentInitialVelocity",&stack0xfffffd5f);

    if (cVar2 != '\0') {

      *(byte *)(param_1 + 0x910) =

           *(byte *)(param_1 + 0x910) ^ (cVar1 * '\x02' ^ *(byte *)(param_1 + 0x910)) & 2;

    }

    cVar2 = FUN_007996d0(unaff_EBX,L"useParentInitialRotation",&stack0xfffffd5f);

    if (cVar2 != '\0') {

      *(byte *)(param_1 + 0x910) =

           *(byte *)(param_1 + 0x910) ^ (cVar1 * '\x04' ^ *(byte *)(param_1 + 0x910)) & 4;

    }

    *(uint8_t *)(param_1 + 0x30) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    cVar1 = FUN_00798bb0(unaff_EBX,L"materialType",awStack_210);

    if (cVar1 != '\0') {

      iVar3 = _wcsicmp(L"Metal",awStack_210);

      if (iVar3 == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 1;

      }

      else {

        iVar3 = _wcsicmp(L"Wood",awStack_210);

        if (iVar3 == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 2;

        }

        else {

          iVar3 = _wcsicmp(L"Glass",awStack_210);

          if (iVar3 == 0) {

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 3;

          }

          else {

            iVar3 = _wcsicmp(L"Stone",awStack_210);

            if (iVar3 == 0) {

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 4;

            }

            else {

              iVar3 = _wcsicmp(L"Vehicle",awStack_210);

              if (iVar3 == 0) {

                *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 5;

              }

              else {

                iVar3 = _wcsicmp(L"Flesh",awStack_210);

                if (iVar3 == 0) {

                  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 6;

                }

              }

            }

          }

        }

      }

    }

    FUN_00799820(unaff_EBX,L"materialSize",(uint8_t *)(param_1 + 0x30),10);

    cVar1 = FUN_00799300(unaff_EBX,L"constraintLength",param_1 + 0xa8);

    *(byte *)(param_1 + 0x90d) =

         *(byte *)(param_1 + 0x90d) ^ (cVar1 << 4 ^ *(byte *)(param_1 + 0x90d)) & 0x10;

    cVar1 = FUN_00799300(unaff_EBX,L"constraintBreak",(uint32_t /* width from decompiler */ *)(param_1 + 0xac));

    if (cVar1 == '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = DAT_009c7c30;

    }

    FUN_007996d0(unaff_EBX,L"noCollide",param_1 + 0xb0);

    FUN_00799300(unaff_EBX,L"scaleX",param_1 + 0xb4);

    FUN_00799300(unaff_EBX,L"scaleY",param_1 + 0xb8);

    (**(code **)(*unaff_EBX + 8))(unaff_EBX);

    return 1;

  }

  return 0;

}
