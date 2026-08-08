# Review B (skeptical / adversarial): `aa_00406220` StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9H-C) |
| **Counterpart** | `reviews/A_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void __fastcall (param_1)` with phantom `in_EAX` is the full ABI | **Partially true** — ECX=value* is real; **EAX=vec*** is required host formal (not ECX thiscall) |
| 2 | This is tree/buynode (VA near `00406c40`) | **Falsified** — begin/end/cap triad + `/0x28`; no RB/isnil |
| 3 | Element stride is 0xC (sibling drop-in) or 4 (dword) | **Falsified** — magic `0x66666667` + `add end,0x28` |
| 4 | Always grows via insert-one | **Falsified** — capacity-room fast path ConstructN only |
| 5 | Host in EDI or ECX on entry | **Falsified** — entry **EAX**; body moves to EDI for insert-one |
| 6 | Value is by-value 0x28 on stack | **Falsified** — pointer in **ECX**; construct/insert take `const T*` |
| 7 | Out-iterator from insert-one is consumed | **Falsified** — stack scratch only; push_back returns void |
| 8 | Scaffold product/mission name applies | **Falsified** — generic multi-caller container util |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX=vec / ECX=value* / ret 0 | **High** | Wrong call-site ABI |
| size/cap `/0x28` gate | **High** | Silent overflow / wrong grow |
| Fast ConstructN + end+=0x28 | **High** | Missed write / leak |
| Slow path sole use of `00406de0` | **High** | Broken grow |
| Product POD fields | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
mov edi, eax                 ; vec host
begin = [edi+4]
if begin==0 → slow
size = (end-begin)/0x28      ; magic 0x66666667
cap  = (capEnd-begin)/0x28
if size >= cap → slow
; fast:
push value; push vec; push 1; push end; call 00409d40; add esp,16
end += 0x28; ret
; slow:
push value; push end; lea out; push out; call 00406de0; ret
```

Callers `FUN_00933480` / `FUN_00976900` both set **EAX=vec**, **ECX=&local**.

Do **not** port as thiscall or dword push_back. Do **not** merge with elem-12 twin `004062a0`.

---

## 4. Surviving contract for AutoCore

```csharp
// void PushBack(ref VectorElem0x28 v, in Elem value)
// EAX=v, ECX=&value, ret 0
// spare capacity → ConstructN@end; else InsertOne_Rebind(end)
```

Shared infrastructure; pair insert-one `00406de0`, ConstructN `00409d40` (when dualed), twin push_back `004062a0`.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm EAX/ECX push_back for 0x28 POD with dual-path capacity gate. Residual: product type, ConstructN dual, runtime. Not reject.
