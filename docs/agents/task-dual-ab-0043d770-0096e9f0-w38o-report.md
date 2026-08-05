# Dual A/B report — W38-O OWN `aa_0043d770` + `aa_0096e9f0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-O  
**Scope:** VAs `0x0043d770`, `0x0096e9f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + callee decompiles + `disassemble_function` (listing only for factory). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave38.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d770` StdMap_EraseEq_UintKey_Isnil15_Inferred | **accept** — EAX map / ECX key\* / equal_range+count+erase / plain RET / 87 B sealed; product map English residual only |
| `aa_0096e9f0` EffTexture_CreateInstance_Inferred | **accept-with-gaps** — EBX dims\* + 5 stack + RET 0x14 + freelist/ctor/init/fail-dtor sealed (106 B); a0..a4 product English open |

---

## VA `0x0043d770` — sealed facts

1. **Body:** `0x0043d770`–`0x0043d7c7` exclusive (**87 B** / `0x57`; final `C3` @ `0x0043d7c6`; pad `CC`).
2. **ABI:** **EAX=map\*** (`MOV EDI,EAX`); **ECX=`const uint32_t* key`** (`MOV EBX,ECX`); plain **`RET`** (`C3`); returns **erase count** in EAX. No stack formals. Bytes win over decompiler `void`/no-formals.
3. **Semantics:** MSVC-style **`map::erase(key)` with count**:
   - `FUN_0043dc20` equal_range → stack pair `{begin,end}` (ECX=map, EBX=key\*, EAX=&pair).
   - Distance loop: `FUN_0046f100` successor while `it != end`; count in ESI.
   - `FUN_00439050` erase `[begin,end)` with **EDI=map**.
   - Return count.
