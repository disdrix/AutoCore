# Dual A/B report — W38-A OWN `aa_0043d570` + `aa_0043e750`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-A  
**Scope:** VAs `0x0043d570`, `0x0043e750` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-A).  
**Terminal coverage claim:** **false** (agent reports never claim terminal bar complete).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d570` StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred | **accept-with-gaps** — EDI/EDX register ABI + Val12 op[] + 112 B sealed; insert-helper English residual |
| `aa_0043e750` GuardedVector_TryPopFront_Stride8_OutPair_Inferred | **accept-with-gaps** — ESI/EDI + stride-8 try-pop + CS gate + 146 B sealed; product pair English residual |

---

## VA `0x0043d570` — sealed facts

1. **Body:** `0x0043d570`–`0x0043d5e0` exclusive (**112 B** / `0x70`; hit epilogue `8D 46 10 5E 83 C4 18 C3`; miss `8B 00 83 C0 10 5E 83 C4 18 C3`). Next function is leaf find `FUN_0043d5e0`.
2. **ABI:** **EDI=map*** (`MOV ECX,[EDI+4]`); **EDX=`const uint32_t* key`**; returns **mapped*** at node+`0x10` in **EAX**; plain **`RET`** (`C3`). No stack formals. Bytes win over decompiler `__fastcall param_1` / `unaff_EDI` phantoms.
3. **Semantics:** MSVC-style **`_Tree` operator[]** get-or-insert on Val12 nodes:
   - `head = *(map+4)`; root = `head->parent`.
   - Walk: if `node.key < *key` go right else remember + go left; stop on **isnil@`+0x19`**.
   - Gate: `cand != head && *key >= cand.key` → hit return `cand+0x10`.
   - Miss: stage `{*key,0,0}` via **`FUN_0043c8b0`**; insert-hint **`FUN_0043d7d0`**; return `*it+0x10`.
4. **Layout:** L`+0` / P`+4` / R`+8` / key-u32`+0x0C` / mapped`+0x10` / isnil`+0x19` (Val12 family).
5. **Classification:** **worker** (mutates on miss).
6. **Callers (3):** `FUN_00970bb0` @ `00970bc7`; `AssPreloader_DrainSuccessResultsAndTally_Inferred` (`00971480`) @ `0097156b`; `FUN_00971ea0` @ `009720db`.
7. **Name:** `StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred` (Ghidra `FUN_0043d570`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_assPreloader_0043d570`. Peer W37-Q `0043bd40` is same algorithm with **ECX/EAX** ABI.
8. **Decompile ≡ bytes** for full CF; **bytes win** on register ABI.  
   Full hex: `8b4f048b410483ec1880781900568bf175168b0a39480c73058b4008eb048bf08b008078190074ec3b770474078b023b460c73340f57c08d4c24088d442410c744240800000000f30f1144240ce8eef2ffff568d7424088bcfe8020200008b0083c0105e83c418c38d46105e83c418c3`

### Gaps

