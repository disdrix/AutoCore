# Review A (reconstruction fidelity): `aa_00518e30` Object_CreateOrRecreateSkillHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518e30` |
| **VA** | `0x00518e30` |
| **Body** | `0x00518e30`–`0x00518ebe` exclusive (**142 B**) |
| **Canonical name** | `Object_CreateOrRecreateSkillHash_Inferred` |
| **Prior / alias** | `FUN_00518e30`; auto callee-chain name (**do not promote**) |
| **Review date** | `2026-08-04` (WQ9R-J OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md` |
| **System** | `skills-abilities` |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Owner helper for the skill-tree **CNDHash** pointer at **`owner+0x70`**:

- If non-null → **recreate** hash at caller log2 (`FUN_004cbdc0` on the hash object).
- If null → **construct** new hash `sizeof 0x34` via `FUN_0051dd60(log2)` (vtbl `PTR_FUN_009ce1b8`); OOM stores null.

Not a skill insert. Not traversal refresh (`Object_RefreshSkillHash_Inferred`). Not inventory CNDHash class (same recreate string family; different helpers/vtbl).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00518e30_FUN_00518e30.md` (+ 2026-08-04 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00518e30_FUN_00518e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CreateOrRecreateSkillHash_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00518e30.cpp` |
| Function records | `functions/aa_00518e30_FUN_00518e30.md`, `…_Object_CreateOrRecreateSkillHash_Inferred.md` |
| Live decompile | branch on `+0x70`; new/ctor vs recreate |
| Live bytes | SEH `6A FF 68 27 36 9A 00…`; all exits `C2 04 00`; pad `CC` |
| Callee context | `FUN_004cbdc0` recreate strings; `FUN_0051dd60` ctor layout |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; ECX=owner; stack log2; **`ret 4`** | **High** | three `C2 04 00` paths |
| Body 142 B; end before `Object_SharedBase_Dtor` `0x00518ec0` | **High** | Ghidra + pad |
| Slot `owner+0x70` is skill hash | **High** | EnsureLoadedInTree / RefreshSkillHash duals |
| Existing → recreate on **hash** ECX | **High** | `mov ecx,[esi+0x70]` before call |
| Missing → `new(0x34)` + ctor | **High** | `6A 34` + `FUN_0051dd60` |
| OOM stores 0 | **High** | fall-through zero store |
| log2 = size exponent (`1 << (log2&0x1f)` in ctor/recreate) | **High** | callee bodies |
| Callers: trio loader push 1; orphan push 4 | **High** | xrefs + site bytes |
| Product class name for skill CNDHash | **Open** | vtbl `009ce1b8` only |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prologue | **Yes** |
| Non-null → recreate → ret 4 | **Yes** |
| Null → new → ctor or zero → ret 4 | **Yes** |
| Decompiler "FUN_004cbdc0(param_2)" without showing hash ECX | **Yes** (asm restores ECX=hash; clean documents it) |
| No skill id / rank logic | **Yes** |

---

## 5. Gaps / open

1. Product / PDB name for skill-family CNDHash (`PTR_FUN_009ce1b8`).
2. Full dual of `FUN_004cbdc0` / `FUN_0051dd60` (support only here).
3. Owning function for orphan call `0x0052a2c5`.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, `+0x70` lifecycle, create vs recreate, sizeof 0x34, and callers sealed; product English open.
