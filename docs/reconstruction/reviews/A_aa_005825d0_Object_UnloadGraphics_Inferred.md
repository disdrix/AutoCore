# Review A (reconstruction fidelity): `aa_005825d0` Object_UnloadGraphics_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005825d0` |
| **VA** | `0x005825d0`–`0x00582664` exclusive (**148 B**) |
| **Canonical name** | `Object_UnloadGraphics_Inferred` (Ghidra `FUN_005825d0`) |
| **Review date** | `2026-07-29` (W31-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005825d0_Object_UnloadGraphics_Inferred.md` |
| **System** | object / graphics unload / mission-state FX |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Object **unload-graphics** worker (MI this):

1. Untrack from manager lists via `FUN_004bfd10` (manager this from host `+0xE914`, stack arg = MI this).
2. Clear flag `this+0x0F = 0`.
3. Object root `vtbl+0x144()` (graphics destroy slot family).
4. `Object_SetMissionStateFx_Inferred(root, 3)` (W30-H).
5. Optional host notify `*(host+0xE500)->vtbl[0](root)`.
6. Object `vtbl+0xFC()`; self `vtbl+0x04()`; self `vtbl+0x18(0)`; self `vtbl+0x18(1)`.

Sole CODE caller `FUN_005d4fd0` logs **`"UnloadGraphics on %s (%d)"`** then calls this body. Also DATA-installed in 14 vtables.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005825d0_FUN_005825d0.md` (+ W31-T append) |
| Annotated | `docs/reconstruction/raw/aa_005825d0_FUN_005825d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_UnloadGraphics_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_005825d0.cpp` |
| Function records | `functions/aa_005825d0_*` |
| Live decompile | Ghidra @ `0x005825d0` |
| Live body bytes | full 148 B via `read_memory` |
| Nested dual | `A/B_aa_00518370_Object_SetMissionStateFx_Inferred` (W30-H) |
| Caller | live decompile `FUN_005d4fd0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `PUSH ESI; MOV ESI,ECX` |
| Manager load | `MOV EAX,[ESI+4]; MOV ECX,[EAX+4]; MOV EDX,[ECX+ESI+0xA8]; MOV ECX,[EDX+0xE914]` |
| Untrack | `PUSH ESI; CALL FUN_004bfd10` |
| Flag | `MOV BYTE PTR [ESI+0x0F],0` |
| Root | `LEA ECX,[ESI+adj+4]` |
| Destroy | `CALL [vtbl+0x144]` |
| Mission FX | `PUSH 3; LEA ECX,root; CALL FUN_00518370` |
| Notify | `MOV ECX,[host+0xE500]; TEST; CALL [ECX]` with root arg |
| Post | `CALL [vtbl+0xFC]`; self `+0x04`; self `+0x18(0)`; self `+0x18(1)` |
| Epilogue | `POP ESI; RET` (`C3`) |
| Body end | exclusive `0x00582664` (pad `CC` → `FUN_00582670`) |

Full body hex: raw W31-T (148 B).

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile CF spine ≡ raw | **pass** |
| Body size exclusive end | **pass** (`00582664`, 148 B) |
| bare RET / thiscall | **pass** |
| First callee this residual | **pass** (bytes win; decompiler shows wrong this) |
| SetMissionStateFx(3) | **pass** |
| UnloadGraphics caller string | **pass** |
| Clean typed path | **pass** |
| Product vfunc / class English | **gap** |
| FUN_004bfd10 product plate | **gap** (not OWN) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full body hex; bare RET |
| UnloadGraphics role | **High** | sole CODE caller format string |
| Manager this @ host+0xE914 | **High** | bytes |
| State 3 FX | **High** | W30-H callee |
| Product English | **Inferred** | structural `_Inferred` |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product/PDB class + vfunc English (`+0x144` / `+0xFC` / self `+0x18`).  
2. Nested `FUN_004bfd10` product type (list-manager).  
3. Host layout `+0xA8` / `+0xE500` / `+0xE914` product names.  
4. Exhaustive vtable slot catalog for 14 DATA installs.  
5. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
