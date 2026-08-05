# Review B (skeptical / adversarial): `aa_004a8100` StdVector_PushBack_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8100` |
| **VA** | `0x004a8100` |
| **Canonical name** | `StdVector_PushBack_BasicStringW` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004a8100_StdVector_PushBack_BasicStringW.md` |
| **System** | MSVC vector push_back (wstring 0x1c) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is insert-at-position / insert-n multi API | Body only fill-one or insert-one at **end** | **Falsified** multi-insert claim |
| 2 | This is erase / pop / clear | No destroy loop; end only grows | **Falsified** |
| 3 | Stride is 4 / dword vector | Magic `0x92492493` + `ADD ESI,0x1C` | **Falsified** dword model |
| 4 | Always grows (never spare-cap fast path) | Explicit size < cap branch + fill-n | **Falsified** |
| 5 | Always in-place (never realloc) | Slow path calls insert-one → insert-n | **Falsified** |
| 6 | Free-function cdecl (no this) | `MOV EDI,ECX`; insert-one `MOV ECX,EDI` | **Falsified** |
| 7 | `ret` plain / RET 0x0C | Bytes end **`C2 04 00`** both paths | **Falsified** wrong cleanup |
| 8 | Attachment/domain logic (scaffold alias) | Pure container CF + STL callees | **Falsified** domain claim |
| 9 | Same VA as RcElem28 / POD push twins | Distinct callees + thiscall RET 4 | **Falsified** merge |
| 10 | Fill-n is thiscall 3-arg only at this site | Retail pushes **5** dwords + `ADD ESP,0x14` | **Agree** push pattern; body still 3-arg W36-R |
| 11 | Product `std::vector::push_back` name required | No RTTI/string on VA | **Agree** structural name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x04 / one stack formal + ECX this | **Confirmed** | Stack imbalance in ports |
| Spare fill-one vs grow insert-one | **Confirmed** | Double-growth / leak |
| Stride 0x1c / wstring family | **Confirmed** | Wrong element lifetime |
| Role as parent of W37-W insert-one | **Confirmed** | Miss slow path |
| Sole listed caller | **Probable** | Miss other sites if xrefs incomplete |
| Runtime | **Open** | No live grow capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04);
bytes @ 0x004a8100 (135 B):
  push ebx; push esi; push edi; mov edi,ecx   ; this = vector
  mov ebx,[edi+4]                             ; begin
  test ebx,ebx / size via magic 0x92492493
  test ebx / cap via same magic
  cmp size,cap / jae slow
  ; fast:
  push value; push edi; push value; push 1; push end
  call FUN_004a74f0
  add esp,0x14
  add esi,0x1c; mov [edi+8],esi
  pop edi; pop esi; pop ebx; ret 4
  ; slow:
  push value; push end; lea outIt; push; mov ecx,edi
  call FUN_004a7ff0
  pop edi; pop esi; pop ebx; ret 4
```

### ABI trap

Do **not** model as free `push_back(vec, value)` with callee-clean 0 args. Retail is **thiscall + RET 4**.

### Grow trap

Fast path **must not** call insert-one; slow path **must not** bump end without insert (capacity exhausted). Mixing them is a classic off-by-one / overflow port bug.

### Fill-n trap

Call site pushes five dwords; do not invent a 5-parameter semantic API — W36-R sealed body is dest/count/value. Extra pushes are MSVC residual (alloc + value echo) cleaned by `ADD ESP,0x14`.

### Twin trap

Do **not** unify with `StdVector_PushBack_RcElem28` (`0x00460f90`, EAX/ECX + bare RET) or POD `0x00469c80` — same CF shape, different element lifetime and callees.

---

## 4. Surviving contract for AutoCore

```
StdVector_PushBack_BasicStringW(vec=ECX, value*):
  if begin && size < cap:
    StdUninitFillN_BasicStringW(end, 1, value*)   // FUN_004a74f0
    end += 0x1c
  else:
    StdVector_InsertOne_RebindIt_BasicStringW(vec, &discard, end, value*)  // FUN_004a7ff0
  ret 0x04

Consumers:
  FUN_004a1d80 token → wstring vector push

AutoCore must NOT:
  - treat as erase / multi-insert
  - skip slow path (capacity-full push becomes no-op or overwrite)
  - use char-string or POD/RC fill/insert twins
  - clean stack as RET 0 / RET 0x0C
  - trust scaffold attachmentResponse name
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks fail to break ABI/CF/stride/fast-slow contract; residual is product demangle + runtime.
