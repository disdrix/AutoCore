# Review B (skeptical / adversarial): `aa_00466da0` StdVector_InsertOne_RebindIt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466da0` |
| **VA** | `0x00466da0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00466da0_StdVector_InsertOne_RebindIt_Inferred.md` |
| **System** | container / std::vector&lt;dword&gt; grow-insert |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body inserts via `FUN_00456960` with count 1; rebinds forward | **Falsified** erase claim |
| 2 | Ghidra single formal `param_1` is full ABI | Bytes: **ret 8**, EDI/EBX live, two stack args | **Falsified** decompiler signature |
| 3 | Count is variable / multi-insert API | Imm `mov ecx, 1` before call | **Falsified** variable count |
| 4 | Out iterator is optional / unused | Always `mov [ebx], ecx; mov eax, ebx` | **Falsified** |
| 5 | Empty-vector index path bugs mid-insert | Empty forces index 0 then insert; rebind to begin′ | **Attack fails** for push_back-at-end |
| 6 | Same as capacity-check push (`004406e0`) | Parent only calls here when full; this always goes through grow helper | **Falsified** merge of VAs |
| 7 | Leaf / no callees | Calls `FUN_00456960` | **Falsified** |
| 8 | Product `std::vector::insert` name required | No RTTI/string | **Agree** structural name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 / two stack formals | **Confirmed** | Stack imbalance in ports |
| EDI vector + EBX out-it | **High** | Wrong registers in hooks |
| One-element insert + rebind | **Confirmed** | Iterator invalidation bugs |
| Stride 4 | **Confirmed** | Wrong element width |
| Role vs push_back fast path | **High** | Duplicate push logic in wrong VA |
| Exact fill/`FUN_00456960` ABI details | **High** role / residual formals Open | Hook wrong args |
| Runtime | **Open** | No live realloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-07-29) shape;
bytes @ 0x00466da0:
  mov eax,[edi+4] ; begin
  mov ecx,[esp+4] ; insert pos
  ... index in ESI ...
  mov eax,[esp+0xc] ; value*
  push ecx ; pos
  mov ecx,1
  mov edx,edi
  call FUN_00456960
  mov eax,[edi+4]
  lea ecx,[eax+esi*4]
  mov [ebx],ecx
  mov eax,ebx
  pop esi
  ret 8
```

### ABI trap

Do **not** model as `void FUN_00466da0(int param_1)` only. Parent and bytes require:

```
// EDI=vec, EBX=&outIt, stack: pos, value*
InsertOne_RebindIt(end, &value);  // push_back slow path
```

### Iterator trap

Saving **index** (not raw pointer) before `FUN_00456960` is load-bearing — after realloc, begin moves; index still valid. Porting as “return old end pointer” is a use-after-realloc bug.

---

## 4. Surviving contract for AutoCore

```
StdVector_InsertOne_RebindIt(vec=EDI, outIt=EBX, pos, value*):
  index = empty(vec) ? 0 : (pos - begin)/4
  Vec_InsertN(vec, 1, pos, *value*)   // FUN_00456960
  *outIt = begin' + index
  return outIt

Consumers:
  StdVector_PushBackDword (0x004406e0) when size==capacity
  FUN_00989e00

AutoCore must NOT:
  - treat as erase
  - ignore rebind (stale iterators after grow)
  - invent multi-element count at this VA
  - trust Ghidra unaff_* as “unknown junk” without EDI/EBX contract
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Insert-one + rebind | **Agree Confirmed** |
| ret 8; EDI/EBX ABI | **Agree Confirmed** |
| Parent push_back slow path | **Agree High** |
| clean ≡ raw ≡ live CF | **Agree** (scaffold noisy on regs only) |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Seal `FUN_00456960` dual (growth formula `cap + cap/2`, etc.).
2. Confirm whether mid-vector insert (not just end) is live in `FUN_00989e00`.
3. Runtime realloc capture.

**Verdict:** **accept-with-gaps** — agree with A; block erase/single-formal/decompiler-only ABI mistakes.
