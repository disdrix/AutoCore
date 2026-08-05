// =============================================================================
// FUN_0093a5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093a5c0
// Address:   0x0093a5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093a5c0 @ 0x0093a5c0
// Stable ID: aa_0093a5c0
// Embedded strings (evidence for future rename):
//   - "Saving Screenshot..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×15, return×5.
//  - Notable callees: VehicleEntity_PushDriveAxesToController×2, FUN_004f3700, FUN_00796240, FUN_00796d40, FUN_007a13e0, FUN_007a69d0, FUN_007a6de0, FUN_007fca10.
//  - Strings: "Saving Screenshot...".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int FUN_0093a5c0(char param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  HWND pHVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  

  iVar5 = 0;

  pHVar3 = GetForegroundWindow();

  if (pHVar3 != *(HWND *)(in_EAX + 0x3188)) {

    if ((*(int *)(in_EAX + 0xe98) != 0) &&

       (iVar5 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x250), iVar5 != 0)) {

      if (*(char *)(in_EAX + 0x9c1) == '\0') {

        VehicleEntity_SetHandbrake(1);

        FUN_004f3700();

      }

      if (*(char *)(iVar5 + 0x101) == '\0') {

        VehicleEntity_PushDriveAxesToController();

      }

    }

    return 0;

  }

  FUN_007a69d0();

  if (param_1 == '\0') {

    iVar5 = in_EAX;

    FUN_00796d40();

    iVar5 = FUN_00796240(iVar5);

    if (iVar5 < 0) {

      return iVar5;

    }

  }

  if ((*(int *)(in_EAX + 0x111c) != 0) &&

     (cVar2 = (**(code **)(**(int **)(in_EAX + 0x111c) + 0x3d8))(), cVar2 != '\0')) {

    return iVar5;

  }

  if ((((*(char *)(in_EAX + 0x11de) != '\0') && (*(char *)(in_EAX + 0x11df) != '\0')) &&

      (*(uint8_t *)(in_EAX + 0x11df) = 0, *(int *)(in_EAX + 0xde8) != 0)) &&

     ((cVar2 = FUN_007a13e0(), cVar2 != '\0' &&

      (uVar4 = FUN_007a6de0("Saving Screenshot...",0xffffffff), DAT_00d1b8dc != 0)))) {

    FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar4,0);

  }

  cVar2 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x3d8))();

  if (cVar2 != '\0') {

    cVar2 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x1cc))();

    if (cVar2 == '\0') {

      if ((*(int *)(in_EAX + 0x302c) <= *(int *)(in_EAX + 0x1ac)) ||

         (*(int *)(in_EAX + 0x3198) - *(int *)(in_EAX + 0x1ac) <= *(int *)(in_EAX + 0x302c))) {

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x450))

                  (*(uint32_t /* width from decompiler */ *)(in_EAX + 0x303c));

      }

      if ((*(int *)(in_EAX + 0x3030) <= *(int *)(in_EAX + 0x1ac)) ||

         (*(int *)(in_EAX + 0x319c) - *(int *)(in_EAX + 0x1ac) <= *(int *)(in_EAX + 0x3030))) {

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x454))

                  (*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3040));

      }

      if ((((*(char *)(in_EAX + 0x11aa) != '\0') && (*(char *)(in_EAX + 0x11ab) != '\0')) &&

          (*(uint8_t *)(in_EAX + 0x11ab) = 0, *(int *)(in_EAX + 0x1138) != 0)) &&

         (cVar2 = (**(code **)(**(int **)(in_EAX + 0x1138) + 0x3d8))(), cVar2 == '\0')) {

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x338))(8,0x4e2a);

      }

      iVar5 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x448))();

      return iVar5;

    }

    cVar2 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x1cc))();

    if (((cVar2 == '\0') &&

        (cVar2 = (**(code **)(**(int **)(in_EAX + 0x1080) + 0x3d8))(), cVar2 != '\0')) &&

       ((DAT_00d1c272 != '\0' && (DAT_00d1c273 != '\0')))) {

      DAT_00d1c273 = '\0';

      FUN_007fca10();

    }

    if (((*(int *)(in_EAX + 0xe98) != 0) &&

        (iVar1 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x250), iVar1 != 0)) &&

       (*(char *)(iVar1 + 0x101) == '\0')) {

      VehicleEntity_PushDriveAxesToController();

    }

  }

  return iVar5;

}
