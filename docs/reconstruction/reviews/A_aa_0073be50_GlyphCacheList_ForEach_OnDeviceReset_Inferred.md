# Review A (reconstruction fidelity): `aa_0073be50` GlyphCacheList_ForEach_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073be50` |
| **VA** | `0x0073be50`–`0x0073be74` exclusive (**36 B** / `0x24`) |
| **Canonical name** | `GlyphCacheList_ForEach_OnDeviceReset_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0073be50` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-U) |
| **Counterpart** | `reviews/B_aa_0073be50_GlyphCacheList_ForEach_OnDeviceReset_Inferred.md` |
| **System** | graphics / GlyphCache device-reset broadcast |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (36 B full) + `analyze_function_complete` + sole xref + `get_assembly_context` + callee `FUN_00755820` decompile + parent `FUN_0075eff0` GfxDevice_Reset + W37-AE GlyphCache node+0x2c. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk the circular list at `container+8` and invoke `FUN_00755820` on each node's payload at `+0x2c` (GlyphCache*). Sole caller is GfxDevice_Reset success path after factories re-init — broadcast device-reset to all glyph caches.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-U append) | `docs/reconstruction/raw/aa_0073be50_FUN_0073be50.md` |
| Annotated | `docs/reconstruction/raw/aa_0073be50_FUN_0073be50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCacheList_ForEach_OnDeviceReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073be50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0073be50_FUN_0073be50.md` |
| Named record | `docs/reconstruction/functions/aa_0073be50_GlyphCacheList_ForEach_OnDeviceReset_Inferred.md` |
| Live | 36 B hex; EBX/ESI ABI; sole Reset site |
| Callee | `FUN_00755820` decompile (ESI GlyphCache rebuild) |
| Sibling | W37-AE `GlyphCache_GetOrCreate` node+0x2c |

**Not performed:** Launcher, runtime, ledgers. Full dual of `00755820` out of OWN scope.

---

## 3. Signature (sealed)

```c
// EBX = container*; no stack formals; returns 0; plain RET
// Callee: ESI = *(node+0x2c)
uint32_t GlyphCacheList_ForEach_OnDeviceReset_Inferred(void* container /*EBX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EBX** (`MOV EAX,[EBX+8]`) | **High** |
| payload | **ESI** = `[EDI+0x2C]` before CALL | **High** |
| return | **0** (`XOR EAX,EAX`) | **High** |
| cleanup | plain **`RET`** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
sentinel = *(EBX+8)
node = *sentinel
if node == sentinel: return 0
loop:
  ESI = *(node+0x2c)
  CALL FUN_00755820
  node = *node
  if node != *(EBX+8): loop
return 0
```

---

## 5. Cross-check vs caller

GfxDevice_Reset (`FUN_0075eff0`) success path @ `0x0075f36d`:

```text
MOV EBX, dword ptr [EBP + 0x758]   ; device+0x758 manager
CALL 0x0073be50
LEA EAX, [EBP + 0x2b8]             ; copy present params back…
```

Preceded by factory Reset helpers and `FUN_00968680`. Domain: device-dependent resource rebuild after `IDirect3DDevice9::Reset`.

---

## 6. Name

`GlyphCacheList_ForEach_OnDeviceReset_Inferred` — structural walk + Reset site + GlyphCache payload family. Scaffold `Named_CalleeOf_Named_gfxDevice_*` rejected.

---

## 7. Gaps (accepted)

- Product class name for manager at `device+0x758`.
- Full plate of unowned `FUN_00755820` / `FUN_00755100`.
- Whether list is NestedHash intrusive chain vs dedicated registry.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
