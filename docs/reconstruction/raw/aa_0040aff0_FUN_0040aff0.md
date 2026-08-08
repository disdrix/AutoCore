# Raw capture: FUN_0040aff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040aff0` |
| **Canonical name** | `FUN_0040aff0` |
| **Proposed name** | `Object_CopyTfid16At228_Inferred` |
| **System** | identity / TFID |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0040aff0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x228);
  param_2[1] = *(undefined4 *)(param_1 + 0x22c);
  param_2[2] = *(undefined4 *)(param_1 + 0x230);
  param_2[3] = *(undefined4 *)(param_1 + 0x234);
  return;
}
```

---

## 2026-08-04 WQ9R-B re-verify (append-only)

| Field | Value |
|---|---|
| Agent | WQ9R-B OWN-ONLY |
| Tools | `decompile_function` / `batch_decompile`, `read_memory`, `get_function_by_address`, `get_function_xrefs`, `get_function_callers` |
| Disallowed | `disassemble_bytes`; Launcher; parent ledgers |

### Live decompile (2026-08-04)

Identical to 2026-07-23 body: four dword loads from `this+0x228..+0x234` into out buffer.

### Body bytes (`read_memory` @ `0x0040aff0`, 48 B)

```
8B 44 24 04       mov  eax, [esp+4]        ; out TFID_16*
81 C1 28 02 00 00 add  ecx, 0x228          ; this += 0x228
56                push esi
8B 31             mov  esi, [ecx]
8B D0             mov  edx, eax
89 32             mov  [edx], esi
8B 71 04          mov  esi, [ecx+4]
89 72 04          mov  [edx+4], esi
8B 71 08          mov  esi, [ecx+8]
89 72 08          mov  [edx+8], esi
8B 49 0C          mov  ecx, [ecx+0xC]
89 4A 0C          mov  [edx+0xC], ecx
5E                pop  esi
C2 04 00          ret  4
CC…               pad
```

| Claim | Evidence |
|---|---|
| Body `0x0040aff0`–`0x0040b016` (38 B to exclusive end) | `get_function_by_address` + bytes |
| `__thiscall` + one stack arg; **`ret 4`** | `C2 04 00` |
| Copy **16 bytes** (4×u32) from **`this+0x228`** | `add ecx,0x228` + four loads |
| EAX returns **out** pointer (preserved across body) | `mov eax,[esp+4]`; never clobbered |
| Leaf | zero callees |

### Callers (Ghidra xrefs, 23 UNCONDITIONAL_CALL)

Including: `Skill_FilterTargetForResolveList_Inferred` (×3), `CVOGHBAIBase_FindTargetToAttack`, `FUN_004ca150`, `FUN_004ca760`, `FUN_00515520`, `FUN_0058a810`, `FUN_005b10a0`, `FUN_0061db60`, `FUN_007ffef0` (×4), `FUN_00836410`, `FUN_00930fc0`, plus sites at `0x005db81a` / `0x005db8cd`.

### Role seal

Out-buffer **TFID_16** extract from object identity layout at **`+0x228..+0x234`** (same field family as combat climb / mode-select duals). Sibling shape: skill HB TFID copy `FUN_0061b960` (from `+0x668`).
