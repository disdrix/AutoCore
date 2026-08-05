# Dual A/B report — W37-K OWN `aa_00458510` + `aa_005e13b0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-K  
**Scope:** VAs `0x00458510`, `0x005e13b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** Wave37 dual K (OWN-ONLY pair).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00458510` StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred | **accept-with-gaps** — EAX/EBX/`ret 4`/unsigned key/isnil15/equal-no-write sealed; insert-helper dual + product English open |
| `aa_005e13b0` StdTree_InsertAndRebalance_Val12 | **accept-with-gaps** — Val12 always-insert CF/ABI/`ret 0x10`/max-size/buynode sealed; product demangle open |

---

## VA `0x00458510` — sealed facts

1. **Body:** `0x00458510`–`0x004585C5` exclusive (**181** B / `0xB5`; pad `CC`). Ghidra meta end `004585c4` is short by final ret byte — **bytes win**.
2. **ABI:** **register-assisted** insert-or-find — **EAX** = map shell (`head@+4`, `size@+8`); **EBX** = `Val8*` (key at `+0`); stack **`InsertPair* out`**; returns **out in EAX**; **`RET 4`** ×3. Not ECX-thiscall; not `ret 8`.
3. **Semantics:**
   - Lower-bound walk while `!isnil(child)` (`isnil@+0x15`).
   - Key compare **unsigned**: walk `SETB` (`0F 92`); equal gate `JAE` (`73`).
   - Key at `node+0x0C` (`node[3]`); first dword of EBX blob.
   - If last step left and node is leftmost (`head->left`): `FUN_00438140(..., addLeft=1)` → `{it,1}`.
   - Else if last step left: predecessor `FUN_004129f0`.
   - If `node.key < *key` (unsigned): insert with `addLeft=goLeft` → `{it,1}`.
   - Else **equal**: `{node,0}` — **no** mapped-value rewrite.
4. **Node family:** Val8 / isnil15 — left@0 parent@4 right@8 key@0x0C mapped@0x10; color@0x14 used inside insert callee.
5. **Classification:** worker (shared multi-caller map glue).
6. **Callers (6):** `FUN_00444850`, `FUN_00444880`, `FUN_0043daf0`, `FUN_004582e0`, `FUN_00752d60`, `FUN_00763620`.
7. **Callees:** `FUN_00438140` (insert+RB; max `0x1ffffffd`; color@+0x14; unOWN), `FUN_004129f0` (predecessor isnil15; unOWN).
8. **Context:** W35-H `FourCCFnPtrMap_TryInsert_DAT_00d21958` is a thin wrapper that builds `{tag,handler}` and calls this — left full dual open; **closed here**.
9. **Name:** `StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred` (Ghidra `FUN_00458510`; **Inferred**). **Reject** scaffold Palantir Named_CalleeOf product role.
10. **Decompile ≡ CF**; **bytes win** on ABI (`ret 4`, EAX/EBX) and unsigned compares.  
    Full hex: raw W37-K append (181 B).

### Gaps

