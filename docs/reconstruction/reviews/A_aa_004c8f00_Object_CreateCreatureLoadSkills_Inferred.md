# Review A (reconstruction fidelity): `aa_004c8f00` Object_CreateCreatureLoadSkills_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8f00` |
| **VA** | `0x004c8f00`–`0x004c9113` inclusive (**532 B** / `0x214`) |
| **Canonical name** | `Object_CreateCreatureLoadSkills_Inferred` |
| **Ghidra name** | `FUN_004c8f00` |
| **Review date** | `2026-08-04` (WQ9E-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md` |
| **System** | skills-abilities / creature object create + skill-bank load |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body + string/RTTI) + `get_assembly_context` (xrefs). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual-method body (entered via MI this-adjust thunks): spawn a clone object from the source's embedded CBID factory (`Object_CreateFromEmbeddedCbid_Inferred` @ `0x0051b230`), `__RTDynamicCast` to **`CVOGCreature`**, copy selected creature fields from the source, **recreate** the destination skill CNDHash at log2=**2**, then **traverse-lock** the source skill hash and `Skill_EnsureLoadedInTree` each skill into the new creature. Returns MI-adjusted creature primary, or 0 after `VOG_DEBUG_STOP` if cast fails.

This is the **second sealed CODE site** of `SkillCNDHash_Recreate_Inferred` (`0x004cbdc0`) with imm log2=2 (peer factory path uses caller log2).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x004c8f00` (2026-08-04) ≡ raw 2026-07-23 CF |
| Bytes | `read_memory` 0x004c8f00 length 600 (body 532 B + `CC` pad) |
| RTTI TD names | `0xaf8e10` `.?AVCVOGClonedObjectBase@@`; `0xaf8d0c` `.?AVCVOGCreature@@` |
| Strings | `HashError:TraversalLock...` @ `0xa27cd0`; `HashError:TraverseToNext...` @ `0xa27c9c`; `VOG_DEBUG_STOP` @ `0xa15844` |
| Factory dual | `aa_0051b230` Object_CreateFromEmbeddedCbid_Inferred (WQ9R-H) |
| Recreate dual | `aa_004cbdc0` SkillCNDHash_Recreate_Inferred (WQ9D-A) |
| Call sites | MI thunks `0x004cd003` JMP; `0x0053bd99` after `SUB ECX,0x8a0` JMP |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = source (MI-adjusted host); no stack args; plain RET; returns creature primary* or 0
void * __thiscall Object_CreateCreatureLoadSkills_Inferred(void *sourceThis);
```

| Formal | Source | Conf |
|---|---|---|
| sourceThis | ECX (`MOV EDI,ECX`) | **High** |
| cleanup | plain `RET` (both exits) | **High** |
| return | EAX = creature MI primary `+4` path, or 0 | **High** |
| Convention | MSVC **`__thiscall`** (not free `__fastcall`) | **High** |

---

## 4. Control flow (decompile ≡ bytes)

1. `LEA ECX, [source MI base -0x4fc]`; call `Object_CreateFromEmbeddedCbid_Inferred` (`0x0051b230`); push result; `__RTDynamicCast` → `ESI` creature.
2. If `ESI==0`: log `VOG_DEBUG_STOP`; return 0.
3. Source vtbl `+0x27c` → clamp `<2` to 1 → store creature `+0x150`.
4. Source vtbl `+0x244` → dest MI primary vtbl `+0x248`; source `+0x23c` → dest `+0x240`.
5. Copy `source-0x3d8` → creature `+0x128`; `FUN_004c4070`/`FUN_004c41c0` on source-0x500 band → creature `+0x13e`/`+0x142`; copy byte `source-0x400` → `+0x100`; optional flag `source-0x1f5` → creature `+0x30b=1`.
6. Dest skill hash: `ECX = *(primary_adj + 0x70)` form (`[EDX+ESI+0x74]`); **`PUSH 2; CALL SkillCNDHash_Recreate_Inferred`**.
7. Source skill hash at MI `+0x70` (`[base-0x48c]`): if lock `@+0x1d` already set → log TraversalLock + VOG (continue); set lock=1.
8. Ordered walk: first from hash `+0x14`, then node `+0x14`; payload at node `+8`; stop when payload 0. Per skill: `Skill_EnsureLoadedInTree(dest_primary, *(skill+0x5fc), *(short*)(skill+0x5f6))`.
9. Clear lock `@+0x1d`; return dest MI primary.

| Stage | Match | Conf |
|---|---|---|
| Create + RTDynamicCast Creature | **Yes** | **High** |
| Field copy / vtbl chain | **Yes** | **High** |
| Recreate log2 imm **2** @ `0x004c902a` | **Yes** (`6A 02` + call `004cbdc0`) | **High** |
| TraversalLock / TraverseToNext soft log | **Yes** (continue, not abort) | **High** |
| Skill_EnsureLoadedInTree loop | **Yes** call `0x0051a980` | **High** |
| Fail path return 0 | **Yes** | **High** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| RTTI to `CVOGCreature` | **Yes** (TypeDescriptor name bytes) |
| Skill hash recreate + EnsureLoadedInTree | **Yes** |
| HashError traverse strings | **Yes** |
| Product/PDB method English | **No** |
| Reject `Mission_CVOGClonedObjectBase_RTTI_*` | **Yes** — RTTI-keyword false rename |
| Reject `Named_VOG_DEBUG_STOP_004c8f00` | **Yes** — shared stop string |

**Decision:** `Object_CreateCreatureLoadSkills_Inferred` — role High (RTTI + skill bank CF); product English **Inferred**.

---

## 6. Gaps

1. Product/PDB virtual method name on clone-base / creature hierarchy.  
2. Semantic English for vtbl slots `+0x27c` / `+0x244` / `+0x23c` and fields `+0x150` / `+0x128` / `+0x30b`.  
3. Dual of nested factory / EnsureLoadedInTree / accuracy helpers (not OWN).  
4. Full MI layout map for `-0x4fc` / `-0x8a0` thunk classes.  
5. Runtime / bit-exact / differential open.

---

## 7. Verdict

ABI, create→cast→copy→recreate(log2=2)→locked skill walk sealed by decompile ≡ disasm ≡ string/RTTI bytes. Residual product English → **accept-with-gaps**.
