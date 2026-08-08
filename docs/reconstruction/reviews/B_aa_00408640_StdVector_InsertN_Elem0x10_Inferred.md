# Review B (skeptical / adversarial): `aa_00408640` StdVector_InsertN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9H-H) |
| **Counterpart** | `reviews/A_aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + call-site context + callee peeks. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is CNDHash freelist / stamp / recreate | **Falsified** — vector triad + `operator_new` insert-N; no hash buckets |
| 2 | Element stride is 4 (dword InsertN twin) | **Falsified** — all math `>>4` / `*0x10`; caller `ADD …,0x10` |
| 3 | Element stride is 0x28 like neighborhood InsertN | **Falsified** — no `0x66666667` magic; pure shift-4 |
| 4 | Pure `__thiscall` ECX=vec like dword InsertN | **Falsified** — **ECX=count**, **EDX=vec**; site sets ECX=1 then LEA EDX vec |
| 5 | `operator_delete` never returns (decompiler) | **Falsified** — triad writes after delete on realloc path |
| 6 | Scaffold Input_Poll name is domain role | **Falsified** — generic container helper; sole caller uses count=1 insert |
| 7 | Returns new end in EAX as primary contract | **Unproven / unused** — void-ish; updates triad in place; RET 8 |
| 8 | max_size uses dword `0x3fffffff` | **Falsified** — `0x0FFFFFFF` (elem-count max for 0x10) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-N role | **High** | Wrong container op on port |
| Stride 0x10 | **High** | Buffer overflow / under-allocate |
| ABI ECX count / EDX vec / ret 8 | **High** | Corrupt regs / stack imbalance |
| 1.5× growth CF | **High** | Capacity bugs |
| Helper English names | Medium | Naming only |
| Product POD type | Low–Medium | Domain mislabel only |

---

## 3. Cross-check

```
capacity = (capEnd-begin)>>4
if count==0 return
if size+count > max: throw FUN_00418130
if need grow:
  newCap = 1.5× else exact; new = operator_new(newCap<<4)
  copy [begin,where); construct-N *value; copy [where,end)
  delete old; triad = new
else in-place shift/fill; end += count*0x10
ret 8
```

Do **not** merge with:
- `aa_004073a0` InsertN **dword** (thiscall ECX=vec)
- `FUN_00408050` InsertN **0x28**
- CNDHash freelist `0x004085e0` / table helpers

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared vector insert-n, elem size 16
void VectorInsertN_Elem16(ref Vec16 v, ref Elem16 where, int count, in Elem16 value)
{
    // ECX=count, EDX=&v, stack where + &value, ret 8
    // growth 1.5×; triad +4/+8/+0xC
}
```

**Verdict:** **accept-with-gaps** — CF/ABI/stride sealed; product demangle + helpers residual.
