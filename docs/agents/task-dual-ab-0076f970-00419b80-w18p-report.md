# Dual A/B report — W18-P OWN `0x0076f970` + `0x00419b80`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x0076f970`, `0x00419b80`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0076f970` `Math_ComposeOptionalTRSMatrix_Inferred` | **accept-with-gaps** — stage order + GfxNode S·R·T map sealed; product name open |
| `aa_00419b80` `CNDHash_BucketUnlinkByU64Key` | **accept** — EBX bucket + predOut keyLo-slot trap sealed; English name Probable |

---

## `0x0076f970` — Math_ComposeOptionalTRSMatrix_Inferred

### Sealed facts

1. **Body** `0x0076f970`–`0x0076fc93` (**0x323** B); cdecl `ret`; callers `ADD ESP,0x14`.
2. **ABI:** **EAX** / **ECX** optional `float3*` translation pairs; stack **dest, rOuter, scale, rInner, translation**; return **dest***.
3. **Algorithm:** build optional ±T / R / R⁻¹ / S mats from identity `DAT_00afdf70`; left-multiply via `FUN_00412d80(dest,A,dest)` in fixed order (null skips).
4. **GfxNode path** (`0x00972e50`): EAX=ECX=`0x00D1A6C0` (image zeros), rOuter=(0,0,0,1), dest=node, scale=`+0x9C`, quat=`+0x80`, T=`+0x90` → **`M = S * R * T`** at node+0.
5. **Callers (4):** `GfxNode_ComposeWorldMatrix_ClearDirty`, `FUN_00965290`, `FUN_0096b470`, `FUN_00765170`.
6. **Callees:** `FUN_00412d80`, `FUN_0076eb00`, `FUN_0076e6b0`.
7. **Field correction vs older tentative:** `+0x80` = quat (not scale); `+0x9C` = scale (not quat); `+0x90` = translation.

### Gaps

1. Product/PDB composer name.  
2. Non-zero T_A/T_B call-site audit (skeleton may exercise sandwich).  
3. Runtime / bit-exact / image diff.  
4. Full numeric dual of mul/quat helpers.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0076f970_FUN_0076f970.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_ComposeOptionalTRSMatrix_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0076f970.cpp` |
| Raw | `docs/reconstruction/raw/aa_0076f970_FUN_0076f970.md` |
| Annotated | `docs/reconstruction/raw/aa_0076f970_FUN_0076f970.annotated.md` |
| Scratch | `tmp/a_0076f970.md` |

---

## `0x00419b80` — CNDHash_BucketUnlinkByU64Key

### Sealed facts

1. **Body** `0x00419b80`–`0x00419bc9` (**73** B); **`ret 8`**.
2. **ABI:** **EBX = bucket header***; stack **keyLo, keyHi** stdcall; return **Node*** (or NULL).
3. **Algorithm:** `CNDHash_BucketFindNodeByU64Key` → splice `pred->next` or `head` with `node->next` (`+0x10`) → always `FUN_00419ad0` (EDI=bucket) → return node.
4. **Bytes ≡ decompile intent** (with traps corrected)  
   `8b4424088b4c2404565750518d7c24148bc3e8a9ffffff8bf085f6741f8b4c240c85c98b461074118bfb894110e81effffff5f8bc65ec208008943048bfbe80dffffff5f8bc65ec20800`.
5. **Decompiler trap:** post-find `param_1` test is **predecessor**, not keyLo (keyLo stack slot reused as predOut).
6. **Callers (2):** `CNDHash_Remove_u64` (`0x00413a60`), `FUN_004197b0`.
7. **Does not** free node, dtor value, or unlink ordered list — parent remove owns that.

### Gaps

1. Product English name (Probable only).  
2. Deep `FUN_004197b0` site audit.  
3. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` |
| Function record | `docs/reconstruction/functions/aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00419b80_FUN_00419b80.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_BucketUnlinkByU64Key.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00419b80.cpp` |
| Raw | `docs/reconstruction/raw/aa_00419b80_FUN_00419b80.md` |
| Annotated | `docs/reconstruction/raw/aa_00419b80_FUN_00419b80.annotated.md` |
| Scratch | `tmp/a_00419b80.md` |

---

## AutoCore impact

- **GfxNode / transform dirty rebuild:** world matrix is **`S(scale@+0x9C) * R(quat@+0x80) * T(pos@+0x90)`**, not T·R·S. Ports that apply translate-last will diverge. Dirty bit0 clear remains in caller `00972e50`, not this VA.
- **Inventory / CNDHash remove:** bucket unlink is a thin find+splice; full remove must still transfer value@`+0xc`, unlink ordered list `+0x20/+0x24`, freelist-push — already documented on `CNDHash_Remove_u64`. Do not free inside `00419b80`.
- **Decompiler traps to preserve in ports:** (1) predOut reuses keyLo slot on `00419b80`; (2) `0076f970` is not thiscall-on-node — GfxNode forces ECX to global zeros service `0x00D1A6C0`.

---

## This report

`docs/agents/task-dual-ab-0076f970-00419b80-w18p-report.md`
