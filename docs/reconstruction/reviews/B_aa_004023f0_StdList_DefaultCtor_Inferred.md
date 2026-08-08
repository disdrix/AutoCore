# Review B (skeptical / adversarial): `aa_004023f0` StdList_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004023f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-052) |
| **Counterpart** | `reviews/A_aa_004023f0_StdList_DefaultCtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `CVOGReaction_Dispatch`-specific / mission packet helper | **Falsified** — 5 CALL + 2 DATA sites across reaction, variable-eval, UI, and generic helpers; body is pure head/size init |
| 2 | Full `std::list` copy / insert / populate | **Falsified** — sole callee is sentinel alloc; no node insert; size forced to 0 |
| 3 | Constructs sentinel **in place** (no heap) | **Falsified** — `CALL 0040fb90` → `operator_new(0xc)` |
| 4 | Head at `this+0`, size at `this+4` | **Falsified** — bytes store **+4** / **+8**; destroy dual frees `*(this+4)` |
| 5 | `__stdcall` / `RET 4` / stack msg arg | **Falsified** — plain **`RET`** (`C3`); ECX this only |
| 6 | Same as `FUN_00402410` (copy ctor) | **Falsified** — `00402410` also inserts range via `FUN_00404490` after empty init |
| 7 | Same as `FUN_0040fb90` (sentinel only) | **Falsified** — `0040fb90` returns node*; this writes list object fields |
| 8 | Vector / array constructor itself | **Falsified** — DATA sites **push this as element ctor** into `_eh_vector_constructor_iterator_`; body is single-object ctor |
| 9 | Writes full 0xC object including +0 | **Clarify** — only +4/+8 written; +0 residual open |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty list default ctor role | **Confirmed** | Wrong port semantics |
| ECX this / EAX this / RET | **Confirmed** | Stack imbalance |
| Head@+4 size@+8 | **Confirmed** | Corrupt list layout |
| Pair with 0040fb90 / 00403430 | **Confirmed** | Leak / double-free |
| Object size 0xC | **High** (vector stride) | Wrong array spacing |
| `list+0` meaning | **Low** | Allocator/base residual only |
| Element `T` product name | **Low** | Site-specific |
| Domain = missions only | **Falsified** | Misleading system tags |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean StdList_DefaultCtor_Inferred.cpp

56                   PUSH ESI
8B F1                MOV ESI, ECX
E8 98 D7 00 00       CALL 0040fb90     ; 004023f8+0xD798 = 0040fb90
89 46 04             MOV [ESI+4], EAX
C7 46 08 00 00 00 00 MOV [ESI+8], 0
8B C6                MOV EAX, ESI
5E                   POP ESI
C3                   RET
```

Call-site pattern (all UNCONDITIONAL_CALL samples):

```text
LEA ECX, [ESP+disp]   ; or similar local list
CALL 004023f0
```

DATA vector-ctor pattern (`004e8109` / `008a5d0a`):

```text
PUSH 00403430         ; element dtor (destroy free head)
PUSH 004023f0         ; element ctor (this unit)
PUSH count            ; 0x1a or 0x4
PUSH 0xC              ; element size
LEA  ..., array
CALL _eh_vector_constructor_iterator_
```

Reject ports that:

- Name this as reaction/mission-only helper.
- Treat it as list insert, clear, or destroy.
- Place head at +0 or size at +4.
- Use cdecl with a stack list arg / `RET 4`.
- Skip the sentinel alloc and zero a stack buffer only.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail MSVC list object (0xC) default ctor:
//   _Myhead = new sentinel{ next=prev=self }; _Mysize = 0;

sealed class StdListEmpty
{
    // +0 residual (allocator / container_base) — not written by retail ctor
    public ListNode Myhead; // +4
    public int Mysize;      // +8

    public StdListEmpty()
    {
        Myhead = StdListAllocEmptySentinel.Alloc(); // aa_0040fb90
        Mysize = 0;
    }
}

// Pair destroy: clear nodes then operator_delete(Myhead) — aa_00403430
```

**Port note:** implement as ordinary empty `List<T>` / `LinkedList<T>` construction. Do **not** invent reaction-dispatch side effects.

---

## 5. Verdict

Adversarial path falsifies domain-misname / wrong layout / wrong ABI claims. Surviving contract is empty-list default ctor with residual +0 / element-`T` gaps → **accept-with-gaps**.
