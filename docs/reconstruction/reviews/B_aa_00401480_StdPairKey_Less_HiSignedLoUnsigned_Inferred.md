# Review B (skeptical / adversarial): `aa_00401480` StdPairKey_Less_HiSignedLoUnsigned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9G-B) |
| **Counterpart** | `reviews/A_aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Both dwords **signed** | **Falsified** — lo uses **JAE** (unsigned) |
| 2 | Both dwords **unsigned** | **Falsified** — hi uses **JG/JL** (signed) |
| 3 | lo primary, hi secondary | **Falsified** — hi compared first |
| 4 | Equality / three-way compare | **Falsified** — only 0/1 strict less |
| 5 | thiscall ECX first key | **Falsified** — both args on stack; RET 8 |
| 6 | RET 0 / bare C3 | **Falsified** — `C2 08 00` ×2 |
| 7 | VOG_DEBUG product leaf | **Narrow** — generic comparator; two hint callers |
| 8 | Same as int-key SETL single-dword | **Falsified** — 2-dword mixed signedness |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 stack ABI | **High** | stack smash on hint insert |
| hi signed / lo unsigned order | **High** | sort bugs / wrong insert side |
| Strict less only | **High** | equal-key mishandled as insert |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
a = [esp+4]; b = [esp+8]
if (int)a[1] > (int)b[1]: return 0   ; JG
if (int)a[1] < (int)b[1]: return 1   ; JL
if a[0] < b[0]: return 1              ; unsigned (not JAE path)
return 0
ret 8
```

Clean must **not** invert hi/lo order, use signed lo, or claim int-key single-dword compare.

---

## 4. Surviving contract for AutoCore

```csharp
// Leaf pair-key less; two stack ptrs; ret 8; EAX = 0|1
bool StdPairKey_Less_HiSignedLoUnsigned(in Key2 a, in Key2 b)
{
    // hi signed primary @ +4; lo unsigned secondary @ +0
    if (a.hi != b.hi) return a.hi < b.hi;
    return a.lo < b.lo; // unsigned
}
```

Insert-hint ports for isnil29 pair maps must preserve this mixed signedness (matches pair insert-or-find order).

---

## 5. Open questions

1. Product type of the 2-dword key (TFID-like vs custom).  
2. Whether `FUN_00406560` is isnil@+0x21 twin of dualed isnil29 hint.  
3. Runtime / bit-exact.
