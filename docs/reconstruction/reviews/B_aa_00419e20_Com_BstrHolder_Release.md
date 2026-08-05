# Review B (skeptical / adversarial): `aa_00419e20` Com_BstrHolder_Release

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-L) |
| **Counterpart** | `reviews/A_aa_00419e20_Com_BstrHolder_Release.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a generic COM `IUnknown::Release` | **Falsified** — frees BSTR + array + self; no vtbl |
| 2 | ECX-this / `__thiscall` with stack args | **Falsified** — **ESI-this**, plain `ret` |
| 3 | `operator_delete` never returns (decomp warning) | **Falsified** — `83 c4 04; 33 c0; 5f; c3` after call |
| 4 | Secondary at +4 uses scalar `delete` | **Falsified** — **`operator_delete[]`** |
| 5 | Mission-only helper (parent-seed name) | **Falsified** — many COM/XML callers beyond mission |
| 6 | Create size ≠ 0xC | **Falsified** — create sibling sealed `push 0xC` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| BSTR holder release role | **High** | Leak / double-free in COM ports |
| ESI-this ABI | **High** | Wrong register in hand-ports |
| Array-delete of +4 | **High** | Heap corruption if scalar delete |
| Mission-specific semantics | Low relevance | Name residue only |
| Product class spelling | Medium | Docs-only |

---

## 3. Cross-check against raw + bytes

```
push edi
lea edi, [esi+8]
call InterlockedDecrement
jnz still_live          ; mov eax,[edi]; pop edi; ret
test esi, esi
jz ret0
; SysFreeString([esi]) if nonzero
; operator_delete[]([esi+4]) if nonzero
; operator_delete(esi)
xor eax, eax
pop edi
ret
```

Clean must **not** implement as `Release()` on an IUnknown vtbl or as mission-objective logic. Parent-seed alias is **not** the role.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of Com_BstrHolder_Release (if server ever mirrors client COM BSTR holders)
long Com_BstrHolder_Release(ComBstrHolder self)
{
    if (Interlocked.Decrement(ref self.RefCount) != 0)
        return self.RefCount;
    if (self != null) {
        if (self.Bstr != IntPtr.Zero) SysFreeString(self.Bstr);
        if (self.Secondary != null) DeleteArray(self.Secondary);
        Free(self);
    }
    return 0;
}
// Server skill-DB path typically avoids this client COM helper family.
```

---

## 5. Open questions

1. Whether any AutoCore server path needs a matching holder.
2. Field name of secondary buffer in product source.

**Verdict:** **accept**
