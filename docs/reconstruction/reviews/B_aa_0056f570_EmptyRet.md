# Review B (skeptical / adversarial): `aa_0056f570` EmptyRet

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056f570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-P) |
| **Counterpart** | `reviews/A_aa_0056f570_EmptyRet.md` |
| **Verdict** | **accept** (trivial CF; residual is naming/catalog only) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Body does real work (flags, free, notify) | **Falsified** — sole byte `c3` |
| 2 | Domain-specific Client_InitInstance helper (parent-seed name) | **Falsified as purpose** — mass Unwind/vtbl reuse; name is scaffold noise |
| 3 | Is the LED/GetCapabilities logger | **Falsified as implementation** — call sites pass strings, but body is empty (sink/nop) |
| 4 | Same unit as `VehicleEntity_DrivePathNoOp` `0x004f3700` | **Falsified** — different VA; both empty rets, not aliases |
| 5 | `__stdcall` / `ret 4` ABI | **Falsified** — bare `c3` |
| 6 | Returns meaningful EAX | **Unfounded** — no `mov eax` in body; callers must not depend on return |
| 7 | Base HB slot 7 always does work | **Falsified for base** — base points here; **derived** player targeting overrides (`0x0051b850`) |
| 8 | Clean should invent printf-like body because callers pass formats | **Falsified** — clean must stay empty; callers waste args |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pure nop body | **High** | inventing side effects breaks all EH/vtbl defaults |
| Shared leaf identity | **High** | splitting into fake per-domain functions |
| Bare `ret` (caller stack cleanup) | **High** | wrong port ABI for cdecl sinks |
| Not a single-purpose InitInstance helper | **High** | wrong ownership / wrong system tag |

---

## 3. Cross-check against raw + bytes

```
EmptyRet:
  ret    ; c3
```

Any clean plate with branches, stores, or string handling is **wrong**.

Parent-seed alias `Named_CalleeOf_…_InitInstance_0056f570` is **auto-rename debt** — keep as alias only.

---

## 4. Surviving contract for AutoCore

```c
// Port: shared empty leaf (do not special-case by caller domain)
void EmptyRet(void) { /* no-op */ }

// Vtbl defaults may point here; overrides (e.g. targeting slot 7) are separate VAs.
// Debug-looking CALL EmptyRet("…") sites are dead in this build — do not re-enable logging
// unless a different address is proven to be a real logger.
```

---

## 5. Open questions

1. PDB / CRT symbol string.
2. Whether server ports need an equivalent shared nop address (usually just omit empty vfuncs).

**Verdict:** **accept**
