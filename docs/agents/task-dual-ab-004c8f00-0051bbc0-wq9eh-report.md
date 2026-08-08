# Dual A/B report — WQ9E-H OWN-ONLY (`aa_004c8f00`, `aa_0051bbc0`)

**Date:** 2026-08-04  
**Agent:** WQ9E-H OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004c8f00`, `0x0051bbc0`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-2 residual — hash recreate second caller site + skill-neighborhood map free-subtree.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c8f00` Object_CreateCreatureLoadSkills_Inferred | **accept-with-gaps** — create/cast/recreate(log2=2)/skill walk CF+ABI+strings sealed; product method English open |
| `aa_0051bbc0` Map_FreeSubtree_Isnil29 | **accept-with-gaps** — free-subtree CF/ABI/isnil@+0x29 sealed by bytes (decomp incomplete); product map type open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; sole-recreate-caller, decompiler-complete free, aggro-product-name, thiscall-no-stack free all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x004c8f00` Object_CreateCreatureLoadSkills_Inferred

1. **Body:** `0x004c8f00`–`0x004c9113` inclusive (**532 B** / `0x214`); `CC` pad from `0x004c9114`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = source this (MI-adjusted host)  
   - no stack args  
   - returns creature primary* in EAX, or 0  
   - plain **`RET`** both exits

3. **Algorithm:**  
   - `Object_CreateFromEmbeddedCbid_Inferred` on MI subobject `source-0x4fc`  
   - `__RTDynamicCast` → `CVOGCreature` (TD `0xaf8d0c` `.?AVCVOGCreature@@`; from `0xaf8e10` ClonedObjectBase)  
   - Copy vtbl-derived stats + fields (`+0x150`, `+0x128`, accuracy `+0x13e`/`+0x142`, `+0x100`, optional `+0x30b`)  
   - **`SkillCNDHash_Recreate_Inferred(destHash@+0x70, log2=2)`** — imm `PUSH 2` @ `0x004c902a`  
   - Soft TraversalLock on source hash `@+0x1d`; ordered walk `+0x14`; payload `+8`  
   - `Skill_EnsureLoadedInTree(dest, *(skill+0x5fc), *(i16*)(skill+0x5f6))`  
   - Unlock; return dest MI primary

4. **Callers (2 MI thunks):**  
   - `0x004cd003` JMP  
   - `0x0053bd99` after `SUB ECX,0x8a0` JMP

5. **Name:** `Object_CreateCreatureLoadSkills_Inferred` — role High (RTTI + skill bank CF); product English **Inferred**.  
   Reject `Mission_CVOGClonedObjectBase_RTTI_Type_Descriptor`; reject `Named_VOG_DEBUG_STOP_004c8f00`.

6. **Decompile ≡ disasm** for CF; recreate site sealed vs WQ9D-A second-caller claim.

### Gaps — `004c8f00`

1. Product/PDB virtual method name.  
2. English for vtbl slots / combat fields copied.  
3. Nested dual of factory / EnsureLoadedInTree / accuracy helpers (not OWN).  
4. Full MI class map for thunk offsets.  
5. Runtime / bit-exact open.

### Dual A/B — `004c8f00`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md` | **accept-with-gaps** |

### Files — `004c8f00`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004c8f00_FUN_004c8f00.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8f00_FUN_004c8f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CreateCreatureLoadSkills_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c8f00.cpp` |
| Function | `docs/reconstruction/functions/aa_004c8f00_FUN_004c8f00.md` |
| Function named | `docs/reconstruction/functions/aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md` |

---

## Sealed facts — `0x0051bbc0` Map_FreeSubtree_Isnil29

1. **Body:** `0x0051bbc0`–`0x0051bbf4` inclusive (**53 B** / `0x35`); `CC` pad after `ret 4`.

2. **ABI:** **`__fastcall`/`__thiscall`-style** ECX = tree_base (threaded, unused in body); stack `node*`; void; **`ret 4`** (`C2 04 00`).

3. **Algorithm (bytes authority — decompiler incomplete):**  
   - If isnil `@+0x29` ≠ 0: return  
   - Loop: recurse free **right** `@+8`; capture **left** `@+0`; `operator_delete(node)`; advance left until isnil  
   - **No value destroy**

4. **Identity:** isnil@+0x29 family matching `Map_EraseRange` / `Map_EraseNode`. Twin CF at `MapFloatTfid_FreeSubtree_Isnil29_Inferred` `0x0058da00` (distinct VA). Discriminator vs `FUN_0051be90` (Map_EraseRange_B free).

5. **Caller (1 external):** `Map_EraseRange` (`0x0051c7c0`) full-clear @ `0x0051c7dc` push root.

6. **Name:** `Map_FreeSubtree_Isnil29` — structural High; pairs Map_EraseRange. Reject aggro-chain scaffold name.

7. **Decompile ⊊ bytes** for left-walk; **bytes sealed**.

### Gaps — `0051bbc0`

1. Product `map<K,V>` / value size.  
2. tree_base unused (threading only).  
3. Full host inventory beyond EraseRange.  
4. Runtime / bit-exact open.

### Dual A/B — `0051bbc0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051bbc0_Map_FreeSubtree_Isnil29.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051bbc0_Map_FreeSubtree_Isnil29.md` | **accept-with-gaps** |

### Files — `0051bbc0`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051bbc0_FUN_0051bbc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bbc0_FUN_0051bbc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil29.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051bbc0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051bbc0_FUN_0051bbc0.md` |
| Function named | `docs/reconstruction/functions/aa_0051bbc0_Map_FreeSubtree_Isnil29.md` |

---

## Chain context (not dualled; evidence only)

```text
Object_CreateCreatureLoadSkills_Inferred (0x004c8f00)          [OWN]
  ├─ Object_CreateFromEmbeddedCbid_Inferred (0x0051b230)       [prior dual]
  ├─ __RTDynamicCast → CVOGCreature
  ├─ SkillCNDHash_Recreate_Inferred (0x004cbdc0, log2=2)       [WQ9D-A; 2nd site]
  └─ Skill_EnsureLoadedInTree (0x0051a980)                     [not OWN]

Map_EraseRange (0x0051c7c0)                                    [WQ9D-H]
  └─ Map_FreeSubtree_Isnil29 (0x0051bbc0)                      [OWN]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c8f00` | Creature clone path must **always** recreate dest skill hash at **log2=2** (not caller log2 factory), then load skills from source hash under soft TraversalLock. thiscall on MI-adjusted source; return MI primary or null. |
| `0051bbc0` | Free-subtree only — **no** value dtor. Use **right-recurse + left-walk**; do not trust Ghidra noreturn collapse. RET 4; ECX may be unused but must be threaded from callers. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ disassemble_function / callers / xrefs / assembly_context).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); `_Inferred` where product English unproven.  
- Odd behavior preserved (soft hash locks; decompiler incompleteness documented).  
- **Terminal false.**