- Full dual of insert helper `FUN_00438140` / buynode `FUN_00439110`.  
- Product English / demangle for six caller map types.  
- Predecessor helper dual (`FUN_004129f0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00458510_FUN_00458510.md` |
| Annotated | `docs/reconstruction/raw/aa_00458510_FUN_00458510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00458510.cpp` |
| Function | `docs/reconstruction/functions/aa_00458510_FUN_00458510.md` |
| Function named | `docs/reconstruction/functions/aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00458510.md` |

---

## VA `0x005e13b0` — sealed facts

1. **Body:** `0x005e13b0`–`0x005e159B` exclusive (**491** B / `0x1EB`; pad `CC`). Ghidra meta end `005e159a` short by final ret byte — **bytes win**.
2. **ABI:** **`__thiscall`**; ECX = map (`head@+4`, `size@+8`); stack `(outIt*, addLeft, where, value*)`; void side-effect + `*outIt`; **`RET 0x10`**.
3. **Semantics:** MSVC `_Tree` **always-insert** + RB rebalance for Val12:
   - If `size > 0x15555553` → throw `"map/set<T> too long"` @ `0x00a1530c` / `DAT_00acc388`.
   - `n = FUN_005ae220(head, where, head, value, color=0)`; `size++`.
   - Link: empty head → root/leftmost/rightmost; else right (`addLeft==0`) or left; maybe update extremities.
   - While parent color red (`color@+0x18`): recolor uncle case or rotate (`FUN_00573170` L / `FUN_00418c10` R; one Lrotate branch **inlined**).
   - Paint root black; `*outIt = n`.
4. **Node:** Val12 / 0x1c — left@0 parent@4 right@8 value@0x0c color@0x18 **isnil@0x19**.
5. **Classification:** worker (always-insert helper; sole consumer).
6. **Callers (1 function / 2 sites):** `FUN_005e18d0` (StdMap_InsertOrFindByIntKey_Val12 — W30-L).
7. **Callees:** `FUN_005ae220`, `FUN_00573170`, `FUN_00418c10`, basic_string/exception/`_CxxThrowException`.
8. **Peer clones (do not merge):** `0x00539210` (W27-Q), `0x0051c1c0` (W25-G), `0x005ae4e0` (W27-T).
9. **Name:** `StdTree_InsertAndRebalance_Val12` (Ghidra `FUN_005e13b0`; **Inferred** structural; VA-disambiguated clean path). **Reject** Mission Named_CalleeOf product role.
10. **Decompile ≡ CF**; epilogue `ADD ESP,0x50; RET 0x10` sealed by bytes. Closes W30-L residual “full dual of always-insert `FUN_005e13b0`”.

### Gaps

- Product English / demangle for map of `FUN_005e18d0` / mission consumer.  
- Buynode null OOM path.  
- Bit-identity vs peer clones (lengths 490–491 B).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005e13b0_StdTree_InsertAndRebalance_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005e13b0_StdTree_InsertAndRebalance_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005e13b0_FUN_005e13b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005e13b0_FUN_005e13b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12_005e13b0.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005e13b0.cpp` |
| Function | `docs/reconstruction/functions/aa_005e13b0_FUN_005e13b0.md` |
| Function named | `docs/reconstruction/functions/aa_005e13b0_StdTree_InsertAndRebalance_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_005e13b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00458510` | Port as **register-ABI** unique insert-or-find: map in **EAX-equivalent**, value/key blob in **EBX-equivalent**, out pair on stack, **`ret 4`**. **Unsigned** 32-bit key at value dword0 / node+0x0C; **isnil@+0x15** (not Val12 +0x19). Equal key → `inserted=0`, **do not** rewrite mapped dword. Pair with Val8 insert+RB (`FUN_00438140` family, max `0x1ffffffd`). Do **not** reuse thiscall/`ret 8` peer `004a7580` or signed Val12 insert-or-find templates. Closes W35-H residual on `FUN_00458510`. |
| `005e13b0` | Port as Val12 **always-insert** rebalance (max `0x15555553`, buynode `005ae220`, rotates Val12 L/R). Parent owns key walk / uniqueness (`005e18d0` signed int key). Share algorithm with peer clones; keep this VA as own instantiation (sole consumer). Closes W30-L residual on always-insert dual. |
| Shared / contrast | These two are **not** a matched insert-or-find + insert helper pair for the same map family: `00458510` is Val8/isnil15/uint/reg-ABI; `005e13b0` is Val12/isnil19/always-insert/thiscall. Do not cross-wire their node offsets or max-size constants. |

Shared / related context:

| Symbol | Role |
|--------|------|
| `FUN_00438140` | Val8 insert+RB for `00458510` (unOWN) |
| `FUN_004129f0` | predecessor isnil15 (unOWN) |
| `FUN_00444850` / `FUN_00444880` | FourCC→fn* ensure wrappers (W35-H) |
| `DAT_00d21958` / `DAT_00d21964` | FourCC maps using `00458510` |
| `FUN_005ae220` | StdTree_Buynode_Val12 (W24-I) |
| `FUN_00573170` / `FUN_00418c10` | Val12 L/R rotate (W26-Q) |
| `FUN_005e18d0` | signed int insert-or-find parent (W30-L) |
| `0x00539210` / `0x0051c1c0` / `0x005ae4e0` | peer always-insert clones |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-K sections).  
- No invented product plates; structural `_Inferred` / Val12 family names from MSVC tree evidence + prior duals.  
- Rejected scaffold Palantir/Mission callee-of product roles.  
- Avoided bare `undefined4` in clean (`uint32_t` / structs).
