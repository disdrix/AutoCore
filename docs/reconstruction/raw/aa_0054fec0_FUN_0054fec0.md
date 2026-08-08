# Raw capture: FUN_0054fec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0054fec0` |
| **Canonical name** | `FUN_0054fec0` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0054fec0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00627be0();
  if (*(uint *)(param_1 + 0x620) == 0) {
    *(uint *)(param_1 + 0x624) = uVar1;
  }
  else {
    *(uint *)(param_1 + 0x624) = uVar1 | 4;
    if (*(char *)(param_1 + 0x148) == '\0') {
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 0x100000;
      return;
    }
  }
  return;
}
```

---

## Live re-verify append — 2026-08-04 (WQ9E-B)

| Field | Value |
|---|---|
| Tool | Ghidra MCP `batch_decompile` / `analyze_function_complete` + `read_memory` + `get_xrefs_to` / bulk xrefs; **no** `disassemble_bytes` |
| Live decompile | ≡ raw body above (CF, offsets `+0x620`/`+0x624`/`+0x148`, `|4`, `|0x100000`) |
| Body bytes | `0x0054fec0`–`0x0054fef8` inclusive of final `ret` (**0x39** = 57 B); `CC` pad after |
| Entry hex | `56 8B F1 E8 18 7D 0D 00` = `push esi; mov esi,ecx; call Skill_ComputeEffectPresenceFlags (0x00627be0)` |
| Store CF (bytes) | `test [esi+0x620]`; jz → store EAX to `+0x624` plain; else `or al,4` then store; if `byte[esi+0x148]==0` then `or [esi+0x620],0x100000` |
| ABI | MSVC **`__fastcall`/`__thiscall`**: `ECX` = skill runtime; void; plain `ret` (`5E C3`) |
| Callee | `Skill_ComputeEffectPresenceFlags_Inferred` (`FUN_00627be0` @ `0x00627be0`) only |
| Callers / xrefs | **None static** (`get_xrefs_to` / bulk / data pattern `C0 FE 54 00` all empty). Store tail is **duplicated** (not called) inside `Skill_ReevaluateForCurrentRank` (`0x00553390`) after Evaluate |
| Twin | Reevaluate store post-process is CF-identical to this unit |
| Named | `Skill_StoreEffectPresenceFlags_Inferred` |
