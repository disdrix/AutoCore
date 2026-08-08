# Review B (skeptical / adversarial): `aa_004898a4` __RTDynamicCast

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898a4` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-011) |
| **Counterpart** | `reviews/A_aa_004898a4___RTDynamicCast.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is a real recursive function / jumptable | **Falsified** — 6 B `FF 25 48 66 9C 00`; tool classifies **thunk** |
| 2 | Unit implements full `dynamic_cast` math in-image | **Falsified** — only IAT jmp; CRT via `0x009C6648` / EXTERNAL |
| 3 | Signature is `void __RTDynamicCast(void)` | **Falsified** — call sites push 5 dwords + `ADD ESP,0x14` |
| 4 | stdcall / thiscall | **Falsified** — caller cleans stack (`ADD ESP,0x14`), no ECX-this required at thunk |
| 5 | Name needs `_Inferred` product invent | **Falsified** — import symbol `__RTDynamicCast` + IAT label `PTR___RTDynamicCast_*` |
| 6 | Parent-only / interaction-only helper | **Falsified as exclusive use** — 100+ callers across systems; partition tag is parent-system only |
| 7 | `isReference` always 1 / throws always | **Falsified at parent** — parent `PUSH 0` for isReference; NULL check after cast |
| 8 | IAT slot is static code | **Falsified** — DATA slot; bulk xref only from this thunk; snapshot `0x006ea91e` is resolved CRT |
| 9 | Scaffold 2026-07-23 already sealed dual | **Falsified** — prior raw was decompile-only scaffold; R10-011 first dual A/B + bytes/IAT seal |
| 10 | Body spans neighboring `FF 25` slots | **Falsified** — function body ends `004898a9`; next `FF 25` is sibling import |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 6-byte IAT jmp identity | **High** | Mis-classifying CRT import as game code |
| cdecl 5-arg + `ADD ESP,0x14` | **High** | Stack imbalance on any manual call |
| CRT export name | **High** | Wrong rename / port surface |
| Return EAX pointer/NULL for pointer casts | **High** (call sites) | Miss null checks |
| Full CRT failure/throw semantics | **Med** (library docs; not re-proved) | Reference-cast path rare in sampled sites |
| Every TypeDescriptor pair meaning | **Open** | Per-caller product types |
| Runtime Confirmed | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

Live 2026-08-05 decompile **matches** 2026-07-23 scaffold text (recursive-call artifact) but **must not** be treated as body authority.

Sealed by:

- `read_memory` entry: `FF 25 48 66 9C 00`
- `get_function_by_address`: body `004898a4`–`004898a9`
- `get_xrefs_from`: INDIRECTION → `009c6648`; EXTERNAL `__RTDynamicCast`
- `get_assembly_context` @ `009386d6` / `00532e7b` / `004de84e`: five pushes + `ADD ESP,0x14`

Parent `FUN_00938670` decompile already names args as `TypeDescriptor*` and shows `__RTDynamicCast(pv,0,src,dst,0)` — consistent with MSVC contract.

---

## 4. Surviving contract for AutoCore

```text
// In-image:
//   0x004898a4: jmp [__imp___RTDynamicCast]

// Call-site contract (pointer cast, isReference==0):
result = __RTDynamicCast(obj, vfDelta, &srcRtti, &dstRtti, 0);
if (result == NULL) { /* not an instance / adjust failed */ }
// cdecl; caller pops 0x14 bytes

// Port: use language dynamic_cast / type checks; do not re-host this IAT stub
// as gameplay logic. Do not invent a product Class::Method name.
```

---

## 5. Verdict

Adversarial pass confirms IAT-thunk identity and rejects decompiler/product misreads. Remaining CRT-body / full-census / runtime residuals → **accept-with-gaps**.
