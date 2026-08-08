# Dual A/B report — R10-027 OWN-ONLY (`0x0044f660`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-027**  
**Scope:** VA `0x0044f660` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. parent complete dtor `0x00416110`, setter `0x00416150`).  
**Ghidra:** HTTP `127.0.0.1:8089` — `decompile_function` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs/callees + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-027**.  
**Parent dual:** `0x00416110` `Class_00a9bbe8_CompleteDtor_Inferred` (vftable slot +4 = this VA).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0044f660` Object_GetFieldAtPlus8_Inferred | **accept-with-gaps** — CF/ABI/bytes/xrefs sealed; product field English + universal pointer typing + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-signature / skills-only exclusive / stack-`RET n` / non-leaf claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0044f660` — sealed facts

1. **Body:** `0x0044f660`–`0x0044f663` inclusive (**4 B** / `0x4`); pad `CC` from `0x0044f664` to next leaf `0x0044f670`.
2. **ABI:** **ECX** = `this`; **plain RET** (`C3`); return dword in **EAX**.
3. **Semantics:** thiscall **getter** — `return *(uint32_t*)(this + 8)`.
4. **Classification:** stub / leaf (analyze_function_complete).
5. **Callees:** none.
6. **Callers (2 UNCONDITIONAL_CALL):**
   - `FUN_00641ad0` @ `0x00641b11` — treats return as object*; dispatches `vtbl+0x14(0,0)`.
   - `FUN_00647990` @ `0x00648123` — Havok XML path (`hkobject`/`hkrawdata`); keeps return as context ptr.
7. **DATA xrefs (10 vtable slots):** `00a9bbec` (parent `0x00a9bbe8`+4), `009e34fc`, `00a9a3d8`, `00a6ff98`, `00aa7418`, `00aa6d90`, `00aa245c`, `00aa6d34`, `00aa6c88`, `00aa6050`.
8. **Sibling setter (context):** `0x00416150` — `MOV EAX,[ESP+4]; MOV [ECX+8],EAX; RET 4` (not a Ghidra function; not owned).
9. **Name:** `Object_GetFieldAtPlus8_Inferred` (Ghidra `FUN_0044f660`). Shared multi-vtable leaf → not named after single class; product field English open → `_Inferred`.
10. **Decompile ≡ raw ≡ bytes** for CF; Ghidra meta `undefined FUN(void)` **rejected** in favor of decompiler + bytes.

### Hex seal

```text
8b4108c3
```

### Gaps

- Product / PDB field English for offset +8.  
- Product class names for non-`00a9bbe8` host vtables.  
- Whether every host types +8 as object* (CALL sites yes; DATA-only hosts open).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` | **accept-with-gaps** |

---

## Artifacts written / refreshed

| Kind | Path |
|------|------|
| Raw (+ R10-027 append) | `docs/reconstruction/raw/aa_0044f660_FUN_0044f660.md` |
| Annotated | `docs/reconstruction/raw/aa_0044f660_FUN_0044f660.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_GetFieldAtPlus8_Inferred.cpp` |
| Clean FUN alias | `docs/reconstruction/reconstructed-exact/FUN_0044f660.cpp` |
| Function record FUN | `docs/reconstruction/functions/aa_0044f660_FUN_0044f660.md` |
| Function record named | `docs/reconstruction/functions/aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` |
| This report | `docs/agents/task-dual-ab-0044f660-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0044f660` | Port as **ECX thiscall getter**: `return ReadUInt32(self + 8)`; plain RET. Shared leaf — do not invent product field names; do not treat as skills-abilities exclusive. Pair with setter `0x00416150` where that vtable is used. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00416110` | Parent complete dtor for class `0x00a9bbe8` |
| `0x00416150` | Sibling set `this+8` (`RET 4`) |
| `0x005ffc80` | Empty virtual |
| `0x004320b0` | sd-dtor-style slot |
| `0x0078bc20` | Ctor twin installs vptr `0x00a9bbe8` |
| `0x00641ad0` / `0x00647990` | CALL parents |

---

## Process

- OWN VA only (`0x0044f660`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name (not bare Ghidra paste).  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
