# Dual A/B report — W30-P OWN `aa_0040d5b0` + `aa_004be2a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-P  
**Scope:** VAs `0x0040d5b0`, `0x004be2a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` (W30-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d5b0` StdTree_Clear_PtrVal_Vtbl0C | **accept-with-gaps** — value-loop + free-loop bytes + Val12/ABI sealed; product T / nested free residual |
| `aa_004be2a0` ListTrackedObj_CompleteDtor | **accept-with-gaps** — complete-dtor CF/ABI/offsets/base vtbl sealed; product class + nested members open |

---

## VA `0x0040d5b0` — sealed facts

1. **Body:** `0x0040d5b0`–`0x0040d62a` (**123 B** / `0x7B`; pad `CC` then `FUN_0040d630`).
2. **ABI:** **ECX=`this`**; bare **`RET`** (`C3`); void. Ghidra `__fastcall` ≡ thiscall ECX.
3. **Semantics:** MSVC-style **`_Tree` clear** on Val12 host (`head@+0x08`, `size@+0x0c`, isnil@`+0x19`):
   - For each in-order node: thiscall **`vtbl[+0x0c]`** on **`T*`** at `node+0x14` (no `operator_delete` on `T*`).
   - Advance with sealed **`StdTree_Inc_Val12`** (`0x005ae0b0`, W28-N).
   - Free all non-nil nodes: **`FUN_0040d630(right)`** then `operator_delete(node)` walking **left** (bytes; decompiler false-noreturn collapsed free path).
   - Reset empty sentinel: parent/left/right = head; size = 0.
4. **Classification:** worker.
5. **Callers:** `FUN_0040d820` @ `0x0040d84b` (host complete dtor after `PTR_FUN_009c7938` install); DATA vtbl slot2 @ `0x009c7940`.
6. **Callees:** `FUN_005ae0b0`, `FUN_0040d630`, `operator_delete`.
7. **Name:** `StdTree_Clear_PtrVal_Vtbl0C` (Ghidra `FUN_0040d5b0`; **Inferred** structural).
8. **Decompile ≡ bytes** for value-destroy loop + empty reset; **bytes win** on free path.  
   Full hex: raw W30-P append (123 B).

### Gaps

- Product/MSVC demangle for map T and vtbl[+0xc] method English.  
- Nested free helper `FUN_0040d630` (not owned).  
- Host class full product plate (`PTR_FUN_009c7938` parent).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d5b0_FUN_0040d5b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d5b0_FUN_0040d5b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Clear_PtrVal_Vtbl0C.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d5b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d5b0_FUN_0040d5b0.md` |
| Function named | `docs/reconstruction/functions/aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d5b0.md` |

---

## VA `0x004be2a0` — sealed facts

1. **Body:** `0x004be2a0`–`0x004be43c` exclusive (**412 B** / `0x19C`; pad `CC`).
2. **ABI:** **ECX=`this`**; SEH `LAB_009a1833`; EH state starts **9**; epilogue **`ADD ESP,0x10; RET`**. Complete dtor — **does not** free `this`.
3. **Semantics:**
   - If flag@`+0x5D0`: list-region cleanup then **`FUN_004bf740(this+0x10)`**.
   - **`DAT_00b03734--`**; intrusive DLL unlink via `+0/+4`.
   - **`DAT_00b0373c--`**; if 0, complete-dtor + `operator_delete` on global **`DAT_00b03730`** (self-recursive) and null it; clamp negative to 0.
   - Free buffer triples @`+0x58C` and @`+0x57C` (begin/end/cap).
   - Member dtors: `FUN_0074b580` @ `+0x474/+0x444/+0x414` (empty stubs); `FUN_00763f60` @ `+0x2C8/+0x17C/+0x30`.
   - Install base **`PTR_LAB_009cb5cc`** at **`+0x20` and `+0x10`**.
4. **Classification:** worker (complete dtor body).
5. **Callers:** `FUN_00494700`, `FUN_00494530`, `FUN_00497a30`, `FUN_005b8000` (Elem0x28 owned@+0x24), self.
6. **Callees:** `operator_delete`, `FUN_004bf740`, self, `FUN_0074b580`×3, `FUN_00763f60`×3.
7. **Name:** `ListTrackedObj_CompleteDtor` (Ghidra `FUN_004be2a0`; **Inferred**). Reject scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` plate.
8. **Decompile ≡ bytes** for stage order; false noreturn on `operator_delete` ignored (full hex reaches epilogue).  
   Full hex: raw W30-P append (412 B).

### Gaps

- Product/MSVC demangle for class.  
- Flag-path nested blob English.  
- Nested `FUN_00763f60` / `FUN_004bf740` product types.  
- Dual global counter product meaning.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004be2a0_ListTrackedObj_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004be2a0_ListTrackedObj_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004be2a0_FUN_004be2a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004be2a0_FUN_004be2a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ListTrackedObj_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004be2a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004be2a0_FUN_004be2a0.md` |
| Function named | `docs/reconstruction/functions/aa_004be2a0_ListTrackedObj_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_004be2a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d5b0` | Port as **tree clear**: destroy each pointer value via **vtbl[3]**, then free nodes (right-subtree helper + left walk), reset sentinel. Do **not** `delete` the `T*` here. Use sealed `StdTree_Inc_Val12` for ++. Ignore Ghidra noreturn on first node free. |
| `004be2a0` | Port as **complete dtor only** for list-tracked owned objects. Callers must `operator_delete` separately (Elem0x28@+0x24 path, grid cells). Preserve global counts + DLL unlink + dual base vtbl `009cb5cc` @ +0x10/+0x20. Closes owned-dtor residual named in W29-F. |
| Pair with | `StdTree_Inc_Val12` (`0x005ae0b0`), parent host dtor `FUN_0040d820` / scalar `FUN_0040d590`, `Elem0x28_CompleteDtor` (`0x005b8000`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected VOG_DEBUG_STOP scaffold alias for `004be2a0`.
