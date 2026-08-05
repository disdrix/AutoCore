# Review A (reconstruction fidelity): `aa_00509940` GetModifierSkillID

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509940` |
| **VA** | `0x00509940`–`0x00509a78` exclusive (**312** B) |
| **Canonical name** | `GetModifierSkillID` |
| **Ghidra symbol** | `FUN_00509940` |
| **Prior / alias** | `Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i_00509940` |
| **Review date** | `2026-07-29` (W23-P OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00509940_GetModifierSkillID.md` |
| **System** | skills / modifier ID resolution |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Product API **`GetModifierSkillID`**: map an **IDPrefix** to a modifier **skill id**.

1. Lower-bound find in global int-key map `DAT_00b041dc`; type at found node `+0x10`.
2. Switch on type into six linear handler-table finds on **registry this**.
3. Return `*(entry + 0x9c)` on hit; on total failure log and return **`-1`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_00509940_FUN_00509940.md` (+ W23-P append) |
| Annotated | `raw/aa_00509940_FUN_00509940.annotated.md` |
| Clean | `reconstructed-exact/GetModifierSkillID.cpp` |
| Scaffold | `reconstructed-exact/FUN_00509940.cpp` |
| Function record | `functions/aa_00509940_GetModifierSkillID.md` |
| Live decompile | ≡ raw body |
| Live body bytes | `read_memory` @ `0x00509940` (256+) + tail / jump table |
| Product string | `read_memory` @ `0x009cdc88` → `GetModifierSkillID() passed an invalid IDPrefix: %i\n` |
| Nested duals | `HandlerTable54/58_FindById6c` (W20-R / W21-D) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. ABI / byte seal

| Fact | Evidence |
|---|---|
| Body 312 B | `get_function_by_address` `00509940`–`00509a78` |
| `ret 4` | all exits `C2 04 00` |
| ECX = registry | `mov edi, ecx` then `mov ecx, edi` before each helper |
| Stack = idPrefix | `mov esi, [esp+0xC]` after two pushes |
| Map this | `mov ecx, 0x00b041dc` before `Map_LowerBoundFindByIntKey` |
| Jump table | dword table @ `0x00509a7c`, index bytes @ `0x00509a98` |

### Type → helper (sealed)

| Type | Helper |
|---|---|
| `0x0C` | `FUN_00508ac0` |
| `0x1C` | `FUN_00508b10` |
| `0x0A` | `FUN_00508b60` |
| `0x0E` | `FUN_00508bb0` |
| `0x46` | `FUN_00508c00` / HandlerTable54 |
| `0x44` | `FUN_00508c50` / HandlerTable58 |

Success field: **`entry+0x9c`**. Fail default: log level 1 GetModifierSkillID string; **`or eax,-1`**.

### Fallthrough (sealed)

Failed table lookup does **not** `break` — control continues into the next case body in binary case order. Clean preserves fallthrough.

### Decompiler residuals corrected

- Missing thiscall ECX (shown as free function + `unaff_EDI`).
- Map call does not take registry EDI as map this.

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Product name GetModifierSkillID | **High** |
| Map → type → table → `+0x9c` | **High** |
| `__thiscall` registry + `ret 4` | **High** |
| Case set {0xA,0xC,0xE,0x1C,0x44,0x46} | **High** |
| Fallthrough-on-miss | **High** |
| Type English / class name of registry | **Open** |
| Whether fallthrough is intentional product vs empty-case codegen | **Med** (bytes still execute) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**

---

## 5. Gaps

1. Registry class English name.  
2. Semantic labels for type codes.  
3. Dual of remaining helpers `00508ac0`/`b10`/`b60`/`bb0` if not already sealed.  
4. Runtime golden for prefix→skill mapping.  
5. Intent of fallthrough-on-miss vs strict type isolation.
