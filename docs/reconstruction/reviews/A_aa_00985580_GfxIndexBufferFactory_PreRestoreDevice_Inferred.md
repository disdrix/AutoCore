# Review A (reconstruction fidelity): `aa_00985580` GfxIndexBufferFactory_PreRestoreDevice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985580` |
| **VA** | `0x00985580`–`0x00985601` exclusive (**129 B**) |
| **Canonical name** | `GfxIndexBufferFactory_PreRestoreDevice_Inferred` |
| **Ghidra name** | `FUN_00985580` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-AC) |
| **Counterpart** | `reviews/B_aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md` |
| **System** | gfxIndexBufferFactory pre-Reset IB release |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + callers/xrefs + `get_assembly_context` @ `0x0075f0dc` + callee decompile `FUN_00743c50`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk the index-buffer factory's map and release device resources for every eligible `gfxDeviceIB` slot before `IDirect3DDevice9::Reset`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-AC append) | `docs/reconstruction/raw/aa_00985580_FUN_00985580.md` |
| Annotated | `docs/reconstruction/raw/aa_00985580_FUN_00985580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxIndexBufferFactory_PreRestoreDevice_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00985580.cpp` |
| Function record | `docs/reconstruction/functions/aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md` |
| Parent | `GfxDevice_Reset` / `FUN_0075eff0` @ call `0x0075f0dc` |
| Callee | `FUN_00743c50` (`gfxDeviceIB.cpp` release) |

---

## 3. Signature (sealed)

```c
// EAX = factory*; plain RET; void
void GfxIndexBufferFactory_PreRestoreDevice_Inferred(
    /* EAX */ void* factory);
```

| Formal | Source | Conf |
|---|---|---|
| factory* | **EAX** (`MOV ECX,[EAX+0x14]` entry; caller `MOV EAX,[EBP+0x750]`) | **High** |
| return | void (no consumer) | **High** |
| RET | plain `C3` @ `0x00985600` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Load map sentinel @ factory+0x14 | decompile + `8B 48 14` | **High** |
| Empty / full RB in-order walk (`is_nil@+0x21`) | decompile + successor blocks | **High** |
| Flag gate `& 0x28` @ node+0x0C | `F6 47 0C 28` | **High** |
| Slot range [+0x14,+0x18) stride 0x20 | `ADD EBP,0x20` / decompile | **High** |
| `MOV ESI,[slot]; CALL FUN_00743c50` | bytes + callee `unaff_ESI` | **High** |
| Epilogue `5E 5D 5B 5F 59 C3` | `read_memory` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (129 B) — raw W38-AC append.

Entry: `51 8B 48 14 57 8B 39 3B F9 …`.  
Epilogue: `5E 5D 5B 5F 59 C3`.  
Pad `CC`×15 then `FUN_00985610` (`PostRestoreDevice`).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0075eff0` ×1 @ `0x0075f0dc` (shutdown cascade, after `FUN_00985f40`, before `FUN_009864e0`) |
| Callees | `FUN_00743c50` only |

---

## 7. Gaps

1. Product/PDB method English (PreRestoreDevice vs OnLostDevice / ReleaseDeviceObjects) — **Inferred**.  
2. Node key / map value_type English.  
3. Exact meaning of flag bits `0x08|0x20` beyond “skip release”.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

EAX factory ABI, map walk, flag gate, stride-0x20 release loop, sole Reset-shutdown caller, and 129 B body sealed. Product plate residual + no runtime → **accept-with-gaps**.
