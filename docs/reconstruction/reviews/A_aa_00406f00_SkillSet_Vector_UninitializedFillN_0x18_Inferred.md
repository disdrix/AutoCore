# Review A (reconstruction fidelity): `aa_00406f00` SkillSet_Vector_UninitializedFillN_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406f00` |
| **VA** | `0x00406f00`–`0x00406f1c` exclusive (**28 B**) |
| **Canonical name** | `SkillSet_Vector_UninitializedFillN_0x18_Inferred` |
| **Ghidra symbol** | `FUN_00406f00` |
| **Review date** | `2026-08-04` (WQ9G-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md` |
| **System** | STL / SkillSet vector |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `disassemble_function` + `read_memory` + caller `FUN_00412730` disasm + callees `00412aa0` / `00412b10`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin MSVC **vector uninitialized_fill_n** wrapper for **0x18-byte** SkillSet entries: fill `[dest, dest+n)` from a prototype value; return end pointer. Invoked only from SkillSet vector insert/reallocate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9G-F re-verify) | `docs/reconstruction/raw/aa_00406f00_FUN_00406f00.md` |
| Annotated | `docs/reconstruction/raw/aa_00406f00_FUN_00406f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_Vector_UninitializedFillN_0x18_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00406f00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md` |
| Body bytes | `read_memory` @ `0x00406f00` — ends **`C2 04 00`** |
| Call sites | `disassemble_function` `FUN_00412730` @ `0x0041287e`, `0x00412978` |
| Fill loop | `FUN_00412aa0` advances **+0x18**; `FUN_00412b10` copies **6 dwords** |
| Stride peer | dualed `SkillSet_GetEntryCount` (`0x00402d80`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 28 B; **`ret 4`** | **Confirmed** | bounds + bytes |
| Return `dest + count*0x18` | **Confirmed** | `lea edx,[esi+esi*2]; lea eax,[edi+edx*8]` |
| EDI=dest, ESI=count, stack=value* | **Confirmed** | both call sites set registers + push |
| Element construct 0x18 via `00412b10` | **Confirmed** | callee disasm `add esi,0x18` + 6 dword stores |
| SkillSet vector insert family | **High** | caller uses `SkillSet_GetEntryCount`, capacity `0xAAAAAAA`, stride math |
| Product / `_Ufill` demangle | **Tentative** | `_Inferred` |
| Tree/map insert semantics | **Reject** | address-neighborhood only vs `00406c40` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Call fill loop then end-pointer math | Yes |
| Single stack arg cleaned by `ret 4` | Yes |
| Decompiler unaff_ESI/EDI explained as register args | Yes (call sites) |

---

## 5. Naming

| Candidate | Ruling |
|---|---|
| `FUN_00406f00` | Scaffold only |
| `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_*` | **Reject** — chain-of-caller; wrong parent |
| Tree insert residual / isnil29 helper | **Reject** — vector Ufill, not RB tree |
| `SkillSet_Vector_UninitializedFillN_0x18_Inferred` | **Accept** — stride + caller family sealed; English Inferred |

---

## 6. Gaps

1. Product / MSVC demangled helper name.  
2. Full `NPCSkillSetEntry` field plate.  
3. Parent insert `FUN_00412730` undualed.  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
