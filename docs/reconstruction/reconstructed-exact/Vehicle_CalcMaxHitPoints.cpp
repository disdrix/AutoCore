// =============================================================================
// Vehicle_CalcMaxHitPoints
// -----------------------------------------------------------------------------
// Stable ID: aa_005002d0
// Address:   0x005002d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Vehicle_CalcMaxHitPoints — player vehicle max HP formula.
   
   Parameters:
     pVehicle (ECX/fastcall): vehicle object
   Returns: int max hit points (ceil).
   
   Algorithm (player-owned, vfunc+0x1dc owner present):
     race=chassis+0x531; class=chassis+0x532; level=owner vfunc+0x27c
     raceTerm = level * g_flVehicleHpRaceMult[race] + g_flVehicleHpBase (60)
     tech = Character_GetTechForPoolCalcs(owner)
     basePool = tech * g_flVehicleHpTechCoeff (~3) + g_flVehicleHpClassMult[class] * raceTerm
     armorFactor from equipped armor@vehicle+0x254 field +0xb4
     chassisArmorAdd = *(short*)(vehicle+0x1d8)  // INFERRED
     return ceil(armor + basePool*(1+hpPct@+0xe4) + hpFlat@+0xe8 + chassisArmorAdd)
   
   Fallback: NPC clone path vfunc+0x1d8; else vfunc+0x244.
   AutoCore: VehicleHitPointCalculator.CalculatePlayerMaxHp */

int __fastcall Vehicle_CalcMaxHitPoints(void *pVehicle)

{
  void *pOwnerChar;
  int nLevelOrScratch;
  int nTmp;
  float flLevelTerm;
  float flBasePool;
  double dVar1;
  float flArmorFactor;
  byte bRace;
  int *pOwnerIface;
  
  pOwnerIface = *(int **)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 0xb0 + (int)pVehicle);
  if (pOwnerIface != (int *)0x0) {
    pOwnerChar = (void *)(**(code **)(*pOwnerIface + 0x1dc))();
    if (pOwnerChar != (void *)0x0) {
      nLevelOrScratch = *(int *)(*(int *)((int)pOwnerChar + 4) + 4);
      bRace = *(byte *)(*(int *)(*(int *)(nLevelOrScratch + 0xac + (int)pOwnerChar) + 0x3c) + 0x531)
      ;
      nLevelOrScratch = (**(code **)(*(int *)((int)pOwnerChar + nLevelOrScratch + 4) + 0x27c))();
                    /* Player path: raceTerm = level * RaceMult[race] + 60 */
      flLevelTerm = (float)nLevelOrScratch * g_flVehicleHpRaceMult[bRace] + g_flVehicleHpBase;
                    /* basePool = tech*TechCoeff + ClassMult[class]*raceTerm */
      flBasePool = g_flVehicleHpClassMult
                   [*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pOwnerChar + 4) + 4) + 0xac +
                                               (int)pOwnerChar) + 0x3c) + 0x532)];
      nLevelOrScratch = Character_GetTechForPoolCalcs(pOwnerChar);
                    /* Add ArmorFactor from equipped armor (+0x254)->+0xb4 */
      flBasePool = (float)(int)(short)nLevelOrScratch * g_flVehicleHpTechCoeff +
                   flBasePool * flLevelTerm;
      flArmorFactor = 0.0;
      if (*(int *)((int)pVehicle + 0x254) != 0) {
        flArmorFactor = (float)(int)*(short *)(*(int *)((int)pVehicle + 0x254) + 0xb4);
                    /* ceil(armor + base + base*hpPct + hpFlat + chassisArmorAdd) */
      }
      nLevelOrScratch = *(int *)(*(int *)((int)pVehicle + 4) + 4);
      dVar1 = ceil((double)((float)(int)flArmorFactor + flBasePool +
                            flBasePool * *(float *)(nLevelOrScratch + 0xe4 + (int)pVehicle) +
                            (float)*(int *)((int)pVehicle + nLevelOrScratch + 0xe8) +
                           (float)(int)*(short *)((int)pVehicle + 0x1d8)));
      return (int)ROUND(dVar1);
    }
  }
  pOwnerIface = *(int **)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 0xb0 + (int)pVehicle);
  if (pOwnerIface != (int *)0x0) {
    nLevelOrScratch = (**(code **)(*pOwnerIface + 0x1d8))();
    if (nLevelOrScratch != 0) {
      nTmp = FUN_0040b330();
      nLevelOrScratch = *(int *)(*(int *)((int)pVehicle + 4) + 4);
      flArmorFactor =
           *(float *)(nLevelOrScratch + 0xe4 + (int)pVehicle) * (float)*(int *)(nTmp + 0x17c) +
           (float)*(int *)(nTmp + 0x17c) + (float)*(int *)((int)pVehicle + nLevelOrScratch + 0xe8);
      if (*(int *)((int)pVehicle + 0x254) != 0) {
        flArmorFactor =
             (float)(int)*(short *)(*(int *)((int)pVehicle + 0x254) + 0xb4) + flArmorFactor;
      }
      dVar1 = ceil((double)flArmorFactor);
      return (int)ROUND(dVar1);
    }
  }
  nLevelOrScratch =
       (**(code **)(*(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 4 + (int)pVehicle) + 0x244)
       )();
  return nLevelOrScratch;
}
