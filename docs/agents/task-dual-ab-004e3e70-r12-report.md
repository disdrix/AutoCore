# Dual A/B report — R12-013 OWN `aa_004e3e70`

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R12-013  
**Scope:** VA `0x004e3e70` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger / other VAs.  
**Ghidra:** `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs + callee `batch_decompile`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-013**.  
**System:** skills-abilities.  
**Parent dual:** `0x005a27f0` (Rrotate isnil21).  
**Dual start:** 2646.  
**Terminal:** **false**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e3e70` StdTree_EraseAndRebalance_Isnil21_Inferred | **accept-with-gaps** — ABI/CF/throw/layout/callers/epilogue size-- sealed (694 B); product English open |

---

## VA `0x004e3e70` — sealed facts

1. **Body:** `0x004e3e70`–`0x004e4126` exclusive (**694 B** / `0x2B6`); pad `CC`×10 then Val12 erase `FUN_004e4130` @ `0x004e4130`.
2. **ABI:** **`__thiscall`** (ECX = map); stack `Node** outIt`, `Node* node`; **`RET 8`** (`C2 08 00` @ `0x004e4123`); void return after out-it write.
3. **Role:** MSVC-style **single-node** map/set tree **erase + RB rebalance** for **isnil@+0x21** family:
   - if `node->isnil (+0x21)` → throw `"invalid map/set<T> iterator"` (`0x00a152f0`, ThrowInfo `DAT_00acc34c`)
   - successor prep `FUN_004e12c0`
   - splice replacement; fix root / leftmost `FUN_004cb2c0` / rightmost `FUN_00421a60`
   - if erased **black** (color@**+0x20** == 1) → recolor + Lrotate `FUN_0050e9f0` / Rrotate `FUN_005a27f0`
   - `operator_delete(node)`; if `size(+0x08)>0` then `--size`; `*outIt = successor`
4. **Layout:** node **0x28**; color@**+0x20**; isnil@**+0x21**; Val16 @+0x10 (not destroyed here); head@map+4; size@map+8.
5. **Does not:** free whole tree; range-loop (parents do); run value vtbl dtor; use Val12 isnil@+0x19 offsets.
6. **Callers (2):** `FUN_004e4e10` @ `0x004e4eaf`; `FUN_004e52a0` @ `0x004e533f` — EraseRange shells (both isnil21).
7. **Callees:** `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, STL throw chain.
8. **Decomp miss:** Ghidra marks `operator_delete` as noreturn and **omits** size-- / `*outIt` / `ret 8` — **bytes seal**.
9. **Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` (Ghidra `FUN_004e3e70`). **Reject** Named_CalleeOf_VOG_DEBUG scaffold.
10. **Family:** insert twin `StdTree_InsertAndRebalance_Isnil21_Inferred` @ `0x00407200`; peer Val12 erase @ `0x004e4130` (not interchangeable); parent dual Rrotate `0x005a27f0`.
11. **Decompile ≡ raw CF** for throw/splice/RB; epilogue from `read_memory`.  
    Entry hex (64 B): `64a1000000006aff68621e9a00508b4424146489250000000083ec4880782100558be9745968f052a1008d4c240cff15f8629c008d4c2424c744245400000000`  
    Epilogue tail: `…83c454c20800` (`ADD ESP,0x54; RET 8`).
12. **Closes** R12-013 residual dual for this VA (static); product demangle still open.

### Gaps

- Product / PDB English for owning `map<K,V>` of EraseRange parents.  
- Bit-exact full RB path golden vs MSVC.  
- Runtime / differential.  
- Residual dual status of rotates `0050e9f0` / `005a27f0` (roles sealed; may still need own duals).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R12-013 append) | `docs/reconstruction/raw/aa_004e3e70_FUN_004e3e70.md` |
| Annotated | `docs/reconstruction/raw/aa_004e3e70_FUN_004e3e70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e3e70.cpp` |
| Function | `docs/reconstruction/functions/aa_004e3e70_FUN_004e3e70.md` |
| Function named | `docs/reconstruction/functions/aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e3e70` | Port as **single-node erase+rebalance** for **isnil@+0x21** maps: throw on nil iterator; splice; RB with **L `0050e9f0` / R `005a27f0`**; plain `operator_delete`; **size--** when size>0; write successor to out-it; **RET 8**. **Do not** use Val12 offsets (+0x18/+0x19) or Val12 rotates. **Do not** treat as range erase (parents `004e4e10`/`004e52a0`). Pair with insert twin `00407200` for same layout. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x005a27f0` | Rrotate isnil21 — **parent dual** (partition) |
| `0x0050e9f0` | Lrotate isnil21 |
| `0x004e12c0` | nextnode / successor isnil21 |
| `0x004cb2c0` / `0x00421a60` | leftmost / rightmost helpers |
| `0x004e4e10` / `0x004e52a0` | EraseRange callers |
| `0x00407200` | InsertAndRebalance isnil21 twin |
| `0x004e4130` | adjacent Val12 erase (different family) |
| `0x00405650` | related isnil21 erase-class residual (R12-009; not this VA) |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Inferred name with `_Inferred` suffix; never Runtime Confirmed.  
- Rejected Named_CalleeOf_* scaffold as product identity.  
- Trio evidence: raw + annotated + clean (named) + function records.
