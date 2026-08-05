# Review B (skeptical / adversarial): `aa_004d0e90` Object_EnqueueDeferredOnce

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0e90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d0e90_Object_EnqueueDeferredOnce.md` |
| **System** | client world / reaction lifecycle |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on bit0 + `+0xe5fc` enqueue; **reject** decompiler-only signature and “immediate destroy” claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Signature is `void f(int obj)` with no this | **Falsified** — `mov edi,ecx`; `ret 4`; queue from `[edi+0xe5fc]` |
| 2 | Callees take only the object (no queue this) | **Falsified** — both calls `mov ecx,[edi+0xe5fc]; push esi; call` |
| 3 | Function always enqueues | **Falsified** — early outs on bit0 set **or** list contains |
| 4 | This **destroys** / frees the object | **Falsified** — only list append + flag OR; no delete/vcall |
| 5 | Flag mask is Broken `0x80000` / other bit | **Falsified** — imm/tests use **`1`** only |
| 6 | Queue field is `+0xe5c0` (removal hash from RemoveObject) | **Falsified** — imm is **`0xe5fc`** (`fc e5 00 00`) |
| 7 | Bit set without list insert possible | **Only if** contains returned true (bit may lag); when inserting, OR is after append |
| 8 | Scaffold “only RemoveObject callee” | **Overstated** — ~20 callers (collision, weapon hardpoint, continent unlock, …) |
| 9 | Ready for bit-exact / runtime seal | **Fail** — matrix open; no live CE this pass |
| 10 | Name must be teardown-only | **Nuance** — RemoveObject uses it on dead-alive short path, but other callers are general deferred work |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Host*
// [esp+4] at entry = Object*   (after push esi → [esp+8] in body)
// ret 4

if ( *(u8*)(obj + 0x17c) & 1 ) return;

q = *(void**)(host + 0xe5fc)
if ( FUN_004e15a0(q, obj) ) return;   // AL != 0

FUN_004024d0(q, obj)
*(u32*)(obj + 0x17c) |= 1
```

### Byte anchors (not decompiler-only)

| Addr | Bytes | Meaning |
|------|-------|---------|
| `004d0e90` | `56` | `push esi` |
| `004d0e91` | `8b 74 24 08` | `mov esi, [esp+8]` object |
| `004d0e95` | `f6 86 7c 01 00 00 01` | `test [esi+0x17c], 1` |
| `004d0e9d` | `8b f9` | `mov edi, ecx` host |
| `004d0ea1` | `8b 8f fc e5 00 00` | `mov ecx, [edi+0xe5fc]` |
| `004d0ea8` | `e8 f3 06 01 00` | `call FUN_004e15a0` |
| `004d0eb8` | `e8 13 16 f3 ff` | `call FUN_004024d0` |
| `004d0ebd` | `83 8e 7c 01 00 00 01` | `or [esi+0x17c], 1` |
| `004d0ec6` | `c2 04 00` | `ret 4` |

Relative checks:
- next after first call = `004d0ead`; + `0x000106f3` → **`004e15a0`**
- next after second = `004d0ebd`; + signed `0xfff31613` → **`004024d0`**

---

## 3. Relation attack: flag bits at `+0x17c`

| Unit / bit | Mask | Role |
|------------|------|------|
| **This** bit **0** | **`0x1`** | Deferred-queued sticky |
| Item Broken bit 19 | `0x80000` | **Other unit** `Item_SetBroken` |
| Dirty bit 17 | `0x20000` | `FUN_00512670` — not here |
| RemoveObject bit tests at `+0x17d` | various | sibling field, not this write |

---

## 4. Adversarial name check

- **Reject** pure “DestroyObject” — no free path.
- **Accept** `Object_EnqueueDeferredOnce` as descriptive INFERRED name.
- Alternate acceptable: `CVOGReaction_EnqueueObjectDeferredOnce` if registry prefers host-centric naming (ECX is host).

---

## 5. Residual risks

1. Race between bit0 and list membership if another thread clears one side (no lock in this unit around the bit).
2. Host type not fully typed (reaction vs sector map vs other large object with `+0xe5fc`).
3. Consumer of the queue unknown → “deferred work” semantic is structural not product-string proven.

**Verdict:** Decompiler signature rejected; sealed ABI/CF holds. **accept-with-gaps.**
