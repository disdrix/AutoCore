// =============================================================================
// Skill_HB_CopyTfid16At668_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b960
// Address:   0x0061b960  (autoassault.exe, image base 0x400000)
// Body:      0x0061b960–0x0061b986 inclusive (39 B / 0x27); pad CC after ret 4
// System:    skills-abilities
// Ghidra:    FUN_0061b960
// Dual:      2026-08-05 MEGA-016 OWN-ONLY
//
// Purpose: Copy the 16-byte TFID identity blob stored at skill-HB this+0x668
//          into the caller-provided TFID_16 out buffer. Leaf; no mutation of
//          source. Sole caller: shared skill-HB pulse FUN_0061b6f0 @ 0x0061b760
//          (feeds vtbl+0x88 target apply after vtbl+0x214 resolve).
//
// ABI:     __thiscall
//          ECX = skillHB* (layout has TFID_16 at +0x668)
//          stack: TFID_16 *out
//          ret 4
//          EAX = out (entry pointer preserved)
//
// Twin:    Object_CopyTfid16At228_Inferred (0x0040aff0) — same body shape,
//          different source offset (+0x228 on world/object vs +0x668 on skill-HB).
//
// Exactness: Behavior-preserving rewrite of decompiler CF + live disasm /
//            read_memory (MEGA-016). Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN (no Launcher).
// =============================================================================

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;
  std::uint32_t dwCoidHi;
  std::uint32_t uGlobalAndPad; // bGlobal + pads (product field names residual)
  std::uint32_t uPadTail;
};

// Returns out (EAX) for chain convenience; decompiler may show void.
TFID_16 *__thiscall Skill_HB_CopyTfid16At668_Inferred(void *thisSkillHb, TFID_16 *out)
{
  // Bytes: add ecx, 0x668; then four dword moves to *out
  // 0061b960  mov eax, [esp+4]
  // 0061b964  add ecx, 0x668
  // 0061b96a  push esi
  // … four dword pairs …
  // 0061b983  pop esi
  // 0061b984  ret 4
  const auto *src = reinterpret_cast<const std::uint32_t *>(
      reinterpret_cast<const char *>(thisSkillHb) + 0x668);
  out->dwCoidLo = src[0];       // this+0x668
  out->dwCoidHi = src[1];       // this+0x66c
  out->uGlobalAndPad = src[2];  // this+0x670
  out->uPadTail = src[3];       // this+0x674
  return out;
}
