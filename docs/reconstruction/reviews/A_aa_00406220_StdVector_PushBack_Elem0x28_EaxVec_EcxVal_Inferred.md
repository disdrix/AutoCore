# Review A (reconstruction fidelity): `aa_00406220` StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406220` |
| **VA** | `0x00406220` |
| **Canonical name** | `StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred` |
| **Ghidra name** | `FUN_00406220` |
| **Prior scaffold** | `FUN_00406220` partial trio |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00406220_StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.md` |
| **System** | util / container (std::vector elem **0x28**) |
| **Wave** | WQ9H-C OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MSVC-style `vector::push_back` for 0x28-byte POD elements**:

```text
// EAX = vector*  (+4 begin, +8 end, +0xC capEnd)
// ECX = const T* value
if begin != 0 && size < capacity:
  ConstructN(end, 1) via FUN_00409d40
  end += 0x28
  return
else:
  InsertOne_Rebind(vec, out_discard, where=end, value) via FUN_00406de0
```

Slow path is the sole caller of dualed insert-one `0x00406de0` (WQ9G-H). Fast path owns the capacity hit.

**Twin:** `aa_004062a0` (same CF, stride **0xC**).

**Not** tree insert, skill logic, or dword push_back (`EAX`/`ESI` family).

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EAX** | `vector*` host |
| **ECX** | `const T*` value (0x28 POD pointer) |
| stack | none |
| return | void; **`ret 0`** (`C3` both exits) |

Body immediately `MOV EDI,EAX` for insert-one customcc (EDI host).

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00406220` ≡ raw CF |
| Bytes | `read_memory` 160 B — magic `0x66666667`, construct pack + `add esi,0x28`, insert-one CALL, dual `C3` |
| Callers | xrefs + `get_assembly_context` @ `0x009335fb`, `0x00976b7c` (EAX=vec, ECX=value*) |
| Callees | `FUN_00409d40` ConstructN; dualed insert-one `00406de0` |
| Raw / annotated / clean | `aa_00406220_*`, named plate |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin@+4; null → slow | **Yes** |
| size = (end−begin)/0x28; cap = (capEnd−begin)/0x28 | **Yes** (magic `0x66666667`) |
| size < capacity → ConstructN@end count=1 + end+=0x28 | **Yes** |
| else insert-one at end (out discarded) | **Yes** (`call 00406de0`) |
| `ret 0` both arms | **Yes** (bytes `C3`) |
| Invented branches | **None** |

### Recovered CF

```c
// customcc; ret 0
void PushBack(void *vec /*EAX*/, const void *value /*ECX*/)
{
  int begin = *(int *)((char *)vec + 4);
  if (begin != 0) {
    unsigned size = (*(int *)((char *)vec + 8) - begin) / 0x28;
    unsigned cap  = (*(int *)((char *)vec + 0xc) - begin) / 0x28;
    if (size < cap) {
      int end = *(int *)((char *)vec + 8);
      FUN_00409d40((void *)end, 1);
      *(int *)((char *)vec + 8) = end + 0x28;
      return;
    }
  }
  void *out = (void *)value;
  FUN_00406de0(vec, &out, *(void **)((char *)vec + 8), value);
}
```

---

## 5. Residual gaps

1. Product / MSVC demangle for 0x28 POD element type (caller locals ~10 dwords).
2. ConstructN `FUN_00409d40` undualed (WQ9H-B owns).
3. Runtime / differential.

---

## 6. Verdict

**accept-with-gaps** — push_back CF, EAX/ECX ABI, stride 0x28, fast ConstructN vs slow insert-one sealed from bytes + dualed callee + callers. Gaps are product type, construct dual, and runtime (not structural CF rejects).
