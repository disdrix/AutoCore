# Dual A/B report — W37-C OWN `aa_00469c80` + `aa_004a04f0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-C  
**Scope:** VAs `0x00469c80`, `0x004a04f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-C).  
**Terminal coverage claimed:** **false** (agent report; no parent ledger update).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00469c80` StdVector_PushBack_Elem28_ValueEax_Inferred | **accept-with-gaps** — ECX=vec / EAX=value / RET 0; spare fill-n + growth insert-one sealed; product T open |
| `aa_004a04f0` MissionTree_InorderCollectMediaPreloads_Inferred | **accept-with-gaps** — thiscall + RET 0x10; inorder walk + `004b88e0` forward sealed; product tree English open |

---

## VA `0x00469c80` — sealed facts

1. **Body:** `0x00469c80`–`0x00469d04` exclusive (**132 B** / `0x84`; pad `CC` @ `0x00469d04`).
2. **ABI:** **ECX=`vec*`** → EDI; **EAX=`value*`** → EBX; bare **`RET`** (`C3`). Decompiler `__fastcall` + `in_EAX` agrees on value-in-EAX; **bytes win** over any stack-value reading.
3. **Semantics:** MSVC-style **`vector::push_back`** for POD T size **0x1c**:
   - Layout `+0x04 begin / +0x08 end / +0x0c cap_end`; size/cap via magic `0x92492493`.
   - **Spare:** `StdUninitFillN_Elem28_CountEcx_Inferred` (`0x0046a260`) with **ECX=1, EAX=end, EBX=value**; `end += 0x1c`.
   - **Full:** `StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred` (`0x00469e20`) with **EDI=vec**, stack `(outIt*, where=end, value*)`, **RET 0xC**; outIt discarded.
4. **Classification:** worker — thin push_back router.
5. **Callers (3):** `FUN_0071a4a0` @ `0x0071a8ec`; `FUN_00983350` @ `0x009833e6`; `FUN_009847c0` @ `0x0098485e`.
6. **Name:** `StdVector_PushBack_Elem28_ValueEax_Inferred` (Ghidra `FUN_00469c80`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*assPackManag*`. Distinct from RC push_back `0x00460f90` (EAX=vec / ECX=value).
7. **Decompile ≡ bytes** for size/cap/end CF; **bytes win** on fill-n register formals (decompiler shows `FUN_0046a260(param_1)`).  
   Full hex: raw W37-C append (132 B).

### Gaps

- Product/PDB T English.  
- Caller container product names.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem28_ValueEax_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469c80.cpp` |
| Function | `docs/reconstruction/functions/aa_00469c80_FUN_00469c80.md` |
| Function named | `docs/reconstruction/functions/aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` |

---

## VA `0x004a04f0` — sealed facts

1. **Body:** `0x004a04f0`–`0x004a057a` exclusive (**138 B** / `0x8A`; final **`C2 10 00`**; pad `CC`).
2. **ABI:** **thiscall ECX=`tree_holder*`**; stack **4×u32** (unused + 3 flags); void; **`RET 0x10`**.
3. **Semantics:** **Inorder tree walk** → per-node media preload collect:
   - `head = *(*holder + 4)`; begin = `*head`; empty when begin==head.
   - Each node: `ECX = [node+0x10]` (mission-host payload); call `MissionHost_CollectMediaPreloads_Inferred` (`0x004b88e0`) with the four stack formals.
   - Successor uses **+0 left / +4 parent / +8 right** and **nil-gate +0x15** (MSVC-style).
4. **Classification:** worker — walk bridge only (no string/path logic in-body).
5. **Callers (5):**  
   - `FUN_004ebf50` @ `0x004ebfa4` — plate **CollectAllSoundPreloads**; flags `(ctx,0,1,0)`; **bytes:** `mov ecx,[reg+0x88]`.  
   - `FUN_004ec7b0` @ `0x004ec871` — **CollectAllPhysicsPreloads**; `(ctx,0,0,1)`.  
   - `FUN_004f1ff0` @ `0x004f2500` — **Object_CollectAllGraphicsPreloads**; `(ctx,1,0,0)`.  
   - `FUN_00542790` @ `0x005429cc`; `FUN_00542e20` @ `0x00542f5b` — all flags `(…,1,1,1)`.
6. **Name:** `MissionTree_InorderCollectMediaPreloads_Inferred` (Ghidra `FUN_004a04f0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG*`.
7. **Decompile ≡ bytes** for walk/call/RET; parent flag triples sealed via decompile + call-site `read_memory`.  
   Full hex: raw W37-C append (138 B).

### Gaps

- Product English for tree/holder/node types.  
- Holder first-indirection field map.  
- +0x15 vs stock `_Isnil` naming residual (behavior sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a04f0_FUN_004a04f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a04f0_FUN_004a04f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionTree_InorderCollectMediaPreloads_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a04f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004a04f0_FUN_004a04f0.md` |
| Function named | `docs/reconstruction/functions/aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00469c80` | Port as **POD push_back**: **ECX=vec**, **EAX=value***, bare ret. Fast path = W36-M fill-n count 1 + end+=0x1c; slow = W36-Q insert-one at end. **Do not** use RC push_back ABI (`00460f90`). |
| `004a04f0` | Port as **inorder mission-tree for-each** into `MissionHost_CollectMediaPreloads`. Preserve **RET 0x10** and independent flag triples from CollectAll* parents. ECX = tree holder (often `obj+0x88` pointer or embed +0x44). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0046a260` | `StdUninitFillN_Elem28_CountEcx_Inferred` (W36-M) — push_back fast path |
| `0x00469e20` | `StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred` (W36-Q) — push_back slow path |
| `0x00469f50` | insert-n ValueEdx (W34-Q) — under insert-one |
| `0x00460f90` | RC push_back twin (different ABI) |
| `0x004b88e0` | `MissionHost_CollectMediaPreloads_Inferred` (W32-H) — per-node work |
| `0x004f1ff0` | Object_CollectAllGraphicsPreloads — graphics flag triple |
| `0x004ebf50` / `0x004ec7b0` | Sound / Physics CollectAll* plates |

Together they close the **POD ValueEax push_back parent** of W36-Q/W36-M and the **mission-tree walk** residual of W32-H `004b88e0`.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze/callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` as sole clean surface (`uint32_t` / explicit structs).