4. **Layout (callees):** L`+0` / P`+4` / R`+8` / key-u32`+0x0C` / isnil`+0x15` (**not** Val12 +0x19).
5. **Classification:** **worker** (3 callees).
6. **Callers (1):** `AssPreloader_DrainAcRingToTree_Inferred` (`FUN_00970fc0`, W37-AD) fail-flag path @ `0x0097100c` — EAX=tree `host+0xDC`, ECX=&key.
7. **Name:** `StdMap_EraseEq_UintKey_Isnil15_Inferred` (Ghidra `FUN_0043d770`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043d770`.
8. **Decompile ≡ bytes** for CF skeleton; **bytes win** on register ABI.  
   Full hex: `83ec0c535556578bf88bd98d4424148bcfe89a0400008b6c24148b5c241833f63beb896c2410741aeb068d9b000000008d54241083c601e854190300395c241075ee53558d44241850e892b8ffff5f8bc65e5d5b83c40cc3`

### Gaps

- Product/PDB map value_type English.  
- Whether multi-equal keys ever appear (AssPreloader inserts unique).  
- Nested dual depth on `0043dc20` / `0046f100` / `00439050`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d770_StdMap_EraseEq_UintKey_Isnil15_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d770_StdMap_EraseEq_UintKey_Isnil15_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d770_FUN_0043d770.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d770_FUN_0043d770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseEq_UintKey_Isnil15_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d770.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d770_FUN_0043d770.md` |
| Function named | `docs/reconstruction/functions/aa_0043d770_StdMap_EraseEq_UintKey_Isnil15_Inferred.md` |

---

## VA `0x0096e9f0` — sealed facts

1. **Body:** `0x0096e9f0`–`0x0096ea5a` exclusive (**106 B** / `0x6A`; dual final **`RET 0x14`** (`C2 14 00`); pad `CC`).
2. **ABI:** **EBX=`const uint32_t dims[2]*`** (width, height); **5 stack dwords**; **`RET 0x14`**; returns **object\*** or **null**. Not thiscall. Ghidra 1-arg prototype under-declared — **bytes win**.
3. **Semantics:** effect-texture **factory**:
   - `MOV EDI,0x00d21930`; `FUN_0043f120` freelist pop → EAX.
   - Non-null → `FUN_0096bbb0` in-place ctor (vtbls `PTR_LAB_00aa0a20` / `00aa0a10`).
   - Pack `*EBX` / `*(EBX+4)` + forward stack args into `FUN_0096cad0` thiscall init (`effTextureImpl.cpp` CreateTexture / pow2 plates).
   - Init `< 0` → `vtbl[0](this, 1)` complete dtor → null.
   - Else return object.
4. **Classification:** **worker** (factory).
5. **Callers / xrefs (2):** `EffTexture_CreateOrAssignSlot_Inferred` (`FUN_0096f0e0` @ `0x0096f102`, W37-H); second site @ `0x0096ee3e` (code not in a named Ghidra function). Parent `0096f0e0` leaves **EBX=p1** and pushes `(p0,p2,p3,p4,p5)`.
6. **Callees:** `FUN_0043f120`, `FUN_0096bbb0`, `FUN_0096cad0`.
7. **Name:** `EffTexture_CreateInstance_Inferred` (Ghidra `FUN_0096e9f0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_effTexture_0096e9f0`.
8. **Decompile ≡ bytes** for CF skeleton; **bytes win** on formals/`RET 0x14`/EBX dims.  
   Full hex: `5657bf3019d200e82407adff85c07409e8abd1ffff8bf0eb0233f685f674458b44241c8b4c24188b54241050518b0b5283ec088bc489088b53048950048b44242089642430508b44242c8bcee88fe0ffff85c07d0f8b166a018bceff1233c05f5ec214005f8bc65ec21400`

### Gaps

- Product English for each of a0..a4 beyond observed format `0x15` / flags `0x4011` from env init.  
- Object size / RTTI type_info English.  
- Nested duals: freelist `0043f120`, ctor `0096bbb0`, init `0096cad0`.  
- Runtime / bit-exact / device-dependent CreateTexture paths.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096e9f0_EffTexture_CreateInstance_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096e9f0_EffTexture_CreateInstance_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096e9f0_FUN_0096e9f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e9f0_FUN_0096e9f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTexture_CreateInstance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096e9f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096e9f0_FUN_0096e9f0.md` |
| Function named | `docs/reconstruction/functions/aa_0096e9f0_EffTexture_CreateInstance_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d770` | Port as **isnil15 uint-key erase-by-key with count**: **EAX=map** (head@`+4`), **ECX=key\***, plain **RET**, return **count**. equal_range → distance → erase_range. Do **not** invent stack formals / `RET 4|8|C`. Do **not** use Val12 isnil@+0x19 erase family. Do **not** reuse insert peer ABI (`0043d700` keeps map in **EDI**). Closes W37-AD fail-helper residual. |
| `0096e9f0` | Port as **effect-texture factory**: **EBX=dims[2]\***, **5 stack dwords**, **`RET 0x14`**, return object\*/null. Freelist `DAT_00d21930` → ctor → `0096cad0`; fail → complete dtor. Do **not** trust Ghidra 1-arg prototype. Parent create-or-assign forwards `(p0,p2,p3,p4,p5)` with EBX=`p1`. Closes W37-H factory residual. |

Shared: unrelated systems co-owned only by partition assignment (AssPreloader tree erase leaf-helper vs effTexture factory). Trio (raw/annotated/clean) + dual A/B filed per VA.

### Context chains (not owned)

```
AssPreloader drain (W37-AD 00970fc0):
  flag==0 → StdMap_EraseEq…(EAX=host+0xDC, ECX=&key)   // this dual 0043d770
  flag!=0 → find-or-insert 0043d700 → *value = 1

EffTexture create-or-assign (W37-H 0096f0e0):
  neu = EffTexture_CreateInstance(p0,p2,p3,p4,p5) with EBX=p1  // this dual 0096e9f0
  fail → log effTexture.cpp:0x57 → -1
  success → ref@+8 acquire / prior release / *slot = neu → 0
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers (+ `disassemble_function` listing for factory). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`StdMap_EraseEq_UintKey_Isnil15_Inferred` from equal_range+count+erase+isnil15; `EffTexture_CreateInstance_Inferred` from freelist factory + `effTextureImpl` init + create-or-assign parent).  
- Rejected scaffold assPreloader / Named_effTexture product aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
