# Review B (skeptical / adversarial): `aa_004062a0` StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004062a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9H-C) |
| **Counterpart** | `reviews/A_aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same body as `00406220` (merge symbols) | **Falsified** — different magic (`0x2AAAAAAB` vs `0x66666667`), stride add (`+0xc` vs `+0x28`), distinct ConstructN/insert engines |
| 2 | Tree / skill-hash operation | **Falsified** — pure vector triad |
| 3 | Stride is 4 or 0x28 | **Falsified** — `/0xc` + `add esi,0xc` |
| 4 | Thiscall ECX=vec | **Falsified** — **EAX**=vec; **ECX**=value* |
| 5 | Always reallocates | **Falsified** — capacity gate fast path |
| 6 | Insert-one result used | **Falsified** — void push_back; out scratch discarded |
| 7 | Multiple call sites imply domain name | **Falsified** — **one** xref to static `0x00d1a82c`; still generic util |
| 8 | Decompiler void signature complete | **Partially true** — return void sealed; host register must be recovered |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX/ECX/ret0 ABI | **High** | Call-site corruption |
| `/0xC` capacity gate | **High** | Wrong growth |
| ConstructN `00409db0` + end+=12 | **High** | Element not written |
| Insert-one `00406e70` sole parent role | **High** | Grow path break |
| Product demangle | Medium | Naming |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
mov edi, eax
begin=[edi+4]; if 0 → slow
size=(end-begin)/12; cap=(capEnd-begin)/12   ; magic 0x2AAAAAAB
if size >= cap → slow
push value; push vec; push 1; push end; call 00409db0; add esp,16
end += 0xC; ret
; slow: call 00406e70 insert-one at end
```

Sole site: `MOV EAX,0x00d1a82c` / `LEA ECX,[ESP]` before `CALL 004062a0`.

Do **not** merge with 0x28 twin. Do **not** invent domain name from single static consumer.

---

## 4. Surviving contract for AutoCore

```csharp
// void PushBack(ref VectorElem12 v, in Elem12 value)
// EAX=v, ECX=&value, ret 0
// spare → ConstructN@end; else InsertOne_Rebind_Elem12(end)
```

Pair insert-one `00406e70`, ConstructN `00409db0`, twin push_back `00406220`.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm elem-12 push_back twin of `00406220`. Residual: product type, ConstructN dual, runtime. Not reject.
