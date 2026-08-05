// =============================================================================
// Client_Input_TryUseModChip
// -----------------------------------------------------------------------------
// Stable ID: aa_0091f6b0
// Address:   0x0091f6b0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (skill cast side-path)
// Generated: 2026-07-29 dual A/B (from raw 2026-07-23 + fresh decompile/asm)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Client input entry to attempt using the equipped vehicle **mod chip**.
//   Gates local player / global block flags, stamps client+0xc2c = 9999999,
//   then either:
//     A) player+0x6b9 set → send C2S 0x202c (self TFID) immediately, or
//     B) require vehicle + FUN_0040ce50 mod-chip skill; LocalCastValidate;
//        on allow send 0x202c; on deny toast FormatFailureMessage;
//        if no skill → modal "You have no mod chip!".
//
// ABI: __fastcall — EDX = client*; ECX unused; void.
// Callers: Client_Input_DriveControlTick (ActionMap DAT_00d1cafa edge);
//          FUN_008c50f4 (UI hazard/case-8 path via DAT_00d1b778+vtbl0x3d8).
//
// Embedded strings:
//   - "You have no mod chip!"
// =============================================================================

/* External symbols (Ghidra / prior plates) */
extern void *DAT_00d1b6d8;   /* local character */
extern int   DAT_00d1b644;   /* world / client-globals host */
extern int   DAT_00d1a840;   /* client root for SendSectorPacket / toast */
extern int   DAT_00d1b8dc;   /* optional combat-log / chat host */
extern char  DAT_00a156cc[]; /* toast format "!" */

void Client_SendSectorPacket(void *clientRoot, unsigned size, void *pkt);
/* FUN_0040ce50: vehicle thiscall/fastcall — mod-chip skill ptr or -1 */
unsigned FUN_0040ce50(void *vehicle);
int  Skill_LocalCastValidate(void *character, void *target, char skipBusy, void *skill);
char *Skill_FormatFailureMessage(int code, char *outBuf, void *characterOrNull);
void FUN_007fdfb0(void *clientRoot, const char *msg, int a, int b, int c);
void FUN_008f8200(int host, int a, void *fmt, char *msg, int z);

void __fastcall Client_Input_TryUseModChip(
    unsigned /*unused*/ param_1,
    int client /* EDX */)
{
  unsigned *puVar1;
  char bSkipBusyCheck;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  unsigned local_118;
  unsigned uStack_114;
  unsigned local_110;
  unsigned local_10c;
  unsigned local_108;
  unsigned local_104[65];

  /* SECTION 1: entry gates */
  if (((DAT_00d1b6d8 != (void *)0x0) && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) &&
     (*(char *)((int)DAT_00d1b6d8 + 0x6bb) == '\0')) {

    /* SECTION 2: client timer / cooldown sentinel */
    *(unsigned *)(client + 0xc2c) = 9999999; /* 0x98967f */
    pvVar3 = DAT_00d1b6d8;

    /* SECTION 3: path A — armed flag +0x6b9 → fire 0x202c without validate */
    if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0') {
      local_118 = 0x202c;
      puVar1 = (unsigned *)
               (*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x164 + (int)DAT_00d1b6d8);
      local_110 = *puVar1;
      local_10c = puVar1[1];
      local_108 = puVar1[2];
      local_104[0] = puVar1[3];
      Client_SendSectorPacket(&DAT_00d1a840, 0x18, &local_118);
      return;
    }

    /* SECTION 4: no vehicle or no mod-chip skill → modal toast */
    if ((*(int *)((int)DAT_00d1b6d8 + 0x250) == 0) || (iVar2 = FUN_0040ce50(), iVar2 == -1)) {
      FUN_007fdfb0(&DAT_00d1a840, "You have no mod chip!", 0xffffffff, 1, 0);
    }
    else {
      /* SECTION 5: LocalCastValidate with vehicle mod-chip skill */
      iVar2 = *(int *)(*(int *)(*(int *)((int)pvVar3 + 4) + 4) + 4 + (int)pvVar3);
      pvVar3 = (void *)FUN_0040ce50(0);
      bSkipBusyCheck = (**(code **)(iVar2 + 0x234))();
      iVar2 = Skill_LocalCastValidate(
                        (void *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +
                                 (int)DAT_00d1b6d8),
                        (void *)0x0,
                        bSkipBusyCheck,
                        pvVar3);

      /* SECTION 6: validate OK (0) → send 0x202c + self TFID
       * Asm seals opcode write (decompiler stack name may omit it). */
      if (iVar2 == 0) {
        puVar1 = (unsigned *)
                 (*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x164 + (int)DAT_00d1b6d8);
        /* opcode 0x202c written at packet base (see asm 0x0091f7ac) */
        uStack_114 = *puVar1;
        local_110 = puVar1[1];
        local_10c = puVar1[2];
        local_108 = puVar1[3];
        Client_SendSectorPacket(&DAT_00d1a840, 0x18, &stack0xfffffee4);
        return;
      }

      /* SECTION 7: validate fail → format + optional log toast */
      pvVar3 = DAT_00d1b6d8;
      if (DAT_00d1b6d8 != (void *)0x0) {
        pvVar3 = (void *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 + (int)DAT_00d1b6d8);
      }
      pcVar4 = Skill_FormatFailureMessage(iVar2, (char *)local_104, pvVar3);
      if (DAT_00d1b8dc != 0) {
        FUN_008f8200(DAT_00d1b8dc, 0x18, &DAT_00a156cc, pcVar4, 0);
        return;
      }
    }
  }
  return;
}
