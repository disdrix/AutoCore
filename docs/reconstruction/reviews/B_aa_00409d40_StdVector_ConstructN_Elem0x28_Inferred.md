# Review B (skeptical / adversarial): `aa_00409d40` StdVector_ConstructN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409d40` |
| **VA** | `0x00409d40` |
| **Canonical name** | `StdVector_ConstructN_Elem0x28_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` |
| **System** | util / container (`std::vector` POD **elem 0x28**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is insert-N / grow | No operator_new/delete; no triad writes | **Falsified** insert claim |
| 2 | Decomp signature is complete (2 stack args only) | Bytes: `mov ebx,ecx` before loop; value is ECX | **Falsified** incomplete ABI |
| 3 | PodCopy does not advance — elements overlap | Parent steps `add esi,0x28` each iter | **Falsified** overlap claim |
| 4 | Stride is 0xC (elem12 twin) | `add esi,0x28`; PodCopy 10 dwords not 3 | **Falsified** stride-12 |
| 5 | Stride is 4 (dword vector) | 10 dwords / +0x28 | **Falsified** dword |
| 6 | `ret 4` / stdcall stack cleanup | Ends **`C3`** plain ret | **Falsified** stdcall model |
| 7 | thiscall ECX=vector host | ECX is value*; no vector triad touch | **Falsified** vec-this |
| 8 | Same as Ufill `00406e50` | Distinct VA; Ufill calls this then returns end | **Falsified** merge |
| 9 | Same as ConstructN elem12 `00409db0` | Different stride/callee (0x28 vs 0xC) | **Falsified** merge |
| 10 | Product `std::uninitialized_fill_n` required | No RTTI/string on VA | **Agree** `_Inferred` |
| 11 | SEH means throwing ctor | Leaf is pure dword copy; SEH is MSVC template wrapper | **Attack weak** — POD copy sealed |
| 12 | count signed vs unsigned traps | `jbe` on count (unsigned-style); empty early-out | **No CF reject** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX value + dest/count stack | **Confirmed** | Wrong construct in ports |
| dest += 0x28 / 10 dwords | **Confirmed** | Element smash / mis-align |
| Plain ret (caller cleans) | **Confirmed** | Stack imbalance |
| Role under Ufill / push_back | **Confirmed** | Misplace construct |
| Product type English | **Open** | Cosmetic |
| Runtime | **Open** | No live stamp capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile_function (2026-08-04);
bytes @ 0x00409d40:
  SEH prolog LAB_009bc630
  mov ebx,ecx                 ; value*
  mov edi,[ebp+0xC]           ; count
  mov esi,[ebp+8]             ; dest
  loop: test edi / jbe done
        mov edx,ebx; mov eax,esi
        call FUN_00409f30     ; 10 dwords
        sub edi,1
        add esi,0x28
        jmp loop
  SEH teardown; pop regs; ret (C3)
```

### ABI trap

Do **not** trust decompiler `void FUN_00409d40(param_1,param_2)` alone — **ECX value** and **dest+=0x28** are load-bearing and only sealed by bytes / parent push patterns.

### Stride trap

Do not paste ConstructN elem12 (`00409db0` / +0xC / 3 dwords). This instantiation is **0x28 / 10 dwords**.

### Role trap

This is the **inner stamp loop**, not the Ufill return-end wrapper (`00406e50`) and not InsertN (`00408050`/`004082f0`).

---

## 4. Residual gaps (agreed with A)

1. Product type English for 0x28-byte `T`.
2. Full dual of PodCopy `00409f30`.
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; ABI/stride/role sealed; product open.
