# Review B (skeptical / adversarial): `aa_00408050` StdVector_InsertN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408050` |
| **VA** | `0x00408050` |
| **Canonical name** | `StdVector_InsertN_Elem0x28_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` |
| **System** | util / container (`std::vector` POD **elem 0x28**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body allocates / fills / advances end | **Falsified** erase |
| 2 | Stride 4 (dword InsertN twin) | All math `/0x28` and `*0x28`; magic `0x66666667` | **Falsified** dword |
| 3 | Stride 0xC (InsertN twin `004082f0`) | Value snap **10** dwords not 3; Ufill `00406e50` not `00406ee0`; **ret 8** not 0xC | **Falsified** 0xC |
| 4 | Thiscall with value on stack (InsertN12 shape) | **EDX**=value*; only where+count on stack; ret 8 | **Falsified** thiscall-3arg |
| 5 | EDI host like InsertOne wrapper | `mov ebx,ecx` this; parent moves EDI→ECX | **Falsified** EDI-this |
| 6 | Value is by-value 0x28 on stack | EDX pointer; 10 dwords loaded to locals | **Falsified** by-value |
| 7 | Always reallocates | Capacity-ok path uses in-place relocate | **Falsified** always-grow |
| 8 | Growth is exact 2× | `cap + (cap>>1)` is 1.5× | **Falsified** 2× |
| 9 | Max size is 0x15555555 (elem12) | Constant `0x06666666` | **Falsified** elem12 max |
| 10 | Multi-caller domain-heavy | Only 1 xref: InsertOne wrapper | **Attack fails** — generic but narrow graph |
| 11 | Same unit as ConstructN `00409d40` | Different VA/role (construct vs insert) | **Falsified** merge |
| 12 | `ret` plain / ret 0xC | Ends **`C2 08 00`** | **Falsified** plain/0xC |
| 13 | Product `vector::insert` required | No RTTI/string on VA | **Agree** `_Inferred` |
| 14 | Decomp "delete does not return" aborts triad | Fall-through after delete writes begin/end/cap | **Falsified** as runtime fact; decomp warning only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x8 / ECX+EDX / 2 stack formals | **Confirmed** | Stack imbalance |
| Stride 0x28 / max 0x06666666 | **Confirmed** | Wrong width ports |
| 1.5× grow + three-way relocate | **Confirmed** | Iterator bugs |
| In-place near/far split | **Confirmed** (CF) | Wrong hole plant |
| Helper formal packing detail | **High** | Rare mid-insert corner |
| Sole listed caller | **Confirmed** | Miss if xrefs incomplete |
| Runtime | **Open** | No live realloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile_function (2026-08-04);
bytes @ 0x00408050:
  SEH prolog LAB_009bd120
  mov ebx,ecx                 ; this
  mov ecx,10; mov esi,edx; lea edi,[ebp-0x58]; rep movsd  ; snap 0x28
  begin = [ebx+4]; cap = (capEnd-begin)/0x28 via 0x66666667
  if count==0 → epilogue
  size check vs 0x06666666 → FUN_00418130
  if need grow: 1.5x; FUN_00437d80; operator_new(n*0x28);
    uninit_copy prefix; FUN_00406e50 fill; uninit_copy suffix;
    operator_delete old; write triad; ret 0x8
  else in-place near/far + FUN_00409b00
  epilogue ret 0x8
```

### ABI trap

Do **not** model as thiscall with value as third stack arg (that is InsertN **0xC** / dword family). **This** unit is **ECX=vec, EDX=value**, stack where+count, **ret 8**.

### Stride trap

Do not paste dword InsertN (`>>2`) or 0xC InsertN (`0x2AAAAAAB` / Ufill `00406ee0`). This instantiation is **elem 0x28** with Ufill `00406e50`.

### Delete trap

Ghidra marks `operator_delete` as noreturn in the grow path — **false** for this binary; triad rebind after free is load-bearing. Ports must not treat free as abort.

---

## 4. Residual gaps (agreed with A)

1. Product type English for 0x28-byte `T`.
2. Full dual of relocate helper leaves.
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; ABI/stride/growth/role sealed; product open.
