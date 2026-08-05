# Review A (reconstruction fidelity): `aa_00466da0` StdVector_InsertOne_RebindIt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466da0` |
| **VA** | `0x00466da0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Inferred` (structural) |
| **Ghidra name** | `FUN_00466da0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00466da0_StdVector_InsertOne_RebindIt_Inferred.md` |
| **System** | container / std::vector&lt;dword&gt; grow-insert |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Insert exactly one dword** into an MSVC-style vector, then **rebind an out-iterator** so it remains valid after a possible reallocation.

Custom register + stack ABI (sealed from `read_memory` bytes + parent `FUN_004406e0`):

| Slot | Role |
|---|---|
| **EDI** | `vector*` header (`+4` begin, `+8` end, `+0xc` capacityEnd) |
| **EBX** | `dword**` out — written with pointer to inserted element after insert |
| Stack arg0 | insert position (`dword*` into buffer; push_back passes `end`) |
| Stack arg1 | `const dword*` value source |
| Return | `EAX = EBX` (out-iterator holder); **`ret 8`** |

CF:

1. `begin = *(edi+4)`.
2. If `begin == 0` **or** `(end-begin)>>2 == 0` (empty) → saved index `0`; else `index = (insertPos - begin) >> 2`.
3. Call grow/insert helper `FUN_00456960` with **count=1**, **vector=EDI**, **pos=insertPos**, **fill=`*value*`** (EAX holds value* into callee).
4. `*ebx = *(edi+4) + index*4` — rebased iterator after possible realloc of begin.
5. `eax = ebx`; `ret 8`.

Primary caller: `StdVector_PushBackDword_Inferred` (`0x004406e0`) slow path when capacity exhausted. Secondary xref: `FUN_00989e00`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00466da0_FUN_00466da0.md` |
| Annotated | `docs/reconstruction/raw/aa_00466da0_FUN_00466da0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00466da0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00466da0_FUN_00466da0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00466da0` (2026-07-29) |
| Bytes | `read_memory` 80 B — ends `C2 08 00` (**ret 8**); count imm `B9 01 00 00 00`; `call FUN_00456960` |
| Parent dual | `A_aa_004406e0_StdVector_PushBackDword_Inferred.md` |
| Grow/insert core | `FUN_00456960` decompile (capacity grow, memmove, fill) |
| Callers | `FUN_004406e0`, `FUN_00989e00` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| **ret 8** — two stack formals | **Confirmed** | `C2 08 00` |
| EDI = vector*; layout +4/+8/+c | **High** | body + parent dual |
| Element stride **4** (`>>2`, `*4`) | **Confirmed** | body |
| Hardcoded insert **count = 1** | **Confirmed** | `mov ecx, 1` before call |
| Index save before realloc, rebind after | **Confirmed** | ESI index; `lea ecx,[eax+esi*4]; mov [ebx],ecx` |
| EBX out-iterator holder; EAX returns EBX | **Confirmed** | bytes |
| `FUN_00456960` = insert/grow engine | **High** (role) | decompile: new, memmove, fill |
| Push_back uses this only on full capacity | **High** | parent `004406e0` CF |
| Decompiler `unaff_EDI`/`unaff_EBX` noise | **Confirmed** | real ABI is customcc |
| Product / STL symbol name | **Open** | structural name kept |
| Full `FUN_00456960` freelist/grow policy dual | **Open** | sibling unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin; empty → index 0 | Yes (raw/live; clean scaffold same shape) |
| Else index = (pos−begin)>>2 | Yes |
| Call insert-one helper | Yes |
| Rebind *out = begin′ + index*4 | Yes |
| ret 8 | Yes (bytes; scaffold may omit) |
| Invented branches | None |

### Recovered CF

```c
// customcc: EDI=Vec*, EBX=dword**, stack(pos*, value*), ret 8
// void* / dword** __stdcall InsertOne_RebindIt(dword *pos, const dword *val)
dword *begin = vec->begin;              // *(edi+4)
int index;
if (begin == 0 || ((vec->end - begin) >> 2) == 0)
  index = 0;
else
  index = (int)(pos - begin);           // >> 2 as dword index
Vec_InsertN(vec, /*count*/1, pos, *val); // FUN_00456960
*outIt = vec->begin + index;            // rebased
return outIt;                           // eax = ebx
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_004406e0` / `StdVector_PushBackDword_Inferred` | capacity-full push_back → insert at end |
| Caller | `FUN_00989e00` | second site (domain Open) |
| Callee | `FUN_00456960` | N-element insert + optional realloc |

---

## 6. Gaps / open

1. Full dual of `FUN_00456960` grow policy / capacity formula (owned elsewhere).
2. Product typedef (vector of what; +0 header field unused here).
3. `FUN_00989e00` caller semantics.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — ABI + one-element rebind-insert CF sealed High; structural name.
