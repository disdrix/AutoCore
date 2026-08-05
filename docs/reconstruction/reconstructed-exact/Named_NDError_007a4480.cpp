// =============================================================================
// Named_NDError_007a4480  →  NDError_Log
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4480
// Address:   0x007a4480 – 0x007a44d0
// Alias of FUN_007a4480 / NDError_Log (dual A/B seal 2026-07-29)
// =============================================================================

void Named_NDError_007a4480(char enable, char *fmt, ...)
{
  char local_800[2048];

  if ((enable == '\x01') && (fmt != (char *)0x0)) {
    _vsnprintf(local_800, 0x800, fmt, (char *)&fmt + 4);
    vog_LogMessage(
        "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDError.cpp",
        0x65,
        3,
        local_800);
  }
  return;
}
