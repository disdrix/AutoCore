# Review B (skeptical / adversarial): `aa_004165f0` Class_00a70524_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004165f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9I-J) |
| **Counterpart** | `reviews/A_aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a vector-deleting dtor (flags&2 / count) | **Falsified** — only bit0 tested; no count arg |
| 2 | operator_delete never returns / function diverges | **Falsified** — bytes always `MOV EAX,ESI; RET 4` |
| 3 | Complete is inline / no callee | **Falsified** — `CALL 0x008327f0` |
| 4 | CODE call sites exist | **Falsified** — DATA xref only (vtbl[0]) |
| 5 | Same object type as `00416590` shell | **Falsified** — unrelated CF/ABI/vtbl |
| 6 | Product name is sealed by chatlog string alone | **Partially true** — string is on **peer ctor** `00832830`; this unit names by vtbl |
| 7 | `RET 0` / cdecl | **Falsified** — `C2 04 00` thiscall flags cleanup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / RET 4 / return this | **High** | Wrong delete path |
| flags bit0 → delete | **High** | Leak or double-free port |
| vtbl[0] @ `00a70524` | **High** | Wrong slot binding |
| Complete `008327f0` | **High** | Incomplete teardown |
| Product demangle | Low | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
push esi
mov esi, ecx
call FUN_008327f0
test byte [esp+8], 1
jz skip
push esi
call operator_delete
add esp, 4
skip:
mov eax, esi
pop esi
ret 4
```

Vtbl dword0 @ `0x00a70524` = `0x004165f0`. Do **not** invent vector-deleting form. Do **not** claim runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// void* ScalarDeletingDtor(this, byte flags)  // thiscall, ret 4
// complete_dtor(this); if ((flags&1)!=0) delete this; return this;
```

Port as MSVC vtbl[0] scalar dtor for class `00a70524`. Pair complete `008327f0` when dualed.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm standard scalar-deleting dtor. Residual: product English, complete dual, runtime. Not reject.
