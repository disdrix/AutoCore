
# Review B (skeptical / adversarial): `aa_0075dae0` Owner_ClearDestroyGuardedPtrDequeAt28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dae0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-C) |
| **Counterpart** | `reviews/A_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| **Scratch** | `tmp/a_0075dae0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler loop is authoritative | **Falsified** — `for (u=0; u!=0;)` never runs; bytes walk `begin..begin+size` |
| 2 | No this / freestanding void | **Falsified** — `MOV EDI,ECX; ADD EDI,0x28` before ClearAndSwap |
| 3 | Operates on free-standing container in ESI only | **Falsified** — owner thiscall; field at +0x28 is B; local is A |
| 4 | operator_delete per element | **Falsified** — `PUSH 1; CALL [vtbl]` scalar deleting dtor, not raw delete |
| 5 | ClearAndSwap optional | **Falsified** — always called; required steal so field empties under CS |
| 6 | Has live callers | **Survives as gap** — 0 xrefs; may be dead or data-only |
| 7 | Product name | **Overstated** — inferred structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX owner +0x28 field | **High** | Clear wrong member |
| Steal + dtor + free order | **High** | Leak / double-free |
| Page map math | **High** (same family as PushBack) | UAF / skip elements |
| Decompiler text | **Low** | Wrong port if trusted |
| Reachability | **Open** | Dead-code retention |
| Owner type English | **Open** | Naming only |

---

## 3. Cross-check against raw + bytes

```
raw decompile: FUN_0043c660(); for(u=0;u!=0;++u) vtbl; FUN_0040d9c0();
bytes:        EDI=ECX+0x28; ESI=local; ClearAndSwap;
              EDI=begin; while EDI!=begin+size: map load; vtbl(1); ++EDI;
              ESI=local; 0040d9c0; ADD ESP,0x20; RET
```

Call offsets: `E8` at steal → `0043c660`; free → `0040d9c0` (verified from body placement + relative).

---

## 4. Surviving contract for AutoCore

```
// Owner clear of owned-pointer GuardedVector at +0x28:
//   ECX = owner
//   ClearAndSwap(empty_local, owner+0x28)  // ESI/EDI ABI
//   for each ring element: if p: p->dtor_delete(1)
//   FUN_0040d9c0(local)  // free pages+map
// Do not trust Ghidra decompile for this VA.
// Do not port as plain vector clear without page map + steal.
```

---

## 5. Verdict

Adversarial pass **confirms** A on byte CF/ABI; forces decompile override; leaves xrefs/owner English/runtime → **accept-with-gaps**.

