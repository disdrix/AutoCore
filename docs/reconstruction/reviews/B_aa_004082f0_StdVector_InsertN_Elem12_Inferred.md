# Review B (skeptical / adversarial): `aa_004082f0` StdVector_InsertN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004082f0` |
| **VA** | `0x004082f0` |
| **Canonical name** | `StdVector_InsertN_Elem12_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` |
| **System** | util / container (`std::vector` POD **elem 0xC**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body allocates / fills / advances end | **Falsified** erase |
| 2 | Stride 4 (dword InsertN twin) | All math `/0xc` and `*0xc`; magic `0x2AAAAAAB` | **Falsified** dword |
| 3 | Stride 0x28 (InsertN twin `00408050`) | Value snap 3 dwords not 10; Ufill `00406ee0` not `00406e50` | **Falsified** 0x28 |
| 4 | EDI host like InsertOne | `mov ebx,ecx` thiscall; parent moves EDI→ECX | **Falsified** EDI-this |
| 5 | Value is by-value 12 B on stack | `param_4` pointer; 3 dwords loaded to locals | **Falsified** by-value |
| 6 | Always reallocates | Capacity-ok path uses in-place relocate | **Falsified** always-grow |
| 7 | Growth is exact 2× | `cap + (cap>>1)` is 1.5× | **Falsified** 2× |
| 8 | Max size is 0x3fffffff (dword twin) | Constant `0x15555555` | **Falsified** dword max |
| 9 | Multi-caller domain-heavy | Only 1 xref: InsertOne wrapper | **Attack fails** — generic but narrow graph |
| 10 | Same unit as ConstructN `00409d40` | Different VA/role/stride (0x28 construct) | **Falsified** merge |
| 11 | `ret` plain / cdecl | Ends **`C2 0C 00`** | **Falsified** plain ret |
| 12 | Product `vector::insert` required | No RTTI/string on VA | **Agree** `_Inferred` |
| 13 | Decomp "delete does not return" aborts triad update | Fall-through after delete writes begin/end/cap | **Falsified** as runtime fact; decomp warning only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0xC / thiscall / 3 stack formals | **Confirmed** | Stack imbalance |
| Stride 12 / max 0x15555555 | **Confirmed** | Wrong width ports |
| 1.5× grow + three-way relocate | **Confirmed** | Iterator bugs |
| In-place near/far split | **Confirmed** (CF) | Wrong hole plant |
| Helper formal packing detail | **High** | Rare mid-insert corner |
| Sole listed caller | **Confirmed** | Miss if xrefs incomplete |
| Runtime | **Open** | No live realloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile_function (2026-08-04);
bytes @ 0x004082f0:
  SEH prolog LAB_009bd110
  mov ebx,ecx                 ; this
  load *value three dwords → [ebp-0x38..]
  begin = [ebx+4]; cap = (capEnd-begin)/12 via 0x2AAAAAAB
  if count==0 → epilogue
  size check vs 0x15555555 → FUN_00418130
  if need grow: 1.5x; FUN_00480c80; operator_new(n*12);
    uninit_copy prefix; FUN_00406ee0 fill; uninit_copy suffix;
    operator_delete old; write triad; ret 0xC
  else in-place near/far + FUN_0042ac90
  epilogue ret 0xC
```

### ABI trap

Do **not** model as EDI-host InsertOne ABI. **This** unit is classic **thiscall ECX=vec**. Wrapper `00406e70` holds vec in EDI and moves to ECX for the call.

### Stride trap

Do not paste dword InsertN (`>>2`) or 0x28 InsertN (`0x66666667` / Ufill `00406e50`). This instantiation is **elem 0xC** with Ufill `00406ee0`.

### Delete trap

Ghidra marks `operator_delete` as noreturn in the grow path — **false** for this binary; triad rebind after free is load-bearing. Ports must not treat free as abort.

---

## 4. Residual gaps (agreed with A)

1. Product type English for 12-byte `T`.
2. Full dual of relocate helper leaves.
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; ABI/stride/growth/role sealed; product open.
