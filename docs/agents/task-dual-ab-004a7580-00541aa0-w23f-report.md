# Dual A/B report — W23-F OWN `aa_004a7580` + `aa_00541aa0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-F  
**Scope:** VAs `0x004a7580`, `0x00541aa0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees / `get_function_by_address` + parent decompile for name). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004a7580` StdMap_InsertOrFindByIntKey_Isnil15_Inferred | **accept** — insert-or-find CF + isnil `+0x15` + thiscall/`ret 8` + equal-no-write sealed |
| `aa_00541aa0` Client_LoadSkillsFX | **accept-with-gaps** — LoadSkillsFX role + thiscall host/`+0xF0C` + SkillDef walk/string gate/entry layout sealed; product string field + full SkillDef residual |

---

## VA `0x004a7580` — sealed facts

1. **Body:** `0x004a7580`–`0x004a7638` (184 B / `0xB8`).
2. **ABI:** **`__thiscall`** (ECX = map shell*); stack `outPair*`, `int *pKey`; **`ret 8`** ×3.
3. **Semantics:** MSVC `std::map<int,T>` **insert-or-find** (not assign).
4. **Node:** key `@+0x0C` (`node[3]`); isnil `@+0x15`; color `@+0x14` (insert helper).
5. **Loop:** lower-bound walk; leftmost insert / predecessor `FUN_005a2850` / insert if `node.key < *pKey` / equal → `inserted=0`.
6. **Callees:** `FUN_004a6d80` insert+RB (`"map/set<T> too long"`); `FUN_005a2850` predecessor.
7. **Callers (3):** `FUN_004a0b90`, `FUN_004a6390`, `FUN_004a4fa0` (FX paths).
8. **Twin:** `aa_00569320` same CF with isnil **`+0x49`**.
9. **Name:** `StdMap_InsertOrFindByIntKey_Isnil15_Inferred` (Ghidra `FUN_004a7580`).
10. **Decompile ≡ bytes** for CF + ABI.

### Gaps

- Product / PDB English name.  
- Mapped-value typedef (size implied by isnil15).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a7580_StdMap_InsertOrFindByIntKey_Isnil15_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004a7580_StdMap_InsertOrFindByIntKey_Isnil15_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a7580_FUN_004a7580.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7580_FUN_004a7580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Isnil15_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a7580.cpp` |
| Function | `docs/reconstruction/functions/aa_004a7580_FUN_004a7580.md` |
| Function named | `docs/reconstruction/functions/aa_004a7580_StdMap_InsertOrFindByIntKey_Isnil15_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004a7580.md` |

---

## VA `0x00541aa0` — sealed facts

1. **Body:** `0x00541aa0`–`0x00541baf` (271 B / `0x10F`).
2. **ABI:** **`__thiscall`** (ECX = content host*); plain **`ret`**; SEH `LAB_009a3ff9`. Decompiler void-no-arg under-states ABI — bytes restore `mov ebp,ecx`.
3. **Name evidence:** parent `FUN_00541e70` logs `"before LoadSkillsFX and SpecialFXMaster"` then calls this → **`Client_LoadSkillsFX`**.
4. **SkillDefMap:** `FUN_0054b480` / sealed `SkillDefMap_GetGlobal`; in-order walk isnil `@+0x641`.
5. **Gate:** non-empty C-string at skill node `+0x5B6`.
6. **Per hit:** `new(0xC)` → `FUN_004a1620` at entry+4 → store skill id `node[3]` → `FUN_00545890(*(host+0xF0C), skillId, entry, 0)`.
7. **Caller (1):** `FUN_00541e70` @ `0x005426d0` (after CloneBase array; before SpecialFXMaster).
8. **Name:** `Client_LoadSkillsFX` (Ghidra `FUN_00541aa0`).
9. **Decompile ≡ bytes** for CF; ABI fixed from `read_memory`.

### Gaps

- Product English for string field `@+0x5B6`.  
- Full SkillDef node schema.  
- Nested dual of `FUN_00545890` (not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00541aa0_Client_LoadSkillsFX.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00541aa0_Client_LoadSkillsFX.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00541aa0_FUN_00541aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00541aa0_FUN_00541aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_LoadSkillsFX.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00541aa0.cpp` |
| Function | `docs/reconstruction/functions/aa_00541aa0_FUN_00541aa0.md` |
| Function named | `docs/reconstruction/functions/aa_00541aa0_Client_LoadSkillsFX.md` |
| Scratch | `docs/reconstruction/tmp/a_00541aa0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004a7580` | Generic int-key map insert-or-find for small value_type (isnil15). Preserve equal-no-write; do not use isnil+0x49 twin layout. FX event maps are consumers. |
| `00541aa0` | Client content-load skills FX hash fill — honor non-empty string gate; entry = id + FxMasterCatalog@+4; target hash host+0xF0C. Not a SkillDefMap mutator. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/parent for name).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
