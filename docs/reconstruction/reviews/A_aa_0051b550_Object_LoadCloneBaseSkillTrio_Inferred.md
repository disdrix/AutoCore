# Review A (reconstruction fidelity): `aa_0051b550` Object_LoadCloneBaseSkillTrio_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b550` |
| **VA** | `0x0051b550` |
| **Body** | `0x0051b550`–`0x0051b5d0` exclusive (**128 B**) |
| **Canonical name** | `Object_LoadCloneBaseSkillTrio_Inferred` |
| **Prior / alias** | `FUN_0051b550`; auto `Named_CalleeOf_Skill_Uses_…` (**narrow — do not promote**) |
| **Review date** | `2026-08-04` (WQ9R-J OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md` |
| **System** | `skills-abilities` |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared **clonebase default-skill trio loader**: recreate the owner's skill CNDHash, then ensure three skill ids from the clonebase template are present in that tree at ranks supplied by three virtual methods.

Not bulk loadout walk (`FUN_004c8a60` — **caller**). Not ensure-single (`Skill_EnsureLoadedInTree` — **callee**). Not cast validate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051b550_FUN_0051b550.md` (+ 2026-08-04 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_0051b550_FUN_0051b550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LoadCloneBaseSkillTrio_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0051b550.cpp` |
| Function records | `functions/aa_0051b550_FUN_0051b550.md`, `…_Object_LoadCloneBaseSkillTrio_Inferred.md` |
| Live decompile | ensure hash + three EnsureLoadedInTree |
| Live bytes | entry `56 57 6A 01 8B F1 E8…`; epilogue `5F 5E C3` |
| Nested dual | `aa_00518e30` (same wave); `aa_0051a980` Skill_EnsureLoadedInTree |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`/`__fastcall`; ECX=`this`; bare `C3` | **High** | `read_memory` + Ghidra body |
| Body 128 B exclusive end `0x0051b5d0` | **High** | Ghidra range + terminal `C3` |
| First call `0x00518e30` with imm **1** | **High** | `6A 01` + rel32 → `0x00518e30` |
| `this+0xA8` → `+0x3C` → clonebase | **High** | `mov eax,[esi+0xA8]; mov ecx,[eax+0x3C]` |
| Skill ids `+0x3BC/+0x3C0/+0x3C4` | **High** | imm loads sealed |
| Ranks from vtbl `+0x264/+0x268/+0x26C` byte | **High** | `call [edx+off]; movzx` |
| `Skill_EnsureLoadedInTree` ×3 | **High** | named callee + prior dual |
| Virtual method (vtbl DATA xrefs) | **High** | 25 xrefs; 1 code caller |
| Sole code caller `FUN_004c8a60` | **High** | callers list |
| Product / PDB symbol | **Open** | `_Inferred` |
| English for three slots / rank vfuncs | **Open** | |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Recreate hash log2=1 | **Yes** |
| Three identical ensure patterns | **Yes** |
| No extra stack formals / void | **Yes** |
| No invented cast/validate/network | **Yes** |
| Order: hash then slots 0→1→2 | **Yes** |

---

## 5. Gaps / open

1. Product demangled method name.
2. Clonebase field English for the three skill id dwords.
3. Product meaning of rank vfuncs `+0x264/+0x268/+0x26C` (class-specific).
4. Type name for `*(this+0xA8)` host object.
5. Runtime capture / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, body, hash-first order, three-slot clonebase path, and callers sealed; product English open.
