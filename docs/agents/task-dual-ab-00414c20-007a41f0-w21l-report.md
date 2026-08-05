# Dual A/B report — W21-L OWN-ONLY (`aa_00414c20`, `aa_007a41f0`)

**Date:** 2026-07-29  
**Agent:** W21-L OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00414c20`, `0x007a41f0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00414c20` GfxVBHolder_ReplaceAndAllocate | **accept** — holder+4 VB replace (pool/ctor/refcount) + `FUN_0099a8e0` allocate; `ret 0x10` sealed |
| `aa_007a41f0` Rng_Source_ExtractU32 | **accept** — **7 B** `mov eax,[ecx+0x14]; jmp Rng_Mt19937_Extract` sealed |

---

## Sealed facts — `0x00414c20`

1. **ABI:** `__thiscall` on **holder**; **four** stack args; epilogue **`ret 0x10`** (`c2 10 00` @ `0x00414cbe`). Body **`0x00414c20`–`0x00414cc0`** (**161 bytes**).

2. **Pool:** bytes force `mov ecx, DAT_00d218e0` then `FUN_00414cd0` freelist pop (not holder-as-pool).

3. **Construct:** non-null node → `FUN_00999960` (gfxVertexBufferImpl ctor; vtbl **`PTR_FUN_00aa161c`**).

4. **Refcount:** new `+4` ++; if ==1 call **vtbl+4**. Old at **`holder+4`**: `+4` −−; if 0 call **vtbl+8**. Store new at **`holder+4`**.

5. **Allocate:** `FUN_0099a8e0` (this = new VB) — plate **`gfxVertexBufferImpl.cpp`** / `"Failed to Allocate Vertex Buffer"`. **EAX** status returned (decompiler `void` is wrong; callers test `< 0`).

6. **Callers:** 40+ mesh/VB sites including `CVOGTerrainChunk_BuildVertexBuffer`, `CVOGTacArc_InitializeMesh`, `gfxGeometryPiece_Serialize`/`Unserialize`.

7. **Name:** `GfxVBHolder_ReplaceAndAllocate` — role-sealed **INFERRED**. Ghidra: `FUN_00414c20`.

---

## Sealed facts — `0x007a41f0`

1. **ABI:** `__thiscall` on RNG **source**; no stack formals; **tail jump** (no local `ret`). Body **`0x007a41f0`–`0x007a41f7`** (**7 bytes**).

2. **Bytes:** `8B 41 14 E9 38 06 C8 FF` → `mov eax,[ecx+0x14]`; `jmp 0x00424830` (`Rng_Mt19937_Extract`). Rel32 target **Confirmed**.

3. **Layout:** `source+0x14` = `Mt19937State*` (EAX-this for extract). Sibling `FUN_007a4200` uses same field for table fill.

4. **Return:** tempered **uint32** in EAX (extract contract).

5. **Callers (2 only):** `FUN_005e1030`, `FUN_005e1150` (loot catalog roll). **Not** a vector index picker — prior loot notes partially mis-attributed pick math to this VA.

6. **Name:** `Rng_Source_ExtractU32` — role-sealed **INFERRED**. Ghidra: `FUN_007a41f0`.

---

## Gaps

### `00414c20`
1. Product English for four stack formals and holder C++ type.  
2. Freelist slab details (`FUN_00414cd0`) — out of owned scope.  
3. Runtime / bit-exact / differential — open.  
4. Null-new then allocate behavior under OOM — parent-dependent.

### `007a41f0`
1. Product class name of source object / field `+0x14`.  
2. Loot parent index selection formula — out of owned scope.  
3. Runtime stream / differential — open.  
4. Table-buffer path policy vs live extract (`007a4200`).

---

## Files

### `aa_00414c20`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md` |
| Function record | `docs/reconstruction/functions/aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00414c20_FUN_00414c20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxVBHolder_ReplaceAndAllocate.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00414c20.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00414c20_FUN_00414c20.md` |
| Annotated | `docs/reconstruction/raw/aa_00414c20_FUN_00414c20.annotated.md` |
| Scratch | `tmp/a_00414c20.md` |

### `aa_007a41f0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007a41f0_Rng_Source_ExtractU32.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007a41f0_Rng_Source_ExtractU32.md` |
| Function record | `docs/reconstruction/functions/aa_007a41f0_Rng_Source_ExtractU32.md` |
| Scaffold record | `docs/reconstruction/functions/aa_007a41f0_FUN_007a41f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_Source_ExtractU32.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_007a41f0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_007a41f0_FUN_007a41f0.md` |
| Annotated | `docs/reconstruction/raw/aa_007a41f0_FUN_007a41f0.annotated.md` |
| Scratch | `tmp/a_007a41f0.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00414c20-007a41f0-w21l-report.md` |

---

## AutoCore impact

### `00414c20`
- Client graphics only: replacing a holder’s VB requires pool construct + refcount protocol + allocate status check (`< 0` fail).
- Do not invent D3D CreateVertexBuffer in this unit — allocate lives in `FUN_0099a8e0`.
- Server AutoCore typically **omits** this path unless hosting client-parity mesh tooling.

### `007a41f0`
- Port as **one line**: extract MT state from source `+0x14`, call shared `Rng_Mt19937_Extract`.
- Loot roll parents own candidate-list pick math; do **not** fold indexing into this wrapper.
- Corrects earlier loot-review residual that treated this VA as the pick primitive.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
