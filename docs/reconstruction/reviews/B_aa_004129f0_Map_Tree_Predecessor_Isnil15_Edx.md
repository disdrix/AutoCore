# Review B (skeptical / adversarial): `aa_004129f0` Map_Tree_Predecessor_Isnil15_Edx

| Field | Value |
|---|---|
| **Stable ID** | `aa_004129f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-M) |
| **Counterpart** | `reviews/A_aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs + assembly context. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is iterator **successor** (`operator++`) | **Falsified** — left-subtree rightmost + climb-while-left is classic **predecessor** |
| 2 | ABI is `__thiscall` / ECX = it (same as `0x005a2850`) | **Falsified** — entry `mov eax,[edx]`; sites `lea edx,…` |
| 3 | isnil is at +0x19 (Val12) | **Falsified** — all probes `+0x15` |
| 4 | Mission-specific active-objective logic | **Falsified** — pure link walk; 8 heterogeneous callers; scaffold Named_CalleeOf rejected |
| 5 | Has callees / allocates | **Falsified** — leaf, no `E8` |
| 6 | Decompiler void + fastcall pair is the full ABI story | **Partially misleading** — void OK; invented `param_1` unused; **EDX** is the real register |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predecessor CF | **High** | Wrong tree walk / skip nodes |
| EDX ABI | **High** | Callers pass it in EDX — ECX port would smash |
| isnil +0x15 | **High** | Read wrong flag / infinite loop |
| Generic role | **High** | Overfit mission English |
| Product demangle | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
mov eax, [edx]           ; *it
cmp byte ptr [eax+0x15], 0
jnz → *it = [eax+8]; ret  ; isnil → right
mov ecx, [eax]           ; left
cmp byte ptr [ecx+0x15], 0
jz  → rightmost(left); ret
; else climb parent while *it == parent->left
ret
```

Do **not** port as ECX twin of `0x005a2850` without changing the register.

---

## 4. Surviving contract for AutoCore

```csharp
// void Pred(ref Node* it)  — pass &it in EDX on x86 retail shape
// Node: Left@0 Parent@4 Right@8 Isnil@0x15
```

Shared infrastructure; pair with ECX peer only when call site matches.

---

## 5. Verdict

**accept** — adversarial checks strengthen EDX + predecessor + isnil15; no CF holes. Gaps are demangle/runtime only.
