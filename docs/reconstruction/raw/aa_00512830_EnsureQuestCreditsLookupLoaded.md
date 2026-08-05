# Raw capture: EnsureQuestCreditsLookupLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512830` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00512830` |
| **Canonical name** | `EnsureQuestCreditsLookupLoaded` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* EnsureQuestCreditsLookupLoaded — one-shot init for tQuestCreditsLookup.
   
   Algorithm:
     if already loaded: return
     LoadQuestCreditsLookupFromWad(//tQuestCreditsLookup/row)
     sets g_nQuestCreditsLookupLoaded_Inferred
   
   Columns: IDQuestCreditsIndex → rlLevelCredits (float @ record+0x10). */

void EnsureQuestCreditsLookupLoaded(void)

{
  int iVar1;
  
  FUN_007e1d80();
  iVar1 = LoadQuestCreditsLookupFromWad(&g_pQuestCreditsLookupMap_Inferred);
  FUN_007b7df0();
  if (iVar1 < 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
```

---

## v2 append — 2026-07-29 dual A/B (`read_memory` + re-decompile)

Do not treat plate early-out / flag-set as body truth. Live decompile still matches the 2026-07-23 pseudocode above (hidden ECX). Asm-sealed bytes @ `0x00512830` (62 bytes):

```text
8B 0D 9C 46 B0 00 56 E8 44 F5 2C 00
8B 0D 9C 46 B0 00 68 58 42 B0 00 E8 24 9C 2B 00
8B 0D 9C 46 B0 00 8B F0 E8 97 55 2A 00
85 F6 5E 7D 0F 68 44 58 A1 00 6A 00 E8 16 1C 29 00 83 C4 08 C3
```

Decoded:

| Off | Bytes | Meaning |
|----:|-------|---------|
| +0 | `8B0D9C46B000` | `ecx = *[0x00b0469c]` |
| +6 | `56` | `push esi` |
| +7 | `E844F52C00` | `call FUN_007e1d80` → `0x007e1d80` |
| +0xC | `8B0D9C46B000` | `ecx = *[0x00b0469c]` |
| +0x12 | `685842B000` | `push 0x00b04258` (map root) |
| +0x17 | `E8249C2B00` | `call LoadQuestCreditsLookupFromWad` → `0x007cc470` |
| +0x1C | `8B0D9C46B000` | `ecx = *[0x00b0469c]` |
| +0x22 | `8BF0` | `esi = eax` (status) |
| +0x24 | `E897552A00` | `call FUN_007b7df0` → `0x007b7df0` |
| +0x29 | `85F65E7D0F` | `test esi,esi; pop esi; jge ret` |
| +0x2E | `684458A1006A00` | push `"VOG_DEBUG_STOP"` @ `0x00a15844`; push 0 |
| +0x35 | `E8161C2900` | `call FUN_007a4480` → `0x007a4480` |
| +0x3A | `83C408C3` | `add esp,8; ret` |

String `read_memory` @ `0x00a15844`: `VOG_DEBUG_STOP\0`.

Globals (`list_globals`):

- `g_pQuestCreditsLookupMap_Inferred` @ `0x00b04258`
- `g_pQuestCreditsLookupEndSentinel_Inferred` @ `0x00b0425c`
- `g_nQuestCreditsLookupLoaded_Inferred` @ `0x00b04260` (xrefs: READ only from `Mission_ComputeObjectiveCredits`)

Callers: `Mission_ComputeObjectiveCredits`, `FUN_0094a6a0`.  
Callees: `FUN_007e1d80`, `LoadQuestCreditsLookupFromWad`, `FUN_007b7df0`, `FUN_007a4480`.
