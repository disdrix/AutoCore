# Review B (skeptical / adversarial): `aa_0096ef70` RefCountedPtr_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096ef70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-N) |
| **Counterpart** | `reviews/A_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function does meaningful work beyond `*p=0` | **Falsified** — entire body is 9 bytes, one store |
| 2 | Decompiler `void` is complete ABI | **Partially falsified** — EAX returns this (`mov eax,ecx`) |
| 3 | TacArc-only helper (auto-name) | **Falsified** — ~62 xrefs across many systems |
| 4 | This is the same type as `FUN_0096f530` | **Falsified** — peer zeros 3 extra bytes; different layout |
| 5 | “RefCountedPtr” name is product-proven RTTI | **Accepted as INFERRED only** — role from peer dtor, not demangled type |
| 6 | Function frees / decrements refs | **Falsified** — no loads of payload; dtor is `0096efd0` |
| 7 | Body size includes padding `cc` | **Falsified** — logical body ends at `C3` @ `0096ef78` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single store CF | **High** | None (trivial) |
| Handle/null-init role | **High** | Wrong if treated as full object zero |
| Product type name | Medium/Inferred | Naming only |
| Calling convention ECX | **High** | Wrong register at call sites |

---

## 3. Cross-check against raw + bytes

```
8B C1                 mov eax, ecx
C7 00 00 00 00 00     mov dword ptr [eax], 0
C3                    ret
```

Clean must **not** invent refcount math, vtbl install, or multi-field zeroing.

Call-site note: TacArc stages SEH around two sequential calls — each initializes a **distinct embedded handle slot**, not a double-init of one field without intermediate ECX reload (caller sets ECX each time).

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape
struct RefCountedPtr { void* payload; /* only field init here */ }
static void DefaultCtor(RefCountedPtr* self) { self->payload = null; }
// Pair with dtor that --refcount / release when dual-sealed
```

Server ports rarely need this exact helper unless sharing client UI/asset handle types.

---

## 5. Open questions

1. Payload class RTTI / vtbl at `payload+4`.
2. Whether some call sites re-null after attach without dtor (leak risk if so).
3. Dual seal schedule for `0096efd0`.

**Verdict:** **accept**
