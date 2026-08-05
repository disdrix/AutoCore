# Review B (skeptical / adversarial): `aa_005121d0` IsPlayerTargetingLinkAndDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_005121d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005121d0_IsPlayerTargetingLinkAndDestroy.md` |
| **System** | object / combat-target / HB |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler 1-arg is full ABI | Epilogue `ret 0xC` | **Falsified** 1-arg as complete — port with **3** stack slots |
| 2 | Is `__thiscall` on entry | Entry `mov esi,[esp+8]`; ECX unused | **Falsified** as thiscall entry |
| 3 | Destroys all HB types on target change | RTTI requires **PlayerTargetingLink** subclass | **Falsified** as universal destroy — base HB kept |
| 4 | Cast uses wrong type order | Push order matches MSVC `__RTDynamicCast(src,0,from,to,0)` | **Survives** |
| 5 | Return value ignored by list walk | Parent documents remove-if; AL 0/1 | **Survives** as remove signal |
| 6 | Named “drive tick helper” is accurate | Sole xref is `Object_SetSelectedTarget` | **Falsified** as primary name — demote to alias |
| 7 | `vtbl+0x18(1,0)` is always `delete this` | Flags (1,0) could mean Release/deferred | **Open** English — **behavior** call sealed |
| 8 | RTTI strings misread | `read_memory` shows `.?AVCVOGHBBase@@` / `.?AVCVOGHBPlayerTargetingLink@@` | **Survives** |

---

## 2. Live ≡ raw

```
// full function (image)
push esi
mov  esi, [esp+8]          ; node
push 0
push offset PlayerTargetingLink_RTTI   ; 0x00af1bb0
push offset Base_RTTI                  ; 0x00af8d98
push 0
push esi
call __RTDynamicCast                   ; 0x004898A4
add  esp, 14h
test eax, eax
jz   keep
mov  eax, [esi]
push 0
push 1
mov  ecx, esi
call dword ptr [eax+18h]
mov  al, 1
pop  esi
ret  0Ch
keep:
; al = 0
pop  esi
ret  0Ch
```

No extra branches, no static writes, no SEH.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF + RTTI pair | **Confirmed** | Wrong purge class |
| `ret 0xC` arity | **Confirmed** | Stack imbalance if ported as 1-arg cdecl without cleanup |
| Remove-if return | **High** | Links leak or over-delete |
| Destroy flag meaning | **Medium** | Wrong teardown if reimplemented with plain `delete` only |

---

## 4. Surviving contract for AutoCore

```
// MUST preserve ret 0xC / 3-arg stack shape for list walker.
// MUST RTTI-filter CVOGHBPlayerTargetingLink only — do not destroy base HB nodes.
// MUST call vtbl+0x18(this, 1, 0) before signaling remove.
// Sole production caller: Object_SetSelectedTarget purge of entity+0xB0.
IsPlayerTargetingLinkAndDestroy(node, ctx1=0, ctx2=0) -> 0|1
```

**Verdict:** **accept**.
