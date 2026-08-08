# Review A (reconstruction fidelity): `aa_005eb040` PodCopyBlock_0x40_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb040` |
| **VA** | `0x005eb040`–`0x005eb0a6` inclusive (**103 B** / `0x67`) |
| **Canonical name (Ghidra)** | `FUN_005eb040` |
| **Proposed name** | `PodCopyBlock_0x40_Thiscall_Inferred` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005eb040` (**retired**) |
| **Review date** | `2026-08-05` (R12-036 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005eb210` query-object base ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **POD block copy** of exactly **16 dwords / 0x40 bytes**:

- **ECX** = destination base
- Stack arg = source base
- Straight-line dword stores `dest[i] = src[i]` for `i = 0..15` (byte offsets `0..0x3C`)
- **`RET 4`**; **EAX** preserved as dest (return-this style)

Shared utility used by the dualed query-object base ctor (`FUN_005eb210` copies `params+0x20` → `self+0x80`) and many sibling physics/query helpers. Not a ctor, not a vcall, not a vector element helper.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005eb040` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/completeness) |
| Assembly | `disassemble_function` (35 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 120 B @ entry — full body hex + `CC` pad after `C2 04 00` |
| Callers / xrefs | `get_function_callers` (13 named) + `get_function_xrefs` (29 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` on `005eb2a1`, `005eb0c8`, `005eb0f7`, `005f06c6`, `0066252f`, `00668d4a` |
| Parent dual | `VOGPhysics_QueryObject_BaseCtor_Inferred` @ `0x005eb210` (R11-008) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005eb040` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of other VAs.

---

## 3. Signature

```c
uint32_t * __thiscall PodCopyBlock_0x40_Thiscall_Inferred(
    uint32_t *dest /* ECX */,
    const uint32_t *src /* stack [ESP+4] */);
// RET 4; EAX = dest (preserved from entry MOV EAX,ECX)
// Decompiler may display void — do not trust; EAX is dest at RET.
```

| Item | Evidence |
|---|---|
| Convention | `MOV EAX,ECX`; `MOV ECX,[ESP+4]`; `RET 4` (`C2 04 00`) |
| Size | exactly **16** dword load/store pairs; last at `+0x3C` |
| Callees | **none** (leaf) |
| Body size | 103 B (`0x67`); pad `CC` from `0x005eb0a7` |
| Classification | leaf (`analyze_function_complete`) |

### Bytes seal (`read_memory`)

```text
8B C1                ; MOV EAX,ECX          ; dest
8B 4C 24 04          ; MOV ECX,[ESP+4]      ; src
8B 11 89 10          ; MOV EDX,[ECX]; MOV [EAX],EDX
… 15 more dword pairs through +0x38 …
8B 49 3C 89 48 3C    ; last dword +0x3C (ECX as temp)
C2 04 00             ; RET 4
CC…                  ; pad
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save dest in EAX | **Yes** (`MOV EAX,ECX`) |
| Load src from stack | **Yes** (`MOV ECX,[ESP+4]`) |
| 16 dword copies 0..0x3C | **Yes** (decompile + disasm) |
| No branches / loops / calls | **Yes** (straight-line leaf) |
| RET 4 | **Yes** (`C2 04 00`) |
| EAX = dest at return | **Yes** (EAX never rewritten after prolog) |
| Decompile ≡ raw CF | **Yes** (void return display is decompiler gap only) |

### Call-site samples (evidence; not dualled)

| Site | ECX (dest) | Stack (src) | Context |
|---|---|---|---|
| `0x005eb2a1` `FUN_005eb210` | `LEA ECX,[ESI+0x80]` | `params+0x20` (`ADD EDI,0x20; PUSH EDI`) | parent base ctor tail |
| `0x005eb0c8` `FUN_005eb0b0` | `LEA ECX,[EDI+0x20]` | `ESI` then adjusted `+0x80` | sibling helper |
| `0x005eb0f7` `FUN_005eb0e0` | `LEA ECX,[ESI+0x80]` | `EDI` (arg) | sibling helper |
| `0x0066252f` / `0x00662544` `FUN_00662510` | object `+0x80` | peer buffer | dual copy |
| `0x00668d4a` / `0x00668d56` `FUN_00668d30` | `ESI+0x30` / `ESI+0x70` | `EDI+0x20` / `EDI+0x60` | dual 0x40 blocks |
| `0x005f06c6` `FUN_005f0210` | stack blob | prepared float block | multi-site consumer |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Named callers (13) | `FUN_005eb0b0`, `FUN_005eb0e0`, `FUN_005eb210`, `FUN_005f0210`, `FUN_005f1ec0`, `FUN_0063aa40`, `FUN_0065ebe0`, `FUN_00661110`, `FUN_00662510`, `FUN_00668d30`, `FUN_00668ea0`, `FUN_006ef0d0`, `FUN_006ef400` |
| Xrefs | **29** UNCONDITIONAL_CALL (multi-site callers) |
| Callees | none |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + 16-dword / 0x40 size | **High** | bytes + disasm + decompile identical |
| thiscall ECX=dest, stack=src, RET 4 | **High** | prolog + epilogue + call sites |
| EAX = dest on return | **High** | EAX preserved; decompiler void is wrong display |
| Leaf / no callees | **High** | analyze + body |
| Shared utility (not query-only) | **High** | 29 xrefs across families |
| Product/PDB English for blob type | **Open** | `_Inferred` hygiene |
| Semantic meaning of the 0x40 blob | **Open** | callers use different dest offsets |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 7. Gaps / open

1. Product/PDB name for the 0x40 blob type (matrix / transform / params tail — not sealed).
2. Full per-caller dest/src field English beyond parent `params+0x20 → self+0x80`.
3. Whether any consumer relies on EAX return (many ignore it).
4. Runtime Confirmed / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/size/leaf/callers High; product English + blob semantics + runtime open.
