# Review A (reconstruction fidelity): `aa_009686e0` GfxBufferedViews_ReleaseDeviceTextures_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009686e0` |
| **VA** | `0x009686e0`–`0x00968715` exclusive (**53 B** / `0x35`) |
| **Canonical name** | `GfxBufferedViews_ReleaseDeviceTextures_Inferred` (was `FUN_009686e0`) |
| **Review date** | `2026-08-04` (W38-AA) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_009686e0_GfxBufferedViews_ReleaseDeviceTextures_Inferred.md` |
| **System** | palantir/graphics — gfxBufferedView list / Device Reset shutdown |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + xrefs/callers/callees + `get_assembly_context` sole call site. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: `GfxDevice_Reset` (W37-N), `GfxBufferedView_Ctor` (W37-I), unowned `FUN_0096c8e0`.

---

## 1. Purpose

**List-level device-texture release** for all registered **gfxBufferedView** instances during **Device Reset shutdown**:

1. Load list head `DAT_00d1ee30`; walk circular nodes.
2. For each non-null payload (`node+0x08`): `tex = *(view+0x44)`.
3. If `*(tex+0x30) == 0`: thiscall `FUN_0096c8e0(tex)`.
4. Return.

Does **not** free views, unlink list nodes, or touch the D3D device directly.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-AA append) | `docs/reconstruction/raw/aa_009686e0_FUN_009686e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009686e0_FUN_009686e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBufferedViews_ReleaseDeviceTextures_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009686e0.cpp` |
| Function records | `functions/aa_009686e0_*.md` |
| Live | decompile ≡ CF; full 53 B hex; call site `0075f0ec` in shutdown chain |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
void GfxBufferedViews_ReleaseDeviceTextures_Inferred(void);
// plain RET (C3); ESI push/pop; callee thiscall ECX=tex
```

| Item | Evidence |
|---|---|
| Formals | none (decompile + no stack args at call site) |
| Cleanup | `C3` |
| Body range | entry `009686e0`, last `C3` @ `00968714` |
| Xrefs | **1** call site |

---

## 4. Control flow (sealed)

```
ECX = DAT_00d1ee30; push ESI
ESI = *ECX
if ESI == ECX: pop ESI; ret
loop:
  EAX = [ESI+8]          ; payload view
  if EAX == 0: goto next
  EAX = [EAX+0x44]       ; texture
  if [EAX+0x30] != 0: goto next
  ECX = EAX; CALL FUN_0096c8e0
  ECX = DAT_00d1ee30     ; reload head
next:
  ESI = *ESI
  if ESI != ECX: loop
pop ESI; ret
```

---

## 5. Gaps (explicit)

- Product English for `view+0x44` and `tex+0x30`.
- Nested `FUN_0096c8e0` not dual-owned here (W38-AB).
- Runtime / bit-exact / differential.

---

## 6. Verdict rationale

**accept-with-gaps:** Body bounds, list walk, thiscall release gate, and sole `GfxDevice_Reset` shutdown placement are sealed from decompile+bytes+call-site context. Residual gaps are nested helper English and field names — not ABI/CF.
