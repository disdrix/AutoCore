# Review A (reconstruction fidelity): `aa_00985610` GfxIndexBufferFactory_PostRestoreDevice

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985610` |
| **VA** | `0x00985610`–`0x009857fb` exclusive (**491 B**) |
| **Canonical name** | `GfxIndexBufferFactory_PostRestoreDevice` |
| **Ghidra name** | `FUN_00985610` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-AC) |
| **Counterpart** | `reviews/B_aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md` |
| **System** | gfxIndexBufferFactory.cpp PostRestoreDevice |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full 491 B) + callers/xrefs + `get_assembly_context` @ `0x0075f281` + callee decompile `FUN_00743cd0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

After successful `IDirect3DDevice9::Reset`, recreate every eligible hardware index buffer and fire restore-surface callbacks; return 0 or fail.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-AC append) | `docs/reconstruction/raw/aa_00985610_FUN_00985610.md` |
| Annotated | `docs/reconstruction/raw/aa_00985610_FUN_00985610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxIndexBufferFactory_PostRestoreDevice.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00985610.cpp` |
| Function record | `docs/reconstruction/functions/aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md` |
| Parent | `GfxDevice_Reset` @ call `0x0075f281` |
| Create leaf | `FUN_00743cd0` (`gfxDeviceIB.cpp`) |

---

## 3. Signature (sealed)

```c
// EAX = factory*; plain RET; returns 0 or HRESULT < 0
int GfxIndexBufferFactory_PostRestoreDevice(
    /* EAX */ void* factory);
```

| Formal | Source | Conf |
|---|---|---|
| factory* | **EAX** (entry `MOV ESI,[EAX+0x14]`; caller `MOV EAX,[EBP+0x750]`) | **High** |
| return 0 | `33 C0` before epilogue | **High** |
| return hr | soft-fail `8B C6` (ESI holds `FUN_00743cd0` result) | **High** |
| RET | plain `C3` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty map early return 0 | decompile + JE far | **High** |
| Same map walk / flag `0x28` / stride 0x20 as PreRestore | decompile + bytes | **High** |
| `FUN_00743cd0(count, usage, is32)` with EDI=IB* | push triple + call; `CMP [EDI+0x10],4` | **High** |
| Fail → errReport line 0x180 PostResoreDevice string | string xrefs + decompile | **High** |
| code==3 → VOGCRASH / raise / ExitProcess | decompile + IAT calls | **High** |
| Callback tree @ slot+8, is_nil@+0x11 | decompile | **High** |
| Callback fail → log only (non-fatal) | continues loop | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (491 B) — raw W38-AC append.

Entry: `83 EC 10 53 55 56 8B 70 14 …`.  
Success epilogue: `5F 5E 5D 33 C0 5B 83 C4 10 C3`.  
Pad `CC`×5 then next factory unit @ `0x00985800`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0075eff0` ×1 @ `0x0075f281` (post-Reset rebuild; parent `TEST EAX,EAX; JGE` else IB Factory fail @ 0x236) |
| Callees | `FUN_00743cd0`, `FUN_0076d1b0`, `FUN_0076cec0`, `vog_LogMessage`, CRT/IO, `raise`, `ExitProcess` |

---

## 7. Gaps

1. Callback host / secondary-tree value_type product English.  
2. Whether `FUN_00743cd0` always returns `0`/`0xFFFFFFFF` vs raw D3D HRESULT (port must preserve ESI passthrough).  
3. Nested create-leaf full pool/usage mapping (not OWN).  
4. Runtime / bit-exact.

---

## 8. Verdict rationale

Product PostRestoreDevice string, EAX factory ABI, int return, recreate+callback CF, sole post-Reset caller, and 491 B body sealed. Nested leaf / callback plate residual → **accept-with-gaps**.