- Unowned insert helpers `0043c8b0` / `0043d7d0` full formal ABI.  
- Product/PDB map / value_type English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d570_FUN_0043d570.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d570_FUN_0043d570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d570.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d570_FUN_0043d570.md` |
| Function named | `docs/reconstruction/functions/aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` |

---

## VA `0x0043e750` — sealed facts

1. **Body:** `0x0043e750`–`0x0043e7e2` exclusive (**146 B** / `0x92`; success `B0 01 5D C3`; empty `32 C0 5D C3`; pad `CC`).
2. **ABI:** **ESI=`GuardedVectorHeader*`**; **EDI=`uint32_t out[2]`**; returns **AL** 1=popped / 0=empty; plain **`RET`**. No stack formals. Bytes win over `unaff_ESI` / `unaff_EDI`.
3. **Semantics:** Optional-CS **try pop_front** of **stride-8** ring element:
   - If lockEnable@`+0x2c`: `EnterCriticalSection(+0x14)`.
   - If size@`+0x10` == 0: Leave if locked; return 0.
   - Front slot: `pageIdx = begin>>1` (subtract capacity if `pageIdx >= cap`); `slot = begin&1`; `slotp = pages[pageIdx] + slot*8`.
   - If `EDI != slotp`: copy first dword; **always** copy second dword.
   - `begin++`; wrap when `begin >= capacity*2`; `size--`; empty → `begin=0`.
   - Leave if locked; return 1.
4. **Header:** pages`+4` / cap`+8` / begin`+0xC` / size`+0x10` / CS`+0x14` / lockEnable`+0x2c` (GuardedVector family).
5. **Classification:** **worker**.
6. **Callers (1 fn, 2 sites):** `AssPreloader_DrainSuccessResultsAndTally_Inferred` (`00971480`) @ `009714b7`, `009715a3` on **`host+0x4c`** success vec.
7. **Name:** `GuardedVector_TryPopFront_Stride8_OutPair_Inferred` (Ghidra `FUN_0043e750`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_assPreloader_0043e750`. **Not** header-only `GuardedVector_PopFront` @ `0x0040d980` (void, no CS, cap×4 dword).
8. **Decompile ≡ bytes** for full CF; **bytes win** on register ABI + stride.  
   Full hex: `807e2c00558d6e14740755ff15bc619c00837e1000746a8b4e0c8bc1d1e88d14002bca8b56083bd077022bc28b56048b04828d04c83bf874048b08890f8b50048957048b461085c0742683460c018b56088b4e0c03d23bd17707c7460c0000000083c0ff8946107507c7460c00000000807d1800740755ff15b8619c00b0015dc3807d1800740755ff15b8619c0032c05dc3`

### Gaps

- Product English for out-pair fields (drain stores object + time nearby).  
- Intent of first-dword alias skip (preserved oddness).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e750_FUN_0043e750.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e750_FUN_0043e750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_TryPopFront_Stride8_OutPair_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e750.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e750_FUN_0043e750.md` |
| Function named | `docs/reconstruction/functions/aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d570` | Port as **Val12 uint-key operator[]**: **EDI=map** (head@`+4`), **EDX=key\***, **EAX=mapped\*** (node+`0x10`), plain **RET**. Miss **inserts** `{key,0,0}` — do **not** treat as leaf find. Do **not** reuse ECX/EAX peer ABI (`0043bd40`) or ECX/EBX/out_it find ABI (`0043d5e0`). Do **not** invent `RET 4`/`RET 8` stack formals. |
| `0043e750` | Port as **GuardedVector try pop_front stride-8**: **ESI=container**, **EDI=out[2]**, **AL** success, plain **RET**. Wrap at **cap×2**, address with **\*8**. Preserve **first-dword skip when EDI==slot**. Optional CS `+0x2c`/`+0x14`. Do **not** merge with header-only `PopFront` (`0040d980`, cap×4, void). Closes W37-B nested dual free for success-vec pop. |

Shared context: both are nested callees of AssPreloader success drain (`00971480`) — map slot ensure at `host+0x10` tree vs success-vector pop at `host+0x4c`. Co-owned only by partition assignment (STL map worker vs GuardedVector worker). Trio (raw/annotated/clean) + dual A/B filed per VA.

### Drain relative order (context; not owned)

```
AssPreloader_DrainSuccessResultsAndTally (00971480):
  loop:
    TryPopFront_Stride8(host+0x4c, &pair)   // this dual 0043e750
    if !popped: break
    cache find / already-loaded path …
    else:
      time = FUN_0076c330()
      slot = OperatorIndex_Val12(host+0x10 tree, &key)  // this dual 0043d570
      slot[0]=obj; slot[1]=time
      ext bucket tally …
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred` from Val12 family + op[] gate + EDI/EDX ABI; `GuardedVector_TryPopFront_Stride8_OutPair_Inferred` from header family + stride-8 try-pop).  
- Rejected scaffold assPreloader-derived leaf names.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).  
- **Terminal coverage:** **false**.
