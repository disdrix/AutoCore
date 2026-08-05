# Dual A/B report — W27-N OWN `aa_006caaa0` + `aa_0055f4c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-N  
**Scope:** VAs `0x006caaa0`, `0x0055f4c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md` → W27-N  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006caaa0` LinkPair_SortedDiffWalk_Inferred | **accept** — sorted dual-range pair merge CF/ABI sealed |
| `aa_0055f4c0` LocalWorklist_Release_Inferred | **accept** — worklist/arena release CF/ABI + tag-free mask sealed |

---

## VA `0x006caaa0` — sealed facts

1. **Body:** `0x006caaa0`–`0x006cac19` (**378 B**); pad `CC` after `ret 0x14`.
2. **ABI:** **thiscall**; ECX = handler-table; 5 stack formals; **`ret 0x14`**; void.
3. **Semantics:** Two sorted ranges of 8-byte pairs; dual-key compare (`node+4`, `partner+4`); equal skip; right-only handler vcall **+8**; left-only predicate then optional handler vcall **+4**; drain both tails.
4. **Classification:** worker; **no direct FUN_* callees** (indirect only).
5. **Callers:** 6 — `FUN_0055fa40`, `FUN_0055fbf0`, `FUN_0055ff20`, `FUN_00560020`, `FUN_006297e0`, `FUN_00634450`.
6. **Role:** complex multi-entry reconcile for bind/unbind when `*(obj+0x40) != 0` (simple path = `FUN_006297e0` only).
7. **Name:** `LinkPair_SortedDiffWalk_Inferred` (Ghidra `FUN_006caaa0`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for handler-table / pair node types.  
- Predicate object install contract.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006caaa0_FUN_006caaa0.md` |
| Annotated | `docs/reconstruction/raw/aa_006caaa0_FUN_006caaa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LinkPair_SortedDiffWalk_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006caaa0.cpp` |
| Function | `docs/reconstruction/functions/aa_006caaa0_FUN_006caaa0.md` |
| Function named | `docs/reconstruction/functions/aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006caaa0.md` |

---

## VA `0x0055f4c0` — sealed facts

1. **Body:** `0x0055f4c0`–`0x0055f51b` (**92 B**); pad `CC` after `RET`.
2. **ABI:** **__fastcall/thiscall**; ECX = local worklist desc; **plain `ret`**; void.
3. **CF:** aligned size from `desc[+0x10]`; bump `DAT_00b05060` counters **or** vcall `vtbl+0x28`; if `desc[+0x8]>=0` tagged free `vtbl+0x14` with tag **`0x12`** and size **`(count & 0x7fffffff)*8`**.
4. **Callers (5 / 8 xrefs):** `FUN_0055fa40`×2, `FUN_0055fbf0`×2, `FUN_0055ff20`, `FUN_00560020`, `FUN_00634450`×2.
5. **Role:** always-on teardown after bind/unbind worklist use.
6. **Name:** `LocalWorklist_Release_Inferred` (Ghidra `FUN_0055f4c0`).
7. **Decompile ≡ bytes** for CF; clean adds machine `0x7fffffff` mask omitted by decompiler.

### Gaps

- Product English for `DAT_00b05060` allocator.  
- Full stack descriptor map beyond sealed offsets.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055f4c0_LocalWorklist_Release_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055f4c0_LocalWorklist_Release_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055f4c0_FUN_0055f4c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055f4c0_FUN_0055f4c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LocalWorklist_Release_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055f4c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0055f4c0_FUN_0055f4c0.md` |
| Function named | `docs/reconstruction/functions/aa_0055f4c0_LocalWorklist_Release_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055f4c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006caaa0` | Complex bind/unbind must preserve sorted dual-range reconcile (not only `006297e0`). Equal-key skip, right vcall+8, left predicate→vcall+4, and both tails are required for multi-entry objects (`obj+0x40 != 0`). |
| `0055f4c0` | Always release the stack worklist desc after bind/unbind (including early free-path returns). Preserve arena bump vs `vtbl+0x28` and tagged free with **`0x7fffffff` mask** + tag `0x12`. Closes nested residual left open by W26-D/E bind-unbind duals. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.
