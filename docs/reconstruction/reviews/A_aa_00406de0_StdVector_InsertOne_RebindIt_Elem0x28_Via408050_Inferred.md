# Review A (reconstruction fidelity): `aa_00406de0` StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406de0` |
| **VA** | `0x00406de0` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred` |
| **Ghidra name** | `FUN_00406de0` |
| **Prior scaffold** | `FUN_00406de0` partial trio |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00406de0_StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.md` |
| **System** | util / container (std::vector elem **0x28**) |
| **Wave** | WQ9G-H OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Insert exactly one 0x28-byte element** into an MSVC-style vector, then **rebind an out-iterator** so it remains valid after a possible reallocation of `begin`.

```text
// EDI = vector*  (+4 begin, +8 end, +0xC capEnd)
// stack: outIt**, where*, value*
index = (begin!=0 && size!=0) ? (where - begin) / 0x28 : 0
FUN_00408050(ECX=vec, EDX=value, where, count=1)   // insert-N; may realloc
*outIt = begin' + index*0x28
EAX = outIt; ret 0xC
```

Primary known caller: **`FUN_00406220`** capacity-full push_back slow path (fast path ConstructN@`end` + `end+=0x28` when room remains).

**Twins** (same CF shape, different stride/engine):

| Twin | Stride | Insert engine | ret |
|---|---|---|---|
| `0x0040b6d0` | 4 | `FUN_00419880` CountEcx | 8 |
| `0x0040dbf0` | 4 | `FUN_004073a0` thiscall | 0xC |
| **this** | **0x28** | **`FUN_00408050`** | **0xC** |

**Not** tree insert/rebalance (neighbor `0x00406c40`), erase, or domain logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EDI** | `vector*` host |
| stack0 | `T**` out-iterator holder |
| stack1 | insert position (`T*`; push_back passes `end`) |
| stack2 | `const T*` value (0x28 POD pointer) |
| return | `EAX = outIt`; **`ret 0xC`** |

Callee `FUN_00408050`: **ECX**=vec, **EDX**=value, stack where + count.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00406de0` ≡ raw CF |
| Bytes | `read_memory` 128 B — magic `0x66666667` `/0x28`, `push 1`, `call FUN_00408050`, `lea`×0x28 rebind, **`C2 0C 00`** |
| Bounds | `get_function_by_address` body `00406de0`–`00406e48` |
| Parent | decompile + bytes `FUN_00406220` @ `0x00406220` |
| Callee | decompile `FUN_00408050` (insert-N elem 0x28; uses this fill-n) |
| Callers | `get_function_xrefs` → 1 UNCONDITIONAL_CALL from `0040628e` |
| Raw / annotated / clean | `aa_00406de0_*`, named plate |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin; empty → index 0 | **Yes** |
| Else index = (pos−begin)/0x28 | **Yes** (signed magic `0x66666667`) |
| Call insert-N with count **1** | **Yes** (`push 1`) |
| Rebind `*outIt = begin' + index*0x28` | **Yes** (`lea ecx,[esi+esi*4]; lea eax,[edx+ecx*8]`) |
| `ret 0xC` | **Yes** (bytes) |
| Invented branches | **None** |

### Recovered CF

```c
// customcc; ret 0xC
void** InsertOne_RebindIt(void *vec /*EDI*/, void **outIt,
                          void *pos, const void *val)
{
  int begin = *(int *)((char *)vec + 4);
  int index;
  if (begin != 0 && ((*(int *)((char *)vec + 8) - begin) / 0x28) != 0)
    index = ((int)pos - begin) / 0x28;
  else
    index = 0;
  FUN_00408050(vec, val, pos, 1); // ECX/EDX + stack
  *outIt = (void *)(*(int *)((char *)vec + 4) + index * 0x28);
  return outIt;
}
```

---

## 5. Residual gaps

1. Product / MSVC demangle for element type (0x28 POD layout unknown).
2. Insert-N engine `FUN_00408050` undualed (owned residual).
3. Parent push_back `FUN_00406220` undualed.
4. Runtime / differential.

---

## 6. Verdict

**accept-with-gaps** — insert-one rebind contract, customcc ABI, count=1, stride 0x28, and callee link sealed from bytes + parent. Gaps are undualed insert-N, product type, and runtime (not structural CF rejects).
