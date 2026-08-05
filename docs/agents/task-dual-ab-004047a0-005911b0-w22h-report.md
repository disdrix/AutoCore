# Dual A/B report — W22-H OWN `aa_004047a0` + `aa_005911b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-H  
**Scope:** VAs `0x004047a0`, `0x005911b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004047a0` UiToast_UninitializedCopy_0x98 | **accept** — range POD copy CF + stride `0x98` + cdecl ABI + PodCopy linkage sealed |
| `aa_005911b0` CVOGObject_JustCreatedInit | **accept-with-gaps** — Just-created phase CF + thiscall/`ret 4` + latch/mode/returns sealed; nested physics formulas residual |

---

## VA `0x004047a0` — sealed facts

1. **Body:** `0x004047a0`–`0x0040480b` (108 B / `0x6C`).
2. **ABI:** **cdecl** plain `ret` (`C3`); EAX = advanced destination end.
3. **Semantics:** MSVC-style **uninitialized_copy** of toast elements stride **`0x98`**.
4. **Loop:** while `src_begin != src_end`: `UiToast_PodCopyElement_0x98(dst, src)`; both += `0x98`.
5. **Callee:** `FUN_00404710` = sealed `UiToast_PodCopyElement_0x98` (`ret 8`, `0x26` dwords).
6. **Caller (1):** `FUN_00404510` thiscall thunk → `(first, last, result, this, result)`.
7. **4th formal:** loaded to EBX/ECX before leaf call; **unused** by PodCopy.
8. **Name:** `UiToast_UninitializedCopy_0x98` (Ghidra `FUN_004047a0`).
9. **Decompile ≡ bytes** for CF; SEH frame present (noop path).

### Gaps

- Product / PDB English name.  
- Product type of unused 4th formal.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004047a0_UiToast_UninitializedCopy_0x98.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004047a0_UiToast_UninitializedCopy_0x98.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004047a0_FUN_004047a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004047a0_FUN_004047a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiToast_UninitializedCopy_0x98.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004047a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004047a0_FUN_004047a0.md` |
| Function named | `docs/reconstruction/functions/aa_004047a0_UiToast_UninitializedCopy_0x98.md` |
| Scratch | `docs/reconstruction/tmp/a_004047a0.md` |

---

## VA `0x005911b0` — sealed facts

1. **Body:** `0x005911b0`–`0x00593233` (8324 B / `0x2083`).
2. **ABI:** **`__thiscall`** (ECX = object*); stack `char mode`; **`ret 4`**; AL = **1** success / **0** abort.
3. **Root profiler:** `"Just created"`.
4. **Done latch:** `*(byte*)(this + 0x910) & 1` → skip, return 1.
5. **Mode 0 soft-skip:** may call `FUN_004a7a20` and return **0** (tick defers).
6. **Phases:** gfx pose apply → `"skyboxphase"` → ragdoll → `"rigidbody"` → `"addEntity"`.
7. **RNG scale:** `DAT_00aaa638` ≈ **1/65535** with `CVOGReaction_RandomUnitScalar`.
8. **Callers (2):** `FUN_00594290` (mode **1**, then OR latch); `FUN_00595230` (mode **0**).
9. **Name:** `CVOGObject_JustCreatedInit` (Ghidra `FUN_005911b0`).
10. **Decompile ≡ entry/exit bytes** for ABI + return; phase map sealed from strings + CF.

### Gaps

- Exhaustive soft-flag bit dictionary `@+0x90c..+0x911`.  
- Product class English beyond CVOG object family.  
- Line-level dual of nested RB builders.  
- Runtime / bit-exact multi-body path.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005911b0_CVOGObject_JustCreatedInit.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005911b0_CVOGObject_JustCreatedInit.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005911b0_FUN_005911b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005911b0_FUN_005911b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_JustCreatedInit.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005911b0.cpp` |
| Function | `docs/reconstruction/functions/aa_005911b0_FUN_005911b0.md` |
| Function named | `docs/reconstruction/functions/aa_005911b0_CVOGObject_JustCreatedInit.md` |
| Scratch | `docs/reconstruction/tmp/a_005911b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004047a0` | Toast vector range-copy only — **not** fill-N; preserve stride `0x98` and cdecl; do not deep-construct elements. |
| `005911b0` | Client Just-created finalize — honor latch `@+0x910`, mode 0/1 return contract; do not treat as skybox-only; nested RB math needs further duals before server port. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
