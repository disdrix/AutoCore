# Review B (skeptical / adversarial): `aa_004a7ff0` StdVector_InsertOne_RebindIt_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ff0` |
| **VA** | `0x004a7ff0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_BasicStringW` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md` |
| **System** | MSVC vector insert-one + rebind (wstring 0x1c) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body calls insert-n with count 1; rebinds forward | **Falsified** erase claim |
| 2 | Ghidra call `FUN_004a7ad0(where,1,value)` is full ABI (no this) | Bytes: `mov ecx,edi` before call; W34-R seals thiscall insert-n | **Falsified** free-function model |
| 3 | Count is variable / multi-insert API | Imm `push 1` (`6A 01`) | **Falsified** variable count |
| 4 | Stride is 4 / dword vector | Magic `0x92492493` + `*0x1c` rebind scale | **Falsified** dword model |
| 5 | Out iterator optional / unused | Always write `*outIt` after insert | **Falsified** |
| 6 | Can rebind with pre-insert begin pointer | Re-reads `*(this+4)` after call | **Falsified** stale-begin model |
| 7 | Same as customcc RcElem28 twin `0x004612d0` | Distinct VA; thiscall ECX vs EDI; different insert-n callee | **Falsified** merge |
| 8 | Leaf / no callees | Calls `FUN_004a7ad0` | **Falsified** |
| 9 | `ret` plain / cdecl stack cleanup | Bytes end **`C2 0C 00`** | **Falsified** plain-ret model |
| 10 | Product `std::vector::insert` name required | No RTTI/string on VA | **Agree** structural name |
| 11 | Attachment/domain logic (scaffold alias) | Pure container math + insert-n | **Falsified** domain claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x0C / three stack formals + ECX this | **Confirmed** | Stack imbalance in ports |
| One-element insert + rebind | **Confirmed** | Iterator invalidation bugs |
| Stride 0x1c / wstring family | **Confirmed** | Wrong element width / dtor path |
| Role vs push_back fast path | **High** | Duplicate push logic in wrong VA |
| Exact grow policy of insert-n | **High** role (dual W34-R) | Hook wrong grow |
| Sole listed caller | **Probable** | Miss other sites if xrefs incomplete |
| Runtime | **Open** | No live realloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04);
bytes @ 0x004a7ff0 (115 B):
  push ebx; mov ebx,[esp+0xC]     ; where
  push esi; push edi; mov edi,ecx ; this = vector
  mov esi,[edi+4]                 ; begin
  ... empty? index=0 : index=(where-begin)/0x1c in ESI ...
  push [esp+0x18]                 ; value*
  push 1
  push ebx                        ; where
  mov ecx,edi
  call FUN_004a7ad0
  mov eax,[edi+4]                 ; begin' after possible realloc
  lea edx,[esi*8]; sub edx,esi    ; edx = index*7
  pop edi
  lea ecx,[eax+edx*4]             ; begin' + index*28
  mov eax,[esp+0xC]               ; outIt*
  pop esi
  mov [eax],ecx
  pop ebx
  ret 0x0C
```

### ABI trap

Do **not** model as free `FUN_004a7ad0(where,1,value)` only. Parent and bytes require:

```
// ECX=vec, stack: &outIt, where, value*
InsertOne_RebindIt(end, &value);  // push_back slow path
```

### Iterator trap

Saving **index** (not raw pointer) before `FUN_004a7ad0` is load-bearing — after realloc, begin moves; index still valid. Porting as “return old end pointer” is a use-after-realloc bug.

### Stride trap

Do **not** unify with dword twin `0x0040dbf0` or POD/RcElem28 twins — same CF shape, different insert-n + element lifetime.

---

## 4. Surviving contract for AutoCore

```
StdVector_InsertOne_RebindIt_BasicStringW(vec=ECX, outIt, where, value*):
  index = empty(vec) ? 0 : (where - begin)/0x1c
  StdVector_InsertN_BasicStringW(vec, where, 1, value*)   // FUN_004a7ad0
  *outIt = begin' + index*0x1c
  ret 0x0C

Consumers:
  FUN_004a8100 when size==capacity (push_back slow path)

AutoCore must NOT:
  - treat as erase
  - ignore rebind (stale iterators after grow)
  - invent multi-element count at this VA
  - trust Ghidra's 3-arg call site without ECX=this
  - use char-string insert-n twin (0x004306b0) or POD insert-n
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks fail to break ABI/CF/stride/rebind contract; residual is product demangle + runtime.
