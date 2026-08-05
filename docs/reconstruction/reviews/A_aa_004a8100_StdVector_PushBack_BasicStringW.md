# Review A (reconstruction fidelity): `aa_004a8100` StdVector_PushBack_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8100` |
| **VA** | `0x004a8100`–`0x004a8187` exclusive (**135 B**) |
| **Canonical name** | `StdVector_PushBack_BasicStringW` |
| **Ghidra name** | `FUN_004a8100` |
| **Prior scaffold** | `FUN_004a8100` / `Named_CalleeOf_*attachmentResponse*` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W38-K) |
| **Counterpart** | `reviews/B_aa_004a8100_StdVector_PushBack_BasicStringW.md` |
| **System** | MSVC `vector::push_back`, `basic_string<wchar_t>` elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + parent decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Push **one** wstring slot onto a triad vector. **Spare capacity** → uninit-fill-n count=1 at `end` then advance. **Empty or full** → insert-one-rebind at `end` (growth; outIt discarded).

Primary known caller: **`FUN_004a1d80`** — tokenizes a `wchar_t*` string into local `basic_string<wchar_t>` objects and push_backs each onto `this` vector.

**Not** insert-at-position API, erase, resize multi, or attachment/domain logic despite historical scaffold alias.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004a8100` (2026-08-04) ≡ raw 2026-07-23 |
| Bytes | `read_memory` — full **135 B** body; magic `0x92492493` ×2; `6A 01`; calls `004a74f0` / `004a7ff0`; **`C2 04 00`** ×2 |
| Fill-n dual | W36-R `StdUninitFillN_BasicStringW` |
| Insert-one dual | W37-W `StdVector_InsertOne_RebindIt_BasicStringW` |
| Parent | `decompile_function` `FUN_004a1d80` — constructs `basic_string<wchar_t>` then calls this VA |
| Raw / annotated / clean | `aa_004a8100_*`, named + scaffold cleans |
| Callers | `get_function_callers` / `get_xrefs_to` → `FUN_004a1d80` @ `0x004a1e57` only |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// __thiscall ECX=vec*; stack value*; RET 0x04
void StdVector_PushBack_BasicStringW(
    StdVectorBasicStringW* vec,
    const BasicStringW_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | ECX (`mov edi,ecx`) | **Confirmed** |
| value* | stack0 (`[esp+0x10]` after 3 pushes) | **Confirmed** |
| RET 0x4 | `C2 04 00` both paths | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Load begin@+4; null → size 0 | **Yes** | **Confirmed** |
| size = (end−begin)/0x1c | magic divide | **Confirmed** |
| cap = (cap_end−begin)/0x1c | magic divide | **Confirmed** |
| spare: size < cap → fill-n count=1 | `push 1` + call `004a74f0` | **Confirmed** |
| end += 0x1c | `add esi,0x1c` / store +8 | **Confirmed** |
| slow: insert-one at end | call `004a7ff0` with where=end | **Confirmed** |
| `ret 0x04` | bytes | **Confirmed** |
| Invented branches | **None** | — |

### Recovered CF

```c
// __thiscall; ret 0x04
void PushBack(void *vec, const void *val)
{
  int begin = *(int *)((char *)vec + 4);
  unsigned size = 0;
  if (begin)
    size = (*(int *)((char *)vec + 8) - begin) / 0x1c;
  if (begin) {
    unsigned cap = (*(int *)((char *)vec + 0xc) - begin) / 0x1c;
    if (size < cap) {
      int end = *(int *)((char *)vec + 8);
      FUN_004a74f0(end, 1, val /*, vec, val */); // 5-dword retail push
      *(int *)((char *)vec + 8) = end + 0x1c;
      return;
    }
  }
  void *outIt;
  FUN_004a7ff0(vec, &outIt, *(void **)((char *)vec + 8), val); // thiscall
}
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element stride **0x1c** | **Confirmed** | magic + end bump |
| Fast fill-n **count = 1** | **Confirmed** | `6A 01` |
| Slow insert-one at end | **Confirmed** | W37-W dual + call target |
| `ret 0x04` / thiscall | **Confirmed** | `C2 04 00` + `8B F9` |
| Wstring element family | **High** | parent builds `basic_string<wchar_t>`; sealed fill/insert callees |
| Product / STL symbol name | **Open** | `_Inferred` |
| Sole caller forever | **Probable** | one listed xref |
| 5-dword fill-n push vs 3-arg body | **Confirmed** pattern | W36-S residual; body uses 3 |

---

## 6. Gaps / open

1. Product MSVC demangle English for `vector<basic_string<wchar_t>>::push_back`.  
2. Runtime / bit-exact under grow.  
3. Whether formal is strictly `const T&` vs temporary by-value (one stack slot either way at this call site).

---

## 7. Verdict

**accept-with-gaps** — ABI/CF/stride/fast-slow callees sealed by live decompile + full body hex; product demangle and runtime open.
