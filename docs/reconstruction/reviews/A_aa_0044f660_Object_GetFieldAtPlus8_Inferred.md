# Review A (reconstruction fidelity): `aa_0044f660` Object_GetFieldAtPlus8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044f660` |
| **VA** | `0x0044f660` |
| **Canonical name** | `Object_GetFieldAtPlus8_Inferred` |
| **Review date** | `2026-08-05` (R10-027 dual OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0044f660_Object_GetFieldAtPlus8_Inferred.md` |
| **System** | skills-abilities partition seed / shared polymorphic util leaf |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, `disassemble_function`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thiscall leaf getter of the dword at `this+8`. Shared vtable method (parent dual `Class_00a9bbe8` slot +4 among ≥10 DATA embeds). Call sites use the return as an object pointer.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x0044f660)` 2026-08-05 |
| Body bytes | `read_memory` 32 B @ `0x0044f660` → hex `8b4108c3` + `CC` pad |
| Disasm | `disassemble_function` → `MOV EAX,[ECX+8]; RET` |
| Function meta | `analyze_function_complete` — stub; callers `FUN_00641ad0`, `FUN_00647990`; 12 xrefs |
| Parent dual | `aa_00416110` vtable map (set/get +8) |
| Raw / annotated / clean | R10-027 trio |

**Not performed:** `disassemble_bytes`; Launcher; parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body bounds `0x0044f660`–`0x0044f663` (4 B) | **Confirmed** | `RET` then `CC` pad |
| Bytes `8B 41 08 C3` | **Confirmed** | `read_memory` |
| ECX = this; load `[ECX+8]` → EAX | **Confirmed** | decomp ≡ disasm ≡ bytes |
| Plain RET (no stack args) | **Confirmed** | |
| No callees | **Confirmed** | analyze + decomp |
| 2 CALL callers | **Confirmed** | xrefs |
| 10 DATA vtable embeds | **Confirmed** | xrefs |
| Parent vftable slot +4 @ `0x00a9bbe8` | **Confirmed** | mem `60f64400` at `00a9bbec` |
| Sibling setter `0x00416150` stores +8 | **Confirmed** | bytes (context) |
| Product field English | **Open** | |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Single load from `this+8` | **Yes** |
| Return that dword | **Yes** |
| No branches / no callees | **Yes** |
| No invented opcodes | **Yes** |

### Sealed CF sketch

```
// ECX = self
return *(uint32_t*)(self + 8);
```

---

## 5. Gaps

1. Product / PDB field name for offset +8.
2. Product class names for non-`00a9bbe8` host vtables.
3. Whether every host types +8 as object* (both CALL sites do; DATA-only hosts unproven).
4. Runtime path capture; bit-exact.

---

## 6. Verdict rationale

Structural CF, ABI, body bounds, multi-vtable sharing, and caller use-as-pointer are sealed from decompile + bytes + xrefs. Product English remains open → **accept-with-gaps** (not reject: contract is port-usable; not full **accept**: field semantics unproven beyond offset).
