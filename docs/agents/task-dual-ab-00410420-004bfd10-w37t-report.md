# Dual A/B report — W37-T OWN `aa_00410420` + `aa_004bfd10`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-T  
**Scope:** VAs `0x00410420`, `0x004bfd10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-T).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00410420` StdVector_DwordResize_ViaInsertN_004073a0 | **accept** — dword vector resize; grow via `004073a0`, shrink via `00410490`; `ret 8`; 105 B sealed |
| `aa_004bfd10` TrackMgr_9CircList_UntrackObject_Inferred | **accept-with-gaps** — 9-bucket circular list remove-by-match; decompiler no-return on `operator_delete` **falsified**; product manager English open |

---

## VA `0x00410420` — sealed facts

1. **Body:** `0x00410420`–`0x00410488` inclusive (**105 B** / `0x69`); pad `CC`×7 then sibling erase `FUN_00410490` @ `0x00410490`.
2. **ABI:** **`__thiscall`**; ECX = vector control (`begin@+4`, `end@+8`); stack **`(newCount, fillValue)`**; void; **`ret 8`** (`c2 08 00` on both grow and shrink exits).
3. **Semantics:** MSVC-style **`vector<uint32_t>` resize** (same control flow as sealed twin `FUN_004367f0` / `StdVector_DwordResize`):
   - `size = (begin==0) ? 0 : (end-begin)>>2`
   - **Grow** (`size < newCount`): `FUN_004073a0(end, newCount-size, &fillValue)` then return
   - **Shrink** (`begin!=0 && newCount < size`): `FUN_00410490(&out, begin+newCount*4, end)`
   - **Equal size:** no-op
