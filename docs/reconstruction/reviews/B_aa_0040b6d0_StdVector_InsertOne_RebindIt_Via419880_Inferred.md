# Review B (skeptical / adversarial): `aa_0040b6d0` StdVector_InsertOne_RebindIt_Via419880_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b6d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ7R-E) |
| **Counterpart** | `reviews/A_aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + parent decompile/bytes + callee dual. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler signature is complete (2 stack args only) | **Partially true** — stack has 2 formals, but **EDI/EBX** are required; unaff_* not optional |
| 2 | This is thiscall like `0040dbf0` | **Falsified** — no `mov reg,ecx` vector install; EDI from parent; **ret 8** not 0xC |
| 3 | Element stride is not 4 | **Falsified** — `>>2` / `lea [reg+esi*4]` |
| 4 | Insert count is variable | **Falsified** — immediate `mov ecx,1` |
| 5 | Mission-domain helper (journal-only logic) | **Falsified as domain** — generic vector; journal is only known chain |
| 6 | Index rebind is optional | **Falsified** — always writes `*ebx` after call |
| 7 | Drop-in of `00466da0` binary | **Falsified as identical** — same ABI shape, **different** insert engine (`419880` vs `456960`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI/EBX + ret 8 ABI | **High** | Stack/register corruption |
| count=1 via CountEcx engine | **High** | Wrong growth path |
| Index rebind formula | **High** | Iterator invalid after realloc |
| Generic role | **High** | Overfitting mission English |
| Product demangle | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
begin = [edi+4]
if begin==0 || size==0: index=0
else index = (where-begin)>>2
push value; push where; push edi; ecx=1; call 00419880
*ebx = [edi+4] + index*4
eax = ebx; pop esi; ret 8
```

Parent `00411180`: capacity room → `*end++=*esi`; else this unit with `where=end`.

Do **not** port as thiscall `0040dbf0`. Do **not** call `004073a0` from this site (CountEcx ABI required).

---

## 4. Surviving contract for AutoCore

```csharp
// void InsertOne_Rebind(ref VectorDword v, out uint* it, uint* where, uint value)
// EDI=v, EBX=&it, stack where/value*, ret 8
// engine = StdVector_InsertN_Dword_CountEcx (count=1)
```

Shared infrastructure; pair with push_back parent `FUN_00411180` (owned elsewhere under WQ7R-D residual set).

---

## 5. Verdict

**accept** — adversarial checks confirm customcc insert-one rebind via CountEcx engine. Residual demangle/runtime only. Not reject.
