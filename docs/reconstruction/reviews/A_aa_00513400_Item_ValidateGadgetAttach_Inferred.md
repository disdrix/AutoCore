# Review A (reconstruction fidelity): `aa_00513400` Item_ValidateGadgetAttach_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513400` |
| **VA** | `0x00513400`–`0x005134d4` inclusive (**213 B** / `0xD5`) |
| **Canonical name** | `Item_ValidateGadgetAttach_Inferred` |
| **Prior names** | `FUN_00513400`; `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513400` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-035 OWN-ONLY dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00513400_Item_ValidateGadgetAttach_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Gadget attach validator** for a host item:

| Stage | Result |
|---|---|
| Type mismatch (no 0x44/0x46 exception) | return **2** |
| Used slots == capacity | return **1** |
| Installed slot id matches gadget id (low 16) | return **3** |
| Else | return **0** (allow) |

Consumers (not owned): dualed hover mode-5 (`FUN_0085ce20` + `CVOGGadget` RTTI) and apply-confirm `FUN_0085fa20` map codes to product strings. Pure predicate — **no** inventory mutation.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513400_FUN_00513400.md` |
| Annotated | `docs/reconstruction/raw/aa_00513400_FUN_00513400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_ValidateGadgetAttach_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00513400.cpp` |
| Function records | `docs/reconstruction/functions/aa_00513400_FUN_00513400.md` + named |
| Live | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` 220 B + callers/xrefs + `get_assembly_context` on 4 sites |
| Parent dual | `A/B_aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` |
| Not performed | `disassemble_bytes`, Launcher, bit-exact, runtime CE |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00513400`–`005134d4`, `RET 4` ×4 | **High / Sealed** | disasm + bytes `C2 04 00` |
| `__thiscall` ECX=host item, stack=gadget | **High / Sealed** | `MOV ESI,ECX`; callers PUSH gadget / MOV ECX item |
| Type gate + 0x44/subtype10 + 0x46/subtype11 | **High / Sealed** | `SUB EAX,0x44` / `SUB EAX,2` + word compares |
| Return 1 = used==cap via vtbl +0x8c / +0x80 | **High / Sealed** | `MOVSX` + `SUB` + `JZ` |
| Return 3 = dup via vtbl +0x7c loop | **High / Sealed** | `MOVZX AX` vs gadget `+0x34` |
| Return 0 = allow | **High / Sealed** | `XOR EAX,EAX` |
| Codes ↔ parent UI strings | **High / Sealed** | dualed `0085ce20` mode 5 + `0085fa20` |
| Product/PDB symbol | **Tentative** | `_Inferred` |
| Vtbl English (used/cap/get-id) | **Probable** | role from CF + strings |
| Type-id English 0x44/0x46 | **Tentative** | constants only |
| Orphan xref `0085d6bb` owner | **Open** | outside `0085ce20` body end |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load gadget type via ac-chain +0x4c4 | **Yes** |
| Compare to hostComp+0x38 (`item+0xa8`) | **Yes** |
| Exception branches 0x44/10 and 0x46/11 | **Yes** |
| return 2 on type fail | **Yes** |
| vtbl +0x8c vs +0x80 → return 1 | **Yes** |
| Loop vtbl +0x7c / +0x80 → return 3 | **Yes** |
| return 0 | **Yes** |
| No non-virtual callees | **Yes** (leaf) |

---

## 5. ABI seal

```text
00513400  PUSH EBP
00513401  MOV  EBP, [ESP+8]     ; gadget
00513409  MOV  ESI, ECX         ; host item
…
00513447  RET  4                ; return 2
0051347b  RET  4                ; return 1
005134c6  RET  4                ; return 0
005134d2  RET  4                ; return 3
```

Call-site pattern (all named callers):

```text
PUSH <gadget*>
MOV  ECX, <item*>
CALL 0x00513400
TEST EAX,EAX / CMP EAX, imm
```

---

## 6. Gaps

1. Product/PDB demangle for host class and vtbl slots.
2. English for type constants **0x44** / **0x46** and subtype words **10** / **11**.
3. Full dual of `FUN_00514190` / `FUN_0085fa20` (not OWN).
4. Function boundary for xref `0x0085d6bb`.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
