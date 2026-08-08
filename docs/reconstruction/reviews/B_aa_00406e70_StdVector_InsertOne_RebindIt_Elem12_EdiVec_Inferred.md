# Review B (skeptical / adversarial): `aa_00406e70` StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406e70` |
| **VA** | `0x00406e70` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` |
| **System** | util / container (`std::vector` POD **elem 0xC**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is erase / pop / shrink | Body inserts via `FUN_004082f0` with count 1; rebinds forward | **Falsified** erase claim |
| 2 | Ghidra free `FUN_004082f0(pos,1,value)` is full ABI (no this) | Bytes: `mov ecx,edi` before call; InsertN is thiscall | **Falsified** free-function model |
| 3 | Count is variable / multi-insert API | Imm `push 1` (`6A 01`) | **Falsified** variable count |
| 4 | ECX thiscall vector host | Body never reads ECX as host; **EDI** holds vec; parent `mov edi,eax` | **Falsified** ECX-this model |
| 5 | Stride 4 (dword vector twin) | Magic `0x2AAAAAAB` is `/12`; lea `index*12` | **Falsified** stride-4 |
| 6 | Out iterator optional / unused | Always write `*outIt` after call | **Falsified** |
| 7 | Empty-vector index path bugs mid-insert | Empty forces index 0 then insert; rebind to begin′ | **Attack fails** for push_back-at-end |
| 8 | Same unit as tree insert `00406c40` | Distinct address; vector not RB-tree; no isnil@+0x29 | **Falsified** merge |
| 9 | Leaf / no callees | Calls `FUN_004082f0` | **Falsified** |
| 10 | `ret` plain / cdecl stack cleanup | Bytes end **`C2 0C 00`** | **Falsified** plain-ret model |
| 11 | Product `std::vector::insert` name required | No RTTI/string on VA | **Agree** structural `_Inferred` |
| 12 | Value is by-value 12 B on stack | InsertN loads `*param_4` three dwords; parent passes pointer in ECX/stack | **Falsified** by-value model |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x0C / three stack formals + EDI host | **Confirmed** | Stack imbalance in ports |
| One-element insert + rebind | **Confirmed** | Iterator invalidation bugs |
| Stride 12 | **Confirmed** | Wrong element width |
| Role vs push_back fast path | **High** | Duplicate push logic in wrong VA |
| Exact grow policy inside `004082f0` | **High** role / open detail | Hook wrong grow |
| Sole listed caller | **Probable** | Miss other domains if xrefs incomplete |
| Runtime | **Open** | No live realloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile_function (2026-08-04);
bytes @ 0x00406e70:
  push ebx
  mov ebx,[esp+0xC]           ; where
  push ebp
  mov ebp,[esp+0xC]           ; outIt
  push esi
  mov esi,[edi+4]             ; begin  (EDI = vec)
  ... empty? index=0 : index=(where-begin)/12 in ESI ...
  push [esp+0x18]             ; value*
  push 1
  push ebx                    ; where
  mov ecx,edi
  call FUN_004082f0
  mov eax,[edi+4]
  lea edx,[esi+esi*2]
  lea ecx,[eax+edx*4]         ; begin' + index*12
  pop esi
  mov [ebp],ecx
  mov eax,ebp
  pop ebp
  pop ebx
  ret 0x0C
```

### ABI trap

Do **not** model as thiscall ECX=vec (that is the **callee** InsertN). Entry host is **EDI**. Parent `FUN_004062a0` uses **EAX** vector + `mov edi,eax`.

### Iterator trap

Saving **index** (not raw pointer) before `FUN_004082f0` is load-bearing — after realloc, begin moves; index still valid. Porting as “return old end pointer” is a use-after-realloc bug.

### Stride trap

Do not paste dword-vector InsertOne (`>>2` / `*4`) templates. This instantiation is **elem 0xC**.

---

## 4. Residual gaps (agreed with A)

1. Product type English for 12-byte `T`.  
2. Full dual of InsertN `004082f0`.  
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; ABI/stride/role sealed; product open.
