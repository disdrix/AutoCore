# Dual A/B report — W37-V OWN `aa_00746400` + `aa_00996d70`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-V  
**Scope:** VAs `0x00746400`, `0x00996d70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-V).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00746400` StdVector_FindOrPushBackDword_Inferred | **accept** — thiscall find-or-push + RET 4 + 0/1 sealed (56 B); product host English residual only |
| `aa_00996d70` ResourceCache_Subobj14_Configure_Inferred | **accept-with-gaps** — EAX subobj + EBX size + flag/RET4 + offsets sealed (76 B); product English + unowned callee duals open |

---

## VA `0x00746400` — sealed facts

1. **Body:** `0x00746400`–`0x00746437` (**56 B** / `0x38`; pad `CC` then next).
2. **ABI:** `__thiscall` **ECX = vector host**; stack **dword value**; **`RET 4`**; returns **1** found / **0** appended.
3. **Semantics:**
   - `MOV EAX,ECX`; scan `cursor=[+4]` … `end=[+8]` stride 4.
   - Match → return **1** (edge path if cursor==end → append).
   - Miss → `LEA ESI,&value`; `call FUN_004406e0` (`StdVector_PushBackDword`, EAX=this, ESI=&value) → return **0**.
4. **Layout:** `+0x04` begin*, `+0x08` end* (capacity `+0x0c` only in push callee).
5. **Classification:** **worker** (container find-or-append).
6. **Callers (5):** `FUN_00576860`, `FUN_00576d70`, `FUN_007334a0`, `FUN_0075fc40`, `FUN_00962780` — common this **`DAT_00d1f620`**.
7. **Callees:** `FUN_004406e0` only.
8. **Name:** `StdVector_FindOrPushBackDword_Inferred` (Ghidra `FUN_00746400`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*`.
9. **Family:** pairs with dualed `StdVector_PushBackDword_Inferred`; water/distort token register is a **caller** of this generic unit.
10. **Decompile ≡ bytes** for scan/compare/returns/RET4.  
    Full hex: `8bc18b5004568b70083bd6740f8b4c2408390a741683c2043bd675f58d742408e8bba2cfff33c05ec204003bd674edb8010000005ec20400`

### Gaps

- Product English / typedef of `DAT_00d1f620` host.  
- Host `+0` role (unread).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00746400_StdVector_FindOrPushBackDword_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00746400_StdVector_FindOrPushBackDword_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00746400_FUN_00746400.md` |
| Annotated | `docs/reconstruction/raw/aa_00746400_FUN_00746400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_FindOrPushBackDword_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00746400.cpp` |
| Function | `docs/reconstruction/functions/aa_00746400_FUN_00746400.md` |
| Function named | `docs/reconstruction/functions/aa_00746400_StdVector_FindOrPushBackDword_Inferred.md` |

---

## VA `0x00996d70` — sealed facts

1. **Body:** `0x00996d70`–`0x00996dbb` (**76 B** / `0x4C`; pad `CC`).
2. **ABI:** **EAX = configure subobject**; **EBX = buffer size** (implicit formal); stack **flag** byte; **`RET 4`**; void. (Decompiler shows only stack arg + `in_EAX`.)
3. **Semantics:**
   - `MOV EDI,EAX`; clear list **ESI=EDI+0x2C** via `FUN_00415e90`.
   - `FUN_00449a90` thiscall **ECX=EDI+0x38**, stack **9**.
   - `*(+0x48)=1; *(+0x4C)=1`.
   - `FUN_009899a0` (EDI free aligned buffer state).
   - `*(+0x50)=stack_flag`.
   - `FUN_00989b00`: **ECX=EDI**, **EAX=4** (align), **EBX=size**, stack push **1** (constant; not re-read of flag).
4. **Parent layout (W31-F):** ResourceCache-family host `+0x10` size, `+0x14` this subobject, `+0x68` CS, `+0x80` lock flag.
5. **Classification:** **worker** (subobject configure / reset).
6. **Callers (2):** `FUN_00989ef0` (`ResourceCache_SetField10AndConfigure_Inferred`), `FUN_00989d50`.
7. **Callees:** `FUN_00415e90`, `FUN_00449a90`, `FUN_009899a0`, `FUN_00989b00`.
8. **Name:** `ResourceCache_Subobj14_Configure_Inferred` (Ghidra `FUN_00996d70`; **Inferred**). Reject scaffold `Named_CalleeOf_*assManager*`.
9. **Family:** closes nested residual from W31-F configure parent; shares lock layout with `ResourceCache_LookupByName`.
10. **Decompile ≡ ordered calls**; **EBX size + ESI/ECX sub-setup from bytes**.  
    Full hex: `5156578bf88d772ce813f1a7ff8b4730894424086a098d4f388d44240ce8fe2cabffbe0100000089774889774ce8fe2bffff8a4c2410884f5056b8040000008bcfe84a2dffff5f5e59c20400`

### Gaps

- Product English for subobject / counters / flag.  
- Full dual contracts of unowned callees.  
- Redundant pre-clear in `00989d50` before re-entry.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00996d70_FUN_00996d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00996d70_FUN_00996d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ResourceCache_Subobj14_Configure_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00996d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00996d70_FUN_00996d70.md` |
| Function named | `docs/reconstruction/functions/aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00746400` | Port as **generic dword vector find-or-push**: `__thiscall` this=vec, stack value, **RET 4**, return **1** present / **0** newly pushed. Use existing `StdVector_PushBackDword` (`004406e0`) on miss. Do **not** treat return 0 as error (water wrappers only fail on **−1**). Do not invent water-only API — unit is registry-generic; `DAT_00d1f620` is a common host binding. |
| `00996d70` | Port as **ResourceCache subobject configure**: **EAX=host+0x14**, **EBX=size** (host `+0x10`), stack flag → `+0x50`, **RET 4**. Include list clear `+0x2C`, vector reset `+0x38` arg 9, counters `+0x48`/`+0x4C`, free+realloc align **4**. Pair with W31-F `SetField10AndConfigure`. Do not model as ECX-thiscall on whole cache. |

Shared: both are **workers** with sealed custom register formals beyond naive decompiler signatures. Co-owned only by W37-V partition; different subsystems (container registry vs ResourceCache configure).

**Terminal coverage:** still **false** globally (dual depth ≪ 25666 live VAs). This pair dual-reviewed only.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names; parent family strings used where sealed.  
- Rejected bare scaffold `Named_CalleeOf_*` plates.  
- Avoided bare `undefined4` as sole clean type surface (`uint32_t` / explicit pointers).
