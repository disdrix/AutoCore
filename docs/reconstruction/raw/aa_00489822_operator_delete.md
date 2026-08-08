# Raw capture: operator_delete

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489822` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489822` |
| **Canonical name** | `operator_delete` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00489822. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}
```

---

## R10-001 re-verify (2026-08-05) — OWN dual append only

**Agent:** R10-001 OWN-ONLY dual for residual wave R10.  
**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`. No Launcher.  
**Scaffold raw body above preserved.**

### Live decompile (≡ scaffold)

```c
void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00489822. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}
```

### Body / ABI (`read_memory` + `get_function_by_address` sealed)

| Item | Value |
|---|---|
| Body | `0x00489822`–`0x00489827` inclusive (**6 B** / `0x6`) |
| Hex | `FF 25 94 66 9C 00` |
| Decode | `JMP dword ptr [0x009C6694]` — MSVC **IAT import thunk** |
| Next sibling | `0x00489828` — next import thunk (`FF 25 90 66 9C 00`) |
| Prev sibling | `0x0048981C` — `operator_delete[]` (`FF 25 98 66 9C 00` → IAT `0x009C6698`) |
| Classification | Ghidra **`thunk`** (`is_thunk: true`); custom name `operator_delete` |
| Signature (Ghidra) | `noreturn void __cdecl operator_delete(void * param_1)` — **`noreturn` is FALSE** (known CRT contamination; free returns) |
| Formal | `param_1` / `void *` / `Stack[0x4]:4` — **cdecl** single pointer |
| Callees (static) | none (indirect JMP through IAT; not a CALL graph edge) |
| IAT slot | `0x009C6694` — sole xref **INDIRECTION** from this thunk |
| IAT live value (this Ghidra image) | dword `0x006EA824` at `009C6694` (runtime-resolved CRT entry; not dualed) |

### Assembly (byte-accurate)

```text
00489822  FF 25 94 66 9C 00    JMP dword ptr [0x009C6694]   ; operator_delete IAT
; end body 00489827
00489828  FF 25 90 66 9C 00    JMP dword ptr [0x009C6690]   ; next import (not OWN)
0048981C  FF 25 98 66 9C 00    JMP dword ptr [0x009C6698]   ; operator_delete[] (R10-010; not OWN)
```

### Callers / xrefs (live)

| Kind | Count / notes |
|---|---|
| **Callers** (`analyze_function_complete`) | **5045** total — ~2463 FUN/Catch + ~2568 Unwind SEH cleanups |
| **Xrefs listed** | tool cap **100** (`xref_count: 100`) — sample UNCONDITIONAL_CALL from FUN/Unwind sites |
| **Parent seed** | partition parent `0x005725a0` (inventory-transfer) — **seed only**, not this VA's identity |
| **Sample FUN callers** | `FUN_00402280`, `FUN_00415e90` family, list/map destroy paths, scalar-deleting dtors, inventory free sites, global CRT free surface |

### Classification

CRT **scalar `operator delete`** import thunk (MSVC `jmp [iat]`). Canonical dual name: **`operator_delete`** (Ghidra symbol; not product-inferred).

**Reject:** inventory-transfer product helper; true noreturn; in-image free implementation; merge with `operator_delete[]` @ `0x0048981c`.

### Semantics (sealed)

1. Single instruction: transfer control to the CRT function bound at IAT `0x009C6694`.
2. ABI = MSVC **`void __cdecl operator delete(void*)`** — stack arg at `[ESP+4]` after CALL; callee cleans? No — **cdecl** (caller `ADD ESP,4` after CALL sites).
3. **Returns** to caller after free (Ghidra `noreturn` / jumptable warnings are decompiler false positives on IAT JMP).
4. Not inventory-specific; universal heap free entry used across the image.

### Integrity

Scaffold raw body above **preserved**. This section **appended only**.
