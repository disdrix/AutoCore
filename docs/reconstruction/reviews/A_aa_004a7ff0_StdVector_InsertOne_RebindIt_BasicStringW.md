# Review A (reconstruction fidelity): `aa_004a7ff0` StdVector_InsertOne_RebindIt_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ff0` |
| **VA** | `0x004a7ff0`–`0x004a8063` exclusive (**115 B**) |
| **Canonical name** | `StdVector_InsertOne_RebindIt_BasicStringW` |
| **Ghidra name** | `FUN_004a7ff0` |
| **Prior scaffold** | `FUN_004a7ff0` / `Named_CalleeOf_*attachmentRe_004a7ff0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W37-W) |
| **Counterpart** | `reviews/B_aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md` |
| **System** | MSVC `vector` insert-one + rebind, `basic_string<wchar_t>` elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert **exactly one** wstring slot at `where` via sealed insert-n (`count=1`), then write a **rebased** iterator to `*outIt` so callers survive reallocation of `begin`.

Primary known caller: **`FUN_004a8100`** capacity-full push_back slow path (fast path: `FUN_004a74f0` fill-one at end when spare cap).

**Not** multi-insert API, erase, resize, or domain/attachment logic despite historical alias.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004a7ff0` (2026-08-04) ≡ raw 2026-07-23 |
| Bytes | `read_memory` 128 B window — full **115 B** body; magic `0x92492493`; `6A 01`; `call FUN_004a7ad0`; **`C2 0C 00`** |
| Parent | `decompile_function` `FUN_004a8100` @ `0x004a8100` |
| Callee dual | W34-R `StdVector_InsertN_BasicStringW` |
| Twins | `aa_0040dbf0` (dword), `aa_004612d0` (RcElem28 customcc) |
| Raw / annotated / clean | `aa_004a7ff0_*`, named + scaffold cleans |
| Callers | `get_function_callers` / `get_xrefs_to` → `FUN_004a8100` @ `0x004a817d` only |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// __thiscall ECX=vec*; stack (outIt*, where*, value*); RET 0x0C
void StdVector_InsertOne_RebindIt_BasicStringW(
    StdVectorBasicStringW* vec,
    BasicStringW_0x1c** outIt,
    BasicStringW_0x1c* where,
    const BasicStringW_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | ECX (`mov edi,ecx`) | **Confirmed** |
| outIt* | stack0 | **Confirmed** |
| where | stack1 → EBX | **Confirmed** |
| value* | stack2 | **Confirmed** |
| RET 0xC | `C2 0C 00` | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Load begin@+4; null/empty → index 0 | **Yes** | **Confirmed** |
| Else index = (where−begin)/0x1c | magic divide | **Confirmed** |
| InsertN count=1 | `push 1` + call `004a7ad0` | **Confirmed** |
| Rebind `*outIt = begin' + index*0x1c` | lea/sub/lea/mov | **Confirmed** |
| `ret 0x0C` | bytes | **Confirmed** |
| Invented branches | **None** | — |

### Recovered CF

```c
// __thiscall; ret 0x0C
void InsertOne_RebindIt(void *vec, void **outIt, void *pos, const void *val)
{
  int begin = *(int *)((char *)vec + 4);
  int index;
  if (begin == 0 || ((*(int *)((char *)vec + 8) - begin) / 0x1c) == 0)
    index = 0;
  else
    index = ((int)pos - begin) / 0x1c;
  FUN_004a7ad0(vec, (int)pos, 1, val); // thiscall ECX=vec
  *outIt = (void *)(*(int *)((char *)vec + 4) + index * 0x1c);
}
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element stride **0x1c** | **Confirmed** | magic + lea scale |
| Hardcoded insert **count = 1** | **Confirmed** | `6A 01` |
| Index save before realloc, rebind after | **Confirmed** | ESI index; write after call |
| `ret 0x0C` / three stack formals + ECX this | **Confirmed** | `C2 0C 00` + `8B F9` |
| Callee = insert-n BasicStringW | **Confirmed** | W34-R dual + call target |
| Push_back slow path role | **High** | parent CF |
| Decompiler elides `this` on call | **Confirmed** | artifact only |
| Product / STL symbol name | **Open** | `_Inferred` |
| Sole caller forever | **Probable** | one listed xref |

---

## 6. Gaps / open

1. Product MSVC demangle English for `vector<basic_string<wchar_t>>::insert` wrapper.  
2. Runtime / bit-exact under grow (iterator value after realloc).  
3. Parent `FUN_004a8100` not dual-owned here (context only).

---

## 7. Verdict

**accept-with-gaps** — ABI/CF/stride/count/rebind sealed by live decompile + full body hex; product demangle and runtime open.
