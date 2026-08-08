# Review A (reconstruction fidelity): `aa_00521eb0` Item_GetTinkerSkillOrCap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521eb0` |
| **VA** | `0x00521eb0`–`0x00521ef6` inclusive (**71 B** / `0x47`) |
| **Canonical name** | `Item_GetTinkerSkillOrCap_Inferred` |
| **Ghidra name** | `FUN_00521eb0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0` (**retired**) |
| **Rejected misname** | `Character_GetTinkerSkillOrCap` as ECX=character |
| **Review date** | `2026-08-05` (MEGA-106 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md` |
| **System** | inventory-transfer / tinker kit skill-tier map |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_xrefs_to` + `get_function_by_address` + full caller disasm. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **item skill-tier / cap mapper** for tinkering:

```text
Item_GetTinkerSkillOrCap_Inferred(item) -> tier 0..5
  v = item[+0x59b]
  0 -> 0
  1..9 paired to 1..5 via jump table
  >=10 -> 5
```

Parents compare the return against **character** `vfunc(+0x8c)+1` when validating tinker kit use / computing tinker float terms.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold raw CF (switch 1..9 + default) |
| Full body | `disassemble_function` + `read_memory` 71 B + jump table 36 B |
| Field | `MOV AL,[ECX+0x59b]` |
| Callers | `FUN_00513c10` @ `0x00513ca4`; `FUN_00521f20` @ `0x00521f59` |
| ECX seal | both sites `MOV ECX,EDI` with EDI = item (`+0x6b4` peer) |
| Callees | none (leaf) |
| Xrefs | 2 UNCONDITIONAL_CALL |

---

## 3. Signature (sealed)

```c
// ECX = item; no stack args; EAX = tier 0..5; plain RET
std::uint8_t __thiscall Item_GetTinkerSkillOrCap_Inferred(void *item);
```

| Formal | Source | Conf |
|---|---|---|
| item | **ECX** (`[ECX+0x59b]`) | **Confirmed** |
| stack args | none | **Confirmed** (`RET` / `C3`) |
| return | **EAX** 0..5 | **Confirmed** |
| jump table | `0x00521ef8` 9 dwords | **Confirmed** |
| default ≥10 | `SBB`/`AND 5` → 5 | **Confirmed** |

**Note:** Ghidra `analyze` signature display `undefined FUN_00521eb0(void)` is **incorrect**; decompiler + assembly seal ECX this + EAX return.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Load `+0x59b`; zero → return 0 | bytes + decompile | **Confirmed** |
| `v-1` index; table jump for 1..9 | JMP `[ECX*4+0x521ef8]` | **Confirmed** |
| Pair map 1-2→1 … 9→5 | table targets | **Confirmed** |
| Default v>9 → 5 | SBB/AND path | **Confirmed** |
| Leaf (no CALL) | analyze callees empty | **Confirmed** |
| Product field English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **leaf** |
| External callers | **2** UNCONDITIONAL_CALL |
| Site role | item-side tier for tinker skill gate / float gate |
| Callees | none |
| Parent system | inventory-transfer (partition MEGA-106; parent `0x00513c10`) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Item ECX via call sites (not character) | **Yes** |
| Field `+0x59b` map to 0..5 cap | **Yes** |
| Tinker parents (validate / float helper) | **Yes** (caller CF) |
| In-body product string | **No** |
| Partition hint Character_* literal | **No** — corrected to Item_* |

**Decision:** promote **`Item_GetTinkerSkillOrCap_Inferred`**. Retire Named_CalleeOf scaffold. Keep `_Inferred` until field English sealed.

---

## 7. Gaps

- Product English for `item+0x59b` (rank vs quality vs kit level).
- Product name of character vfunc `+0x8c`.
- Full dual of parents `00513c10` / `00521f20` (out of OWN scope).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/mapping/call-site ECX with only product-field English residual → **accept-with-gaps**.
