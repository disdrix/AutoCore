# Review B (skeptical / adversarial): `aa_00792980` NDUIWindow_ReloadInterface

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792980` |
| **VA** | `0x00792980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00792980_NDUIWindow_ReloadInterface.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sends a client→server or UI protocol packet | Body has only UI load + local field clears + virtuals; no `Client_Send*`, no bitstream | **Falsified** |
| 2 | Is itself the XML parser / widget factory | Parser is **`NDUIWindow_LoadInterfaceFile` @ `0x007b0ef0`** — this unit only *calls* it | **Falsified as parser**; **survives** as reload orchestrator |
| 3 | Always hides children | Hide loop is under **`path == 0` only**; normal ctor path with `"i_*.xml"` returns after clear | **Falsified** for typical callers |
| 4 | `param_1[0x12d]` is a byte offset `0x12d` | Decompiler uses **dword** indices on `int* this`; bytes prove **`+0x4B4`** (`0x12d*4`) | **Sealed correction** — use byte offs in clean notes |
| 5 | Cached object free is operator `delete` only | Call is `(*vtbl)(1)` — MSVC deleting-dtor / release with flag **1**, not bare free | **Survives as virtual release**; do not claim `operator delete` alone |
| 6 | `FUN_00411e10` fully understood | Only known as lock prelude from call site + hash lock byte | **Do not overclaim** — **Probable** lock only |
| 7 | Name invents non-UI gameplay | 241 UI-ctor xrefs; XML path strings | **Survives** as NDUI leaf |
| 8 | Clean scaffold invents behavior vs raw | Live re-decompile 2026-07-29 matches raw 2026-07-23 body | **No material drift** |

---

## 2. Cross-check: live decompile ≡ raw ≡ bytes

| Checkpoint | Raw / clean | Live decompile | Bytes |
|---|---|---|---|
| Call `LoadInterfaceFile` first | Yes | Yes | `call 0x007b0ef0` via rel32 |
| Zero `[0x12e]/[0x12f]` → `+0x4B8/+0x4BC` | Yes | Yes | `mov [ebp+0x4b8/bc], ebx` |
| Cond. release `*[0x12d]` then zero | Yes | Yes | load `+0x4b4`, `push 1; call [eax]`, store 0 |
| Branch on `path == 0` | Yes | Yes | `cmp esi, ebx` / long jnz |
| Hash walk + `HashError:TraverseToNext…` | Yes | Yes | present in decompile (strings) |
| Child `vtbl+0x28(0)` | Yes | Yes | — |
| Unlock `hash+0x1d=0` + `vtbl+0x34c` | Yes | Yes | — |

**No** material CF drift. Residual risk is **naming** of virtuals and **callee** `LoadInterfaceFile`, not this unit’s branch structure.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Orchestrator role (load + clear cache) | **High** | Wrong UI lifecycle in port |
| Null-path-only child hide | **High** | Incorrectly hide widgets on every XML load |
| Byte offsets `+0x4B4/+0x4B8/+0x4BC/+0x4C0` | **High** | Layout corruption |
| “Hide” = product SetVisible(false) | **Probable** | Wrong child API if reimplemented |
| Hash lock helper identity | **Probable** | Debug-only hazard |
| LoadInterfaceFile semantics | **Out of unit** | File I/O / XML parse bugs elsewhere |
| Server / economy impact | **None** | N/A |

---

## 4. Surviving contract for AutoCore

```
// Client-only NDUI leaf — no wire protocol.
// thiscall NDUIWindow_ReloadInterface(this, path /* may be null */):
//   1. NDUIWindow_LoadInterfaceFile(path)          // always
//   2. this+0x4B8 = 0; this+0x4BC = 0
//   3. if (p = this+0x4B4) { p->vtbl[0](p, 1); } this+0x4B4 = 0
//   4. if (path != null) return
//   5. if (this->vtbl[0x3d8]() && this+0x4C0) {
//        lock-traverse hash at +0x4C0;
//        for each child: child->vtbl[0x28](0);
//        unlock; this->vtbl[0x34c]();
//      }
//
// Typical callers pass "i_*.xml" string literals after widget field init.
// Do not treat this as the XML parser (that is 0x007b0ef0).
```

---

## 5. Open questions (residual)

1. Exact product names / RTTI for `NDUIWindow` and the three virtual slots used here.  
2. Full contract of `NDUIWindow_LoadInterfaceFile` when `path == null`.  
3. Identity of `FUN_00411e10` beyond “hash lock for traversal”.  
4. Exhaustive list of null-path call sites (if any product UI deliberately clears).  
5. Runtime confirmation that child `+0x28(0)` is visibility and not another flag.

**Verdict:** Adversarial checks kill packet / parser / always-hide overclaims. Ownership-clear + dual path CF hold. **accept-with-gaps.**
