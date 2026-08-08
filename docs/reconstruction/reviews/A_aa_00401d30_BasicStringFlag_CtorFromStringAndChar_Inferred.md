# Review A (reconstruction fidelity): `aa_00401d30` BasicStringFlag_CtorFromStringAndChar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401d30` |
| **VA** | `0x00401d30`–`0x00401d83` inclusive (**84 B** / `0x54`) |
| **Canonical name (Ghidra)** | `FUN_00401d30` |
| **Proposed name** | `BasicStringFlag_CtorFromStringAndChar_Inferred` |
| **Rejected scaffold** | `Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00401d30` |
| **Review date** | `2026-08-05` (MEGA-065 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` |
| **System** | missions-progression (partition parent chain); unit = shared aggregate construct-from-parts |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

SEH-guarded **construct-from-parts** for a fixed layout aggregate:

```text
struct BasicStringFlag {          // footprint ≥ 0x1D
  std::basic_string<char> str;    // +0x00, size 0x1C (this binary)
  uint8_t flag;                   // +0x1C
};
```

Control flow:

1. Install SEH (`LAB_009bbfb9`).
2. `basic_string` copy-ctor via IAT `[0x009c62ec]` into dest (thiscall; source pushed from stack param_2).
3. Store trailing byte `dest[+0x1c] = *param_3` (param_3 is **char***).
4. Teardown SEH; return dest in EAX; **`RET 0xC`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00401d30` ≡ raw 2026-07-23 CF |
| Complete analysis | `analyze_function_complete` name=`0x00401d30` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (21 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 96 B @ entry — hex seal + `C2 0C 00` + `CC` pad |
| Callers / xrefs | `get_function_callers` (1) + `get_function_xrefs` / `get_xrefs_to` (1 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` @ `009801af` + parent decompile `FUN_00980160` |
| Callee | IAT `[0x009c62ec]` demangle shared with MEGA-080 twin |
| Twin (context) | dualed `BasicStringFlag_CopyCtor_EdiSrc_Inferred` `0x00402040` |
| Clean | `reconstructed-exact/BasicStringFlag_CtorFromStringAndChar_Inferred.cpp` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers.

---

## 3. Signature

```c
// dest, src string*, char* on stack; returns dest* in EAX; RET 0xC
BasicStringFlag* __stdcall BasicStringFlag_CtorFromStringAndChar_Inferred(
    BasicStringFlag* dest,
    const basic_string<char>* src,
    const uint8_t* flag_src);
```

| Item | Evidence |
|---|---|
| Stack dest | `MOV ESI,[ESP+0x14]` after SEH+`PUSH ESI` → original arg1 |
| Stack src string | `MOV EAX,[ESP+0x14]` before PUSH ESI → arg2; pushed before string CALL |
| Stack char* | `MOV ECX,[ESP+0x1c]` after CALL → arg3; `MOV DL,[ECX]` |
| thiscall string only | `MOV ECX,ESI; CALL [0x009c62ec]` |
| Cleanup | `RET 0xC` (`C2 0C 00` @ `0x00401d81`) |
| Return | `MOV EAX,ESI` |
| Body size | 84 B; pad `CC` before `FUN_00401d90` @ `0x00401d90` |
| SEH | shared `LAB_009bbfb9` with `00402040` / `004020f0` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | **Yes** |
| string copy-ctor only callee | **Yes** |
| flag byte @ `+0x1c` from `*char*` | **Yes** (disasm overrides decompiler string typing) |
| return dest / RET 0xC | **Yes** |
| No mission UI / dialog calls | **Yes** |

### Call-site sample

| Site | Parent | Args |
|---|---|---|
| `0x009801af` | `FUN_00980160` | dest=local StringFlag; src=substr result; char*=local zeroed byte; then `MOV EDI,EAX; CALL 00402040` |

### Family (not dualled except copy twin)

| VA | Role |
|---|---|
| `0x00402040` | copy twin — **dualed MEGA-080** (EDI src; RET 4) |
| `0x004020f0` | string dtor only (flag POD) |
| `0x00401fe0` | node ctor embeds StringFlag at `+0xc` |
| `0x00401c50` | map insert/find peer after construct |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + string copy + flag byte | **High** | decompile ≡ disasm ≡ bytes |
| ABI 3 stack args / RET 0xC | **High** | epilogue + sole call site 3 pushes |
| Layout string@0 + flag@0x1c | **High** | `MOV [ESI+0x1c],DL` after string size 0x1c; twin agrees |
| Not mission-dialog logic | **High** | no strings/UI; 1 generic caller |
| Reject Named_CalleeOf scaffold | **High** | xref-seed only |
| Product flag English | **Open** | `_Inferred` |
| Parent map/value_type product name | **Open** | residual parents |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps

1. Product English for the flag byte (bool / enum / tag).
2. Full product type for the map/node that consumes this aggregate.
3. Runtime golden / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/layout sealed; product flag + map English open → keep `_Inferred`. Scaffold Named_CalleeOf mission name **retired**.
