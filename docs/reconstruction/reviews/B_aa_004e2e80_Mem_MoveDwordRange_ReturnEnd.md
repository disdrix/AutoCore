# Review B (skeptical / adversarial): `aa_004e2e80` `Mem_MoveDwordRange_ReturnEnd`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2e80` |
| **VA** | `0x004e2e80` |
| **Canonical name** | `Mem_MoveDwordRange_ReturnEnd` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md` |
| **System** | `stl-helpers` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__cdecl` / bare `ret` | Bytes end `C2 0C 00` | **Falsified** cdecl |
| 2 | `__thiscall` ECX this | No ECX use as this; all three args stack | **Falsified** thiscall |
| 3 | Byte-exact `end-begin` size | Size is `(span>>2)*4` | **Falsified** pure-byte size |
| 4 | `memcpy` (no overlap) | IAT is memmove | **Falsified** memcpy |
| 5 | Returns dest only (not end) | `add eax,esi` after call | **Falsified** dest-only return |
| 6 | Args order dest,src | Stack: begin, end, dest; memmove(dest,src,size) | **Attack fails** — order sealed |
| 7 | Scaffold invents CF | Live ≡ raw; 42 B bytes seal | **Attack fails** |
| 8 | Product STL name proven | Structural only | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `__stdcall` `ret 0xC` | **Confirmed** | Stack imbalance if ported cdecl |
| Size floor to dwords | **Confirmed** | Over/under-copy on odd spans |
| Return write-end | **Confirmed** | Broken chain-assign in realloc helpers |
| memmove overlap safety | **Confirmed** | Corruption if ported to memcpy under overlap |
| Product name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
_Size = (param_2 - (int)param_1 >> 2) * 4;
pvVar1 = memmove(param_3, param_1, _Size);
return (void *)((int)pvVar1 + _Size);
```

Bytes: stack load begin/end → `sub` → `sar 2` → `lea *4` → push size/src/dest → IAT memmove → `add eax,esi` → `ret 0xC`.

**Trap:** decompiler signature looks like cdecl `void*(void*,int,void*)` without showing `ret 0xC`. Adversarial seal requires the epilogue — **must** port as stdcall / callee-clean 12.

---

## 4. Surviving contract for AutoCore

```c
// Port of Mem_MoveDwordRange_ReturnEnd (aa_004e2e80)
// Callee cleans 12 bytes (MSVC __stdcall).
void* Mem_MoveDwordRange_ReturnEnd(void* srcBegin, int srcEnd, void* dest) {
  size_t size = ((size_t)((int)srcEnd - (int)srcBegin) >> 2) * 4;
  void* p = memmove(dest, srcBegin, size);
  return (char*)p + size;
}
```

- Do **not** use `memcpy` if any caller may overlap.
- Do **not** use full `(srcEnd-srcBegin)` when span may be non-multiple of 4.

---

## 5. Open questions

1. Product/PDB STL helper name.
2. Whether any call site relies on partial-dword truncation (unlikely but sealed by math).

**Verdict:** **accept**
