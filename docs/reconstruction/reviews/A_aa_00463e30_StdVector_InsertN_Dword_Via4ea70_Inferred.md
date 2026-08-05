# Review A (reconstruction fidelity): `aa_00463e30` StdVector_InsertN_Dword_Via4ea70_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00463e30` |
| **VA** | `0x00463e30` |
| **Canonical name** | `StdVector_InsertN_Dword_Via4ea70_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` |
| **System** | util / container (generic dword vector) |
| **Wave** | W38-M OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`__thiscall`** worker: insert **`count`** copies of **`*value`** at **`where`** into an MSVC-style **`vector<uint32_t>`** (begin/end/capEnd triad at +4/+8/+0xC).

| Branch | Behavior |
|---|---|
| `count==0` | no-op |
| `size+count > 0x3fffffff` | `FUN_004540b0` throw |
| `cap < size+count` | 1.5× grow, relocate (4ea70/36ef0), delete old, rewrite triad |
| in-place | shift + fill; bump end when needed |

**Not** domain logic — shared container engine (UI/gfx/net/mission hosts).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00463e30_FUN_00463e30.md` (+ W38-M append) |
| Annotated | `docs/reconstruction/raw/aa_00463e30_FUN_00463e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00463e30.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Dword_Via4ea70_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00463e30` |
| Body image | `read_memory` — SEH, `ret 0x0C`, 1.5× / `0x3fffffff` constants |
| Helpers | decompile `0044ea70`, `00436ef0`, `0044ea50`, `004540b0` |
| Callers | analyze + assembly context (`push` triad, `call`) |
| Twins | `004073a0` thiscall family; `00419880` count-ECX (W23-D) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact image diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__thiscall` ECX=vector | `mov edi,ecx`; field loads `[edi+4/8/c]` | **High** |
| Stack where/count/value*; **ret 0xC** | decompile params; epilogue `c2 0c 00`; call-site pushes | **High** |
| Stride 4 | all size math `>>2` / `*4` | **High** |
| 1.5× growth | `cap + (cap>>1)` in decompile + bytes | **High** |
| Max `0x3fffffff` | compare + `bb ff ff ff 3f` | **High** |
| Throw `004540b0` | callee; decompile string `vector<T> too long` | **High** |
| Helper roles copy/fill | decompile of 4ea70/36ef0/4ea50 | **High** |
| Post-delete continues | bytes after optional delete rewrite triad + ret | **High** |
| Product demangle | no PDB | **Open** |
| Exact helper register wiring in clean | decompiler incomplete; sketched | **Medium** |
| Runtime / bit-exact | not run | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

Clean captures ABI, growth policy, throw, realloc vs in-place spine. Helper micro-moves left partially schematic (same pattern as sealed `00419880` clean). Decompiler noreturn on `operator_delete` **corrected** by bytes.

---

## 5. Residual gaps

1. Product / MSVC demangle.
2. Bit-exact line-by-line of in-place shift ranges (prefer helper duals).
3. Runtime / differential.
4. Full caller taxonomy.

---

## 6. Verdict

**accept-with-gaps** — insert-N dword contract, ABI, growth, throw, and helper set sealed. Gaps are demangle, helper micro-ABI polish, and runtime.
