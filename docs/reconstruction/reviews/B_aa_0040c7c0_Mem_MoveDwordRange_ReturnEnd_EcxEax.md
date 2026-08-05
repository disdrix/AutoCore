# Review B (skeptical / adversarial): `aa_0040c7c0` Mem_MoveDwordRange_ReturnEnd_EcxEax

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c7c0` |
| **VA** | `0x0040c7c0` |
| **Canonical name** | `Mem_MoveDwordRange_ReturnEnd_EcxEax` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-T) |
| **Counterpart** | `reviews/A_aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md` |
| **System** | stl-helpers / POD relocate |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | True `__thiscall` method on a C++ object | No field loads; ECX is range begin only | **Falsified** object-method |
| 2 | Same ABI as `Mem_MoveDwordRange_ReturnEnd` (`004e2e80`) | Twin uses 3 stack args + `ret 0xC`; this is ECX/EAX/`ret 4` | **Falsified** same-ABI |
| 3 | Byte-exact `end-begin` size | Size is `(span>>2)*4` | **Falsified** pure-byte size |
| 4 | `memcpy` (no overlap) | IAT / callees say memmove | **Falsified** memcpy |
| 5 | Returns dest only (not end) | `add eax,esi` after call | **Falsified** dest-only |
| 6 | Two stack formals (decompiler looks like thiscall+1) | Only dest on stack; end in EAX | **Attack fails** — EAX end sealed |
| 7 | Fill helper (same as `004651d0`) | Calls memmove of a range | **Falsified** fill |
| 8 | Scaffold invents CF | Live ≡ 2026-07-23 raw; 35 B seal | **Attack fails** |
| 9 | Prior mission/assManager alias is the product name | Multi-caller generic helper | **Falsified** domain name |
| 10 | Product STL name proven | Structural only | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX/EAX/stack/`ret 4` | **Confirmed** | Stack imbalance if ported as cdecl/thiscall method |
| Size floor to dwords | **Confirmed** | Over/under-copy on odd spans |
| Return write-end | **Confirmed** | Broken chain in insert-N realloc |
| memmove overlap safety | **Confirmed** | Corruption under overlap if memcpy |
| Distinct from `004e2e80` ABI | **Confirmed** | Wrong call convention at hooks |
| Product name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
_Size = (in_EAX - (int)param_1 >> 2) * 4;
pvVar1 = memmove(param_2, param_1, _Size);
return (void *)((int)pvVar1 + _Size);
```

Bytes: `sub eax,ecx` → `sar 2` → `lea esi,[eax*4]` → load dest → push size/src/dest → IAT memmove → `add eax,esi` → `ret 4`.

**Trap:** decompiler signature omits `in_EAX` as a formal and labels `__thiscall`. Adversarial seal requires EAX end + `ret 4`.

**Trap:** do not merge with `004e2e80` when binary-hooking — same math, different cleanup size (4 vs 12).

---

## 4. Surviving contract for AutoCore

```c
// Port of Mem_MoveDwordRange_ReturnEnd_EcxEax (aa_0040c7c0)
// Retail: ECX=srcBegin, EAX=srcEnd, push dest; ret 4
void *Mem_MoveDwordRange_ReturnEnd_EcxEax(void *srcBegin, int srcEnd, void *dest) {
  size_t size = ((size_t)((int)srcEnd - (int)srcBegin) >> 2) * 4;
  void *p = memmove(dest, srcBegin, size);
  return (char *)p + size;
}
```

- Server ports: normal C++ three-arg function; ignore register ABI unless hooking.
- Do **not** use `memcpy` if any caller may overlap (insert-N in-place does).
- Pair with `Mem_FillDwordN_ReturnEnd` (`0x004651d0`) on insert-N — keep separate.

---

## 5. Open questions

1. Product/PDB STL helper name.
2. Whether any site relies on partial-dword truncation (math sealed; callers pass aligned ends).
3. Runtime golden vs synthetic relocate.

**Verdict:** **accept**
