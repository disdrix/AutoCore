# Review B (skeptical / adversarial): `aa_0040dbf0` StdVector_InsertOne_RebindIt_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dbf0` |
| **VA** | `0x0040dbf0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Thiscall_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040dbf0_StdVector_InsertOne_RebindIt_Thiscall_Inferred.md` |
| **System** | util / container (std::vector&lt;dword&gt;) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body inserts via `FUN_004073a0` with count 1; rebinds forward | **Falsified** erase claim |
| 2 | Ghidra call `FUN_004073a0(pos,1,value)` is full ABI (no this) | Bytes: `mov ecx,edi` before call; parent dual seals thiscall insert-N | **Falsified** free-function model |
| 3 | Count is variable / multi-insert API | Imm `push 1` (`6A 01`) | **Falsified** variable count |
| 4 | Out iterator optional / unused | Always `lea` + `mov [outIt], edx` | **Falsified** |
| 5 | Empty-vector index path bugs mid-insert | Empty forces index 0 then insert; rebind to begin′ | **Attack fails** for push_back-at-end |
| 6 | Same VA as customcc twin `0x00466da0` | Distinct address; different callee (`004073a0` vs `00456960`); different ABI | **Falsified** merge |
| 7 | Leaf / no callees | Calls `FUN_004073a0` | **Falsified** |
| 8 | `ret` plain / cdecl stack cleanup | Bytes end **`C2 0C 00`** | **Falsified** plain-ret model |
| 9 | Product `std::vector::insert` name required | No RTTI/string on VA | **Agree** structural name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x0C / three stack formals + ECX this | **Confirmed** | Stack imbalance in ports |
| One-element insert + rebind | **Confirmed** | Iterator invalidation bugs |
| Stride 4 | **Confirmed** | Wrong element width |
| Role vs push_back fast path | **High** | Duplicate push logic in wrong VA |
| Exact fill/`FUN_004073a0` grow policy | **High** role (dual elsewhere) | Hook wrong grow |
| Sole listed caller | **Probable** | Miss other domains if xrefs incomplete |
| Runtime | **Open** | No live realloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile_function (2026-07-29);
bytes @ 0x0040dbf0:
  mov edi,ecx                 ; this = vector
  mov eax,[edi+4]             ; begin
  mov ecx,[esp+10]            ; pos (after push esi/edi)
  ... empty? index=0 : index=(pos-begin)>>2 in ESI ...
  push [esp+14]               ; value*
  push 1
  push ecx                    ; pos
  mov ecx,edi
  call FUN_004073a0
  mov ecx,[edi+4]
  mov eax,[esp+0C]            ; outIt*
  lea edx,[ecx+esi*4]
  pop edi
  mov [eax],edx
  pop esi
  ret 0x0C
```

### ABI trap

Do **not** model as free `FUN_004073a0(pos,1,value)` only. Parent and bytes require:

```
// ECX=vec, stack: &outIt, pos, value*
InsertOne_RebindIt(end, &value);  // push_back slow path
```

### Iterator trap

Saving **index** (not raw pointer) before `FUN_004073a0` is load-bearing — after realloc, begin moves; index still valid. Porting as “return old end pointer” is a use-after-realloc bug.

---

## 4. Surviving contract for AutoCore

```
StdVector_InsertOne_RebindIt_Thiscall(vec=ECX, outIt, pos, value*):
  index = empty(vec) ? 0 : (pos - begin)/4
  StdVector_InsertN_Dword(vec, pos, 1, value*)   // FUN_004073a0
  *outIt = begin' + index*4
  ret 0x0C

Consumers:
  CVOGReaction_FailMissionNotify (0x004149d0) when size==capacity

AutoCore must NOT:
  - treat as erase
  - ignore rebind (stale iterators after grow)
  - invent multi-element count at this VA
  - trust Ghidra's 3-arg call site without ECX=this
  - merge with 0x00466da0 customcc twin
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Insert-one + rebind | **Agree Confirmed** |
| ret 0x0C; thiscall + 3 stack | **Agree Confirmed** |
| Parent push_back slow path | **Agree High** |
| clean ≡ raw ≡ live CF | **Agree** (clean now carries this on call) |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Additional callers beyond FailMissionNotify (xref list may grow).
2. Runtime realloc capture.
3. Whether any mid-vector insert (not just end) is live for this VA.

**Verdict:** **accept-with-gaps** — agree with A; block erase/free-function/decompiler-only ABI mistakes.
