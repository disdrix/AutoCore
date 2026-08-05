# Review B (skeptical / adversarial): `aa_00985390` AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-P) |
| **Counterpart** | `reviews/A_aa_00985390_AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-only thiscall single formal | **Falsified** — bytes `mov edi,ecx; mov esi,eax`; dual formals |
| 2 | Decompiler `in_EAX` is phantom garbage | **Falsified** — block offset/size loaded from ESI=EAX; call site sets EAX |
| 3 | Returns full EAX status codes | **Falsified** — only AL set (`mov al,1` / `xor al,al`) |
| 4 | Always inserts new free range | **Falsified** — coalesce next and prev arms before insert |
| 5 | gfxIndexBuffer product unit | **Falsified** — scaffold alias only; pack free-map CF + AssPack neighborhood |
| 6 | RET 4 stdcall | **Falsified** — bare `C3` after frame teardown |
| 7 | Product PDB name sealed | **Careful** — `_Inferred` structural name only |
| 8 | Map empty means failure | **Open wording** — AL=1 only when count hits 0 after erase; caller treats non-zero as continue-free |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual formal ECX/EAX + AL | **High** | Wrong port ABI |
| Erase-then-coalesce order | **High** | Double-free / leak |
| Free pair stride 8 | **High** | Corrupt free list |
| Map key = block pointer | **Med-High** | Wrong find key |
| Product English | **Low/Open** | Misnamed type |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
// entry: sub esp,0xC; push ebx/ebp/esi/edi; mov edi,ecx; mov esi,eax
// map:   lea ebp,[edi+4]; call FUN_00445750; call FUN_004477a0
// empty: cmp [edi+0xc],0 → mov al,1; ret
// free:  mov edx,[esi+0x18]; mov eax,[esi+0x1c]; begin=[edi+0x14]; end=[edi+0x18]
// lb:    call FUN_00460a60
// next:  if cursor!=end && *cursor==offset+size → merge; xor al,al; ret
// prev:  if cursor!=begin && prev.end==offset → merge size; xor al,al; ret
// ins:   call FUN_00445c80; xor al,al; ret
// caller FUN_00985a30 @ 00985a85: mov eax,ebx; mov ecx,edi; call; test al,al
```

---

## 4. Surviving contract for AutoCore

```
// Port as pack free-map release (not gfx index buffer):
uint8_t ReleaseBlock(Host* host, Block* block) {
  // erase map entry for block at host->map (+0x04)
  // if host->map_count (+0x0c) == 0 return 1;
  // range = { block->offset(+0x18), block->size(+0x1c) };
  // lower_bound free_vec; coalesce adjacent or insert; return 0;
}
// Preserve AL-only return. Do not invent vtbl. Pair with pack open/compact free-map owners.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, erase/coalesce CF, stride-8 free pairs, sole caller. Product plates + nested helpers residual → **accept-with-gaps**.
