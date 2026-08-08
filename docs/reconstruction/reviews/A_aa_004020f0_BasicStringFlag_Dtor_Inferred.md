# Review A (reconstruction fidelity): `aa_004020f0` BasicStringFlag_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004020f0` |
| **VA** | `0x004020f0`–`0x00402126` inclusive (**55 B** / `0x37`) |
| **Canonical name (Ghidra)** | `FUN_004020f0` |
| **Proposed name** | `BasicStringFlag_Dtor_Inferred` |
| **Review date** | `2026-08-05` (R10-018 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_004020f0_BasicStringFlag_Dtor_Inferred.md` |
| **System** | missions-progression (partition parent chain); unit = shared aggregate dtor |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

SEH-guarded **destructor** for a fixed layout aggregate:

```text
struct BasicStringFlag {          // footprint ≥ 0x1D
  std::basic_string<char> str;    // +0x00, size 0x1C (this binary)
  uint8_t flag;                   // +0x1C  (POD — no dtor work)
};
```

Control flow:

1. Install SEH (`LAB_009bbfb9`).
2. `basic_string` dtor via IAT `[0x009c62f4]` with `this` = stack arg (`MOV ECX,[ESP+0x10]`).
3. Teardown SEH; **`RET 4`**.
4. Flag byte never read or written.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004020f0` ≡ raw 2026-07-23 |
| Complete analysis | `analyze_function_complete` name=`0x004020f0` (xrefs/callers/callees/locals) |
| Assembly | `disassemble_function` (12 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 64 B @ entry — hex seal + `C2 04 00` + `CC` pad |
| Callers / xrefs | `get_function_callers` (7 Unwind) + `get_function_xrefs` (7 UNCONDITIONAL_CALL) |
| Callee | `get_function_callees` → EXTERNAL `~basic_string` via IAT `[0x009c62f4]` |
| Family (context) | dualed `00401d30` ctor + dualed `00402040` copy (evidence only) |
| Clean | `reconstructed-exact/BasicStringFlag_Dtor_Inferred.cpp` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers.

---

## 3. Signature

```c
// object on stack; nested thiscall into string dtor; RET 4
void BasicStringFlag_Dtor_Inferred(BasicStringFlag* obj);
```

| Item | Evidence |
|---|---|
| Stack formal | `MOV ECX,[ESP+0x10]` after SEH install (3× PUSH) → original arg1 |
| Nested thiscall | ECX fed to IAT dtor only |
| Cleanup | `RET 4` (`C2 04 00` @ `0x00402124`) |
| Body size | 55 B; pad `CC` before `FUN_00402130` @ `0x00402130` |
| SEH | shared `LAB_009bbfb9` with `00401d30` / `00402040` |
| Flag | no access to `+0x1c` in disasm |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | **Yes** |
| string dtor only callee | **Yes** |
| No flag byte touch | **Yes** |
| RET 4 | **Yes** |
| No mission UI / dialog calls | **Yes** |

### Call-site summary

All 7 xrefs are `Unwind@*` UNCONDITIONAL_CALL sites — registered MSVC exception cleanup for the string-bearing object. No gameplay/direct callers in the xref set.

### Family (not dualled here)

| VA | Role |
|---|---|
| `0x00401d30` | construct from `(string*, char*)` — **RET 0xC** (dualed MEGA-065) |
| `0x00402040` | copy-ctor EDI src — **RET 4** (dualed MEGA-080) |
| `0x00401fe0` | node ctor embeds StringFlag at `+0xc` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + string dtor only | **High** | decompile ≡ disasm ≡ bytes |
| ABI stack obj / RET 4 | **High** | epilogue + stack offset math |
| Flag POD / not touched | **High** | no `+0x1c` access |
| Not mission-dialog logic | **High** | Unwind-only callers; no strings/UI |
| Family = BasicStringFlag dtor | **Probable** | shared SEH + twin docs; no RTTI seal |
| Product flag English | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps

1. Product English for the flag byte (bool / enum / tag).
2. Per-Unwind-site owning frame type (beyond string-bearing).
3. Runtime golden / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/string-dtor-only sealed; family type name Probable → keep `_Inferred`. Product flag English + runtime open.
