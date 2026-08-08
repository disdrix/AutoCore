# Review A (reconstruction fidelity): `aa_00406e70` StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406e70` |
| **VA** | `0x00406e70` |
| **Body** | `0x00406e70`–`0x00406ed8` (**104 B** / `0x68`); pad `CC` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred` |
| **Ghidra name** | `FUN_00406e70` |
| **Prior scaffold** | `FUN_00406e70` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9G-I**) |
| **Counterpart** | `reviews/B_aa_00406e70_StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.md` |
| **System** | util / container (`std::vector` POD **elem 0xC**) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Insert exactly one 12-byte POD** into an MSVC-style vector, then **rebind an out-iterator** so it remains valid after a possible reallocation of `begin`.

```text
// EDI = vector*  (+4 begin, +8 end, +0xC capEnd)
// stack: outIt**, where*, value*
index = empty(vec) ? 0 : (where - begin) / 12
FUN_004082f0(vec, where, count=1, value*)   // may realloc
*outIt = begin' + index * 12
ret 0x0C
```

Primary known caller: **`FUN_004062a0`** push_back slow path (EAX=vec → `mov edi,eax`; capacity miss → this unit with `where = end`).

**Family twins:** thiscall/dword `StdVector_InsertOne_RebindIt_Thiscall_Inferred` (`0x0040dbf0`); EDI dword `Via419880` (`0x0040b6d0`); neighborhood leaf InsertOne elem **0x28** (`0x00406de0`).

**Not** multi-insert API, erase, map/tree, or skill-domain logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EDI** | `vector*` host |
| stack0 | `T**` out-iterator holder |
| stack1 | insert position (`T*` into buffer; push_back passes `end`) |
| stack2 | `const T*` value source (12-byte POD) |
| return | EAX = outIt; **`ret 0x0C`** |

```c
T** __customcc StdVector_InsertOne_RebindIt_Elem12_EdiVec(
    /*EDI*/ void *vec, void **outIt, void *pos, const void *value);
```

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x00406e70` (2026-08-04) ≡ raw scaffold CF |
| Bytes | `read_memory` 128 B — magic `/12`, `push 1`, `call FUN_004082f0`, `lea` rebind, **`C2 0C 00`** |
| Parent | `decompile_function` + `read_memory` `FUN_004062a0` @ `0x004062a0` |
| Callee | `FUN_004082f0` InsertN elem-0xC (uses this unit's pair `00406ee0` as Ufill) |
| Raw / annotated / clean | `aa_00406e70_*`, `StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.cpp` |
| Callers | `get_function_callers` → `FUN_004062a0` only (1 xref @ `0x0040630c`) |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin from EDI+4; empty → index 0 | **Yes** |
| Else index = (where−begin)/12 via `0x2AAAAAAB` | **Yes** |
| Call InsertN with count **1** | **Yes** (`6A 01`) |
| Rebind `*outIt = begin' + index*12` | **Yes** (`lea edx,[esi+esi*2]; lea ecx,[eax+edx*4]`) |
| `ret 0x0C` | **Yes** (bytes) |
| Invented branches | **None** |

### Recovered CF

```c
// customcc EDI=vec; ret 0x0C
void **InsertOne_RebindIt_Elem12(void *vec, void **outIt, void *pos, const void *val)
{
  int begin = *(int *)((char *)vec + 4);
  int index;
  if (begin == 0 || ((*(int *)((char *)vec + 8) - begin) / 12) == 0)
    index = 0;
  else
    index = ((int)pos - begin) / 12;
  FUN_004082f0(vec, (int)pos, 1, (unsigned)val); // thiscall ECX=vec
  *outIt = (void *)(*(int *)((char *)vec + 4) + index * 12);
  return outIt;
}
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element stride **12** | **Confirmed** | `/12` magic + `*12` lea |
| Hardcoded insert **count = 1** | **Confirmed** | `6A 01` |
| Index save before realloc, rebind after | **Confirmed** | ESI index; write after call |
| `ret 0x0C` / three stack formals | **Confirmed** | `C2 0C 00` |
| EDI = vector; layout +4/+8/+C | **Confirmed** | body + parent |
| Callee `FUN_004082f0` = insert-N | **High** | parent + self-use of Ufill pair |
| Push_back slow path role | **High** | parent CF sealed |
| Decompiler elides EDI this | **Confirmed** | `unaff_EDI` artifact only |
| Product / STL symbol name | **Open** | `_Inferred` |
| Sole caller forever | **Probable** | one listed xref |

---

## 6. Gaps / open

1. Product demangle for `T` (12 B).  
2. InsertN `FUN_004082f0` not dualed in this OWN pair.  
3. Runtime / bit-exact / differential.  
4. Other xref sites if Ghidra incomplete (none listed).

**Verdict:** **accept-with-gaps**
