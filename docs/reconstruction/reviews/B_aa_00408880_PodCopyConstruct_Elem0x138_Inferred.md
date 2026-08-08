# Review B (skeptical / adversarial): `aa_00408880` PodCopyConstruct_Elem0x138_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9H-I) |
| **Counterpart** | `reviews/A_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + callers/xrefs + assembly_context. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is CNDHash freelist / tree buynode (VA neighborhood) | **Falsified** — pure POD dword copy; no `operator_new`, no isnil/color |
| 2 | Width is 0x28 or 0x98 or 0x30 | **Falsified** — 14 dwords + 0x40 dwords = **0x138** |
| 3 | `ret 0` cdecl / no stack formals | **Falsified** — **`ret 4`**; stack src sealed by `8B 4C 24 04` |
| 4 | Fastcall / two register pointers only | **Falsified** — ECX dest + stack src; thiscall plate matches callers |
| 5 | Non-POD construct (vtbl / nested ctors) | **Falsified** — leaf stores only; no CALLs |
| 6 | Scaffold SendLogicUi chain name is product | **Falsified as product** — callee plate only; dual renames |
| 7 | Multiple independent element types | **Fails as multi-type** — sole sealed consumer width is LogicUi 0x138; 0040a6e0 shares width |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 ABI | **High** | Stack imbalance |
| Width 0x138 | **High** | Misaligned queue elements |
| Role = POD construct leaf | **High** | Invented tree/hash semantics |
| Product field English | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
004076ca: lea ecx, [ebp+local_164]   ; dest = 0x138 stack buf
004076c6: mov eax, [ebp+0x10]        ; valueSrc
004076c9: push eax
004076d0: call FUN_00408880          ; thiscall construct

0040a70e: push src; ecx = dest; call FUN_00408880
```

Do **not** merge with empty tree buynode `0x004088f0` (next symbol). Do **not** treat as freelist node copy.

---

## 4. Surviving contract for AutoCore

```csharp
// void PodCopyConstruct_Elem0x138(void* dest /*this*/, in byte src /*0x138*/)
// ECX=dest, stack src, ret 4
// ≡ memcpy(dest, src, 0x138)
```

Pair with `LogicUiEventQueue_InsertN` (`0x004076a0`) and residual placement `FUN_0040a6e0`.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm POD construct leaf CF/ABI/width. Residual demangle + event field map + runtime. Not reject.
