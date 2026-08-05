# Dual A/B report — W22-R OWN-ONLY (`aa_00436900`, `aa_004e7450`)

**Date:** 2026-07-29  
**Agent:** W22-R OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00436900`, `0x004e7450`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `reviews/WAVE_2026-07-29_wave22_partition_map.md` → W22-R  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00436900` stoChunkReader_ReadU32_ModeDispatch | **accept** — 27 B mode gate on `reader+0x4044` → binary `ReadU32` / text `FUN_007689e0`; EAX status sealed |
| `aa_004e7450` RbTree_InitEmptyHeader | **accept** — 43 B empty tree header: alloc 0x18 node, `+0x15=1`, self-link L/P/R, size 0, return this |

---

## Sealed facts — `0x00436900`

1. **ABI:** reader in **EAX**; out pointer in **ECX** (`push ecx` → stack formal of both callees); plain **`ret`**. Return **EAX** status `0` / `0xffffffff` (decompiler `void` understates).

2. **Body:** `0x00436900`–`0x0043691a` (**27 bytes**).

3. **Mode gate:** `cmp dword [eax+0x4044], 0` — **0 = binary**, ≠0 = **text** (same convention as OpenChunk / PeekChunkTag / f32 readers).

4. **Binary arm:** `push ecx; call FUN_00437050` (`stoChunkReader_ReadU32`, W18-N sealed); `ret`.

5. **Text arm:** `push edi; push ecx; mov edi,eax; call FUN_007689e0; pop edi; ret` — text reader requires reader in **EDI** (plate `stoChunk.cpp` / `"Expected uint32 but got \"%s\"..."`).

6. **Rel32:** `00437050` and `007689e0` **Confirmed** via `read_memory`.

7. **Callers:** `gfxGeometryPiece_Unserialize` (×4), `gfxVertexBufferImpl_Unserialize`, `FUN_0095ef50` (×7), `FUN_00964690`, site `0x0095ffc2`.

8. **Name:** `stoChunkReader_ReadU32_ModeDispatch` — role-sealed **INFERRED**. Ghidra: `FUN_00436900`.

---

## Sealed facts — `0x004e7450`

1. **ABI:** **`__thiscall`** on header (**ECX**); no stack formals; plain **`ret`**; returns **this** in EAX.

2. **Body:** `0x004e7450`–`0x004e747a` (**43 bytes**).

3. **Alloc:** `call FUN_00439770` → sealed `RbTree_AllocEmptyNode_Inferred` (`operator_new(0x18)`). Rel32 **Confirmed**.

4. **Header:** `+4 = node*`; `+8 = size = 0`.

5. **Node:** `+0x15 = 1` (head/nil; factory left 0); left/parent/right **self-linked** (`+0`, `+4`, `+8`).

6. **Role:** empty MSVC-style `_Tree` / RB-tree header init. Complements factory (W18-S noted this caller pattern).

7. **Callers:** `FUN_004d8a10` ×4 (large ctor / Client init chain); additional xrefs `0x009c0a*`.

8. **Sibling (not owned):** `FUN_004e7420` — different node factory + flag at **`+0x19`**.

9. **Name:** `RbTree_InitEmptyHeader` — role-sealed **INFERRED**. Ghidra: `FUN_004e7450`.

---

## Gaps

### `00436900`
1. Product English plate spelling of the dispatch helper (may be `ReadU32` overload in source).  
2. Full text-reader contract (`FUN_007689e0`) — out of owned scope.  
3. Exact product type of non-zero `+0x4044` (bool vs enum).  
4. Runtime / bit-exact / differential — open.

### `004e7450`
1. Product C++ typedef for this 0x18-node map flavor.  
2. Whether `header+0` is a live adjacent field (untouched here).  
3. OOM null-head path (retail stores without null check).  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00436900` | `reviews/A_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` | `reviews/B_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` | **accept** |
| `0x004e7450` | `reviews/A_aa_004e7450_RbTree_InitEmptyHeader.md` | `reviews/B_aa_004e7450_RbTree_InitEmptyHeader.md` | **accept** |

---

## Files

### `aa_00436900`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| Function record | `docs/reconstruction/functions/aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00436900_FUN_00436900.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU32_ModeDispatch.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00436900.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00436900_FUN_00436900.md` |
| Annotated | `docs/reconstruction/raw/aa_00436900_FUN_00436900.annotated.md` |

### `aa_004e7450`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e7450_RbTree_InitEmptyHeader.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e7450_RbTree_InitEmptyHeader.md` |
| Function record | `docs/reconstruction/functions/aa_004e7450_RbTree_InitEmptyHeader.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004e7450_FUN_004e7450.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RbTree_InitEmptyHeader.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e7450.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004e7450_FUN_004e7450.md` |
| Annotated | `docs/reconstruction/raw/aa_004e7450_FUN_004e7450.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00436900-004e7450-w22r-report.md` |

---

## AutoCore impact

### `00436900`
- Chunk unserialize of a single u32 must branch on **mode `reader+0x4044`**, not assume binary-only.
- Port as a thin dispatcher: binary → sealed `stoChunkReader_ReadU32`; text → token/parse peer.
- Preserve **status return** (`< 0` fail); do not treat as void.
- Retail ABI quirk: reader in **EAX**, out in **ECX** (text also needs EDI).

### `004e7450`
- Empty maps of this flavor are **two steps**: `AllocEmptyNode` + this header init (self-link + size 0 + head flag). Do not invent a single combined factory that leaves `+0x15=0`.
- Do not use `FUN_004e7420` offsets (`+0x19`) for this node size.
- Server ports of client maps that use 0x18 sentinels should mirror head self-links or risk empty-iterator bugs.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00437050` | `stoChunkReader_ReadU32` binary peer (W18-N sealed) |
| `0x007689e0` | text-mode uint32 reader (`stoChunk.cpp`) |
| `0x00439770` | `RbTree_AllocEmptyNode_Inferred` (W18-S sealed) |
| `0x004e7420` | sibling empty header with different node factory / `+0x19` |
| `0x004d8a10` | large ctor calling this header init ×4 |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
