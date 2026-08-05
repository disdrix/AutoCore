# Review B (skeptical / adversarial): `aa_004651d0` Mem_FillDwordN_ReturnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004651d0` |
| **VA** | `0x004651d0` |
| **Canonical name** | `Mem_FillDwordN_ReturnEnd` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-T) |
| **Counterpart** | `reviews/A_aa_004651d0_Mem_FillDwordN_ReturnEnd.md` |
| **System** | stl-helpers / POD fill |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a **memcpy/move** of a source range | Loop always reads `[edx]` without advancing edx | **Falsified** — pure fill |
| 2 | Count is in ECX on entry (thiscall/fastcall classic) | Entry `test esi,esi`; ECX loaded from ESI after gate | **Falsified** — count is ESI |
| 3 | Dest is ECX this | Dest is EDI (`mov eax,edi`) | **Falsified** |
| 4 | Value is by-value in a register | `mov ebx,[edx]` each iter | **Falsified** — pointer |
| 5 | Hoists `*value` once (like some optimizers) | `[edx]` inside loop body | **Falsified** hoist claim |
| 6 | Returns void / returns dest only | `lea eax,[edi+esi*4]` | **Falsified** dest-only |
| 7 | `__stdcall` / cleans stack | bare `c3` | **Falsified** stdcall |
| 8 | Same ABI as `StdFill_DwordRange` | That unit is cdecl first/last/value | **Falsified** same-ABI |
| 9 | Same as `Mem_MoveDwordRange_*` | No memmove; leaf fill | **Falsified** |
| 10 | Product name proven | Structural only | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI/ESI/EDX contract | **Confirmed** | Hooking with wrong regs corrupts vectors |
| Fill not move | **Confirmed** | Wrong port uses memmove from value* |
| Return end for chain | **Confirmed** | Realloc suffix write starts wrong |
| Leaf / bare ret | **Confirmed** | Stack imbalance if assumed stdcall |
| Product name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
for (iVar2 = unaff_ESI; iVar2 != 0; iVar2--) {
  *puVar1 = *param_2;  // param_2 = EDX
  puVar1++;
}
return unaff_EDI + unaff_ESI;
```

Bytes: `test esi` → loop `mov ebx,[edx]; mov [eax],ebx; add eax,4; sub ecx,1` → `lea eax,[edi+esi*4]; ret`.

**Trap:** decompiler labels `__fastcall` with a dummy `param_1` and hides EDI/ESI. Ports must not invent ECX-this or stack args.

**Trap:** parents (`FUN_00456960`) prepare fill value in `*EAX` for themselves, but **this** helper takes the value pointer in **EDX** — caller must set EDX before call (decompiler often elides the reg setup).

---

## 4. Surviving contract for AutoCore

```c
// Port of Mem_FillDwordN_ReturnEnd (aa_004651d0)
// Retail: EDI=dest, ESI=count, EDX=&fill; bare ret; EAX=end
uint32_t *Mem_FillDwordN_ReturnEnd(uint32_t *dest, int count, uint32_t const *value) {
  for (int i = 0; i < count; ++i)
    dest[i] = *value;
  return dest + count;
}
```

- Server ports: use normal C++ args; do **not** preserve EDI/ESI ABI unless binary-hooking retail.
- Do **not** replace with `memset` unless value is 0 and you accept byte-fill semantics (not general dword fill).
- Pair with `Mem_MoveDwordRange_ReturnEnd_EcxEax` (`0x0040c7c0`) on insert-N paths — do not fold both into one helper.

---

## 5. Open questions

1. Product/PDB name (`_Fill_n` / `uninitialized_fill_n` POD).
2. Whether negative ESI is reachable (bytes treat as non-zero; huge loop) — callers seal non-negative.
3. Runtime golden vs synthetic fill-N.

**Verdict:** **accept**
