# Dual A/B report — W22-M OWN-ONLY (`aa_0041a8e0`, `aa_004220c0`)

**Date:** 2026-07-29  
**Agent:** W22-M OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0041a8e0`, `0x004220c0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0041a8e0` Com_LoaderCtx_NestedTeardown_Inferred | **accept-with-gaps** — nested COM holder + owned-block destroy sealed from **bytes** (decompile tail truncated); product type of `*(ctx+0x0C)` open |
| `aa_004220c0` SkillRow_UninitializedFillN_0x934 | **accept** — leaf fill-N, stride **0x934** / **0x24d** dwords, register ABI ECX/EAX/EBX sealed |

---

## Sealed facts — `0x0041a8e0`

1. **ABI:** `__stdcall` one formal (`ctx`); epilogue **`ret 4`**. Body **`0x0041a8e0`–`0x0041a988`** (**169 bytes**). SEH **`LAB_009bd810`**.

2. **EDI = `&ctx+0x10`** for Ado rowset-holder subobject.

3. **If `*(ctx+0x10)≠0`:** `OleDb_ReleaseAccessorHandleArray_Inferred` (`0x00422de0`) then `AdoRowsetHolder_Teardown_Inferred` (`0x0041bf70`).

4. **Always** second `AdoRowsetHolder_Teardown` (SEH state 1 around it).

5. **Defensive Releases** (`vtbl+8`) on `*(ctx+0x14)` then `*(ctx+0x10)`.

6. **Owned nested object** at `*(ctx+0x0C)`: `operator_delete(*(p+0x0C))` → optional **`free(*p)`** IAT `[0x009c6524]` → zero `p[0..2]` → `operator_delete(p)`. Does **not** null `ctx+0x0C`.

7. **Decompiler gap:** first `operator_delete` @ `0x00489822` marked noreturn → live decompile omits free/zero/second delete; **bytes supersede**.

8. **Sole functional caller:** `Com_LoaderCtx_Teardown_Inferred` `0x0041a3e0` @ `0x0041a428` (+ SEH unwind).

9. **Name:** `Com_LoaderCtx_NestedTeardown_Inferred` — structural from parent dual + callee duals + offsets.

---

## Sealed facts — `0x004220c0`

1. **ABI:** register-only — **ECX=count**, **EAX=dst**, **EBX=src prototype**; bare **`ret`**. Body **`0x004220c0`–`0x004220e3`** (**36 bytes**).

2. **Algorithm:** for each of `count`: if dst non-null, **`rep movsd` of `0x24d` dwords** from EBX→EAX; then **EAX += `0x934`**. EBX fixed (same prototype all slots).

3. **Constants:** `0x24d` (=589 dwords), `0x934` (=2356 bytes = `0x24d*4`).

4. **Leaf:** no callees, no SEH, POD copy only.

5. **Callers (3):** `SkillRowVec_EmplaceBack_Stride934_Inferred` `0x0041aef0` (count=1); `FUN_0041c9a0`; `FUN_0041f740` (grow fill).

6. **Name:** `SkillRow_UninitializedFillN_0x934` — role-sealed from stride + skill-vector parents.

---

## Gaps

### `0041a8e0`
1. Product English / full layout of nested object at `ctx+0x0C`.  
2. Fine register contract into `00422de0` from this site (callee dual residual).  
3. Runtime / bit-exact / differential — open.  
4. Raw decompile head remains truncated; annotated + named clean + re-verify section authoritative for tail.

### `004220c0`
1. Product field map of 0x934 skill-character row — parent-owned.  
2. Runtime / bit-exact / differential — open.

---

## Files

### `aa_0041a8e0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0041a8e0_FUN_0041a8e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Com_LoaderCtx_NestedTeardown_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0041a8e0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_0041a8e0_FUN_0041a8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0041a8e0_FUN_0041a8e0.annotated.md` |

### `aa_004220c0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004220c0_SkillRow_UninitializedFillN_0x934.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004220c0_SkillRow_UninitializedFillN_0x934.md` |
| Function record | `docs/reconstruction/functions/aa_004220c0_SkillRow_UninitializedFillN_0x934.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004220c0_FUN_004220c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillRow_UninitializedFillN_0x934.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004220c0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004220c0_FUN_004220c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004220c0_FUN_004220c0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0041a8e0-004220c0-w22m-report.md` |

---

## AutoCore impact

- **`0041a8e0`:** On loader-ctx dispose (after outer `+0x24` Release), always run nested holder teardown and the `+0x0C` destroy arm when present. Do not port the truncated Ghidra decompile alone — include free/zero/second delete. Map to C# `IDisposable`/finally; do not free the outer ctx here.
- **`004220c0`:** Port skill-row vector grow/emplace as **memcpy of full 0x934-byte prototype** into new slots (count often 1 on emplace fast path). Preserve register-style inputs or a clear `(dst, count, src)` API matching the machine contract.
