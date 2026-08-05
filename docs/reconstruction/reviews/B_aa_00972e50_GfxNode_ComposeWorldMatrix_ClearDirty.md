# Review B (skeptical / adversarial): `aa_00972e50` GfxNode_ComposeWorldMatrix_ClearDirty

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972e50` |
| **VA** | `0x00972e50` |
| **Canonical name** | `GfxNode_ComposeWorldMatrix_ClearDirty` (structural) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00972e50_GfxNode_ComposeWorldMatrix_ClearDirty.md` |
| **System** | graphics / scene graph |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This function **is** the full TRS math | Body is thin: call `76f970` + clear bit | **Falsified** — math is callee |
| 2 | Always runs only when dirty | **This** VA always composes; **caller** `00972fa0` gates on bit 0 | **Partial** — entry itself unconditional |
| 3 | Local 16-byte buffer is the world matrix dest | `76f970` writes 16 dwords to its dest formal; dest mapping is callee-owned | **Do not claim** local is final 4×4 storage |
| 4 | Decompiler `FUN_0076f970(param_1,&local,…)` with this=node | Bytes set **`ECX=0x00D1A6C0`** before call; node is stack arg | **Falsified** decompiler this-elision |
| 5 | Clears entire flags dword | `AND …, 0xFFFFFFFE` clears **only bit 0** | **Falsified** full-clear |
| 6 | Exclusive to terrain chunker | 49 xrefs across gfx | **Falsified** exclusive |
| 7 | Product name sealed | No RTTI/string | **Agree structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dirty bit 0 at +0xBC clear | **Confirmed** | Infinite dirty loops / missed updates |
| ECX in = node; EAX out = node | **Confirmed** | ABI break |
| Composer service @ `0x00D1A6C0` | **Confirmed** | Wrong singleton |
| Field roles +0x80/+0x90/+0x9C English | **Tentative** | Wrong component wiring |
| Dest matrix location on node | **Open** (callee) | Write to wrong offset |

---

## 3. Cross-check against raw / live / bytes

```
read_memory @ 0x00972e50 (full ~0x60 B):
  sub esp,10; xorps xmm0,xmm0; push esi; mov esi,ecx
  push [esi+0x90]; push [esi+0x80]; push [esi+0x9c]
  push &local; mov ecx, 0x00D1A6C0
  store local xyz=0; push esi; mov eax,ecx; local.w=1
  call FUN_0076f970; add esp,14
  and dword [esi+0xbc], 0xfffffffe
  mov eax,esi; pop esi; add esp,10; ret
```

### Dirty-bit trap

`FUN_00972fa0` pattern:

```
if (node->flags & 1) GfxNode_ComposeWorldMatrix_ClearDirty(node);
Math_Mat4TransformPoint3_Project(...);  // uses matrix
```

Calling **only** `76f6e0` without rebuild when bit0 set uses stale matrix. Calling **only** `972e50` every frame is correct but expensive — matches “clear dirty after compose”.

### Decompiler trap

Do not trust Ghidra’s `FUN_0076f970(param_1, &local_10, …)` as thiscall-on-node. Bytes force global `this`.

---

## 4. Surviving contract for AutoCore

```
GfxNode* GfxNode_ComposeWorldMatrix_ClearDirty(GfxNode* self)  // ECX
  // compose via global service 0x00D1A6C0 + FUN_0076f970
  // inputs: self, temp (0,0,0,1), self+0x9C, self+0x80, self+0x90
  self->flags_0xBC &= ~1u;
  return self;
```

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| Entry CF / dirty clear / call shape | **Sealed Confirmed** |
| Full TRS compose (`76f970`) | Open (separate dual) |
| Field English | Tentative |
| Product name | Open |

**Verdict:** accept-with-gaps.
