# Review A (reconstruction fidelity): `aa_00409ed0` SkillSet_CopyBackward_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409ed0` |
| **VA** | `0x00409ed0`–`0x00409f0a` inclusive (**59 B** / `0x3B`) |
| **Canonical name** | `SkillSet_CopyBackward_0x18` |
| **Ghidra name** | `FUN_00409ed0` |
| **Review date** | `2026-08-05` (MEGA-054 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409ed0_SkillSet_CopyBackward_0x18.md` |
| **System** | skills-abilities / SkillSet vector |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory` |
| **Verdict** | **accept** |

**Tools note:** **No** `disassemble_bytes`. No Launcher. No parent ledger edits. OWN VA only.

---

## 1. Purpose

Leaf **copy_backward** of **0x18-byte POD** SkillSet vector entries: reverse-walk `[src_begin, src_end)` into a destination ending at `dest_end`; return `dest_begin`. Used by SkillSet insert/reallocate parents when shifting the high half of a range (paired with forward `SkillSet_UninitializedCopy_0x18` @ `0x00442b00` at several sites).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-054 re-verify append) | `docs/reconstruction/raw/aa_00409ed0_FUN_00409ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00409ed0_FUN_00409ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_CopyBackward_0x18.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409ed0.cpp` |
| Function | `docs/reconstruction/functions/aa_00409ed0_FUN_00409ed0.md` |
| Function named | `docs/reconstruction/functions/aa_00409ed0_SkillSet_CopyBackward_0x18.md` |
| Body bytes | `read_memory` @ `0x00409ed0` length 64 — ends **`C3`**, pad `CC` |
| Callers | 5 sites via `get_function_callers` + assembly context |
| Forward twin | dualed `SkillSet_UninitializedCopy_0x18` (`0x00442b00`) |
| Stride peer | dualed `SkillSet_GetEntryCount` (`0x00402d80`) |

---

## 3. Signature (sealed)

```c
// EAX = dest_end, ECX = src_end, EDX = src_begin (exclusive end / inclusive begin)
// returns EAX = dest_begin; RET 0
void *SkillSet_CopyBackward_0x18(void *dest_end, void *src_end, void *src_begin);
```

| Formal | Source | Conf |
|---|---|---|
| dest_end | **EAX** | **High** — `SUB EAX,0x18` loop; pre-call `MOV EAX,…` at sites |
| src_end | **ECX** | **High** — decompiler `param_1`; `SUB ECX,0x18` |
| src_begin | **EDX** | **High** — decompiler `param_2`; empty `CMP EDX,ECX` |
| return dest_begin | **EAX** | **High** — empty leaves EAX; non-empty leaves after reverse walk |
| stack | none | **High** — `RET` not `RET n` |

Decompiler residual: `void` + phantom `in_EAX` — **corrected** via assembly/callers (same class of residual as forward twin).

---

## 4. Control flow (clean ≡ raw ≡ live)

```
if EDX == ECX: ret                    ; empty
push ebx/esi/edi
loop:
  ECX -= 0x18; EAX -= 0x18
  cmp ECX, EDX
  copy 6 dwords [ECX] → [EAX]
  jnz loop                            ; flags from cmp (MOVs preserve)
pop edi/esi/ebx
ret
```

| Stage | Match | Conf |
|---|---|---|
| Empty early `jz` → `ret` | **Yes** | **High** |
| Stride `0x18` / 6 dwords | **Yes** | **High** |
| Reverse walk (SUB not ADD) | **Yes** | **High** |
| No null-dest skip | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| 5 SkillSet-family callers | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (59 B):
```
3bd1743653565783e91883e8183bca8bf18b1e8bf8891f8b5e04895f048b5e08895f088b5e0c895f0c8b5e10895f108b761489771475d05f5e5bc3
```

Decompile ≡ bytes for CF. Phantom `in_EAX` = dest; return advanced reverse EAX.

---

## 6. Naming

| Candidate | Ruling |
|---|---|
| `FUN_00409ed0` | Scaffold only |
| `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00409ed0` | **Reject / retire** — chain-of-caller; not role |
| GetEntryCount identity | **Reject** — real count is `0x00402d80` |
| Merge with forward `00442b00` | **Reject** — direction + null-skip differ |
| Tree/list rotate | **Reject** — pure POD memcopy loop |
| `SkillSet_CopyBackward_0x18` | **Accept** — role + stride + parent family sealed |

---

## 7. Gaps

1. Product field layout of the 0x18-byte entry.  
2. MSVC demangle exact symbol (`_Copy_backward` vs local helper).  
3. Runtime / bit-exact / differential.  
4. Parent insert bodies not dualled in this OWN task.

---

## Verdict

**accept** — reverse 0x18 POD range-copy kernel, ABI EAX/ECX/EDX/RET0, and SkillSet vector role sealed from live decompile + assembly + 5 call sites. Gaps are product English / runtime only.
