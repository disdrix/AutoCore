# Review B (skeptical / adversarial): `aa_00406de0` StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9G-H) |
| **Counterpart** | `reviews/A_aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + parent/callee decompile. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler signature is complete (2 stack args + unaff_EDI noise) | **Partially true** — stack has **3** formals (ret 0xC); EDI is required register formal |
| 2 | This is tree insert / buynode (partition neighborhood) | **Falsified** — no RB color/isnil; pure vector begin/end/cap triad + `/0x28` |
| 3 | Element stride is 4 (dword twin drop-in) | **Falsified** — magic `0x66666667` + `lea`×0x28; not `>>2` |
| 4 | Insert count is variable | **Falsified** — immediate `push 1` |
| 5 | Thiscall ECX=vec like `0040dbf0` | **Falsified** — vec in **EDI**; ECX only loaded for callee |
| 6 | Out-iterator in EBX like dword rebind `0040b6d0` | **Falsified** — out on **stack** (EBP load); ret **0xC** not 8 |
| 7 | Value is 0x28 bytes by-value on stack | **Falsified** — ret 0xC = 3×ptr; EDX gets value pointer into insert-N |
| 8 | Index rebind is optional | **Falsified** — always writes `*out` after call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI + 3 stack + ret 0xC ABI | **High** | Stack/register corruption |
| count=1 via `00408050` | **High** | Wrong growth path |
| Index rebind `/0x28` | **High** | Iterator invalid after realloc |
| Not tree/buynode | **High** | Wrong system ownership |
| Product demangle / POD fields | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
begin = [edi+4]
if begin==0 || size==0: index=0
else index = (where-begin)/0x28   ; magic 0x66666667
mov edx, value; push 1; push where; mov ecx, edi; call 00408050
*out = [edi+4] + index*0x28
eax = out; pop esi; pop ebp; pop ebx; ret 0xC
```

Parent `00406220`: capacity room → ConstructN@end count=1 + end+=0x28; else this unit with where=end.

Do **not** port as thiscall dword rebind. Do **not** name as tree insert despite VA neighborhood of `00406c40`.

---

## 4. Surviving contract for AutoCore

```csharp
// void InsertOne_Rebind(ref VectorElem0x28 v, out Elem* it, Elem* where, in Elem value)
// EDI=v, stack out/where/value*, ret 0xC
// engine = FUN_00408050 (insert-N count=1)
```

Shared infrastructure; pair with push_back parent `FUN_00406220` and fill-n `00406e50` (this wave).

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm customcc insert-one rebind via 0x28 insert-N engine. Residual: undualed `00408050`, product POD layout, runtime. Not reject.
