// =============================================================================
// FUN_00914dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00914dc0
// Address:   0x00914dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914dc0 @ 0x00914dc0
// Stable ID: aa_00914dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~281 non-empty decompiler lines.
//  - Control keywords: if×74, goto×1, return×1.
//  - Notable callees: ABS×21, FUN_00914dc0.
//  - Return sites: 1.

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

void FUN_00914dc0(void)



{

  float fVar1;

  bool bVar2;

  float fVar3;

  bool bVar4;

  bool bVar5;

  

  fVar1 = *(float *)(DAT_00d09874 + 0x30);

  bVar2 = false;

  bVar4 = false;

  bVar5 = false;

  if (DAT_00d1d556 != '\0') {

    if (DAT_00d1b207 == '\0') {

      DAT_00d1b278 = DAT_00d1b290;

      bVar2 = true;

    }

    else if (DAT_00d1b290 < ABS(DAT_00d1b278)) {

      bVar2 = true;

    }

    else {

      DAT_00d1b278 = DAT_00d1b284 * fVar1 + DAT_00d1b278;

      bVar2 = true;

    }

  }

  if (DAT_00d1d58a == '\0') {

    if ((!bVar2) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar3 = DAT_00d1b284 * fVar1, ABS(DAT_00d1b278) <= fVar3)) {

        DAT_00d1b278 = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b278) {

          DAT_00d1b278 = DAT_00d1b278 - fVar3;

        }

        if (DAT_00d1b278 < 0.0) {

          DAT_00d1b278 = fVar3 + DAT_00d1b278;

        }

      }

    }

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b278 = 0.0 - DAT_00d1b290;

  }

  else if (ABS(DAT_00d1b278) <= DAT_00d1b290) {

    DAT_00d1b278 = DAT_00d1b278 - DAT_00d1b284 * fVar1;

  }

  if (DAT_00d1d486 != '\0') {

    if (DAT_00d1b207 == '\0') {

      DAT_00d1b270 = DAT_00d1b288;

      bVar4 = true;

    }

    else if (DAT_00d1b288 < ABS(DAT_00d1b270)) {

      bVar4 = true;

    }

    else {

      DAT_00d1b270 = DAT_00d1b27c * fVar1 + DAT_00d1b270;

      bVar4 = true;

    }

  }

  if (DAT_00d1d4ba == '\0') {

    if ((!bVar4) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar3 = DAT_00d1b27c * fVar1, ABS(DAT_00d1b270) <= fVar3)) {

        DAT_00d1b270 = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b270) {

          DAT_00d1b270 = DAT_00d1b270 - fVar3;

        }

        if (DAT_00d1b270 < 0.0) {

          DAT_00d1b270 = fVar3 + DAT_00d1b270;

        }

      }

    }

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b270 = 0.0 - DAT_00d1b288;

  }

  else if (ABS(DAT_00d1b270) <= DAT_00d1b288) {

    DAT_00d1b270 = DAT_00d1b270 - DAT_00d1b27c * fVar1;

  }

  if (DAT_00d1d4ee != '\0') {

    if (DAT_00d1b207 == '\0') {

      DAT_00d1b274 = DAT_00d1b28c;

      bVar5 = true;

    }

    else if (DAT_00d1b28c < ABS(DAT_00d1b274)) {

      bVar5 = true;

    }

    else {

      DAT_00d1b274 = DAT_00d1b280 * fVar1 + DAT_00d1b274;

      bVar5 = true;

    }

  }

  if (DAT_00d1d522 == '\0') {

    if ((!bVar5) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar3 = DAT_00d1b280 * fVar1, ABS(DAT_00d1b274) <= fVar3)) {

        DAT_00d1b274 = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b274) {

          DAT_00d1b274 = DAT_00d1b274 - fVar3;

        }

        if (DAT_00d1b274 < 0.0) {

          DAT_00d1b274 = fVar3 + DAT_00d1b274;

        }

      }

    }

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b274 = 0.0 - DAT_00d1b28c;

  }

  else if (ABS(DAT_00d1b274) <= DAT_00d1b28c) {

    DAT_00d1b274 = DAT_00d1b274 - DAT_00d1b280 * fVar1;

  }

  if (DAT_00d1d68e == '\0') {

    bVar2 = false;

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b29c = DAT_00d1b2b4;

    bVar2 = true;

  }

  else if (DAT_00d1b2b4 < ABS(DAT_00d1b29c)) {

    bVar2 = true;

  }

  else {

    DAT_00d1b29c = DAT_00d1b2a8 * fVar1 + DAT_00d1b29c;

    bVar2 = true;

  }

  if (DAT_00d1d6c2 == '\0') {

    if ((!bVar2) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar3 = DAT_00d1b2a8 * fVar1, ABS(DAT_00d1b29c) <= fVar3)) {

        DAT_00d1b29c = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b29c) {

          DAT_00d1b29c = DAT_00d1b29c - fVar3;

        }

        if (DAT_00d1b29c < 0.0) {

          DAT_00d1b29c = fVar3 + DAT_00d1b29c;

        }

      }

    }

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b29c = 0.0 - DAT_00d1b2b4;

  }

  else if (ABS(DAT_00d1b29c) <= DAT_00d1b2b4) {

    DAT_00d1b29c = DAT_00d1b29c - DAT_00d1b2a8 * fVar1;

  }

  if (DAT_00d1d5be == '\0') {

    bVar2 = false;

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b294 = DAT_00d1b2ac;

    bVar2 = true;

  }

  else if (DAT_00d1b2ac < ABS(DAT_00d1b294)) {

    bVar2 = true;

  }

  else {

    DAT_00d1b294 = DAT_00d1b2a0 * fVar1 + DAT_00d1b294;

    bVar2 = true;

  }

  if (DAT_00d1d5f2 == '\0') {

    if ((!bVar2) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar3 = DAT_00d1b2a0 * fVar1, ABS(DAT_00d1b294) <= fVar3)) {

        DAT_00d1b294 = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b294) {

          DAT_00d1b294 = DAT_00d1b294 - fVar3;

        }

        if (DAT_00d1b294 < 0.0) {

          DAT_00d1b294 = fVar3 + DAT_00d1b294;

        }

      }

    }

  }

  else {

    if (DAT_00d1b207 == '\0') {

      DAT_00d1b294 = 0.0 - DAT_00d1b2ac;

    }

    else if (ABS(DAT_00d1b294) <= DAT_00d1b2ac) {

      DAT_00d1b294 = DAT_00d1b294 - DAT_00d1b2a0 * fVar1;

      bVar2 = true;

      goto LAB_00915384;

    }

    bVar2 = true;

  }

