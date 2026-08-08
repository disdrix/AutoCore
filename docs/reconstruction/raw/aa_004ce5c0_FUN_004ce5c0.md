# Raw capture: FUN_004ce5c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ce5c0` |
| **Canonical name** | `FUN_004ce5c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool __thiscall FUN_004ce5c0(int param_1,int param_2)



{

  if (param_2 == 0) {

    return false;

  }

  if (*(char *)(param_1 + 0xf5) != '\0') {

    return true;

  }

  return *(char *)(param_1 + 0x7e) != '\0';

}
```

---

## Live re-verify append (2026-08-05 MEGA-118)

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-118** |
| **Exclusive VA** | `0x004ce5c0` (`aa_004ce5c0`) |
| **System** | inventory-transfer |
| **Structural name** | `Character_TownInventoryFallback_Inferred` |
| **Ghidra** | `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_xrefs_to` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. No Launcher. |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

### Live checks

| Check | Result |
|---|---|
| `decompile_function` @ `0x004ce5c0` | **≡** raw CF (null stack-arg → false; `ECX+0xf5` true; else `ECX+0x7e != 0`) |
| `get_function_by_address` | Body **`004ce5c0`–`004ce5e3`** (Ghidra end); last insn `RET 4` @ `004ce5e1` |
| `analyze_function_complete` | classification **leaf**; callees **[]**; callers `FUN_008012f0`, `Client_SendInventoryUnequip`; xref_count **3**; locals `param_1`=register ECX, `param_2`=Stack[0x4] |
| `disassemble_function` | 11 insns; three **`RET 0x4`** exits; no external CALL |
| `read_memory` length 64 | Body hex sealed (below); trailing `cc` pad then sibling `004ce5f0` prologue |
| Callers | **2** functions / **3** UNCONDITIONAL_CALL sites |
| Xrefs | `00801351`, `00801654` in `FUN_008012f0`; `00862caa` in `Client_SendInventoryUnequip` |

### Byte seal (`read_memory` + `disassemble_function` @ `0x004ce5c0`)

Inclusive body through final RET: **`0x004ce5c0`–`0x004ce5e3`** (Ghidra body end exclusive `004ce5e3`).

```
004ce5c0  83 7c 24 04 00     cmp dword [esp+4], 0     ; character*
004ce5c5  75 05              jnz 004ce5cc
004ce5c7  32 c0              xor al, al
004ce5c9  c2 04 00           ret 4                    ; false
004ce5cc  80 b9 f5 00 00 00 00  cmp byte [ecx+0xf5], 0  ; mode host
004ce5d3  74 05              jz 004ce5da
004ce5d5  b0 01              mov al, 1
004ce5d7  c2 04 00           ret 4                    ; true
004ce5da  80 79 7e 00        cmp byte [ecx+0x7e], 0
004ce5de  0f 95 c0           setne al
004ce5e1  c2 04 00           ret 4                    ; (mode+0x7e)!=0
004ce5e4  cc…                int3 pad → sibling 004ce5f0
```

Hex (body through final RET, 36 B / `0x24`):

```
83 7c 24 04 00 75 05 32 c0 c2 04 00 80 b9 f5 00 00 00 00 74 05 b0 01 c2 04 00 80 79 7e 00 0f 95 c0 c2 04 00
```

### ABI seal (call-site assembly)

| Slot | Register / stack | Conf |
|---|---|---|
| mode host (flags) | **ECX** (`param_1`) | **High** — `cmp [ecx+0xf5]` / `cmp [ecx+0x7e]` |
| character* | stack `[ESP+4]` (`param_2`) | **High** — entry `cmp [esp+4],0` |
| cleanup | **`RET 4`** ×3 exits | **High** — `c2 04 00` |
| return | **AL** bool | **High** |

| Site | ECX setup | Stack push | True-path follow-up |
|---|---|---|---|
| `Client_SendInventoryUnequip` `0x00862caa` | `MOV ECX,[0x00d1b644]` | `PUSH [0x00d1b6d8]` (character host) | `MOV ECX,[0x00d1b6d8]`; `MOV EDI,[ECX+0xcbc]` then free-slot retry |
| `FUN_008012f0` mode-3 `0x00801351` | `MOV ECX,[ESI+0xe04]` | `PUSH EAX` where `EAX=[ESI+0xe98]` (preserved from prologue) | `MOV EBP,[[ESI+0xe98]+0xcbc]` (locker grid) |
| `FUN_008012f0` free-slot fallback `0x00801654` | `MOV ECX,[ESI+0xe04]` after `PUSH [ESI+0xe98]` | character host | free-slot retry `FUN_005714e0`; success → mode byte **3** / grid `+0xcbc` |

### Semantics (sealed structure)

1. Null **character** (stack) → **false**.
2. Else **true** if `modeHost+0xf5 != 0`.
3. Else **true** iff `modeHost+0x7e != 0`.
4. **Leaf** — no external CALLs; pure predicate (no stores).

### Role (caller CF — structural, not product PDB)

- Parent dualed **`Client_SendInventoryUnequip`** (`0x00862c00`): after free-slot `FUN_005714e0` fails, gate true → rebind dest via character **`+0xcbc`** (inventory type **3** / locker grid) and retry free-slot; else toast *"There is not enough space…"*.
- **`FUN_008012f0`** (C2S inventory move builder opcode **`0x2036`**): mode **3** path gated by this predicate then uses **`char+0xcbc`**; free-slot miss path uses same gate to allow mode-3/locker fallback (else equip-change toast).

### Related (not dualled here)

- Immediate sibling **`Character_HostModeGateForObjectV210`** `0x004ce5f0` — same host flag pair `+0xf5`/`+0x7e` after object `vtbl+0x210(0)` gate.
- Parent-seed name `Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0` is **incomplete** (also `FUN_008012f0` ×2).

### Gaps remaining

- Product/PDB symbol.
- Product English for mode-host flags `+0xf5` / `+0x7e` and identity of `DAT_00d1b644` / `client+0xe04` (shared layout only).
- Whether product string says "town" vs "locker" for `+0xcbc` path (layout docs: locker / inv type 3).
- Runtime / bit-exact / differential — open (no Launcher).