4. **Twin distinction:** `004367f0` grows via `FUN_004507a0`; this unit grows via **`FUN_004073a0`** (`StdVector_InsertN_Dword`-family). Shared shrink: sealed `StdVector_EraseRange_Dword_Inferred` (`0x00410490`).
5. **Classification:** multi-domain worker leaf (30 CODE xrefs / 21 caller funcs).
6. **Callers (sample):** clear paths with `push 0; push 0; lea ecx,[obj+off]; call` — e.g. `FUN_004bbeb0` @ `+0x48/+0x28/+0x38` (W31-N), `FUN_00496410`/`00496600`/`00496810`/`00496920`, `FUN_005e7600`, `FUN_0068e710`, UI/gfx hosts, etc.
7. **Callees:** `FUN_004073a0` (grow insert-N), `FUN_00410490` (shrink erase-range).
8. **Name:** `StdVector_DwordResize_ViaInsertN_004073a0` (Ghidra `FUN_00410420`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxGeometryPiece_*`.
9. **Decompile ≡ bytes** for CF/ABI; fill third-arg via grow `lea … &stack fill`. Full hex in raw W37-T append.

### Gaps

- Product/MSVC demangle (`vector::resize`).  
- Why two near-identical resize clones (`004073a0` vs `004507a0` grow engines).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00410420_FUN_00410420.md` |
| Annotated | `docs/reconstruction/raw/aa_00410420_FUN_00410420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordResize_ViaInsertN_004073a0.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00410420.cpp` |
| Function | `docs/reconstruction/functions/aa_00410420_FUN_00410420.md` |
| Function named | `docs/reconstruction/functions/aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md` |

---

## VA `0x004bfd10` — sealed facts

1. **Body:** `0x004bfd10`–`0x004bfda1` inclusive (**146 B** / `0x92`); pad `CC` then sibling finder `FUN_004bfdb0` @ `0x004bfdb0` (set payload`+0x51` on match; not OWN).
2. **ABI:** **`__thiscall`**; ECX = **track manager**; stack **`(object*)`**; returns **`uint8`/`bool`** success (**1** removed / **0** not found); **`ret 4`** (`c2 04 00`).
3. **Semantics:** Scan **9** circular doubly-linked list buckets starting at **`this+8`**, stride **`0xC`** each:
   - Bucket layout: **`head@+0`** (sentinel), **`count@+4`** (skip if 0), third dword unused here.
   - Walk `for (n = head->next; n != head; n = n->next)`.
   - Node: `{ next@+0, prev@+4, payload*@+8 }`.
   - Match: `FUN_005c6720(payload, object)` — identity / TFID-style compare (not OWN).
   - On match (primary path): unlink node; `operator_delete(node)`; **`count--`**; if payload non-null, **scalar-deleting dtor** `payload->vtbl[0](1)`; return **1**.
   - Special path if `node == head` pointer: destroy payload only, return 1 (no unlink/count). Under normal circular-sentinel walk this is **unreachable**; treat as defensive.
   - Exhaust buckets → return **0**.
4. **Decompiler pitfall:** Ghidra marks `operator_delete` as **noreturn** and drops post-delete CF — **bytes win**: `add esp,4; add [count],-1; optional vtbl dtor; mov al,1; ret 4`.
5. **Classification:** worker (manager untrack helper).
6. **Callers (5 funcs / 8 sites):**
   - `Object_UnloadGraphics_Inferred` (`0x005825d0`, W31-T) — manager = `*(*(host_via_vb+0xA8)+0xE914)`, arg = MI this (**bytes sealed**).
   - `FUN_00854d20`, `FUN_00855810`, `FUN_00856380`, `FUN_008d80c0` (×4) — same pattern: load mgr from host`+0xE914`, push object identity from `vtbl+0x1cc` or object ptr.
7. **Callees:** `FUN_005c6720` (match), `operator_delete`, virtual scalar-deleting dtor on payload.
8. **Name:** `TrackMgr_9CircList_UntrackObject_Inferred` (Ghidra `FUN_004bfd10`; **Inferred** from structure + UnloadGraphics parent). **Reject** scaffold `Named_CalleeOf_…Skill…`.
9. **Decompile CF spine OK** except post-`delete` / return-type; machine seals ABI and destroy tail. Full hex in raw W37-T append.

### Gaps

- Product class name for manager at host`+0xE914`.  
- Payload type / what `vtbl[0](1)` frees (graphics track entry).  
- Meaning of 9 buckets (layers / types).  
- Sibling `004bfdb0` product English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bfd10_FUN_004bfd10.md` |
| Annotated | `docs/reconstruction/raw/aa_004bfd10_FUN_004bfd10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TrackMgr_9CircList_UntrackObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bfd10.cpp` |
| Function | `docs/reconstruction/functions/aa_004bfd10_FUN_004bfd10.md` |
| Function named | `docs/reconstruction/functions/aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00410420` | Port as **`vector<uint32_t>::resize(n, fill)`** on MSVC 3-pointer vector (`begin+4`/`end+8`). Grow = insert-N at end via existing insert engine (`004073a0`); shrink = erase `[n, end)` via `00410490` (no element dtors). **Do not** unify with twin `004367f0` if grow engines differ in capacity policy. Callers often `resize(0,0)` to clear. |
| `004bfd10` | Port as **manager untrack**: walk 9 circular lists; match object via `005c6720`; unlink list node; free node; `count--`; owning-delete payload. Return bool. Used first in `Object_UnloadGraphics` before graphics teardown. Prefer **bytes** over decompiler for post-delete path. |
| Shared | Unrelated domains (STL resize utility vs graphics/object track manager). Co-owned only by W37-T partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004073a0` | Grow insert-N for dword vectors |
| `0x00410490` | `StdVector_EraseRange_Dword_Inferred` (W16-S sealed) |
| `0x004367f0` | Twin resize using grow `004507a0` |
| `0x005c6720` | Object/payload identity match predicate |
| `0x005825d0` | `Object_UnloadGraphics_Inferred` (W31-T) — primary consumer of untrack |
| `0x004bfdb0` | Sibling 9-bucket find + set `payload+0x51` |

Closes W37-T OWN pair: dword-vector resize clone (via insert-N `004073a0`) + 9-bucket track-manager untrack used by unload-graphics.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
