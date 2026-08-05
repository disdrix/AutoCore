// =============================================================================
// FUN_00723ab0 / CSoundManager::_stopSound
// -----------------------------------------------------------------------------
// Stable ID: aa_00723ab0
// Address:   0x00723ab0 – 0x00723b14  (autoassault.exe, image base 0x400000)
// System:    client audio / CSoundManager
// Generated: 2026-07-29 OWN dual W16-H (decompile + read_memory; assembly-faithful)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   CSoundManager::_stopSound — stop one active sound slot by index.
//   Product name sealed by log string at 0x00aa91d0.
//
// ABI (assembly-sealed):
//   ECX  = CSoundManager* this
//   EAX  = unsigned slot index (must be < 0x30)
//   ret  = AL 1 on accepted stop, 0 otherwise (no stack cleanup)
//
// READABILITY:
//   - Body 101 bytes; branches: range/null fail, flag gate, success, log-fail.
//   - Callees: FUN_007227e0 (fade/envelope float), FUN_007a4480 (log).
//   - Ghidra 2026-07-23 decompile invents uVar2/extraout packing — do not port that.

/*
 * Behavioral notes:
 * - Slot table at this+0x31c, 48 entries (index < 0x30).
 * - Success only when slot+0x38==0 and slot+0x3a==0 (not already stopped,
 *   not flagged to start playing). Then write envelope float at +0x1b0,
 *   set +0x38=1, clear +0x3a=0, return 1.
 * - FUN_007227e0(0.0f) returns DAT_00aaa5d8 = -10000.0f (arg <= 0 path).
 * - Invalid flags: log via FUN_007a4480 and return 0.
 * - Range/null: return 0 without log.
 */

// FUN_007227e0: float helper (callee not owned this dual)
// FUN_007a4480: log helper (callee not owned this dual)

typedef unsigned char uint8_t;
typedef unsigned int  uint;

// Assembly-faithful: ECX=this, EAX=index. Ghidra __fastcall param_1 = this.
uint8_t __fastcall FUN_00723ab0(int param_1 /* this ECX */)
{
  int iVar1;
  uint in_EAX; /* slot index — live in EAX at entry */

  if ((in_EAX < 0x30) &&
      (iVar1 = *(int *)(param_1 + 0x31c + in_EAX * 4), iVar1 != 0)) {
    if ((*(char *)(iVar1 + 0x38) == '\0') && (*(char *)(iVar1 + 0x3a) == '\0')) {
      /* push 0; call FUN_007227e0 → ST0 = -10000.0f; fstp [iVar1+0x1b0] */
      *(float *)(iVar1 + 0x1b0) = (float)FUN_007227e0(0.0f);
      iVar1 = *(int *)(param_1 + 0x31c + in_EAX * 4);
      *(uint8_t *)(iVar1 + 0x38) = 1;
      iVar1 = *(int *)(param_1 + 0x31c + in_EAX * 4);
      *(uint8_t *)(iVar1 + 0x3a) = 0;
      return 1;
    }
    iVar1 = *(int *)(param_1 + 0x31c + in_EAX * 4);
    FUN_007a4480(
        0,
        "CSoundManager::_stopSound called with sound that was either already stopped(%d), or flagged to start playing(%d)",
        *(uint8_t *)(iVar1 + 0x38),
        *(uint8_t *)(iVar1 + 0x3a));
  }
  return 0;
}
