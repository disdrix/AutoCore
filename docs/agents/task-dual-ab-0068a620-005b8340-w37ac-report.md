# Dual A/B report — W37-AC OWN `aa_0068a620` + `aa_005b8340`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-AC  
**Scope:** VAs `0x0068a620`, `0x005b8340` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` + callers/callees/xrefs (+ parent call-site context only). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-AC).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0068a620` StdVector_InsertOne_RebindIt_Elem28 | **accept-with-gaps** — insert-one ABI/CF/stride/rebind sealed; product T English open |
| `aa_005b8340` CircularListHead_ClearFreeNodes_Inferred | **accept-with-gaps** — re-ring + free-loop sealed (bytes win over decompile); product node type open |

**Terminal coverage:** false (wave policy; no runtime/diff/bit-exact Confirmed).

---

## VA `0x0068a620` — sealed facts

1. **Body:** `0x0068a620`–`0x0068a68a` exclusive (**106 B** / `0x6A`; pad `CC`).
2. **ABI:** **ECX=`vector*`**; stack **`outIt*`**, **`where*`**, **`value*`**; **`RET 0x0C`** (`C2 0C 00`); void.
3. **Semantics:** MSVC-style **insert-one + rebind** for **POD T size 0x1c**:
   - `index = 0` if `begin==0` or size `(end-begin)/0x1c == 0`; else `index = (where-begin)/0x1c` (magic `0x92492493`).
   - `FUN_0068a1d0(where, count=1, value)` — thiscall vec (`StdVector_InsertN_Elem28`, W34-S).
   - `*outIt = begin' + index*0x1c` (re-read begin after possible realloc).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0068ae50` @ `0x0068aecd` (capacity-full push_back slow path; fast path fills at end without this unit).
6. **Callees:** `FUN_0068a1d0` only.
7. **Name:** `StdVector_InsertOne_RebindIt_Elem28` (Ghidra `FUN_0068a620`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_*`. Family twin of dword/0x1c InsertOne_RebindIt units with different InsertN ABIs.
8. **Decompile ≡ CF**; bytes seal `6A 01`, `/0x1c`, `C2 0C 00`; value formal is **pointer** (not lone dword).  
   Full hex: raw W37-AC append (106 B).

### Gaps

- Product English for POD `T`.  
- Caller `FUN_0068ae50` dual not OWN.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0068a620_StdVector_InsertOne_RebindIt_Elem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0068a620_StdVector_InsertOne_RebindIt_Elem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0068a620_FUN_0068a620.md` |
| Annotated | `docs/reconstruction/raw/aa_0068a620_FUN_0068a620.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0068a620.cpp` |
| Function | `docs/reconstruction/functions/aa_0068a620_FUN_0068a620.md` |
| Function named | `docs/reconstruction/functions/aa_0068a620_StdVector_InsertOne_RebindIt_Elem28.md` |

---

## VA `0x005b8340` — sealed facts

1. **Body:** `0x005b8340`–`0x005b8369` exclusive (**41 B** / `0x29`; pad `CC`).
2. **ABI:** **ECX = circular list head/sentinel**; no stack args; bare **`C3`**; void.
3. **Semantics:** **Clear free-all non-head nodes**:
   - Save `first = [head+4]`.
   - Re-ring empty circular: `[head+4] = head`, `[head+0] = head`.
   - If `first==0` or `first==head`: return.
   - Else loop: `next = [node+4]`; `operator_delete(node)` cdecl; continue until `node==head`.
4. **Decompile gap (critical):** Ghidra marks `operator_delete` **noreturn** → free-loop **collapsed** to one delete. **Bytes restore** loop (`83 C4 04` / `75 EE`).
5. **Not** `StdList_Clear` (`0x00404060`): here ECX **is** the sentinel (no `_Myhead` indirection); **no** size field zeroed.
6. **Classification:** worker (shared list clear).
7. **Callers (5 fn / 15 sites):** `FUN_004ba0a0` (3), `FUN_00593e10` (3), `FUN_00594030` (3), `FUN_005b85e0` (1), `FUN_005bbc50` (5) — ObjectMotion / NDSpecialFX / host teardown paths clear host- and buffer-embedded heads.
8. **Callees:** `operator_delete` @ `0x00489822` only.
9. **Name:** `CircularListHead_ClearFreeNodes_Inferred` (Ghidra `FUN_005b8340`; **Inferred**). **Reject** scaffold Mission-complete-audio callee-of plate.
10. **Decompile ≢ free-loop**; **bytes win**.  
    Full hex: raw W37-AC append (41 B).

### Gaps

- Product node payload type / size beyond 8-byte link header.  
- prev/next English labels for `+0` vs `+4` (walk uses `+4`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b8340_CircularListHead_ClearFreeNodes_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b8340_CircularListHead_ClearFreeNodes_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b8340_FUN_005b8340.md` |
| Annotated | `docs/reconstruction/raw/aa_005b8340_FUN_005b8340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CircularListHead_ClearFreeNodes_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b8340.cpp` |
| Function | `docs/reconstruction/functions/aa_005b8340_FUN_005b8340.md` |
| Function named | `docs/reconstruction/functions/aa_005b8340_CircularListHead_ClearFreeNodes_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0068a620` | Port as **`vector<POD0x1c>::insert(where, value)` with out-iterator rebind**. ECX=vec; stack outIt/where/value; **`RET 0x0C`**. Always count=1 into `StdVector_InsertN_Elem28`. Do **not** unify with basic_string insert-one or dword-stride twins without matching InsertN. |
| `005b8340` | Port as **circular head clear**: re-ring links, free all other nodes with bare `operator_delete`, keep head. Do **not** trust decompile single-free. Do **not** free head. Do **not** assume size field. Used for host- and buffer-embedded list heads in motion/FX teardown. |
| Pair with | W34-S `StdVector_InsertN_Elem28` (`0x0068a1d0`); W30-S `ObjectMotion_HostTeardown` (`0x005bbc50`); W27-D `NDSpecialFX_StopFinalize` (`0x004ba0a0`); sibling clears `0x00404060` / `0x004bf740` (different shapes). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + parent context for ABI only. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-AC sections).  
- No invented product plates; `_Inferred` / structural names from sealed CF + family twins.  
- Rejected scaffold Named_CalleeOf / Mission plates.  
- Avoided bare `undefined4` as sole clean surface (`uint32_t` / `Elem28` / `CircularListHead`).  
- Terminal full coverage remains **false**.
