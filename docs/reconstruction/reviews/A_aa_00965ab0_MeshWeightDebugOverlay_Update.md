# Review A (reconstruction fidelity): `aa_00965ab0` MeshWeightDebugOverlay_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00965ab0` |
| **VA** | `0x00965ab0`–`0x0096650A` exclusive (**2650 B**) |
| **Canonical name** | `MeshWeightDebugOverlay_Update` |
| **Ghidra name** | `FUN_00965ab0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-N) |
| **Counterpart** | `reviews/B_aa_00965ab0_MeshWeightDebugOverlay_Update.md` |
| **System** | Client gfx mesh-weight debug overlay |
| **Evidence pass** | Live Ghidra `batch_decompile` / `analyze_function_complete` (no disasm) + `read_memory` (entry, resize site, terminal, globals) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-BeginScene update of mesh skinning-weight debug overlay: fade, rebuild text lines, draw/layout.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-N append) | `docs/reconstruction/raw/aa_00965ab0_FUN_00965ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00965ab0_FUN_00965ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshWeightDebugOverlay_Update.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00965ab0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00965ab0_MeshWeightDebugOverlay_Update.md` |
| Resize dual | W35-Q `aa_004611e0` |
| Parent decompile | `FUN_0075fb90` (gfxDevice.cpp residual) |
| Callers | `FUN_0075fb90` @ `0x0075fc18` |

---

## 3. Signature (sealed)

```c
// stdcall RET 4; EDI=self in body
void MeshWeightDebugOverlay_Update(MeshWeightDebugOverlay* self);
```

| Formal | Source | Conf |
|---|---|---|
| self* | `[ebp+8]` → EDI (`8B 7D 08`) | **High** |
| RET 4 | parent push/call without `ADD ESP` | **High** |
| Body size | `0xA5A` to pad | **High** |

---

## 4. Control flow (sealed stages)

| Stage | Match | Conf |
|---|---|---|
| SEH + EDI=self | entry bytes | **High** |
| dt × ±0.005f → progress clamp | decompile + float reads | **High** |
| progress==0 early UI vtbl+4 | decompile | **High** |
| dirty / mid-fade rebuild | decompile | **High** |
| Resize RC list @ `0x00965f47` | call → `0x004611e0` | **High** |
| Mesh loop stride 0xC + strings | decompile | **High** |
| push_back `FUN_00460f90` + RC font | decompile | **High** |
| layout + dirty clear | decompile | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry (32 B): raw W36-N append.  
Resize site `0x00965f47`: `E8 94 B2 AF FF` → `0x004611e0`.  
Terminal `0x00966505`: `E9 C4 F7 FF FF` → epilogue; pad `CC` @ `0x0096650A`.

Globals:

| Addr | Value |
|---|---|
| `0x00aaa9f4` | −0.005f |
| `0x00aaa6a4` | +0.005f (`g_flHardKillInterpolate`) |
| `0x00aaa5dc` | 4294967296.0f |
| `0x00aaa6f8` | 255.0f |
| `0x00a27c24` | 80.0f |

---

## 6. Gaps

- Product/PDB class English.  
- Full UI draw/layout callee duals.  
- Exact mesh-entry struct beyond stride/fields used.  
- Clean is structural, not bit-exact body.  
- Runtime open.

---

## Verdict

**accept-with-gaps** — domain, ABI, fade CF, and RC-list integration sealed; full draw body residual.
