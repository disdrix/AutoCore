# Review A (reconstruction fidelity): `aa_00402040` BasicStringFlag_CopyCtor_EdiSrc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402040` |
| **VA** | `0x00402040`–`0x0040208c` inclusive (**77 B** / `0x4D`) |
| **Canonical name (Ghidra)** | `FUN_00402040` |
| **Proposed name** | `BasicStringFlag_CopyCtor_EdiSrc_Inferred` |
| **Rejected scaffold** | `Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00402040` |
| **Review date** | `2026-08-05` (MEGA-080 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` |
| **System** | missions-progression (partition parent chain); unit = shared aggregate copy-ctor |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

SEH-guarded **copy constructor** for a fixed layout aggregate:

```text
struct BasicStringFlag {          // footprint ≥ 0x1D
  std::basic_string<char> str;    // +0x00, size 0x1C (this binary)
  uint8_t flag;                   // +0x1C
};
```

Control flow:

1. Install SEH (`LAB_009bbfb9`).
2. `basic_string` copy-ctor via IAT `[0x009c62ec]` into dest (thiscall; source pushed from EDI).
3. Copy trailing byte `dest[+0x1c] = src[+0x1c]`.
4. Teardown SEH; return dest in EAX; **`RET 4`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00402040` ≡ raw 2026-07-23 |
| Complete analysis | `analyze_function_complete` name=`FUN_00402040` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (20 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 80 B @ entry — hex seal + `C2 04 00` + `CC` pad |
| Callers / xrefs | `get_function_callers` (2) + `get_xrefs_to` (2 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` + `disassemble_function` on `FUN_00401fe0` / `FUN_00980160` |
| Callee | `get_function_callees` + import demangle `??0?$basic_string@...@@QAE@ABV01@@Z` |
| Twin (context) | `decompile_function` / `disassemble_function` `0x00401d30` construct-from-parts |
| Clean | `reconstructed-exact/BasicStringFlag_CopyCtor_EdiSrc_Inferred.cpp` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers.

---

## 3. Signature

```c
// dest on stack; source in EDI; returns dest* in EAX; RET 4
BasicStringFlag* BasicStringFlag_CopyCtor_EdiSrc_Inferred(BasicStringFlag* dest);
```

| Item | Evidence |
|---|---|
| Stack formal | `MOV ESI,[ESP+0x14]` after SEH+`PUSH ESI` → original arg1 |
| Register source | `PUSH EDI` then `MOV AL,[EDI+0x1c]`; call site `009801be MOV EDI,EAX` |
| thiscall string | `MOV ECX,ESI; CALL [0x009c62ec]` |
| Cleanup | `RET 4` (`C2 04 00` @ `0x0040208a`) |
| Return | `MOV EAX,ESI` |
| Body size | 77 B; pad `CC` before `FUN_00402090` @ `0x00402090` |
| SEH | shared `LAB_009bbfb9` with `00401d30` / `004020f0` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | **Yes** |
| string copy-ctor only callee | **Yes** |
| flag byte @ `+0x1c` | **Yes** |
| return dest / RET 4 | **Yes** |
| No mission UI / dialog calls | **Yes** |

### Call-site samples

| Site | Parent | Dest | Source (EDI) |
|---|---|---|---|
| `0x0040200a` | `FUN_00401fe0` | `LEA EAX,[ESI+0xc]; PUSH` | inherited from grandparent (node value copy) |
| `0x009801c0` | `FUN_00980160` | local `[ESP+0x30]` | `MOV EDI,EAX` after `FUN_00401d30` |

### Family (not dualled)

| VA | Role |
|---|---|
| `0x00401d30` | construct from `(string*, char*)` — **RET 0xC** |
| `0x004020f0` | string dtor only (flag POD) |
| `0x00401fe0` | node ctor embeds StringFlag at `+0xc` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + string copy + flag byte | **High** | decompile ≡ disasm ≡ bytes |
| ABI EDI src / stack dest / RET 4 | **High** | both call sites + epilogue |
| Layout string@0 + flag@0x1c | **High** | `MOV [ESI+0x1c],AL` after string size 0x1c |
| Not mission-dialog logic | **High** | no strings/UI; 2 generic callers |
| Reject Named_CalleeOf scaffold | **High** | xref-seed only |
| Product flag English | **Open** | `_Inferred` |
| Parent map/value_type product name | **Open** | `00401fe0` residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps

1. Product English for the flag byte (bool / enum / tag).
2. Full product type for the map node that embeds this at `+0xc` (`FUN_00401fe0`).
3. Runtime golden / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/layout sealed; product flag + map English open → keep `_Inferred`. Scaffold Named_CalleeOf mission name **retired**.
