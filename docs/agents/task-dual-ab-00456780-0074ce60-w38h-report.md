# Dual A/B report — W38-H OWN `aa_00456780` + `aa_0074ce60`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-H  
**Scope:** VAs `0x00456780`, `0x0074ce60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00456780` StdVector_DwordResize_EcxCount_EdxVec_Inferred | **accept** — EDX=vec / ECX=n / stack fill / RET 4 / dword grow+shrink sealed |
| `aa_0074ce60` phyBoundingBox_Unserialize | **accept** — ECX=bbox / EBX=reader / tag `'BBOX'` / v1–v2 / return 0|-1 sealed |

---

## VA `0x00456780` — sealed facts

1. **Body:** `0x00456780`–`0x004567f5` exclusive (**117 B** / `0x75`; pad `CC` then next).
2. **ABI:** **EDX=`vec*`**, **ECX=`newCount`**, stack **`fill`** (dword); **`RET 4`**. Decompiler `__fastcall(uint,int)` omits fill and collapses grow args — **bytes win**.
3. **Semantics:** MSVC-style **`vector<uint32_t>::resize(n, value)`**:
   - `size = begin(+4) ? (end(+8)−begin)>>2 : 0`.
   - Grow: `FUN_00456960` InsertN with count `n−size`, `&fill`, end, EDX=vec.
   - Shrink: `FUN_00456660(vec, begin+n*4, end)` memmove-publish.
   - Equal / empty: no-op.
