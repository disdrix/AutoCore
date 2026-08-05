// READABILITY (auto CF):
//  - Body size: ~166 non-empty decompiler lines.
//  - Control keywords: if×23, while×4, do×3, return×3, goto×1.
//  - Notable callees: BitStream_readBits×6, FUN_00783aa0×4, FUN_00783b60×3, BitStream_readInt, FUN_00424ee0, FUN_00425ac0, FUN_00426290, FUN_004263a0.
//  - Strings: "LogNetConnection"; "Packet failed crypto"; "LogConnectionProtocol"; "Not recv %d".
//  - Return sites: 3.

// =============================================================================
// Named_Packet_failed_crypto_00425ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00425ac0
// Address:   0x00425ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Packet failed crypto"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint Named_Packet_failed_crypto_00425ac0(uint param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  bool bVar9;

  float fVar10;

  uint local_14;

  uint local_10;

  uint local_c;

  uint auStack_8 [2];

  

  iVar1 = param_1;

  param_1 = 0;

  BitStream_readBits(2,&param_1);

  param_1 = param_1 & 3;

  local_10 = 0;

  BitStream_readBits(5,&local_10);

  uVar6 = local_10 & 0x1f;

  if (*(uint *)(in_EAX + 0x2c) < *(uint *)(in_EAX + 0x18)) {

    *(uint8_t *)(in_EAX + 0x1c) = 1;

  }

  else {

    *(uint *)(in_EAX + 0x18) = *(uint *)(in_EAX + 0x18) + 1;

  }

  local_14 = 0;

  BitStream_readBits(6,&local_14);

  local_10 = 0;

  BitStream_readBits(10,&local_10);

  uVar7 = local_10 & 0x3ff;

  local_10 = 0;

  BitStream_readBits(0,&local_10);

  local_c = *(uint *)(iVar1 + 0x8c);

  local_14 = uVar6 | (local_14 & 0x3f) << 5 | local_c & 0xfffff800;

  if (local_14 < local_c) {

    local_14 = local_14 + 0x800;

  }

  if (local_14 - local_c < 0x20) {

    local_c = *(uint *)(iVar1 + 0x90);

    uVar7 = uVar7 | local_c & 0xfffffc00;

    if (uVar7 < local_c) {

      uVar7 = uVar7 + 0x400;

    }

    if (uVar7 <= *(uint *)(iVar1 + 0x94)) {

      if (*(int *)(iVar1 + 0x1b4) != 0) {

        FUN_00783850(local_14,uVar7,param_1,0);

        cVar2 = FUN_0042bd10(in_EAX,5,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1b4));

        if (cVar2 == '\0') {

          if ((_DAT_00d20c18 & 1) == 0) {

            _DAT_00d20c18 = _DAT_00d20c18 | 1;

            DAT_00d20c14 = FUN_00783b60("LogNetConnection");

          }

          local_c = DAT_00d20c14;

          if (*(char *)(DAT_00d20c14 + 4) != '\0') {

            DAT_00d179a0 = DAT_00d20c14;

            local_c = FUN_00783aa0(&DAT_00a2c2a4,"Packet failed crypto");

            DAT_00d179a0 = 0;

          }

          goto LAB_00425c4c;

        }

      }

      iVar8 = 0;

      local_c = FUN_00424ee0(in_EAX,4);

      if ((local_c < 5) && (param_1 < 3)) {

        local_10 = local_c + 3 >> 2;

        uVar6 = 0;

        if (local_10 != 0) {

          do {

            if (uVar6 == local_10 - 1) {

              iVar3 = (local_c - iVar8) * 8;

            }

            else {

              iVar3 = 0x20;

            }

            uVar4 = BitStream_readInt(iVar3);

            *(uint32_t /* width from decompiler */ *)((int)auStack_8 + iVar8) = uVar4;

            uVar6 = uVar6 + 1;

            iVar8 = iVar8 + 4;

          } while (uVar6 < local_10);

        }

        local_10 = 0;

        BitStream_readBits(8,&local_10);

        local_c = (local_10 & 0xff) * 8 + 4;

        if ((_DAT_00d20c18 & 2) == 0) {

          _DAT_00d20c18 = _DAT_00d20c18 | 2;

          DAT_00d20c10 = FUN_00783b60("LogConnectionProtocol");

        }

        uVar6 = local_14;

        if (*(char *)(DAT_00d20c10 + 4) != '\0') {

          uVar5 = *(uint *)(iVar1 + 0x8c);

          DAT_00d179a0 = DAT_00d20c10;

          while (uVar5 = uVar5 + 1, uVar5 < uVar6) {

            FUN_00783aa0("Not recv %d",uVar5);

          }

          FUN_00783aa0("Recv %d %s",uVar6,(&PTR_s_DataPacket_00afa258)[param_1]);

          DAT_00d179a0 = 0;

        }

        uVar5 = uVar6 - *(int *)(iVar1 + 0x8c);

        if (0x20 < uVar5) {

          iVar8 = (uVar5 - 0x21 >> 5) + 1;

          do {

            uVar5 = uVar5 - 0x20;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98) = 0;

        }

        local_10 = 0;

        *(uint *)(iVar1 + 0x98) =

             *(int *)(iVar1 + 0x98) << ((byte)uVar5 & 0x1f) | (uint)(param_1 == 0);

        auStack_8[1] = uVar7 - *(int *)(iVar1 + 0x90);

        if (auStack_8[1] != 0) {

          do {

            uVar6 = *(int *)(iVar1 + 0x90) + 1 + local_10;

            bVar9 = (auStack_8[uVar7 - uVar6 >> 5] & 1 << ((char)uVar7 - (char)uVar6 & 0x1fU)) != 0;

            if ((_DAT_00d20c18 & 4) == 0) {

              _DAT_00d20c18 = _DAT_00d20c18 | 4;

              DAT_00d20c0c = FUN_00783b60("LogConnectionProtocol");

            }

            if (*(char *)(DAT_00d20c0c + 4) != '\0') {

              DAT_00d179a0 = DAT_00d20c0c;

              FUN_00783aa0("Ack %d %d",uVar6,bVar9);

              DAT_00d179a0 = 0;

            }

            *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa8) = 0;

            FUN_004263a0(uVar6);

            if ((*(int *)(iVar1 + 0xa8) != 0) &&

               (fVar10 = (float)(int)((*(int *)(*(int *)(iVar1 + 0x1a8) + 0x78) -

                                      *(int *)(iVar1 + 0xa8)) - local_c) * g_flMultiKillCountBlend +

                         *(float *)(iVar1 + 0xbc) * DAT_00a0f734, *(float *)(iVar1 + 0xbc) = fVar10,

               fVar10 < 0.0)) {

              *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0;

            }

            if (bVar9) {

              *(uint32_t /* width from decompiler */ *)(iVar1 + 0x9c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc + (uVar6 & 0x1f) * 4);

            }

            local_10 = local_10 + 1;

            uVar6 = local_14;

          } while (local_10 < auStack_8[1]);

        }

        if (0x20 < uVar6 - *(int *)(iVar1 + 0x9c)) {

          *(uint *)(iVar1 + 0x9c) = uVar6 - 0x20;

        }

        uVar5 = *(uint *)(iVar1 + 0x8c);

        *(uint *)(iVar1 + 0x90) = uVar7;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x114) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x110) = 0;

        *(uint *)(iVar1 + 0x8c) = uVar6;

        if ((param_1 == 1) || (0x10 < uVar6 - *(int *)(iVar1 + 0x9c))) {

          FUN_00426290();

        }

        if ((uVar5 != uVar6) && (param_1 == 0)) {

          return 1;

        }

        return 0;

      }

    }

  }

LAB_00425c4c:

  return local_c & 0xffffff00;

}
