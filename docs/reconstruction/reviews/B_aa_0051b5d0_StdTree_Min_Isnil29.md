# Review B (skeptical / adversarial): `aa_0051b5d0` StdTree_Min_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b5d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0051b5d0_StdTree_Min_Isnil29.md` |
| **Verdict** | **accept** on CF/ABI/return; product symbol residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Decompiler `void` means no return value | Callers `piVar3 = (int*)FUN_0051b5d0(piVar6)`; bytes leave EAX = node | **Falsified** — returns node* |
| 2 | Walks until **nil** and returns the sentinel | Early exit keeps original when left isnil; loop exits with EAX = last non-nil | **Falsified as return-nil** |
| 3 | This is skill-domain logic | 5 erase-family callers; `"invalid map/set<T> iterator"` | **Falsified as skill-only** |
| 4 | isnil is @ +0x19 (Val12 twin) | Bytes `+0x29` only | **Falsified** — separate node class |
| 5 | Rightmost / `_Max` | Only follows `*node` (left) | **Falsified** — min/leftmost |
| 6 | `__thiscall` ECX node | `mov eax, [esp+4]` | **Falsified** — stack arg / cdecl |
| 7 | Scaffold `Named_CalleeOf_…Aggro` is product | Generic tree leaf | **Superseded** by role name |
| 8 | Mutates tree links | Only loads | **Falsified** — pure walk |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leftmost + isnil@+0x29 + EAX | **High** | Wrong erase Lmost → tree corruption in port |
| Map/set erase consumer | **High** | Mis-domain docs |
| Product symbol | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0051b5d0  mov  eax, [esp+4]
0051b5d4  mov  ecx, [eax]              ; left
0051b5d6  cmp  byte ptr [ecx+0x29], 0
0051b5da  jne  ret                     ; return original node
0051b5e0  mov  eax, ecx
0051b5e2  mov  ecx, [eax]
0051b5e4  cmp  byte ptr [ecx+0x29], 0
0051b5e8  je   0051b5e0
0051b5ea  ret                          ; EAX = leftmost non-nil
```

Live 2026-08-04 ≡ 2026-07-23 raw decompile body; **return semantics corrected from bytes** (same pattern as dual of `StdTree_Min_Val12`).

---

## 4. Surviving contract for AutoCore

```
// After map erase unlink when successor subtree non-nil:
head->left = StdTree_Min_Isnil29(successorOrChild);
// Node: left@0, isnil@+0x29; do not use Val12 (+0x19) offsets here.
```

**Verdict:** **accept**.