4. **Classification:** worker.
5. **Callers (35 fn; 58 xrefs):** includes **`FUN_00986070`** PoolHost_Acquire0x40 freelist shrink, `FUN_00765740`, `FUN_00466580`, many physics/asset/list hosts (full list in function record).
6. **Callees:** `FUN_00456960` (InsertN/grow), `FUN_00456660` (erase/shrink).
7. **Name:** `StdVector_DwordResize_EcxCount_EdxVec_Inferred` (Ghidra `FUN_00456780`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxBody_00456780`.
8. **Twin family (do not merge):**
   - `FUN_0044a380` — ECX=vec, **EAX=n**, fill, RET 4 (W37-Z)
   - `FUN_004367f0` — stack n + fill, **RET 8**
9. **Decompile vs bytes:** CF skeleton ≡ raw; **bytes win** on fill formal, grow count, RET 4.  
   Full hex: raw W38-H append (117 B).

### Gaps

- Product/PDB STL mangled English.  
- Unowned grow/shrink callee duals.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00456780_FUN_00456780.md` |
| Annotated | `docs/reconstruction/raw/aa_00456780_FUN_00456780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordResize_EcxCount_EdxVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00456780.cpp` |
| Function | `docs/reconstruction/functions/aa_00456780_FUN_00456780.md` |
| Function named | `docs/reconstruction/functions/aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` |

---

## VA `0x0074ce60` — sealed facts

1. **Body:** `0x0074ce60`–`0x0074d0b4` exclusive (**596 B** / `0x254`; pad `CC` then next).
2. **ABI:** **ECX=`phyBoundingBox*`**, **EBX=`stoChunkReader*`** (chunk convention); **int** return 0/−1; SEH `LAB_009b1ab3`; frame `SUB ESP,0x18` + ESI/EBX; teardown `ADD ESP,0x24; RET`.
3. **Semantics:** **phyBoundingBox unserialize** (`phyBoundingBox.cpp`):
   - Tag **`'BBOX'`** = `0x42424F58`.
   - Versions **1** and **2** only; else log + −1.
   - Three `stoChunkReader_readF32Array` (EAX=3) → `+0x00`, `+0x14`, `+0x20`; f32 `@+0x0C`; extent `@+0x10` = `abs(sqrt(dx²+dz²))` from A.xz vs C.xz.
   - v1: derive bool `@+0x2C` from scalar≤0; v2: stream-read bool first.
   - Binary/text via reader `+0x4044`; success from reader `+0x402c`.
4. **Classification:** worker.
5. **Callers (5):** `gfxGeometryPiece_Unserialize` @ `0x0074b0c0`; `FUN_00765740` @ `0x007658b5`; `FUN_0095ef50`; `FUN_0095f560`; `FUN_00960f80`. **17** xrefs.
6. **Callees:** `stoChunkReader_EnterChunkScope`, `stoChunkReader_readF32Array`, `FUN_00435fe0`, `FUN_00767fd0`, `FUN_00437000`, `FUN_00769660`, `FUN_00769e40`, `vog_LogMessage`.
7. **Name:** `phyBoundingBox_Unserialize` (Ghidra `FUN_0074ce60`; **High** from path + strings). **Reject** sole “post-effect/vertex hook” identity (gfx piece is one caller).
8. **Decompile vs bytes:** CF ≡ raw for tag/version/error/SEH; **bytes/LEA win** on array destinations and xz-only extent.  
   Body span sealed by final `C3` @ `0x0074d0b3`.

### Gaps

- Float3 product English (min/max/center labels).  
- Full SEH path bit-exact.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074ce60_phyBoundingBox_Unserialize.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0074ce60_phyBoundingBox_Unserialize.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074ce60_FUN_0074ce60.md` |
| Annotated | `docs/reconstruction/raw/aa_0074ce60_FUN_0074ce60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBoundingBox_Unserialize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074ce60.cpp` |
| Function | `docs/reconstruction/functions/aa_0074ce60_FUN_0074ce60.md` |
| Function named | `docs/reconstruction/functions/aa_0074ce60_phyBoundingBox_Unserialize.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00456780` | Port as **dword vector resize**: **EDX=vec**, **ECX=n**, stack **fill**, **RET 4**. begin@+4 end@+8 stride 4. Do **not** use `FUN_0044a380` (EAX-count) or `FUN_004367f0` (`RET 8`) ABI. Critical under pool freelist pop (`00986070`) and many physics vector trims. |
| `0074ce60` | Port as **phyBoundingBox chunk unserialize**: ECX=bbox, EBX=reader, tag `'BBOX'`, v1/v2, return 0/−1. Recompute xz extent at +0x10; do not assume 3D radius. gfxGeometryPiece embeds bbox @ piece+0x24. |
| Shared | Unrelated domains (container vs physics serialize); co-owned only as W38-H partition pair. Note `FUN_00765740` calls **both** (bbox unserialize + dword resize) — pair meets under physics asset load. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0044a380` | StdVector_DwordResize_EaxCount (W37-Z) — different register ABI |
| `0x004367f0` | StdVector_DwordResize stack-count / RET 8 twin |
| `0x00456960` | InsertN / grow for this resize |
| `0x00456660` | Erase-range shrink for this resize |
| `0x00986070` | PoolHost_Acquire0x40 (W33-R) — freelist shrink caller |
| `0x00436090` | stoChunkReader_readF32Array |
| `0x004370b0` | stoChunkReader_EnterChunkScope |
| `0x00435fe0` | Binary f32 read |
| `0x00767fd0` | Text f32 read |
| `0x00437000` | Binary u8/bool read |
| `0x00769660` | Text bool read (W38-J peer) |
| `0x00769e40` | Leave chunk scope |
| `0x0074af60` | gfxGeometryPiece_Unserialize — bbox field caller |
| `0x00765740` | Physics asset path calling both OWN units |

Closes W38-H OWN pair: multi-host dword **resize** helper (ECX-count/EDX-vec) + physics **phyBoundingBox** chunk unserialize left open under pool/ freelist and sto-chunk geometry/physics paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural name for resize; product-anchored name for phyBoundingBox.  
- Rejected long Named_CalleeOf scaffold alias on resize.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Distinguished EDX/ECX resize from EAX-count and stack-count twins.  
- Distinguished v1 bool-from-scalar vs v2 stream bool; xz-only extent.  
- Terminal coverage: **false** always.
