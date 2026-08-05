# Dual A/B report — W23-I OWN `aa_004baa30` + `aa_00979290`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-I  
**Scope:** VAs `0x004baa30`, `0x00979290` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004baa30` StdMap_EraseIterator_Inferred | **accept-with-gaps** — STL erase CF + throw string + thiscall/`ret 8` + size-- epilogue sealed; product name / K-V residual |
| `aa_00979290` ClientSpecialEvent_Respawn_TeardownAirlift | **accept-with-gaps** — EDI-this CF + gate/clear + resolve + vtbl/`Vehicle_ActivateEnterWorld` sealed; vtbl product name residual |

---

## VA `0x004baa30` — sealed facts

1. **Body (sealed):** `0x004baa30`–`0x004bace5` (**694 B / `0x2B6`**). Ghidra lists end `004bacb6` (false noreturn on `operator_delete`).
2. **ABI:** **`__thiscall`** (ECX = map*); 2 stack formals; epilogue **`ret 8`** (`C2 08 00`).
3. **Semantics:** MSVC **`map`/`set` single-iterator erase** (`_Tree::erase`).
4. **Nil gate:** `node+0x15` isnil → throw `"invalid map/set<T> iterator"` @ `0x00a152f0`.
5. **Layout:** color `@+0x14`; head `@map+4`; size `@map+8` (decremented in sealed epilogue).
6. **Rebalance:** black-node fixup with `FUN_004e22d0` / `FUN_006753b0`; begin/rbegin via `FUN_004e12a0` / `FUN_00421b70`.
7. **Caller (1):** `FUN_004bacf0` = sealed `StdMap_EraseRange_Inferred`.
8. **Name:** `StdMap_EraseIterator_Inferred` (Ghidra `FUN_004baa30`).
9. **Decompile ≡ bytes** for main CF; epilogue size--/out-it sealed from bytes past decomp truncation.

### Gaps

- Product / PDB English name.  
- Key/value types of map instantiations.  
- Full dual of `FUN_00673070` / rotation helpers.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004baa30_StdMap_EraseIterator_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004baa30_StdMap_EraseIterator_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.md` |
| Annotated | `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseIterator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004baa30.cpp` |
| Function | `docs/reconstruction/functions/aa_004baa30_FUN_004baa30.md` |
| Function named | `docs/reconstruction/functions/aa_004baa30_StdMap_EraseIterator_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004baa30.md` |

---

## VA `0x00979290` — sealed facts

1. **Body:** `0x00979290`–`0x009792ff` (**112 B / `0x70`**).
2. **ABI:** **EDI = `ClientSpecialEvent_Respawn* this`**; no stack formals; plain **`ret`** (`C3`).
3. **Gate:** `this+0x38 != 0` (airlift/full-sequence latch); always cleared on exit of gated body.
4. **Resolve:** ECX = `[DAT_00b04830]`; `FUN_004bb010(this+0x28)` = sealed `Object_ResolveTfIdVtbl1d4_Inferred`.
5. **On hit:** `vtbl+0x1bc(0)`; `*(phys+0x28) = this+0x68`; `FUN_00560e90(phys)`; if `this+4==0` → `Vehicle_ActivateEnterWorld` (**ECX = resolved** @ `0x00503f30`).
6. **Callers (2):** `ClientSpecialEvent_Respawn_Update` (phase 4→5); `ClientSpecialEvent_Respawn_dtor`.
7. **Name:** `ClientSpecialEvent_Respawn_TeardownAirlift` (Ghidra `FUN_00979290`).
8. **Decompile ≡ bytes** for CF; ECX loads for resolve/activate sealed from bytes (decomp drops them).

### Gaps

- Product English for vtbl slot `+0x1bc`.  
- Product names for event `+0x04` / `+0x68`.  
- Whether `FUN_00560e90` staged stack byte is a true formal.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00979290_FUN_00979290.md` |
| Annotated | `docs/reconstruction/raw/aa_00979290_FUN_00979290.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ClientSpecialEvent_Respawn_TeardownAirlift.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00979290.cpp` |
| Function | `docs/reconstruction/functions/aa_00979290_FUN_00979290.md` |
| Function named | `docs/reconstruction/functions/aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` |
| Scratch | `docs/reconstruction/tmp/a_00979290.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004baa30` | Prefer `std::map`/`set` erase or bit-exact tree; honor isnil throw + size--; do not treat as list erase or host free. |
| `00979290` | Client VFX/event teardown only — honor `+0x38` latch, EDI this, resolve-then-clear; do not invent C2S; ActivateEnterWorld needs ECX=entity. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
