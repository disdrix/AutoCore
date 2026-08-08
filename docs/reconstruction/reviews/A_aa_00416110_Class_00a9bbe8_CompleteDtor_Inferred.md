# Review A (reconstruction fidelity): `aa_00416110` Class_00a9bbe8_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416110` |
| **VA** | `0x00416110` |
| **Canonical name** | `Class_00a9bbe8_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00416110` |
| **Prior scaffold** | `FUN_00416110` partial trio |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00416110_Class_00a9bbe8_CompleteDtor_Inferred.md` |
| **System** | util / polymorphic class (vftable `0x00a9bbe8`) |
| **Wave** | WQ9I-G OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Complete destructor** for the class whose vftable is `PTR_LAB_00a9bbe8`:

```text
// stack obj*; ret 4; SEH frame in bytes
*obj = &PTR_LAB_00a9bbe8;
// no free, no field teardown
```

Sole call site is scalar-deleting dtor `FUN_004160f0` (`push this; call`), which optionally `operator_delete`s when flag bit0 set.

Ctor twin `FUN_0078bc20` installs the same vptr.

**Not** transform assign `0x00416160` (adjacent VA only).

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| stack `[esp+4]` at entry (after SEH: `[esp+0x10]`) | `obj*` |
| **ECX** | unused on entry |
| return | void; **`ret 4`** (`C2 04 00`) |

Body size **55 B** (`0x00416110`–`0x00416147` exclusive).

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00416110` ≡ raw store CF |
| Bytes | `read_memory` 64 B — SEH + `mov [eax],0x00a9bbe8` + `ret 4` |
| Disasm | `disassemble_function` (not `disassemble_bytes`) |
| Callers | 1 xref `0x004160f4` + assembly context (`push esi; call`) |
| Vtable | `read_memory` @ `0x00a9bbe8` (setter/getter/empty/sd-dtor slots) |
| Raw / annotated / clean | `aa_00416110_*`, named plate |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Install vptr `0x00a9bbe8` | **Yes** (bytes + decompile) |
| No field free / no callees | **Yes** (leaf) |
| `ret 4` stack cleanup | **Yes** (`C2 04 00`) |
| SEH frame present | **Yes** (bytes; decompiler elides) |
| Invented branches | **None** |

### Recovered CF

```c
// stack ABI, ret 4
void CompleteDtor(void *obj)
{
  // SEH omitted
  *(void **)obj = &PTR_LAB_00a9bbe8;
}
```

---

## 5. Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (vptr only) | **High** |
| Stack ABI + ret 4 | **High** (caller push + bytes) |
| Vtable address | **High** |
| Product class English | Open → `_Inferred` |
| Runtime | Open |

---

## 6. Gaps

- Product / RTTI name for `Class_00a9bbe8`.
- Dual relationship of virtual sd-dtor @ `0x004320b0` vs `FUN_004160f0`.
- Runtime / bit-exact.

---

## 7. Verdict

**accept-with-gaps** — complete dtor CF/ABI/vptr sealed by bytes + sole caller. Residual: product name, runtime.