LAB_00915384:

  if (DAT_00d1d626 != '\0') {

    if (DAT_00d1b207 == '\0') {

      DAT_00d1b298 = DAT_00d1b2b0;

      bVar2 = true;

    }

    else if (DAT_00d1b2b0 < ABS(DAT_00d1b298)) {

      bVar2 = true;

    }

    else {

      DAT_00d1b298 = DAT_00d1b2a4 * fVar1 + DAT_00d1b298;

      bVar2 = true;

    }

  }

  if (DAT_00d1d65a == '\0') {

    if ((!bVar2) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar3 = DAT_00d1b2a4 * fVar1, ABS(DAT_00d1b298) <= fVar3)) {

        DAT_00d1b298 = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b298) {

          DAT_00d1b298 = DAT_00d1b298 - fVar3;

        }

        if (DAT_00d1b298 < 0.0) {

          DAT_00d1b298 = fVar3 + DAT_00d1b298;

        }

      }

    }

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b298 = 0.0 - DAT_00d1b2b0;

  }

  else if (ABS(DAT_00d1b298) <= DAT_00d1b2b0) {

    DAT_00d1b298 = DAT_00d1b298 - DAT_00d1b2a4 * fVar1;

  }

  if (DAT_00d1d7fa == '\0') {

    bVar2 = false;

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b2c4 = DAT_00d1b2cc;

    bVar2 = true;

  }

  else if (DAT_00d1b2cc < ABS(DAT_00d1b2c4)) {

    bVar2 = true;

  }

  else {

    DAT_00d1b2c4 = DAT_00d1b2c8 * fVar1 + DAT_00d1b2c4;

    bVar2 = true;

  }

  if (DAT_00d1d82e == '\0') {

    if ((!bVar2) && (DAT_00d1b208 != '\0')) {

      if ((DAT_00d1b207 == '\0') || (fVar1 = DAT_00d1b2c8 * fVar1, ABS(DAT_00d1b2c4) <= fVar1)) {

        DAT_00d1b2c4 = 0.0;

      }

      else {

        if (0.0 < DAT_00d1b2c4) {

          DAT_00d1b2c4 = DAT_00d1b2c4 - fVar1;

        }

        if (DAT_00d1b2c4 < 0.0) {

          DAT_00d1b2c4 = fVar1 + DAT_00d1b2c4;

        }

      }

    }

  }

  else if (DAT_00d1b207 == '\0') {

    DAT_00d1b2c4 = 0.0 - DAT_00d1b2cc;

  }

  else if (ABS(DAT_00d1b2c4) <= DAT_00d1b2cc) {

    DAT_00d1b2c4 = DAT_00d1b2c4 - DAT_00d1b2c8 * fVar1;

  }

  if ((DAT_00d1d6f6 != '\0') && (DAT_00d1d6f7 != '\0')) {

    DAT_00d1b207 = DAT_00d1b207 == '\0';

    DAT_00d1d6f7 = '\0';

  }

  if ((DAT_00d1d72a != '\0') && (DAT_00d1d72b != '\0')) {

    DAT_00d1b208 = DAT_00d1b208 == '\0';

    DAT_00d1d72b = '\0';

  }

  if ((DAT_00d1d7c6 != '\0') && (DAT_00d1d7c7 != '\0')) {

    DAT_00d1b209 = DAT_00d1b209 == '\0';

    DAT_00d1d7c7 = '\0';

  }

  if ((DAT_00d1d75e != '\0') && (DAT_00d1d75f != '\0')) {

    DAT_00d1b270 = 0.0;

    DAT_00d1b274 = 0.0;

    DAT_00d1b278 = 0.0;

    DAT_00d1b294 = 0.0;

    DAT_00d1b298 = 0.0;

    DAT_00d1b29c = 0.0;

    DAT_00d1d75f = '\0';

  }

  return;

}
