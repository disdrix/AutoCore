# Review A (reconstruction fidelity): `aa_0040b6d0` StdVector_InsertOne_RebindIt_Via419880_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b6d0` |
| **VA** | `0x0040b6d0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Via419880_Inferred` |
| **Ghidra name** | `FUN_0040b6d0` |
| **Prior scaffold** | `Named_CalleeOf_…Client_UpdateMissionJournal_0040b6d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` |
| **System** | util / container (std::vector dword) |
| **Wave** | WQ7R-E OWN |
| **Verdict** | **accept** |

---

## 1. Purpose

**Insert exactly one dword** into an MSVC-style vector, then **rebind an out-iterator** so it remains valid after a possible reallocation of `begin`.

```text
// EDI = vector*  (+4 begin, +8 end, +0xC capEnd)
// EBX = T** outIt
// stack: where*, value*
index = empty(vec) ? 0 : (where - begin) / 4
FUN_00419880(count=1, vec, where, value)   // CountEcx insert-N; may realloc
*outIt = begin' + index*4
EAX = EBX; ret 8
```

Primary known caller: **`FUN_00411180`** capacity-full push_back slow path (fast path writes `*end++` when room remains).

**Twins** (same CF, different ABI/callee):

| Twin | ABI | Insert engine |
|---|---|---|
| `0x0040dbf0` | thiscall + stack out/pos/value; ret 0xC | `FUN_004073a0` |
| `0x00466da0` | EDI/EBX; ret 8 | `FUN_00456960` |
| **this** | EDI/EBX; ret 8 | **`FUN_00419880`** (CountEcx) |

**Not** multi-insert API, erase, domain/mission logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EDI** | `vector*` host |
| **EBX** | `T**` out-iterator holder |
| stack0 | insert position (`T*`; push_back passes `end`) |
| stack1 | `const T*` value source |
| return | `EAX = EBX`; **`ret 8`** |

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0040b6d0` ≡ raw CF |
| Bytes | `read_memory` 68 B — `B9 01 00 00 00`, `call FUN_00419880`, `lea edx,[ecx+esi*4]`, **`C2 08 00`** |
| Parent | decompile + bytes `FUN_00411180` @ `0x00411180` |
| Callee dual | `A_aa_00419880_StdVector_InsertN_Dword_CountEcx_Inferred` (W23-D) |
| Twin duals | `A_aa_0040dbf0_*`, `A_aa_00466da0_*` |
| Raw / annotated / clean | `aa_0040b6d0_*`, named plate |
| Callers | `get_function_callers` → `FUN_00411180` only |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin; empty → index 0 | **Yes** |
| Else index = (pos−begin)>>2 | **Yes** |
| Call insert-N with count **1** | **Yes** (`mov ecx,1`) |
| Rebind `*outIt = begin' + index*4` | **Yes** |
| `ret 8` | **Yes** (bytes; scaffold previously omitted) |
| Invented branches | **None** |

### Recovered CF

```c
// customcc; ret 8
void InsertOne_RebindIt(void *vec /*EDI*/, void **outIt /*EBX*/,
                        void *pos, const void *val)
{
  int begin = *(int *)((char *)vec + 4);
  int index;
  if (begin == 0 || ((*(int *)((char *)vec + 8) - begin) >> 2) == 0)
    index = 0;
  else
    index = ((int)pos - begin) >> 2;
  // ECX=1; stack vec, pos, val
  FUN_00419880(1, vec, pos, val);
  *outIt = (void *)(*(int *)((char *)vec + 4) + index * 4);
}
```

---

## 5. Residual gaps

1. Product / MSVC demangle.
2. Whether non-push_back callers exist outside current xref set.
3. Runtime / differential.

---

## 6. Verdict

**accept** — insert-one rebind contract, customcc ABI, count=1, and callee link fully sealed from bytes + parent. Gaps are demangle/runtime only (not structural).
