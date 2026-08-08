# Review A (reconstruction fidelity): `aa_004062a0` StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004062a0` |
| **VA** | `0x004062a0` |
| **Canonical name** | `StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred` |
| **Ghidra name** | `FUN_004062a0` |
| **Prior scaffold** | `FUN_004062a0` partial trio |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004062a0_StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.md` |
| **System** | util / container (std::vector elem **0xC**) |
| **Wave** | WQ9H-C OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MSVC-style `vector::push_back` for 12-byte POD elements**:

```text
// EAX = vector*  (+4 begin, +8 end, +0xC capEnd)
// ECX = const T* value
if begin != 0 && size < capacity:
  ConstructN(end, 1) via FUN_00409db0
  end += 0xC
  return
else:
  InsertOne_Rebind(vec, out_discard, where=end, value) via FUN_00406e70
```

Slow path is the sole caller of dualed insert-one `0x00406e70` (WQ9G-I).

**Twin:** `aa_00406220` (same CF, stride **0x28**).

**Not** tree/skill logic; **not** dword push_back ABI.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EAX** | `vector*` host |
| **ECX** | `const T*` value (12-byte POD pointer) |
| stack | none |
| return | void; **`ret 0`** (`C3` both exits) |

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x004062a0` ≡ raw CF |
| Bytes | `read_memory` 160 B — magic `0x2AAAAAAB` `/0xC`, construct + `add esi,0xc`, insert-one CALL, dual `C3` |
| Callers | 1 xref `0x00930d53` — `MOV EAX,0x00d1a82c`; `LEA ECX,[ESP]` |
| Callees | `FUN_00409db0` ConstructN; dualed insert-one `00406e70` |
| Raw / annotated / clean | `aa_004062a0_*`, named plate |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| begin null → slow | **Yes** |
| size/cap `/0xC` compare | **Yes** (magic `0x2AAAAAAB`) |
| spare → ConstructN@end + end+=0xC | **Yes** |
| full/empty → insert-one at end | **Yes** (`call 00406e70`) |
| `ret 0` | **Yes** |
| Invented branches | **None** |

### Recovered CF

```c
// customcc; ret 0
void PushBack(void *vec /*EAX*/, const void *value /*ECX*/)
{
  int begin = *(int *)((char *)vec + 4);
  if (begin != 0) {
    unsigned size = (*(int *)((char *)vec + 8) - begin) / 0xc;
    unsigned cap  = (*(int *)((char *)vec + 0xc) - begin) / 0xc;
    if (size < cap) {
      int end = *(int *)((char *)vec + 8);
      FUN_00409db0((void *)end, 1);
      *(int *)((char *)vec + 8) = end + 0xc;
      return;
    }
  }
  void *out = (void *)value;
  FUN_00406e70(vec, &out, *(void **)((char *)vec + 8), value);
}
```

---

## 5. Residual gaps

1. Product / MSVC demangle for 12-byte element type.
2. ConstructN `FUN_00409db0` undualed.
3. Sole caller's enclosing function English / static map meaning.
4. Runtime / differential.

---

## 6. Verdict

**accept-with-gaps** — push_back CF, EAX/ECX ABI, stride 0xC, dual-path sealed from bytes + dualed insert-one + sole caller. Gaps are product type, construct dual, runtime.
