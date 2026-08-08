# Review B (skeptical / adversarial): `aa_00409db0` StdVector_ConstructN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409db0` |
| **VA** | `0x00409db0` |
| **Canonical name** | `StdVector_ConstructN_Elem12_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |
| **System** | util / container (`std::vector` POD **elem 0xC**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is insert-N / grow | No operator_new/delete; no triad writes | **Falsified** insert claim |
| 2 | Decomp signature is complete (2 stack args only) | Bytes: `mov ebx,ecx` before loop; value is ECX | **Falsified** incomplete ABI |
| 3 | PodCopy does not advance — elements overlap | Parent steps `add esi,0x0C` each iter | **Falsified** overlap claim |
| 4 | Stride is 0x28 (elem0x28 twin) | `add esi,0x0C`; PodCopy 3 dwords not 10 | **Falsified** stride-0x28 |
| 5 | Stride is 4 (dword vector) | 3 dwords / +0x0C | **Falsified** dword |
| 6 | `ret 4` / stdcall stack cleanup | Ends **`C3`** plain ret | **Falsified** stdcall model |
| 7 | thiscall ECX=vector host | ECX is value*; no vector triad touch | **Falsified** vec-this |
| 8 | Same as Ufill `00406ee0` | Distinct VA; Ufill calls this then returns end | **Falsified** merge |
| 9 | Same as ConstructN elem0x28 `00409d40` | Different stride/callee (0xC vs 0x28) | **Falsified** merge |
| 10 | Product `std::uninitialized_fill_n` required | No RTTI/string on VA | **Agree** `_Inferred` |
| 11 | PodCopy uses EDX src like 0x28 leaf | Bytes: `mov ecx,ebx` then call — **ECX=src** | **Falsified** EDX model |
| 12 | count signed vs unsigned traps | `jbe` on count (unsigned-style); empty early-out | **No CF reject** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX value + dest/count stack | **Confirmed** | Wrong construct in ports |
| dest += 0x0C / 3 dwords | **Confirmed** | Element smash / mis-align |
| Plain ret (caller cleans) | **Confirmed** | Stack imbalance |
| Role under Ufill / push_back | **Confirmed** | Misplace construct |
| Product type English | **Open** | Cosmetic |
| Runtime | **Open** | No live stamp capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile_function (2026-08-05);
bytes @ 0x00409db0:
  SEH prolog LAB_009bc620
  mov ebx,ecx                 ; value*
  mov edi,[ebp+0xC]           ; count
  mov esi,[ebp+8]             ; dest
  loop: test edi / jbe done
        mov ecx,ebx; mov eax,esi
        call FUN_00409f50     ; 3 dwords
        sub edi,1
        add esi,0x0C
        jmp loop
  SEH teardown; leave; ret (C3)
```

### ABI trap

Do **not** trust decompiler `void FUN_00409db0(param_1,param_2)` alone — **ECX value** and **dest+=0x0C** are load-bearing and only sealed by bytes / parent push patterns.

### Stride trap

Do not paste ConstructN elem0x28 (`00409d40` / +0x28 / 10 dwords). This instantiation is **0x0C / 3 dwords**.

### PodCopy ABI trap

Leaf `00409f50` is **EAX=dst, ECX=src** — not EAX/EDX like `00409f30`.

### Role trap

This is the **inner stamp loop**, not the Ufill return-end wrapper (`00406ee0`) and not InsertN (`004082f0`).

---

## 4. Residual gaps (agreed with A)

1. Product type English for 0x0C-byte `T`.
2. Full dual of PodCopy `00409f50`.
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; ABI/stride/role sealed; product open.
